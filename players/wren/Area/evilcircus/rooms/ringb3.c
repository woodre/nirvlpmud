	/*  */
	/*  */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Second Ring";
   long_desc = 
"Ring B 3  \n\
   \n\
   \n\
   \n\
   \n\
   \n\
   \n";

      items=({		/*Remember two deep on noun descriptions*/
          "tear","",
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
          "","",
          "",""
             });

        
      dest_dir = ({
          "/players/wren/Area/evilcircus/rooms/ringb1.c","northwest",
          "/players/wren/Area/evilcircus/rooms/ringb2.c","west",
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
    add_action("sneak_tear","enter");
            }

  search_room()  {
        write("You notice a tear in the tent you could enter \n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

   sneak_tear(str) {
      if(str != "tear") {write("Enter what?\n"); return 0; }
      if(str == "tear") {
             write("Carefully parting the impromtu flaps you exit the tent.\n");
             say(this_player()->query_name() + "sneaks out of the tent. \n");
             this_player()->move_player("out of the tent#players/wren/Area/evilcircus/rooms/back.c");
             return 1;
           }
         }

  	/*      */
	/*      */
	/*      */
	/*      */
