inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hofflik");
set_short("Hofflik Kaese");
set_long("Hofflik is the master cheesemaker here.  He is highly credited for\n" +
         "his white cheese 'Lindenbrook'.  He looks very pissed.\n");
set_al(0);
set_level(3);
set_wc(7);
set_ac(4);
set_hp(45);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(100);
move_object(coins,this_object());
}
 
