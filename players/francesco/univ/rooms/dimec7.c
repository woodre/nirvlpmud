#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("tecnico")) {
  move_object(clone_object("/players/francesco/univ/mob/tecnico2.c"),
	this_object());  }

if (!present("tecnico 2")) {
  move_object(clone_object("/players/francesco/univ/mob/volontario.c"),
	this_object());  }

set_light(1);

short_desc = "Dynamic tests laboratory" ;
long_desc =
     "     The instrumentations present in this lab are very modern and\n"+
     "sophisticated.  Yet, the one which mostly grabs your attention is\n"+
     "a simple gun positioned onto a holder, in front of a wall, about 20\n"+
     "feet away from it.\n";

items = ({
   "holder","This three-legs holder allows for a very stable positioning",
   "gun","The gun is onto the holder and points to the wall",
   "wall","A schematized shape of a man is depicted on the wall",

});

dest_dir = ({

   "/players/francesco/univ/rooms/dimec5.c","east",

});

}
