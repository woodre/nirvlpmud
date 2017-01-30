#include "../definitions.h"
string *my_first_names;
string *my_nicknames;

get() {
    return 0;
}
short() {
    return "A server named (guido)";
}
id(str) {
    return str == "guido" || str == "server";
}


string get_first_name() {
    return my_first_names[random(sizeof(my_first_names))];
}

string get_nickname() {
    return my_nicknames[random(sizeof(my_nicknames))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_first_names = ( {
	    "Paulie",
            "Mikey",
            "Vinnie",
            "Ronnie",
            "Vinny",
            "Sammy",
            "Anthony",
            "Tony",
            "Richie",
            "Tommy",
            "Tommie",
            "Rocco",
            "Ennino",
            "Charlie",
        });

        my_nicknames = ( {
            "The Situation",
	    "B-Muscle",
            "Fist Pump",
            "The Hands",
            "The T-Bomb",
            "T-Bomb",
            "T-bag",
            "Juice Box",
            "The Body",
	    "Juice Springsteen",
            "Tan Jovi",
            "The Blowout",
            "Hot Bones",
            "The Operation",
            "The Doctor",
            "B-Train",
            "Lats",
            "The Deltoid",
            "Pecs",
            "The Pectorals",
            "Hard Hat",
            "B-Tan",
            "B-Hot",
            "The Sausage",
            "Orange Juice",
            "The Tricep",
            "Triceps",
            "B-Gel",
            "The Tan-talizer",
            "The Prince of Paramus",
            "The Prince of Teaneck",
            "The Prince of Trenton",
        });
    }
}

