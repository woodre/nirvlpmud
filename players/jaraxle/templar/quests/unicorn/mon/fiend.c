
#include "/players/jaraxle/define.h"
#define moose this_object()->query_attack()
#define moosen capitalize(moose->query_name())
#define dam_count query_dam_taken_this_round()
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  
{
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name(GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM);
   set_alias("fiend");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM);
   set_long("  Xen"+HIG+"-"+NORM+"Xion is the ultimate "+HIR+"Champion"+NORM+" from the Coorquak clan.\n"+
      "It has six lenghty "+BLK+BOLD+"tenticles"+NORM+" that sway elegantly behind its back.\n"+
      "It's skin, reflective in nature, has a distinct combonation of blue\n"+
      "and green hues.  It has enormous hands with large metallic talons\n"+
      "for fingers and long, deep black hair that is braided in strands.\n"+
      "It is without eyelids, eyes; black as onyx, deep as any black-hole,\n"+
      "and sparkling with wetness, glare stonely forward.\n");  
   set_level(25);
   set_hp(10);
   set_al(-1300);
   set_wc_bonus(72);
   
   /* Total: hit_player(75)* 55% = 41.25  + 122/4 (random damage of 4 spells) * 55% = 30.5 
   for wc_bonus of 71.75 or 72.  */
   
   set_ac_bonus(11);
   
   /* Total: heal_self 30% chance for total damage taken+random total damage take
   in a round of combat if over 30points of damage taken.  This was a little harder to
      calculate - 30*30%*2 = 19. That's the bare minimum, if damage is at 30 w/o calculating the
      random.  I put it at 11 for playability sake, after continuous testing w/ a 19+5 player
   solo, using sonic & wc20 weapon he healed about 50 each time it went off which = 15.
   */
   
   set_ac(24+random(5));
   set_aggressive(0);
   set_wc(45+random(6));
   set_dead_ob(this_object());
   set_chat_chance(4);
   load_chat("The "+GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM+" bellows, 'You will not escape!'\n");
}

monster_died() {
   write_file("/players/jaraxle/templar/quests/unicorn/kill.log",ctime(time())+" "+HIB+this_player()->query_name()+NORM+" killed the "+BOLD+BLK+"Fiend\n"+NORM);
   tell_room(environment(this_object()),
      GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM+" crashes heavilly to the ground.\n");
   return 0; }     


spec1(){
   
   string ATT_NAME,msg;
   int total_damage, i;
   string hit_type;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say("\nXen"+HIG+"-"+NORM+"Xion's "+BLK+BOLD+"tenticles"+NORM+" scream at "+ATT_NAME+"...\n");
   for(i = 0; i < 6; i++) {
      switch(random(7)){
         case 0: hit_type = ""+HIB+"lashes"+NORM+"";
         total_damage +=14;
         break;
         
         case 1: hit_type = ""+HIY+"slashes"+NORM+"";
         total_damage +12;
         break;
         
         case 2: hit_type = ""+HIC+"slices"+NORM+"";
         total_damage +=9;
         break;
         
         case 3: hit_type = ""+HIG+"thrashes"+NORM+"";
         total_damage +=8;
         break;
         
         case 4: hit_type = ""+HIM+"whips"+NORM+"";
         total_damage +=5;
         break;
         
         case 5: hit_type = ""+HIR+"welts"+NORM+"";
         total_damage +=3;
         break;
         
         case 6: hit_type = ""+HIW+"misses"+NORM+"";
         total_damage +=0;
         break;
       }
      
      say("\tA "+BLK+BOLD+"tenticle"+NORM+" "+hit_type+" at "+ATT_NAME+"\n");
   }
   
   attacker_ob->hit_player(total_damage);
   /*
   say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
   */
   
}

spec2(){
   string ATT_NAME,msg;
   int total_damage, i;
   string body_part;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   for(i = 0; i < 1 + random(6); i++)
   {
      switch(random(6)){
         case 0: body_part = "foot";
         total_damage +=2;
         break;
         case 1: body_part = "thigh";
         total_damage +=5;
         break;
         case 2: body_part = "chest";
         total_damage +=8;
         break;
         case 3: body_part = "arm";
         total_damage +=10;
         break;
         case 4: body_part = "stomach";
         total_damage +=12;
         break;
         case 5: body_part = "bicept";
         total_damage +=3;
         break;
       }
      say("A "+BLK+BOLD+"tenticle"+NORM+" "+RED+"stabs"+NORM+" into "+ATT_NAME+"'s "+body_part+"!\n");
      /*
      say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
      */
   }
   attacker_ob->hit_player(total_damage);
}


spec3(){
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   lil_doggy = sizeof(inv);
   tell_room(environment(moose),
      GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM+" roars in "+RED+"anger"+NORM+"!\n"+
      "\tThe "+GRN+"Goblin"+BOLD+BLK+" Fiend"+NORM+" swings its mighty arms around in circles. . .\n");
   tell_room(environment(moose),
      "Its large and powerful fists smash through everything!\n");
   for(i = 0; i < lil_doggy; i++)
   {
      if(inv[i]->query_name() != "goblin")
         {
         if(living(inv[i]))
            {
            tell_object(inv[i], "\tA "+GRN+"large fist"+NORM+" pounds into your chest!\n");
            inv[i]->hit_player(25 + random(26));
         }
       }
   }
}  

spec4(){
   string ATT_NAME,msg;  if(attacker_ob) 
      ATT_NAME = attacker_ob->query_name();
   say(HIW+"~ "+NORM+RED+"Blood seeps from deep gashes in "+ATT_NAME+"'s chest. "+HIW+"~\n"+NORM);
   attacker_ob->hit_player(25+random(36));
}


heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(21);
      switch(i){
         
         case 0..2: spec1();
         break;
         
         case 3..8: spec2();
         break;
         
         case 9..10: spec3();
         break;
         
         case 11..14: spec4();
         break;
         
         case 15..20: return 0;
         break;
      }
   }
}
