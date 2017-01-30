#include "/players/feldegast/defines.h"
#define MYALIGN environment(this_object())->query_alignment()
inherit "/obj/weapon.c";

reset(arg) {
   ::reset(arg);
  if(arg) return;
  set_type("sword");
  set_class(18);
  set_name("winterlight");
  set_alias("longsword");
  set_short("Winterlight the Longsword");
  set_weight(4);
  set_value(2500);
  set_light(1);
  set_long(
"This is a magnificently forged longsword with a razor\n"+
"sharp edge and a comfortable hilt.  A single perfect\n"+
"snowflake is etched into the sword's pommel.  The sword's\n"+
"blade glows with an unearthly gleam.\n"
  );
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  string aname;
  
  if(MYALIGN>1000) {
    hits=1;
    misses=1;
  }
  
  if(random(MYALIGN)>1000) {
    tell_room(environment(environment(this_object())),
      HIW+"Winterlight the Longsword gleams with an unearthly light.\n"+NORM);
    return 7;
  }
  
  aname=attacker->short();
  if(!aname) aname="it";
  if(random(environment(this_object())->query_attrib("wil"))>15) {
    tell_room(environment(environment(this_object())),
      HIW+"Winterlight the Longsword "+HIR+"cleaves"+HIW+" through "+aname+HIW+"'s flesh.\n"+NORM);
    return 8;
}
  }


void long(string str)
{
  if(!str)
    ::long(str);
  else if(str == "hilt")
    write("The hilt is wrapped in a leather grip.\n");
  else if(str == "pommel")
    write("A single perfect snowflake is etched into the sword's pommel.\n");
  else ::long(str);
}

int id(string str)
{
  return ::id(str) || str == "hilt" || str == "pommel" || str == "blade";
}

weapon_breaks()
{
  if(MYALIGN>1000) return 1;
  return ::weapon_breaks();
}
