inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("tpass");
    set_weight(0);
    set_value(0);
}

drop() {
if(environment()->query_ghost()) destruct(this_object());
else return 1; }
get()   { return 0; }
can_put_and_get()  { return 0; }
