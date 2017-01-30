#include "/players/jamila/define.h"
inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short("A Tourist Hat");
    set_long("A large hat that keeps the sun off your face. It\n"+
    "looks kind of like a large lampshade.\n");
     set_ac(1);
     set_weight(2);
	set_value(900);
	set_alias("helmet");
	set_name("hat");
	set_type("helmet");
  }
