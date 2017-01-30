/*  Buffalo hide adapted from Mythos pelt.c with permission */

inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("hide");
	set_short("A large buffalo hide");
    set_weight(4);
set_long(
	"  This large and scrapped buffalo hide will provide shelter \n"+
	"or clothing.  You might want to 'sell to trader'.\n");
    set_value(100);
}

init() {
  ::init();
  add_action("ssell","sell");
}

ssell(str) {
int nm;
  if(str == "to trader") {
  nm = 400 + random(100);
  write("You sell the hide to a trader\n");
  write("He gives you "+nm+" for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
