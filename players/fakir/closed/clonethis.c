inherit "obj/treasure";


void reset(int arg) {
  if(arg) return;
  set_id("thing");
  set_short("A Thing");
  set_long("You can dest this.\n");
this_player()->set_noidlequit();
}

