inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("behir");
set_short("Behir");
set_long("This is a snake-like reptilian monster with a dozen legs.  It looks\n" +
        "like it is a little young.\n");
set_al(65);
set_level(12);
set_wc(13);
set_ac(8);
set_ac_bonus(5);
set_hp(150);
set_aggressive(0);
}
 
