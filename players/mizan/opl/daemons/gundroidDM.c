#include "../definitions.h"
string *my_gundroid_st_msgs;
string *my_gundroid_mt_msgs;
string *my_gundroid_lt_msgs;
string *my_gundroid_ltdetail_msgs;
string *my_gundroid_insults;

get() {
    return 0;
}
short() {
    return "A server named (gundroid)";
}
id(str) {
    return str == "gundroid" || str == "server";
}

string get_gundroid_st_attack_message() {
    return my_gundroid_st_msgs[random(sizeof(my_gundroid_st_msgs))];
}

string get_gundroid_mt_attack_message() {
    return my_gundroid_mt_msgs[random(sizeof(my_gundroid_mt_msgs))];
}

string get_gundroid_lt_attack_message() {
    return my_gundroid_lt_msgs[random(sizeof(my_gundroid_lt_msgs))];
}

string get_gundroid_lt_attack_detail() {
    return my_gundroid_ltdetail_msgs[random(sizeof(my_gundroid_ltdetail_msgs))];
}

string get_gundroid_insult() {
    return my_gundroid_insults[random(sizeof(my_gundroid_insults))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {

        my_gundroid_st_msgs = ( {
        "cuts off a clean burst",
        "squeezes off a few rounds",
        "cuts loose a burst",
        "blasts out a burst",
        "fires off a shot",
        "gets a clean shot",
        "gets a quick burst",
        "hits off a round",
        });

        my_gundroid_mt_msgs = ( {
        "rips some fiery, molten ass",
        "toasts off a round",
        "burn off a fiery round",
        "cuts loose a blast",
        "drills a clean shot",
        "drills a hot one",
        "fires a crispy shot",
        });

        my_gundroid_lt_msgs = ( {
        "unleashes deadly buckshot",
        "blasts a torrent of pellets",
        "fires off a shell",
        "squeezes off a buckshot round",
        "ignites a pellet storm",
        });

        my_gundroid_ltdetail_msgs = ( {
        "is struck in the ass with pellets!",
        "is struck with a face full of buckshot!",
        "is caught in a pellet storm!",
        "is hit with a wave of buckshot!",
        "is blasted with hot metal pellets!",
        "is knocked backwards by buckshot!",
        });

        my_gundroid_insults = ( {
        "Come on, you stupid humans! You can do MUCH BETTTTERRRRRR!",
        "You douchebags call that combat? That SUCKED! You deserve to die!",
        "HA HA HA HA HA!",
        "Is that all you got?! My, my! That's pissweak!",
        "YOU HUMANS SUCK MOOSE BALLS!",
        "Prepare to die, you ugly bags of meaty water!",
        "I am a killing machine. Killing is my business. Business is GOOD!",
        "You suckers are all going to taste lead!",
        "Come on! That's all you got?! I'm going to beat your sorry asses!",
        "I'm going to penetrate you with my turrets, and pump you full of LOVELY LEAD!",
        "Yeah! That's how we do it, softforms! Suck it!",
        "Is that what you call fighting? You're going to have to do better!",
        "You are weak. I am perfect. Get used to that new world order.",
        });

    }
}

