#define TP this_player()
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("ant larvae");
set_alias("larvae");
set_short("larvae");
set_long(
  "This white, gel-like ant larvae is slimy to the touch.  It has a \n"+
  "pungent, noxious odor and feels as if it were moving slightly.\n");

set_weight(1);
set_value(500 + random(50));
set_save_flag();
}

init() {
  ::init();
  add_action("barter","barter");
}

barter(str) {
int num;
object ob;
  ob = (present("madame rue",environment(TP)));
if(!str) { write("Barter what?\n"); return 1; }
if(ob && (str == "ant larvae" || str == "larvae")) {
  num = 950 + random(100);
  write("With excitement, Madame Rue rubs her hands together as you\n"+
	"hand her the squirming larvae.  She listens to it, runs her\n"+
	"tongue along it, and gives you "+num+" coins for it.\n");
  TP->add_money(num);
  destruct(this_object());
  return 1; }
else {
  write("I'm sorry, the person who would be interested is not present\n"+
	"to barter with...\n");
  return 1; }
}
