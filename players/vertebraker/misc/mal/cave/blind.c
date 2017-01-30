#include "/players/vertebraker/ansi.h"

#define verb ({ "look", "l", "examine", "exa", "glance", "i", "inventory" })

status
id(string str)
{
    return str == "verte_blind_fuck";
}

void
reset(status arg)
{
    if(arg) return;
    call_out("punkybrewster", 600);
}

void
punkybrewster()
{
    object e;

    if(e = environment())
      tell_object(e, 
        HIW + "You have regained your vision.\n");
    destruct(this_object());
}

void
init()
{
    int i;

    for(i = 0; i < sizeof(verb); i ++)
      add_action("busteminthejawwitdafatgoldring", verb[i]);
}

status
busteminthejawwitdafatgoldring()
{
    write(HIC + "You have been blinded by the chilly mist!\n" + NORM);
    return 1;
}

status
drop()
{
    return 1;
}

status
get()
{
    return 1;
}
