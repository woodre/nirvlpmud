inherit "room/room";
reset(arg) {
  if(!present("cat1.c")) {
    move_object(clone_object("/players/mythos/amon/cat1.c"),this_object());} 
  if(!present("cat2")) {
    move_object(clone_object("/players/mythos/amon/cat2.c"),this_object());}
  if(!present("cat3")) {
    move_object(clone_object("/players/mythos/amon/cat3.c"),this_object());}
  if(!present("cat4")) {
    move_object(clone_object("/players/mythos/amon/cat4.c"),this_object());}
  if(!present("mist")) {
    move_object(clone_object("/players/mythos/amon/mcat.c"),this_object());}
  if(!arg) {
  set_light(0);
    short_desc = "Cat Space";
    long_desc =
    "This end of the field is pitch dark.  It is very, very creepy.\n"+
    "Who knows what lurks here.\n";
  items = ({
    "hole","It is an odd thing.  Perhaps you should 'enter' it",
    "field","You can barely make out the field.  There is something funny over\nin the 'edge' of the field",
    "edge","You find a 'hole'",
  });

  dest_dir = ({
    "/players/mythos/aroom/cat1.c","north",
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
