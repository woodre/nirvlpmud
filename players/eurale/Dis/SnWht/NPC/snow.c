
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("snow white");
set_alias("snow");
set_race("human");
set_short("Snow White");
set_long(
	"  Snow White was a beautiful lass with black tresses.  Her fair\n"+
	"skin, red lips and pleasant personality made her the envy of \n"+
	"the prince.  She has been relegated to live away from the queen\n"+
	"because of petty jealousy.\n");
set_hp(450);
set_level(18);
set_al(600);
set_wc(26);
set_aggressive(0);
set_ac(15);

set_chat_chance(20);
  load_chat("Snow White tidies up her room...whistling as she works. \n");
set_a_chat_chance(20);
  load_a_chat("Snow White screams: HELP! HELP! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+1000);
move_object(gold,this_object());
}
