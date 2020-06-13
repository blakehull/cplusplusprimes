//
//  main.cpp
//  numbertheory
//
//  Created by Blake Hull on 6/12/20.
//  Copyright © 2020 Blake Hull. All rights reserved.
//

#include <iostream>
#include "functions.h"

int main(int argc, const char * argv[]) {
    std::list<int> myList = pMinusOne(753, 753, 2);
    std::list<int> solution = {3, 251};
    for (auto v : myList)
        cout << v << "\n";
    if(myList == solution){
        cout << "This function is working!\n";
    }else{
        cout << "Back to the drawing board :(\n";
    }
    return 0;
}



