#include "../definitions.h"
string *my_snake_names;
string *my_snake_titles;
string *my_snake_surnames;
string *my_snake_postfixes;
string *my_snake_insults;

get() {
    return 0;
}
short() {
    return "A server named (snake)";
}
id(str) {
    return str == "snake" || str == "server";
}


string get_snake_name() {
    return my_snake_names[random(sizeof(my_snake_names))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_snake_names = ( {
            "Higgins",
            "Baldrick",
	    "Kenworth",
        });

        my_snake_titles = ({
            "Lord",
            "Professor",
            "Doctor",
            "Duke",
            "Prince",
            "Sir",
        });
 
	/* CREDITS: a bunch of these come from the following sources:
	 */
        my_snake_insults = ({

	});


    }
}
