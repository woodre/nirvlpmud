inherit "/players/mizan/bai/core/block.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("dirt");
    set_short("A block of dirt");
    set_long("This is a block of dirt.\n");
    set_level(1);
    set_hp(39);
    set_ac(0);
}
