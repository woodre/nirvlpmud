#include <ansi.h>

inherit "/obj/treasure.c";

reset(arg)
{
  set_id("setter");
  set_short("Guild And Race Setter");
  set_long("  This is a little tool that you can use to change\n\
your guild name.  To use it just 'title_me'.\n");
}

init()
{
  ::init();
  add_action("titler","title_me");
  if(environment() && interactive(environment()))
  if(this_player()->query_real_name() != "angel")
  {
    write("Sorry, but you are not angel. \n");
    destruct (this_object());
    return 1;
  }
}

titler()
{
  if(this_player()->query_level() < 100) { return 1; }
  this_player()->set_guild_name("BEAST"); 
  this_player()->set_race("Regenerator");
  return 1;
}

drop() { return 1;}
