/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("canine");
set_short("golden canine teeth");
set_alias("teeth");
set_long(
	"  These large golden canine teeth come from the dangerous and \n"+
	"deadly hellhounds that guard the devil himself.  These animals \n"+
	"are among his favorites.  You might 'trade to devil' to return \n"+
	"the prized teeth. \n");
    set_weight(1);
set_value(1000);
}

init() {
  ::init();
  add_action("trade","trade"); }

trade(str) {
int m;
  if(str == "to devil") {
  m = 6000 + random(2000);
  write("You trade the golden canine teeth to the devil.\n");
  write("He gives you "+m+" for them and laughs.. \n");
  this_player()->add_money(m);
  destruct(this_object());
  return 1; }
}
