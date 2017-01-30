inherit "obj/monster";
object owner;
int level, hp, wc, ac;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Jena");
  set_alias("jena");
  set_alt_name("bitch");
  set_short("Jena: just a nice girl from back home");
  set_long("Did you ever meet a girl who was perfect, except\n"+
           "for her uncanny way of being a bitch most of the time?\n"+
           "Well, meet Jena the Bitch. Brought to you by catt. Do\n"+
           "me a favour and slap her, punch her, do whatever makes\n"+
           "you happy, it will make me feel better. Oh, just to help\n"+
           "type {assess} and it will tell you what she looks like.\n");
  set_level(10);
  set_hp(200);
  set_wc(10);
  set_ac(10);
  enable_commands();
set_chat_chance(10);
load_chat("Jena laughs at you\n");
load_chat("Jena tells you: you are a dork!\n");
load_chat("Jena teases you like the bitch she is\n");
load_chat("Jena burps in your face\n");
load_chat("Jena says: can I sit on you?\n");
}
init() {
  add_action("assess","assess");
  ::init();
}
assess() {
   write("Jena is 5ft 2inches, 102 lbs, dark hair(long), blue-green\n");
   write("eyes, chest: 32  waist: 24  hips: 36, fair skinned.\n");
   write("Definately good looking. Kill the bitch, please!!!\n");
  return 1;
}
