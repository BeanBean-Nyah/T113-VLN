#include <iostream>
#include "toplayer.h"
#include "data.h"



using namespace std;

int main()
{


    data dat;

    dat.write();
    dat.read();


    toplayer ui;
    ui.run();



    return 0;
}

