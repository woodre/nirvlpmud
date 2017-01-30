inherit "obj/monster";
reset(arg)
{
    ::reset(arg);
    if (arg) return;
set_name("king");
set_alias("vegeta");
    set_level(100);
    set_al(-1000);
    set_short("The King, Vegeta");
    set_long(
"This is the king of all Saiyans. You can tell by his build that he is powerful 
and agile.  He looks strong and proud of what he does, but has an evil look abou
t him.");
add_weapon("/players/mosobp/areas/DBZ/OBJ/ksword.c");
}
