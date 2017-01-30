/* 10/08/06 - Rumplemintz
      Moved inherit above #include statement
      Changed 'orb' to 'mana' in object cloning to fix
*/

inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/jaraxle/define.h"
int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   call_out("walk", 10);
   set_name("quin");
   set_alias("maiden");
   set_alt_name("huntress");
   set_race("human");
   set_gender("female");
   set_short("Quin, the Fairy Huntress");
   set_level(20);
   set_hp(500+random(101));
   set_al(0);
   set_aggressive(0);
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   set_a_chat_chance(15);
   load_a_chat("Quin reloads her quiver with arrows.\n");
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());
   MOCO("/players/jaraxle/3rd/warrior/heals/caocao.c"),this_object());
    MOCO("/players/jaraxle/3rd/warrior/heals/teenom.c"),this_object());
switch(random(2)){
case 0:
    MOCO("/players/jaraxle/3rd/silence/items/crossbow.c"),this_object());
break;
case 1:
    MOCO("/players/jaraxle/3rd/silence/items/elfsword.c"),this_object());
break;
}
    MOCO("/players/jaraxle/3rd/silence/armors/mana.c"),this_object());
    MOCO("/players/jaraxle/3rd/silence/items/pouch.c"),this_object());
/*
   command("activate orb", TP);
*/
   command("wield weapon", TP);
   set_ac(17);
   set_wc(30+random(8));
} 
long(){ write("Quin is a Huntress from the TreeTop Village,  one of Willa's\n"+
                    "most prized and decorated Warrior Maidens. Quin is a tall,\n"+
                    "muscular woman with long black hair, which has been tied\n"+
                    "back into a braided ponytail.\n"); }
                   

drink_soft(x){ return 1; }
eat_food(x){ return 1; }

monster_died() {
   tell_room(environment(this_object()),
      "With a final breath Quin sinks softly into the grass.\n");
   return 0; }

arrow1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("Quin pulls an arrow out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n");
   
   attacker_ob->hit_player(-5-random(10));
}

arrow2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("\nQuin pulls a pair of arrows out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n\tQuin fires a second arrow into "+ATT_NAME+"!\n\n");
   
   attacker_ob->hit_player(10+random(10));
}

arrow3(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("Quin pulls a trio of arrows out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n\tQuin fires a second arrow into "+ATT_NAME+"!\n\n\tA third arrow drives into "+ATT_NAME+"!\n\n");
   
   attacker_ob->hit_player(20+random(10));
}

onslaught(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("Quin backhands "+ATT_NAME+" in the face!\n"+
      "  Quin kicks "+ATT_NAME+" in the chest!\n");
      say("\tAs "+ATT_NAME+" staggers back, Quin draws a trio of "+HIR+"flaming"+NORM+" arrows...\n"+
     "\tQuin fires three "+HIR+"flaming"+NORM+" arrows into "+ATT_NAME+"'s chest,\n"+
                                                                  "driving "+ATT_NAME+" into the ground!\n\n");
   
   attacker_ob->hit_player(31+random(20));
}

heal_me(){
   switch(random(2)){
case 0:
    command("eat fruit",this_object());
    command("eat fruit",this_object());
say("Quin takes a "+HIM+"Ca"+HIY+"oCao"+NORM+" fruit from her pouch.\n");
    MOCO("/players/jaraxle/3rd/warrior/heals/caocao.c"),TO);
      break;
case 1:
    command("squeeze fruit",this_object());
    command("squeeze fruit",this_object());
say("Quin takes a "+HIR+"Teen"+HIB+"om"+NORM+" fruit from her pouch.\n");
    MOCO("/players/jaraxle/3rd/warrior/heals/teenom.c"),TO);
      break;
   }
   

   this_object()->heal_self(11+random(21));
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(17);
      switch(i){
         
         case 0..2: arrow1();
         break;
         
         case 3..5: arrow2();
         break;
         
         case 6..7: arrow3();
         break;
         
         case 8..10: heal_me();
         break;
         
         case 11..12: onslaught();
         break;
         
         case 13..16: return 0;
         break;
      }
   }
}
walk(){
   string direct;
   switch(random(8)){
      case 0: direct = "north";
      break;
      case 1: direct = "south";
      break;
      case 2: direct = "east";
      break;
      case 3: direct = "west";
      break;
      case 4: direct = "northeast";
      break;
      case 5: direct = "northwest";
      break;
      case 6: direct = "southwest";
      break;
      case 7: direct = "southeast";
      break;
   }
   command(direct, this_player());
   call_out("walk", 10);
}
