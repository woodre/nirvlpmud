/* blatently stolen from vertebraker and modified to quickly show off the
  turtleville map.  I am a lazy bastard! */
#include "/players/wocket/closed/ansi.h"

inherit "/players/vertebraker/closed/std/treasure";

string text, title;

void
reset(status arg)
{
    if(arg) return;
    set_id("map");
    set_weight(0); /* piece of paper */
    set_value(50);
    title = BOLD+"Turtleville"+OFF;
}

void
init()
{
    ::init();
    add_action("cmd_read", "read");
}

status
cmd_read(string str)
{
    if(!str)
    {
      notify_fail("Read what?\n");
      return 0;
    }
    if(id(str) || str == "parchment" || str == "piece of parchment")
    {
    write("You unfurl the map and read from it.\n\n");
  "/players/wocket/turtleville/tville_map.c"->cmd();
      say((string)this_player()->query_name() + " \
unfurls a map and reads it.\n");
      return 1;
    }

    return 0;
}

string
short()
{
title = BOLD+"Turtleville"+OFF;
    return "A map of " + title;
}


void
set_title(string x)
{
    add_id("map of " + x);
    title = (BOLD + capitalize(x) + NORM);
}

void
long()
{
    write("\
A rolled up, yellowed piece of parchment marked with some\n\
scrawlings upon it.  It is titled \"" + title + "\".\n\
You may read it.\n");
}
    
