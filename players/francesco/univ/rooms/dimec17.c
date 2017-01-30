#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("phd")) {
  move_object(clone_object("/players/francesco/univ/mob/phd.c"),
	this_object());  }
if (!present("phd")) {
  move_object(clone_object("/players/francesco/univ/mob/phd.c"),
	this_object());  }

set_light(1);

short_desc = "PhD students room" ;
long_desc =
      "   Some chaos is present in this large room.  Matter of fact,\n"+
      "the desks are full of papers, books and several printouts.  The \n"+
      "Mechanical Enineering PhD students have to do research,  they tutor\n"+
      "younger colleagues and they even give some lectures at both master\n"+
      "and bachelor levels.  They continuosly run in and out of this room, \n"+
      "to computer labs, to mechanical labs, to testing labs or to their\n"+
      "professor rooms.\n",

items = ({
   "desks","Large desks to ease the working on them.",
   "papers","Reprints from scientific Journals that the PhD students must continuosly study",
   "books","Most of them are relative to engineering subjects",
   "printouts","Fan-fold papers coming by tractor printers, likely the outputs\n"+
               "of some computer simulations",


});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec15.c","west",
   
   
});

}
