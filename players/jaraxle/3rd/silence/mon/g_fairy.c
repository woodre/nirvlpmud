#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int exp_total;
reset(arg)  {
   object gold;
    exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIG+"Grass"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("grass fairy");
   set_race("fairy");
   set_short(HIG+"Grass"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "This fairy is a wonderous looking creature.  She has "+HIG+"green hair"+NORM+"\n"+
      "and "+HIG+"bright green eyes"+NORM+".  She has four small, translucent wings on\n"+
      "her back that flutter quickly, keeping her in flight.\n");
   
   set_level(10);
   set_hp(150+random(16));
   set_al(0);
   set_ac(7);
   set_wc(15);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy zips through the air.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(800+random(300));
   move_object(gold,this_object());
}

monster_died() {
   int prize;
   switch(random(8)){
      case 0: prize = "/players/jaraxle/3rd/silence/armors/amulet.c";
      break;
      case 1: prize = "/players/jaraxle/3rd/silence/armors/shield.c";
      break;
      case 2: prize = "/players/jaraxle/3rd/silence/armors/helmet.c";
      break;
      case 3: prize = "/players/jaraxle/3rd/silence/armors/wings.c";
      break;
      case 4..7: prize = "/players/jaraxle/3rd/silence/items/dust.c";
      break;
   }
   tell_room(environment(this_object()),
      "As the dead fairy plops to the ground, an item falls from her grasp.\n");
   move_object(clone_object(prize)),environment(this_object());
   return 0; }

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   say("The "+HIG+"Grass"+NORM+" fairy swarms up a "+HIG+"tornado of leaves."+NORM+"\n");
   if(ATT_LVL <= 5){
      say("The "+HIG+"leaves"+NORM+" dance around "+ATT_NAME+".\n");
      attacker_ob->hit_player(1);
      attacker_ob->hit_player(random(5), "other|earth");
   }
   if(ATT_LVL > 6){
      say("  The "+HIG+"tornado of leaves"+NORM+" glance softly at "+ATT_NAME+".\n");
      attacker_ob->hit_player(1+random(5));
      attacker_ob->hit_player(5, "other|earth");
      exp_total+=1;
   }
   if(ATT_LVL >= 10){
      say("    The "+HIG+"tornado of leaves"+NORM+" snap angrilly at "+ATT_NAME+".\n");
      attacker_ob->hit_player(5+random(6));
      attacker_ob->hit_player(random(7), "other|earth");
      exp_total+=1;
   }
   if(ATT_LVL >= 16){
      say("      The "+HIG+"tornado of leaves"+NORM+" lash "+HIR+"violently"+NORM+" at "+ATT_NAME+".\n");
      attacker_ob->hit_player(15+random(11));
      attacker_ob->hit_player(5+random(6), "other|earth");
      exp_total+=1;
   }
}
heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(11);
      switch(i){
         
         case 0..2: DUST();
         break;
         case 3..10: return 0;
         break;
      }
   }
}
calculate_worth(){
   if(attacker_ob && attacker_ob->is_player())
      set_wc_bonus(exp_total);
   return ::calculate_worth(); }
