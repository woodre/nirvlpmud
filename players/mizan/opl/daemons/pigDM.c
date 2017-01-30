#include "../definitions.h"
string *my_names;
string *my_insults;

get() {
    return 0;
}
short() {
    return "A server named (pig)";
}
id(str) {
    return str == "pig" || str == "server";
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
            "Porkins",
            "Tubby",
            "Hudson",
            "Burt",
            "Blatt",
            "Jake",
            "Buttlarge",
            "Newt",
            "Paulenty",
            "Palen",
            "Hogg",
            "Lester",
            "Morton",
            "Babu",
            "Babalu",
            "Ho-bag",
            "Larry",
            "Nostrum",
            "Chuckles",
            "Sanders",
            "Logan",
            "Princess",
            "Wenzel",
            "Chaz", 
            "Lopez",

        });


        /* Cop Talk */ 
        my_insults = ({

	});


    }
}

int get_hp()
{
    return 10000;
}

int get_gold()
{
    return 50 + random(100);
}

int get_wc()
{
    return 90;
}

int get_ac()
{
    return 55;
}

