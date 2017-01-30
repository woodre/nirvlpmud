#include "../definitions.h"

get() {
    return 0;
}
short() {
    return "A server named (stats)";
}
id(str) {
    return str == "stats" || str == "server";
}


/*
string get_name() {
    return my_names[random(sizeof(my_names))];
}

string get_insult() {
    return my_insults[random(sizeof(my_insults))];
}
*/

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {

    }
}

int get_level_weak() { return 19; }
int get_hp_weak() { return 800; }
int get_gold_weak() { return (1500 + random(1000)); }
int get_wc_weak() { return 50; }
int get_ac_weak() { return 25; }
int get_hp_bonus_weak() { return 1000 + random(500); }

/* occasionally, we throw EASY monsters a curveball in the form of
 * a WC boost. */
int get_level_easy() { return 25; }
int get_hp_easy() { return 3000; }
int get_gold_easy() { return (4500 + random(1000)); }
int get_wc_easy() {
    if(1 == random(1)) return 110 + random(30);
    else return 70 + random(10); 
}
int get_ac_easy() { return 45; }
int get_hp_bonus_easy() { return 1750 + random(750); }

/* same rule applies for mediums... once in a while, some of the
 * respawns are badass */
int get_level_medium() { return 27; }
int get_hp_medium() { return 5000; }
int get_gold_medium() { return (7500 + random(1000)); }
int get_wc_medium() { 
    if(1 == random(10)) return 160 + random(30);
    else return 80 + random(15); 
}
int get_ac_medium() { return 45 + random(10); }
int get_hp_bonus_medium() { return 1500 + random(700); }

/* For hard monsters, they get a boost in HP rather than WC.
 */
int get_level_hard() { return 29; }
int get_hp_hard() {
    if(1 == random(6)) return 15000; 
    else return 10000;
}
int get_gold_hard() { return (12000 + random(2000)); }
int get_wc_hard() { return 150; }
int get_ac_hard() { return 55 + random(20); }
int get_hp_bonus_hard() { return 1500 + random(1000); }
