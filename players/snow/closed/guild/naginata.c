/*CyberNinja Guild weapon*/
 
#define NAGIN "/players/snow/closed/nagidaem.c"
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
#define NI "*~*"
 
inherit "obj/weapon.c";
 reset(arg) {
  int artwc;
  string ninshort;
    ::reset(arg);
artwc = (ARTR/3)+1;
ninshort = "A Naginata <steel>";
if(!GOB) destruct(TO);
if(TP->query_level() < 20) {if(artwc > 5) artwc = 5;}
if(artwc == 3) ninshort = "A Naginata <titanium>";
if(artwc == 4) ninshort = "A Naginata <adamantium>";
if(artwc == 5) ninshort = "A Naginata <ether-alloy>";
if(artwc > 5) ninshort = "A Naginata<vortex-forged>";
 
 
    if (arg) return;
    set_name("Naginata");
    set_alias("naginata");
    set_short(ninshort);
    set_long(
"A deadly CyberNinja Guild weapon, the Naginata is a polearm about\n"+
"5 1/2 feet long with a razor-edged blade and a stout black staff. When\n"+
"wielded by an expert of the art of Ninjitsu, the Naginata becomes a\n"+
"whirling instrument of destruction.\n");
    set_class(artwc + 12);
    set_weight(2);
    set_value(0);
    set_hit_func(this_object());
}
 
init() {
  ::init();
  if(!GOB) destruct(TO);
add_action("offer_naginata","offer");
}
 
offer_naginata(arg) {NAGIN->offer_naginata(arg); return 1;}
weapon_hit() {NAGIN->weapon_hit(); return 1;}
nag_slice() {NAGIN->nag_slice(); return 1;}
nag_leg_sweep() {NAGIN->nag_leg_sweep(); return 1;}
nag_bar_bash() {NAGIN->nag_bar_bash(); return 1;}
nag_multi_hit() {NAGIN->nag_multi_hit(); return 1;}
r_attack() {NAGIN->r_attack(); return 1;}
nag_bar_smash() {NAGIN->nag_bar_smash(); return 1;}
nag_strike() {NAGIN->nag_strike(); return 1;}
nag_throat_blow() {NAGIN->nag_throat_blow(); return 1;}
nag_aura() {NAGIN->nag_aura(); return 1;}
nag_finish() {NAGIN->nag_finish(); return 1;}
 
