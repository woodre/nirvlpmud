inherit"obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_chat_chance(40);
load_chat("Shop Keeper says: Hello, how can I help you today?\n");
load_chat("Shop Keeper says: I have lots of quality items from the surface.\n");
set_name("keeper");
set_alias("shop keeper");
set_short("Shop keeper");
set_long(
"A very well dressed drow this guy is.  He eyes you closely to make \n"
+ "sure you dont take anything. He is very cheerful just like the\n"
+ "guys you can't get rid of in a store.\n");
set_level(15);
set_al(-400);
set_race("drow");
set_hp(230);
set_wc(20);
set_ac(12);
gold = clone_object("obj/money");
 gold->set_money(random(200)+800);
 move_object(gold,this_object());
}
