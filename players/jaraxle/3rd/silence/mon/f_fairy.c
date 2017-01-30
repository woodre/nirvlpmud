#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int exp_total;
reset(arg)  {
   object gold;
   exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIM+"Flower"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("flower fairy");
   set_race("fairy");
   set_short(HIM+"Flower"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "A sweet scent surrounds this pretty fairy.  She has "+HIM+"flower petals"+NORM+"\n"+
      "showered into her hair.  Her eyes sparkle with an "+YEL+"amber"+NORM+" glow.\n");
   set_level(12);
   set_hp(180+random(46));
   set_al(0);
   set_ac(9);
   set_wc(16);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy twirls in delight.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(300+random(101));
   move_object(gold,this_object());
}

monster_died() {
   MOCO("/players/jaraxle/3rd/silence/items/dust.c"),environment(this_object()));
   switch(random(3)){
      case 0..1:
      tell_room(environment(this_object()),
         "The dead fairy plops to the ground.\n");
      MOCO("/players/jaraxle/3rd/silence/items/dust.c"),environment(this_object()));
      break;
      case 2:
      tell_room(environment(this_object()),
        "As the fairy plops to the ground a small\nitem falls from her grasp.\n");
      MOCO("/players/jaraxle/3rd/silence/items/ring_piece1.c"),environment(this_object()));
      break;
   }
   return 0; }

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   say("The "+HIM+"Flower"+NORM+" fairy waves her hands in a swooping motion...\n");
   if(ATT_LVL <= 5){
      say("A shower of petals dance around the fairy.\n");
      this_object()->heal_self(1+random(1));
   }
   if(ATT_LVL >= 6){
     say("  A rain of "+HIM+"flower petals"+NORM+" fall from the trees over the fairy.\n");
      this_object()->heal_self(5+random(3));
   }
   if(ATT_LVL >= 10){
      say("    Twirling "+HIM+"flowers"+NORM+" spin from the ground, dancing around the fairy.\n");
      this_object()->heal_self(10+random(8));
     exp_total+=1;
   }
   if(ATT_LVL >= 14){
     say("\t\t"+GRN+"Thorned "+HIR+"roses"+NORM+" shoot into "+ATT_NAME+" like arrows!\n");
     attacker_ob->hit_player(20+random(16));
     exp_total+=1;
   }
}
heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(10);
      switch(i){
         
         case 0..2: DUST();
         break;
         case 3..9: return 0;
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
