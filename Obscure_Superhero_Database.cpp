#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int NUM_HEROES = 10;

// Parallel Arrays
string names[NUM_HEROES] = {
    "Captain Canuck", "Moon Girl", "El Muerto", "Snowflame",
    "Jack of Hearts", "Maggott", "Big Bertha", "The Heckler",
    "Nemesis", "Zeitgeist"
};

string superpowers[NUM_HEROES] = {
    "Enhanced Strength and Reflexes", "Genius Intellect", "Luchador Powers",
    "Cocaine Empowerment", "Energy Blasts", "Sentient Slugs", "Body Expansion",
    "Chaos Induction", "Illusion Manipulation", "Acid Vomit"
};

string weaknesses[NUM_HEROES] = {
    "Limited Resources", "Youth Inexperience", "Loss of Mask",
    "Sobriety", "Power Overload", "Slug Dependency", "Self-esteem",
    "Obscurity", "Mental Fatigue", "Stomach Irritation"
};

// Multidimensional Array for Year and Universe
int metadata[NUM_HEROES][2] = {
    {1975, 2}, {2015, 0}, {2006, 0}, {1988, 1},
    {1976, 0}, {1997, 0}, {1989, 0}, {1992, 1},
    {1983, 1}, {2001, 2}
};
// 0 = Marvel, 1 = DC, 2 = Other
string universeNames[] = {"Marvel", "DC", "Other"};

// Helper Functions
string toLowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string toUpperStr(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

void displayHero(int i, bool toUpper = false, bool toLower = false) {
    string name = names[i];
    string power = superpowers[i];
    string weak = weaknesses[i];

    if (toUpper) {
        name = toUpperStr(name);
        power = toUpperStr(power);
        weak = toUpperStr(weak);
    } else if (toLower) {
        name = toLowerStr(name);
        power = toLowerStr(power);
        weak = toLowerStr(weak);
    }

    cout << "Name: " << name << "\nSuperpower: " << power << "\nWeakness: " << weak;
    cout << "\nYear Introduced: " << metadata[i][0] << "\nUniverse: " << universeNames[metadata[i][1]] << "\n\n";
}

void searchByName(string query) {
    query = toLowerStr(query);
    bool found = false;
    for (int i = 0; i < NUM_HEROES; i++) {
        if (toLowerStr(names[i]).find(query) != string::npos) {
            displayHero(i);
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that name.\n";
}

void findByPower(string query) {
    query = toLowerStr(query);
    bool found = false;
    for (int i = 0; i < NUM_HEROES; i++) {
        if (toLowerStr(superpowers[i]).find(query) != string::npos) {
            displayHero(i);
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that power.\n";
}

void sortAlphabetically() {
    for (int i = 0; i < NUM_HEROES - 1; i++) {
        for (int j = i + 1; j < NUM_HEROES; j++) {
            if (toLowerStr(names[i]) > toLowerStr(names[j])) {
                swap(names[i], names[j]);
                swap(superpowers[i], superpowers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(metadata[i], metadata[j]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically!\n";
}

void displayAll(bool upper = false, bool lower = false) {
    for (int i = 0; i < NUM_HEROES; i++) {
        displayHero(i, upper, lower);
    }
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n==== Superhero Database ====" << endl;
        cout << "1. Search by Name\n2. Find by Superpower\n3. Sort Alphabetically\n4. Display All (Uppercase)\n5. Display All (Lowercase)\n6. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name to search: ";
                getline(cin, input);
                searchByName(input);
                break;
            case 2:
                cout << "Enter superpower to search: ";
                getline(cin, input);
                findByPower(input);
                break;
            case 3:
                sortAlphabetically();
                break;
            case 4:
                displayAll(true);
                break;
            case 5:
                displayAll(false, true);
                break;
            case 6:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
