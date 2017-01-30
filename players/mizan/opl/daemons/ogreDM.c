#include "../definitions.h"
#include "/obj/ansi.h"

string *my_ogre_names;
string *my_ogress_names;
string *my_insults;

get() {
    return 0;
}
short() {
    return "A server named (ogre)";
}
id(str) {
    return str == "ogre" || str == "server";
}


string get_name() {
    return my_ogre_names[random(sizeof(my_ogre_names))];
}

string get_ogress_name() { 
    return my_ogress_names[random(sizeof(my_ogress_names))];
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
        my_ogre_names = ( {
            "Elephant Smasher",
            "Bull Humper",
            "Tree Eater",
            "Ditch Maker",
            "Grunt Poop",
            "Stealthy Shitter",
            "Bad Stench",
            "Ox Smasher",
            "Tree Breaker",
            "Andrew Ogrestein",
            "Bill Ogreman",
            "Thor Ogresson",
            "Fat Butt",
            "Diesel Engine",
            "Norman Tractorplow",
            "Penis Van Lesbian",
            "Gunch Cruncher",
        });

        my_ogress_names = ({
            "Helga Hippostone",
            "Rita Rhino",
            "Ugly Ursula",
            "Hill Potatomama",
            "Hogapotamus",
            "Wendy Wench Pickup Truck",
            "Olga Stoneplow",
            "Natalia Oakenplow",
            "Wheat Thresher",
            "Olga Limpdick",
            "Minka Mammoth",
        });

        my_insults = ({
"screams: " + HIG + "You filthy, rotten humans!",
"screams: " + HIG + "I'm sick and tired of you people dicking us over!",
"cries: " + HIG + "The goddamn circus never ends, does it?!",
"screams: " + HIG + "You stupid humans have no COJONES!",
"says: " + HIG + "Is that all you got?! Bring it, you blockheads!",
"says: " + HIG + "Go kill some Beanos instead, you assholes!",
"grumbles: " + HIG + "I don't get paid enough for this goddamn job...",
"screams: " + HIG + "You damn people are why I am poor! DIE! DIE!",
"mumbles: " + HIG + "You stupid pigs breed like rabbits...",
"mumbles: " + HIG + "I could cut your throats *snap* just like that...",
"mumbles: " + HIG + "You humans have no business being here.",
"mumbles: " + HIG + "I hope you just die already.",
"mumbles: " + HIG + "Greasy pigbags.",
"mumbles: " + HIG + "Hey! How does Hell function when you assholes are up here?",
"grumbles about something or another.",
"stares at you menacingly.",
"burps rudely.",
        });
    }
}

