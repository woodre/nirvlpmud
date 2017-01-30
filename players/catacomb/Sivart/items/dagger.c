inherit "/obj/weapon.c";
#include <ansi.h>
#define TPN this_player()->query_name()

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dagger");
  set_alias("knife");
  set_short("A Durkor belt dagger");
  set_long(
 " The razor-sharp, double-edged dagger glows a mysterious red.\n"+
 "The handle curves away from you into a sharp spike.\n");
  set_type("dagger");
  set_class(15);
  set_weight(1);
  set_value(2000);
  set_hit_func(this_object()); }
  mixed
  weapon_hit(object attacker) {
  string name;
    if(environment() && environment()->is_player()) {
    name=(string)environment()->query_name(); }
    if(!name) return 0;
    if(random(20)  > 17) {
     write("\n     You slash through your opponent quickly leaving a thin line of blood.\n\n");
     say("\n     "+TPN+" slashes through their opponent leaving a thin line of blood.\n\n");
 return 2; } }

  
