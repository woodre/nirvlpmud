/*
v3.0 of the great dragon Icingdeath is even tougher than before.
It is now evil, with several special attacks.
*/
 
#define TO this_object()
#define MEAT attacker_ob
#define MEATN capitalize(MEAT->query_name())
#include "/players/snow/closed/cyber/color.h"
 
inherit "/obj/monster";
 
string fucker;
int healnum, take_dam;
reset(arg) {
   ::reset(arg);
   if (!arg) {
 

     set_name("icingdeath");
     set_short(BOLD+"Icingdeath, the Great Wyrm"+OFF);
     set_race( "dragon");
     set_alias("frost dragon");
     set_long(
"This is the legendary "+BOLD+"Icingdeath"+OFF+".\n"+
"Huge, enchanted claws and teeth are his weapons while scales\n"+
"of frosty adamantium line his flanks. No mortal has ever\n"+
"defeated this mighty being. You know that if you attempt to do\n"+
"battle, you also will die.\n");
     set_level(50);
     set_ac(random(25)+15);
     set_wc(random(30)+80);
     set_hp(4000);
     set_heal(5,1);
     healnum = 15;
/* NEW CODE */
set_hp_bonus(-1000); /* Special weakness */
set_ac_bonus(7);
set_wc_bonus(36);
     set_al(-1000);
     set_aggressive(0);
    set_dead_ob(this_object());
     set_chat_chance(3);
     set_a_chat_chance(7);
     load_chat(BOLD+"Icingdeath"+OFF+" sneers at you.\n");
     load_chat(BOLD+"Icingdeath"+OFF+" says: Have you come to pay tribute?\n");
     load_chat(BOLD+"Icingdeath"+OFF+
               " gazes into your eyes. You tremble in fear.\n");
     load_a_chat(
BOLD+"Icingdeath"+OFF+" roars: Another battle, at last!\n");
     load_a_chat(
BOLD+"Icingdeath"+OFF+" laughs at your puny attacks!\n");
  set_chance(35);
  set_spell_mess1(BOLD+"Icingdeath"+OFF+" attacks in a rage!\n");
  set_spell_mess2(BOLD+"Icingdeath"+OFF+" attacks in a rage!\n");
     set_spell_dam(80);
    call_out("rebeat",40);
    money = random(10000)+20000;
   }
}

init() { add_action("stop_back", "back"); }

stop_back() { if(this_player()->query_attack() == this_object() || this_object()->query_attack() == this_player()) {
  write("You are engaged in combat and cannot get back off the summit!\n");
  return 1; }
}
 
query_hbflag() { return "hbstayon"; }

heart_beat() {
  ::heart_beat();
  if(hit_point < 2000) ice_heal();
  if(MEAT && !MEAT->query_ghost()) {
  if(MEAT->query_real_name() == "icingdeath") ravage();
  if(MEAT->query_level() < 14) eat_em_up(MEAT);
  if(MEAT) ice_hurt(MEAT);
  }
  if(this_object()->query_wc() < 80) pissed();
  if(query_attack() && present("fear_link", query_attack()) )
    destruct(present("fear_link", query_attack()) );
  take_dam = 0;
return 1;
}

query_limited_shadow() { return 1; }

heal_self(dam) {
  if(dam < 0 && !take_dam) {
    take_dam ++;
    ::heal_self(dam); return dam; }
  if(dam < 0) dam = 0;
  ::heal_self(dam);
  return dam;
}
 
ice_heal() {
  int healme;
  healme = random(healnum);
  TO->heal_self(healme);
  if(healme > 10) {
    say(BOLD+"Icingdeath"+OFF+"'s wounds seem to close before your eyes!\n");
  }
return 1;
}

ravage() {
  object dest, list;
  int i;
  dest = environment(this_object());
  list = all_inventory(dest);
   tell_room(environment(this_object()),
    BOLD+"Icingdeath"+OFF+" stops fighting and smiles wickedly.\n");
  this_object()->stop_fight();
  this_object()->stop_fight(); this_object()->stop_hunted();
  this_object()->stop_hunted();
  ice_area_breath(); ice_area_breath(); ice_area_breath();
  ice_area_breath(); ice_area_breath();
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i], dest)) {
      if(living(list[i]) && !list[i]->is_ghost()) {
        list[i]->hit_player(100);
      }
     }
  }
  return 1;
}

eat_em_up(object ob) {
  object meat, room;
  meat = ob;
  room = environment(this_object());
  tell_room(room, BOLD+"Icingdeath"+OFF+" laughs at "+meat->query_name()+
            "'s pathetic attack!\n\n");
  tell_room(room, "The Great Wyrm grabs "+meat->query_name()+
            " with its giant claws and "+REV_RED+"*R*I*P*S*"+OFF+"\n");
  meat->hit_player(10000);
  return 1; }
 
ice_hurt(object ob) {
  int lev;
  object meat;
  lev = ob->query_level();
  meat = present(ob,environment(TO));
  if(meat) {
    if(random(130) < lev) { ice_breath(ob); return 1; }
    if(random(80) < lev) { ice_claws(ob); return 1; }
    if(random(150) < lev) { ice_area_breath(); return 1; }
  }
  return 1;
}
 
ice_breath(object ob) {
  tell_room(environment(ob),
    BOLD+"Icingdeath"+OFF+" breaths a stream of ice at "+ob->query_name()+"!\n");
  tell_object(ob, REV_BLUE+
    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
    ">>>YOU ARE HIT BY AN ICE BLAST!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
    OFF );
  if(ob->is_player()) {
    ob->add_hit_point(-(random(50)+50));
    ob->hit_player(20);  return 1; }
  ob->hit_player(random(50)+100);
  return 1;
}

ice_claws(object ob) {
  tell_room(environment(ob),
    BOLD+"Icingdeath"+OFF+" "+RED+"slashes"+OFF+" at "+ob->query_name()+
         " with deadly claws!\n");
  tell_object(ob,
    BOLD+"Icingdeath"+OFF+"'s claws "+RED+"rip"+OFF+" into you!\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(20)+10)); return 1; }
  ob->hit_player(random(40)+50);
  return 1;
}

ice_area_breath() {
  object dest, list;
  int i;
  dest = environment(TO);
  tell_room(dest,
BOLD+"Icingdeath"+OFF+" breaths forth a cloud of ice crystals!\n"+"\n"+
BLUE+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
" *     *     *     *     *     *     *     *     *     *     *     * \n");
  tell_room(dest,
"    *     *     *     *     *     *     *     *     *     *     *     *\n"+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
OFF+
"\n"+"You are shredded by slivers of ice!\n");
  list = all_inventory(dest);
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i],dest)) {
      if(list[i]->is_player()) {
        list[i]->add_hit_point(-(random(60)+50));
       list[i]->hit_player(20); }
if(living(list[i]) && !list[i]->is_player() && !list[i]->id("icingdeath") ) list[i]->hit_player(100);
    }
  }
  return 1;
}

pissed() {
  tell_room(environment(this_object()),
    BOLD+"Icingdeath"+OFF+" grows "+REV_RED+"very angry"+OFF+"...\n");
  this_object()->set_wc(200);
bring_back();
  healnum = 60;
  return 1;
}

bring_back() {
  object toast;
  if(MEAT) fucker = MEAT->query_real_name();
  toast = find_player(fucker);
  if(!toast) return 1;
  if(toast->query_ghost()) return 1;
  if(environment(toast) != environment(this_object()) )
    move_object(toast, environment(this_object()) );
    this_object()->attack_object(toast);
  call_out("bring_back",3);
  return 1;
}
 
monster_died() {
   object weap_off,dest;
   object list;
   int i;
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(15000) + 10000);
  move_object(gold,this_object());
 
move_object(clone_object("/players/snow/WEAPONS/hon_sword"),this_object());
move_object(clone_object("/players/snow/closed/q/orb"),this_object());
   dest = environment(TO);
   log_file("snow.det","\n");
   log_file("snow.det","~Icingdeath killed at> "+ctime(time())+" by:\n");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      if(present(list[i], dest))
      {
        log_file("snow.det","            "+
           capitalize(list[i]->query_real_name())+"       "+
           "Level: "+list[i]->query_level()+"    Extra_level: "+
           list[i]->query_extra_level()+"\n");
        weap_off=present("wyrmslayer",list[i]);
        if(weap_off) weap_off->set_usedup();
      }
   }
  this_object()->query_attack()->add_exp(15000);
   return 0;
}
 

rebeat() { call_out("rebeat",60); set_heart_beat(1); heart_beat(); return 1; }
