inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg)
{
    object gold, what, what2;
    ::reset(arg);
    if(arg) return;
    set_name("gumby");
    set_race("gumby");
    set_short("Gumby");
    set_long("Gumby is a lovable green figure made entirely of what appears\n"+
    "to be... clay. He's not too outlandish or wacky compared to some of\n"+
    "other natives of this realm, but there's something just plain cool\n"+
    "about the way he carries himself, in a civilized, innocent manner.\n");
    set_level(13);
    set_hp(195);
    set_al(670);
    set_wc(17);
    set_ac(10);
    set_chance(20);
    set_spell_dam(4);
    set_spell_mess1("Gumby goes: Hey!");
    set_spell_mess2("Gumby absorbs your shot.");
    set_chat_chance(10);
    load_chat("Gumby exclaims: WOW! I loooove this place!\n");
    load_chat("Gumby asks: Don't you love it here, Pokey?\n");
    load_chat("Gumby smiles happily.\n");
    load_chat("Gumby says: Something said that Mizan is actually made of clay!\n");
    load_chat("Gumby asks: Do you think Mizan is made of clay too?\n");
    load_chat("Gumby exclaims: How neat would it be if he were just like us!\n");
    load_chat("Gumby says: We would have many more new friends to make...\n");
    gold=clone_object("obj/money");
    gold->set_money(2);
    move_object(gold, this_object());
    what=clone_object("players/mizan/etheriel/heals/lolly.c");
    move_object(what, this_object());
    what2=clone_object("players/mizan/etheriel/items/zokballs.c");
    move_object(what2, this_object());
}
