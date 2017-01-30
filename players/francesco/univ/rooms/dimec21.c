#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("fullprof")) {
  move_object(clone_object("/players/francesco/univ/mob/fullprof.c"),
	this_object());  }

set_light(1);

short_desc = "An office" ;
long_desc =
     "   The best furniture you have ever seen in this Department are\n"+
     "present in this room:  leather chairs,  an ample working desk and \n"+
     "a wide meeting table look all handcrafted by the best skilled wood\n"+
     "workers.  A plaque is on the wall behind the desk.\n",
items = ({
   "chairs","Very sophisticated chairs made with handcrafted wood",
   "table","A table that can hold up to 12 people for scientific meetings",
   "desk","A perfectly maintained desk with few items on it:\n"+
          "a notebook, a penholder and a couple of books",
   "plaque","                  Presented to\n"+
            "   Prof. Sashangicatsanga Bhranopaardiamontry\n"+
            "  MOST Professor of  Manufacturing Engineering\n"+
            "                     by the\n"+ 
            "Machining Organization for Science and Technology",
   
 });
 
dest_dir = ({
  "/players/francesco/univ/rooms/dimec18.c","southwest",
});

}
