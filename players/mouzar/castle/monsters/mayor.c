inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("mayor");
set_short("Mayor Fairweather Montajay");
set_long("The beautiful Mayor of Lindendale.  She looks like she knows how\n"+
         "to fight.\n");
set_al(0);
set_level(4);
set_wc(9);
set_ac(4);
set_hp(60);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(150);
move_object(coins,this_object());
}
 
