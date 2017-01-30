inherit "obj/treasure";

object caster;

reset(arg) {
  set_id("resur_ob");
  call_out("time_out",100);
}
set_caster(object ob) {
  caster=ob;
}
get() { return 0; }
drop() { return 1; }
init() {
  add_action("cmd_live","live");
}
cmd_live() {
  tell_room(environment(environment()),
caster->query_name()+" infuses life and order into "+environment()->query_name()+
"\nbringing a physical manifestation to what was once\n"+
"a feeble shade.\n");
  return this_player()->remove_ghost();
}
time_out() {
  if(!environment()->query_ghost()) destruct(this_object());
  tell_object(environment(),
    "Your silence is taken to mean that you wish to remain a ghost.\n");
  tell_object(caster,
environment()->query_name()+" wishes to remain a ghost.\n");
  caster->add_sp(100+random(50));
  destruct(this_object());
}
