#define DEST "room/eastroad4"
#include "/players/llew/closed/ansi.h"

id(str) {
   return
      str == "crystal" ||
      str == "bar" ||
      str == "store" ||
      str == "toy store";
}

short() {
   return
      GRN+"Lazy Llew's Bar"+NORM+" is to the west.\n"+
      "A small blue crystal.\n"+
      "A Toy Store"
   ;

}

long(str) {
   if(str == "bar") {
      write("Lazy Llew's is a peaceful warm building made of logs.\n"+
         "Enter to be safe from attack and to rest and heal.\n");
   }
   if(str == "crystal") {
      write("Shimmering faintly, the small blue crystal looks chillingly cold.\n");
      write("Through the soft azure glow a darkness resides.  It grows within.\n");
      write("Still, the gem looks very valuable.\n");
   }
   if(str == "store" || str == "toy store") {
      write("The toy store stands before you inviting you in to have fun.\n");
      write("Enter the store to visit with some old friends.\n");
   }
}

reset(arg) {
   object quest;
   if(!present("toy_store",find_object("room/quest_room"))) {
      quest=clone_object("obj/quest_obj");
      quest->set_name("toy_store");
      quest->set_hint("Save the King of the Legopeople in the Toy Store.\n"+
         "Listen to what the policeman has to say.\n");
      move_object(quest,"room/quest_room");
   }
   if(arg) return;
   "/players/llew/closed/auto_ob"->start();
   move_object("/players/llew/junk/item_rock",DEST);
   move_object(this_object(), DEST);
}
init() {
   add_action("get","take");
   add_action("get","get");
   add_action("west","west");
   add_action("enter","enter");
}

get(str) {
   string junk,logstring;
   if(str != "crystal") return 0;
   write("You reach for the crystal, but light flashes, blinding you momentarily.\n");
   say("Blue light flashes, and "+this_player()->query_name()+" disappears.\n",this_player());
   this_player()->move_player("into the crystal#/players/llew/closed/crystal/crys.c");
   if(this_player()->query_level() < 8)
      write(BOLD+"Newbie"+NORM+":  This area is not for you.  Save yourself by typing out now!\n");
   return 1;
}

is_castle(){return 1;}

west() {
   this_player()->move_player("west#players/llew/Other/rooms/lazy");
   return 1;
}

enter(str) {
   string junk,logstring;
   if(str == "store" || str == "toy store") {
      this_player()->move_player("into the Toy Store#players/llew/Toys/rooms/entrance");
      return 1;
   }
   notify_fail("Enter what?\n");
}

level_color() {
   int lev;
   lev=this_player()->query_level();
   if(this_player()->query_extra_level())
      return HIR;
   if(lev > 15)
      return RED;
   if(lev > 10)
      return HIY;
   if(lev > 5) 
      return GRN;
   return "";
}
