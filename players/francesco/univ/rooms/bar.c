#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("hope")) {
  move_object(clone_object("/players/francesco/univ/mob/bartender.c"),
	this_object()); }

if (!present("dispenser")) {
  move_object(clone_object("/players/francesco/univ/items/dispenser.c"),
	this_object());  }
set_light(1);


short_desc = "In Campus Cafeteria" ;
long_desc =
     "    The In Campus Cafeteria is mainly used by the professors and\n"+
     "the staff of the University during breaks from their job.  The \n"+
     "students also like to come here and gather in a relaxed atmosphere.\n"+
     "There arent many tables here to sit around, because the University\n"+
     "management tends to discourage people from lazing around instead\n"+
     "of working.  The bartender works behind the long counter, she is all \n"+
     "intent upon serving the people that usually come here and run away \n"+
     "very fast.  She also prepares her own specialties by getting the \n"+
     "ingredients from the shelf behind herself.  Beware, the bartender\n"+
     "does not work 24/7.\n",

items = ({
         "tables","Six wood tables aligned one after the other",
         "counter","A counter made by wood and shining brass, like in the old style Far West pubs",
         "shelf","Tall, wide shelf can hold dozens of bottles"
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor3.c","exit",

});

}
