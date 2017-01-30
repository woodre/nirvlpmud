#include <ansi.h>

inherit "obj/armor";

reset(arg){
  string what;
  if(arg) return;
  ::reset(arg);
  switch(random(4)) {
	case 0 : what = "helmet"; break;
	case 1 : what = "ring"; break;
	case 2 : what = "amulet"; break;
	case 3 : what = "boots"; break;
  }
  set_short("Lava "+capitalize(what));
  set_long("This armor is fashioned by the Salamanders from molten lava.\n");
  set_name("Lava "+capitalize(what));
  if(!random(5)) set_ac(2);
  else set_ac(1);
  set_weight(2);
  set_value(230);
  set_alias("lava "+what);
  set_arm_light(0);
  set_type(what);
  if(ac > 1) set_save_flag(1);
  set_params("other|fire", 2, 10, "do_fire_special");
}

do_ice_special(owner)
{
 if(!random(8))
 {
    tell_object(owner, "\
Your "+query_name()+" absorbs some of the "+HIR+"FIRE"+NORM+"!\n");
 }
}
