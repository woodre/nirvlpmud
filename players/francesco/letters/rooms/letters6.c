#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("prof")) {
  move_object(clone_object("/players/francesco/letters/mobs/prof.c"),
	this_object()); }

set_light(1);

short_desc = "An office" ;
long_desc =
     "   This is the typical office of a University professor.  There \n"+
     "are an ample working desk and a wide meeting table.  Some leather \n"+
     "chairs surround the table.  Behind the desk, a business chair with\n"+
     "a high back.  A plaque is hanging on the wall behind the desk.\n",
items = ({
   "chairs","Very sophisticated chairs made with handcrafted wood",
   "table","A table that can hold up to 12 people for scientific meetings",
   "desk","A perfectly maintained desk with few items on it:\n"+
          "a notebook, a penholder and a couple of books",
   "plaque","                  Presented to\n"+
            "           Prof. Giovanbattista DeRossi\n"+
            "  For his outstanding contribution to the organization\n"+
            "                      of the\n"+ 
            "   First World Conference on Automatized Translation",
   "chair","The business chair is all made with leather",
   "notebook","It is held within a leather cover",
   "penholder","It is made with a blue china",
   "books","Hard to say their content, unless after opening them",
   "wall","White painted and perfectly maintained",
    });
 
dest_dir = ({
  "/players/francesco/letters/rooms/letters5.c","east",
});

}



