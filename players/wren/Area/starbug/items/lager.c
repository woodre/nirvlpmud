	/* listers lager */



inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("lager");
    add_alias("beer");
    add_alias("glass");
    add_alias("pint");
    set_short("A pint of lager.");
    set_long("This pint of beer has been out for awhile. Its questionable looking.\n");
    set_type("sips");
    set_msg("You guzzle the lager and gag. You cough up old cigar dibs. Gross.\n");
    set_msg2(" chokes on the lager. \n");
    add_cmd("drink");
    add_cmd("sip");
    set_heal(-10,0);
    set_charges(1);
    set_intox(1);
    set_value(5);
}

