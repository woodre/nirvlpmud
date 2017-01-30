inherit "/players/persephone/closed/thingys.c";

object top_list,player;

init(){
   ::init();
   add_action("order","order");
   add_action("order","buy");
}
reset(arg) {
   if(arg){return;}
   if(!top_list || !present(top_list,this_object())){
      top_list = clone_object("obj/level_list");
      move_object(top_list,this_object());
   }
   short_desc="Stormin Norman Bates' Liquer Shop";
   long_desc = "Storman Norman Bates' outlet of fine spirits and\n"+
               "heals. Our motto is no pirate ship to small or order to\n"+
               "large.  All beverages are for persons level 10 and over\n\n"+
   "     Inner Circle (Island Rum)  500 coins\n"+
   "     Shanghai (Our Special Mix) 750 coins\n"+
   "     Captains Choice (beer)     1000 coins\n"+
   "     Whiplash (Heal in a shot!) 10000 coins\n"+
   "     Coffee (coffee)            180 coins\n";
   set_light(1);
   dest_dir = 
   ({
         "/players/persephone/rooms/square8","west"
    });
}





order(str)
{
   object drink;
   string name, short_desc, mess;
   int value, cost, strength, heal;
   
   if (!str) {
      write("Order what ?\n");
      return 1;
   }
   if (str == "coffee" ) {
      name = "coffee";
      short_desc = "A strong black coffee";
      mess = "You feel slightly more sober";
      heal = 0;
      value = 180;
      strength = -10;
   } else if (str == "rum"||str=="inner circle"||str=="Inner Circle") {
      name = "rum";
      short_desc = "Inner Circle Rum";
      mess = "You feel like you could handle anything";
      heal = 50;
      value = 500;
      strength = 14;
   } else if (str == "Shanghai" || str == "shanghai"  || str == "special mix") {
      name = "shanghai";
      short_desc = "A Shanghai Cocktail";
      mess = "You feel like you have been Shanghaid for a ship!!";
      heal = 50;
      value = 750;
      strength = 10;
   } else if (str == "ale") {
      name = "ale";
      short_desc = "A Barrel of the finest Ale";
      mess = "Ah, that was good!!!";
      heal = 50;
      value = 1000;
      strength = 6;
#if 0
   } else if (str == "whiplash" || str == "Whiplash"||str=="heal") {
      name = "whiplash";
      short_desc = "A potion of healing";
      mess = "You are totally healed";
      heal = 1000;
      value = 10000;
      strength = 0;
#endif
   } else {
      write("Norman shrugs we do not have that here look!\n");
      return 1;
   }
   if (call_other(this_player(), "query_money", 0) < value) {
      write("Scathe says:  Do a score fool, you're too poor to buy that!!!!\n");
      return 1;
   }
   drink = clone_object("players/persephone/closed/drink");
   if (!call_other(this_player(), "add_weight",
            call_other(drink, "query_weight"))) {
      write("You can't carry more.\n");
      destruct(drink);
      return 1;
   }
   if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess +
            "#" + heal + "#" + value + "#" + strength)) {
      write("Error in creating drink.\n");
      destruct(drink);
      return 1;
   }
   call_other(drink, "set_pub");
   move_object(drink, this_player());
   call_other(this_player(), "add_money", - value);
   write("You pay " + value + " for a " + name + ", which Norman shoves into you.\n");
   say(call_other(this_player(), "query_name", 0) + " orders a " +
      name + ".\n");
   return 1;
}
