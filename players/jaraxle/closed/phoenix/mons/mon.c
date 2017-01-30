
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
   set_name(RED+"Phoenix"+NORM);
   set_alias("phoenix");
   set_alt_name("bird");
   set_race("phoenix");
   set_aggro(1, 50, 100);
   set_short(RED+"Phoenix"+NORM);
   set_long("The Phoenix is breathtaking to say the least. Its large\n"+
      "size only enhances its beauty, as it soars and dives in\n"+
      "the sky. Its feathers are composed entirely of fire. Its\n"+
      "tail feathers orange and deep yellow, and its body mostly\n"+
      "dark orange, red and crimson. Other than the feathers of\n"+
      "fire, the Phoenix has huge talons which are razor sharp.\n"+
      "The talons themselves are about a half-foot long, three\n"+
      "curved claws in front, and one larger jagged claw in\n"+
      "the back.\n");
   set_level(25);
   set_hp(1000+random(500));
   set_al(0);
   set_wc_bonus(72);
   
   /* Total: hit_player(75)* 55% = 41.25  + 122/4 (random damage of 4 spells) * 55% = 30.5 
   for wc_bonus of 71.75 or 72.  */
   
   set_ac(24+random(5));
set_heal(10+random(11), 4);
   set_aggressive(0);
   set_wc(45+random(6));
   set_dead_ob(this_object());
   set_chat_chance(4);
   load_chat(HIR+"Flames"+NORM+" dance around the "+RED+"Phoenix"+NORM+"\n");
   load_chat(HIR+"Flames"+NORM+" flicker around the "+RED+"Phoenix"+NORM+"\n");
}

monster_died() {
   object b, c;
   c = present("corpse", environment());
   if(c){ destruct(c); }
   tell_room(environment(this_object()),
      "The "+RED+"Phoenix"+NORM+" is engulfed in flames.\n"+
      "\tA shower of ashes rain down into a pile on the ground.\n");
   MOCO("/players/jaraxle/closed/phoenix/ashes.c") ,environment(this_object()));
switch(random(10)){
case 0..3: MOCO("/players/jaraxle/closed/phoenix/pt1.c"),environment(this_object()));
break;
case 4..7: MOCO("/players/jaraxle/closed/phoenix/pt2.c"),environment(this_object()));
break;
case 8..9: MOCO("/players/jaraxle/closed/phoenix/pt3.c"),environment(this_object()));
break;
}
   return 0; }     


spec2(){
   string ATT_NAME;
   int total_damage, i;
   string body_part;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
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
      say("The "+RED+"Phoenix"+NORM+" stabs its massive beak into "+ATT_NAME+"'s "+body_part+"!\n");
      /*
      say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
      */
   }
  attacker_ob->hit_player(total_damage, "other|fire");
}
}


spec3(){
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   lil_doggy = sizeof(inv);
   tell_room(environment(moose),
      "The "+RED+"Phoenix"+NORM+" screeches in a "+HIR+"rage"+NORM+"!\n"+
      HIR+"\t*FLAMES*"+NORM+" ignight about the entire room . . .\n");
   tell_room(environment(moose),
      "\t\tscorching any flesh licked by the torrential fires.\n\n");
   for(i = 0; i < lil_doggy; i++)
   {
      if(inv[i]->query_name() != "phoenix")
         {
         if(living(inv[i]))
            {
            tell_object(inv[i], "\t"+BRED+HIY+"You are engulfed in flames!"+NORM+"\n"+
               "\t"+BRED+HIY+"Your skin makes popping sounds as it burns!\n"+NORM);
         inv[i]->hit_player(random(25)+50, "other|fire");
         }
       }
   }
}  

spec4(){
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   say("The "+RED+"Phoenix"+NORM+" hacks "+ATT_NAME+"'s chest maliciously with both talons!\n");
   say(HIR+"\t  -"+HIY+"\\"+HIR+"-              -"+HIY+"/"+HIR+"-\n"+
     "\t    -"+HIY+"\\"+HIR+"-         -"+HIY+"/"+HIR+"-\n");
   say("\t       -"+HIY+"\\"+HIR+"-   -"+HIY+"/"+HIR+"-\n"+
    "\t          -"+HIY+"*"+HIR+"-\n"+
    "\t       -"+HIY+"/"+HIR+"-   -"+HIY+"\\"+HIR+"-\n");
   say("\t    -"+HIY+"/"+HIR+"-         -"+HIY+"\\"+HIR+"-\n"+
       "\t -"+HIY+"/"+HIR+"-               -"+HIY+"\\"+HIR+"-\n"+NORM);
   say(HIW+"~ "+NORM+RED+"Blood seeps from deep gashes in "+ATT_NAME+"'s chest. "+HIW+"~\n"+NORM);
 attacker_ob->hit_player(random(36)+25, "other|fire");
}
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(16);
      switch(i){
         
         case 0..3: spec2();
         break;
         
         case 4..7: spec3();
         break;
         
         case 8..11: spec4();
         break;
         
         case 12..15: return 0;
         break;
      }
   }
}
