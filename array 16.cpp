
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
        int i,j,n;

        n=nums.size();
        unordered_set<int> uset;

        for(i=0;i<n;++i){
            if(uset.find(nums[i])==uset.end()){
                uset.insert(nums[i]);
            }
            else
                return nums[i];
        }

    }

