#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("guard")) {
  move_object(clone_object("/players/francesco/univ/mob/guard.c"),
	this_object()); }
if (!present("student")) {
  move_object(clone_object("/players/francesco/univ/mob/student3.c"),
	this_object()); }
if (!present("student 2")) {
  move_object(clone_object("/players/francesco/univ/mob/student1.c"),
	this_object()); }

set_light(1);


short_desc = "A long corridor" ;
long_desc =
     "    This is a straight corridor, with doors on both sides that lead\n"+
     "to the classrooms.  The walls hold several announcements put there \n"+
     "by students searching for useful items to barter with each other.  \n"+
     "The side windows allow for enough light to enter and illuminate the\n"+
     "corridor.  Several students are going back and forth to their next\n"+
     "classes.  Sometimes you could also meet a guard, controlling the\n"+
     "students moves.\n",

items = ({
   "doors","The doors to the classroom are open and you already see\n"+
          "several students inside, getting ready with their notebooks.\n",
   "announcements","Paper sheets held on a self sticking panel",
   "windows","High almost until the ceiling, made by wooden frame, brown",
   "walls","White painted, likely very recently",
   "ceiling","Of a semi-circular shape, like the old roman archs",
});

dest_dir = ({
  "/players/francesco/univ/rooms/classroom.c","enter12",
  "/players/francesco/univ/rooms/classroom2.c","enter13",
  "/players/francesco/univ/rooms/main_entrance.c","west",  
  "/players/francesco/univ/rooms/corridor2.c","east",
});

}
