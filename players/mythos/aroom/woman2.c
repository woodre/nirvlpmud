#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("taira1.c")) {
    move_object(clone_object("/players/mythos/amon/taira1.c"),this_object());} 
  if(!present("taira2")) {
    move_object(clone_object("/players/mythos/amon/taira2.c"),this_object());}
  if(!present("taira3")) {
    move_object(clone_object("/players/mythos/amon/taira3.c"),this_object());}
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/ryo.c"),this_object());}
  if(!present("officer")) {
    move_object(clone_object("/players/mythos/amon/gtaira.c"),this_object());}
  if(!arg) {
  set_light(1);
    short_desc = "Taira's Revenge";
    long_desc =
      "You pass through the gore in the battle'field' and you reach the standard \n"+
      "of the Taira.  The battle seems to have gone badly for the Taira, but luckily\n"+
      "for them the Minamoto have called a retreat.  The atmosphere is heavy.\n";
  items = ({
    "hole","It is an odd thing.  Perhaps you should 'enter' it",
      "field","You notice two things that seem odd in this mess- a 'hole' and a \n'mound' of flesh",
      "mound","You look closer and you realize that it is the 'body' of a woman",
      "standard","The flag is blood red.  It flies high",
     "body","A body of a woman.  Perhaps her spirit has returned as a 'ryo'?",
  });

  dest_dir = ({
    "/players/mythos/aroom/woman1.c","north",
  });
} }

init() {
  ::init();
    add_action("enter_hole","enter");
    add_action("north","north");
}

enter_hole() {
  call_other(this_player(),"move_player","hole#players/mythos/aroom/dream.c");
  say(this_player()->query_name()+" disappears through a hole in the dream.\n");
  return 1;
}

north() {
  object ob;
    ob = present("ryo");
    if(present("ryo")) {
    write("Something blocks your way.\n");
    say(tp+ " is stopped from going north by some mist.\n");
  return 1;
}
}
