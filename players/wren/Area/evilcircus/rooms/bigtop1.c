	/* bigtop1 */
	/*  */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Inside the Big Top";
   long_desc = 
" Big Top \n\
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
          "/players/wren/Area/evilcircus/rooms/entrance.c","out",
          "/players/wren/Area/evilcircus/rooms/bigtop2.c","east",
          "/players/wren/Area/evilcircus/rooms/bigtop3.c","southeast",
          "/players/wren/Area/evilcircus/rooms/bigtop4.c","south",
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
         }

  search_room()  {
        write(" \n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

  read_sign(str) {
      if(str != "sign") {
        write("Read what?\n");
        return 0;
                       }
      if(str == "sign") {
        write("                                                                  \n");
        say(this_player()->query_name() +" looks at the sign.\n");
        return 1;
                    }
              }   

  	/*      */
	/*      */
	/*      */
	/*      */
