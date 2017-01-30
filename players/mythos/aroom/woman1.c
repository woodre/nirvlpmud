#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("taira1")) {
    move_object(clone_object("/players/mythos/amon/taira1.c"),this_object());} 
  if(!present("taira2")) {
    move_object(clone_object("/players/mythos/amon/taira2.c"),this_object());}
  if(!present("taira3")) {
    move_object(clone_object("/players/mythos/amon/taira3.c"),this_object());}
  if(!present("taira4")) {
    move_object(clone_object("/players/mythos/amon/taira4.c"),this_object());}
  if(!present("officer")) {
    move_object(clone_object("/players/mythos/amon/gtaira2.c"),this_object());}
  if(!arg) {
  set_light(1);
    short_desc = "Taira Sleeping Room";
    long_desc =
      "You enter the old woman's dreams.  You see a great battlefield before you.\n"+
      "The field is a red color with patches of brown.  You hear the cries of dying\n"+
      "soldiers. This is the battlefield of the great Gempei War- the battle between\n"+
      "the Taira clan and the Minamoto clan, during the year 1156.  You see a small\n"+
      "band of Tairas before you.\n";   
      items = ({
      "south","To the south you see the red flag of the Taira's flying",
      "field","The field is a nasty mess of blood and gore",
  });

  dest_dir = ({
    "/players/mythos/aroom/woman2.c", "south",
    "/players/mythos/aroom/hut.c","hut",
  });
} }

init() {
  ::init();
    add_action("south","south");
}

south() {
  object ob;
    ob = present("officer");
  if(present("officer")) {
  write("Officer blocks your way.\n");
  say(tp+" is blocked by Officer.\n");
  return 1;
}
}
