#include <iostream>
#include <string>
#include "unorderedSetType.h"

using namespace std;

int main()
{
    // Create an array of integers and an array of strings.
    int intArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    string strArray[] = { "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "ice cream", "jackfruit" };

    // Create an unorderedSet object that will contain integers and add the values from the integer array to the set (use insertEnd).
    unorderedSetType<int> intSet(20); // Increased size to 20
    for (int i = 0; i < 10; i++)
        intSet.insertEnd(intArray[i]);

    // Create another unorderedSet object that will contain strings and add the values from the string array to the set (use insertEnd).
    unorderedSetType<string> strSet(10); // Increased size to 10
    for (int i = 0; i < 10; i++)
        strSet.insertEnd(strArray[i]);

    // Verify that insertEnd will not allow a duplicate entry to be made in each of the sets (use the print function to display the results).
    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Verify that insertAt will allow a unique item, but not a duplicate entry to be made in each of the sets.
    intSet.insertAt(0, 11);
    strSet.insertAt(0, "fig");
    cout << "Integer Set after insertAt: ";
    intSet.print();
    cout << "String Set after insertAt: ";
    strSet.print();

    // Verify that replaceAt will allow a unique item, but not a duplicate entry to be made in each of the sets.
    intSet.replaceAt(0, 12);
    strSet.replaceAt(0, "grape");
    cout << "Integer Set after replaceAt: ";
    intSet.print();
    cout << "String Set after replaceAt: ";
    strSet.print();

    // To test your union and intersection operations. Create three sets for each data type. Add items to two of them. Perform the union operation by adding the two sets and assigning the result to the third set. Repeat for the intersection operation.
    unorderedSetType<int> intSet2(10);
    for (int i = 5; i < 15; i++)
        intSet2.insertEnd(i);
    unorderedSetType<int> intUnionSet = intSet + intSet2;
    unorderedSetType<int> intIntersectSet = intSet - intSet2;
    cout << "Integer Union Set: ";
    intUnionSet.print();
    cout << "Integer Intersection Set: ";
    intIntersectSet.print();

    unorderedSetType<string> strSet2(5);
    for (int i = 2; i < 7; i++)
        strSet2.insertEnd(strArray[i]);
    unorderedSetType<string> strUnionSet = strSet + strSet2;
    unorderedSetType<string> strIntersectSet = strSet - strSet2;
    cout << "String Union Set: ";
    strUnionSet.print();
    cout << "String Intersection Set: ";
    strIntersectSet.print();

    return 0;
}
