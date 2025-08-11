#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
   int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
     int m = rowCosts.size();
     int n = colCosts.size(); 
     int cost =0; 
     int r = startPos[0]; 
     int c = startPos[1]; 
     while(r!= homePos[0]){
       r += (r<homePos[0]) ? 1 : -1; 
       cost += rowCosts[r]; 
     }
     while(c!=homePos[1]){
       c += (c<homePos[1])? 1: -1; 
       cost += colCosts[c]; 
     }
     return cost; 
   }
};
int main(){
  vector<int> startPos = {1,0};
  vector<int> homePos = {2,3}; 
  vector<int> rowCosts= {5,4,3};
  vector<int> colCosts = {8, 2, 6, 7};
  Solution sol; 
  cout << sol.minCost(startPos, homePos, rowCosts, colCosts) <<endl; 
  return 0; 
}
