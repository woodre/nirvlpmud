inherit "/obj/monster";

void reset(int arg)
{
    if(arg) return;
    ::reset();
    is_npc = 0;  /* mark it as not an npc */
    set_name("old woman");
    set_alias("woman");
    set_alt_name("chair");
    set_gender("female");
    set_race("spirit");
    set_short("An old woman rocking in a chair");
    set_long("\
Fill this in later...\n\
:)\n");
    set_chat_chance(10);
    load_chat("hi hi hi hi hi\n");
    load_chat("The hills are alive.. with the sound of music. ugh.\n");
}
