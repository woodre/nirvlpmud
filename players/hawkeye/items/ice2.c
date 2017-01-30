inherit "obj/treasure";

drop() { return 0; }
reset(arg) {
  if(!arg) {

  set_id("bug");
  set_long("ha ha your screwed");
}
}
init() {
  ::init();

#ifndef __LDMUD__
         add_action("screwed"); add_xverb(" ")
#else
           add_action("screwed"," ",3);
#endif
}
screwed() { write("What?\n");
              say(capitalize(this_player()->query_real_name())+
            " goes into a corner to play with himself.\n");
      return 1; }

die() {

  destruct(this_object());
  return 1;
}
