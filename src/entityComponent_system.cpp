#include <SFML/Graphics.hpp>
#include <string>

class C_Base
{
public:
    // Component is an enum
    // Constructor for the class, initializes m_type mem var with the value of l_type
    C_Base(const Component& l_type): m_type(l_type){}
    // Virtual destructor 
    virtual ~C_Base(){}

    Component GetType() const { return m_type; }

    friend std::stringstream& operator >>(
        std::stringstream& l_stream, C_Base& b)
    {
        b.ReadIn(l_stream);
        return l_stream;
    } 
    virtual void ReadIn(std::stringstream& l_stream) = 0;
protected:
    Component m_type;
}