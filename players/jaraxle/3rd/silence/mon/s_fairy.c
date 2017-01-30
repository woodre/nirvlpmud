#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int exp_total;
reset(arg)  {
   object gold;
   exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIB+"Sky"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("sky fairy");
   set_race("fairy");
   set_short(HIB+"Sky"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "This fairy is a wonderous looking creature.  She has bright, "+HIW+"white hair"+NORM+"\n"+
      "and "+HIB+"deep blue eyes"+NORM+".  She has four small, translucent wings on her back\n"+
      "that flutter quickly, keeping her in flight.\n");
   
   set_level(15);
   set_hp(250+random(36));
   set_al(0);
   set_ac(10);
   set_wc(25);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy twirls in delight.\n");
   load_chat(HIB+"Sky"+NORM+" fairy smiles sweetly at you.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(750+random(101));
   move_object(gold,this_object());
}

monster_died() {
   MOCO("/players/jaraxle/3rd/silence/items/dust.c"),environment(this_object()));
   switch(random(3)){
      case 0..1:
      tell_room(environment(this_object()),
         "The dead fairy plops to the ground.\n");
      break;
      case 2:
      tell_room(environment(this_object()),
         "As the dead fairy plops to the ground a small\npiece of her ring breaks off to the ground.\n");
      MOCO("/players/jaraxle/3rd/silence/items/ring_piece2.c"),environment(this_object()));
      break;
   }
   return 0; }

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   say(HIB+"Sky"+NORM+" fairy whips up a gust of wind...\n");
   if(ATT_LVL <= 5){
      say("A breeze whisks by "+ATT_NAME+".\n");
      attacker_ob->hit_player(1, "other|wind");
      attacker_ob->hit_player(random(4));
   }
   if(ATT_LVL >= 6){
      say(HIB+"\tWinds blow into "+ATT_NAME+".\n"+NORM);
      attacker_ob->hit_player(5, "other|wind");
      attacker_ob->hit_player(1+random(3));
   exp_total +=1;
   }
   if(ATT_LVL >= 10){
      say(HIW+"\tA gust of wind pushes "+ATT_NAME+" to the floor!"+NORM+"\n");
      attacker_ob->hit_player(9, "other|wind");
      attacker_ob->hit_player(2+random(8));
   exp_total +=1;
   }
   if(ATT_LVL >= 15){
      say(HIB+"\n\tThunderous winds punish "+ATT_NAME+".\n"+NORM);
      attacker_ob->hit_player(17, "other|wind");
      attacker_ob->hit_player(5+random(12));
   exp_total +=1;
   }
}
heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(11);
      switch(i){
         
         case 0..3: DUST();
         break;
         case 4..10: return 0;
         break;
      }
   }
}

/* This calculate worth is necessary IMHO b/c of the spells casted by the fairy
   which are based on the level of the player.  Using this calculate worh it is
   an easier calculation of the difficulty of the mob for gained exp. */

calculate_worth(){
   if(attacker_ob && attacker_ob->is_player())
      set_wc_bonus(exp_total);
 return ::calculate_worth(); }
