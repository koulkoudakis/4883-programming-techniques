/*
Sharome Burton
01/23/2023
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

const double PI = 3.14159265358979323846;
const double EARTH_RADIUS = 6356.752; //in km
const float MAX_RANGE = 320.0; // maximum range of car
const float DRIVING_SPEED = 105.0;	// in km/h
const float CHARGING_SPEED = 800.0; // in km/h

// unordered_map<string, unordered_map<string, double>> weights;
// vector<string> directions;

// Structure for each location read from .csv file
struct Location {
    string name; // name of location
    double lat, lon; // coordinates
	double g = 0; // accumulated cost to arrive at this location
	double h = INFINITY; // heuristic distance to goal
	double rangeNeededFromPrev = INFINITY; // range needed to arrive here from previous location
	Location *prev = NULL; // previous location
	double f() { return g + h; } // f-score: accumulated cost to reach this location + heuristic
};

// For use with priority queue
struct MyComparator {
    bool operator()(pair<int, string> a, pair<int, string> b) {
        return a.first > b.first;  // this will make the priority_queue sort in descending order of the first element of the pair
    }
};

// Converts degrees to radians
double deg2rad(double deg) {
    return deg * PI / 180;
}

// Heuristic - determines the minimum time (including charging time) to reach destination in hrs
double distToTime(double dist)
{
	if (dist < MAX_RANGE) return dist / DRIVING_SPEED; // 105 km/hr driving
	else 
	{
		return (dist / DRIVING_SPEED) + ((dist - MAX_RANGE) / CHARGING_SPEED); // driving time + min time to gain needed range
	}
}

// converts range necessary to time (hrs)
double chargeToTime(double dist)
{
	return dist / CHARGING_SPEED; // 800 km/hr charging
}

// Used to convert degrees latitude or longitude to kilometers
double latToKm(double latDist) { return latDist * 110.574; }
double longToKm(double longDist, double lat) { return longDist * 111.320 * cos(deg2rad(lat)); }
double kmToLat(double dist) { return dist / 110.574; }
double kmToLong(double dist, double lat) { return dist / (111.320 * cos(deg2rad(lat))); }


// Rounds up to 2 decimal places (rounding up ensures enough charge time)
double round2DP(double num)
{
	return ceil(num * 100.0) / 100.0;
}

// Read the locations from .csv file and stores in hash map
unordered_map<string, Location> readLocations(const string& filename, unordered_map<string, Location> locations) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream linestream(line);
        string value;

        string name;
        double lat, lon;
        getline(linestream, value, ',');
        name = value;
        getline(linestream, value, ',');
        lat = stod(value);
        getline(linestream, value, ',');
        lon = stod(value);
        locations[name] = {name, lat, lon};
    }
	return locations;
}

// Returns Great circle distance from pair of Locations
double geodesicDist(Location start, Location end)
{
	double lat1 = start.lat;
	double lon1 = start.lon;
	double lat2 = end.lat;
	double lon2 = end.lon;

	double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    lat1 = deg2rad(lat1);
    lat2 = deg2rad(lat2);

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// Great circle distance alternative formula
double geodesicDistAlt(Location start, Location end)
{
	double lat1 = start.lat;
	double lon1 = start.lon;
	double lat2 = end.lat;
	double lon2 = end.lon;

    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

// // function to pre-compute the weights between locations
// void computeWeights() {
//     for (auto& location1 : locations) {
//         for (auto& location2 : locations) {
//             if (location1.first != location2.first) {
//                 double distance = geodesicDistance(location1.second.lat, location1.second.lon, location2.second.lat, location2.second.lon);
//                 weights[location1.first][location2.first] = distance;
//                 directions.push_back(location2.first);
//             }
//         }
//     }
// }

// Finds and returns hashmap of chargers within 320km range
unordered_map<string, Location> possibleChargers(string& start, unordered_map<string, Location>& locations)
{
	unordered_map<string, Location> candidates;
	int numPossible = 0; // locations within range
	int numChecked = 0;	// total number of locations in network

	// cout << "\nCHARGERS WITHIN 320km FROM " << start << ": \n";
	for (auto &loc : locations)
	{
		if (loc.first != start){
			numChecked += 1;

			// first, consider only locations within 640x640km square
			if (((abs(locations[start].lat - loc.second.lat)) < kmToLat(MAX_RANGE)) && (abs(locations[start].lon - loc.second.lon) < kmToLong(MAX_RANGE, locations[start].lat))) 
			{
				// get distance to charger
				double dist = geodesicDist(locations[start], loc.second);
				if (dist < MAX_RANGE){ // choose only locations within a 320km geodesic range

					// cout << loc.first << ", " << loc.s:econd.lat << ", " << loc.second.lon << ", " << dist <<" km away." << ", " << distToTime(dist) << "hours to arrival. \n";

					numPossible += 1;

					// Potentially next node to be visited (within driving range)
					candidates[loc.first] = {loc.first, loc.second.lat, loc.second.lon, 0, INFINITY, INFINITY, NULL};
				}
			}
		}
	}
	// cout << "Number of possibly reachable chargers: " << numPossible << " out of " << numChecked << "\n";
	return candidates;
}

// A solution has been found
priority_queue<pair<double, string>, vector<pair<double, string>>, MyComparator> addSolution(priority_queue<pair<double, string>, vector<pair<double, string>>, MyComparator> solutions,
																							 unordered_map<string, Location> nodes,
																							 string start,
																							 string goal,
																							 pair<double, string> current
																							 )
{
	string route = goal;
	double firstCharge = 0; // amount of time spent at the first supercharger
	double safetyFactor = 0.25; // minimum amount of time to spend at first supercharger

	if (nodes.size() == 1) // best case: if the start is within range of the goal
	{
		solutions.push({0.0, start + ", " + goal});
		return solutions;
	}

	// cout << "Found path with cost: " << nodes[current.second].g + distToTime(geodesicDist(nodes[current.second], nodes[goal])) << "\n";	

	// Backtrack from goal to start, taking into account the amount of charging needed to get between each location
	Location temp1 = nodes[current.second];
	Location temp2;

	// cout << goal << " <--- dist to goal: " << temp1.prev->h << ", then need " << temp1.rangeNeededFromPrev << " hrs charging... \n";
	while (temp1.prev->name != start)
	{
		// cout << temp1.prev->name << " <--- dist to goal: " << temp1.prev->prev->h << ", then need " << temp1.prev->rangeNeededFromPrev << " hrs charging... \n";

		// This ensures that the car does not charge more than necessary at the first charger after the start
		if (temp1.prev->prev->name == start)
		{ 
			firstCharge = temp1.prev->rangeNeededFromPrev; // naive amount of time spent at 1st supercharger (the first charger after the start)
			double secondCharge = temp1.rangeNeededFromPrev; // optimal amount of time spent at 2nd supercharger
			double firstConsumption = distToTime(geodesicDist(nodes[temp1.prev->name], nodes[start])); // Fuel consumed between start and 1st supercharger
			firstCharge = safetyFactor + firstCharge - (firstConsumption - (secondCharge + abs(chargeToTime(MAX_RANGE) - firstConsumption))); // optimal time to spend at 1st supercharger
			if (firstCharge < 0)
				firstCharge = 0;						

			route = to_string(firstCharge) + ", " + route;
			route = temp1.prev->name + ", " + route;
			break; 
		}

		route = to_string(temp1.prev->rangeNeededFromPrev) + ", "  + route;
		route = temp1.prev->name + ", " + route;

		temp2 = *temp1.prev;
		temp1 = temp2;
	}
	// cout << start << " <--- dist to goal: " << nodes[goal].h << " \n";
	
	route = start + ", " + route;
	// cout << "*** " << route << " ***";

	solutions.push({nodes[current.second].g, route});
	// cout << "\nSOLUTION FOUND\n cost: " << nodes[current.second].g;
	// cout << "\n\nOUTPUT:\n\n" << route << "\n\n";
	return solutions;
}

// A* pathfinding algorithm
// string start: starting supercharger
// string goal: destination supercharger
// unordered_map<string, Location> locations: hashable Location structs 
string aStar(const string start, const string goal, unordered_map<string, Location> locations){
	string route = goal;
	if (start == goal) return goal; // No need to drive

	priority_queue <pair<double, string>, vector<pair<double, string>>, MyComparator> solutions; // valid solutions
	priority_queue <pair<double, string>, vector<pair<double, string>>, MyComparator> open; // nodes arranged with  lowest f() value on top (best immediately available node to explore)
	unordered_map<string, bool> closed; // nodes already visited and not being considered again
	unordered_map<string, Location> nodes; // nodes that have been probed
	unordered_map<string, Location> candidates; // nodes that have been within driving range of the vehicle

	// cout << "\n\nFINDING PATH FROM " << start << " TO " << goal << "\n\n";

	// First node being considered is the starting node
	nodes[start] = {start, locations[start].lat, locations[start].lon, 0.0, distToTime(geodesicDist(locations[start], locations[goal])), 0.0, NULL};
	open.push({nodes[start].f(), start});

	// Continue until there are no nodes available to explore
	while (!open.empty())
	{
		auto current = open.top();
		open.pop();
		closed[current.second] = true;		
		// cout << "\n\nCURRENT *********************: " << current.second << "\n";
		
		// check if current node being considered is the goal
		if (current.second == goal)
		{	
			solutions = addSolution(solutions, nodes, start, goal, current);
		}
	
		// candidates = possibleChargers(current.second, locations);
		for (auto candidate : possibleChargers(current.second, locations))
		{
			candidates.insert(candidate);
		}
		// check if goal is within range of current node
		if (candidates.count(goal)){
			if (nodes[current.second].prev == NULL){
				solutions = addSolution(solutions, nodes, start, goal, current);
			}
		}

		for (auto& next : candidates)
		{
			// check if each candidate has already been probed
			if (closed[next.second.name] == false)
			{
				double g = nodes[current.second].g + nodes[current.second].rangeNeededFromPrev + distToTime(geodesicDist(locations[current.second], locations[next.second.name]));

				double h = distToTime(geodesicDist(locations[next.second.name], locations[goal])) ; // A-star heuristic
				// double h = 0.0; // Dijksra-like (heuristic is set to zero)

				// check if candidate node is not already in open or if the cost of going to this candidate node from current node
				// is less than the cost of going to this candidate node from another node
				if (!(nodes.count(next.second.name)) || ((g + h) < nodes[current.second].f()))
				{
					if (geodesicDist(locations[current.second], locations[next.second.name]) < MAX_RANGE)
					{
						// Push new node to priority queue to explore
						nodes[next.second.name] = {next.second.name,
							next.second.lat,
							next.second.lon,
							g,
							h,
							round2DP(chargeToTime(geodesicDist(locations[current.second], locations[next.second.name]))),
							&nodes[current.second]};
								
						// open.push({nodes[next.second.name].f()), next.second.name}); // push node into queue to be explored
						open.push({pow(nodes[next.second.name].f(), 2), next.second.name}); 
						// push node into queue to be explored, f() score is squared before pushing to queue to ensure highest cost potential next nodes are explored later
						// I found that squaring f() tended to lead to more optimal paths
					}
				}
			}
		}
	}
	
	if (solutions.empty()){
		"\n***PATH NOT FOUND ***\n";
		return "PATH NOT FOUND";
	}
	// return route;	
	// cout << "\nSOLUTION FOUND\n cost: " << solutions.top().first << "\n";
	return solutions.top().second; // lowest cost solution found
};

int main(int argc, char **argv)
{
	// Begin timing
	auto start = high_resolution_clock::now();

    if (argc != 4)
    {
        cout << "Error: requires csv path, initial supercharger names, and final supercharger names" << endl;        
        return -1;
    }
    
    string charger_csv_path = argv[1];
    string initial_charger_name = argv[2];
    string goal_charger_name = argv[3];

	unordered_map<string, Location> locations;
	locations = readLocations(charger_csv_path, locations);

	// Pathfinding Algorithm
	string path = aStar(initial_charger_name, goal_charger_name, locations);
	// if (!path.empty()){cout << "\n\nOUTPUT:\n\n" << path;}
	if (!path.empty()){cout << path;} // REQUIRED STANDARD OUTPUT
	
	// After function call
	auto stop = high_resolution_clock::now();
	// Subtract stop and start timepoints and
	// cast it to required unit. Predefined units
	// are nanoseconds, microseconds, milliseconds,
	// seconds, minutes, hours. Use duration_cast()
	// function.
	auto duration = duration_cast<milliseconds>(stop - start);
	// To get the value of duration use the count()
	// member function on the duration object

	// cout << "\n\n time taken to execute main(): " << duration.count() << " ms" << endl;

	return 0;
}