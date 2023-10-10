
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;
void Graph::dijkstraTraverse(string sourceVertex){ 
   vertex *vStart = search(sourceVertex); 
   if(!vStart){ 
      cout << "Start not found" << endl; 
      return; 
    }
   vStart->solved = true; 
   vStart->distDijk = 0; 
   // Create a list to store solved vertices 
   // and append vStart 
   vector<vertex*> solvedList; 
   solvedList.push_back(vStart); 
   // Will use this Boolean variable to leave the loop  
   // if all vertices have been solved 
   bool allSolved = false; 
   while(!allSolved){
        int minDist = INT_MAX;
      // pointer to keep track of solved node 
      vertex *solvedV = nullptr; 
      allSolved = true; 
      // iterate across list of solved vertices 
      for(int i=0; i<solvedList.size(); i++){ 
         vertex *s = solvedList[i];
         // now iterate s's adjacency list 
         for(int j=0; j<s->adj.size(); j++){ 
            if(!s->adj[j].v->solved){ 
               // calculate the distance from vStart 
               int dist = s->distDijk + s->adj[j].weight; 
               // check if the distance is less than 
               // smallest distance thus far 
               if(dist<minDist){ 
                  solvedV = s->adj[j].v; 
                  minDist = dist; 
               } 
               allSolved = false; 
            }                     
         }          
      }
    } 
    if(!allSolved){ 
         solvedV->distDijk = minDist; 
         solvedV->solved = true; 
         solvedList.push_back(solvedV); 
    } 
} 