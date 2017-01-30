#define EO environment(this_object())

id(str) { return str == "rock"; }
query_value() { return 1; }
short() { return "A rock"; }
long() { write("A rock.\n"); }
init() { add_action("activate","activate"); }

activate() {
  call_out("tele", 20, this_player());
  write("You activate the rock, it starts glowing.\n");
  return 1; }

tele(object ob) {
  tell_object(ob, "Zooom--------------->\n");
  move_object(ob, EO);
  tell_object(ob, "File name: "+file_name(EO)+".\n");
  destruct(this_object());
  return 1; }
