#include <bits/stdc++.h> /* 万能头 */

using namespace std;

int main(int argc, char **argv) {
  namespace fs = std::filesystem;
  fs::path pathToShow("/home/adl/a.txt");
  cout << "exists() = " << fs::exists(pathToShow) << "\n"
       << "root_name() = " << pathToShow.root_name() << "\n"
       << "root_path() = " << pathToShow.root_path() << "\n";
}