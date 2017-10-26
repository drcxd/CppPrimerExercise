/* I think the Employee class don't need special copy-control members.
   When the object of Employee is copyed, the name should be
   copyed. The promblem showed up when we discuss whether the m_eid
   should be copyed. If the m_eid is not copyed, then there will be
   two Employee with the same name but share the different ID. In the
   real world this will happen. However, this will happen by accident
   but not when we intend to copy one object to another. When we want
   to copy, we want the two object share the same content. For this
   particular example, use the synthesized copy-control member doesn't
   cause trouble.
*/

#include <string>

class Employee {
public:
    Employee() { eid = id_number++; }
    Employee(std::string &name) : m_name(name) { eid = id_number++; }
    Employee(const Employee &) = default;
    const Employee &operator=(const Employee &) = default;
private:
    static int id_number = 10000;

    std::string m_name;
    int m_eid;
};
