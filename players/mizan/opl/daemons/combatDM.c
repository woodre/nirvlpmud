/*****************************************************************************
 *      File:                   combatDM.c
 *      Function:               combat routines for core/monster.c
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "../definitions.h"
string *my_names;
string *my_insults;

get() {
    return 0;
}

short() {
    return "A server named (combat)";
}

id(str) {
    return str == "combat" || str == "server";
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

}

int do_room_hit(object monster,
                int base_damage,
                int random_damage,
                string damage_type,
                string monster_startmsg,
                string victim_tellmsg,
                string victim_roommsg,
                string victim_wimpymsg)
{
    object room;
    object ob, oc;
    int dam;

    if(!monster) return 0;

    room = environment(monster);
    if(!room) return 0;

    ob = first_inventory(room);

    tell_room(room, monster_startmsg);

    while(ob)
    {
        oc = next_inventory(ob);

        if(living(ob) &&
           ob != monster &&
           (ob->is_player() || ob->is_pet()))
        {
            if(1 == random(5))
            {
                /* we wimpy our target */
                tell_room(room, monster->query_name() + " " + victim_wimpymsg);
                ob->run_away();
            }
            else
            {
                tell_object(ob, victim_tellmsg);
                tell_room(room, ob->query_name() + " " + victim_roommsg);
                ob->hit_player(base_damage + random(random_damage), damage_type);
            }

        }

        ob = oc;
    }

    return 1;
}
