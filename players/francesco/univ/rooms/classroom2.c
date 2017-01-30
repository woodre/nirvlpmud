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


set_light(1);
DOOR = 0;

short_desc = "Classroom #13" ;
long_desc =
     "    This is a typical University classroom.  It is used for small\n"+
     "to medium attendance classes, like those given to advanced courses.\n"+
     "On the end wall there is a wide blackboard.  The podium holds an \n"+
     "overhead projector, a laser pen and some transparencies.  The sitting \n"+
     "desks are all aligned and they supposedly could host about 50 people.\n",


items = ({
   "projector","The overhead projector is used by the teachers to send information to a\n"+
               "large screen.  It allows everyone to see the formulas, the definitions\n"+
               "and the schemes written by the teacher on the transparencies.  This frees\n"+
               "up time the teacher would otherwise be spending writing on the blackboard\n"+
               "and therefore he can concentrate on the explanations and the comments",
   "blackboard","It spams from one side to the other of the end wall",
   "transparencies","Thin plastic sheets that can be written on",
   "screen","White screen illuminated by the light coming from the projector",
   "pen","Like a plain pen, it emits a thin laser beam to point to the screen",
   "wall","The end wall is about 12 feet tall",
   "podium","It is flat shaped so that it can keep things on it",
});

dest_dir = ({
  "/players/francesco/univ/rooms/corridor1.c","exit",
  
});

}




