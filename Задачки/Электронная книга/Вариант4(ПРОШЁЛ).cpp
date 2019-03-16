#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
//#include "profile.h"

using namespace std;

class ReadingManager {
public:
    ReadingManager() : pages_(1001) {}
    void Read(int user_id, int page_count) { // тут два случая - либо человек уже есть в базе, либо его нет
        if (users_.count(user_id) != 0) { // если человек уже есть в базе 
            int old_page = users_[user_id];  
            for(int i = old_page+1; i <= page_count; ++i){
                pages_[i]-= 1;
            }
            users_[user_id] = page_count; 
        } else { // на тот слуай, когда мы заводим нового
            users_[user_id] = page_count; // добавляем человека O(~log10^2.5) armot const
            for(int i = page_count+1; i < 1001; ++i) {
                pages_[i] += 1;
            }
        }
    }
    
    double Cheer(int user_id)  { 
        if(users_.count(user_id) != 0) { // Если человека ещё нет в базе
            if (users_.size()-1 == 0) {
                return 1.0;
            } else {
                int kek = users_.at(user_id);
                return pages_[kek]*1.0/(users_.size()-1);
            }
        } else {
            return 0.0;
        }
    }
    
private:
    map<int, int> users_; // map<Id, Page>
    vector<int> pages_; // map<Page, map<Raiting>>
};

int main() {
    
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
