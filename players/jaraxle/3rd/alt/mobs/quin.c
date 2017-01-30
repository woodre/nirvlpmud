#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
 no_clean = 1;
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
   set_wander(50, 0, ({ "pass" }));
   set_a_chat_chance(15);
   load_a_chat("Quin reloads her quiver with arrows.\n");
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());

    MOCO("/players/jaraxle/closed/heals/roht.c"),TO);
    MOCO("/players/jaraxle/closed/heals/amplee.c"),TO);
    MOCO("/players/jaraxle/3rd/silence/items/crossbow.c"),this_object());

 switch(random(2)){
case 0:
    MOCO("/players/jaraxle/3rd/silence/armors/helm.c"),this_object());
break;
case 1:
    MOCO("/players/jaraxle/3rd/silence/armors/helm.c"),this_object());
break;
}

    MOCO("/players/jaraxle/3rd/silence/items/pouch.c"),this_object());
   command("wear shield", TP);
   command("wear helmet", TP);
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
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   say("Quin pulls an arrow out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n");
   
attacker_ob->hit_player(10+random(31));
}
}

arrow2(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   say("\nQuin pulls a pair of arrows out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n\tQuin fires a second arrow into "+ATT_NAME+"!\n\n");
   
   attacker_ob->hit_player(30+random(10));
}
}


arrow3(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   say("Quin pulls a trio of arrows out of her quiver.\n"+
      "\tQuin fires an arrow into "+ATT_NAME+"!\n\n\tQuin fires a second arrow into "+ATT_NAME+"!\n\n\tA third arrow drives into "+ATT_NAME+"!\n\n");
   
   attacker_ob->hit_player(30+random(21));
}
}

onslaught(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   say("Quin backhands "+ATT_NAME+" in the face!\n"+
      "  Quin kicks "+ATT_NAME+" in the chest!\n");
      say("\tAs "+ATT_NAME+" staggers back, Quin draws a trio of "+HIR+"flaming"+NORM+" arrows...\n"+
     "\tQuin fires three "+HIR+"flaming"+NORM+" arrows into "+ATT_NAME+"'s chest,\n"+
                                                                  "driving "+ATT_NAME+" into the ground!\n\n");
   
   attacker_ob->hit_player(31+random(20));
}
}

heal_me(){
   switch(random(2)){
case 0:
    command("eat amplee",this_object());
    command("eat amplee",this_object());
    command("eat amplee",this_object());
say("Quin takes fruit from her pouch.\n");
MOCO("/players/jaraxle/closed/heals/amplee.c"),TO);
      break;
case 1:
    command("eat roht",this_object()); 
    command("eat roht",this_object()); 
    command("eat roht",this_object()); 
say("Quin takes fruit from her pouch.\n");
MOCO("/players/jaraxle/closed/heals/roht.c"),TO);
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

