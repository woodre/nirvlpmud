/* path4.c: end of pathway */
#define ROOT_DIR "/players/wizardchild/darkwood/"
inherit "players/wizardchild/darkwood/dwroom";
object *here; /* track who's come around */
status called;
reset(arg) {
  if(arg)
    return;
  short_desc = "A dark pathway";
  long_desc  = "As you walk along the path, you notice that you are no longer alone.\n"
              +"In fact, you are far from it.\n"
              +"The pathway comes to an abrupt stop; apparently, the creators of the\n"
              +"path didn't live long enough to extend it beyond here. Though you are\n"
              +"unable to see distinct figures, you can barely see the light of the\n"
              +"shack behind you being shaded out by a large, hairy beast.\n"
              +"This is, apparently, the \"wrong\" side of town.\n";
  dest_dir   =
  ({
    ROOT_DIR+"rooms/death", "die"
  });
  objects    =
  ({
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/shadow",
    ROOT_DIR+"mons/beastie",
    ROOT_DIR+"mons/beastie",
    ROOT_DIR+"mons/bbeastie"
  });
  load_room();
  called = 0;
  call_out("replace_mons", 2400);
}
init() {
  int i;
  ::init();
  if(called && !present("slayer", this_object()))
    replace_mons();
  else if(!present("slayer", this_object())) {
    for(i = 0; i < sizeof(here); i++)
      if(here[i] == this_player()) {
        move_object(clone_object(ROOT_DIR+"mons/bslayer"), this_object());
        called = 1;
      }
  }
  if(i == sizeof(here))
    here += ({this_player()});
  add_action("search","search");
}
search() {
  if(present("slayer") || present("beastie")) { 
    write("You find nothing.\n");
    return 1;
  }
  write("You find an exit to the path.\n");
  this_player()->move_player("path#"+ROOT_DIR+"rooms/path3");
  return 1;
}
replace_mons() {
  if(called && !present("slayer", this_object()))
    move_object(clone_object(ROOT_DIR+"mons/bslayer"), this_object());
  if(called)
    return 0;
  if(!present("beastie", this_object()))
    move_object(clone_object(ROOT_DIR+"mons/beastie"), this_object());
  if(!present("big beastie", this_object()))
    move_object(clone_object(ROOT_DIR+"mons/bbeastie"), this_object());
  if(!present("shadow", this_object()))
    move_object(clone_object(ROOT_DIR+"mons/shadow"), this_object());
}
