/*  Changed to barterable item 8/17/02 - Eurale  */

#define ETP environment(this_player())
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("tooth");
set_short("tyrannosaurus tooth");
set_long(
  "This tooth from the ferocious and feared tyrannosaurus rex is\n"+
  "sharp and discolored from devouring its prey.  Many a treasure\n"+
  "hunter would pay a handsome price to get one of their very own.\n"+
  "You might just want to cash it.\n");
    set_weight(2);
    set_value(4600);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int nm;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "tooth") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  nm = 3600 + random(700);
  write("You hand the tyrannosaurus tooth to Sedjak.  He rolls it over\n"+
        "in his hands and says, 'Ahhh, a fine specimen, I'll make good\n"+
        "use of it' and he hands you "+nm+" coins.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
