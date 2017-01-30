inherit "obj/player.c";
reset(arg) {
  if(arg) return ;
  name = "wizkid";
  restore_object("players/"+name);
  move_object(this_object(), "/players/wizardchild/workroom");
  set_living_name(name);
  level = 666;
}
set_crap() {
  is_interactive = 1;
  call_out("set_crap", 1);
}
