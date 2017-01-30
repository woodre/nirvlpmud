inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bear");
set_alias("teddy");
set_short("A Ferocious Teddy Bear");
set_long("Somebody has definitely treated this teddy poorly...\n");
set_al(0);
set_level(4);
set_wc(5);
set_hp(30);
set_ac(1);
set_aggressive(0);
}
