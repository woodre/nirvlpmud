inherit "room/room";
reset(arg) {
  if(!present("kappa1.c")) {
    move_object(clone_object("/players/mythos/amon/kappa1.c"),this_object());} 
  if(!present("kappa2")) {
    move_object(clone_object("/players/mythos/amon/kappa2.c"),this_object());}
  if(!present("kappa3")) {
    move_object(clone_object("/players/mythos/amon/kappa3.c"),this_object());}
  if(!present("kappa4")) {
    move_object(clone_object("/players/mythos/amon/kappa4.c"),this_object());}
  if(!present("master")) {
    move_object(clone_object("/players/mythos/amon/master.c"),this_object());}
  if(!arg) {
  set_light(1);
    short_desc = "Kappa Space";
    long_desc =
    "You reach a bend in the river.  Here there is a big rock, on it are \n"+
    "sitting the Master Kappa and his retainers.  Be careful, he is a \n"+
    "ferocious foe.\n";
  items = ({
    "river","A fast smooth moving body of water. \nThe Kappa's home and territory.  It flows 'east'",
    "east","You make out a small 'hole' in the fabric of space-\nan enterance beyond the dream",
    "hole","It is an odd thing.  Perhaps you should 'enter' it",
  });

  dest_dir = ({
    "/players/mythos/aroom/boy1.c","north",
  });
} }

init() {
  ::init();
    add_action("enter_hole","enter");
}

enter_hole() {
  call_other(this_player(),"move_player","hole#players/mythos/aroom/dream.c");
  say(this_player()->query_name()+" disappears through a hole in the dream.\n");
  return 1;
}
