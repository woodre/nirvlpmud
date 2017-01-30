inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("illusion");
    set_short("illusion");
    set_alias("illusion");
    set_long("An illusion.\n");
    set_weight(100);
    set_value(0);
call_out("ill_count", random(500) + 500);
}

ill_count()  {
tell_room(environment(this_object()),
  "Something has changed.\n");
remove_call_out("ill_count");
destruct(this_object());
   return 1;
}

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 1; }
