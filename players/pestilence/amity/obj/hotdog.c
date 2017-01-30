inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+YEL+"hotdog"+NORM+" with "+HIG+"relish"+NORM+"");
  add_alias("hotdog");
  add_alias("dog");
  add_alias("hotdog with relish");
  add_alias("relish");
  set_short(""+YEL+"hotdog"+NORM+" with"+HIG+" relish"+NORM+"");
  set_long("This is a "+YEL+"hotdog"+NORM+" with "+HIG+"relish"+NORM+" sticking out of the bun.\n"+
           "The "+YEL+"hotdog"+NORM+" looks very good.\n");    
  set_type("bites");
  set_msg("You take a big bite of the "+YEL+"hotdog"+NORM+" with some "+HIG+"relish"+NORM+" running down your chin.\n");
  set_msg2(" takes a big bite of the "+YEL+"hotdog"+NORM+" with some "+HIG+"relish"+NORM+" running down "+this_player()->query_possessive()+" chin.\n");
  add_cmd("eat");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(3);
  set_stuff(12);
/* changed by verte */
  set_value(700);
}

query_save_flag(){
  return 1;
  }
