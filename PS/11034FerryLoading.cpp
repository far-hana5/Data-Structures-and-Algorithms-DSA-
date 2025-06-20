/*
11034 Ferry Loading IV
Before bridges were common, ferries were used
to transport cars across rivers. River ferries,
unlike their larger cousins, run on a guide line
and are powered by the river’s current. Cars
drive onto the ferry from one end, the ferry
crosses the river, and the cars exit from the
other end of the ferry.
There is an l-meter-long ferry that crosses
the river. A car may arrive at either river bank
to be transported by the ferry to the opposite
bank. The ferry travels continuously back and
forth between the banks so long as it is carrying
a car or there is at least one car waiting at either
bank. Whenever the ferry arrives at one of the
banks, it unloads its cargo and loads up cars
that are waiting to cross as long as they fit on its deck. The cars are loaded in the order of their arrival;
ferry’s deck accommodates only one lane of cars. The ferry is initially on the left bank where it broke
and it took quite some time to fix it. In the meantime, lines of cars formed on both banks that await
to cross the river.
Input
The first line of input contains c, the number of test cases. Each test case begins with l, m. m lines
follow describing the cars that arrive in this order to be transported. Each line gives the length of a
car (in centimeters), and the bank at which the car arrives (‘left’ or ‘right’).
Output
For each test case, output one line giving the number of times the ferry has to cross the river in order
to serve all waiting cars.
Sample Input
4
20 4
380 left
720 left
1340 right
1040 left
15 4
380 left
720 left
1340 right
1040 left
15 4
380 left
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int c; // number of test cases
    cin >> c;

    while (c--) {
        int l, m;
        cin >> l >> m;
        l *= 100; // convert ferry length to centimeters

        queue<int> left, right;
        for (int i = 0; i < m; ++i) {
            int carLength;
            string side;
            cin >> carLength >> side;
            if (side == "left") {
                left.push(carLength);
            } else {
                right.push(carLength);
            }
        }

        bool onLeft = true; // ferry starts on left
        int trips = 0;

        while (!left.empty() || !right.empty()) {
            int space = l;

            // Load cars from current side
            if (onLeft) {
                while (!left.empty() && left.front() <= space) {
                    space -= left.front();
                    left.pop();
                }
            } else {
                while (!right.empty() && right.front() <= space) {
                    space -= right.front();
                    right.pop();
                }
            }

            // One crossing
            trips++;
            onLeft = !onLeft; // change side
        }

        cout << trips << endl;
    }

    return 0;
}
