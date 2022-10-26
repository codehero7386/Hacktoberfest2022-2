-------------------- BASIC STRUCTURE ---------------------------

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define append push_back
#define list make_pair
#define endl "\n";


int32_t main(){
    IOS
    
	#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif


	return 0;
}




-------------------------------- VECTORS ------------------------

vector<int> v;

vector<int> v;
v.push_back(2);
v.push_back(5);
v.push_back(1);
v.push_back(3);
v.push_back(4);

v.pop_back();

v.erase(v.begin());

v.erase(v.begin() + v.size() - 1);

v.front();

v.back();

v.size();

v.empty();

v[0] = 10;
v[1] = 20;
v[2] = 30;
cout << v[0] << endl; // 10
cout << v[1] << endl; // 20
cout << v[2] << endl; // 30

v.clear();

#include <algorithm>
sort(v.begin(), v.end());

#include <algorithm>
sort(v.begin(), v.end(), greater<int>());

vector<int>::iterator low;
low = lower_bound(A.begin(), A.end(), key); //if found returns first occurence else where to be placed

vector<pair<string,double>> revenue; //pairing
revenue.push_back(make_pair("string",map[i].second));
revenue[i].first //accessing
revenue[i].second //accessing

------------------------------- STRING STREAM --------------------------

2,3,4,5

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> ans;
    int temp;
    char ch;
    while(ss >> temp){
        ans.push_back(temp);
        ss >> ch;
    }
    return ans;
}

--------------------------- STRINGS -------------------------------------

string a = "abc";

int len = a.size();

string a = "abc";
string b = "def";
string c = a + b; // c = "abcdef".

string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'

s[0] = 'z';         // s = "zbc"

--------------------------- SETS -------------------------------------------

set<int>s; //Creates a set of integers.

int length=s.size(); //Gives the size of the set.

s.insert(x); //Inserts an integer x into the set s.

s.erase(val); //Erases an integer val from the set s.

set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().

--------------------------- MAPS ----------------------------------------------

map <key_type, data_type>;

map<string,int>m; //Creates a map m where key_type is of type string and data_type is of type int.

int length=m.size(); //Gives the size of the map.

m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.

m.erase(ke); //Erases the pair from the map where the key_type is val.

map<string,int>::iterator itr=m.find(key); //Gives the iterator to the element val if it is found otherwise returns m.end() .
Ex: map<string,int>::iterator itr=m.find("Maps"); //If Maps is not present as the key value then itr==m.end().

To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.

------------------------------ DEQUE ----------------------------------------

deque<int> mydeque;

int length = mydeque.size();

mydeque.push_back(1); 
mydeque.push_front(2);

mydeque.pop_back();
mydeque.pop_front();

mydeque.empty()

--------------------------- QUEUE ----------------------------------------
queue <int> gquiz; 
gquiz.push(10); 
gquiz.size()
gquiz.front()
gquiz.back()
gquiz.pop()
showq(gquiz); //Displays Queue elements

--------------------------- STACKS ----------------------------------------
stack<int> stk;
stk.empty()
stk.size()
stk.top()
stk.push(x)
stk.pop()