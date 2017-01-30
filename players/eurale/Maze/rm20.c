/*  a teleporting maze for higher level players  */

#define tp this_player()->query_name()
inherit "room/room";
int is_cross;

reset(arg) {
is_cross = 1;

if(!present("diablo")) {
move_object(clone_object("players/eurale/Mon/diablo.c"),this_object()); }

  if(arg) return;
set_light(0);

short_desc = "a dark cave";
long_desc =
	"  You stand in a carved out tunnel through the rocks.  The air \n"+
	"is damp and musty and it is very hard to see.  The floor is \n"+
	"covered with sand to make it as flat and smooth as possible. \n"+
	"The jagged rocks sticking out along the sides pose a serious \n"+
	"threat of injury if you continue.  The tunnel looks like it has \n"+
	"been used recently. \n";

items = ({
	"sand","It appears the sand came from another portion of the tunnel \n"+
		"or from outside altogether.",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs7.c","south",
	"/players/eurale/Maze/tun19.c","east",
});

}


init() {
  ::init();
  add_action("south","south");
  add_action("search","search"); }

search() {
object cross;
  if(present("diablo",environment(this_player()))) {
  write("Diablo will not let you search... \n");
  return 1; }

if(!present("corpse of diablo")) {
  write("A thorough search reveals nothing special.. \n");
  is_cross = 0;
  return 1; }

else {
  if (is_cross) {
  write("You carefully search the smoldering corpse of Diablo.. \n"+
	"and hidden deep within his clothing.... you find a tiny \n"+
	"silver cross. \n");
  cross = clone_object("players/eurale/Misc/rood.c");
  if(transfer(cross,this_player()))
	move_object(cross,this_player());
  is_cross = 0;
  }
return 1;
  }

}


south() {
  object ob;
    ob = present("diablo");
  if(present("diablo")); {
    write("Diablo blocks your way! \n");
    say(tp+" is blocked by Diablo! \n");
  return 1; }
}
