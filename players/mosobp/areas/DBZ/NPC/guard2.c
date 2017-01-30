inherit "obj/monster";
reset(arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("guard");
set_alias("saiyan");
    set_level(69);
    set_al(-500);
    set_short("Saiyan Palace Guard");
    set_long(
"This is a Saiyan Elite fighter. He is both deadly and fierce, one not to be tak
en lightly.\n");
add_armor("/players/mosobp/areas/DBZ/OBJ/ggloves.c");
add_armor("/players/mosobp/areas/DBZ/OBJ/helmet.c");
set_block_exit(({"north"}));
}
