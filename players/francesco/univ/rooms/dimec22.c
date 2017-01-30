#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("dean")) {
  move_object(clone_object("/players/francesco/univ/mob/dean.c"),
	this_object());  }


set_light(1);

short_desc = "An office" ;
long_desc =
     "   The office of the Dean of the Department of Mechanical\n Engineering\n"+
     "is relatively empty and not well ornated.  This is due to the fact\n"+
     "that the dean position is a temporary one and therefore all the previous\n"+
     "deans did not care very much about the furniture of this room.  There \n"+
     "are also plaques on the side walls,\n";
items = ({
   "furniture","Just a plain desk, some chairs and shelfs",
   "desk","A brown desk, like it was made by wood",
   "chairs","Black office chairs, made by metal frame and soft upholstery, very ergonomic",
   "shelfs","Metallic shelfs, they hold some books",
   "books","Not only engineering books, but also concerning the business administration",
   "plaques","They report the prizes won by departmental staff in Conferences or Meetings\n",
});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec18.c","southeast",

});

}
