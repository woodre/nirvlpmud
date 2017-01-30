#include "../definitions.h"
string *my_mob_names;
string *my_captain_names;
string *my_mob_chats;
string *my_mob_achats;
string *my_captain_chats;
string *my_captain_achats;
string *my_boss_chats;
string *my_boss_achats;

get() { return 0; }
short() { return "A server named (l3dm)"; }
id(str) { return str == "l3dm" || str == "server"; }


string get_mob_name() { return my_mob_names[random(sizeof(my_mob_names))]; }
string get_captain_name() { return my_captain_names[random(sizeof(my_captain_names))]; }

string get_mob_chat() { return my_mob_chats[random(sizeof(my_mob_chats))]; }
string get_mob_achat() { return my_mob_achats[random(sizeof(my_mob_achats))]; }

string get_captain_chat() { return my_captain_chats[random(sizeof(my_captain_chats))]; }
string get_captain_achat() { return my_captain_achats[random(sizeof(my_captain_achats))]; }

string get_boss_chat() { return my_boss_chats[random(sizeof(my_boss_chats))]; }
string get_boss_achat() { return my_boss_achats[random(sizeof(my_boss_achats))]; }

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if(!arg)
    {
	my_mob_names = ({
"Ankles",
"Blizzard",
"Butterbutt",
"Buttersaucy",
"Cloud",
"Fluffers",
"Juicy",
"Juicebooty",
"Saucy",
"Snowball",
"Snuggles",
"Wiggles",
"Wimples",
"Woof",
"Xylo",
"Zebra",
	});

        my_captain_names = ({
"Dolly",
"Icepick",
"Lambchop",
"Lambert",
"Range Maggot",
"Rumpypumpy",
"Ratbert",
        });


        my_mob_chats = ({
"I'm still traumatized. Every time I see Earwax, I cry a little inside.",
"I heard Earwax is demoting some of the other troops next week.",
"Sometimes, I wonder if life is really worth living...",
"Everything is so full of angst. Everything.",
"I just want to chew on grass and be left alone. Why are we fighting this war?",
"War freaking sucks, man.",

        });


        my_mob_achats = ({
"",
""
        });


        my_captain_chats = ({
"",
""
        });


        my_captain_achats = ({
"",
""
        });


        my_boss_chats = ({
"",
""
        });


        my_boss_achats = ({
"",
""
        });


    }
}

