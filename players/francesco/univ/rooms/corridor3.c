#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("student")) {
  move_object(clone_object("/players/francesco/univ/mob/student2.c"),
	this_object()); }
set_light(1);

short_desc = "An intersection" ;
long_desc =
     "   You have reached an intersection.  From here it is possible\n"+
     "to reach several other areas of the University,  accordingly to\n"+
     "everyone's willing.  A stand is positioned in the middle of the room.\n",

items = ({
   "stand","A metallic stand useful to post a sign on it",
   "sign","       NORTH      Department of Mechanical Engineering\n"+
          "       UP         Department of Letters\n"+
/*          "       EAST       Emergency exit\n"+ */
          "       WEST       Classrooms\n"+
          "       SOUTH      Restrooms\n"+
          "       ENTER      In Campus Cafeteria and Cinema",

});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec1.c","north",
  "/players/francesco/univ/rooms/corridor2.c","west",
/*  "/players/francesco/univ/rooms/outside.c","east",*/
  "/players/francesco/univ/rooms/restroom.c","south",
  "/players/francesco/letters/rooms/letters1.c","up",
/*  "/players/francesco/univ/rooms/bar2.c","east",*/
});

}

init(){
      ::init();
      add_action("enter","enter");
      }

enter(str) 
  {
  if(!str) {write("Enter what?\n"); return 1;}
  if(str!="cafeteria") {write("Enter what?\n"); return 1; }
  write("Welcome to the In Campus Cafeteria, "+call_other(this_player(),"query_name")+".\n\n");
  this_player()->move_player("into the Cafeteria#players/francesco/univ/rooms/bar2.c");
  return 1;
  }
