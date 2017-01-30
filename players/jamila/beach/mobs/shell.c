#include "/players/jamila/define.h"
inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short("A Large Shell");
    set_long("A large shell that can be used to defend yourself.\n");
     set_ac(1);
     set_weight(1);
	set_value(300);
	set_alias("shield");
	set_name("shell");
	set_type("shield");
  }
