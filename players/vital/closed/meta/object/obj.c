/******************************************************************************
 *  File:           obj.c
 *  Function:       Meta guild object
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         25/01/2002
 *  Notes:          This is the original proto-guild object from the
 *                  mind of Vital
 *  Change History: Began commenting the functions, 25/04/2004
 *****************************************************************************/


#include "../inc/def.h"     /* Guild Definitions File */

inherit "/players/vital/closed/meta/lib/query_set.c";

mapping Houses;             /* Might want to save this at some point */
                            /* These are stored as House:ID# */

/******************************************************************************
 *  Function:   load_houses()
 *  Description:Call Function Daemon to load this members houses into Houses
 *  Returns:    void
 *****************************************************************************/
void
load_houses()
{
    Houses = FUND->load_houses(this_object());
}

/******************************************************************************
 *  Function:   reset
 *  Description:Sets up the arrays/mappings.
 *****************************************************************************/
void
reset(int arg)
{
    if (environment() && (string)environment()->query_real_name())
        restore_object(SAVE + environment()->query_real_name());
    load_houses();
    if(arg) return;
    Houses = ([ ]);
    if (environment() && (string)environment()->query_real_name())
        save_object(SAVE + environment()->query_real_name());
}

/******************************************************************************
 *  Function:   init()
 *  Description:With each change to environment(this_object()), login_object()
 *              is called, and actions existing within the Cmds mapping are
 *              loaded
 *****************************************************************************/
void
init()
{
    int i;
    string *k;

    if(environment() && (string)environment()->query_real_name())
    {
        add_action("list_houses", "membership");
        add_action("member_house","member");
        add_action("add_house", "add_house");
    }
}

/******************************************************************************
 *  Function:   id(string str)
 *  Description:This is what you can refer to the object as!
 *  Arguments:  "str" is what someone types in
 *  Returns:    true if "str" matches defined id
 *****************************************************************************/
status
id(string str)
{
    return (str == GUILD_ID || str == ALT_GID);
}

/******************************************************************************
 *  Function:   drop()
 *  Description:To drop the object or Not drop the object
 *  Returns:    1 if unable to drop it, 0 if droppable
 *****************************************************************************/
status
drop()
{
    return 1;
}

/******************************************************************************
 *  Function:   get()
 *  Description:To get or Not to get the object
 *  Returns:    1 if unable to get it, 0 if gettable
 *****************************************************************************/
status
get()
{
    return 1;
}

/******************************************************************************
 *  Function:   psychic_suicide()
 *  Description:Death by mindlessness. Called by some spells when guild
 *              member doesn't have enough power.
 *****************************************************************************/
void
psychic_suicide()
{
    string name;
    if (environment() && (string)environment()->query_real_name())
    {
        name = (string)environment()->query_real_name();
        FUND->psychic_suicide(name);
    }
}

/******************************************************************************
 *  Function:   list_houses()
 *  Description:Call the function daemon to figure out which Houses this
 *              object is a member of
 *  Returns:    string of comma separated houses.
 *****************************************************************************/
string
list_houses()
{
    return FUND->list_houses(Houses);
}

/******************************************************************************
 *  Function:   query_houses()
 *  Description:What houses is the object a member of
 *  Returns:    mapping of membership in a House:ID# format
 *****************************************************************************/
mapping
query_houses()
{
    return Houses;
}

/******************************************************************************
 *  Function:   member_house(string house)
 *  Description:A check for the membership of in house
 *  Arguments:  string name of house to check for
 *  Returns:    int ID# of house if member and 0 if not.
 *****************************************************************************/
status
member_house(string house)
{
    return (Houses[house]);
}
