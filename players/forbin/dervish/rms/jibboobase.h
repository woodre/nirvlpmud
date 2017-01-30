/* 
 * Forbin
 * Created:   2003.08.20
 * Last edit: 2003.11.11 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * Base desert inherit to make random room descriptions:
 *   -This controls the long descriptions, items, chats,
 *    listens, smells, touches, exit messages, and includes
 *    the random movement code for the Jibboo Desert
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int D;

create_random_room() {
  int slope;
  string slopedir;
  slope = random(8);
  switch(slope) {
    case 0: slopedir = "north"; break;
    case 1: slopedir = "northeast"; break;
    case 2: slopedir = "east"; break;
    case 3: slopedir = "southeast"; break;
    case 4: slopedir = "south"; break;
    case 5: slopedir = "soutwest"; break;
    case 6: slopedir = "west"; break;
    case 7: slopedir = "northwest"; break;
  }
  switch(random(4)) {
    case 0:
      long_desc = HIY+BYEL+
        "  The desert sands slowly rise above you in all directions, and\n"+ 
        "the many sand dunes tower high into the air.  Carved by winds, \n"+
        "several places bear trails and waves that snake their paths    \n"+
        "across the smooth surface of the sand.                         \n"+
        "    You could travel in any of the compass directions.         \n"+NORM;
      add_item("desert","The desert stretches off into the horizon in all directions");
      add_item(({"sand","sands"}),"Grainy, dark sand covers everything here");
      add_item(({"dune","dunes","sand dune","sand dunes"}),
                   "Large hills of sand dot the landscape of the desert");
      add_item(({"trail","trails","wave","waves","path","paths"}),
                   "Small patterns made by the desert winds have been formed in the sand");
      set_chance(random(5));
        add_msg("The scorching sun beats down upon you.");
        add_msg("Sweat runs down your face, stinging your eyes.");
        add_msg("Wind whistles past you, scouring your face with sand.");
        add_msg("A dust devil blows through, stirring up the settled sand.");
        add_msg("You look up and the gleeming sun burns your eyes.");
      add_listen("main", "You listen closely, but hear nothing but the wind.\n");
        add_listen("wind", "The wind whistles through the air.\n");
      add_smell("main", "You sniff the air and get a nose-full of dirt.\n"); 
        add_touch("sand", "You burn your hand on the scalding hot sand.\n");
        add_touch("sands", "You burn your hand on the scalding hot sand.\n");
        add_touch("dune", "The sand is scalding to the touch.\n");
        add_touch("dunes", "The sand is scalding to the touch.\n");
        add_touch("trail", "You follow the outline of a trail, tracing its path in the sand");
        add_touch("trails", "You follow the outline of a trail, tracing its path in the sand");
        add_touch("path", "You follow the outline of a path, tracing its trail in the sand");
        add_touch("paths", "You follow the outline of a path, tracing its trail in the sand");
        add_touch("wave", "You follow the outline of a wave, tracing its path in the sand");
        add_touch("waves", "You follow the outline of a wave, tracing its path in the sand");
      add_exit_msg("north", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("northeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("east", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("southeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("south", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("southwest", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("west", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("northwest", "You trudge off across the desert...\n",
	                            "trudges off across the desert.\n");
      break;
    case 1:
      long_desc = HIY+BYEL+
        "  Standing atop a high sand dune, the desert creeps outwards into\n"+
        "the distance.  The harsh light from an intense sun causes one to \n"+
        "squint their eyes, and as far as one can see, there is nothing   \n"+
        "but sand.  High in the sky off towards the horizon, you can make \n"+
        "out the fluttering forms of things you suppose are birds.        \n"+
        "    You could travel in any of the compass directions.           \n"+NORM;
      add_item(({"desert","sand"}),"The desert covers everything in an ocean of sand");
      add_item(({"dune","sand dune","high dune","high sand dune"}),
                   "You stand at the peak of a tall sand dune.  It dominates its surrounding in height");
      add_item("distance","Far away, you see no end to the desert");
      add_item(({"sky","horizon","forms","fluttering forms","form","fluttering form",
                 "bird","birds"}),"Towards the horizon you watch as dark shadows circle slowly in the air");
      set_chance(random(5));
        add_msg("The scorching sun beats down upon you.");
        add_msg("Sweat runs down your face, stinging your eyes.");
        add_msg("Wind whistles past you, scouring your face with sand.");
        add_msg("A dust devil blows through, stirring up the settled sand.");
        add_msg("You look up and the gleeming sun burns your eyes.");
      add_listen("main", "Far in the distance you hear the sqwaking of birds.\n");
        add_listen("bird", "You can hear shrill chirps and sqawks from the birds.\n");
        add_listen("birds", "You can hear shrill chirps and sqawks from the birds.\n");
      add_smell("main", "You sniff the air and get a nose-full of dirt.\n"); 
        add_touch("sand", "You burn your hand on the scalding hot sand.\n");
        add_touch("sands", "You burn your hand on the scalding hot sand.\n");
        add_touch("dune", "The sand is scalding to the touch.\n");
        add_touch("dunes", "The sand is scalding to the touch.\n");
      add_exit_msg("north", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("northeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("east", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("southeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("south", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("southwest", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("west", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("northwest", "You trudge off across the desert...\n",
	                            "trudges off across the desert.\n");
      break;
    case 2:
      long_desc = HIY+BYEL+
        "  A sandstorm rages all around you.  Here the rolling hills of \n"+
        "sand ripple outward hunging the contours of the ground beneath.\n"+
        "Winds scour the landscape, kicking up particles of sand and    \n"+
        "assaulting you with them.  This place is sandy quicksilver; the\n"+
        "sands churn and move constantly with the hard wind that blows. \n"+
        "    You could travel in any of the compass directions.         \n"+NORM;
      add_item(({"storm","sandstorm"}),"A sandstorm churns about you");
      add_item(({"sand","sands"}),"The wind picks sand up from the ground and carries it around");
      add_item(({"particle","particles"}),"Particles of sand drift about in the wind");
      add_item(({"ground","landscape","desert"}),"You cannot make out much while in this storm");
      add_item(({"hill","hills"}),"You can see the outlines of a few hills, but not much more");
      set_chance(random(5));
        add_msg("The winds beat against you.");
        add_msg("Sand scrapes at your skin.");
        add_msg("Flecks of sand dig into you, drawing blood.");
        add_msg("Wind whistles past you, scouring your face with sand.");
      add_listen("main", "You are deafened by the roar of the storm.\n");
        add_listen("storm", "The wind rages - your ears are ready to burst.\n");
        add_listen("sandstorm", "The wind rages - your ears are ready to burst.\n");
      add_smell("main", "You sniff the air and get a nose-full of dirt.\n"); 
      add_exit_msg("north", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("northeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("east", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("southeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("south", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("southwest", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("west", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("northwest", "You trudge off across the desert...\n",
	                            "trudges off across the desert.\n");
      break;
    case 3: 
      if(slopedir == "north" || slopedir == "south") {
        long_desc = HIY+BYEL+
          "  Sand stretches off in all directions.  The ground slopes to \n"+
          "the "+slopedir+", then falls off sharply down a sand covered incline.\n"+  
          "Sand looks to have slid down this "+slopedir+"ern slope and is piled \n"+ 
          "towards the bottom in a lump.  Black shadows are cast here and\n"+ 
          "there by the high dunes that surround the area.               \n"+
          "    You could travel in any of the compass directions.        \n"+NORM;        
      }
      if(slopedir == "east" || slopedir == "west") {
        long_desc = HIY+BYEL+
          "  Sand stretches off in all directions.  The ground slopes to \n"+
          "the "+slopedir+", then falls off sharply down a sand covered incline. \n"+  
          "Sand looks to have slid down this "+slopedir+"ern slope and is piled  \n"+ 
          "towards the bottom in a lump.  Black shadows are cast here and\n"+ 
          "there by the high dunes that surround the area.               \n"+
          "    You could travel in any of the compass directions.        \n"+NORM;        
      }
      else {
        long_desc = HIY+BYEL+
          "  Sand stretches off in all directions.  The ground slopes to the\n"+
          ""+slopedir+", then falls off sharply down a sand covered incline.   \n"+  
          "Sand looks to have slid down this "+slopedir+"ern slope and is piled\n"+ 
          "towards the bottom in a lump.  Black shadows are cast here and   \n"+ 
          "there by the high dunes that surround the area.                  \n"+
          "    You could travel in any of the compass directions.           \n"+NORM;        
      }      
      add_item(({"sand","ground"}),"Desert sands paint everything here in a dark brown");
      add_item(({"slope","incline"}),"The ground sharply dips down an incline several feet from you");
      add_item(({"pile","lump"}),"The ever moving sands have formed a pile at the bottom of the slope");
      add_item(({"shadow","shadows"}),"The bright sun and the high dunes make shadows that cover small areas");
      add_item(({"dune","dunes"}),"High piles of sand form dunes surrounding much of this place");
      add_item("area","The area down below is bathed in shadows");     
      set_chance(random(5));
        add_msg("The scorching sun beats down upon you.");
        add_msg("Sweat runs down your face, stinging your eyes.");
        add_msg("Wind whistles past you, scouring your face with sand.");
        add_msg("A dust devil blows through, stirring up the settled sand.");
        add_msg("You look up and the gleeming sun burns your eyes.");
      add_listen("main", "You listen closely, but hear nothing but the wind.\n");
        add_listen("wind", "The wind whistles through the air.\n");
      add_smell("main", "You sniff the air and get a nose-full of dirt.\n"); 
        add_touch("sand", "You burn your hand on the scalding hot sand.\n");
        add_touch("sands", "You burn your hand on the scalding hot sand.\n");
        add_touch("dune", "The sand is scalding to the touch.\n");
        add_touch("dunes", "The sand is scalding to the touch.\n");
      add_exit_msg("north", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("northeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("east", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("southeast", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("south", "You trudge off across the desert...\n",
		                    "trudges off across the desert.\n");
      add_exit_msg("southwest", "You trudge off across the desert...\n",
		                        "trudges off across the desert.\n");
      add_exit_msg("west", "You trudge off across the desert...\n",
		                   "trudges off across the desert.\n");
      add_exit_msg("northwest", "You trudge off across the desert...\n",
	                            "trudges off across the desert.\n");
      break;
  }
}

check_random_move() {  /* Random move is based on devotion to Sands */ 
/* commented out till I get it working -forbin  
  int sandy;
  sandy = present("dervish_tattoo", previous_object())->query_sand_points();
  if(sandy < 33333) { if(random(100) < 70) random_move(); }
  if(sandy > 33332 && sandy < 66666) { if(random(100) < 45) random_move(); }
  if(sandy > 66665 && sandy < 99999) { if(random(100) < 35) random_move(); }
  if(sandy > 99998) { if(random(100) < 20) random_move(); }
*/
  if(!random(3)) random_move();
}

random_move() {
  D = random(26);
  if(D == 0) { D = 1; }
  if(D == 14) {  /* <------------ Checks to insure player does not go to main */                            
    if(!random(2)) { D += 1+random(5); } /* quest room by the random movement */
    else D -= 1+random(5);
  }
  if(D < 10) { 
    tell_room(environment(this_player()), 
      this_player()->query_name()+" trudges off across the desert.\n", ({ this_player() }));
    tell_object(this_player(), "You trudge off across the desert...\n");
    move_object(this_player(),ROOT+"rms/jibboo0"+D+".c");
    command("look",TP);
      return 1;
  }
  else if(D > 9) {
    tell_room(environment(this_player()),
      this_player()->query_name()+" trudges off across the desert.\n", ({ this_player() }));
    tell_object(this_player(), "You trudge off across the desert...\n");
    move_object(this_player(),ROOT+"rms/jibboo"+D+".c");
    command("look",TP);
      return 1;
  }
}