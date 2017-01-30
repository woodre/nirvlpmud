inherit "obj/weapon";

reset(arg)
{
    ::reset(arg);
    if (!arg)
    {
        set_name("nightstick");
        set_long("This is an ordinary looking black wooden 'Police Special'\n"+
                 "nightstick. In some areas the black paint has chipped and worn\n"+
                 "off, and there are some dings and dents, but it is still perfectly\n"+
                 "useful for cracking someone's head in if needed.\n");
        set_short("A black 'Police Special' nightstick");
        set_class(13);
        set_value(250);
        set_alias("stick");
        set_weight(2);
    }
}
