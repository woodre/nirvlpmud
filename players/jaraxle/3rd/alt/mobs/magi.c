#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Alejandro");
   set_alias("alejandro");
   set_race("human");
   set_short("Alejandro, the "+HIM+"Magi"+NORM);
   set_long("A tall thin man covered in age.  A long white\n"+
      "beard grows unkept from his wrinkled chin.\n"+
      "His glasses are thin, without frame, and barely\n"+
      "cover hiss squinting eyes.  He leans his scrawny\n"+
      "body on an old gnarled staff.\n");
   set_level(18);
   set_hp(500);
   set_al(0);
   set_wc(30);
   set_ac(45);
   set_aggressive(0);
   
   set_chat_chance(20);
   load_chat("Alejandro asks, 'Please look at the sign.'\n");
   load_chat("Alejandro asks, 'Please look at the sign.'\n");
   load_chat("Alejandro says, 'If you have any spirits, I will trade.'\n");
  load_chat("Alejandro says,\n\t'Spirits are hard to come by...'\n\t'I have special items for spirits.'\n");
   set_chance(15);
   set_spell_dam(75+random(36));
   
   set_spell_mess1(
      "\n\nAlejandro blasts you with a Fireball.\n");
   set_spell_mess2(
      "\n\nAlejandro blasts you with a Fireball.\n");
   gold = clone_object("obj/money");
   gold->set_money(200+random(200));
   move_object(gold,this_object());
}

init() {
   ::init();
   add_action("buy_it","buy");
   add_action("cmd_trade","trade");
}

cmd_trade(str){
   object SPECIAL;
   object SPB;
   SPB = present("spirit_in_a_bottle",TP);
   
   switch(random(6)){
      case 0: SPECIAL = "/players/jaraxle/3rd/alt/items/armor_orb";
      break;
      case 1: SPECIAL = "/players/jaraxle/3rd/alt/items/defense_orb";
      break;
      case 2: SPECIAL = "/players/jaraxle/3rd/alt/items/healing_orb";
      break;
      case 3: SPECIAL = "/players/jaraxle/3rd/alt/items/holding_orb";
      break;
      case 4: SPECIAL = "/players/jaraxle/3rd/alt/items/mana_orb";
      break;
      case 5: SPECIAL = "/players/jaraxle/3rd/alt/items/nature_orb";
      break;
   }
   
   if(str == "bottle"){
      if(SPB){
switch(random(11)){
case 0..9:
write("Alejandro says: Good job, but that is a weakened spirit.\n"+
"Alejandro says: Here, I will give you a bag of coins for it.\n");
move_object(clone_object("/players/jaraxle/3rd/alt/items/coinbag.c"),TP);
break;
case 10:
         write("Alejandro says: Wow! You captured a spirit!\n"+
            "Alejandro says: Here, take this in exchange!\n"+
            "Alehandro hands you a special item!\n");
         move_object(clone_object(SPECIAL),TP);
break;
}
         destruct(SPB);
         return 1; }
   }
   write("Alejandro says: What would you like to trade?\n"); return 1; }

buy_it(arg) {
   if(TP->query_money() < 4000){
      write("Alejandro says: You do not have enough for that, I'm sorry.\n");
      return 1; }
   
   if(!TP->add_weight(1)){ write("Alejandro tells you: You cant carry this!\n"); return 1; }
   
   if(arg == "earth" || arg == "earth orb"){
      tell_object(TP, "You buy an Earth Orb for "+HIY+"4000"+NORM+" coins.\n");
      TP->add_money(-4000); 
      MOCO("/players/jaraxle/3rd/alt/items/earth.c"),TP);
   tell_room(environment(TP), TPN+" buys an Earth Orb.\n");
   return 1; }

  if(arg == "flame" || arg == "flame orb"){
   tell_object(TP, "You buy a Flame Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/flame.c"),TP);
   tell_room(environment(TP), TPN+" buys a Flame Orb.\n");
   return 1; }

  if(arg == "good" || arg == "good orb"){
   tell_object(TP, "You buy a Good Orb for "+HIY+"4000"+NORM+" coins.\n");
   MOCO("/players/jaraxle/3rd/alt/items/good.c"),TP);
   TP->add_money(-4000); 
   tell_room(environment(TP), TPN+" buys a Good Orb.\n");
   return 1; }

  if(arg == "hate" || arg == "hate orb"){
   tell_object(TP, "You buy a Hate Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/hate.c"),TP);
   tell_room(environment(TP), TPN+" buys a Hate Orb.\n");
   return 1; }

  if(arg == "laser" || arg == "laser orb"){
   tell_object(TP, "You buy a Laser Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/laser.c"),TP);
   tell_room(environment(TP), TPN+" buys a Laser Orb.\n");
   return 1; }

  if(arg == "love" || arg == "love orb"){
   tell_object(TP, "You buy a Love Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/love.c"),TP);
   tell_room(environment(TP), TPN+" buys a Love Orb.\n");
   return 1; }

  if(arg == "lightning" || arg == "lightning orb"){
   tell_object(TP, "You buy a Lightning Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/lightning.c"),TP);
   tell_room(environment(TP), TPN+" buys a Lightning Orb.\n");
   return 1; }

  if(arg == "poison" || arg == "poison orb"){
   tell_object(TP, "You buy a Poison Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/poison.c"),TP);
   tell_room(environment(TP), TPN+" buys a Poison Orb.\n");
   return 1; }

  if(arg == "water" || arg == "water orb"){
   tell_object(TP, "You buy a Water Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/water.c"),TP);
   tell_room(environment(TP), TPN+" buys a Water Orb.\n");
   return 1; }

  if(arg == "wind" || arg == "wind orb"){
   tell_object(TP, "You buy a Wind Orb for "+HIY+"4000"+NORM+" coins.\n");
   TP->add_money(-4000); 
   MOCO("/players/jaraxle/3rd/alt/items/wind.c"),TP);
   tell_room(environment(TP), TPN+" buys a Wind Orb.\n");
   return 1; }

if(arg == "bottle" || arg == "empty bottle"){
tell_object(TP, "You buy an empty bottle for "+HIY+"4000"+NORM+" coins.\n");
TP->add_money(-4000); 
  MOCO("/players/jaraxle/3rd/alt/items/bottle.c"),TP);
tell_room(environment(TP), TPN+" buys an empty bottle.\n");
return 1; }

   write("Alejandro says: Look at the sign to see what I have.\n"); return 1; }
