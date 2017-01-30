inherit "obj/weapon";

init() {
  ::init();
}

reset(arg) {
  set_name("tire iron");
  set_class(4);
  set_alias("bar");
  set_alt_name("crow bar");
  set_short("bar");
set_long(
  "This small, round metal crow bar is often used as\n"+
  "a pry bar to get off hub caps or open stubborn doors,\n"+
  "windows, etc.\n");
  set_value(5);
  set_weight(1);

}


query_save_flag(){ return 1;}

