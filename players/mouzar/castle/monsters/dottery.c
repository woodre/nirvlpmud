inherit "obj/monster.c";
object armour, coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dottery");
set_short("Dottery Dale");
set_long("The old halfling woman who is responsable for all the wonderfull\n" +
         "baking you see here.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(120);
move_object(coins,this_object());
if(!present("apron")) {
armour = clone_object("players/mouzar/castle/armor/apron.c");
move_object(armour,this_object());
}
}
 
