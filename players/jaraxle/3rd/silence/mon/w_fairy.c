#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int exp_total;
reset(arg)  {
   object gold;
    exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Woodlands"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("woodlands fairy");
   set_race("fairy");
   set_short(GRN+"Woodlands"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "A strange looking fairy, her skin has a wooden look to it.  Her\n"+
      "hair is dark green, and shaped like thin blades of grass.  She\n"+
      "has two wide wings on her back which flap slowly.\n");
   
   set_level(14);
   set_hp(220+random(31));
   set_al(0);
   set_ac(10);
   set_wc(20);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy zips through the air.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(675+random(51));
   move_object(gold,this_object());
}

monster_died() {
   switch(random(2)){
      case 0:
      tell_room(environment(this_object()),
         "The dead fairy plops to the ground.\n");
      break;
      case 1:
      tell_room(environment(this_object()),
         "As the dead fairy plops to the ground a small\npiece of her ring breaks off to the ground.\n");
      MOCO("/players/jaraxle/3rd/silence/items/ring_piece4.c"),environment(this_object()));
      break;
   }
   return 0; }

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   say("The fairy claps her hands.\n\tThorns crash down from the trees!\n");
   if(ATT_LVL <= 5){
      say("The thorns zip past "+ATT_NAME+".\n");
      attacker_ob->hit_player(random(6), "other|earth");
   }
   if(ATT_LVL >= 6){
    say("  The "+YEL+"thorns"+NORM+" "+HIR+"scratch"+NORM+" across "+ATT_NAME+"'s body!\n"); 
      attacker_ob->hit_player(7+random(6), "other|earth");
      exp_total+=1;
   }
   if(ATT_LVL >= 10){
      say("    "+HIW+"Sharp "+NORM+YEL+"thorns"+HIR+" stab"+NORM+" into "+ATT_NAME+"'s body painfully!\n"); 
      attacker_ob->hit_player(15+random(11), "other|earth");
      exp_total+=1;
   }
   if(ATT_LVL >= 14){
     say("      Powerful "+YEL+"thorns"+HIY+" thunder"+NORM+" into "+ATT_NAME+"'s body!\n");
      attacker_ob->hit_player(20+random(21), "other|earth");
      exp_total+=1;
   }
}
heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(8);
      switch(i){
         
         case 0..2: DUST();
         break;
         case 3..7: return 0;
         break;
      }
   }
}
calculate_worth(){
   if(attacker_ob && attacker_ob->is_player())
      set_wc_bonus(exp_total);
 return ::calculate_worth(); }
