/* Changed hps from 650 to 1500, lev. from 20 to 22, wc from 21 to 35
   money from random(500)+1050 to random(5000)+1050  -Snow */
inherit "obj/monster";
object gold, cannon;
int items;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Veritech");
set_alias("fighter");
set_short("Veritech Fighter");
set_long("A high-tech robot capable of transforming itself. It is the last remaining kind of its design since the battle with the Zentradis'.\n");
set_level(22);
set_hp(1500);
set_al(1000);
set_ac(25);
set_aggressive(0);
set_chance(35);
set_spell_mess1("The Veritech crushes you under him!!\n");
set_spell_mess2("The Veritech has struck you with a mighty blow!\n");
set_spell_dam(20);
set_chat_chance(30);
load_chat("Veritech says: The Battle is now over..Zentradis' have been defeated.\n");
load_chat("Veritech echoes: How can I help you?\n");
set_a_chat_chance(30);
load_a_chat("Veritech screams: Do you think you can defeat me?!?!\n");
load_a_chat("Veritech screams: This will be a way too easy kill!!\n");
gold=clone_object("obj/money");
gold->set_money(random(5000)+1050);
move_object(gold, this_object());
cannon=clone_object("players/cyrex/cannon");
move_object(cannon, this_object());
init_command("wield cannon");
/* Setting wc after wield  -Snow */
set_wc(35);
}
