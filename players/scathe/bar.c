inherit "room/room";

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
   short_desc="Scathe's Spirit Store";
   long_desc = "Scathe's take out bar for all your healing\n"+
   "needs.  Newbies, stick to the 8ball, as the other drinks\n"+
   "are for players of great fame and power.\n\n"+
   "     8-Ball (Newbie drink)            40 coins\n"+
   "     Colt45 (Malt Liquor)             750 coins\n"+
   "     Purple Passion (A bit stronger)  10000 coins\n"+
   "     Cheap Wine (in a bag)            10000 coins\n"+
   "     Bacardi (Strong Stuff!)          10000 coins\n"+
   "     Alka Seltzer (Relief)            10000 coins\n";
   set_light(1);
   dest_dir = 
   ({
         "/players/scathe/cave/entry","east"
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
   if (str == "alka" || str == "alka seltzer") {
      name = str;
      short_desc = "A glass of Alka Seltzer";
      mess = "Plop plop fizz fizz oh what a relief it is!!";
      heal = 0;
      value = 10000;
      strength = -45;
   } else if (str == "8-ball") {
      name = "8-ball";
      short_desc = "A bottle of 8-Ball";
      mess = "That 8-Ball is Kickin!";
      heal = 1;
      value = 40;
      strength = 3;
   } else if (str == "colt45" || str == "malt"  || str == "Colt45") {
      name = "colt45";
      short_desc = "Colt45 Malt Liquor";
      mess = "Billy Dee Williams says: Colt45!";
      heal = 50;
      value = 750;
      strength = 9;
   } else if (str == "passion") {
      name = "passion";
      short_desc = "A 2 liter of Purple Passion";
      mess = "Ah, that was good!!!";
      heal = 100;
      value = 10000;
      strength = 15;
   } else if (str == "wine" || str == "cheap wine") {
      name = str;
      short_desc = "A bottle of wine in a paper bag";
      mess = "Don't drink that wine!!!!";
      heal = 200;
      value = 10000;
      strength = 15;
   } else if (str == "bacardi") {
      name = str;
      short_desc = "Bacardi, that Puerto Rican Rum";
      mess = "You hit the Bacardi";
      heal = 360;
      value = 10000;
      strength = 25;
#if 0
   } else if (str == "potion" || str == "potion of healing") {
      name = "potion";
      short_desc = "A potion of healing";
      mess = "You are totally healed";
      heal = 1000;
      value = 10000;
      strength = 0;
#endif
   } else {
      write("Scathe yells: MORON!  Do a look!! That aint for sale here!!!!\n");
      return 1;
   }
   if (call_other(this_player(), "query_money", 0) < value) {
      write("Scathe says:  Do a score fool, you're too poor to buy that!!!!\n");
      return 1;
   }
   drink = clone_object("/obj/drink");
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
   write("You pay " + value + " for a " + name + ", which Scathe hands to you.\n");
   say(call_other(this_player(), "query_name", 0) + " orders a " +
      name + ".\n");
   return 1;
}
