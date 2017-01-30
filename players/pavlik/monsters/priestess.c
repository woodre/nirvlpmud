inherit "obj/monster";
int head1,head2,head3,head4,head5;
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
   object weapon,armor,misc,gold;
   ::reset(arg);
   if(arg) return;
   set_name("priestess");
   set_race("drow");
   set_alias("priestess");
   set_short("Head priestess");
   set_level(30);
   set_hp(2000);
   set_al(-1000);
   set_wc(16);
   set_ac(20);
   set_chat_chance(25);
   load_chat("The priestess screams: Go away you filtyh hordes of Set!\n");
   load_chat("The priestess screams: Your master is dead and soon you shall be too!!!\n");
   load_chat("The priestess searches through her book of spells.\n");
   load_chat("The priestess casts a spell and the dead warrior at her feet rises again.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+1000);
   move_object(gold,this_object());
   weapon = clone_object("/players/sweetness/weapon/staff");
   move_object(weapon,this_object());
   armor = clone_object("/players/sweetness/armor/robes");
   move_object(armor,this_object());
   misc = clone_object("/players/death/stuff/tome");
   move_object(misc,this_object());
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
            dam = random(10);
            if(n == 1){
               tell_room(room,"The priestess draws energy from "+attacker_name+"\n");
               attacker->hit_player(dam);
               attacker->add_spell_point(-dam);
               this_object()->heal_self(dam*2);
               tell_room(room,"The priestess seems healthier.\n");
            }
            if(n == 2){
               tell_room(room,"The priestess casts a bolt of fire at "+attacker_name+"\n");
               attacker->hit_player(random(50));
            }
            if(n == 3){
               tell_room(room,"The priestess chants an ancient spell at "+attacker_name+"\n");
               attacker->add_spell_point(-random(attacker->query_sp()));
            }
            if(n == 4){
               if(random(100) < 5){
                  tell_room(room,"The priestess sucks life force from "+attacker_name+"\n");
                  tell_object(attacker,"You feel weaker.\n");
                  attacker->raise_strength(-5);
               }
            }
            if(n == 5){
               tell_room(room,"The priestess is greedy and steals from "+attacker_name+"\n");
               attacker->add_money(-random(attacker->query_money()/10));
               tell_object(attacker,"You feel poorer.\n");
            }
            if(n == 6){
               tell_room(room,"The priestess draws energy from everyone in the room.\n");
               tell_room(room,"The priestess looks healthier.\n");
               drain();
            }
         }
      }
   }
}
drain(){
   object ob;
   ob = first_inventory(environment(this_object()));
   while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      if(living(cur)){
         if(cur->query_npc() != 1){
            cur->add_spell_point(-random(20)-10);
            this_object()->heal_self(random(10)+20);
         }
         }
   }
   return 1;
}
