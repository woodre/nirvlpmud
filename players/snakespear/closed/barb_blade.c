/*
 * Kept in a separate file so the weapon won't lose its special if saved
 */
#pragma strict_types
#include "/players/snakespear/closed/ansi.h"
inherit "obj/weapon";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Barbarian's DeathBlade");
    set_alias("blade");
    set_short(HIR+"Barbarian's "+HIW+"B"+HIM+"l"+HIG+"a"+HIB+"d"+HIC+"e"+HIR+" of "+GRY+"Death"+NORM);
    set_long("A finely made blade, it's a weapon of death, that is very sharp.\n");
    set_class(40);
    set_hit_func(this_object());
    set_weight(3);
    set_value(0);
}

mixed weapon_hit(object opponent) {
    if (random(100) < 50) {
        write(HIW+"The "+GRY+"blade"+HIW+" effortlessly glides through your opponent's intestines.\n"+NORM);
        say(HIR+this_player()->query_name()+"'s blade "+BLINK+"blurs"+HIR+" as it slashes through its victim's flesh.\n"+NORM);
        return 1;
    }
}
