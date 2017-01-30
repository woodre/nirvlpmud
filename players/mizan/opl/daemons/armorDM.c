#include "../definitions.h"
string *my_transparasteel_armors;
string *my_corporate_armors;

get() {
    return 0;
}
short() {
    return "A server named (armor)";
}
id(str) {
    return str == "armor" || str == "server";
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {

        my_transparasteel_armors = ( {
            "transparasteel_armor",
            "transparasteel_amulet",
            "transparasteel_helm",
            "transparasteel_boots",
            "transparasteel_gloves",
            "transparasteel_chest",
            "transparasteel_shield",
            "transparasteel_misc",
            "transparasteel_pants",
            "transparasteel_ring",
            "transparasteel_underwear",
            "transparasteel_earring", 
            "transparasteel_bracers",
            "transparasteel_necklace",
            "transparasteel_cloak",
            "transparasteel_belt"
        });


        my_corporate_armors = ( {
            "corporate_armor",
            "corporate_amulet",
            "corporate_helm",
            "corporate_boots",
            "corporate_gloves",
            "corporate_chest",
            "corporate_shield",
            "corporate_misc",
            "corporate_pants",
            "corporate_ring",
            "corporate_underwear",
            "corporate_earring", 
            "corporate_bracers",
            "corporate_necklace",
            "corporate_cloak",
            "corporate_belt"
        });

    }
}

int check_transparasteel_full_set(object arg)
{
    object wearer;
    object ob;
    int i;

    if (!arg) return 0;
    wearer = environment(arg);

    if (!wearer || !living(wearer)) return 0;

    for (i = 0; i < sizeof(my_transparasteel_armors); i ++)
    {
        ob = present(my_transparasteel_armors[i], wearer);

        if (!ob || !ob->query_worn())
            return 0;
    }
    return 1;
}

int check_corporate_full_set(object arg)
{
    object wearer;
    object ob;
    int i;

    if (!arg) return 0;
    wearer = environment(arg);

    if (!wearer || !living(wearer)) return 0;

    for (i = 0; i < sizeof(my_corporate_armors); i ++)
    {
        ob = present(my_corporate_armors[i], wearer);

        if (!ob || !ob->query_worn())
            return 0;
    }
    return 1;
}

