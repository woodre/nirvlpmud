/*  a bearskin pelt  */
/*  and is used with his permission.... 8/28/96  */

inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("pelt");
    set_alias("fur");
set_short("A grizzly pelt");
set_long(
	"  This large Grizzly bear pelt came from one of nature's \n"+
	"wonders.  It is thick and well cared for. \n");
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
  nm = 750 + random(150);
  write("You sell the pelt to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
