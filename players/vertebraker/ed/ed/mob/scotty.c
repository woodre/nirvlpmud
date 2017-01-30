#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("scotty");
    set_alias("kid");
    set_alt_name("college kid");
    set_race("human");
    set_short("A tall college kid");
    set_long(
    "Scotty is standing here with a makeshift club.  He looks entirely too\n"+
    "scared, and you get the feeling that something TERRIBLE has occurred here.\n"+
    "His furtive glances all around tip you off that something else may still\n"+
    "be lurking around- perhaps in the nearest shadow.  Scotty also has a\n"+
    "number of cuts on his head and arms, as well as blood on his face\n");
    set_gender("male");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(20);
    set_chat_chance(9);
    set_a_chat_chance(8);
    load_chat("Scotty looks forlorn.\n");
    load_chat("Scotty wipes away a tear.\n");
    load_chat("Scotty mumbles: Shelly...\n");
    load_chat("Scotty says:  If only we had listened to Cheryl...\n");
    load_a_chat("Scotty delivers a swift kick to your knee!\n");
    load_a_chat("Scotty wallops you over the head with the log!\n");
    load_a_chat("Scotty charges full-force into you!\n");
    enable_commands();
    }

init() {
    ::init();
}
heart_beat() {
object attacker;
    attacker = TO->query_attack();
    ::heart_beat();
    if(attacker) {
        tell_room(ENV(TO),
    "\nScotty pauses for a moment and yells, screaming in agonizing pain!\n"+
"He begins to SPEW hot green vomit from his mouth, his eyes rolling\n"+
" back into blazing "+HIR+"red"+NORM+" orbs of fire!  It is clear that\n"+
" this is now *NOT* Scott!\n\n");
    MOCO(ED1MOB+"evil_scotty"),ENV(attacker));
    destruct(TO);
        return 1; } }
