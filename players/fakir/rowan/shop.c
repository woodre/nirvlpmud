
#include "/room/clean.c"
int weight, value;
string short_str, me;
object itemob;

#define SPEAK(x) write("The shopkeeper says:  "+x)

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object keeper;
   if(!present("shopkeeper")) {
     keeper = clone_object("obj/monster");
     keeper->set_name("shopkeeper");
     keeper->set_short("The local shopkeeper");
     keeper->set_long("The shopkeeper is a middle-aged, well kept man.\n");
     keeper->set_level(3);
     move_object(keeper, this_object());
   }
}

short() { return "The general store of the town of Rowan  [s]"; }

long() {
   write("You are in the General Store of Rowan.  The stone and woodwork\n"+
         "are in good repair making it evident that the place is well cared\n"+
         "for.  A small doorway lies to the north.\n"+
       "You can 'inspect items' for sale in the shop to get a closer look.\n"+
         "     There is one obvious exit:  south\n");
   if(present("shopkeeper")) {
     write("COMMANDS:  buy, sell, list, value, inspect\n");
   } else
     write("The shopkeeper is out right now.  Come back later.\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   if(!present("shopkeeper"))
     return 0;
   add_action("buy","buy");                
   add_action("sell","sell");
   add_action("list","list");
   add_action("inspect","inspect");
   add_action("value","value");
}

north() {
   if(this_player()->query_level() < 21) {
     if(present("shopkeeper")) {
        SPEAK("That's a private store room.  Please stay out.\n");
     } else
        write("The room is locked securely.\n");
     return 1;
   }
   this_player()->move_player("north towards the private store room"+
       "#players/molasar/rowan/store");
   return 1;
}

south() {
   this_player()->move_player("the General Store"+
       "#players/molasar/rowan/e_twn_sq");
   return 1;
}

value(item) {
   if(!item) {
     SPEAK("What would you like to know the value of?\n");
     return 1;
   }
   itemob = present(item, this_player());
   if(!itemob) {
     SPEAK("You do not have a "+item+"\n");
     return 1;
   }
   short_str = itemob->short();
   value = itemob->query_value();
   if(!value) {
      SPEAK(short_str+" is worthless.\n");
      return 1;
   }
   SPEAK(short_str+" is worth "+value+" gold coins.\n");
   return 1;
}

inspect(item) {
   if(!item) {
     SPEAK("What would you like to inspect?\n");
     return 1;
   }
   call_other("players/molasar/rowan/store", "inspect", item);
   return 1;
}

buy(item) {
   if(!item) {
     SPEAK("What would you like to buy?\n");
     return 1;
   }
   call_other("players/molasar/rowan/store", "buy", item);
   return 1;
}


list(item) {
   if(!item)
     item = "all";
   write("\nItems available for sale:\n");
write("[===============================================================]\n");
   call_other("players/molasar/rowan/store","inventory", item);
write("[===============================================================]\n");
   return 1;
}

sell(str) {
   if(!str) {
     SPEAK("What would you like to sell?\n");
     return 1;
   }
   if(str == "all") {
     sell_all();
     return 1;
   }
   itemob = present(str, this_player());
   if(!itemob) {
     SPEAK("You do not have a "+str+".\n");
     return 1;
   }
   sell_item(itemob);
   return 1;
}

sell_all() {
   object invob, next_invob;

   invob = first_inventory(this_player());
   first_inventory(invob); 
   while(invob) {   
      next_invob = next_inventory(invob);
      if(invob->query_value() && !invob->query_drop())
        sell_item(invob);
      invob = next_invob;
   }
   write("All items sold......\n");
   return 1;
}

sell_item(itemob) {
   if(itemob->drop())
     return 1;
   value = itemob->query_value();
   short_str = itemob->short();
   me = this_player()->query_name();
   if(!value) {
     SPEAK(short_str+" has no value.\n");
     return 1;
   }
   if(value > 1000) value = 1000;
   move_object(itemob, "/players/molasar/rowan/store");
   say(capitalize(me)+" sells "+short_str+".\n");
   this_player()->add_weight(-weight);
   this_player()->add_money(value);
   write("You recieve "+value+" gold coins for "+short_str+".\n");
   SPEAK("Thank you!\n");
   return 1;
}


