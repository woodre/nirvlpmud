#define IT capitalize(attacker_name)
inherit "obj/monster";

reset(arg){
   object arm1, armor, pass, heal;
   ::reset(arg);
   if(arg) return;
   set_name("head priest");
   set_race("priest");
   set_alias("head priest");
   set_short("Head Priest of the Mind");
   set_level(25);
   set_hp(500);
   set_al(-1000);
   set_wc(20);
   set_ac(20);
  set_aggressive(0);
    pass = clone_object("players/pavlik/items/pass3.c");
       move_object(pass, this_object());
    arm1 = clone_object("players/pavlik/armor/priest_robe.c");
        move_object(arm1, this_object());
   heal = clone_object("players/pavlik/closed/stuff/invul_potion.c");
        move_object(heal, this_object());
}
heart_beat(){
   int dam;
   int n;
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      if(attacker->query_npc() == 1){
         attacker->stop_fight();
         attacker->stop_fight();
         this_object()->stop_fight();
         this_object()->stop_fight();
         attacker->stop_hunter();
         this_object()->stop_hunter();
         return 1;
      }
      if(living(attacker)){
         attacker_name=attacker->query_real_name();
         if(present(attacker_name,environment(this_object()))){
            set_chat_chance(0);
            n = random(15);
            dam = random(20);
            if(n == 1){
tell_room(room, "The Head Priest places his hand on "+IT+"'s forehead.\n"+
      IT+" begins to quiver uncontrolably.\n");
               attacker->hit_player(dam);
               attacker->add_spell_point(-dam);
               this_object()->heal_self(dam*2);
            }
            if(n == 2){
 tell_room(room, "Head priest unleashes a flame arrow straight at "+IT+"!\n");
               attacker->hit_player(random(30));
            }
            if(n == 3){
 tell_room(room, capitalize(attacker_name)+" is hit by a bolt of mental energy!\n");
   attacker->add_spell_point(-((attacker->query_sp())/12));
            }
            if(n == 4){
 tell_room(room, "Head Priest drains some of "+IT+"'s life force!\n");
      attacker->add_hit_point(-((attacker->query_hp())/12));
            }
       if(n == 5) {
 tell_object(attacker, "Priest tells you: Your mind has rotting away!  Fighting against me\n"+
   "will only speed up the process!\n");
      }
    if(n == 6) {
  tell_room(room, IT+" is driven to insanity by Mind Priest!\n");
        drain();
                  }
         }
      }
   }
}
drain(){
   object ob, attacker, here;
       attacker = this_object()->query_attack();
        here = environment(attacker);
      ob = first_inventory(here);
   while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
   attacker->attack_object(cur);
 tell_room(here, capitalize(attacker->query_name())+" attacks "+capitalize(cur->query_name())+"!\n");
      cur->attack_object(attacker);
   }
   return 1;
}


