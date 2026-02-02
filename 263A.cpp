#include <iostream>
using namespace std;
int main() 
{
   int v;
   for (int i = 0; i <=5; i++) 
   {
         for (int j = 0; j <=5; j++) 
         {
              if ((i == 0 || i == 5) && (j == 0 || j == 5)) 
              {
                cout << "U+263A ";
              } 
              else if (i == 0 || i == 5 || j == 0 || j == 5) 
              {
                cout << "U+263B ";
              } 
              else 
              {
                cout << "U+263C ";
              }
         }
         cout << endl;
   }


}