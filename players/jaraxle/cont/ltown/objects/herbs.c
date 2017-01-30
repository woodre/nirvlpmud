#include <ansi.h>

inherit "/obj/generic_heal.c";



void reset(int arg)

{

  ::reset(arg);

  if(arg) return;

  set_name("herbs");

  add_alias("lump");

  set_short("A lump of healing herbs");

  set_long("This is a small lump of herbs that have\n"+

	       "been collected in the swamplands.  It is\n"+

		   "an ancient Elven recipe that is quite\n"+

		   "effective in healing wounds.  You can\n"+

		   "eat them if you like.\n");

  set_type("bites");

  set_type_single("bite");


  set_msg(HIG+"You bite off a large chunk of herbs and instantly feel\n"+

	      "much better.\n"+NORM);

  set_msg2(" eats something brown and green looking.\n");

  add_cmd("eat");

  set_heal(50,50);

  set_charges(3);

  set_soak(7);

  set_stuff(7);

  set_value(600);

}



short(){ return "A lump of healing herbs "+YEL+"-"+HIY+charges+NORM+YEL+"-"+NORM; }



query_save_flag(){

  return 1;

  }

