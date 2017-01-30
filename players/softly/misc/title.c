#include "/players/softly/ansi.h"
mixed id(string str) { return str == "titlething"; }

string short() { return "titlething"; }

void init()
{
    add_action("cmdTitle","title");
}

int drop() { return 1; }

int cmdTitle()
{
    write("Setting title...\n");
    this_player()->set_title(",as in a morning sunrise);
    write("Okay.\n");
    destruct(this_object());
    return 1;
}
