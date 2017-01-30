inherit "obj/weapon";

reset(arg)
{
    ::reset(arg);
    set_name("sax");
    set_short("A Golden Saxophone");
    set_long("This golden saxophone was created by master\n"+
             "craftsman from a golden alloy harder than steel.  The sax fills you\n"+
           "with a sense of well being as you hold it.\n");
    set_class(5);
    set_weight(1);
    set_value(30);
}
