#include "cal.h"
#include <iostream>
using namespace std;

Calendar :: Calendar (int _month){

month = _month;
}

void Calendar :: print()

for()   
    {
        switch (month)
{
    case 1:
    cout<<setw(21)<<"January ";
    break;
    
    case 2:
    cout<<setw(21)<<"February ";
    break;
    
    case 3:
    cout<<setw(21)<<"March ";
    break;
    
    case 4:
    cout<<setw(21)<<"April ";
    break;
    
    case 5:
    cout<<setw(21)<<"May ";
    break;
    
    case 6:
    cout<<setw(21)<<"June ";
    break;
    
    case 7:
    cout<<setw(21)<<"July ";
    break;
    
    case 8:
    cout<<setw(21)<<"August ";
    break;
    
    case 9:
    cout<<setw(21)<<"September ";
    break;
    
    case 10:
    cout<<setw(21)<<"October ";
    break;
    
    case 11:
    cout<<setw(21)<<"November ";
    break;
    
    case 12:
    cout<<setw(21)<<"December ";
    break;
}
}

