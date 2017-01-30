/*
v3.0 of the great dragon Icingdeath is even tougher than before.
It is now evil, with several special attacks.
*/
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(15000) + 10000);
  move_object(gold,this_object());
 
move_object(clone_object("/players/snow/WEAPONS/hon_sword"),this_object());
move_object(clone_object("/players/snow/closed/q/orb"),this_object());

     set_name("icingdeath");
     set_short("Icingdeath, the Great Wyrm");
     set_race( "dragon");
     set_alias("frost dragon");
     set_long(
"This is the legendary Icingdeath. Huge, enchanted claws and teeth are his\n"+
"weapons while scales of frosty adamantium line his flanks. No mortal has\n"+
"ever defeated this mighty being. You know that if you attempt to do battle,\n"+
"you also will die.\n");
     set_level(50);
     set_ac(random(25)+15);
     set_wc(random(30)+80);
     set_hp(2000);
     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
    set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Icingdeath sneers at you.\n");
     load_chat("Icingdeath says: Have you come to pay tribute?\n");
     load_chat("Icingdeath gazes into your eyes. You tremble in fear.\n");
     load_a_chat(
"Icingdeath roars: Another battle, at last!\n");
     load_a_chat(
"Icingdeath laughs at your puny attacks!\n");
  set_chance(35);
  set_spell_mess1("Icingdeath attacks in a rage!\n");
  set_spell_mess2("Icingdeath attacks in a rage!\n");
     set_spell_dam(80);
    call_out("rebeat",10);
   }
}
 
heart_beat() {
  ::heart_beat();
    if(TO->query_hp() < 1800) ice_heal();
  if(MEAT) ice_hurt(MEAT);
return 1;
}
 
ice_heal() {
  int X;
X = random(15);
call_other(TO,"heal_self",X);
  if(X > 10) {
    say("Icingdeath's wounds seem to close before your eyes!\n");
  }
return 1;
}
 
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
    "Icingdeath breaths a stream of ice at "+ob->query_name()+"!\n");
  tell_object(ob,
    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
    ">>>YOU ARE HIT BY AN ICE BLAST!>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(50)+50)); return 1; }
  ob->hit_player(random(50)+100);
  return 1;
}

ice_claws(object ob) {
  tell_room(environment(ob),
    "Icingdeath slashes at "+ob->query_name()+" with deadly claws!\n");
  tell_object(ob,
    "Icingdeath's claws rip into you!\n");
  if(ob->is_player()) { ob->add_hit_point(-(random(20)+10)); return 1; }
  ob->hit_player(random(40)+50);
  return 1;
}

ice_area_breath() {
  object dest, list;
  int i;
  dest = environment(TO);
  tell_room(dest,
"Icingdeath breaths forth a cloud of ice crystals!\n"+"\n"+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
" *     *     *     *     *     *     *     *     *     *     *     * \n");
  tell_room(dest,
"    *     *     *     *     *     *     *     *     *     *     *     *\n"+
"  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * \n"+
"\n"+"You are shredded by slivers of ice!\n");
  list = all_inventory(dest);
  for(i = 0; i < sizeof(list); i++) {
    if(present(list[i],dest)) {
      if(list[i]->is_player()) list[i]->add_hit_point(-(random(60)+50));
      if(living(list[i]) && !list[i]->is_player() && list[i]->id() != "icingdeath") list[i]->hit_player(100);
    }
  }
  return 1;
}
 
monster_died() {
   object dest;
   object list;
   int i;
   dest = environment(TO);
   log_file("snow.det","\n");
   log_file("snow.det","~Icingdeath killed at> "+ctime(time())+" by:\n");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      if(present(list[i], dest))
        log_file("snow.det","            "+
           capitalize(list[i]->query_real_name())+"       "+
           "Level: "+list[i]->query_level()+"    Extra_level: "+
           list[i]->query_extra_level()+"\n");
   }
   return 0;
}
 

rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }
