#include "/players/dune/closed/guild/DEFS.h"
inherit "players/dune/closed/guild/snow/weapons/wepmanager.c";

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
  ::reset(arg);
  if (arg) return;

  name = "nunchaku";
  ninshort = "Nunchaku";
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
  set_alias("nunchuk");
  set_short(ninshort);
  set_long(
"A powerful "+FUNKYNAME+" Guild weapon, the Nunchaku is a pair of short\n"+
"blunt sticks connected to each other by a shorter metal chain. Though\n"+
"simple in design, Nunchaku's can be extremely deadly when wielded by a\n"+
"skilled ninja. Each purplish-black handle is encrusted with the golden\n"+
"emblem of a magnificent dragon.\n");
  set_class(artwc + 12);
  set_weight(2);
  set_hit_func(this_object());
  ninjaWeapon();
  call_out("wep_beat",5);
}


void ninjaWeapon() {
  /* Guild Weapon Settings, defined by Weapon Manager */
  set_base_chance(random(75) + random(alv * 5) / 2);

  set_aura_attack(          106, alv * 2);
  set_max_bonus(            91);
  set_min_bonus(        71, 90);
  set_multi_attack(     64, 105);
  set_max_attack(       57, 90, "standard",     random(alv) + random(alv/2) +
                                                random(alv/3));
  set_med_attack(       46, 56, "standard",     random(alv/3));
  set_min_attack(       35, 45, "hit_location", random(alv/5));
 
  set_msg("min_bonus_private", 
MIN_BONUS+" races along the shafts and chain of your "+WEP+"!\n");
  set_msg("min_bonus_public", 
MIN_BONUS+" races along the shafts and chain of "+TPN+"'s "+WEP+"!\n");
  set_msg("max_bonus_private", 
MAX_BONUS+" blasts off the searing outline of your "+WEP+"!\n");
  set_msg("max_bonus_public", 
MAX_BONUS+" blasts off the searing outline of "+TPN+"'s "+WEP+"!\n");

  set_msg("min_attack_private", 
NI+"You bash the "+WEP+" into "+meatn+"'s ");
  set_msg("min_attack_public", 
NI+TPN+" bashes the "+WEP+" into "+meatn+"'s ");

  set_msg("extra_med1_private", 
NI+"You use the shadows to creep in close to "+meatn+".\n"+
NI+"With slight muscle twitches, you whip your "+WEP+" into "+meatn+"'s face!\n"+
NI+REV_BROWN+"SSSSSMMMMAAAAAACCCCCCKKKKKK"+OFF+"\n"+
meatn+" fumbles around dumbfoundedly like an idiot.\n");
  set_msg("extra_med1_public", 
NI+TPN+" uses the shadows to creep in close to "+meatn+".\n"+
NI+"With slight muscle twitches, "+TPN+" whips "+TP->POS+" "+WEP+" into "+meatn+"'s face!\n"+
NI+REV_BROWN+"SSSSSMMMMAAAAAACCCCCCKKKKKK"+OFF+"\n"+
meatn+" fumbles around dumbfoundedly like an idiot.\n");

  set_msg("extra_med2_private", 
NI+"Your dragon "+WEP+" roars with a "+REV_RED+"fiery"+OFF+" hiss!\n"+
NI+"You circle your cowering foe!\n"+
NI+"You send several blindingly quick strikes into "+meatn+".\n"+
meatn+" is completely disoriented!\n");
  set_msg("extra_med2_public", 
NI+TPN+"'s dragon "+WEP+" roars with a "+REV_RED+"fiery"+OFF+" hiss!\n"+
NI+TPN+" circles "+TP->POS+" cowering foe!\n"+
NI+TPN+" sends several blindingly quick strikes into "+meatn+".\n"+
meatn+" is completely disoriented!\n");

  set_msg("med_attack_private", 
NI+"You twirl your "+WEP+" into a whirlwind of pain.\n"+
NI+"You unleash all your hatred upon "+meatn+" in HARD merciless blows.\n"+
meatn+" crumples in muffled agony as "+meatn+" chokes on blood.\n"+
NI+"You spit on "+meatn+"'s pitiful, prone form.\n");
  set_msg("med_attack_public", 
NI+TPN+" twirl your "+WEP+" into a whirlwind of pain.\n"+
NI+TPN+" unleashes all of "+TP->POS+" hatred upon "+meatn+" in HARD merciless blows.\n"+
meatn+" crumples in muffled agony as "+meatn+" chokes on blood.\n"+
NI+TPN+" spits on "+meatn+"'s pitiful, prone form.\n");

  set_msg("max_attack_private", 
NI+"The dragon spirit of your "+WEP+" yearns to be unleashed!\n"+
NI+"You focus all your strength and stealth into the "+WEP+" DEATH sequence.\n"+
NI+"You suddenly shower "+meatn+" with a TORRENT of MASSIVE BEATINGS!\n"+
NI+REV_BROWN+"CCCCRRRRAAAAAACCCCKKKKKK"+OFF+"\n"+
meatn+" is knocked in and out of consciousness.\n"+
NI+REV_BROWN+"WWWHHHAAAAAAMMMMMM"+OFF+"\n"+
NI+"Blood spatters everywhere!\n"+
meatn+" whispers a single word to you, 'Uncle'.\n");
  set_msg("max_attack_public", 
NI+"The dragon spirit of "+TPN+"'s "+WEP+" yearns to be unleashed!\n"+
NI+TPN+" focuses all of "+TP->POS+" strength and stealth into the "+WEP+" DEATH sequence.\n"+
NI+TPN+" suddenly showers "+meatn+" with a TORRENT of MASSIVE BEATINGS!\n"+
NI+REV_BROWN+"CCCCRRRRAAAAAACCCCKKKKKK"+OFF+"\n"+
meatn+" is knocked in and out of consciousness.\n"+
NI+REV_BROWN+"WWWHHHAAAAAAMMMMMM"+OFF+"\n"+
NI+"Blood spatters everywhere!\n"+
meatn+" whispers a single word to you, 'Uncle'.\n");
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
