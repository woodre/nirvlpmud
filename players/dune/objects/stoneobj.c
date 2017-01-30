#define MASTER_R "/players/dune/objects/stonedaem.c"
id(str) { return str=="stone"; }
reset() {}
short() { return "A Philosopher's Stone"; }
long() {
   write("You have found the Philosopher's Stone!\n");
   MASTER_R->howto();}
query_value() {return 5000;}
get() { return 1; }
init() {
   add_action("stone","stone");
   }
stone(str) { MASTER_R->stone(str); return 1; }

