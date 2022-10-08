/*
    N-Queens Algorithm

    This program determines the position of n number of queens on an n x n board in which their positions do not conflict according to the rules of a chess game.
    The position of each queen must not be vertically, horizontally, or diagonally colliding with any other queens on the board.
    The positive integer n is user-defined, so the program will prompt the user to input an integer at the beginning.
    Stack data structure is implemented to keep track of the queens' position, forming "a Stack of Locations" to handle the 2D coordinates of each queen. 
        If a valid queen position is identified, the location is pushed to the stack.
        If the exisitng order does not provide a valid solution, the queens are popped from the stack for back-tracking and recalculating.
    After a solution is found for the n-queens problem, the program displays an n x n board with the position of the queens denoted as "Q" and their 2D coordinates.

    Data Structures: Stack, Struct (2D-coordinates)
*/

#include "main.h"
using namespace std;

// Function declaration to determine the position of each queen on an n x n board
void nQueens (int n, stack<location> Queens);

// Function declaration to check for collision between the queen's position (vertical, diagonal, horizontal)
bool checkForCollision(location next, stack<location> Queens);
bool checkDiagonalCollision(location one, location two);
bool checkVerticalCollision(location one, location two);

// Function declaration to draw and display the n x n board with the correct position of queens
void drawBoard(int n, stack<location> Queens);


int main() {
    int n;

    // Prompt user to input integer n for n number of queens and n x n board
    cout << "Please enter the value of N for N-Queens: " ;
    cin >> n ;

    // Invalid input n if n is less than 3
    if (n < 3)
    {
        cout << "There is no solution for " << n << "-Queens." << endl;
    }
    else
    {
        stack <location> Queens;
        nQueens(n, Queens);
    }
    return 0;
}

// nQueen Function initialization
void nQueens (int n, stack<location> Queens)
{
    bool keep_going = true;

    // Default location for the first queen 
    location first = {0,0};

    // Default location for the second queen
    location next = {2,1}; 

    // push the first Queen to the stack
    Queens.push(first);

    // One of the n queens is filled on the stack 
    int filled = 1; 
    bool conflict = false;
    while (keep_going)
    {
        conflict = checkForCollision(next, Queens);

        // If not conflicting -> add that location to stack as a Queen 
        if (!conflict)
        {
            Queens.push(next);

            // increment the number of queens filled
            filled ++; 
            cout << "A Queen was pushed at: " << "[" << Queens.top().x << ", " << Queens.top().y << "]" << endl;

            // If the stack is full, exit the while loop
            if (filled == n)
            {
                keep_going = false;
            }

            // If the stack is not full, start at a new row with column 0 to find the next Queen location
            else 
            {
                next.x = 0;
                next.y += 1;
            }
        }

        // If conflicting but the element is not at the last column of the row, increment to get to the next column
        else if (conflict && (next.x+1) < n)
        {
            next.x += 1;
        }

        // If conflicting and the element is at the last column of the row
        else
        {
            // Pop all queens on the stack that is already at the end of the row and cannot be shifted to the right
            while(!Queens.empty() && Queens.top().x == (n-1)){
                cout << "A Queen was popped at: " << "[" << Queens.top().x << ", " << Queens.top().y << "]" << endl;
                Queens.pop();
                filled --; // decrement the filled queens on stack once popped
            }

            // If the stack is not empty and there is more than one queen on stack
            if (!Queens.empty() && filled > 1)
            {
                next.x = Queens.top().x + 1;
                next.y = Queens.top().y;
                cout << "A Queen was popped at: " << "[" << Queens.top().x << ", " << Queens.top().y << "]" << endl;
                Queens.pop();
                filled --;
            }

            // If the stack is not empty and only one queen remains on stack
            else if (!Queens.empty() && filled == 1)
            {
                // Shift the queen to the next position. Since there is only one queen left, no conflict occurs
                next.x = Queens.top().x + 1;
                next.y = Queens.top().y;
                cout << "A Queen was popped at: " << "[" << Queens.top().x << ", " << Queens.top().y << "]" << endl;
                Queens.pop();
                Queens.push(next);
                cout << "A Queen was pushed at: " << "[" << Queens.top().x << ", " << Queens.top().y << "]" << endl;

                // Set next location to a new row of column 0
                next.x = 0;
                next.y += 1;
            }

            // If the stack is empty, then there is no solution to this n number of queens
            else
            {
                cout << "\nThere is no solution for " << n << "-Queens.\n" << endl;
                return;
            }
        }
    }

    // After the while loop, display the outcome of queens position on the board
    cout << "\nThere is a solution!\n" << endl;
    cout << "----------------------------------------------------------------\n";
    cout << "                  " << n << " x " << n << " Board with " << n << " Queens\n";
    cout << "----------------------------------------------------------------\n" << endl;
    drawBoard(n, Queens);
}

// Function to check for all collision 
bool checkForCollision(location next, stack<location> Queens)
{
    // Continuously get the top Queen of the stack
    while (!Queens.empty())
    {
        location queen = Queens.top();

        // If either one of the collision type function returns true, conflict occurs
        if (checkVerticalCollision(queen, next) || checkDiagonalCollision(queen, next))
        {
            // return true to indicate that the Queen and the next position is conflicting 
            return true;
        }
        Queens.pop();
    }
    return false;
}

// Function to check for diagonal collision
bool checkDiagonalCollision(location one, location two)
{
    if (abs(one.x - two.x) == abs(one.y - two.y))
        return true;
    return false;
}

// Function to check for vertical collision
bool checkVerticalCollision(location one, location two)
{
    if (one.x == two.x)
        return true;
    return false;
}

// drawBoard Function
void drawBoard(int n, stack<location> Queens) 
{
    int board[n][n];
    int counter = 0;

    // Initialize every element in the 2D array to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    // Change the value of the element in the 2D array to 1 if it is a position of the Queen
    while(!Queens.empty())
    {
        board[Queens.top().x][Queens.top().y] = 1;
        Queens.pop();
    }
    
    // Rotating the 2D array by 90 degrees counterclockwise to match the regular coordinate system
    for (int x = 0; x < n / 2; x++) {
        
        for (int y = x; y < n - x - 1; y++) {
            // Store current element in temp variable
            int temp = board[x][y];
 
            // Move values from right to top
            board[x][y] = board[y][n - 1 - x];
 
            // Move values from bottom to right
            board[y][n - 1 - x] = board[n - 1 - x][n - 1 - y];
 
            // Move values from left to bottom
            board[n - 1 - x][n - 1 - y] = board[n - 1 - y][x];
 
            // Assign temp to left
            board[n - 1 - y][x] = temp;
        }
    }

    // Display the board on the command line interface
    for (int i = 0; i < n; i++)
    {
        counter = n-i-1;

        // print the value of each row
        if (counter > 9)
            cout << counter << "   ";
        else
            cout << counter << "    ";

        for (int j = 0; j < n; j++)
        {
            // if the value of element is 0 -> not Queen
            if (board[i][j] == 0)
            {
                cout << "*  ";
            }
            // if the value of element is 1 -> Queen
            else
            {
                cout << "Q  ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "     ";
    // print the value of each column
    for (int i = 0; i < n; i++)
    {
        if (i > 9)
            cout << i << " ";
        else
            cout << i << "  ";
    }
    cout << "\n" << endl;
    
}