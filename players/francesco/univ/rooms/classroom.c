


#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int DOOR;

reset(arg) {
  if(arg) return;

if (!present("student")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 2")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 3")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 4")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 5")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 6")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 7")) {
  move_object(clone_object("/players/francesco/univ/mob/student31.c"),
	this_object()); }
if (!present("student 8")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 9")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }
if (!present("student 10")) {
  move_object(clone_object("/players/francesco/univ/mob/student.c"),
	this_object()); }



set_light(1);
DOOR = 0;

short_desc = "Classroom #12" ;
long_desc =
     "    This is the University Auditorium:  not only is this a classroom\n"+
     "during school hours, but it also hosts scientific seminars, graduating \n"+
     "ceremonies, and the University Council.  This is one of the largest \n"+
     "rooms on campus, seating up to 300 people.  On the end wall there is\n"+
     "a wide blackboard.  The podium holds an overhead projector, a laser \n"+
     "pen and some transparencies.  The curved amphitheatre shape makes the \n"+
     "room suitable for both teaching activities and conferences.\n",


items = ({
   "projector","The overhead projector is used by the teachers to send information to a\n"+
               "large screen.  It allows everyone to see the formulas, the definitions\n"+
               "and the schemes written by the teacher on the transparencies.  This frees\n"+
               "up time the teacher would otherwise be spending writing on the blackboard\n"+
               "and therefore he can concentrate on the explanations and the comments",
   "blackboard","It spans from one side to the other of the end wall",
   "transparencies","Thin plastic sheets that can be written on",
   "screen","White screen illuminated by the light coming from the projector",
   "pen","Like a plain pen, it emits a thin laser beam to point to the screen",
   "wall","The end wall is about 20 feet tall",
   "podium","It is flat shaped so that it can keep things on it",
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor1.c","exit",
  
});

}




