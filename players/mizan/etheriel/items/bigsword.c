inherit "players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("sword");
    set_long("This is a really, really, REALLY BIG sword.\n"+
	"It's for those people who think size really matters.\n");
    set_short("A really BIG sword");
    set_class(17);
    set_value(1000);
    set_alias("big sword");
    set_weight(5);

    set_read("The words 'I LOVE TOM HANKS' is scratchittied into the blade. DAMN that is freaky...\n");
    set_smell("The sword smells a lot like rotten tuna.\n");
    set_type("sword");
    set_taste("The hilt of the sword really tastes quite like... cheese? No. Sausages.\n");
}


