inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sheriff");
set_short("Sheriff Greenspan");
set_long("This is a stocky warrior with grizzled sideburns.  This sheriff\n"+
         "looks like he can take anything that disturbs the peace.\n");
set_al(0);
set_level(4);
set_wc(8);
set_ac(4);
set_hp(60);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(150);
move_object(coins,this_object());
 
}
 
