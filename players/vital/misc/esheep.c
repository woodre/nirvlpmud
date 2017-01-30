/******************************************************************************
 *  File:           esheep.c
 *  Function:       This is an electronic sheep to follow players and bleat.
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         25/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#pragma strong_types
#pragma combine_strings

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "/obj/monster.c";

object On;
string Oname;

void
reset(status arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("fluffy");
    set_alias("lamb");
    set_alt_name("ewe");
    set_race("sheep");
    set_level(5);
    set_al(-500);
    set_wc(15);
    set_ac(random(500));
    set_hp(500+random(500)+random(500));
    set_gender("female");
    set_short("a sheep 2.0");
    set_long(
"  This is a little sheep that loves you very much. If you don't like \n\
sheep, perhaps you could try to run away from it. However, be aware \n\
that heep are very loving, attached creatures and this particular one \n\
thinks you are very cute. I really wouldn't suggest killing him.\n");
    load_chats(
        ({
        "A sheep says, \"Baaa.\"\n",
        "A fluffy sheep silently munches on some grass it manages to find.\n",
        "A sheep says, \"Bleh.\"\n",
        "A fluffy sheep looks like it could use a shearing.\n",
        "\"Baaa. Baaa.\"\n",
        })
    );
    set_a_chat_chance(25);
    set_chat_chance(25);
    load_a_chats( ({
        "A sheep says, \"Baaa. Why?\"\n",
        "A fluffy sheep nuzzles your leg.\n",
        "\n",
    }) );
    set_chance(15);
    set_spell_mess1("");
    set_spell_mess2("");
    set_spell_dam(15 + random(30));
    no_exp_value = 1;
    On = find_object("/obj/monster.c");
}

heart_beat()
{
    if (attacker_ob)
    {
        say("Why do you attack poor sheep?\n");
        return 1;
    }
    ::heart_beat();
}

void
set_on(string target)
{
    On = find_living(target);
    Oname = capitalize((string)On->query_real_name());
}

void
get_owner()
{
    string temp_name;
    remove_call_out("get_owner");
    if (On && (this_player() != On) ) temp_name = Oname;
    if (!On || this_player() == On) temp_name = "you";
    if (On && (environment(this_object()) != environment(On)) )
    {
        {
            move_object(this_object(),On);
            move_object(this_object(),environment(On));
            say("A beautiful sheep wanders in and nuzzles " + temp_name +
                " on the leg lovingly.\n");
        }
    }
    if (!On) destruct(this_object());
    call_out ("get_owner", 3);
}

string
short()
{
    if (On) short_desc = Oname + "'s little sheep";
    if (!On) short_desc = "a little sheep";
    return short_desc;
}

long()
{
    if (On && (this_player() != On) ) long_desc =
"  This is a little sheep that loves " + Oname + " very much. If you \
don't like \nsheep, perhaps you could try to run away from it. However, \
be aware \nthat sheep are very loving, attached creatures and this \
particular one \nthinks you are very cute. The powers that be really \
wouldn't suggest \nkilling him.\n";
    if (!On || this_player() == On) long_desc =
"  This is a little sheep that loves you very much. If you don't like \n\
sheep, perhaps you could try to run away from it. However, be aware \n\
that sheep are very loving, attached creatures and this particular one \n\
thinks you are very cute. The powers that be really wouldn't suggest \n\
killing him.\n";
    ::long();
}
