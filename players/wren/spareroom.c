	/* Spare workroom for monster testing and player confinement possibly. */
	/* Mostly for testing stuff out of the way of accidental wanderings. */

#include "/players/wren/ansi.h"; 
inherit "room/room";
int searched;

reset(arg)  {
   if(arg) 
      return ;
/*
   if(!present("monster_name")) {
      move_object(clone_object("/players/wren/Area/   .c"),this_object()); }
*/
   set_light(1);
   short_desc = "Oubliette";
   long_desc = 
"Darkness prevails in this damp stone cell. The only light coming from \n\
a blue sphere hanging motionless above. Dark stains are visible in the \n\
pale light indicating that previous occupants may not have left whole. \n";

      items=({		/*Remember two deep on noun descriptions*/
          "stone","A dark basalt slick with moisture",
	  "light","Pale azure illumination from the magic sphere",
	  "stains","Dark splats of red and green on the walls and floors",
	  "stain","Whatever icor this was it is now only coloring the stones",
	  "sphere","Mystic device providing illumination",
	  "red","Almost black in hue this red may have once been blood",
	  "green","Some sort of hearty moss that requires little light",
          "moss","Simple plant life clinging to the stone walls"
             });

/*        
      dest_dir = ({
          "/players/wren/Area/ "," ",
          "/players/wren/Area/ "," " 
                 }); 
*/ 
searched = 1;   
}

  init() {
    ::init();
    add_action("search_room","search");
          }

  search_room()  {
      if(searched == 0) {
        write("You search through the clutter and a couple things hold your attention\n");
        say (this_player()->query_name() +" searches the area. \n");
        move_object(clone_object("/players/wren/Area/  .c"),this_object());
        searched = 1;
        return 1;
                        }
      else {
        write("You search the clutter but find nothing clean enough to keep.\n");
        say(this_player()->query_name() +" searches the area. \n");
        return 1;            
           }
     }
