inherit "/obj/treasure.c";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){

  set_short(RED+"Bf HDaemon Tool"+NORM);
  set_long(
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "tool"; }

  init(){
  ::init();
  add_action("add", "bfadd");
  add_action("rm", "bfrm");
  add_action("print", "bfprint");
  add_action("print_top", "bftop");
}

status add(string str)
{
  if(this_player()->query_level() < 60) return 0;
  if(HONOR_DAEMON->add_member(str))
    write(capitalize(str)+" has been added.\n");
  return 1;
}

status rm(string str)
{
  if(this_player()->query_level() < 60) return 0;
  if(HONOR_DAEMON->rm_member(str))
    write(capitalize(str)+" has been removed.\n");
  return 1;
}

status print()
{
  write("Honor Daemon members:\n");
  HONOR_DAEMON->print_members(this_player());
  return 1;
}


status print_top()
{
  write("Honor Daemon Top members:\n");
  HONOR_DAEMON->print_top_members(this_player());
  return 1;
}

