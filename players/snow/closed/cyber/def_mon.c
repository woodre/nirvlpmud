/* CyberNinja Guild Defense Monster */
 
#define TP this_player()
#define TO this_object()
#define ENV environment
#define CYB "/players/dune/closed/guild/lib/CYBERDAEMON"
 
inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
 
  set_name("shadow warrior");
  set_long("Darkness in the form of death.\n");
 
  set_level(22);
  set_hp(500);
  set_ac(50);
  set_wc(80);
  set_al(-500);
  set_dead_ob(TO);
}}
 
monster_died() {
  CYB->overchannel(" *!* CyberNinja Guild Defenses Breached *!*");
  return 0; }
 
init() {
  if(!TP->is_player() && !TP->is_pet()) destruct(TP);
  ::init(); }
 
heal_self(num) {
  if(num < 0) num = -num;
  ::heal_self(); }
 
heart_beat() {
  object att;
  att = attacker_ob;
  armor_class = 50;
  weapon_class = 80;
  if(!att || !present(att, ENV(TO)) || 
     att->query_name() == "shadow warrior" ) find_enemy();
  if(att && present(att, ENV(TO)) ) hurt(att);
  ::heart_beat(); }
 
find_enemy() {
  object ob;
  ob = first_inventory(ENV(TO));
  while(ob) {
    if(ob->is_player() && ob->query_guild() != "cyberninja" &&
       !present("either implants", ob) && ob->query_level() < 20) {
    TO->attack_object(ob); return; }
    ob = next_inventory(ob);
  }
  return 1;
}
 
hurt(object ob) {
int obhp;
  obhp = ob->query_hp();
  if(random(20) < 3)
    CYB->overchannel(" *!* CyberNinja Defenses Under Attack *!*");
  if(obhp > 50) ob->heal_self(-random(30));
  if(obhp < 80) ob->heal_self(-obhp);
  return 1; }
