inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
 set_name("rhino");
set_short("A huge Rhino");
set_long("A large Rhino. He is quietly grazing on grass. You\n"+
"you startle him as you come into their view. They peer at you\n"+
"quizically.\n");

  set_level(7);
 set_ac(6);
 set_wc(11);
 set_hp(105);
 set_al(1000);
 }
}
