inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A drifting cardboard sign");
   set_long("You might want to 'read' the sign.\n");
   set_name("sign");

   set_smell("The sign smells like cardboard.\n");
   set_taste("The sign tastes like diapers!\n");
}

init() 
{
    ::init();

    add_action("on_read","read");
}

on_read(str) 
{
    if(!str || str != "sign") return 0;
    cat("/players/mizan/etheriel/environs/text/GUILD_SIGN");
    return 1;
}

