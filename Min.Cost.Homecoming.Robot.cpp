#include<iostream> 
#include<vector>
#include<queue> 
#include<climits> 

using namespace std; 

class Solution{
public: 
     int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts){
        int m = rowCosts.size(); 
        int n = colCosts.size(); 
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; 
        pq.push({0, startPos[0], startPos[1]}); 
        vector<int> direction={-1,0,1,0,-1}; 
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX)); 
        dist[startPos[0]][startPos[1]]=0; 
        while(!pq.empty()){
            auto [dis, x,y] = pq.top(); 
            pq.pop(); 
            if (dis > dist[x][y]) continue;
            if(x == homePos[0]&& y == homePos[1]) return dis; 
            for(int k=0; k<4; ++k){
                int dx = x+ direction[k]; 
                int dy = y +direction[k+1]; 
                if(dx>=0 && dx <m && dy >=0 && dy <n ){
                    int moveCost = (dx != x) ? rowCosts[dx] : colCosts[dy];
                    int newCost = dis + moveCost;
                    if(newCost< dist[dx][dy]) {
                        dist[dx][dy] = newCost; 
                        pq.push({newCost, dx,dy}); 
                    }
                }
            }
        }
        return -1; 
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
