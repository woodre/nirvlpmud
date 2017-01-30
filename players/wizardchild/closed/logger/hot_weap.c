string type;
set_type(s) { type = lower_case(s); }
query_type() { return type; }
short() { return "A hot "+type; }
long() {
  write("This just-made weapon is still too hot to use, so you must let it sit.\n");
  write("You would probably injure yourself if you tried to grab it.\n");
  return 1;
}
id(str) { return str == "weapon" || str == "hot weapon" 
            || str == "hot_weap" || str == type;
}
get() {
  write("You reach for the hot weapon and scorch your hand!\n");
  this_player()->add_hp(-5);
  return 0;
}
