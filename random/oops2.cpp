/*
Question: Create a dynamic object named dhoni of the following class. Don’t use a constructor here, that means you need to fill the data by yourself.
Cricketer
{
	jersey_no;
	country;
}
Then make another dynamic object named kohli and copy the data of the dhoni object to kohli and after that delete the dhoni object. Then print the jersey_no and country of kohli object.
Note: At first try to do this, kohli=dhoni and see if it gives the correct output. If not, then think deeply why it didn’t work and try to copy the data manually like kohli->jersey_no=dhoni->jersey_no; 

*/

#include <iostream>
using namespace std;

class Cricketer {
public:
    int jersey_no;
    string country;
};

int main() {
    // Create dynamic object dhoni
    Cricketer* dhoni = new Cricketer;

    // Manually assign values
    dhoni->jersey_no = 7;
    dhoni->country = "India";

    // Try shallow copy using assignment
    Cricketer* kohli = new Cricketer;
    // This would NOT work: kohli = dhoni; // It just makes kohli point to same memory as dhoni

    // Instead, manually copy the data
    kohli->jersey_no = dhoni->jersey_no;
    kohli->country = dhoni->country;

    // Delete dhoni object
    delete dhoni;

    // Print kohli's data
    cout << "Jersey No: " << kohli->jersey_no <<"\n";
    cout << "Country: " << kohli->country <<"\n";

    // Clean up
    delete kohli;

    return 0;
}
/*
Why kohli = dhoni; doesn't work:
kohli = dhoni; makes both pointers point to the same memory.

Deleting dhoni would then make kohli a dangling pointer, and accessing it would be undefined behavior.

Hence, you must copy data manually:
kohli->jersey_no = dhoni->jersey_no;
*/