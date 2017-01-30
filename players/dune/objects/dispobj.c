#define MASTER_R "/players/dune/objects/dispdaem.c"
id(str) { return str=="dispenser"; }
reset() {}
short() { return "A fancy talker dispenser"; }
long() {
   write("The Fancy Talker Dispenser!\n");
   MASTER_R->howto();}
get() { return 0; }
init() {
   add_action("buy","buy");
   }
buy(str) { MASTER_R->buy(str); return 1; }
