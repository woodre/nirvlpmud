/*  a black wolf pelt  */

inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pelt");
    set_alias("fur");
    set_short("A beautiful black pelt");
set_long(
	"  A pelt taken from the hideous black wolves of the caves of \n"+
	"Drygulch.  A prized possession, you may want to 'sell to trader'. \n");
    set_weight(4);
    set_value(1900);
}

init() {
  ::init();
  add_action("ssell","sell");
}

ssell(str) {
int nm;
  if(str == "to trader") {
  nm = 1800 + random(600);
  write("You sell the pelt to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
