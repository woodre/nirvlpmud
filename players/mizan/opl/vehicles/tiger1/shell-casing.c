inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_get(1);
    set_value(10);
    set_weight(2);
    set_name("casing");
    set_short("A large empty brass shell casing");
    set_long("This is a brass shell casing from what appears to be a very large munition.\n"+
             "It is scorched and covered with carbon deposits.\n"+
             "The words '88mm' appears on it.\n");
}

