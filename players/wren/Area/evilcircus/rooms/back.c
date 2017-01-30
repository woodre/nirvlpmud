	/* Back entrance to Circus*/
	/* Hidden entrance made as Aboth entered */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Behind the scenes";
   long_desc = 
"Wagons, carts, and pens are set up around the rear of the massive tents. \n\
Nobody seems to be around with the show in full swing. The cheering crowd \n\
can be heard from within the Big top. The air is full of strong odors. \n\
Something seems out of place in this quiet corner though.\n\
   \n";

      items=({		/*Remember two deep on noun descriptions*/
          "tear","Somebody carefully slit the back of a tent to enter secretly",
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
          "/players/wren/Area/evilcircus/rooms/entrance.c","around",
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
        write("Boot prints lead to a tear in the tent worth investigating. \n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

  sneak_tear(str) {
      if(str != "tear") {
            write("Enter what?\n"); 
            return 0; 
                 }
      if(str == "tear") {
             write("Carefully parting the impromtu flaps you dive into the tent.\n");
             say(this_player()->query_name() + "sneaks into the tent. \n");
             this_player()->move_player("into the tent#players/wren/Area/evilcircus/rooms/ringb3.c");
             return 1;
           }
         }


  	/*      */
	/*      */
	/*      */
	/*      */
