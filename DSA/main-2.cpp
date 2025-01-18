#include <bits/stdc++.h>
using namespace std;// For std::advance and std::next
#define pt pair<int,tuple<int,int,int>>


void findsteps(pt state,pt target, pt cap,map<pt,pt> &dp){
    /// If target found
    if(dp.find(target) != dp.end()){
        // cout<<"Found target";
        
        
        // do{
        //     int s1 = target.first;
        //     auto [s2,s3,s4] = target.second;
        //     cout<<"( "<< s1<<" , "<<s2<<" , "<<s3<<" , "<<s4<<")\n";
        //     target = dp[target];
        // } while(  target != dp[target] );
        return;
    }
    // checking if already calculated that step
    // if(dp.find(state) != dp.end() && state != {-1,{-1,-1,-1}}) return;
    
    
    ///checking each case;
    int j1 = state.first;
    auto [j2,j3,j4] = state.second;
    
    int c1 = cap.first;
    auto [c2,c3,c4] = cap.second;
    
    // pouring from j1
    if(j1 > 0 ){
         //j1 --> j2
         if (c2 - j2 > 0) {
            int fill = min(j1, c2 - j2);
            pt newstate = {j1-fill, {j2+fill,j3,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j1 --> j3
         if (c3 - j3 > 0) {
            int fill = min(j1, c3 - j3);
            pt newstate = {j1-fill, {j2,j3+fill,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j1 --> j4
         if (c4 - j4 > 0) {
            int fill = min(j1, c4 - j4);
            pt newstate = {j1-fill, {j2,j3,j4+fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
          
    }
    
    
    //poring from j2
    
    if(j2 > 0 ){
         //j2 --> j1
         if (c1 - j1 > 0) {
            int fill = min(j2, c1 - j1);
            pt newstate = {j1+fill, {j2-fill,j3,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j2 --> j3
         if (c3 - j3 > 0) {
            int fill = min(j2, c3 - j3);
            pt newstate = {j1, {j2-fill,j3+fill,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j2 --> j4
         if (c4 - j4 > 0) {
            int fill = min(j2, c4 - j4);
            pt newstate = {j1, {j2-fill,j3,j4+fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
          
    }
    
    
    //Pouring from j3
    
    if(j3 > 0 ){
         //j3 --> j1
         if (c1 - j1 > 0) {
            int fill = min(j3, c1 - j1);
            pt newstate = {j1+fill, {j2,j3-fill,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j3 --> j2
         if (c2 - j2 > 0) {
            int fill = min(j3, c2 - j2);
            pt newstate = {j1, {j2+fill,j3-fill,j4}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
        //j3 --> j4
         if (c4 - j4 > 0) {
            int fill = min(j3, c4 - j4);
            pt newstate = {j1, {j2,j3-fill,j4+fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
          
    }
    
    
    
    /// pouring from j4
    
    if(j4 > 0 ){
         //j4 --> j1
         if (c1 - j1 > 0) {
            int fill = min(j4, c1 - j1);
            pt newstate = {j1+fill, {j2,j3,j4-fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        //j4--> j2
         if (c2 - j2 > 0) {
            int fill = min(j4, c2 - j2);
            pt newstate = {j1, {j2+fill,j3,j4-fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
         
        //j4 --> j3
         if (c3 - j3 > 0) {
            int fill = min(j4, c3 - j3);
            pt newstate = {j1, {j2,j3+fill,j4-fill}};
                if(dp.find(newstate) == dp.end()) {
                    dp[newstate] = state;
                    findsteps(newstate,target,cap,dp);
                }
        }
        
         
    }
    
}


int main() {
    
    
    map<pt,pt> mp;
    
    //Starting
    int j1 = 6;
    int j2 = 6;
    int j3 = 0;
    int j4 = 0;
    ///Target
    int tr1 = 12;
    int tr2 = 0;
    int tr3 = 0;
    int tr4 = 0;
    
    //capacity
    int cj1 = 12;
    int cj2 = 13;
    int cj3 = 7;
    int cj4 = 3;
    
    
    // mp[{j1,{j2,j3,j4}}] = {-1,{-1,-1,-1}};
     mp[{j1,{j2,j3,j4}}] = {j1,{j2,j3,j4}};  //self parent
    
    findsteps({j1,{j2,j3,j4}}, {tr1,{tr2,tr3,tr4}},{cj1,{cj2,cj3,cj4}},mp);
    
    
    
    
    // for(auto k : mp){
    //     int c1 = k.first.first;
    //     auto [c2,c3,c4] = k.first.second;
        
    //     cout<<c1<<": "<<c2<<" "<<c3<<" "<<c4<<"\n";
    // }
    
    
    
    cout<<"Way to get target: ->\n ";
    
    pt target = {tr1,{tr2,tr3,tr4}};
    do{
            int s1 = target.first;
            auto [s2,s3,s4] = target.second;
            cout<<"( "<< s1<<" , "<<s2<<" , "<<s3<<" , "<<s4<<")\n";
            target = mp[target];
     } while(  target != mp[target] );
     
    
           int s1 = target.first;
            auto [s2,s3,s4] = target.second;
            cout<<"( "<< s1<<" , "<<s2<<" , "<<s3<<" , "<<s4<<")\n";
}
