#include "../definitions.h"
string *my_turkey_names;
string *my_key_types;

get() {
    return 0;
}
short() {
    return "A server named (turkey)";
}
id(str) {
    return str == "turkey" || str == "server";
}


string get_turkey_name() {
    return my_turkey_names[random(sizeof(my_turkey_names))];
}

string get_key_types() {
    return my_key_types[random(sizeof(my_key_types))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {

        my_key_types = ({
            "medium-security",
            "mild-security",
            "secpass-a",
            "secpass-b",
            "secpass-n",
            "basic-security",
            "normal-security",
        });

        my_turkey_names = ( {
            "Lester",
            "Tickles",
            "Eldrick",
            "Ethridge",
            "Harvey",
            "Louis Butters III",
            "Bostwick",
            "Larry",
            "Eugene",
            "Georgie",
            "Fist Fucker",
            "Gary",
            "Mike",
	    "Hot Carl",
	    "Arnold",
	    "Devin Butters",
	    "Mister Funny Guy",
            "Old Man Stevie",
	    "Conan Smith",
	    "Clap Happy",
	    "Gregory",
	    "Danger Bird",
	    "Super Motorcycle",
            "Terminator Fowl",
	    "Johnson Eames",
            "Jeffrey",
	    "Rufus",
            "Jack",
            "Joop",
            "Curtis",
            "Mickey",
            "Rothwood",
            "Riley",
	    "Jake Strong Bow",
	    "Mike Sitting Bison",
            "Strong Bill Stone",
            "Anderson",
        });
    }
}


