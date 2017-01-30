inherit "players/dune/closed/guild/snow/weapons/wepmanager.c";
#include "../../DEFS.h"

#define NI        RED+"*~*"+OFF
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
  object tak;
  ::reset(arg);
  if (arg) return;

  name = "kusari_gama";
  ninshort = "Kusari-Gama";
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
    if(artwc == 5)  ninshort += " <ether-alloy>";
    if(artwc > 5)  ninshort += " <vortex-forged>";
  }

  set_name(name);
  set_alt_name("kusari");
  set_alias("gama");
  set_short(ninshort);
  set_long(
"A short scythe converted to a finely-honed weapon with the addition of a\n"+
"weighted chain make the Kusari-Gama a feared weapon of the "+FUNKYNAME+"s.\n");
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
  set_base_chance(random(67) + random(alv * 5) / 2);

  set_aura_attack(          106, alv * 2);
  set_max_bonus(            91);
  set_min_bonus(        71, 90);
  set_multi_attack(     91, 105);
  set_max_attack(       75, 90, "standard",     random(alv)+random(alv/2)+
                                                random(alv/3) + 8);
  set_med_attack(       54, 74, "standard",     random(alv/2));
  set_min_attack(       43, 53, "hit_location", random(alv/3));

  set_msg("min_bonus_private", 
MIN_BONUS+" races along the blade of your "+WEP+"!\n");
  set_msg("min_bonus_public", 
MIN_BONUS+" races along the blade of "+TPN+"'s "+WEP+"!\n");
  set_msg("max_bonus_private", 
MAX_BONUS+" blasts off the searing outline of your "+WEP+"!\n");
  set_msg("max_bonus_public", 
MAX_BONUS+" blasts off the searing outline of "+TPN+"'s "+WEP+"!\n");

  set_msg("min_attack_private", 
NI+"You slice "+meatn+" in the ");
  set_msg("min_attack_public", 
NI+TPN+" slices "+meatn+" in the ");

  set_msg("extra_med1_private", 
NI+"You twirl the chain of your "+WEP+" around "+meatn+"'s legs!\n"+
meatn+" slams into the ground.\n");
  set_msg("extra_med1_public", 
NI+TPN+" twirls the chain of "+TP->POS+" "+WEP+" around "+meatn+"'s legs!\n"+
meatn+" slams into the ground.\n");

  set_msg("med_attack_private", 
NI+"You elegantly step inside "+meatn+"'s guard.\n"+
NI+"You rip your "+WEP+" blade through "+meatn+"'s midsection!\n"+
meatn+" coughs up "+RED+"blood"+OFF+".\n"+
NI+"You sneer and spit on "+meatn+", then spin away.\n");
  set_msg("med_attack_public", 
NI+TPN+" elegantly steps inside "+meatn+"'s guard.\n"+
NI+TPN+" rips "+TP->POS+" "+WEP+" blade through "+meatn+"'s midsection!\n"+
meatn+" coughs up "+RED+"blood"+OFF+".\n"+
NI+TPN+" sneers and spits on "+meatn+", then spins away.\n");

  set_msg("max_attack_private", 
NI+"You whip your "+WEP+" blade through the air while holding the chain!\n"+
NI+REV_RED+"SSSLLLLIIIIICCCCCCEEEEEE"+OFF+"\n"+
NI+"Your "+WEP+" blade wraps around and through "+meatn+"'s throat!\n"+
NI+RED+"Blood"+OFF+" spatters everywhere!\n");
  set_msg("max_attack_public", 
NI+TPN+"'s "+WEP+" streaks through the air!.\n"+
NI+REV_RED+"SSSLLLLIIIIICCCCCCEEEEEE"+OFF+"\n"+
NI+TPN+"'s "+WEP+" blade wraps around and through "+meatn+"'s throat!\n"+
NI+RED+"Blood"+OFF+" spatters everywhere!\n");
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
