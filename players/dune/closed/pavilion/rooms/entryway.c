/* Place to read rules on RoboMech */
inherit "room/room";
#define MECH environment(this_player())
#define TP  this_player()

init() {
   if(!present("oracle", find_object("room/plane8.c"))) {
    move_object(
      clone_object("/players/dune/castle.c"),
      "/room/plane8.c");
      }
   write_file("/players/dune/log/ROBOENTER", this_player()->query_real_name()+
         " (level "+this_player()->query_level()+") was in Robomech."+
         " ("+ctime()+")\n");
  add_action("look","look");
  add_action("read","read");
  add_action("go_leave","leave");
  ::init();
  }

reset(arg) {
   if(!arg) {
   set_light(1);
   short_desc=("RoboMech Central");
   long_desc=
"     You stand in the center of RoboMech Pavilion.  Huge beams of\n"+
"strange bone and metal twine into the towering hexagonal glass\n"+
"sky.  Before you, a speckled marble floor reaches from wall to\n"+
"wall.  It fills the vast area of the pyramid base with a sea of\n"+
"reflecting smootheness before clashing against huge electronic \n"+
"doors.  A gigantic screen of the Official RoboMech Rules\n"+
"hangs from the ceiling.  Exits are 'leave' and 'hangar'.\n";

   dest_dir=({
   "/players/dune/closed/pavilion/rooms/roboshop.c","hangar",
        });

   items=({
   "pavilion",
"The Pavilion is gigantic.  It's as large as a small mountain",
   "beams","The beams are of bone and metal, intertwined",
   "floor","The floor is of black and red speckled marble",
   "marble","The reflecting marble is speckled red and black",
   "pyramid","The RoboMech Pavilion is in the shape of a pyramid",
   "doors","The metal double doors stand 20' tall",
   "glass","The glass ceiling arches high over your head",
        });
   }   }

go_leave() {
  if(this_player()->is_player()) {
    say(capitalize(this_player()->query_name())+
        " leaves RoboMech Pavilion.\n");
    write("You leave RoboMech Pavilion.\n\n");
    move_object(this_player(),
                "/room/plane8.c");
    }
  else write("RoboMechs may not leave the premise.\n");
  return 1;
}

look(string str) {
  if(str && str == "at screen") {
    show_screen();
    return 1; }
}


read(string str) {
  string file;
  if(str && str == "screen") {
    show_screen(); 
    return 1; }
  file = "/players/dune/closed/pavilion/docs/"+str;
  if(str && file_size(file) >= 0) {
    cat(file);
    return 1; }
   write("There is no such topic.\n");
}

show_screen() {
  /* Shows all help files and instructions to play */
  write(
"Welcome to RoboMech Central\n"+
"\n"+
"     RoboMech is a strategy/action game where players\n"+
"climb inside their own individualized robomech and\n"+
"fight the robomechs of other players.  Robomechs are\n"+
"tall robots which are piloted by players.\n"+
"To make a RoboMech, visit the RoboMech Hangar.\n"+
"     RoboMech is an alternative to player killing.\n"+
"Feel free to pour out all your homicidal manias,\n"+
"since you can't do any 'real' harm.  But who likes\n"+
"to lose?  This IS war, so go all out  >:D\n"+
"     You may get more detailed information by reading\n"+
"each of these other topics.\n");
  ls("/players/dune/closed/pavilion/docs");
  return 1;
}
