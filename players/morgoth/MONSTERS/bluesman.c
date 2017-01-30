inherit "obj/monster";

reset(arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("bluesman");
    set_alias("man");
    set_short("A Blues Man");
    set_long("A lean tall man dressed in dark clothing\n"+
             "and wearing sun glasses and a wide brim hat.\n"+
             "He is playing some mean licks on his sax !!\n");
    set_level(14);
    set_ac(11);
    set_wc(18);
    set_chance(20);
    set_spell_mess1("The Blues Man raises his sax and blasts you with a  blues riff !!!\n");
    set_spell_mess2("A blue mist streams out of the sax and covers you with the Blues !\n");
    set_spell_dam(15);
    set_chat_chance(20);
    load_chat("The Blues Man says: I took a train to Tupelo but ended up here !\n");
    load_chat("The Blues Man asks: Have you seen my woman ??\n");
    load_chat("The Blues Man says: You're damn right I got the blues !\n");
    set_a_chat_chance(20);
    load_a_chat("The Blues Man says: Don't mess with my sax or I'll dust your ass off !\n");
    load_a_chat("The Blues Man thinks: I'm gonna smoke this SOB !\n");
}
