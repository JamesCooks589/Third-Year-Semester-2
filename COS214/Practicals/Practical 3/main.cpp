#include <string>
#include <iostream>
using namespace std;
int main()
{    

    string arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = "[-]";       
        }
        
    }

    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            if (b<9)
            {
                cout << arr[a][b];
            }
            else{
                cout << arr[a][b] << endl;
            }
        }
        
    }
    
    
    return 0;
}
