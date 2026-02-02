#include <iostream>
using namespace std;
int main() 
{
   int v;
   for (int i = 0; i <=5; i++) 
   {
         for (int j = 0; j <=5; j++) 
         {
              cin >> v;
              if (v == 1) 
              {
                   cout << abs(3 - i) + abs(3 - j)<< endl;
              }
         }
         cout << endl;
   }


}