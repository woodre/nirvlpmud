/*  10/08/06 - Rumplemintz
      Moved inherit above #include, removed duplicate define of exp_total
*/

inherit "/obj/monster.c";
#include "/players/jaraxle/define.h"
int exp_total;
reset(arg)  {
   object gold;
    exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIY+"SunShine"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("sunshine fairy");
   set_race("fairy");
   set_short(HIY+"SunShine"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "Glowing brightly with an internal light, this fairy has\n"+
      "a strange form to her.  Her body is bright light, with\n"+
      "no real features.  Her hair flows a "+HIY+"golden yellow"+NORM+".  She\n"+
      "has four wings which create a flash of light each time\n"+
      "she flaps them.\n");
   set_level(15);
   set_hp(250+random(46));
   set_al(0);
   set_ac(12);
   set_wc(22);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy twirls in delight.\n");
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
         "As the dead fairy plops to the ground a small\nitem drops from her grasp.\n");
     MOCO("/players/jaraxle/3rd/silence/items/ring_piece3.c"),environment(this_object()));
      break;
   }
   return 0; }

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   say("The "+HIY+"SunShine"+NORM+" fairy raises her hands to the sky...\n");
   if(ATT_LVL <= 5){
     say("A "+HIW+"ray of light"+NORM+" shines on "+HIW+ATT_NAME+NORM+".\n");
      attacker_ob->hit_player(1, "other|fire");
   }
   if(ATT_LVL >= 6){
     say(HIW+"  A ray of light "+NORM+"beams to the "+GRN+"ground"+NORM+" and "+YEL+"tans"+NORM+" "+ATT_NAME+"!\n");
      attacker_ob->hit_player(10+random(6), "other|fire");
   exp_total +=1;
   }
   if(ATT_LVL >= 10){
     say(HIY+"   Bright sunlight "+HIW+"burns"+HIW+" into "+NORM+ATT_NAME+"!\n");
      attacker_ob->hit_player(15+random(6), "other|fire");
   exp_total +=1;
   }
   if(ATT_LVL >= 11){
      say(HIY+"      Rays of light"+NORM+" beam down through the "+GRN+"trees"+NORM+", "+HIR+"burning"+NORM+" "+ATT_NAME+" to a "+HIR+"crisp"+HIY+"!"+NORM+"\n");
      attacker_ob->hit_player(25+random(11), "other|fire");
   exp_total +=1;
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
