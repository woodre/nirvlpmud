inherit "/obj/treasure";

reset(arg){
  if(arg) return;
  set_short("Dir Thingy");
  set_long("Dir Thingy - just for Rump's use.\n");
}

init(){
  ::init();
  add_action("dir_check", "n");
  add_action("dir_check", "s");
  add_action("dir_check", "w");
  add_action("dir_check", "e");
  add_action("dir_check", "ne");
  add_action("dir_check", "nw");
  add_action("dir_check", "sw");
  add_action("dir_check", "se");
  add_action("dir_check", "u");
  add_action("dir_check", "d");
}

dir_check(){
  write("Your verb was "+query_verb()+".\n");
  return 1;
}
