inherit "obj/treasure";
int first;

reset(arg)  {
  if(arg) return;
first = 0;
    set_id("greendragon");
    set_weight(0);
    set_value(0);
}

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
