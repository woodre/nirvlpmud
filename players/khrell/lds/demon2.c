
inherit "obj/monster";

reset(arg) {
   ::reset(arg);
if(!arg) {
   object gold;
   set_name("xetra");
   set_level(20);
   set_race("demon");
   set_hp(random(300)+400);
   set_al(-1000);
   set_short("Xetra");
   set_long("A demon with eight inch claws, razor sharp.  It towers ten feet\n"+
      "up, destroying anything in its path.  Red skin burns hot, evaporating\n"+
      "any moisture in the air. \n");
   set_wc(random(18)+20);
   set_ac(random(8)+7);
   set_dead_ob(this_object());
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood","thrashed"," with blood dripping claws","sliced"," cleanly","cut","","grazed","","scratched"," a glancing blow"}));
   set_chance(10);
   set_spell_mess2("The Xetra reaches into your soul with icy fingers.\n"+
      "Cold evil invades your blood, draining your life.");
   set_spell_mess1("The Xetra eats at a soul.");
   set_spell_dam(20);
   set_a_chat_chance(10);
   load_a_chat("Xetra screams in bloodlust.\n");
   load_a_chat("Xetra says:  Hurocdt rufk tri!\n");
   load_a_chat("Xetra says:  Tlurrk bsiri corr.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
}
}

heart_beat() {
   object *ri,first;
   int X,x,so;
   ::heart_beat();
   if(attacker_ob==this_object() && !random(3)) {
      object rob;
      tell_room(environment(),"The xetra screams in rage!\n");
      rob=first_inventory(environment());
      attacker_ob=0;
      while(!attacker_ob && rob) {
         if(living(rob) && rob->query_race() != "demon") {
            attacker_ob=rob; }
         else rob=next_inventory(rob);
      }
   }
   first=attacker_ob;
   for(x=0,ri=all_inventory(environment()),so=sizeof(ri);so>x;x++) {
      if(ri[x]->query_attack() == this_object() && ri[x] != first && !ri[x]->query_npc()) {
         already_fight=0;
         attack_object(ri[x]);
         attack();
      }
         attack_object(first);
   }
   X=2;
   while(!random(X)) {
      already_fight=0;
      attack();
      X++;
   }
}

monster_died() {
   say("The Xetra screams in agony as light explodes from it's dying body.\n");
}

stop_fight() {
  if(!attacker_ob) return;
   if(!attacker_ob->query_interactive() && !attacker_ob->query_npc()) {
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
   }
}
init() {
   ::init();
     add_action("prevent","north");
  add_action("prevent","south");
  add_action("prevent","east");
  add_action("prevent","west");
  add_action("prevent","northeast");
  add_action("prevent","northwest");
  add_action("prevent","southeast");
  add_action("prevent","southwest");
   if(!attacker_ob && !this_player()->query_npc()) {
      attack_object(this_player());
   }
}

prevent() {
int CH;
  if(query_attack()) {
      if(this_player() == query_attack()) CH = 35;
    else CH = 15;
}
  else CH = 10;
  if(random(100) < CH) {
     write("The Xetra prevents you from leaving!\n");
   return 1; }
}

