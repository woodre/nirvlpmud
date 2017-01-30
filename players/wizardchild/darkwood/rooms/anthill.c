/* anthill.c: entrance to newbie place */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
reset(arg) {
  if(arg)
    return ;
  short_desc = "An oversized ant hill";
  long_desc  = "You are inside an oversized ant hill, to say the least. By looking around,\n"
              +"you can see that ants aren't the only thing crawling around in here.\n"
              +"This area is intended for newbies only.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/entry.c","out",
   ROOT_DIR+"rooms/ahroom1", "down",
  });
  objects    =
  ({
    ROOT_DIR+"obj/nwbsign",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant",
    ROOT_DIR+"mons/ant"
  });
  check_dirs =
  ({
    "down"
  });
  load_room();
}
init() {
  ::init();
  add_action("godown", "down", 1);
if(this_player()->query_level() >= 9 && this_player()->query_level() < 20)
if(this_player()->is_player())
    command("out", this_player());
}
goback() {
  write("You climb back out of the anthill.\n");
  say(this_player()->query_name()+" climbs out of the anthill.\n");
  return 0;
}
godown() {
  if(present("ant", this_object()))
    write("The ants block your path.\n");
  return (present("ant", this_object()));
}
