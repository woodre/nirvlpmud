inherit "players/dune/closed/guild/snow/weapons/wepmanager.c";
#include "../../DEFS.h"

#define NI        RED+"*~*"+OFF
#define HIR       BLUE+"*~*"+OFF
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

  name = "ton-fa";
  ninshort = "A Pair of Ton-Fa";
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
  set_alias("tonfa");
  set_short(ninshort);
  set_long("A three foot long staff with a handle about 1/3 of\n"+
            "the way down, perpendicular to the pole. In the trained\n"+
            "arms of a "+FUNKYNAME+", it is a very deadly weapon.\n");
  set_class(artwc + 9);
  set_weight(2);
  set_hit_func(this_object());
  ninjaWeapon();
  call_out("wep_beat",5);
}


void ninjaWeapon() {
  if(!this_player()) return;
  if(!this_player()->query_attack()) return;
  /* Guild Weapon Settings, defined by Weapon Manager */
  set_base_chance(random(71) + random(alv * 5) / 2);

  set_aura_attack(          106, alv * 2);
  set_max_bonus(            91);
  set_min_bonus(        71, 90);
  set_multi_attack(     91, 105);
  set_max_attack(       61, 90, "standard",      random(alv) + random(alv/2) +
                                                 random(alv/3) + 4);
  set_med_attack(       50, 60,  "standard",     (alv/(random(2)+2)));
  set_min_attack(       39, 49,  "hit_location", random(alv/3));

  set_msg("min_bonus_private", 
MIN_BONUS+" burns along the shaft of your "+WEP+"!\n");
  set_msg("min_bonus_public", 
MIN_BONUS+" burns along the shaft of "+TPN+"'s "+WEP+"!\n");
  set_msg("max_bonus_private", 
MAX_BONUS+" crackles off the searing outline of your "+WEP+"!\n");
  set_msg("max_bonus_public", 
MAX_BONUS+" crackles off the searing outline of "+TPN+"'s "+WEP+"!\n");

  set_msg("min_attack_private", 
NI+"You crack "+meatn+" in the ");
  set_msg("min_attack_public", 
NI+TPN+" cracks "+meatn+" in the ");

  set_msg("extra_med1_private", 
NI+"You spin elegantly around your gasping foe.\n"+
NI+"You crack your "+WEP+" over "+meatn+"'s back.\n"+
"You hear "+meatn+"'s spine crack.\n");
  set_msg("extra_med1_public", 
NI+TPN+" spins elegantly around "+TP->POS+" gasping foe.\n"+
NI+TPN+" cracks "+TP->POS+" "+WEP+" over "+meatn+"'s back.\n"+
"You hear "+meatn+"'s spine crack.\n");

  set_msg("med_attack_private", 
NI+"You roll underneath "+meatn+"'s pathetic attack.\n"+
NI+"You SMACK! "+meatn+"'s head with your "+WEP+".\n"+
meatn+" looks dazed.\n"+
NI+"You sneer and spit on "+meatn+", then spin away.\n");
  set_msg("med_attack_public", 
NI+TPN+" rolls underneath "+meatn+"'s pathetic attack.\n"+
NI+TPN+" SMACKS! "+meatn+"'s head "+TP->POS+" "+WEP+".\n"+
meatn+" looks dazed.\n"+
NI+TPN+" sneers and spits on "+meatn+", then spins away.\n");

  set_msg("max_attack_private", 
NI+"You slam your "+WEP+" into "+meatn+"'s throat!\n"+
HIR+meatn+"'s windpipe collapses!\n"+
meatn+" gasps for air!"+OFF+"\n");
  set_msg("max_attack_public", 
NI+TPN+"'s "+WEP+" blurs into a black streak across your vision.\n"+
HIR+"SSSCCCCHHHHHWWWWWWAAAAAACCCCCKKKK!!!"+OFF+"\n"+
NI+TPN+" slams "+TP->POS+" "+WEP+" into "+meatn+"'s throat!\n");
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
