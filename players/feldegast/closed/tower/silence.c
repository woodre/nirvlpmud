inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Chamber of Silence";
  long_desc=
"This is a high vaulted chamber bare of all furnishings\n"+
"and distractions of any kind except for a plush couch\n"+
"in the center of the room.  Sounds here cannot carry\n"+
"more than a few feet and silence reigns.\n";
  items=({
    "couch","A comfortable couch made of black leather"
  });
  dest_dir=({
    "/players/feldegast/closed/tower/tower3","north"
  });
}
init() {
  ::init();
  command("muffle gossip",this_player());
  command("muffle risque",this_player());
  command("muffle junk",this_player());
  command("muffle equip",this_player());
  command("muffle msg",this_player());
  command("muffle shout",this_player());
  command("muffle babble",this_player());
  command("muffle poetry",this_player());
  command("hush",this_player());
  command("toggle",this_player());
  command("mdark",this_player());
  write("All sounds are deadened as you step across the threshold.\n");
  add_action("north","north");
}
north() {
  command("channel gossip",this_player());
  command("channel risque",this_player());
  command("channel junk",this_player());
  command("channel equip",this_player());
  command("channel msg",this_player());
  command("channel shout",this_player());
  command("channel babble",this_player());
  command("channel poetry",this_player());
  command("hush",this_player());
  command("toggle",this_player());
  command("mdark",this_player());
  return 0;
}
