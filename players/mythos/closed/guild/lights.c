inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("lights");
  set_weight(100000);
    set_value(1);
    set_light(10);
  call_out("moo",3);
}

get() { return 0; }
drop() { return 1; }

moo() {
  destruct(this_object()); return 1; }
