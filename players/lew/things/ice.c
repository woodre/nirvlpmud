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

    add_action("screwed"); add_xverb("");
}
screwed() { write("You are frozen.\n");
              say(capitalize(this_player()->query_real_name())+
            " tries to move in his block of ice.\n");
      return 1; }

die() {

  destruct(this_object());
  return 1;
}
