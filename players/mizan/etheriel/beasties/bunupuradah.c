inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"

object curry, whipped, weapon;

reset(arg) 
{
    int n;
    set_heart_beat(1);
    ::reset(arg);
    if(!arg) 
    {
        set_ep(820039);
        set_name("bunupuradah");
        set_short("Bunupuradah");
        set_long("Bunupuradah is a mean looking dood (yes, 'dood'). He grins evilly\n"+
        "  as you enter the area. He is wielding a rather nasty knife, that seems\n"+
        "  like it could harm you greatly if it made contact with you.\n"+
        "Bunupuradah has a small red patch on his shirt.\n");
        set_level(17);
        set_hp(450);
        set_ac(14);
        set_wc(23);
        set_chat_chance(12);
        load_chat("Bunupuradah smiles stupidly.\n");
        load_chat("Bunupuradah points and laughs at you.\n");
        set_chance(20);
        set_spell_dam(25);
        set_spell_mess1("Bunupuradah beats you to a bloody pulp!\n");
        set_spell_mess2("Bunupuradah mashes you so hard it hurts just to see it!\n");
        weapon=clone_object("players/mizan/etheriel/items/bowie.c");
        move_object(weapon, this_object());
        curry = clone_object("players/mizan/etheriel/heals/currychicken.c");
        move_object(curry, this_object());
        whipped = clone_object("players/mizan/etheriel/heals/whipped.c");
        move_object(whipped, this_object());
    }
}
