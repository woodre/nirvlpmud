id(str) { return str == "pump"; }
short() { return "A busy suction pump (pumping)"; }
long() {
  string text_a;
  text_a=call_other("/players/mizan/closed/RandomRoomDM.c", "dump_call_out");
  write("This is a happy suction pump. You have no idea what a\n"+
  "suction pump is, or does, for that matter, but it is here, and\n"+
  "it is happy. A small sticker on it reads:\n\n"+
  "'For a heart-beat fixer... kick me!\n");
 write("\nA small LCD thingy stapled to the pump reads: \n");
  call_other("/players/mizan/closed/RandomRoomDM.c", "dump_call_out");
  write("\n");
}

init(){ add_action("kickme","kick"); }
kickme(str) {
  object ob;
  if(!str || str != "pump") return 0;
  ob=present("beatfixer", this_player());
  if(ob) {
  write("Nothing happens.\n");
  return 1; }
  write("You kick the pump, and it belches something which rockets\n"+
  "into your inventory!\n");
  move_object(clone_object("players/mizan/etheriel/items/beatfixer"), this_player());
  return 1;
}
