
inherit "obj/treasure";
string who;

reset(arg) {
if(arg) return;
  set_alias("knight summon");
  call_out("junk", 30);
}

init() {
::init();
  add_action("yes","yes");
  add_action("no","no");
}

yes() {
object ob;
  ob = find_player(lower_case(who));
  write("You accept and with a blink, you appear at " +who+ "'s side.\n");
  move_object(this_player(), environment(ob));
  say(this_player()->query_name()+" arrives with a great flash.\n");
  this_player()->look();
  destruct(this_object());
  return 1;
}
no() {
object ob;
  ob = find_player(lower_case(who));
  write("You decline and choose to stay where you are.\n");
  tell_object(ob, this_player()->query_name()+" has declined the offer.\n");
  destruct(this_object());
  return 1;
}
set_who(w)  { who = w; }

junk() {
  destruct(this_object());
  return 1;
}
drop() { return 1; }

