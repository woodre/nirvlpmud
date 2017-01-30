#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("pilot")) {
  move_object(clone_object("/players/francesco/2001/mobs/pilot1.c"),
	this_object());  }

set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "The cockpit of the spacecraft is a small and uncomfortable room.  Only\n"+
     "one chair in front of a console desk.  One main wheeldrive and some \n"+
     "leverages to drive the spacecraft, mainly at take off and at landing.\n"+
     "From the window it is possible to see the Moon approaching.\n",

items = ({
   "desk","It is a metallic console about 2 feet tall and 3 feet wide",
   "monitors", "They have modern 15 inch, LCD screens",
   "chair","It has also security belts",
   "leverages","Small poles emerging from the desk",
   "wheeldrive","Only the most skilled pilots can use it properly.\n"+
                "They use it to 'land moon'",
   "window","It almost surrounds the pilot for the whole horizon",
   "moon","Being so close to the satellite of the Earth it is now possible\n"+
          "to see some details invisible for afar",
   "details","Rocks, canyons and plains on the surface of the Moon",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space8.c","southeast",
  "/players/francesco/2001/rooms/space7.c","southwest",
});

}

init(){
      ::init();
      add_action("land","land");
      }

land(str) 
  {
  if(!str) {write("Land where?\n"); return 1;}
  if(str!="moon") {write("Land where?\n"); return 1; }
  write("The pilot controls very well the descend of the spacecraft on\n"+
        "the surface of the Moon.  You then exit the spacecraft.\n");
  this_player()->move_player("to the Clavius Base#players/francesco/2001/rooms/moon1.c");
  return 1;
  }

