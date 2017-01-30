#include "../definitions.h"
string *my_names;
string *my_desc;
string *my_style;
string *attack_pre;
string *attack_post;

get() {
    return 0;
}

short() {
    return "A server named (karate)";
}

id(str) {
    return str == "karate" || str == "server";
}


string get_name() {
    return my_names[random(sizeof(my_names))];
}


string get_desc() {
    return my_desc[random(sizeof(my_desc))];
}


string get_style() {
    return my_style[random(sizeof(my_style))];
}


string get_attack_pre() {
    return attack_pre[random(sizeof(attack_pre))];
}

string get_attack_post() {
    return attack_post[random(sizeof(attack_post))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_names = ( {
	    "Ken",
            "Golbi",
	    "Ginjiro",
            "Gokomatsu",
            "Hachiuma",
            "Haru",
            "Hideo",
	    "Hiro",
            "Hoshu",
            "Isamu",
            "Kanji",
            "Junichi",
            "Kenzo",
            "Genki",
            "Minoru",
	    "Ren",
            "Ryu",
	    "Bob",
	    "Michael",
	    "Sam",
	    "Ted",
	    "David",
            "Eric",
            "Vince",
            "John",
            "Jake",
            "Steve",
        });

        my_desc = ({
            "crouching",
            "sleeping",
	    "drunken",
            "aroused",
            "angry",
            "shameless",
            "northern",
            "southern",
            "eastern",
            "western",
            "eastwest",
            "imperial",
            "stoned",
        });
 
        my_style = ({
	    "rabbit",
	    "ox",
	    "tiger",
	    "dragon",
	    "mouse",
	    "volkswagen",
            "penis",
            "penis bird",
            "butcher knife",
            "fire hydrant",
            "meatloaf",
            "pooh bear",
            "wombat",
            "badger",
            "scorpion",
            "snake",
            "toad",
            "basilisk",
            "chicken", 
            "platypus",
            "fishnugget",
	});


        attack_pre = ({
            " strikes ",
            " smashes ",
            " beats ",
            " viciously kicks ",
            " fiercely punches ",
            " deftly punches ",
            " quickly punches ",
            " jabs ",
            " quickly jabs ",
            " multiple punches ",
            " multiple jabs ",
            " backpunches ",
            " chops ",
            " chop hits ",
            " crescent kicks ",
            " forward kicks ",
            " side kicks ",
            " jump kicks ",
            " jump elbows ",
            " knee smashes ",
            " whip kicks ",
            " double crescent kicks ",
            " double spinning kicks ",
            " spinning kicks ",
        });

        attack_post = ({
            " in the groin!\n",
            " in the face!\n",
            " in the chest!\n",
            " in the shoulder!\n",
            " in the ribs!\n",
            " in the neck!\n",
            " in the throat!\n",
            " in the ass!\n",
            " in the crotch!\n",
        });


    }
}

int get_hp()
{
    return 10000;
}

int get_gold()
{
    return 25000;
}

int get_wc()
{
    return 75;
}

int get_ac()
{
    return 55;
}

