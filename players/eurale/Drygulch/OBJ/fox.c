/*  This pelt is an adaption of pelt.c belonging to Mythos  */
/*  and is used with his permission.... 8/28/96  */

inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pelt");
    set_alias("fur");
    set_short("A beautiful fox pelt");
set_long(
	"  A beautiful and thick fox pelt trapped high in the mountains. \n"+
	"You may want to 'sell to trader'. \n");
    set_weight(4);
    set_value(550);
}

init() {
  ::init();
  add_action("ssell","sell");
}

ssell(str) {
int nm;
  if(str == "to trader") {
  nm = 400 + random(150);
  write("You sell the pelt to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
