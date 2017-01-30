inherit "/players/mizan/core/armor.c";

reset(arg) 
{

    ::reset(arg);
    if(arg) return;

	set_name("Viking helmet");
	set_short("A Viking helmet (with horns!)");

	set_long("This is a fairly massive Viking helmet with horns!\n"+
             "Okay, so the horns may be historically inaccurate but\n"+
             "it still does little to take away the hilarously frightening\n"+
             "effect of someone charging at you while wearing one of these.\n");

	set_value(1500);
	set_ac(2);
	set_type("helmet");
	set_alias("helm");
    set_weight(2);
    set_size(6);

    /* this object is limited in number! */
    set_limited_issue(1);
    /* only two at a time can be cloned in the game at all */
    set_limited_issue_count(10);

}

