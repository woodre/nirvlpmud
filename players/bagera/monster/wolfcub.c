inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
     object item;
 item = clone_object("/players/bagera/weapons/cub.c");
  move_object(item, this_object());
  command("wield bone", this_object());
 set_name("cub");
 set_alias("wolf");
 set_alias("wolfcub");
 set_short("A small wolf cub");
 set_long("A little wolf cub. It looks totally harmless.\n"+
 "It looks up at you with big puppy dog eyes and yelps.\n");
  set_level(7);
 set_ac(6);
 set_wc(11);
 set_hp(105);
 set_al(100);
 set_chat_chance(35);
load_chat("The wolf cub yelps and barks at you playfully.\n");
set_a_chat_chance(50);
load_a_chat("The cub yelps for his momma!\n");
load_a_chat("The cub whimpers as he is beaten to death.\n");
load_a_chat("The cub looks at you with huge puppy dog eyes, begging for his life.\n");
 }
}
