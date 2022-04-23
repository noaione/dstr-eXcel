#include <iostream>

#include "impl/linkedlist.hpp"
#include "impl/arraystruct.hpp"
#include "utils/menu.hpp"
#include "utils/utils.hpp"
#include "types/date.hpp"

typedef struct Test {
    int id;
    int age;
} Test;

#ifdef LINKED_LIST
void testListFormat() {
    std::cout << "Executing linked list version test..." << std::endl;
    Test* testdata = new Test;
    testdata->id = 1;
    testdata->age = 20;
    LinkedList<Test*>* llTest = new LinkedList<Test*>();
    llTest->insert(testdata);
}
#else
void testListFormat() {
    std::cout << "Executing array struct version test..." << std::endl;
    Test* testData = new Test;
    testData->id = 1;
    testData->age = 20;
    // ArrayStruct<Test>* asTest = new ArrayStruct<Test>();
    // asTest->insert(*testData);
}
#endif

int main()
{
    std::cout << "Hello World!" << std::endl;
    Date date = Date::now();
    std::cout << date.fmt("dd mm yyyy") << std::endl;
    std::cout << date.fmt("dd m yyyy") << std::endl;
    std::cout << date.toString() << std::endl;
    testListFormat();
    return 0;
}
