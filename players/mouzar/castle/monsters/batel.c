inherit "obj/monster.c";
object coin;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("batel");
set_short("Dwilcath Batel");
set_long("Batel is the premier woodcarver of lindendale.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
coin=clone_object("obj/money");
coin->set_money(100);
}
 
