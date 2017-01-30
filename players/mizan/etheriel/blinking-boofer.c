#include "/players/mizan/esc.h"
#define BLINK ESC +"[0m"+ESC +"[1m"+ESC +"[5m"+ESC +"[32m"+ESC +"[40m"
#define UNBLINK ESC+"[0m"

inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Boofer");
    set_race("boofer");
    set_ep(600000);
    set_alias("boofer");
    set_short(BLINK+"A blinking Boofer"+UNBLINK);
    set_long("  This is a Boofer. It is making all sorts of funny noises,\n"+
    "  and blinking with a violent fervor.\n");
    set_level(16);
    set_hp(440);
    set_al(100);
    set_wc(24);
    set_ac(14);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1(BLINK+"Boofer zoks you with a burst of silliness!"+UNBLINK);
    set_spell_mess2(BLINK+"Boofer flugs loudly and hits you with its wub!"+UNBLINK);
    set_chat_chance(20);
    load_chat(BLINK+"Boofer blinks loudly.\n"+UNBLINK);
    load_chat("Boofer fades into the environment.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    weapon=clone_object("players/mizan/etheriel/items/purple-stick.c");
    move_object(weapon, this_object());
    move_object(clone_object("players/mizan/etheriel/items/plyrblinker.c"), this_object());
    armor=clone_object("players/mizan/etheriel/items/spucksuit.c");
    move_object(armor, this_object());
}
