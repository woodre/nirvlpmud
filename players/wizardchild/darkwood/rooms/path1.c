/* path1.c: path in forests */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "A dark pathway";
  long_desc  = "Walking along, you notice that the trees surrounding you are becoming larger\n"
              +"and larger, blocking out the sun. The path beneath you looks moderately worn,\n"
              +"though much less worn than the entry path.\n"
              +"There is a large ant hill here, and many ants crawling around it.\n"
              +"Through the overgrown bushes and the enormous trees, you think you can see\n"
              +"something...\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/path2", "west",
    ROOT_DIR+"rooms/entry", "east",
    ROOT_DIR+"rooms/forest1", "north"
  });
  load_room();
}
init() {
  ::init();
  /* get the newbies out of here */
  if(this_player()->query_level() < 9) {
    say(this_player()->query_name()+" trips and slides into the anthill.\n");
    write("You slip on some mud, and go sliding into the anthill.\n");
call_other(ROOT_DIR+"rooms/anthill","??");
    this_player()->move_player("anthill#"+ROOT_DIR+"rooms/anthill");
  } else
    add_action("gonorth", "north", 1);
}
gonorth() {
  write("Being a fool, you jump straight into the darkness.\n");
  say(this_player()->query_name()+" jumps into the darkness.\n");
  return 0;
}
