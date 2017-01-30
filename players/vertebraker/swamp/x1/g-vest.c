#include "/players/vertebraker/ansi.h"

inherit "/obj/armor";

#define MAX_WEIGHT 12

static int local_weight;

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("vest");
    set_alias("fishing vest");
    set_short("A " + GRN + "fishing vest" + NORM);
    set_long("\
A dark green fishing vest, with several pockets and zippers.\n\
There is some cotton padding in the inside to keep the\n\
wearer warm and comfortable.\n");
    set_type("chest");
    set_weight(1);
    set_ac(1+random(2));
    set_value(444 + random(222));
}

status
query_dest_flag()
{
    return 1;
}

status
can_put_and_get()
{
    return 1;
}

status
add_weight(int w)
{
    if((local_weight + w) > MAX_WEIGHT)
      return 0;
    else
    {
      local_weight += w;
      return 1;
    }
}

status
query_save_flag()
{
    if(first_inventory(this_object()))
      return 1;

    else return 0;
}

void
long()
{

    write(long_desc);
}

int
query_weight()
{
    return (local_weight + weight);
}
