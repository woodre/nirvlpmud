inherit "obj/monster.talk";
int i;
object coins, sword;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("elf");
set_short("A peaceful elf");
set_long("This is just a simple elf.  He is not around to really hurt anybody.\n");
set_al(100);
set_level(8);
set_wc(12);
set_hp(120);
set_ac(6);
set_aggressive(0);

coins = clone_object("obj/money");
coins->set_money(100+(random(200)));
move_object(coins,this_object());
i = random(10);
if (i<6) {
sword = clone_object("players/grimm/weapons/gen_sword");
move_object(sword,this_object());
}
}
