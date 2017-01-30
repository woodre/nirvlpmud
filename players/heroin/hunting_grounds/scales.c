inherit "obj/armor";

reset(arg)
{
::reset(arg) ;
set_short("Alien exo-skeleton");
set_long("You are wearing a piece of the Aliens skeleton. Since\n"+
"you were barely able to penetrate it with your weapons, you are\n"+
"fairly confident in it's ability to protect you from harm.\n");
set_ac(4);
set_weight(5);
set_value(10000);
set_alias("skeleton");
set_name("skeleton");
set_type("armor");
}

/*  Set to ac 4 by Saber - ac 5 armor is NOT saveable.  */
