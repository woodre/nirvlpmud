inherit "obj/monster";
  object crap;
reset(arg){
   object weapon,armor,misc,gold;
   ::reset(arg);
   if(arg) return;
   set_name("Purple Slime");
   set_race("slime");
   set_alias("slime");
   set_short("A Puddle of Slime");
  set_long("This is a puddle of bubbling, brainless Purple slime.\n");
   set_level(15);
   set_hp(225);
   set_al(0);
   set_wc(20);
   set_ac(10);
   set_aggressive(1);
   gold=clone_object("obj/money");
   gold->set_money(random(500)+500);
   move_object(gold,this_object());
   crap = clone_object("players/pavlik/items/junk.c");
      move_object(crap, this_object());
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
             if(n <= 2){
  tell_object(attacker, "You slip on the slick purple slime and go crashing\n"+
       "back down the stairs...Ouch that hurt!\n");
 tell_room(room, capitalize(attacker_name)+" slips on the purple slime and goes tumbling\n"+
   "   down the stairs.\n");
     move_object(attacker, "players/pavlik/castle/room10.c");
         command("look", attacker);
               attacker->hit_player(random(20));
         }
      }
   }
}
   return 1;
}
