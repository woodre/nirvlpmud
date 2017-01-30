inherit "/obj/weapon.c";
#include <ansi.h>
#define tpn this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sword");
  set_alias("apocalypse");
  set_short(HIM+"Apocalypse"+NORM);
  set_long(
 HIR+"  The sword of Ragnarok, the end of time.  Forged deep\n"+
 "within the underdark by the four horsemen, the sword lies\n"+
 "in wait for the time when it will be needed.\n"+NORM );
  set_type("sword");
  set_class(100);
  set_weight(2);
  set_value(0);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random (10) < 7) {
     write("\nYou rain down fire and brimstone.\n\n");
 return 5; } }

  
