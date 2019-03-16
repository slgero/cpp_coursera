#include <iomanip>
#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>
//#include "profile.h"

//#include "test_runner.h"
using namespace std;

struct Hotel {
    int ID;
    string hotelname;
    int roooms;
};

class Event {
public:
    Event() : num(0), sum(0) {}
    
    void BOOK(const int64_t& time, const string& hotel_name, const int& client_id, const int& room_count) {
       time_.push(time);
       h.push_back({client_id, hotel_name, room_count});
       name_rooms[hotel_name]+=room_count;       
       pop[hotel_name][client_id]++;
       ParseTime(time);
       ParseID();
    }
    
    int ROOMS(const string& s) {
        return name_rooms[s];
    }
    
    int CLIENTS(const string& s) {
        return pop[s].size();
    }
    
    void pol() {
        cout << "sum = " << sum << "num = " << num << endl;
    }
private:
    int num; // счётчик
    int sum; // счётчик 
    map<string, int> name_rooms; // будем сразу добавлять или удалять количество отелей
    map<string, map<int, int>> pop;
    queue<int64_t> time_;
    vector<Hotel> h; // ветор структуры
  
    void ParseTime(const int64_t& t) {
        while(!time_.empty() && time_.front() <= t - 86400) { // 86400
             time_.pop();
            ++sum;
        }
    }
    
    void ParseID() {
    for(int i = num; i < sum; ++i){      
  /* у нас есть специальная структура
         в ней находeм имя отеля, в котором будем удалять,
         затем находeм количество комнат, которые будут удалены.*/ 
        name_rooms[h[i].hotelname]-= h[i].roooms;
        
        --pop[h[i].hotelname][h[i].ID];
        if(pop[h[i].hotelname][h[i].ID]==0) {
            pop[h[i].hotelname].erase(h[i].ID);
        }
        ++num;
    }
}
};



int main() {

////   Для ускорения чтения данных отключается синхронизация
//   cin и cout с stdio,
//   а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Event e;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    
    if (query_type == "BOOK") {
      int64_t time;
      int client_id, room_count;
      string hotel_name;
      cin >> time >> hotel_name >> client_id >> room_count;
      e.BOOK(time, hotel_name, client_id, room_count);
    } else if (query_type == "CLIENTS") {
      string hotel_name; 
      cin >> hotel_name;
      cout << e.CLIENTS(hotel_name) << "\n";
    } else if (query_type == "ROOMS") {
      string hotel_name; 
      cin >> hotel_name;
      cout << e.ROOMS(hotel_name) << "\n";  
    }
  }
  return 0;
}

