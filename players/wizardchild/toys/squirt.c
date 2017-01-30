drop() { return 1; }
get() { return 1; }
extra_look() {
  string name;
  name = environment(this_object())->query_name();
  return "For some strange reason, "+name+" is drenched";
}
reset(arg) { if(arg) destruct(this_object()); }
id(str) { return str == "squirt"; }
init() { if(present("squirt", this_player()) != this_object())
destruct(this_object()); }
