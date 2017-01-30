inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("dark");
    set_short("A cloud of darkness");
    set_long("It is too dark to see.\n");
    set_weight(100);
    set_value(0);
 set_light(-1);
call_out("dark",60);
}

dark() {
tell_room(environment(this_object()),
  "The darkness which fills the room dissipates.\n");
remove_call_out("dark");
destruct(this_object());
   return 1;
}
