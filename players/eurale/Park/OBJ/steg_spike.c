/*  Changed to barterable item 8/17/02 - Eurale  */

#define ETP environment(this_player())
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("spike");
set_short("stegosaurus spike");
set_long(
	"This solid stegosaurus spike was part of the animal's\n"+
	"protection and is valued by treasure hunters.  You can\n"+
	"always 'barter' it in.\n");
    set_weight(3);
    set_value(1000);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int nm;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "spike") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  nm = 4500 + random(450);
  write("Sedjak slaps you on the back and says, 'Well done'.  He then\n"+
        "slips "+nm+" coins in your money purse and takes the spike.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
