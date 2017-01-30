inherit "/obj/weapon.c";
#include <ansi.h>
#define tpn this_player()->query_name()
int on;

reset (arg) {
  on = 0;
  ::reset(arg);
  if(arg) return;

  set_name("flashlight");
  set_alias("maglight");
  set_short(BOLD+HIY+"Mag"+BLK+"Light"+NORM);
  set_long(
 "  A large flashlight that could make a formidable weapon if\n"+
 "need be. Otherwise it always makes a great source of light.\n" );
  set_type("club");
  set_class(16);
  set_weight(2);
  set_value(1400);
  }

short(){
  if(wielded && on) {
    return BOLD+HIY+"Mag"+BLK+"Light"+NORM+" (wielded)("+BOLD+HIY+"lit"+NORM+")";
   }
  if(!wielded && on){
   return BOLD+HIY+"Mag"+BLK+"Light"+NORM+" ("+BOLD+HIY+"lit"+NORM+")";
  }
  if(wielded) {
   return BOLD+HIY+"Mag"+BLK+"Light"+NORM+" (wielded)";
  }
  if(!wielded){
   return BOLD+HIY+"Mag"+BLK+"Light"+NORM;
  } 
  }

init(){
  ::init();
   add_action("lightem","light");
   add_action("unlightem","unlight");
  }
 
lightem(str){
  if(!str){ write("Light what?\n"); return 1; }
  if(on == 1){
    write("The flashlight is already on!\n");
    return 1; }
  if(str == "flashlight" || str == "maglight"){
    write("You turn on the flashlight.\n");
    say(capitalize(tpn)+" turns on the flashlight.\n");
    on = 1;
    set_light(1);
    return 1; }
  }

unlightem(str){
  if(!str){ write("Unlight what?\n"); return 1; }
  if(on == 0){
    write("The flaslight is already off!\n");
    return 1; }
  if(str == "flashlight" || str == "maglight"){
    write("You turn off the flashlight.\n");
    say(capitalize(tpn)+" turns off the flashlight.\n");
    on = 0;
    set_light(-1);
    return 1; }
  }

wield(str) {
   if(!id(str)) return 0;
   if(wielded) {
      return 0; }
   ::wield(str);
   return 1; }

un_wield(str) {
   if(!id(str)) return 0;
   ::un_wield(str);
   return 1; }
