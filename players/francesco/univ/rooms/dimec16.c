#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("master")) {
  move_object(clone_object("/players/francesco/univ/mob/master.c"),
	this_object());  }
if (!present("master 1")) {
  move_object(clone_object("/players/francesco/univ/mob/master.c"),
	this_object());  }

set_light(1);

short_desc = "Master students room" ;
long_desc =
     "   Not only desks are in this room.  As a matter of fact the master\n"+
     "students need also some equipment to perform their activities.\n"+
     "They are allowed to use the computer, the phone and the fax.\n",

items = ({
   "desks","They are cheap and resistant, made by hard plastics",
   "computer","A modern PC",
   "phone","Coloured in black, with handset on it",
   "fax","Ink jet fax, it can be also used as a copier, as a printer or as a scanner",
});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec15.c","east",
   
   
});

}
