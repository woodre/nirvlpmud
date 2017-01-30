inherit"obj/monster";
reset(arg) {
object gold;
object armor;
object weapon;
::reset(arg);
if(arg) return;
chat_str = allocate(2);
load_chat("Orc says: ggrrriiill wwwrrrrrrttthhhh\n");
load_chat("Orc drools\n");
set_name("orc");
set_alias("ugly");
set_short("Orc");
set_long(
"This is one ugly beast.  It resemble primitive human with grey-green skin\n"
+ "covered with coarse hair.  It has a slightly stooped posture, a low\n"
+ "jutting forehead, and a snout instead of a nose.  It has pointy ears\n"
+ "and human eyes witha reddish tint to them.  It it about 6 1/2 feet tall.\n");
set_level(17);
set_al(-200);
set_race("orc");
set_hp(425);
set_wc(24);
set_ac(14);
set_aggressive(1);
set_random_pick(30);
gold = clone_object("obj/money");
 gold->set_money(20);
 move_object(gold,this_object());
armor = clone_object("/players/mouzar/castle/under/obj/orcloak");
 move_object(armor,this_object());
weapon = clone_object("/players/mouzar/castle/under/obj/orcaxe");
 move_object(weapon,this_object());
}
