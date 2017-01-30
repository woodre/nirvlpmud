inherit "obj/monster";
reset(arg); {
    ::reset(arg);
    if (arg) return;
    set_name("fighter");
set_short("Saiyan Elite Fighter");
set_race("saiyan");
    set_level(30);
    set_al(-500);
    set_long(
"This is a Saiyan Elite fighter. He is both deadly and fierce, one not to be tak
en lightly.\n");
}
