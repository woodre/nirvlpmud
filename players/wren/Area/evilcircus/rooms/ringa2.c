	/*  */
	/*  */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "First Ring";
   long_desc = 
"Ring A 2  \n\
   \n\
   \n\
   \n\
   \n\
   \n\
   \n";

      items=({		/*Remember two deep on noun descriptions*/
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
          "","",
          "",""
             });

        
      dest_dir = ({
          "/players/wren/Area/evilcircus/rooms/ringa1.c","northeast",
          "/players/wren/Area/evilcircus/rooms/ringa3.c","east",
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
         }

  search_room()  {
        write(" \n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

 
  	/*      */
	/*      */
	/*      */
	/*      */
