#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;


struct Segment {
    int start, end;
};


vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points; //a clue

    //write your code here. heavily inspired from: https://medium.com/competitive/covering-segments-by-points-fc2c56c4b038
    //sort segments according to start time
    std::sort(segments.begin(), segments.end(), 
        [](const Segment a, const Segment b) {return a.start < b.start;});//this is a lambda expression

    Segment currSeg = segments[0];

    for (size_t i = 1; i < segments.size(); ++i){
        if (currSeg.end < segments[i].start) //if currSeg does not overlap with segments[i]
        {
            points.push_back(currSeg.start); //create new currSeg
            currSeg = segments[i];     
        }
        
        else //if curSeg overlaps with segments[i]
        {
            currSeg.start = std::max(segments[i].start, currSeg.start); //move curSeg around 
            currSeg.end = std::min(segments[i].end, currSeg.end);
        }
        
        for (int i = 0; i < points.size(); i++)
        {
            std::cout << points[i] << "\n";
        }
    }
    
    points.push_back(currSeg.start);
    return points;
}


int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
    }
    
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
