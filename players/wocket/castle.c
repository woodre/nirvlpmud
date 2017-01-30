inherit "/obj/treasure";
/*
* This is just the facade to a castle. If you want to enable the
* "enter" command, move the player to a hall or something (which
   * you have to design yourself).
* The predefined string DEST is where a player should come when he
* leaves the castle.
*
* This file is loaded automatically from "init_file". We have to move
* ourself to where we are supposed to be.
*/


#if 0 /* Rumplemintz */
#include "/players/wocket/closed/ansi.h"
#else
#include <ansi.h>
#endif
#define NAME "Wocket"
#define DEST "room/south/sforst45"


object qob;
reset(arg) {
   if (arg)
      return;
   set_no_clean(1);
   set_id("object");
   set_short("An object covered with overgrowth");
   set_long("A stone object.  It has been hidden by vines and bushes that have\n"+
      "been growing over the years.  You might think about 'uncover'ing the \n"+
      "the object.\n");
   set_weight(2147483647);
   move_object(this_object(), DEST);
   /* Autoloads */
   clone_object("/players/wocket/mages/mageautoload.c");
   clone_object("/players/wocket/wedding/ring.c");
/*
   clone_object("/players/wocket/junk/quill.c");
   clone_object("/players/wocket/junk/w_silence.c");
*/
/* Don't do this, it's moved to guilds dir - Rumplemintz
  clone_object("/players/wocket/necro/guildob.c");
*/
   
   /* Quest Objects */
   if(!present("sinja_quest",find_object("room/quest_room.c"))){
      qob = clone_object("obj/quest_obj");
      call_other(qob,"set_name","sinja_quest");
      call_other(qob,"set_hint","The mayor of Turtleville needs your help.  Go to him and ask what the\ntrouble is.\n");
      move_object(qob,"room/quest_room");
    }

/*Not open yet -wocket
    if(!present("euka_quest",find_object("room/quest_room.c"))){
      qob = clone_object("obj/quest_obj");
      call_other(qob,"set_name","euka_quest");
      call_other("qob,"set_hint","Listen to the gossip of Turtleville.  News travels fast.\n");
      move_object(qob,"room/quest_room");
    }
*/
}

is_castle(){ return 1;}

get(){ return 0; }



init(){
   add_action("uncover","uncover");
   if(short() == "A statue of an angel"){
      add_action("ask","ask");
      add_action("touch","touch");
      add_action("sread","read");
      add_action("explain","explain");
   }
}


int uncover(string str){
   if(str = "object"){
      set_id("statue");
      set_alias("angel");
      set_short("A statue of an angel");
      set_long("Here stands a beautifully carved statue of an angel.  Her wings are spread.\n"+
         "Her left arm is raised holding a wooden bow to the sky, while her right\n"+
         "carries a glowing orb of swirling colored rays.  She almost seems alive.\n"+
         "There is a small inscription at the base you may wish to 'read'.\n");
      write("You uncover the object to reveal a statue.\n");
      say(this_player()->query_name()+" uncovers the object to reveal a statue.\n");
      init();
      return 1;
   }
   notify_fail("What would you like to uncover?\n");
   return 0;
}


int sread(string str){
   if(!str || str != "inscription"){
      notify_fail("What would you like to read?\n");
      return 0;
   }
   write("The inscription reads:\n\n"+
      "\tYou might want to 'ask angel about' the following things:\n"+
      HIR+"\t\t\tthe mushroom grove\n"+NORM+
      HIB+"\t\t\tthe dryant graveyard\n"+NORM+
      HIG+"\t\t\tturtleville\n"+NORM+
      HIM+"\t\t\tthe dark caverns\n"+NORM+
      HIY+"\t\t\tthe glowing orb\n"+NORM+
      "\nYou might wish to have the angel 'explain' more about certain topics.\n"+
      "\n");
   return 1;
}


int touch(string str){
   int x;
   int cost;
   if(!str || str != "orb"){
      notify_fail("What would you like to touch?\n");
      return 0;
   }
   if(str == "orb"){
      /* To Disable the orb set x to 1 */
      x = 1;
      if(x == 1){
         write("The orb has been removed till further notice.\n");
         write("                                 -wocket\n");
         return 1;
      }
      if(this_player()->query_hp() <101 || this_player()->query_spell_point() < 100){
         notify_fail("You lack enough essence to touch the orb.\n");
         return 0;
      }
      cost = 3000+random(2000);
      if(this_player()->query_money() < cost){
         notify_fail("You lack enough money to create a duplicate orb.\n");
         return 0;
      }
      if(present("aglowingorb",this_player())){
         notify_fail("You are already one with the orb.\n");
         return 0;
      }
      write("With the orb's heat you begin to melt some coins down.  As you place\n"+
         "the molten gold upon the orb, energy rips through your soul, stealing\n"+
         "essense.\n");
      write("Your forge a duplicate orb.\n"+HIY+"It glows with power.\n"+OFF);
      say(this_player()->query_name()+" touches the orb.\n");
      say(this_player()->query_name()+" looks weaker.\n");
      this_player()->heal_self(-100);
      this_player()->add_money(-cost);
      move_object(clone_object("/players/wocket/std/orb.c"),this_player());
      return 1;
   }
}

int explain(string str){
   if(!str){
      write("Usage: explain <topic>\n");
      return 1;
   }
   if(str == "the mushroom grove"){
      write(""+
         "The statue begins to move.\n"+
         "\nThe Angel says:  The mushroom grove is a very mystical place.  It is home\n"+
         "to the Nonge, which is a strong, bipedal, cat-like race.\n"+
         "Their society is very primitive having a High priest to lead them,\n"+
         "but their unity is strong and way of life content.\n"+
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
   if(str == "the dryant graveyard"){
      write(""+
         "The statue begins to move.\n\n"+
         "The Angel says:  Long ago there was a great war between giant creatures.\n"+
         "An entire race was lost, that of the dryants.  They were very proud\n"+
         "and stubborn at times, so as the last one died he prayed to his\n"+
         "diety to recreate their once flourishing race.  They diety was cruel in his\n"+
         "hatred of the war so he resurrected the dryants only to trap them in the\n"+
         "graveyard to wander mindlessly.  There they have stayed, but be warned,\n"+
         "they are still very strong and very aggressive.  Standing 9 feet tall with\n"+
         "pale eyes, they are determined in their conquest.\n"+
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
   if(str == "turtleville"){
      write(""+
         "The statue begins to move.\n\n"+
         "The Angel says:  Turtleville was a city built long ago upon the marshes surrounding\n"+
         "the area.  Turtles thrived there so the settlers received many resources from\n"+
         "them.  Even today, turtles are still a major part of the economy.  The town has\n"+
         "however calmed down from its once hectic lifestyle.  It lies just west of the\n"+
         "mushroom grove.\n"+
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
   if(str == "the dark caverns"){
      write(""+
         "The statue begins to move.\n\n"+
         "The Angel says:  Long ago there was a fight between the Nonge\n"+
         "which seperated a clan.  They fell deep with in the land.  Many\n"+
         "of these Nonge took to practicing arcane magic as an attempt to\n"+
         "survive in such a hostile environment.  Through the centuries they\n"+
         "have conquer both the use of magic and the dark caverns.\n"+
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
   if(str == "the glowing orb"){
      write(""+
         "The statue begins to move.\n\n"+
         "The Angel says:  This is a powerful orb that allows passage to\n"+
         "a many energy gates.  If you choose to touch the orb you will become\n"+
         "one with its own energy, and as such some of your essence will be\n"+
         "removed.\n"+
         
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
   notify_fail("What would you like the angel to explain?\n");
   return 0;
}


int ask(string str){
   if(str != "angel about the mushroom grove" && str != "angel about the glowing orb" && str != "angel about the dryant graveyard" &&
         str != "angel about turtleville" && str != "angel about the dark caverns"){
      notify_fail("What would you like to ask?\n");
      return 0;
   }
   if(str == "angel about the mushroom grove" || str == "angel about turtleville"){
      write("You think you see the angel begin to move.\nA path to the west opens up revealing a trail.\n");
      say("A path to the west opens up revealing a trail.\n");
      move_object(clone_object("/players/wocket/mushrooms/opening.c"),environment(this_object()));
      return 1;
   }
   if(str == "angel about the dryant graveyard"){
      write("You think you see the angel begin to move.\nA path to the southwest opens up revealing a trail.\n");
      say("A path to the southwest opens up revealing a trail.\n");
      move_object(clone_object("/players/wocket/graveyard/opening.c"),environment(this_object()));
      return 1;
   }
   if(str == "angel about the dark caverns"){
      write("You think you see the angel begin to move.\nA hole opens up revealing a tunnel downwards.\n");
      say("A hole opens up revealing a tunnel downwards.\n");
    move_object(clone_object("/players/wocket/caves/NEWCAVES/opening.c"),environment(this_object()));
      return 1;
   }
   if(str == "angel about the glowing orb"){
      write(""+
         "The statue begins to move.\n\n"+
         "The Angel says: You need only touch the orb.\n"+
         "\nThe statue hardens and all is quiet.\n");
      return 1;
   }
}
