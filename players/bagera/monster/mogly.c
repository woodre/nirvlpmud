inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
 set_name("mowgli");
 set_alias("man-cub");
 set_alias("mancub");
 set_short("Mowgli, a small man-cub");
set_long("This is Mowgli, the man-cub, who has been sent to live\n"+
"back in the man village. He has seen the rain come and go\n"+
"10 times. He is a skinny little dark Indian boy with\n"+
"knock knees and bird legs.\n");
  set_level(10);
 set_ac(8);
 set_wc(14);
 set_hp(150);
 set_al(100);
 set_chat_chance(35);
load_chat("Mowgli says: I don't wanna go back to the man-village!\n");
load_a_chat("The cub whimpers as he is beaten to death.\n");
 }
}
