inherit "/obj/weapon.c";
#include <ansi.h>
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_alias("sword");
  set_short("A fine katana");
  set_long(
 " A finely honed, Durkor katana.  Its razor-sharp blade\n"+
 "meets an intricatly wrapped handle.  At the base of the \n"+
 "blade a small coiled snake is carved.\n" );
  set_type("sword");
  set_class(16);
  set_weight(2);
  set_value(2500);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random(20)  > 19) {
     write("\n     The blade slides cleanly through your enemy.\n\n");
     say("\n     "+TPN+" slices through their enemy with the katana.\n\n");
 return 3; } }

  
