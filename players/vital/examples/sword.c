/******************************************************************************
 *  File:           sword.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			Started  11/23/03 at 9:27 PM [GMT+4].
 *  Notes:			
 *  Change History: 
 *****************************************************************************/

inherit "obj/weapon.c";

string *ids;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sword");
    set_alias("a sword");
    set_short("A Sword");
    set_long("This is an utterly generic sword.\n");
    set_type("sword");
    set_id( ({
        name_of_weapon, alias_name, type, "blade"
    }) );
    set_class(20);
    set_weight(1);
    set_value(0);
}

id(string str) {
    if(!ids) ids = ({ });
    if(member_array(str, ids)) return (member_array(str, ids) >= 0);
    return 1;
}

set_id(string *new_ids) {
    ids = new_ids;
}
