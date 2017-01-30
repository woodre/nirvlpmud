id(str) { return str == "noidle"; }

init() {
  if(this_player()->query_level() > 60) {
   this_player()->set_noidlequit();
   }
destruct(this_object());
}
