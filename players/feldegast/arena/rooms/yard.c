inherit "room/room";

object dummy;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Training Room";
  long_desc=
"     This is an open room used by gladiators to practice.  Carefully\n"+
"woven grass practice mats are on the floor, and sackcloth dummies\n"+
"are suspended from the ceiling.\n";
  dest_dir=({
    "/players/feldegast/arena/rooms/crtyard","west"
  });
}
init() {
  ::init();
  if(!dummy) {
    dummy=clone_object("/players/feldegast/arena/npc/target");
    move_object(dummy,this_object());
  }
}
   
