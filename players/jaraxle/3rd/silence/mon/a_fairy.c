#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int exp_total;
reset(arg)  {
   object gold;
   exp_total =0;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIC+"Aqua"+NORM+" Fairy");
   set_alias("fairy");
   set_alt_name("aqua fairy");
   set_race("fairy");
   set_short(HIC+"Aqua"+NORM+" Fairy");
   set_gender("female");
   set_long(
      "  With skin almost transparent, and "+HIB+"deep blue eyes"+NORM+", this fairy seems very magical\n"+
      "indeed.  She has six small, "+HIC+"aqua"+NORM+" colored wings which flap violently to keep her in\n"+
      "flight.  Her "+HIW+"white"+NORM+" hair flows effortlessly down her entire back.\n");
   
   set_level(13);
   set_hp(200+random(46));
   set_al(0);
   set_ac(9);
   set_wc(21);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
   load_chat("Bursts of mist fly about the room as the fairy laughs in delight.\n");
   load_chat("The fairy winks at you playfully.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   load_a_chat("The fairy smacks you!\n\t"+HIC+"Water"+NORM+" slaps you across the face!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(300+random(501));
   move_object(gold,this_object());
}

monster_died() {
   switch(random(4)){
      case 0..2:
      tell_room(environment(this_object()),
         "The dead fairy plops to the ground.\n");
      MOCO("/players/jaraxle/3rd/silence/items/dust.c"),environment(this_object()));
      break;
      case 3:
      tell_room(environment(this_object()),
        "As the fairy plops to the ground a small\nitem falls from her grasp.\n");
      MOCO("/players/jaraxle/3rd/silence/armors/shield2.c"),environment(this_object()));
      break;
   }
   return 0; }

BUBBLE(){
   if( (present("fairy_bubble",this_object())) == 0){
      say("Aqua Fairy spreads out her hand and spins in a circle\n\tA small bubble forms around her!\n");
      MOCO("/players/jaraxle/3rd/silence/armors/bubble.c"),this_object());
      init_command("wear armor");
   }
}

DUST(){
   string ATT_NAME,ATT_LVL,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(ATT_LVL <= 5){
      say(""+HIC+"Aqua Fairy"+NORM+" flicks "+HIC+"water"+NORM+" into "+ATT_NAME+"'s face!\n");
      attacker_ob->hit_player(1, "other|water");
      exp_total+=1;
   }
   if(ATT_LVL >= 6){
      say("  "+HIC+"Aqua Fairy"+NORM+" "+HIW+"blasts"+NORM+" "+ATT_NAME+" with a "+HIB+"wave of water"+NORM+"!\n");
      attacker_ob->hit_player(5, "other|water");
      exp_total+=1;
      attacker_ob->hit_player(1+random(3));
   }
   if(ATT_LVL >= 11){
      say("    A blast of "+HIB+"water"+NORM+" drowns "+ATT_NAME+"!\n");
      attacker_ob->hit_player(9, "other|water");
      exp_total+=1;
      attacker_ob->hit_player(2+random(8));
   }
   if(ATT_LVL >= 15){
      say("      A "+HIB+"TSU"+HIW+"N"+HIB+"AMI of water"+HIR+" crashes"+NORM+" over "+ATT_NAME+"!\n");
      attacker_ob->hit_player(17, "other|water");
      exp_total+=1;
      attacker_ob->hit_player(5+random(12));
   }
}
heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(10);
      switch(i){
         
         case 0..3: DUST();
         break;
         case 4..7: BUBBLE();
         break;
         case 8..9: return 0;
         break;
      }
   }
}
calculate_worth(){
   if(attacker_ob && attacker_ob->is_player())
tell_object(find_player("jaraxle"), "exp_total: "+exp_total+"\n");
      set_wc_bonus(exp_total);
   return ::calculate_worth(); }
