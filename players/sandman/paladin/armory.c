
#include "/room/clean.c"

int weight, value;
string short_str, me;
object itemob;

#define STORE "players/sandman/paladin/store"
#define SPEAK(x) write("The armorer says:  "+x)

/* To get rid of high/low priced stuff */
#define HIGH_DEST_VALUE 5000
#define LOW_DEST_VALUE 50

realm() { return "NT"; }

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object keeper;
   if(!present("armorer")) {
     keeper = clone_object("obj/monster");
     keeper->set_name("armorer");
     keeper->set_short("The local armorer");
     keeper->set_long("The armorer is a middle-aged, well kept man.\n"+
                "He is clad in platemail wielding a large broadsword.\n"+
                "       The armorer is carrying:\n"+
                "A bronze medallion (worn)\n");
     keeper->set_level(18);
     keeper->set_wc(20);
     keeper->set_ac(8);
     keeper->set_hp(400);
     keeper->set_al(342);
     move_object(keeper, this_object());
   }
}

short() { return "The Paladin Armory"; }

long() {
   write("You are in the Paladin Armory. The stone and woodwork are\n"+
       "in good repair making it evident that the place is well cared\n"+
       "for.  A small doorway lies to the east.\n"+
       "You can 'inspect items' for sale in the shop to get a closer look.\n"+
       "     There is one obvious exit:  west\n");
   if(present("armorer")) 
     write("COMMANDS:  buy, sell, list, value, inspect\n");
   else
     write("The armorer is out right now.  Try again later.\n");
}

init() {
   if(!present("guild_medal", this_player()) &&
       this_player()->query_interactive()) {
      call_other(this_player(), "move_player", "out#room/church");
      return 1;
   }
   if(!this_player()->query_npc()) {
     if(!present("guild_medal", this_player()) && 
                                this_player()->query_level() < 20) {
       write("Only Paladins and Wizards may access this room.\n");
       move_object(this_player(), "/players/sandman/paladin/entry");
       return 1;
     }
   }
   add_action("east","east");
   add_action("west","west");
   add_action("buy","buy");                
   add_action("sell","sell");
   add_action("list","list");
   add_action("inspect","inspect");
   add_action("value","value");
}

east() {
   if(this_player()->query_level() < 21) {
     if(present("armorer")) 
       SPEAK("That's a private store room.  Please stay out.\n");
     else
        write("The room is locked securely.\n");
     return 1;
   }
   this_player()->move_player("east#players/sandman/paladin/store");
   return 1;
}

west() {
   if(present("armorer")) {
     write("\n");
     SPEAK("Thank you now....you come back.\n");
     write("\n");
   }
   this_player()->move_player("west#players/sandman/paladin/hall2");
   return 1;
}

value(item) {
   if(!present("armorer")) {
     write("The armorer is not in right now. Try again later.\n");
     return 1;
   }
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
   if(!present("armorer")) {
     write("The armorer is not in right now. Try again later.\n");
     return 1;
   }
   if(!item) {
     SPEAK("What would you like to inspect?\n");
     return 1;
   }
   STORE->inspect(item);
   return 1;
}

buy(item) {
   if(!present("armorer")) {
     write("The armorer is not in right now. Try again later.\n");
     return 1;
   }
   if(!item) {
     SPEAK("What would you like to buy?\n");
     return 1;
   }
   STORE->buy(item);
   return 1;
}

list(item) {
   if(!item)
     item = "all";
   write("\nItems available for sale:\n");
write("[===============================================================]\n");
   STORE->inventory(item);
write("[===============================================================]\n");
   return 1;
}

sell(str) {
   if(!present("armorer")) {
     write("The armorer is not in right now. Try again later.\n");
     return 1;
   }
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
   weight = this_object()->query_weight();
   short_str = itemob->short();
   me = this_player()->query_name();
   if(!value) {
     SPEAK(short_str+" has no value.\n");
     return 1;
   }
   if(value > HIGH_DEST_VALUE || value < LOW_DEST_VALUE) {
     write("The armorer puts "+short_str+" in a special locker.\n");
     destruct(itemob);
   } else
     move_object(itemob, "/"+STORE);
   say(me+" sells "+short_str+".\n");
   if(value > 1000) value = 1000;
   this_player()->add_weight(-weight);
   this_player()->add_money(value);
   write("You recieve "+value+" gold coins for "+short_str+".\n");
   SPEAK("Thank you!\n");
   return 1;
}
