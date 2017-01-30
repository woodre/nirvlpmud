#include "/players/vertebraker/ansi.h"

#pragma strict_types

inherit "/obj/treasure";

int is_on;

string pos;

string short() 
{ 
    if(!is_on) 
      pos = "lava lamp"; 
    return "A " + pos; }

void long()
{
     return write("A cyan lava lamp.\n\It is " + (is_on ? "on" : "off") +
".\n");
}

void init()
{
    add_action("cmdOn","on");
    add_action("cmdOff","off");
}

status cmdOn()
{
    if(is_on)
    {
      notify_fail("\
The lava lamp is on.\n");
      return 0;
    }
    write( "\
You turn on the lava lamp.\n");
    say((string)this_player()->query_name() + "\
 turns on the lava lamp.\n");
    is_on = 1;
    pos = "lava lamp";
    call_out("mv_lava", 3);
    return 1;
}

status cmdOff()
{
    if(!is_on)
    {
      notify_fail("\
The lava lamp is off.\n");
      return 0;
    }
    write( "\
You turn off the lava lamp.\n");
    say((string)this_player()->query_name() + "\
 turns off the lava lamp.\n");
    is_on = 0;
    remove_call_out("mv_lava");
    return 1;
}

void mv_lava()
{
    int x;
    string tmp, new, bob;
    tmp = "lava lamp";
    new = "";
    for(x = 0; x < strlen(tmp); x ++)
    if(0 == random(2))
      new += "" + HIC + tmp[x..x] + NORM + "";
    else new += tmp[x..x];
    if(0 == random(20))
      tell_room(environment(), "The lava lamp churns and bubbles.\n");
    pos = new;
    call_out("mv_lava", 3);
}

status id(string str) { return str == "lamp" || str == "lava lamp"; }

int
query_weight() { return 1; }

int
query_value() { return 75; }
