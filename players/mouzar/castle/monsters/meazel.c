inherit "obj/monster.c";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("meazel");
set_short("Meazel");
set_long("This is humanoid is slightly smaller that a human and it's skin is\n" +
        "is a dark green color.");
set_al(0);
set_level(8);
set_wc(12);
set_ac(7);
set_hp(120);
coins=clone_object("obj/money");
coins->set_money(600);
move_object(coins,this_object());
set_aggressive(0);
}
 
