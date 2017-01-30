inherit "obj/monster";
object gold;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Sentry");
set_level(15);
set_hp(550);
set_ac(16);
set_wc(19);
set_al(250);
set_alias("sentry");
set_short("Sentry");
set_long("A mechanical Sentry that was placed here to kill all Zentradis' who try to go through...it still looks active.\n");
set_aggressive(1);
set_a_chat_chance(15);
load_a_chat("Sentry shouts: You player's make me laugh! You cannot fight me!\n");
gold=clone_object("obj/money");
gold->set_money(random(800)+1000);
move_object(gold, this_object());
}
