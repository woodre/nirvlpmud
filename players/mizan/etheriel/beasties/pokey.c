inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg)
{
    object gold, what;
    ::reset(arg);
    if(arg) return;
    set_name("pokey");
    set_race("pokey");
    set_short("Pokey the horse");
    set_long("This is Gumby's best friend, Pokey the horse. He too is made\n"+
    "entirely of clay, but instead of green, he's orange. There is\n"+
    "something in his tone of voice that expresses worry and fear of\n"+
    "the unknown...\n");
    set_level(13);
    set_hp(200);
    set_al(660);
    set_wc(17);
    set_ac(10);
    set_chat_chance(10);
    load_chat("Pokey complains: Gumby... there's no ground here!\n");
    load_chat("Pokey says: I don't like Boofers.\n");
    load_chat("Pokey says: It's nice but I really would'nt like to live here.\n");
    load_chat("Pokey exclaims: No, Mizan is not made out of clay.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(2)+10);
    move_object(gold,this_object());
    what=clone_object("players/mizan/etheriel/heals/cheesenub.c");
    move_object(what, this_object());
}
