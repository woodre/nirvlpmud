/* Sword of the Forsaken, Created <8/4/01> by Jara */

#include "/players/jara/area1/castle/misc/ansi.h"
#define MYALIGN environment(this_object())->query_alignment()
inherit "/obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("forsaken");
set_alias("sword");
set_short("Sword of the "+RED+"Forsaken"+NORM);
set_long(
    "The sword has a brass guard, with an ornate pommel and leather wrapped\n"+
    "grip. The blade is just over two feet in length, and the metal seems to\n"+
    "radiate with an evil power. An inscription is etched into the guard.\n");
set_type("sword");
set_class(18);
set_weight(3);
set_value(2000);
set_hit_func(this_object());
}

weapon_hit(attacker){
  string aname;

  if(attacker->query_alignment() < 0) {
      tell_room(environment(environment(this_object())),
    "The Sword of the "+RED+"Forsaken"+NORM+" seems to radiate with evil...\n");
  return 2;
  }
  aname=attacker->short();
  if(!aname) aname="it";
  if(random(environment(this_object())->query_attrib("pie"))>15) {
    tell_room(environment(environment(this_object())),
    "The Sword of the "+RED+"Forsaken"+NORM+" slices through "+aname+".\n");
  return 4;
   }
 }

void long(string str) {
  if(!str)
    ::long(str);
  else if(str == "inscription")
    write("Embrace the "+RED+"evil"+NORM+" within....\n");
else ::long(str);
}
int id(string str)
{
return ::id(str) || str == "inscription";
}
