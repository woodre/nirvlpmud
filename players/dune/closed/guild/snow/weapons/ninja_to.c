inherit "players/dune/closed/guild/snow/weapons/wepmanager.c";
#include "../../DEFS.h"

#define NI        RED+"*~*"+OFF
#define NB        BLUE+"*~*"+OFF
#define WEP       BOLD+name+OFF
#define MIN_BONUS RED+"Fire"+OFF
#define MAX_BONUS BOLD+"Lightning"+OFF


object master;
int totaldam, alv;
string name;

query_totaldam()  { return prof; }
set_totaldam(num) { prof = num; }
mod_totaldam(num) { prof += num; }


reset(arg) {
  int artwc;
  string ninshort;
  ::reset(arg);
  if (arg) return;

  name = "ninja_to";
  ninshort = "Ninja-to";
  if(IPTP && IPTP->query_weapon_name())
    ninshort = IPTP->query_weapon_name();
  master = this_player();
  artwc = -10;
  if(!IPTP) ninshort += " <rubber>";
  else {
    alv = (int)IPTP->query_art_level();
    artwc = (alv / 3) + 1;
    if((int)TP->query_level() < 20) { if (artwc > 6) artwc = 6; }
    if(artwc < 3)  ninshort += " <steel>";
    if(artwc == 3) ninshort += " <titanium>";
    if(artwc == 4) ninshort += " <adamantium>";
    if(artwc == 5) ninshort += " <ether-alloy>";
    if(artwc > 5)  ninshort += " <vortex-forged>"; 
  }
 
  set_name(name);
  set_alias("ninjato");
  set_short(ninshort);
  set_long(
     "A deadly "+FUNKYNAME+" Guild weapon, the Ninja-to is a dead-black blade about\n"+
     "3 1/2 feet long with an incredibly keen edge that longs for blood. When\n"+
     "wielded by an expert of the art of Ninjitsu, the Ninja-to becomes less like\n"+
     "a material object, more like death extending from the arm of its wielder.\n");
  set_class(artwc + 11);
  set_weight(3);
  set_hit_func(this_object());
  ninjaWeapon();
  call_out("wep_beat",5);
}


void ninjaWeapon() {
  if(!this_player()) return;
  if(!this_player()->query_attack()) return;
  /* Guild Weapon Settings, defined by Weapon Manager */
  set_base_chance(random(73) + random(alv * 5) / 2);

  set_aura_attack(          106, alv * 2);
  set_max_bonus(            91);
  set_min_bonus(        71, 90);
  set_multi_attack(     91, 105);
  set_max_attack(       59, 90,  "standard",     random(alv) + random(alv/2) +
                                                 random(alv/3) + 2);
  set_med_attack(       48, 58,  "standard",     random(alv/3));
  set_min_attack(       37, 47,  "hit_location", random(alv/4));

  set_msg("min_bonus_private", 
MIN_BONUS+" burns along the blade of your "+WEP+"!\n");
  set_msg("min_bonus_public", 
MIN_BONUS+" burns along the blade of "+TPN+"'s "+WEP+"!\n");
  set_msg("max_bonus_private", 
MAX_BONUS+" crackles off the searing outline of your "+WEP+"!\n");
  set_msg("max_bonus_public", 
MAX_BONUS+" crackles off the searing outline of "+TPN+"'s "+WEP+"!\n");

  set_msg("min_attack_private", 
NI+"You stab "+meatn+" in the ");
  set_msg("min_attack_public", 
NI+TPN+" stabs "+meatn+" in the ");

  set_msg("extra_min1_private", 
NI+"You jab the butt of your "+WEP+" into "+meatn+"'s ");
  set_msg("extra_min1_public", 
NI+TPN+" jabs the butt of "+TP->POS+" "+WEP+" into "+meatn+"'s ");

  set_msg("extra_med1_private", 
NI+"You spin elegantly around your gasping foe.\n"+
NI+"You plunge your "+WEP+" into "+meatn+"'s exposed back.\n"+
meatn+" screams in pain.\n");
  set_msg("extra_med1_public", 
NI+TPN+" spins elegantly around "+TP->POS+" gasping foe.\n"+
NI+TPN+" plunges "+TP->POS+" "+WEP+" into "+meatn+"'s exposed back.\n"+
meatn+" screams in pain.\n");

  set_msg("med_attack_private", 
NI+"You elegantly step inside "+meatn+"'s guard.\n"+
NI+"You slap "+meatn+"'s head with the flat of your "+WEP+" blade\n"+
meatn+" looks dazed.\n");
  set_msg("med_attack_public", 
NI+TPN+" elegantly steps inside "+meatn+"'s guard.\n"+
NI+TPN+" slaps "+meatn+"'s head with the flat of "+TP->POS+" "+WEP+" blade\n"+
meatn+" looks dazed.\n");

  set_msg("max_attack_private", 
NB+"SSSLLLLIIIIICCCCCCEEEEEE!!!"+OFF+"\n"+
NI+"You rip your "+WEP+" deep into "+meatn+"'s throat!\n"+
NB+RED+"Blood spatters everywhere!"+OFF+OFF+"\n");
  set_msg("max_attack_public", 
NI+TPN+"'s "+WEP+" blurs into a black streak across your vision.\n"+
NB+"SSSLLLLIIIIICCCCCCEEEEEE!!!"+OFF+"\n"+
NI+TPN+" rips "+TP->POS+" "+WEP+" deep into "+meatn+"'s throat!\n"+
NB+RED+"Blood spatters everywhere!"+OFF+OFF+"\n");
}


wep_beat() {
  object myenv;
  myenv = environment(this_object());
  if(!myenv) return 1;
  if(!master) { 
    destruct(this_object()); 
    return 1; 
  }
  if(myenv != master 
  && myenv->is_player() 
  && this_object()->wielded()) {
    myenv->stop_wielding(); 
    destruct(this_object()); 
    return 1; 
  }
  if(!myenv->is_player()) destruct(this_object());
  call_out("wep_beat",25);
  return 1;
}
