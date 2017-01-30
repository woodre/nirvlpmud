/*  The heal seller  */

#define TP this_player()
inherit "obj/monster";
reset(arg) {

object gold;
object nug;
object buyer;

::reset(arg);
if(arg) return;
set_name("gabby");
set_race("human");
set_short("Gabby Hayes");
set_alias("hayes");
set_long(
	"  Gabby is a weathered and tough old geezer.  He's lived alone \n"+
	"out here for many years prospecting for gold and mixing up healing \n"+
	"potions for whatever happened to ail him.  He's willing to share \n"+
	"his remedies if you [inquire] of him.  Should you find anything \n"+
	"that suits your fancy, just [purchase] a bottle or strip.  Don't \n"+
	"underestimate this old man, he may fool you. \n");
set_level(20);
set_hp(950);
set_al(0);
set_wc(31);
set_ac(20);
set_heal(5,5);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
  load_chat("Gabby says:  What can I do for you, young fella? \n");

set_chance(8);
set_spell_dam(50);
set_spell_mess1(
  "Gabby grabs a rotgut bottle and hits his attacker upside the head!\n");
set_spell_mess2(
  "Gabby grabs a rotgut bottle and hits you upside the head!\n");

gold = clone_object("obj/money");
gold->set_money(random(10)+10);
move_object(gold,this_object());
}

init() {
add_action("inquire","inquire");
add_action("purchase","purchase");
}

inquire() {
  write("Gabby scratches his chin and says... \n"+
	"  I've been mixing these concoctions for many years now and \n"+
	"here's what I figure works the best....  I got lots so just \n"+
	"purchase what you'd like.... \n"+
	"  \n"+
	"           rotgut              840 coins\n"+
	"\n");
  return 1; }

purchase(str) {
object item;
int value, m, heavey;
m = 0;

if(str == "rotgut") {
  item = clone_object("players/eurale/Drygulch/OBJ/rotgut.c");
  value = 840;
  m = 1; }
if(m) {
if(this_player()->query_money() <value) {
  write("You do not have enough to purchase this item! \n");
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
write("You got too much in your saddle bags already, pardner!\n");
return 1; }

/*  take the coins from the player  */
this_player()->add_money(-value);

move_object(item,this_player());
say(capitalize(this_player()->query_real_name())+" purchases a "+str+" \n"); }
else {
  write("That item cannot be purchased here. \n"); }
return 1;
}
