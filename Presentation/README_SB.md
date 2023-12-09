
# Autopilot Simulation Challenge README - Sharome Burton
 
My objective is to construct a search algorithm to find the minimum time path through a hypothetical network of Tesla supercharging stations. The final route does not have to fully charge at every visited charger, so long as it never runs out of charge between two chargers.

## My rough approach

I first considered an approach of computing all distances between each location, then brute forcing the shortest path. With a dataset size of 302 locations, this could be a worthwhile approach but it would not be reasonably scalable as the size of the charger network increases.

I ultimately decided to use an A* algorithm, using the minimum possible time required to travel from the starting location to the goal location along a great circle as the heuristic. This minimum time considers the time needed to drive along that range + the minimum time needed to spend at chargers to have just enough range for the entire journey. 

My approach aims for the car to reach to the goal with near zero range remaining and have near zero range remaining when it stops at a supercharger to charge. The minimum amount of range the car should ever have (measured in hours of charging at 800km/h) is represented by **double safetyFactor**. The car will charge just enough to get enough range to reach the next supercharger along the route. 

The function *distToTime()* converts this great circle distance to an optimal journey time in hours.Only locations  within 320km geodesic range are of the current node are considered as candidates to be visited. 

As each node is visited, a pointer to the previous node (if that step is seen as a more optimal one than another way of getting to that node) is saved within the data structure representing each location (**struct Location**).

This method should always return a valid path to the goal, if it exists, within reasonable time.

The drawback of this approach is that it may not always return the perfectly optimal path.

## How to run

I provide the solution in **main.cpp**.

This submission compiles under gcc with optimization level 1, for example:

    g++ -std=c++17 -O1 main.cpp -o solution

This submission does not use libraries outside of the C++ Standard Library.


The charger network data is in the format below with newlines separating each charger:
  
    name, latitude in degrees, longitude in degrees

The program takes as input three strings:

    ./solution [path to list of chargers csv] [start charger name] [end charger name]

 The program’s only output is a print to standard out in the format:
 
    initial charger name, first charger name, charge time in hrs, second charger name, charge time in hrs, …, …, goal charger name

The following assumptions were made:

- The car begins at the start charger with a full charge of 320km
- The superchargers have a charge rate of 800km/hr
- The car travels at a constant speed of 105km/hr along great circle routes between chargers
- The Earth is a sphere of radius 6356.752km


## References:

**GREAT CIRCLE DISTANCE FORMULA**

[https://www.geeksforgeeks.org/great-circle-distance-formula/](https://www.geeksforgeeks.org/great-circle-distance-formula/)

d = rcos-1[cos a cos b cos(x-y) + sin a sin b]

**GREAT CIRCLE VS GEODESIC DISTANCE**

[https://gis.stackexchange.com/questions/308508/difference-between-geodetic-distance-and-great-circle-distance](https://gis.stackexchange.com/questions/308508/difference-between-geodetic-distance-and-great-circle-distance)

**MEASURING EXECUTION TIME IN C++**

[https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/](https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/)

**A-STAR ALGORITHM**

[https://isaaccomputerscience.org/concepts/dsa_search_a_star?examBoard=all&stage=all](https://isaaccomputerscience.org/concepts/dsa_search_a_star?examBoard=all&stage=all)

[https://en.wikipedia.org/wiki/A*_search_algorithm#Description](https://en.wikipedia.org/wiki/A*_search_algorithm#Description)

**LAT/LONG TO KM**

[https://stackoverflow.com/questions/1253499/simple-calculations-for-working-with-lat-lon-and-km-distance](https://stackoverflow.com/questions/1253499/simple-calculations-for-working-with-lat-lon-and-km-distance)

**BALLPARK DISTANCE ESTIMATES BETWEEN LOCATIONS**

https://www.google.com/maps/

**REVERSING A PRIORITY QUEUE**
https://stackoverflow.com/questions/15647162/priority-queue-in-reverse-order

