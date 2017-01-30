#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int DOOR;

reset(arg) {
  if(arg) return;

if (!present("student 1")) {
  move_object(clone_object("/players/francesco/univ/mob/student1.c"),
	this_object()); }

if (!present("student 2")) {
  move_object(clone_object("/players/francesco/univ/mob/student1.c"),
	this_object()); }

if (!present("student 3")) {
  move_object(clone_object("/players/francesco/univ/mob/student1.c"),
	this_object()); }


set_light(1);
DOOR = 0;

short_desc = "A long corridor" ;
long_desc =
     "   Walking along the corridor more students cross your way.  They\n"+
     "run to their classes since they really want to learn something new.\n"+
     "You wonder why a door very similar to the one you saw in the other \n"+
     "part of the corridor is closed.  It might be an another entrance to\n"+
     "the same classroom.  Should the same guard you met in the previous \n"+
     "room have followed you here be careful and behave politely.\n",


items = ({
   "door","This door might lead to the rear of the classroom.  You might want\n"+
          "to enter it and check who is inside.  It has a sign on it.  Beware\n"+
          "when you enter a room with a warning sign on its door",
   "sign","The sign reads: STAFF ONLY",
});

dest_dir = ({
  "/players/francesco/univ/rooms/sala_proiezioni.c","enter",
  "/players/francesco/univ/rooms/corridor1.c","west",
  "/players/francesco/univ/rooms/corridor3.c","east",
});

}

init() {
  ::init();
  add_action("open_door","open");
  add_action("close_door","close");
  add_action("enter","enter");
}

open_door(str) {
if(!str) { write("Open what?\n"); return 1; }
if(str == "door" && DOOR == 0) {
  write("You silently turn the knob and open the door.\n");
  DOOR = 1;
  return 1; }
else {
  write("With a second glace you see that the door is already open.\n");
  return 1; }
}

close_door(str) {
if(!str) { write("Close what?\n"); return 1; }
if(str == "door" && DOOR == 1) {
  write("You gently close the door with an audible 'click.'\n");
  DOOR = 0;
  return 1; }
else {
  write("You turn to see that the door has already been closed.\n");
  return 1; }
}

enter() {
if(DOOR == 0) {
  write("You take a step and run smack into the closed door.\n");
  tp->hit_player(8);  /* a little damage from bumping thier nose */
  return 1; }
else {
  tp->move_player("enter#/players/francesco/univ/rooms/sala_proiezioni.c");
  return 1; }
}
