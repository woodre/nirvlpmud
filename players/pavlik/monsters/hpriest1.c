#define IT capitalize(attacker_name)
inherit "obj/monster";

reset(arg){
   object arm1, armor, pass, heal;
   ::reset(arg);
   if(arg) return;
   set_name("head priest");
   set_race("priest");
   set_alias("head priest");
   set_short("The Head Priest of Souls");
   set_level(25);
   set_hp(500);
   set_al(-1000);
   set_wc(20);
   set_ac(20);
  set_aggressive(0);
    set_dead_ob(this_object());
    pass = clone_object("players/pavlik/items/pass1.c");
       move_object(pass, this_object());
    armor = clone_object("players/pavlik/weapons/unshield.c");
     move_object(armor, this_object());
    arm1 = clone_object("players/pavlik/weapons/priest_mace.c");
        move_object(arm1, this_object());
   heal = clone_object("obj/heal.c");
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
 tell_room(room, "Head priest unleashes a lightning bolt straight at "+IT+"!\n");
               attacker->hit_player(random(30));
            }
            if(n == 3){
   tell_room(room, capitalize(attacker_name)+" is damned by head priest!.\n");
   attacker->add_spell_point(-((attacker->query_sp())/12));
            }
            if(n == 4){
 tell_room(room, "Head Priest drains some of "+IT+"'s life force!\n");
      attacker->add_hit_point(-((attacker->query_hp())/12));
            }
       if(n == 5) {
 tell_object(attacker, "The Priest tells you: Leave, before your soul is\n"+
 "damned to hell, forever!\n");
      }
    if(n == 6) {
tell_room(room, "The Head Priest of Souls charms "+IT+"'s soul and convinces it\n"+
 "to give up it's weapon.\n");
        drain();
                  }
         }
      }
   }
}
drain(){
    object ob, attacker;
       attacker = this_object()->query_attack();
   ob = first_inventory(attacker);
   while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
       if(cur->weapon_class()) {
       move_object(cur, this_object());
       return 1;
         }
   }
   return 1;
}


monster_died() {
   object charm, room, attacker;
  room = environment(this_object());
   attacker = this_object()->query_attack();
  tell_room(room, "The defeated Vampire looks at you and smiles.\n"+
  "'You can't kill me that easy!' he says. 'I look forward to when we\n"+
  "meet again!'  His body turns into a cloud of mists and disappears\n"+
  "out the window.  He must return to the dungeons deep below to\n");
tell_room(room, "regenerate.  Only down there can you finish him off for good!\n");
 tell_object(attacker, "\n");
 tell_object(attacker, "The Vampire glares at you specifically.  'I cannot wait\n"+
  "to give you a true test of my powers,' he says.  'I will be waiting\n"+
  "for you my friend...dont' disappiont me!'\n"+
  "He sneers at you and then disappears out the window.\n"+
  "    well done, you have gained an item.\n");
       charm = clone_object("players/pavlik/items/charm.c");
         move_object(charm, attacker);
      return 0;
}
