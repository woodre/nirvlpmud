#include "/players/grimm/header"
inherit "room/room";
object demon, stake;
reset(arg) {
   monster();
  if (arg) return;
short_desc="Demon's Lair";
long_desc="You have entered the lair of the Demon Lord.  All is quiet, and\n"+
          "the fealing of death is near!\n";
dest_dir=({"/players/grimm/caverns/cavern5_2","up",
   "/players/grimm/closed/stakeroom","down"});
set_light(0);
}
monster() {
   if(!present("demon")) {
      demon = clone_object("players/grimm/monster/demonlord");
      move_object(demon,this_object());
   }
}

down() {
  if(!present("demon")) {
    write("The demon comes back to life and begins to pound you!\n");
    monster();
    return 1;
  }
  if(this_player()->query_ghost() || this_player()->query_level()>19) {
    this_player()->move_player("down#/players/grimm/closed/stakeroom");
    return 1;
} else {
  write("The demon will not let you past him...ALIVE...\n");
  return 1;
}
}

init() {
  add_action("up","up");
  add_action("up","u",1);
  if(present("bad_boy_bane",this_player()) && present("demon",this_object())) {
    destruct(present("demon"));
    destruct(present("bad_boy_bane",this_player()));
    write("The demon's bane killed the demon.\n");
  }
  add_action("down","down");
  add_action("down","d",1);
}
up() {
this_player()->move_player("up#/players/grimm/caverns/cavern5_2");
return 1;
}
