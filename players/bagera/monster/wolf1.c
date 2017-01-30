inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
 set_name("wolf1");
 set_alias("wolf");
 set_short("A large grey wolf");
 set_long("A large grey wolf. He is part of the council of wolves.\n"+
"He sits on his hind legs listening to the meeting in progress.\n"+
"His ears perk up and his head snaps around as you look at him.\n");
  set_level(10);
 set_ac(8);
 set_wc(14);
 set_hp(150);
 set_al(100);
 set_chat_chance(10);
load_chat("A wolf says: If Shere Khan finds him, he will kill the boy.\n");
set_a_chat_chance(50);
load_a_chat("The wolf growls deep within his throat and snaps his razor sharp teeth at you!\n");
load_a_chat("The wolf sinks his teeth into your flesh, ripping it apart.\n");
 }
}
