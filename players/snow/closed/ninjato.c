/*CyberNinja Guild weapon*/
 
#define NINJATO "/players/snow/closed/ninjatodaem.c"
#define TP this_player()
#define TO this_object()
#define ETO ENV(TO)
#define ETP ENV(TP)
#define TPN CAP(TP->query_name())
#define ETON ETO->query_name()
#define GOB present("CyberNinja Implants",TP)
#define GLEV GOB->query_guild_lev()
#define ARTR GOB->query_art_level()
#define MEAT TP->query_attack()
#define MEATN CAP(MEAT->query_real_name())
#define GEN TP->query_possessive()
#define RAN random
#define CAP capitalize
#define TR tell_room
#define ENV environment
#define CO call_other
 
inherit "obj/weapon.c";

id(str) { 
  return str == "ninjato" || str == "ninja-to" ||
         str == "Ninja-To" ||
         str == "ninja_to" || str == "weapon";
}

drop() { remove_weapon(); return 0; }

/* all ninja weapons must have this line in them */
/* it allows the user to wield the weapon */
string q_id() { return "ninjaweapon"; }


 reset(arg) {
  int artwc;
  string ninshort;
    ::reset(arg);
if(!GOB) { destruct(TO); return 1;}
artwc = (ARTR/3)+1;
ninshort = "A Ninja-To <steel>";
if(TP->query_level() < 20) {if(artwc > 5) artwc = 5;}
if(artwc == 3) ninshort = "A Ninja-To <titanium>";
if(artwc == 4) ninshort = "A Ninja-To <adamantium>";
if(artwc == 5) ninshort = "A Ninja-To <ether-alloy>";
if(artwc > 5) ninshort = "A Ninja-To <vortex-forged>";
 
#define NI "*~*"
 
    if (arg) return;
    set_name("ninja-to");
    set_alt_name("ninjato");
    set_alias("nwep");
    set_short(ninshort);
    set_long(
"A deadly CyberNinja Guild weapon, the Ninja-to is a dead-black blade about\n"+
"3 1/2 feet long with an incredibly keen edge that longs for blood. When\n"+
"wielded by an expert of the art of Ninjitsu, the Ninja-to becomes less like\n"+
"a material object, more like death extending from the arm of its wielder.\n");
    set_class(artwc + 12);
    set_weight(2);
    set_value(0);
    set_hit_func(this_object());
}
 
init() {
  ::init();
  if(!GOB && TP->is_player()) remove_weapon();
add_action("offer_ninjato","offer");
}
 
offer_ninjato(arg) {NINJATO->offer_ninjato(arg); return 1;}
weapon_hit() {NINJATO->weapon_hit(); return 1;}
nin_stab() {NINJATO->nin_stab(); return 1;}
nin_gut_punch() {NINJATO->nin_gut_punch(); return 1;}
nin_face_smash() {NINJATO->nin_face_smash(); return 1;}
nin_multi_hit() {NINJATO->nin_multi_hit(); return 1;}
r_attack() {NINJATO->r_attack(); return 1;}
nin_head_slap() {NINJATO->nin_head_slap(); return 1;}
nin_back_strike() {NINJATO->nin_back_strike(); return 1;}
nin_throat_blow() {NINJATO->nin_throat_blow(); return 1;}
nin_aura() {NINJATO->nin_aura(); return 1;}
nin_finish() {NINJATO->nin_finish(); return 1;}

remove_weapon() {
  if(wielded) command("unwield nwep", ETO);
  tell_object(ETO,TO->query_name()+" self-destructs.\n");
  destruct(TO);
  return 1;
}
