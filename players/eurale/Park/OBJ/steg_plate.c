/*  Changed to barterable item 8/17/02 - Eurale  */

#define ETP environment(this_player())
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("plate");
set_short("stegosaurus plate");
set_long(
	"This solid stegosaurus plate was part of the animal's\n"+
	"protection and is valued by treasure hunters.  You can\n"+
	"always 'barter' with it.\n");
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
if(str == "plate") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  nm = 4500 + random(450);
  write("You hand the stegosaurus plate to Sedjak and the bartering\n"+
        "begins.  When you finish, Sedjak hands you "+nm+" coins.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
