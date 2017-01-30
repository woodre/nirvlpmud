/* Annie Oakley */

inherit "obj/monster";
reset(arg) {
	object gold;
	::reset(arg);
	if(arg) return;
	set_name("annie");
	set_race("human");
	set_short("Annie Oakley");
set_alias("oakley");
set_long(
	"  Christened Phoebe Anne Oakley Mozee (1860-1926) and later\n"+
	"called 'Little Sure Shot,' she was a major star of Buffalo \n"+
	"Bill Cody's Wild West Show for 17 years.  Sharpshooter and \n"+
	"entertainer.  She was the source for 'Annie Get Your Gun.' \n");
	set_hp(220);
	set_level(14);
set_al(-50 + random(100));
	set_wc(18);
	set_ac(11);
	set_aggressive(0);
set_chat_chance(4);
load_chat("Annie whispers:  Wanna test your skill stranger? \n");
load_chat("Annie says:  I can shoot your eye out at 50 paces. \n");
	load_chat("Annie laughs at you.\n");
gold = clone_object("obj/money");
gold->set_money(random(100)+800);
move_object(gold,this_object());
}
