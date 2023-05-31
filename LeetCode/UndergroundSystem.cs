// https://leetcode.com/problems/design-underground-system/description/
// Use dictionary to support all operations in O(1) time

public class UndergroundSystem {
    Dictionary<string, Dictionary<string, (int, int)>> stations = new  Dictionary<string, Dictionary<string, (int, int)>>(); // stationId -> {stationId -> (time, n)}
    Dictionary<int, (string, int)> checkin = new Dictionary<int, (string, int)> (); // id -> (stationId, checkInTime)

    public UndergroundSystem() {
    }
    
    public void CheckIn(int id, string stationName, int t) {
        checkin[id] = (stationName, t);
    }
    
    public void CheckOut(int id, string stationName, int t) {
        (string checkInStation, int checkInTime) = checkin[id];
        if (!stations.ContainsKey(checkInStation)) {
            stations.Add(checkInStation, new Dictionary<string, (int, int)>());
        }
        if (!stations[checkInStation].ContainsKey(stationName)) {
            stations[checkInStation].Add(stationName, (0, 0));
        }

        var temp = stations[checkInStation][stationName];
        temp.Item1 += t - checkInTime;
        temp.Item2++;
        stations[checkInStation][stationName] = temp;
    }
    
    public double GetAverageTime(string startStation, string endStation) {
        if (stations.ContainsKey(startStation) && stations[startStation].ContainsKey(endStation)) {
            return 1.0 * stations[startStation][endStation].Item1 / stations[startStation][endStation].Item2;
        }
        return 0;   
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * double param_3 = obj.GetAverageTime(startStation,endStation);
 */