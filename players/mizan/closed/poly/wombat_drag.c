#define MORPH_ID "Mizan-morph-object"

object dragger;

id(str) { return str == "drag_device" || str == "reminder"; }
short() { return "A small reminder"; }
long() {
  write("This is a reminder for you to type 'loosen' when you don't want to\n"+
  "be dragged anymore.\n");
}

register_dragger(arg) { dragger = arg; }
get() { return 1; }
drop() { return 1; }
query_save_flag() { return 1; }

init() { add_action("stop_drag","loosen"); }


stop_drag() {
  object mob;
  if(!dragger) destruct(this_object());
  mob = present(MORPH_ID, dragger);

  if(!mob) destruct(this_object());
  mob->set_drag_ob(0);
  this_player()->say((this_player()->query_name()) + " is no longer being dragged.\n");
  tell_object(dragger, "You are long longer dragging anything.\n");
  write("You are no longer being dragged.\n");
  return 1;

}

