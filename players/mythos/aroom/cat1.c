#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("cat1")) {
    move_object(clone_object("/players/mythos/amon/cat1.c"),this_object());} 
  if(!present("cat2")) {
    move_object(clone_object("/players/mythos/amon/cat2.c"),this_object());}
  if(!present("cat3")) {
    move_object(clone_object("/players/mythos/amon/cat3.c"),this_object());}
  if(!present("cat4")) {
    move_object(clone_object("/players/mythos/amon/cat4.c"),this_object());}
  if(!present("vampire cat")) {
    move_object(clone_object("/players/mythos/amon/Hcat.c"),this_object());}
  if(!arg) {
  set_light(0);
    short_desc = "Cat Room";
    long_desc =
    "You enter the cat's dream.  And what do you see?  Cats of course.  \n"+
    "The room is a small field leading to the south.  You see that it is \n"+
    "night and cats are abound.\n";
  items = ({
    "south","You barely make out the south end of the field. It's too dark",
    "field","The field is rather big",
  });

  dest_dir = ({
    "/players/mythos/aroom/cat2.c", "south",
    "/players/mythos/aroom/hut.c","hut",
  });
} }

init() {
  ::init();
    add_action("south","south");
}

south() {
  object ob;
    ob = present("vampire cat");
  if(present("vampire cat")) {
  write("The Vampire Cat blocks your way.\n");
  say(tp+" is blocked by the Vampire Cat.\n");
  return 1;
}
}
