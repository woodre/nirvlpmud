#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("splooge");
  add_alias("tube");
  add_alias("liquid");
  set_long(
"A tube filled with a liquidy ooze\n"+
"You are not quite sure what it is but\n"+
"you have the urge to 'squeeze' it.\n");
  set_type("uses");
  set_type_single("use");
  set_msg("You hold the tube to your mouth and squeeze it lightly.\n"+
          "Some of the liquid shoots into your mouth. MMMmmm!\n");
  set_msg2(" squeezes some of the splooge into their mouth.\n");
  set_empty_msg("");
  add_cmd("squeeze");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);
  set_msg_soaked(HIY+"You are all splooged up!\n"+NORM);
  set_msg_stuffed(HIY+"You are all splooged up!\n"+NORM);
}

query_save_flag(){  return 1;  }

short()
{
    return BOLD+BLK+"["+RED+"Splooge"+BLK+"] "+NORM+BOLD+"*"+charges+"*"+NORM;
 
}

int use_charge()
{
  if(charges) charges--;
  if(charges <= 0) destruct(this_object());
  return charges;
}
