#include "../definitions.h"
#include "/obj/ansi.h"

string *my_names;
string *my_insults;

get() {
    return 0;
}
short() {
    return "A server named (postal)";
}
id(str) {
    return str == "postal" || str == "server";
}


string get_name() {
    return my_names[random(sizeof(my_names))];
}

string get_insult() {
    return my_insults[random(sizeof(my_insults))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_names = ( {
            "Dale",
            "Jarrett",
            "James",
            "Frank",
            "Perry",
            "Patrick",
	    "Pat",
            "Steve",
            "Warren",
            "Joe",
            "Tom",
            "Roy",
            "Lee",
            "Cliff",
            "Larry",
            "Mark",
            "Bruce",
            "Charlie",
            "Jesus",
            "Grant",
            "Kevin",
            "Bob",
        });

        my_insults = ({
            "chants: " + HIY + "USA! USA! USA!",
            "grumbles about something or another.",
            "stares at you menacingly.",
            "burps rudely.",
            "says: " + HIY + "I didn't get my goddamn raise!",
            "says: " + HIY + "I'm entitled to a raise, you goddamn assholes!",
            "says: " + HIY + "I have to work like a dog, and I don't get paid enough.",
            "says: " + HIY + "How about them unidentified flying objects?!",
            "says: " + HIY + "Why don't you go suck some ass.",
            "says: " + HIY + "Hey! You talking to me?",
            "says: " + HIY + "Come get your MAIL... Asshole!",
        });
    }
}

