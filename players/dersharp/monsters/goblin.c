inherit "obj/monster";

reset(arg) {

string name;
object weapon, mrew;

::reset(arg);
if(arg)
        return;

        set_level(3);
        set_hp(45);
        set_name("goblin");
        set_short("A dirty Goblin");
        set_long("It's dirty, what did you expect??\n");
        set_race("goblin");
        set_al(-50);
        set_ac(5);
        set_wc(6);
        set_aggressive(0);
        set_rand_move(0);
   set_chat_chance(2);
   load_chat("Goblin looks at you suspiciously");
   weapon=clone_object("/players/dersharp/weapons/gobsword");
   move_object(weapon,this_object());
}
