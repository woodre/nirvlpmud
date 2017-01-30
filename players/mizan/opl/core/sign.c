#include "/obj/ansi.h"
string my_text;

id(str) { return str == "sign"; }

short()
{
    return HIW + "A small wooden sign" + NORM;
}

long() 
{
    write("You see small wooden sign with the following text on it:\n");
    if(!my_text) write("This space for rent! YOUR AD HERE.\n");
    else write(my_text + "\n");
}

init() 
{
    add_action("read_sign","read");
}

read_sign(string arg) 
{
    if(!arg || arg != "sign") return 0;

    long();
    return 1;
}

set_text(string arg)
{
    my_text = arg;
}
