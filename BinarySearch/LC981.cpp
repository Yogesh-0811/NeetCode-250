#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class TimeMap{
    public:
        unordered_map<string, vector<pair<int,string>>>map;

        void set(string key,string value, int timestamp){
            auto &arr = map[key];
            arr.push_back({timestamp,value});
        }

        string get(string key, int timestamp){
            if(map.find(key)==map.end()) return "";

            auto &arr = map[key];
            int low=0,high=arr.size()-1;
            string result = "";
            while(low<=high){
                int mid = low+(high-low)/2;
                if(arr[mid].first<=timestamp){
                    result=arr[mid].second;
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            return result;
        }
};

int main(){
    TimeMap timeMap;

    int q;
    cout<<"Enter number of queries: ";
    cin>>q;

    cout<<"Commands: "<<endl;
    cout<<"1 key value timestamp => set"<<endl;
    cout<<"2 key timestamp => get"<<endl;

    for(int i=0;i<q;i++){
        int type;
        cin>>type;

        if(type==1){
            string key, value;
            int timestamp;
            cin>>key>>value>>timestamp;
            timeMap.set(key,value,timestamp);
            cout<<"Set done"<<endl;
        }else if(type==2){
            string key;
            int timestamp;
            cin>>key>>timestamp;
            string res = timeMap.get(key, timestamp);
            cout<<"Value at "<<timestamp<<": "<<(res.empty()? "null":res)<<endl;
        }else{
            cout<<"Invalid Command."<<endl;
        }
    }
    return 0;
}