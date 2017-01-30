#include "/players/llew/closed/ansi.h"

inherit "obj/monster";

reset(arg) {
   ::reset(arg);
if(!arg) {
   move_object(clone_object("/players/llew/closed/crystal/xetra_claws.c"),this_object());
   set_name(RED+"Xetra"+NORM);
   set_level(25);
   set_alt_name("xetra");
   set_race("demon");
   set_hp(random(250)+1400);
   set_al(-1000);
   set_aggressive(1);
   set_short(RED+"Xetra"+NORM);
   set_long("Darkness surrounds the xetra, broken only by it's red glowing\n"+
            "eyes and the reflection off it's long metallic claws.\n");
   set_wc(random(10)+44);
   set_wc_bonus(35);
   set_ac(25);
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood","thrashed"," with blood dripping claws","sliced"," cleanly","cut","","grazed","","scratched"," a glancing blow"}));
   set_chance(35);
   set_spell_mess2(RED + "The Xetra reaches into your soul with icy claws.\n"+
      "Cold evil invades your blood, draining your life" + NORM);
   set_spell_mess1("The Xetra eats at a soul");
   set_spell_dam(60);
   set_a_chat_chance(10);
   set_chat_chance(7);
   load_chat("The Xetra looks at you with hunger.\n");
   load_chat("Xetra whispers:  Welcome to my hell.\n");
   load_chat("The Xetra lashes out with it's claws.\n");
   load_chat("The Xetra eyes glow with a red light.\n");
   load_a_chat("The Xetra eats the blue light.\n");
   load_a_chat("Xetra says:  Hurocdt rufk tri!\n");
   load_a_chat("Xetra says:  Tlurrk bsiri corr.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
   set_dead_ob(this_object());
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
   if(attacker_ob) {
      first=attacker_ob;
      for(x=0,ri=all_inventory(environment()),so=sizeof(ri);so>x;x++) {
         if(ri[x]->query_attack() == this_object() && ri[x] != first && !ri[x]->query_npc()) {
            already_fight=0;
            attack_object(ri[x]);
         }
            attack_object(first);
      }
      for(X=1;!random(X);X++) {
         already_fight=0;
         attack();
      }
      if(!random(5)) {
         object crystal;
         say("Xetra summons a ball of "+RED+"Red Energy"+NORM+" to his aid.\n");
         crystal=clone_object("/players/llew/closed/crystal/energy.c");
         transfer(crystal,environment());
         crystal->attack_object(attacker_ob);
      }
   }
   if(!random(5)) random_move();
   if(hit_point < 100 && !random(4) && present("energy")) {
      say("The Xetra grasps some red energy and absorbs it.\n");
      heal_self(present("energy")->query_hp());
      set_hp_bonus(query_hp_bonus() + present("energy")->query_hp());
      destruct(present("energy"));
   }
}



monster_died() {
write_file("/players/llew/closed/logs/big_demon",attacker_ob->query_name()+" killed me at "+ctime(time())+".\n");
}


random_move() {
   string direc;
   direc=(string)({"north","south","east","west"})[random(4)];
   if(command(direc)) 
      tell_room(environment(),"Xetra leaves "+direc+".\n");
}
