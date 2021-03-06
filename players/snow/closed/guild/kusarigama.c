/*CyberNinja Guild weapon*/
 
#define KGAMA "/players/snow/closed/kgamadaem.c"
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
ninshort = "A Kusari-Gama <steel>";
if(!GOB) destruct(TO);
if(TP->query_level() < 20) {if(artwc > 5) artwc = 5;}
if(artwc == 3) ninshort = "A Kusari-Gama <titanium>";
if(artwc == 4) ninshort = "A Kusari-Gama <adamantium>";
if(artwc == 5) ninshort = "A Kusari-Gama <ether-alloy>";
if(artwc > 5) ninshort = "A Kusari-Gama <vortex-forged>";
 
 
    if (arg) return;
    set_name("Kusari-Gama" || "kusari-gama");
    set_alias("kusari" || "gama");
    set_short(ninshort);
    set_long(
"A short scythe converted to a finely-honed weapon with the addition of\n"+
"a weighted chain make the Kusari-Gama a feared weapon of the CyberNinjas.\n");
    set_class(artwc + 10);
    set_weight(1);
    set_value(0);
    set_hit_func(this_object());
}
 
init() {
  ::init();
  if(!GOB) destruct(TO);
add_action("offer_kgama","offer");
}
 
offer_kgama(arg) {KGAMA->offer_kgama(arg); return 1;}
weapon_hit() {KGAMA->weapon_hit(); return 1;}
gama_slice() {KGAMA->gama_slice(); return 1;}
kusari_tangle() {KGAMA->kusari_tangle(); return 1;}
kusari_whip() {KGAMA->kusari_whip(); return 1;}
kgama_multi_hit() {KGAMA->kgama_multi_hit(); return 1;}
r_attack() {KGAMA->r_attack(); return 1;}
gama_chop() {KGAMA->gama_chop(); return 1;}
kgama_tangle_chop() {KGAMA->kgama_tangle_chop(); return 1;}
kgama_neck_rip() {KGAMA->kgama_neck_rip(); return 1;}
kgama_aura() {KGAMA->kgama_aura(); return 1;}
kgama_finish() {KGAMA->kgama_finish(); return 1;}
