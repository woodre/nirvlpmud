inherit "obj/monster.c";
object weapon, coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("maedar");
set_short("Maedar");
set_long("This is a muscular, hairless, male humanoid.  This is the male counterpart\n" +
        "to the medusae.  He lacks the petrifying gaze of his counterpart.\n");
set_al(0);
set_level(12);
set_wc(16);
set_ac(9);
set_hp(180);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(600);
move_object(coins,this_object());
if(!present("sword")) {
weapon = clone_object("/players/mouzar/castle/weapons/msword.c");
move_object(weapon,this_object());
}
}
 
