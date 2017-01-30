#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";
object newspaper, top_list;
object band;

reset(arg) {
   if (!top_list || !present(top_list)) {
      top_list = clone_object("obj/level_list");
      move_object(top_list, this_object());
   }
   if (!present("bartender"))
      move_object(clone_object("obj/bartender"), this_object());
   
   if (!newspaper || !present(newspaper)) {
      newspaper = clone_object("obj/newspaper");
      move_object(newspaper, this_object());
   }
   
   if (arg) return;
   short_desc =  BLK+BOLD+"The local pub"+NORM;
   long_desc =
   "This old pub features paneled walls with wood tables and \n"+
   "chairs scattered about the place. There is a large wooden bar\n"+
   "where the barkeep usually is, serving drinks to all who order.\n"+
   "There are stools in front of the bar and a large mirror with\n"+
   "shelves full of booze behind it. There is a large sign behind\n"+
   "the bar with the drinks and prices written on it.\n";
   add_item("table","Old, crudely made wood tables are throughout the pub");
   add_item("chairs","Simple factory made wood chairs of cheap construction");
   add_item("bar","A worn, ornately carved bar");
   add_item("sign","A sign you can read");
   set_light(0);
   add_exit("/players/jaraxle/3rd/alt/rooms/yard.c","west");
}


init() {
   ::init();
   add_action("order","order");
   add_action("order","buy");
   add_action("cmd_read", "read");
}

cmd_read(str) {
   if(str == "sign"){
      write("A large sign here says:\n");
      write("You can order drinks here.\n\n");
      write("     Warm Beer    :  10 coins\n");
      write("     Sludge       :  20 coins\n");
      write("     Blended Worm :  150 coins\n");
      write("     Insect Urine :  230 coins\n\n");
      return 1;
   }
   return 1;
}   
order(str)
{
   string name, short_desc, mess;
   int value, cost, strength, heal;
   
   if (!str) {
      write("Order what ?\n");
      return 1;
   }
   if (!present("bartender")) {
      write("The bartender is gone and all the bottles appear to be \n"+
         "broken. Their contents spilled on the floor behind the bar.\n");
      return 1;
   }
   if (str == "beer") {
      mess = "That feels disgusting";
      heal = 1;
      value = 10;
      strength = 3;
   }
   else if (str == "worm" || str == "blended worm") {
      mess = "You feel like gagging";
      heal = 10;
      value = 150;
      strength = 7;
   } else if (str == "urine" || str == "insect urine") {
      mess = "You hack and choke it down";
      heal = 25;
      value = 230;
      strength = 14;
   } else if (str == "sludge" || str == "detox") {
      mess = "The sludge coats your stomach";
      heal = 0;
      value = 20;
      strength = -2;
   } else {
      write("The bartender says: What do you want?\n");
      return 1;
   }
   if (call_other(this_player(), "query_money", 0) < value) {
      write("That costs " + value + " gold coins, which you don't have.\n");
      return 1;
   }
   cost = value;
   if (strength > (call_other(this_player(), "query_level") + 2)) {
      if (strength > (call_other(this_player(), "query_level") + 5)) {
         /* This drink is *much* too strong for the player */
         say(call_other(this_player(), "query_name", 0) + " orders a " +
            str + ", and immediately throws it up.\n");
         write("You order a " + str + ", try to drink it, and throw up.\n");
       } else {
         say(call_other(this_player(), "query_name", 0) + " orders a " +
            str + ", and spews it all over you!\n");
         write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
       }
      call_other(this_player(), "add_money", - cost);
      return 1;
   }
   if (!call_other(this_player(), "drink_alcohol", strength)) {
      write("The bartender says: I think you've had enough.\n");
      say(call_other(this_player(), "query_name", 0) + " asks for a " +
         str + " but the bartender refuses.\n");
      
      return 1;
   }
   write("You pay " + cost + " coins for a " + str + ".\n");
   say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
   say("The bartender serves up the drink.\n");
   call_other(this_player(), "add_money", - cost);
   call_other(this_player(), "heal_self", heal);
   write("The bartender serves you your drink.\n");
   write(mess + ".\n");
   return 1;
}
