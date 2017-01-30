#define MASTER_R "/players/mizan/closed/RandomRoomDM.c"
id(str) { return str == "pump"; }
short() { return "A busy suction pump (pumping)"; }
long() {
  write("This is a happy suction pump. You have no idea what a\n"+
  "suction pump is, or does, for that matter, but it is here, and\n"+
  "it is happy. A small sticker on it reads:\n\n"+
  "'For a heart-beat fixer... kick me!\n");
write("\n"+
  "An ant crawling on the pump shouts:\n"+
  "'" + MASTER_R->query_reboot_time());
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
