inherit "obj/monster";

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("nurse");
    set_level(9);
    set_wc(13);
    set_ac(7);
    set_short("A pretty nurse");
    set_long("A very pretty nurse who is selling poppies from a tray\n"+
             "And though she feels as if she's in a play\n"+
              "She is anyway !\n");
    set_chance(30);
    set_spell_dam(20);
    set_spell_mess2("The nurse shakes a poppy at you and you begin to get very sleepy...\n");
}
