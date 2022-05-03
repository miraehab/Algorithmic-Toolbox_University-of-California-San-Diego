#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  vector <vector<int>> edit_dist((str1.length() + 1), vector <int> (str2.length() + 1));

  for (int i = 0; i <= str1.length(); ++i){
      for (int j = 0; j <= str2.length(); ++j){
        
          if (i == 0){ 
            edit_dist[i][j] = j;
          }else if(j == 0){ 
            edit_dist[i][j] = i;
          }else if(str1[i - 1] == str2[j - 1]){ 
            edit_dist[i][j] = edit_dist[i - 1][j - 1];
          }else{ 
            edit_dist[i][j] = 1 + min({edit_dist[i][j - 1], edit_dist[i - 1][j],  edit_dist[i - 1][j - 1]});
          }

        }
    }

    return edit_dist[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
