inherit "obj/armor";

reset(arg)
{
::reset(arg) ;
set_short("Rod's jacket");
set_long("You are wearing Rod's jacket.  Rod is the Mc on the \n"+
"Price of Right, and he likes sequines.  If your parents could\n"+
"see you-they'ld be proud.\n");
set_ac(1);
set_weight(0);
set_value(10);
set_alias("jacket");
set_name("jacket");
set_type("shield");
}

