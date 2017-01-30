#include "/players/fakir/color.h"
inherit "obj/weapon.c";

#define USER environment(this_object())

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("noctis");
set_alias("anima");
set_short(YELLOW+"Anima Nox "+BOLD+GREEN+"Noctis"+OFF);
set_long(
"Anima Nox Noctis...or 'Breath of Death' is a terrible weapon to behold.\n"+
"It seeks death in every foe, and feeds off the life forces of all who\n"+
"dwell in the realm of life.  He who wields Noctis need not fear.\n"); 
set_type("sword");  
set_class(18);
set_weight(2);
set_value(12000);
  /* make hit func do magical type dam
set_hit_func(this_object());
  */
  set_params("magical",0,"magic_hit");
/* make save -Bp
set_save_flag(1);
*/
}

magic_hit(attacker){
int dappl;
int dadam;

dappl = sizeof(users());
dadam = 0;
if(random(100) >= 70){
 switch(dappl){
  case 25..1000:
  tell_room(environment(USER),
  BOLD+GREEN+"The Breath of Death "+BOLD+YELLOW+"BURNS"+OFF+BOLD+GREEN+" with Life Energy!\n\n"+OFF);
  tell_object(USER,
  "        "+BOLD+"- - -- ---- "+BOLD+YELLOW+"SLICE"+OFF+BOLD+" ---- -- - -"+OFF+"\n\n");
  dadam = 10 + random(8);
  break;
  case 20..24:
  tell_room(environment(USER),
  BOLD+GREEN+"The Breath of Death "+BOLD+YELLOW+"GLOWS"+OFF+BOLD+GREEN+" brightly as it slices!"+OFF+"\n");
  dadam = 6 + random(6);
  break;
  case 15..19:
  tell_room(environment(USER),
  BOLD+RED+"Breath of Death sweeps out, slicing its enemy!"+OFF+"\n");
  dadam = 3 + random(3);
  break;
  case 0..14:
  tell_room(environment(USER),
  BOLD+RED+"Breath of Death vibrates with energy!"+OFF+"\n");
  dadam = 2 + random(3);
  break;
  default:
  tell_room(environment(USER),
  BOLD+GREEN+"Breath of Death vibrates with energy!"+OFF+"\n");
  dadam = 2 + random(3);
  break;
  }
}
if(random(100) > 80){
tell_object(USER,
"The "+BOLD+"Breath of "+BOLD+GREEN+"Death"+OFF+" lends you its energy..."+BOLD+GREEN+"\n\n"+
"               ___       ___           ____ \n"+
"             ___       __  ___      ___    _\n"+
"           ___       __       __      ____  __      __       __\n"+
"             ___       ___     __    __       __  __   __  _   ______\n"+
"               ___   ___      __   ___          __       __\n"+
"                  ___          ____              __"+OFF+"\n"); 
USER->heal_self(dappl / 4);
}
return dadam;
}
