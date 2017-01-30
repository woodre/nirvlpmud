/*
This is one of those items that people frequently suggest as
something that should be coded...Go figure.
*/

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("weed");
  set_alias("herb");
  set_short("Whore's Weed");
  set_long(
    "This herb has long been used by whores and women of poor character\n"+
    "to abort their unborn children.  You may 'injest' this herb if you\n"+
    "if that is what you wish to do.\n"
  );
  set_weight(1);
  set_value(450);
}

void init() {
  add_action("cmd_injest","injest");
}

int cmd_injest(string str) {
  if(!str || !id(str)) {
    notify_fail("Injest what?\n");
    return 0;
  }
  if(!((int)this_player()->query_pregnancy())) {
    write("You are not pregnant.\n");
    return 1;
  }
  this_player()->clear_pregnancy();
  write("You chew the weed and begin to feel ill.\n");
  this_player()->add_weight(-local_weight);
  destruct(this_object());
  return 1;
}
