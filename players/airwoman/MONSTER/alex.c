/* Changed from lev.18 to 12, ac16 to 10, wc23 to 18, aggressive 0 to 1
   - Snow */
inherit "obj/monster";
object orange;
reset(arg){
    ::reset(arg);
	if (!arg){
    set_name("Alex");
     set_short("Alex");
     set_alias("alex");
     set_long("A teenage hoodlum..a little droogie who rapes, kills, and plunders all.\n"+
     "It is best to kill this boy rather than let him live to grow up.\n");
	set_level(12);
	set_ac(10);
	set_al(0);
	set_wc(18);
	set_aggressive(1);
        load_chat("Joyboy says:  Hmmm... you still lack a bit of color.\n"); 
	load_a_chat("Joyboy tries to poke his venomous needle to embalm you.\n");
  orange=clone_object("players/airwoman/food/orange.c");
  move_object(orange, this_object());
}
}
