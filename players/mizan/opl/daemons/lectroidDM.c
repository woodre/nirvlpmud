#include "../definitions.h"
string *my_lectroid_names;
string *my_lectroid_boss_names;
string *my_lectroid_quotes;
string *my_lectroid_boss_quotes;

get() {
    return 0;
}
short() {
    return "A server named (lectroid)";
}
id(str) {
    return str == "lectroid" || str == "server";
}


string get_lectroid_name() {
    return my_lectroid_names[random(sizeof(my_lectroid_names))];
}

string get_lectroid_boss_name() {
    return my_lectroid_boss_names[random(sizeof(my_lectroid_boss_names))];
}

string get_lectroid_quote() {
    return my_lectroid_quotes[random(sizeof(my_lectroid_quotes))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_lectroid_names = ( {
            "Abramstein",
            "Barnett",
            "Beez",
            "Bible Beater",
            "Bigboote",
            "Bilbobaggins",
            "Bilboggan",
            "Boxcar",
            "Camp",
            "Candice",
            "Careful Walker",
            "China Cymbals",
            "Chief Crier",
            "Cooper",
            "Coyote",
            "Dickson",
            "Door Bells",
            "Drop Sack",
            "Edwards",
            "Fish",
            "Fork",
            "Fledgling",
            "Georgiou",
            "Girly Man",
            "Gomez",
            "Grim",
            "Gun Plop",
            "Guardian",
            "Hot Balls",
            "Heineken",
            "Hero",
            "Hefner",
            "Icicle Boy",
            "Janeway",
            "Jeffries",
            "Jingle Box",
            "Jones",
            "Joseph",
            "Jacklone",
            "Kim Chi",
            "Lee",
            "Littlejohn",
            "Many Jars",
            "Milton",
            "Moammar",
            "Muammar",
            "Mud Head",
            "Nephew",
            "Norris Rustler",
            "Nolan",
            "O'Connor",
            "Okay",
            "Omar",
            "Onion",
            "Olives",
            "Pass Flat",
            "Pants",
            "Parrot",
            "Parapot",
            "Pimple Pusher",
            "Rajeesh",
            "Ready to Fly",
            "Repeat Dance",
            "Roberts",
            "Sandwich Meat",
            "Sin City",
            "Scott",
            "Smallberries",
            "Starbird",
            "Steam Pipe",
            "Steam Truck",
            "Take Cover",
            "Thorny Stick",
            "Two Horns",
            "Wing Pants",
            "Wood",
            "Wright",
            "Ya Ya",
            "Yorkshire",

        });

        my_lectroid_boss_names = ( {
            "Big Casino",
            "Whorfin",
            "Hector",
            "Raise Fish",
            "Good Grip",
            "Black Heart",
            "Stock Car",
            "Volcano",
            "Cous-cous",
        });

        my_lectroid_quotes = ( {
            "Let's go back up to my office and talk about this like two reasonable beings.",
            "Nineteen thirty-eight. Can you imagine what it must have been like then... then... then...",
            "Sealed with a curse as sharp as a knife. Doomed is your soul and damned is your life!",
            "They're only monkey-boys!",
            "Laugh-a while you can, monkey-boy.",
            "You are the weakest individual I ever know.",
            "It's not my goddamn planet. Understand, monkey boy?",
            "History is-a made at night. Character is what you are in the dark.",
            "Put the snot on the track!",
            "Lest we let this place become a zoo, not to mention a haven for gawkers.",
            "The only joy is the joy of duty. Work... work... work.",
            "Lithium is no longer available on credit.",
            "Why do I make it redwood! DID I ASK YOU?",
        });

        my_lectroid_boss_quotes = ( {
            "Home. Home is where you hang your hat!",
            "Blast a-damn!",
            "May I pass along my congratulations for your great interdimensional breakthrough. I am sure, in the miserable annals of the Earth, you will be duly enshrined!",
            "That's what it makes to go quickly!",
            "Barney, I'm going home... with my overthruster.",
            "Home... home is where you wear your hat... I feel so breakup, I wanna go home.",
            "BANZAI! I'LL-A SEE YOU IN-A HELL! ",
            "We are not in the Eighth dimension, we are over New Jersey. Hope is not lost.",
            "Will somebody turn off that gosh darn klaxon?",
            "Stupid monkey boys. You a-will be blasted to SAND!",
        });

    }
}

