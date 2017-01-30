inherit "room/room";

init() {
 ::init();
}

reset(arg){


if(!present("terminal")) {
  move_object(clone_object(
    "/players/snow/closed/cyber/boards/ministryboard.c"),
    this_object());
   }

 if(!arg){
 set_light(1);
 short_desc="Ministry Chambers";
 long_desc=
"     The CyberNinja Ministry Chambers is a tall circular room\n"+
"with walls and ceiling made completely of transparent crystal.\n"+
"This crystal dome houses a large low-standing circular table.\n"+
"Surrounding this table rest several mats, one for each Council\n"+
"Member.\n"; 

items=({
 "mats","The mats are square pillows",
 "crystal","The crystal is completely transparent",
 "table","The table is a gathering place for Council discussions",
 });

  dest_dir=({
 "/players/snow/closed/cyber/rooms/hallway1.c","down",
      });
  }   }

feel() { return "no"; }