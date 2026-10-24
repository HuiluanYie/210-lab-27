// COMSC-210 | Lab 27 | Huiluan Yie

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    // The key is the villager's name.
    // The tuple stores friendship level, species, and catchphrase.
    map<string, tuple<int, string, string>> villager;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villager["Audie"] = make_tuple(8, "Wolf", "foxtrot");
    villager["Raymond"] = make_tuple(10, "Cat", "crisp");
    villager.insert({"Marshal", make_tuple(7, "Squirrel", "sulky")});

    // access the map using a range-based for loop
    cout << "Villagers and details(range-based for loop):" << endl;
    for (auto pair : villager) {
        cout << pair.first << ": ";
        cout << "Friendship level: " << get<0>(pair.second) << '\n';
        cout << "Species: " << get<1>(pair.second) << '\n';
        cout << "Catchphrase: " << get<2>(pair.second) << '\n';
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and details(iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villager.begin(); 
                                               it != villager.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < 3; i++) {
            cout << get<i>(it->second) << " ";
        }
        cout << endl;
    }

    // delete an element
    villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villager.find(searchKey);
    if (it != villager.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager.size() << endl;
    villager.clear();
    cout << "Size after clear: " << villager.size() << endl;

    return 0;
}
