/* antqueen.c: queen ant in hill */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("ant");
  set_alias("queen ant");
  set_short("The Queen ant");
  set_long("Much larger than even the guard ants, the Queen ant appears to be laying her\n"
          +"eggs now. Despite her size, she is very weak due to her current condition,\n"
          +"and would probably be an easy foe.\n");
  set_level(14);
  set_hp(80);
  set_wc(10);
  set_ac(7);
  set_al(350);
  move_object(clone_object(ROOT_DIR+"obj/eggs"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/eggs"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/eggs"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/eggs"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/eggs"), this_object());
}
id(str) { return str == "ant" || str == "queen ant"; }
init() {
  add_action("kill_me", "kill");
}
kill_me(str) {
  if(id(str) && present("ant", environment(this_object())) == this_object())
    return 0;
  else
    write("Another ant gets in your way.\n");
  return 1;
}
