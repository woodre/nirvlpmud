#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("rumba")) {
  move_object(clone_object("/players/francesco/univ/mob/rumba.c"),
	this_object());  }

set_light(1);

short_desc = "Chemical laboratory" ;
long_desc =
     "     The chemical lab is very clean and secluded and the admit is restricted\n"+
     "to authorized personnel only.  Several glass vials and beakers are seen here.\n"+
     "Some high metallic shelves are positioned against the walls and you bet they\n"+
     "contain all the chemicals needed in this lab.\n";

items = ({
   "vials","Glass vials used to prepare the reagents",
   "beakers","Containers used to make mixtures",
   "shelves","They are locked to avoid dangers",

});

dest_dir = ({

   "/players/francesco/univ/rooms/dimec5.c","up",

});

}
