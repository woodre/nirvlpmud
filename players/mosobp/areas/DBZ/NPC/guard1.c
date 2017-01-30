inherit "obj/monster";
reset(arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("guard");
set_alias("saiyan");
    set_level(60);
    set_al(-500);
    set_short("Saiyan Palace Guard");
    set_long(
      "This is a palace guard. He looks as though he was picked to guard the pal
ace for a reason. Pick your battle wisely.");
    set_block_exit(({ "up" }));
add_armor("/players/mosobp/areas/DBZ/OBJ/gboots.c");
add_armor("/players/mosobp/areas/DBZ/OBJ/shield.c");
}
