inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("poppy");
    set_short("A beautifull poppy");
    set_value(100);
    set_weight(2);
}

init()
{
    add_action("smell_poppy", "smell");
}
smell_poppy(str)
{
    if ((!str) || !id(str)) return 0;
    write("You smell the sweet fragrance of the poppy.\n");
    return 1;
}
