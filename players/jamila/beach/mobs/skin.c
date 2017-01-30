#include "/players/jamila/define.h"
inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short("A Lizard Skin");
    set_long("The skin from a dead lizard.  You can\n"+
    "wear it to protect yourself.\n");
     set_ac(1);
     set_weight(1);
	set_value(110);
	set_alias("skin");
	set_name("lizard skin");
	set_type("armor");
  }
