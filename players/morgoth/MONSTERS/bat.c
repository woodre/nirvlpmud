inherit "obj/monster";

reset(arg)
{
    if (arg) return;
    ::reset(arg);
    set_name("bat");
    set_level(8);
    set_al(-50);
    set_short("A nasty little bat");
    set_long("An evil denizen of Strawberry Fields\n"+
             "The bat's claws and teeth are quite sharp.\n");
    set_wc(12);
    set_ac(7);
    set_aggressive(1);
    set_chat_chance(15);
    load_chat("EEP EEP !\n");
    set_chance(15);
    set_spell_mess2("A bat gets tangled in your hair !!\n");
    set_spell_dam(5);
}
