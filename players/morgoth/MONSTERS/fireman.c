inherit "obj/monster";
 
reset(arg)
{
    if (arg) return;
    ::reset(arg);
    set_name("fireman");
    set_level(15);
    set_al(-100);
    set_short("A fireman");
    set_long("In his pocket is a portrait of the queen.\n");
    set_ac(12);
    set_wc(20);
    set_chat_chance(13);
    load_chat("Fireman says: I like to keep my fire engine clean !\n");
    load_chat("Fireman says: It's a clean machine !\n");
}
