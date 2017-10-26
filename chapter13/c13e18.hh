#include <string>

class Employee {
public:
    Employee() { eid = id_number++; }
    Employee(std::string &name) : m_name(name) { eid = id_number++; }
private:
    static int id_number = 10000;

    std::string m_name;
    int m_eid;
};
