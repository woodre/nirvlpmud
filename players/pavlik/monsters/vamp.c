inherit "obj/monster";
int hps;
init(){
   ::init();
   add_action("devil","devil");
}
devil(){
   say("The priestess looks at you and grins.\n");
   this_object()->attack_object(this_player());
   return 1;
}

reset(arg){
  object arm1,armor,gold;
   ::reset(arg);
   if(arg) return;
   set_name("vampire");
   set_race("vampire");
   set_alias("vamp");
   set_short("A Vampire");
   set_level(22);
   set_hp(500);
   set_al(-1000);
   set_wc(20);
   set_ac(20);
  set_aggressive(1);
    set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(3000)+2000);
   move_object(gold,this_object());
    armor = clone_object("players/pavlik/closed/stuff/frost.c");
     move_object(armor, this_object());
    arm1 = clone_object("players/pavlik/items/hneck.c");
        move_object(arm1, this_object());
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
  tell_room(room, "The Vampire sinks his fangs into "+capitalize(attacker_name)+
     " and draws out some blood!\n");
               attacker->hit_player(dam);
               attacker->add_spell_point(-dam);
               this_object()->heal_self(dam*2);
    tell_room(room, "His fangs glisten in the faint light of this room.\n");
            }
            if(n == 2){
   tell_room(room, "The Vampire rakes his claws across "+capitalize(attacker_name)+"'s face!\n");
               attacker->hit_player(random(30));
            }
            if(n == 3){
   tell_room(room, capitalize(attacker_name)+" quivers with fear!.\n");
      attacker->add_spell_point(-(random(attacker->query_sp())));
            }
            if(n == 4){
  tell_room(room,"Your knees feel weak and wobbly, your confidence shaken.\n");
      attacker->add_hit_point(-((attacker->query_hp())/6));
            }
       if(n == 5) {
    if(present("vampirefangs", attacker)) {
   tell_object(attacker, "The vampire sneers at you. 'You are not\n"+
     "one of us, you weakling.  Join us! and feel the Real power\n"+
     "of what it is to be a Vampire!\n");
         }
    tell_object(attacker, "The Vampire tells you: You have no chance against me, leave\n"+
   "while you still can!\n");
      }
    if(n == 6) {
  tell_room(room, "The Vampire charms "+capitalize(attacker_name)+" and takes an item!\n");
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
       if(cur->armor_class()) {
       move_object(cur, this_object());
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
