/*CyberNinja Guild unarmed weapon*/
 
#define NAGIN "/players/snow/closed/handsdaem.c"
#define TP this_player()
#define TO this_object()
#define GOB present("CyberNinja Implants",TP)
#define GLEV GOB->query_guild_lev()
#define ARTR GOB->query_art_level()
 
inherit "obj/weapon.c";
 reset(arg) {
  int artwc;
    ::reset(arg);
artwc = ARTR;
if(!GOB) destruct(TO);
if(TP->query_level() < 20) {if(artwc > 11) artwc = 11;}
 
    if (arg) return;
    set_name("Hands");
    set_alias("hands");
    set_long(
"Your hands have been blessed by your Emperors to be weapons of incredible\n"+
"power. To remove yourself of this blessing, 'no_hands' .\n");
    set_class(artwc + 5);
    set_weight(0);
    set_value(0);
    set_hit_func(this_object());
}
 
init() {
  ::init();
  if(!GOB) destruct(TO);
add_action("offer_hands","no_hands");
}
 
side() {NAGIN->side(); return 1;}
offer_hands() {NAGIN->offer_hands(); return 1;}
weapon_hit() {NAGIN->weapon_hit(); return 1;}
hands_jab() {NAGIN->hands_jab(); return 1;}
hands_leg_sweep() {NAGIN->hands_leg_sweep(); return 1;}
hands_kick() {NAGIN->hands_kick(); return 1;}
hands_multi_hit() {NAGIN->hands_multi_hit(); return 1;}
r_attack() {NAGIN->r_attack(); return 1;}
hands_head_smash() {NAGIN->hands_head_smash(); return 1;}
hands_strike() {NAGIN->hands_strike(); return 1;}
hands_throat_blow() {NAGIN->hands_throat_blow(); return 1;}
hands_aura() {NAGIN->hands_aura(); return 1;}
hands_finish() {NAGIN->hands_finish(); return 1;}
