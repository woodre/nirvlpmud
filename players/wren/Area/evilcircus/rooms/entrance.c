	/* Circus Entrance*/
	/* Barker is here, search reveals prints leading to back entrance */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
/*
   if(!present("monster_name")) {
      move_object(clone_object("/players/wren/Area/   .c"),this_object()); } 
*/
   set_light(1);
   short_desc = ""+HIR+"Circus Gate"+NORM+"";
   long_desc = 
"A massive free-standing iron archway looms over the heads of the patrons \n\
entering the circus. Children dart around next to their parents while waiting \n\
to purchase their tickets. Bright red and gold paint adorns the barkers stand \n\
before the main entrance to the Big top. Flashy balloons float above short    \n\
ribbon tethers drawing further attention to the door. Creatures from all over \n\
creation have come to be entertained at the circus. A small sign is staked  \n\
near where you first came into this clearing. \n";

      items=({		/*Remember two deep on noun descriptions*/
          "sign","A small sign worth 'read'ing",
	  "prints","Boot prints leading behind the tents, maybe you too could 'sneak behind'",
          "","",
	  "","",
	  "","",
	  "","",
	  "","",
	  "","",
          "","",
          "","",
          "","",
          "","",
          "","",
          "",""
             });

        
      dest_dir = ({
          "/players/wren/Area/evilcircus/rooms/bigtop1","enter",
          "/players/wren/Area/entrance","leave", 
                 }); 
 
set_chance(5);       
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");

add_listen("main"," ");
add_listen(" "," ");
add_listen(" "," ");

add_smell("main"," ");
add_smell(" "," ");
add_smell(" "," ");

add_touch(" "," ");

add_exit_msg("dir","message to mover\n",
                    "movement seen by others\n");
}

  init() {
    ::init();
    add_action("search_room","search");
    add_action("read_sign","read");
    add_action("sneak_around","sneak");
         }

  search_room(str)  {
        write("You notice some faint prints leading around the outside of the tents.\n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

  read_sign(str) {
      if(str != "sign") {
        write("Read what?\n");
        return 0;
                       }
      if(str == "sign") {
        write("This Circus is extremely dangerous. Many have disappeared mysteriously around it. \n\
               Many others have been greviously wounded without a healer nearby to remedy. \n\
               You have been warned.   --Aboth the Avenger \n");
        say(this_player()->query_name() +" looks at the sign.\n");
        return 1;
                    }
              }   

  sneak_around(str) {
      if(str != "behind") {write("Sneak where?\n"); return 0; }
      if(str == "behind") {
             write("You make sure you aren't observed and slip around behind the tents.\n");
             say(this_player()->query_name() + "slips out of sight. \n");
             this_player()->move_player("behind the scenes#players/wren/Area/evilcircus/rooms/back.c");
             return 1;
           }
         }


  	/* Barker is here with hellhounds as backup   */
	/*      */
	/*      */
	/*      */
