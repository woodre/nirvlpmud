inherit "/obj/weapon.c";
#include "/players/fred/defines.h"

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("knuckles");
  set_short(HIY+"Brass"+NORM+" Knuckles");
  set_long(
 "Solid "+HIY+"brass"+NORM+" knuckle blades once used by the Chief of\n"+
 "Security to punish those that got out of line.\n");
  set_type("club");
  set_class(17);
  set_weight(2);
  set_value(1200);
  set_hit_func(TO);
  message_hit=({
    "made",BOLD+BLK+" cry"+NORM+" for their "+BOLD+BLK+"mommy"+NORM,
    GRN+"overwhelmed"+NORM," with a vicious onslaught",
    BOLD+"pounded"+NORM," mercilessly",
    RED+"mauled"+NORM," like a "+BOLD+"freakin'"+NORM+" maniac",
    "punched",BOLD+BLK+" solidly"+NORM+" in the "+BOLD+BLK+"chest"+NORM,
    HIY+"nicked"+NORM," drawing a thin line of"+BOLD+RED+" blood"+NORM,
    "missed","",
    });
}

weapon_hit(fatso){
  int q;
  q = random(20);
  if(q > 17){
    write("You swing your fists wildly catching "+BOLD+CAP(fatso->query_name())+NORM+" with a "+GRN+"wicked"+NORM+" uppercut!\n");
    say(TPN+" swings "+POS+" fists wildly catching "+BOLD+CAP(fatso->query_name())+NORM+" with a "+GRN+"wicked"+NORM+" uppercut!\n");
    return 6;
   }
  return;
 }
 
