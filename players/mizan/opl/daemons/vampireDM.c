#include "../definitions.h"
string *my_male_vampire_names;
string *my_male_vampire_chats;

get() {
    return 0;
}
short() {
    return "A server named (vampire)";
}
id(str) {
    return str == "vampire" || str == "server";
}


string get_male_vampire_name() {
    return my_male_vampire_names[random(sizeof(my_male_vampire_names))];
}
string get_male_vampire_chat() {
    return my_male_vampire_chats[random(sizeof(my_male_vampire_chats))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_male_vampire_names = ( {
            "Edward",
            "Corniche",
            "Desmond",
            "Eugin",
            "Carl",
            "Emmett",
            "Demitri",
            "Felix",
            "Jasper",
            "James",
            "Jacob",
            "Benjamin",
            "Kevin",
            "Laurent",
            "Antoine",
            "Paul",
            "Stanley",
            "Charlie",
            "Vladimir",
            "Samuel",
	    "Yves",
	    "Laurel",
            "Ashley",
            "Stanwick",
	    "Yorkshire",
	    "Hiller",
	    "Jackson",
	    "Michel",
            "Stefan",
            "Riley",
            "Alexey",
	    "Evinweygh",
            "Everland",
            "Honore",
        });

        my_male_vampire_chats = ( {
            "says: I don't know why girls don't like me...",
            "mopes and winces from... too much EMOTION!",
            "says: Look at me! I'm... GLISTENING!",
            "says: My perfectly formed abs... they're a bit soggy now...",
            "says: I need to stop eating so many pork rinds.",
            "says: It's too bad that Bella is such a mean bitch.",
            "says: Why do women manipulate me so? They're technically... prey!",
            "says: I don't know how to handle this. It's just... too much emotion.",
            "says: I wish people would just trust me. Trust... me.",
            "says: Hmm. No blood, no foul.",
            "says: Someone has to spread the good news that we survived.",
            "says: I saved her life. I didn't owe her anything.",
            "says: I hope that you enjoy disappointment.",
            "sighs wistfully.",
            "amazes you with a pure, almost visible emission of ANGST!",
            "says: Perhaps it's better that we're not friends. Trust me.",
            "says: Bella is utterly absurd.",
            "says: I decided that if I were to go to Hell, I would do it very throughly.",
            "says: Do you faint at the sight of blood?",
            "says: It's healthy to ditch class every now and then.",
            "says: I think I am going to go sit down and look pale.",
            "says: Do you think that I could be... scary?",
            "says: Oh... distract me... please.",
            "says: Sometimes I have a problem with my temper.",
            "says: Do I... DAZZLE you?",
            "says: Bella is a magnet for accidents.",
            "says: Oh. It's you. I followed your scent.",
            "says: The more familiar someone's 'voice' is, the farther away I can hear them.",
            "says: I hear voices in my mind and you're worried that I'm the freak.",
            "says: You don't care if I'm a monster? If I'm not... human?",
            "says: Don't you want to know if I drink blood?",
            "says: They are right to keep their distance from us. We are still dangerous.",
            "says: I don't want to be a monster.",
            "says: I am a lover, not a killer.",
            "says: I was distracted all weekend, worrying about you.",
            "says: Have you noticed? We're breaking all the rules now.",
            "flicks his dark hair back, revealing a pale, glistening... beer gut.",
            "says: We all like to drive fast.",
            "clasps at his oversized, but glistening belly.",
            "says: Of all the things that are frightening, she worries about my driving.",
            "says: You need a healthy dose of fear. Nothing could be more beneficial for you.",
            "says: It's twilight.",
            "says: I don't want you to be afraid.",
        });

    }
}

