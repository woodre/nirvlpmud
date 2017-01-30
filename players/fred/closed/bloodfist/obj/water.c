/* 1800 gold */
#include "/players/fred/closed/bloodfist/defs.h"
inherit "/obj/generic_heal.c";
object gob;
int a;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("canteen of water");
  add_alias("canteen");
  add_alias("water");
  set_long(
"This small canteen of water is perfect for the on-the-go player.\n"+
"Rather than having a twist off cap like most canteens do, this\n"+
"kind features a self-closing squeeze top that provides you with\n"+
"the fastest satisfaction of all the top-selling canteens on the\n"+
"market.  The canteen is filled with that wonderful liquid water,\n"+
"which both quenches your thirst and satiates your hunter.  You\n"+
"can't go wrong with water!  The canteen is so small that it fits\n"+
"discreetly in your pocket, so most people won't even notice it.\n");
  set_type("drinks");
  set_msg(HIC+"You drink a quick shot of water and feel refreshed.\n"+NORM);
  set_msg2(" drinks a quick shot of water.\n");
  set_empty_msg(HIC+"You finish off the last drop of water in the canteen.\n"+
    NORM);
  add_cmd("drink");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);
}

query_save_flag(){  return 1;  }

id(str){ return (::id(str) || str == "zbf_water"); }

short()
{
  if( this_player() && environment() )
    if(this_player()->query_guild_name() == "bloodfist"
      || this_player()->query_level() > 19
      || !living(environment()) || environment() == this_player())
      return HIC+"A canteen of water ["+NORM+charges+HIC+"]"+NORM;

  return 0;
}

int cmd_imbibe(string str)
{
  a = ::cmd_imbibe(str);
  if(a && (gob = present("bloodfist_gob", this_player())))
    gob->add_endurance(3);
  return a;
}

int use_charge()
{
  if(charges) charges--;
  if(charges <= 0) destruct(this_object());
  return charges;
}
