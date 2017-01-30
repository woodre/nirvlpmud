#include "../definitions.h"
string *my_soldier_names;
string *my_soldier_boss_names;
string *my_soldier_insults;

get() {
    return 0;
}
short() {
    return "A server named (soldier)";
}
id(str) {
    return str == "soldier" || str == "server";
}


string get_name() {
    return my_soldier_names[random(sizeof(my_soldier_names))];
}

string get_boss_name() {
    return my_soldier_boss_names[random(sizeof(my_soldier_boss_names))];
}

string get_insult() {
    return my_soldier_insults[random(sizeof(my_soldier_insults))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_soldier_names = ( {
	    "Major Disaster",
	    "Major Payne",
	    "Major B.O.",
	    "Major Hardon",
	    "Major Lee Small",
	    "Major Problems",
	    "Major Malfunction",
	    "Major Minor",
	    "Captain Crunch",
	    "Seaman Samples",
	    "Seaman Stains",
	    "Seaman Guzzler",
	    "Major Wood",
	    "Private Parts",
	    "Private Road",
	    "Corporal Punishment",
            "Sergeant Facesmasher",
	    "Captain Obvious",
	    "Lieutenant Dan",
	    
        });

        my_soldier_boss_names = ({
	    "General Motors",
	    "General Failure",
	    "General Warning",
            "General Admission",
	    "Colonel O'Corn",
	    "Rear Admiral Butts",
	    "General E. Speaking",
	    "General Store",
	   
	});
 
        my_soldier_insults = ({
"What are you looking at, homo?",
"Maggot! You're useless as tits on a nun!",
"Maggot! You're useless as a pecker on a pope!",
"Maggot! You're useless as tits on a boar hog!",
"You must be sweating like a virgin at a prison rodeo!",
"Last time you got a piece of ass your finger slipped though the toilet paper!",
"If I wanted any lip from you, I'd have unzipped my pants, maggot!",
"Do they have a name for what's wrong with you?",
"What's your malfunction, numbnuts?",
"I don't know what your problem is, but I'll bet it's hard to pronounce.",
"You've got a face made for radio, numbnuts!",
"Stop sweating as a whore in church!",
"Stop sweating like a pedophile on a playground!",
"You're the poster child for abortion!",
"I'm gonna beat you 'til you shit your pants and then I'm gonna beat you for shitting them!",
"Your father must have jerked off in a flower pot, because you're a blooming fucking idiot!",
"That's nice, do you blow your dad with that mouth?",
"You're as useful as a one legged-man in an ass kicking contest.",
"Looks like the best part of you ran down the crack of your momma's ass and ended up as a brown stain on the mattress.",
"Make like a fetus and abort!",
"If I want any more shit outta you, I'll squeeze your head.",

	});


    }
}



