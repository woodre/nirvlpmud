inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("awl");
    set_short("An awl");
    set_long("A common carpenter's awl\n");
    set_value(10);
    set_weight(1);
}
