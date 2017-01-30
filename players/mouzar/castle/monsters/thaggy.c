inherit "obj/monster.c";
object weapon, coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("thaggypoo");
set_short("Thaggypoo the Half-Orc");
set_long("What a foul-smelling beast! What could any blonde see in this guy?\n" +
         "Please kill this chauvinist pig!\n");
set_al(-65);
set_level(11);
set_wc(18);
set_ac(8);
set_hp(213);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(500);
move_object(coins,this_object());
if(!present("blade")) {
weapon = clone_object("players/mouzar/castle/weapons/tgblade.c");
move_object(weapon,this_object());
}
}
 
