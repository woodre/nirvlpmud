#include "/players/grimm/header"
inherit "room/room";
object watch, man;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Clock Tower";
  long_desc=
    "This is the clock tower in the town of Sacred Blood.  It doesn't\n"+
    "look in very good shape, everything appears to be rusted.  Even\n"+
    "though all the parts are rusted, if this place had someone to\n"+
    "fix it up it would be a very nice tower.  Apparently, the man who\n"+
    "who use to keep it up is too old to manage now.\n";
  dest_dir=({DIR6(forest42),"down"});
  set_light(1);
}
monster() {
  if(!present("old man")) {
    man = clone_object(DIR8(towerman));
    move_object(man,this_object());
    return 1;
  }
}
