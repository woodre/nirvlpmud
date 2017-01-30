#include "../definitions.h"
string *my_sheep_names;

get() {
    return 0;
}
short() {
    return "A server named (sheep)";
}
id(str) {
    return str == "sheep" || str == "server";
}


string get_sheep_name() {
    return my_sheep_names[random(sizeof(my_sheep_names))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_sheep_names = ( {
            "Busty",
            "Ron Jeremy",
            "Muammar Gaddafi",
            "Federico Fellini",
            "Buck Angel",
            "Alec Baldwin",
            "Al Parker",
            "Adam Rom",
            "Aaron James",
            "Ashley Ryder",
            "Cybersocket",
            "Hot Rascal",
            "Grabby Hammers",
            "Golden Dickie",
            "Bobble Blake",
            "Bo Summers",
            "Caesar",
            "Probie",
            "Chip Daniels",
            "Gender Bender",
            "David Fleetwood",
            "Anal Reflex",
            "Hot Earwax",
            "David Rockmore",
            "Christian XXX",
            "Raging Stallion",
            "Glenn Steers",
            "Erik Stryker",
            "Jackie Beat",
            "Crotch Rocket",
            "Lady Bunny",
            "Logan Reed",
            "Kip Noll",
            "Johnny Rammer",
            "Hot Rod",
            "Dirty Sanchez",
            "Riding Crop",
            "Maxx Diesel",
            "Jean Poop Van Damme",
            "Ricky Sinz",
            "Roman Heart",
            "Sam Page",
            "Short Storm",
            "Tai Chi Larue",
            "Tyler Riggz",
            "Titof",
            "Tag Adams",
            "Homo Phobic",
            "Van Darkholme",
            "Zak Spears",

            "Wet Pockets",
            "Fudge Tunnel",
            "Dirty Hallways",
            "Back Door",
            "Pick-Me-Up",
            "Double Barrelled",
            "Chop Sockem",
            "Duke Nucular",


        });
    }
}

