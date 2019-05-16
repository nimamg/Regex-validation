#include <iostream>
#include <string>

using namespace std;

int main () {
  string str, rgx,rgxtemp;
  cin >> str >> rgxtemp;
  int si = 0 , ri = 0, ls = -1;
  str += "$";
  rgxtemp += "$";
  rgx = "";
  rgx += rgxtemp[0];
  for (int i = 1; i < rgxtemp.size() ; i++) {
    if (rgxtemp[i] == '*' && rgx[rgx.size() - 1] == '*') {
      continue;
    }
    rgx += rgxtemp[i];
  }
  string a;
  while (true) {
    //cerr << "in while" << endl;
    //cerr << rgx[ri] << " " << str[si] << endl;
    //cin >> a;
    if ((rgx[ri] == '$' && str[si] == '$') || (rgx[ri] == '*' && str[si] == '$' && rgx[ri+1] == '$')) {
      cout << "YES" << endl;
      return 0;
    }

    else if (str[si] == '$' && rgx[ri] != '$') {
      cout << "NO" << endl;
      return 0;
    }

    else if (rgx[ri] == '*' && str[si] == rgx[ri+1]) {
      //cerr << "rgx * and proceed" << endl;
      //cin >> a;
      ls = ri;
      ri+=2;
      si++;
    }

    else if (rgx[ri] == '*' && str[si] != rgx[ri+1]) {
      //cerr << "rgx * and NOT proceed" << endl;
      //cin >> a;
      ls = ri;
      si++;
    }

    else if (rgx[ri] == '?') {
      //cerr << "rgx ? and proceed" << endl;
      //cin >> a;
      si++;
      ri++;
    }

    else if (rgx[ri] == str[si]) {
      //cerr << "rgx = str proceed" << endl;
      //cin >> a;
      si++;
      ri++;
    }

    else if (rgx[ri] != str[si]) {
      //cerr << "rgx != Str" << endl;
      //cin >> a;
      if (ls != -1) {
        //cerr << "last star available " << endl;
        //cin >> a;
        ri = ls;
      }
      else {
        //cerr << "last star not available" << endl;
        cout << "NO" << endl;
        return 0;
      }
    }

  }
}
