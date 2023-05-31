class UndergroundSystem {
public:
    unordered_map<string, pair<long long, int>> times;
    unordered_map<int, pair<string, int>> in;
    
    UndergroundSystem() {
        times.clear();
        in.clear();
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(in.find(id) != in.end()){
            return;
        }
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &info = in[id];
        string startStation = info.first;
        int startTime = info.second;
        
        string key = startStation + ":" + stationName;
        int time = t - startTime;
        
        if(times.find(key) != times.end()){
            auto &oldTimes = times[key];
            oldTimes.first += time;
            oldTimes.second++;
        }
        else{
            times[key] = {time, 1};
        }
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto &info = times[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
