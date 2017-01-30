#include "../include/ansi.h"

inherit "/obj/treasure";

void
reset(status arg)
{
    if(arg) return;
    set_id("torch");
    set_alias("eternal torch");
    set_weight(1);
    set_value(100);
    set_light(5);
    set_short("An eternal torch [" + RED + 
    "lit from the bloodFlame" + NORM + "]");  
    set_long("\
An eternal torch from the trade city of Ryllian,\n\
wrapped in a putrid demon's fire.\n");
}

status
query_save_flag()
{
    return 1;
}

void
init()
{
    ::init();
    add_action("cmd_extinguish", "extinguish");
    add_action("cmd_light", "light");
}

status
cmd_extinguish(string arg)
{
    if(!arg)
    {
      notify_fail("Extinguish what?\n");
      return 0;
    }
    if(id(arg))
    {
      write("You cannot seem to extinguish this flame.\n");
      return 1;
    }

    notify_fail("You can try to extinguish the torch.\n");
}

status
cmd_light(string arg)
{
    if(!arg)
    {
      notify_fail("Light what?\n");
      return 0;
    }
    if(id(arg))
    {
      write("You cannot light this anymore.\n");
      return 1;
    }

    notify_fail("You can try to light the torch.\n");
    return 0;
}

status
shardakEternalTorch()
{
    return 1;
}

status
shardakEternalFlame()
{
   return 1;
}
