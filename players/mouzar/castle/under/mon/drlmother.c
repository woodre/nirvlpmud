inherit"obj/monster";
object gold;
reset(arg) {
string chat_str;
string a_chat_str;
::reset(arg);
if(arg) return;
set_chat_chance(25);
set_a_chat_chance(35);
load_chat("Mother says:  One day i will have the #1 house of this city.\n");
load_chat("Mother says:  Tomorrow i will send another party to the surface to kill!\n");
load_chat("Mother says:  Lolth is the ultimate god of evil.\n");
load_chat("Mother shouts:  Where is my bastard of a son!  Lolth why have you cursed me\n with a male!\n");
load_a_chat("You are weakened by some unseen force\n");
load_a_chat("Mother shouts:  How dare you attack a matron mother\n");
load_a_chat("Mother shouts:  GUARDS!!!!!!!!!\n");
set_name("mother");
set_alias("matron");
set_short("Matron Mother");
set_long(
"This is a drow matron mother.  She holds one of the highest ranks in the \n"
+ "drow city.  She commands everyone in her house including her own house\n"
+ "guards.  You can see the lust for power writen all over her twisted face.\n");
set_level(20);
set_al(-900);
set_race("drow");
set_hp(500);
set_wc(30);
set_ac(17);
set_chance(10);
set_spell_dam(40);
set_spell_mess1("The mother summons a mist of deadly gas");
set_spell_mess2("You are consumed by deadly gas");
gold = clone_object("obj/money");
 gold->set_money(random(1000)+4000);
 move_object(gold,this_object());
}
