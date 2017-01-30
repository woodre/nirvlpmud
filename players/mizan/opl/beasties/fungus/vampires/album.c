#include "/players/mizan/opl/definitions.h"

string my_name;

reset(arg)
{
    if(arg) return;

    my_name = RANDOBJ_DM->get_album_name();
}

id(str) { return str == "album" || str == "cd"; }

short()
{
    return "A music CD titled " + my_name;
}

long()
{
    write("This is an ordinary album, but the quality of the subject\n"+
          "matter is very dubious and questionable.\n");
}

get() { return 1; }
query_value() { return 2; }

query_save_flag() { return 1; }

