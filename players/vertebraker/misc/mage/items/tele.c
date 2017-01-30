#include "../def.h"

inherit POTION;

string
colourize(string str)
{
    int s, i;
    string x;

    s = strlen(str);
    x = "";

    for(i = 0; i < s; i ++)
      switch(random(2))
      {
        case 0: x += (HIB + str[i..i] + NORM); break;
        case 1: x += (HIW + str[i..i] + NORM); break;
      }

    return x;
}

void
reset(int arg)
{
    if(arg) return;
    set_id("swirling blue and white potion");
    set_alias("swirling potion");
    add_id("potion");
    add_id("blue and white potion");
    set_short("A " + colourize("swirling blue and white") + " potion");
    set_long("\
A beautiful swirling blue and white potion.\n\
On the top of the bottle is a tan cork.\n");
    set_value(200 + random(100));
    set_weight(1);
}

void
potion_effect()
{
    int s;
    string *destinations, loc, n;
    object x, r, z;

    x = this_player();
    if((string)(r = environment(x))->realm() == "NT")
      return;

    tell_object(x, colourize("\n\n\
\t\tEverything seems to fade away....\n\n\
You find yourself in a new place.\n\n"));
    tell_room(r,  ((n = (string)x->query_name()) + 
" disappears in a whirl of blue and white energy.\n"), ({ x }));
   
    s = random(sizeof(destinations = explode(read_file("/open/TELE_ERR"), "\n")));
    loc = destinations[s];

    if(!(z = find_object(loc)))
    {
      loc->load_me();
      z = find_object(loc);
    }

    move_object(x, z);
    tell_room(z,   (n + 
      " appears in a whirl of blue and white energy.\n"), ({ x }));
    command("look", x);
}
