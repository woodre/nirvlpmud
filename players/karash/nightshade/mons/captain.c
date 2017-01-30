inherit "obj/monster";
object ob, weap, gold, duh, penis;
reset(arg)
{
::reset(arg);
if(arg) return;
set_alias("cassana");
set_name("captain");
set_short("Cassana Praxis, Captain of the Watch");
set_long(
"This is Cassana Praxis, an elven female and captain of the town watch.\n"+
"She has lived many centuries but still looks rather young. Of course\n"+
"only through magic could she stay so young. Another curious feature\n"+
"you notice about her, is that she is almost seven feet tall! Once again\n"+
"only through magic could she have attained such a height. Strapped on\n"+
"her back is Drow Cleaver, a magically enchanted axe. It is her most\n"+
"prized posession and she is quite capable of keeping it that way. She\n"+
"is very hard to kill. You have been warned.\n");
set_level(20);
set_hp(1000);
set_wc(30);
set_ac(17);
set_chance(30);
set_spell_dam(10);
set_spell_mess1("The captain of the watch executes a blinding double attack!");
set_spell_mess2("You are hit from all sides as the captain executes a blurring double attack!");
ob=clone_object("players/nightshade/weap/drow_cleaver");
move_object(ob, this_object());
weap=clone_object("players/nightshade/armor/capt_armor");
move_object(weap, this_object());
duh=clone_object("players/nightshade/armor/capt_cloak");
move_object(duh, this_object());
penis=clone_object("players/nightshade/armor/capt_shield");
move_object(penis, this_object());
gold=clone_object("obj/money");
gold->set_money(2000);
move_object(gold, this_object());
}
