#include "ansi.h"
#define NAME "Martha"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if (!present("terminal"))
      {
      move_object(clone_object("/players/dune/closed/guild/boards/guildboard.c"), this_object());
   }
   if(arg) return;
   
   set_long(
      "As you look around you see an organized jumble of board games and\n"+
      "their pieces.  You see directions to different games stacked on a\n"+
      "bookshelf in the corner of the room.  You see a silver glimmer out\n"+
      "of the corner of your eye and notice there are game pieces splayed\n"+
      "all over the floor.  A wall of televisions captures your attention\n"+
      "and you see that each is tuned into a different game show.  In the\n"+
      "center of the room is a large mahogany table that has many games in\n"+
      "various stages of play.  The air has a sweetness to it that reminds\n"+
      "you of years that have past and you can't help but smile.  A ray of\n"+
      "sunshine cuts through the window leaving a rainbow trail across the\n"+
      "wooden floor.  On the other wall you see a plush velvet couch upon\n"+
      "which many naps have been taken.");
   set_light(1);
   
   add_listen("main", "You hear laughter and game pieces clinking on the cardboard.");
   add_smell("main", "You smell candied apples, popcorn and soda.");
   items = ({
         "board games","A pile of your standard childhood games",
	 "games","A pile of your standard childhood games",
         "pieces","Various game pieces from different games",
	 "game pieces","Various game pieces from differnt games",
         "bookshelf","A large wooden structure with many games on it",
	 "shelf","A large wooden structure with many games on it",
         "glimmer","The silver pieces from the Monopoly game",
         "floor","A mess of game boards, pieces and cards",
         "wall","Rows upon rows of televisions tuned to various game shows",
	 "televisions","19 inch TV's tuned to various game shows",
	 "table","A beautiful mahogany table that has been polished",
	 "ray","A beautiful beam of sunshine",
	 "trail","Red, Orange, Green, Blue, Shiny Yellow, Purple too!",
	 "couch","A well worn couch that has been used over and over"});
}

init() {
   ::init();
   add_action("bring", "bring");
   add_action("church","church");
   add_action("post","post");
   add_action("green","green");
   add_action("ninja","ninja");
}

church(string str) {
   if (!str || str != "church"){
      notify_fail("Where would you like to go?\n");
      write("You skip out of the gameroom\n");
      say(this_player()->query_name()+" skips off to the church.\n");
      move_object(this_player(),"/room/church.c");
      command("look",this_player());
      return 1;}
}

post(string str) {
   if (!str || str != "post"){
      notify_fail("Where would you like to go?\n");
      write("You skip out of the gameroom\n");
      say(this_player()->query_name()+" skips off to the post office.\n");
      move_object(this_player(),"/room/post.c");
      command("look",this_player());
      return 1;}
}

green(string str) {
   if (!str || str != "green"){
      notify_fail("Where would you like to go?\n");
      write("You skip out of the gameroom\n");
      say(this_player()->query_name()+" skips off to the green.\n");
      move_object(this_player(),"/room/vill_green.c");
      command("look",this_player());
      return 1;}
}

ninja(string str) {
   if (!str || str != "bank"){
      notify_fail("Where would you like to go?\n");
      write("You skip out of the gameroom\n");
      say(this_player()->query_name()+" skips off to the Cyberninja Guildhall.\n");
      move_object(this_player(),"/players/dune/closed/guild/rooms/phase_hall.c");
      command("look",this_player());
      return 1;}
}


bring(str)  {
   object person;
   if(!str) {
      write("Usage: bring <living>\n");
      return 1;
   }
   person = find_living(str);
   if(!person) {
      write(str+" can not be found.\n");
      return 1;
   }
   tell_room(environment(person), 
      "A small scottie dog bounds into the room and nudges "+capitalize(str)+" off to\n"+
      "Martha's Gameroom.\n");
   tell_room(this_object(),
      "The scottie dog bounds into the room and gently places "+capitalize(str)+" in a gaming chair.\n");
   move_object(person,this_object());
   tell_object(person,"Do Not Pass Go, Do Not Collect $200...you are going to Martha's Gameroom.\n");
   return 1;
}
short() { int a; a = random(15);
   if (a==0) return ""+HIB+"Martha's Gameroom"+NORM+"";
   if (a==1) return ""+HIM+"Martha's Gameroom"+NORM+"";
   if (a==2) return ""+HIW+"Martha's Gameroom"+NORM+"";
   if (a==3) return ""+HIY+"Martha's Gameroom"+NORM+"";
   if (a==4) return ""+HIG+"Martha's Gameroom"+NORM+"";
   if (a==5) return ""+HIR+"Martha's Gameroom"+NORM+"";
   if (a==7) return ""+RED+"Martha's Gameroom"+NORM+"";
   if (a==8) return ""+GRN+"Martha's Gameroom"+NORM+"";
   if (a==9) return ""+YEL+"Martha's Gameroom"+NORM+"";
   if (a==10) return ""+BLU+"Martha's Gameroom"+NORM+"";
   if (a==11) return ""+MAG+"Martha's Gameroom"+NORM+"";
   if (a==12) return ""+CYN+"Martha's Gameroom"+NORM+"";
   if (a==13) return ""+WHT+"Martha's Gameroom"+NORM+"";
   if (a==14) return "A jumble of board games";
   if (a==6) return "An instruction pamphlet";
}
