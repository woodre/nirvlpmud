#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("tecnico3")) {
  move_object(clone_object("/players/francesco/univ/mob/tecnico3.c"),
	this_object());  }


set_light(1);

short_desc = "An office" ;
long_desc =
     "    One desk, one chair and one computer are the only items in this\n"+
    "booth.  At a first glance,  the computer doesnt look powerful, but the\n"+
    "more you look at it, you notice something special and decide to\n"+
    "investigate it deeper.  It might reveal far different.\n",

items = ({
   	"computer","A tag on the cabinet of this computer says:\n"+
		   "PROPERTY OF PARALLEL COMPUTING INC.  DO NOT OPEN",
        "desk","Simple wooden desk with just a computer on it",
        "chair","Leather chair, looks very confortable",

});

dest_dir = ({
   "/players/francesco/univ/rooms/dimec10.c","exit",

});

}
