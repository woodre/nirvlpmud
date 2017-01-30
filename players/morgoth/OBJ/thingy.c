inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("thingy");
    set_short("A thingy");
    set_value(10);
    set_weight(1);
}
