inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+YEL+"hamburger"+NORM+"");
  add_alias("burger");
  add_alias("burg");
  add_alias("hamburger");
  set_short(""+YEL+"a hamburger"+NORM+"");
  set_long("This is a"+YEL+" hamburger"+NORM+" that has been cooked to well done.\n"+
           "There is a roll on each end of the hamburger with a bit of "+RED+"ketchup"+NORM+"\n"+
           "coming from under the bun, making this hamburger almost irresistable to eat.\n");    
  set_type("bites");
  set_msg("You take a big bite out of the "+YEL+"hamburger"+NORM+", dripping a little "+RED+"ketchup"+NORM+" on your chin.\n");
  set_msg2(" takes a big bite out of the "+YEL+"hamburger"+NORM+", dripping a little "+RED+"ketchup"+NORM+" on their chin.\n");
  add_cmd("eat");
  add_cmd("bite");;
  set_heal(50,50);
  set_charges(3);
  set_stuff(14);
  set_value(600); /* changed to 600  by verte */
}

query_save_flag(){
  return 1;
  }
