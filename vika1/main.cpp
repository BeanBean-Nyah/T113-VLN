#include <iostream>
#include "toplayer.h"
#include "data.h"

using namespace std;

int main()
{
    toplayer ui;
    ui.run();

    data dat;
    dat.write();

    return 0;
}

