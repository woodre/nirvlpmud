#include "/players/jamila/define.h"
inherit "obj/armor" ;

reset(arg)
{
  ::reset(arg) ;
    set_short(""+HIG+"A "+HIY+"Large "+HIB+"Button"+NORM+"");
    set_long("This iS a button that when worn signifies that the\n"+
    "healer wearing it is the most active on the mud\n"+
    "Congratulations "+HIR+"Redhawk"+NORM+"!\n");
     set_ac(0);
     set_weight(0);
	set_value(0);
	set_alias("armor");
	set_name("button");
	set_type("armor");
  }
