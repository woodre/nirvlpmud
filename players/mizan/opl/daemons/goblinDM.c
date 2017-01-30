#include "../definitions.h"
#include "/obj/ansi.h"

string *my_goblin_names;
string *my_insults;
string *my_knobgoblin_names;
string *my_knobgoblin_bully_names;

get() {
    return 0;
}
short() {
    return "A server named (goblin)";
}
id(str) {
    return str == "goblin" || str == "server";
}


string get_goblin_name() {
    return my_goblin_names[random(sizeof(my_goblin_names))];
}

string get_knobgoblin_name() {
    return my_knobgoblin_names[random(sizeof(my_knobgoblin_names))];
}

string get_knobgoblin_bully_name() {
    return my_knobgoblin_bully_names[random(sizeof(my_knobgoblin_bully_names))];
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
        my_goblin_names = ( {
            "Uruk-Poop",
	    "Stick Face",
	    "Meat Popsicle",
	    "Enik Boop",
            "Shagrat",
            "Strong Skull",
            "Rock Skull",
            "Bash Face",
            "Mister Wiggles",
	    "Strong Balls",
	    "Face Masher",
	    "Head Banger",
            "Kropp Ptoop",
	    "Agis",
	    "Gum Agar",
	    "Phenol Gropp",
	    "Barglebasher",
	    "Burgle",
            "Steam Fart",
            "Gonk",
            "Gruuk",
            "Flaargh",
            "Laaarm",
            "Teruk",
            "Fire Face",
            "Mudbutt",
	    "Hot Lunch",
	    "No Pants",
	    "Meat Bib",
	    "Drunk Smasher",
	    "Drunk Punch",
	    "Ho Bag",
            "Hrop Frung",
	    "Chan Li Hong",
	    "Druuk",
            "Fart Pop",
            "Hork Lamentor",
            "Flop Tits",
            "Guitar Solo",
            "Hulaaaaaaagrh",
            "Hraaaaagh",
            "Hulk Butt",
            "Drunk Hulk",
            "Pop Smash",
            "Bolo",
            "Mogro",
            "Cornhole",
            "Hak-Ptooey",
            "Flat Head",
        });

        my_knobgoblin_names = ({
            "Poop Stains",
            "Aborto",
            "Hand Jerk",
            "Bed Drips",
            "Backsplatter",
            "Linkdeath",
            "Dip Stick",
            "Meat Paste",
            "Anal Lube",
            "Cock Punch",
            "Dark Splat",
            "Dickless Dave",
            "Jingle Tits",
            "Nut Face",
            "Retardo",
            "Ass Puncher",
            "Crockpot Head",
            "Bug Eater",
            "Booger Fairy",
            "Shitpile",
            "Eunuch",
            "Faygo Drinker",
            "Dark Anal Stain",
            "Vomit Pie",
            "Vomit Cakes",
            "Deep Throat",
            "Nut Balls",
            "Meat Locker",
            "Browntown",
        });

        my_knobgoblin_bully_names = ({
            "Fist Pump",
            "Jerk Puncher", 
            "Face Smasher",
            "High Cholestorol",
            "Super Bully",
            "Throat Smasher",
            "Surprise Sex",
            "Angry Puncher",
            "Angry Kicker",
            "Hormonal Rage",
            "Testosterones",
            "Fist Dick",
            "Fisterman",
            "Gut Punch",
            "Ox Fucker",
            "Goat Paste",
            "Brain Smasher",
            "Cunt Puncher",
            "Balls",
            "Gooch McSamson",
            "Gray Matter",
            "Meat Grinder",
            "Power Joint",
            "Angle Grinder",
            "Vomit King",
            "Brake Face",
            "Break Face",
            "Ugly Farter",
            "Pasta Stealer",
            "Goat Stealer",
            "Drain Clog",
            "Mexican Shower",
            "American Fatty",
            "Grain Licker",
            "Boils",
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
            "farts in your general direction.",
            "burps rudely.",
            "screams: " + HIG + "Hey slack-ass! Get out of my goddamn way!",
            "screams: " + HIG + "You guys are suckers!",
            "screams: " + HIG + "You slack-ass shovelhead!",
        });
    }
}

