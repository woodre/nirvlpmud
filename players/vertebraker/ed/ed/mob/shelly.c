#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("shelly");
    set_alias("student");
    set_alt_name("girl");
    set_race("human");
    set_short("A female college student");
    set_long(
    "Sleek, sexy, brown-haired Shelly is the girlfriend of Scott- She has all\n"+
    "the traits of a teenager in love - You can see it in her eyes.  Speaking\n"+
    "of her eyes, however... there seems to be something gleaming within 'em...\n"+
    "You wonder if this is who you think it should be?  It seems as though\n"+
    "another consciousness has taken over.\n");
    set_gender("female");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(20);
    set_chat_chance(9);
    set_a_chat_chance(8);
    load_chat("Shelly says: the book...\n");
    load_chat("Shelly says:  Zombies?  Don't make me laugh...\n");
    load_chat("Shelly says:  The way Scotty acts, its making me go to pieces!\n");
    enable_commands();
    }

heart_beat() {
object attacker;
    attacker = TO->query_attack();
    ::heart_beat();
    if(attacker) {
tell_room(ENV(TO),
     "\n\nShelly cackles maniacally...\n\n"+
BOLD+BLK+"Her entire body changes form!  You are utterly horrified at the result!\n\n"+NORM);
    destruct(TO);
    MOCO(ED1MOB+"evil_shelly"),ENV(attacker));
        return 1; } }
