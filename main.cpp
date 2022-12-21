#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object {
private:
    string m_name;
    vector<int> m_coordinates;

public:
    Object(string name, int x, int y) : m_name(name) {
        m_coordinates.push_back(x);
        m_coordinates.push_back(y);
    }

    string getCoordinates() {
        return "x = " + to_string(m_coordinates[0]) + " y = " + to_string(m_coordinates[1]);
    }

    string getName() { return m_name; }

    void rearrange(int x, int y) {
        m_coordinates[0] = x;
        m_coordinates[1] = y;
    }
};

class Bed : public Object {
public:
    Bed(string name, int x, int y) : Object(name, x, y) {}
};

class Carpet : public Object {
public:
    Carpet(string name, int x, int y) : Object(name, x, y) {}
};

class Table : public Object {
public:
    Table(string name, int x, int y) : Object(name, x, y) {}
};

class Room {
private:
    string m_name;
    std::vector<Object *> m_objects;

public:
    Room(string name) : m_name(name) {
    }

    void add(Object *object) {
        m_objects.push_back(object);
    }

    void remove(int position) {
        if (position < m_objects.size() & position >= 0){
            m_objects.erase(m_objects.begin() + position);
            }
        else{
            cout << "Wrong position" << endl;
            }
    }

    void rearrangement(int position, int x, int y) {
        m_objects[position]->rearrange(x, y);
    }

    void print_objects() {
        for (auto obj: m_objects){
            cout << obj->getName() << ' ' << obj->getCoordinates() << endl;
        cout<<endl;
    }
    }

};


int main() {
    Room room1{"My room"};

    Bed bed1{"My bed", 10, 10};
    Carpet carpet1{"My carpet", 25, 25};
    Table table1{"My table", 1, 5};

    room1.add(&bed1);
    room1.add(&carpet1);
    room1.add(&table1);


    room1.print_objects();

    room1.rearrangement(0, 5, 5);

    room1.print_objects();

    room1.remove(1);

    room1.print_objects();

    return 0;
}