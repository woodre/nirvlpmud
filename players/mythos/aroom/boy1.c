#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("kappa1")) {
    move_object(clone_object("/players/mythos/amon/kappa1.c"),this_object());} 
  if(!present("kappa2")) {
    move_object(clone_object("/players/mythos/amon/kappa2.c"),this_object());}
  if(!present("kappa3")) {
    move_object(clone_object("/players/mythos/amon/kappa3.c"),this_object());}
  if(!present("kappa4")) {
    move_object(clone_object("/players/mythos/amon/kappa4.c"),this_object());}
  if(!present("slave")) {
    move_object(clone_object("/players/mythos/amon/slave.c"),this_object());}
  if(!arg) {
  set_light(1);
    short_desc = "Kappa Room";
    long_desc =
    "You enter the boy's dream.  He dreams of the nightmarish creatures\n"+
    "called th Kappa. A river flows to the south.  The Kappa seem to enjoy\n"+
    "jumping in and out of the water. You notice that the Kappa are staring\n"+
    "at you...\n";
  items = ({
    "river","A fast smooth moving body of water.  The Kappa's home and territory.\nIt flows south",
    "south","You make out a patch of land to the south where the river flows",
  });

  dest_dir = ({
    "/players/mythos/aroom/boy2.c", "south",
    "/players/mythos/aroom/hut.c","hut",
  });
} }

init() {
  ::init();
    add_action("south","south");
}

south() {
  object ob;
    ob = present("slave");
  if(present("slave")) {
  write("Slave blocks your way.\n");
  say(tp+" is blocked by Slave.\n");
  return 1;
}
}
