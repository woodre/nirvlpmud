#include "../definitions.h"
string *my_neocon_first_names;
string *my_neocon_last_names;
string *my_ethnic_groups;
string *my_insults;
string *my_locations;


get() {
    return 0;
}
short() {
    return "A server named (neocon)";
}
id(str) {
    return str == "neocon" || str == "server";
}


string get_first_name()
{
    return my_neocon_first_names[random(sizeof(my_neocon_first_names))];
}

string get_last_name()
{
    return my_neocon_last_names[random(sizeof(my_neocon_last_names))];
}

string get_ethnic_group()
{
    return my_ethnic_groups[random(sizeof(my_ethnic_groups))];
}

string get_insult()
{
    return my_insults[random(sizeof(my_insults))];
}

string get_location()
{
    return my_locations[random(sizeof(my_locations))];
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_neocon_first_names = ( {
            "Billy-Bob",
            "Lance",
            "Austin",
            "Billy",
            "Billy Ray",
            "Bo",
            "Beau",
            "Bobby Joe",
            "Bodean",
            "Bryar",
            "Bubba",
            "Bucephelus",
            "Bud",
            "Buck",
            "Buddy",
            "Carson",
            "Casey",
            "Charlie Ray",
            "Chester",
            "Cleavon",
            "Clevon",
            "Cletus",
            "Chandler",
            "Clifton",
            "Clint",
            "Clyde",
            "Cody",
            "Cooper",
            "Cooter",
            "Coy",
            "Dale",
            "Delmont",
            "Donny",
            "Doc",
            "Duane",
            "Duke",
            "Dwayne",
            "Earl",
            "Elrod",
            "Enos",
            "Floyd",
            "Ford",
            "Forrest",
            "Garth",
            "Homer",
            "Horace",
            "Jack",
            "Jed",
            "Jerry Lee",
            "Jessie",
            "Jim Bob",
            "Jimmy Don",
            "Jimmy Dean",
            "Joe Bob",
            "John Boy",
            "Junior",
            "Lee",
            "Lonnie",
            "Luther",
            "Micah",
            "Otis",
            "Pervis",
            "Ray",
            "Rebel",
            "Ricky",
            "Robbie",
            "Rocky",
            "Roscoe",
            "Rowan",
            "Roy",
            "Rufus",
            "Tommy",
            "Tommy Lee",
            "Trigger",
            "Tyler",
            "Wilbur",
        });

        my_neocon_last_names = ( {
            "Uppercut",
            "Jenkins",
            "Smith",
            "Chang",
            "Gonzales",
            "White",
            "Black",
            "Reagan",
            "Bush",
            "Miller",
            "Hess",
            "Roth",
            "Squires",
            "Arnold",
            "Anderson",
            "Johnson",
            "Brown",
            "Jones",
            "Moore",
            "Jackson",
            "Garcia",
            "Chen",
            "Thompson",
            "Wilson",
            "Davis",
            "Harris",
            "Martin",
            "Clark",
        });

        my_ethnic_groups = ( {
            "Players",
            "Mexicans",
            "Non-Americans",
            "Amputees",
            "Vulcans",
            "Wookies",
            "Beanos",
            "Gundroids",
            "Gays",
            "Bisexuals",
            "Russians",
            "Chinese",
            "Jews",
            "Commies",
            "Germans",
            "Parisians",
            "Long Islanders",
            "Minnesotans",
            "Californians",
            "Walmart shoppers",
            "Target shoppers",
            "Protestants",
            "Catholics",
            "Southern Baptists",
            "Armenians",
            "Taiwanese",
            "Koreans",
            "Haitians",
            "Austrians",
            "Maltese",
            "Libyans", 
            "Egyptians",
            "Dominicans",
            "Puerto Ricans",
            "Canadians",
            "French",
            "Indians",
            "Vegetarians",
            "Japanese",
            "New Yorkers",
            "Bostonians",
            "Jawas",
            "Chickens",
            "Athiests",
            "Buddhists",
            "Muslims",
            "Rastafarians",
            "Spaghetti Monsters",
            "Funny Hat Wearers",
            "Soccer fans",
            "Cricket fans",
            "Los Angelinos",
	    "Twilight fans",
	    "Harry Potter fans",
	    "Star Wars fans",
	    "Star Trek fans",
            "Photographers",
	    "Betazoids",
	    "Cardassians",
	    "Ferengi",
            "Romulans",
            "Corellians",
	    "Ewoks",
	    "Wampas",
            "North Dakotans",
        });

        my_insults = ( {
            "If you don't follow the scriptures, then go home!",
            "Reject Science! Reason is for assholes!",
            "Reject Technology! It's a Sin against the scriptures!",
            "Sarah Palin has a communications degree! She is a GODDESS!",
            "Terrrrrists must die!",
            "Don't retreat! Reload! Kill all those who disagree with us!",
            "We must stand with our North Korean allies! Queen Sarah says so!",
            "This is Reagan country! Yeah!",
            "Drill, baby! Drill!",
            "They are kooks, so I agree with Rush Limbaugh!",
            "Only dead fish go with the flow!",
            "Don't take away from my Medicare to subsidize Socialist healthcare!",
            "Youth in Asia will kill your grandma!",
            "The Japanese deserved the earthquake. Pearl Harbor! Pearl Harbor!",
            "The New Zealand people deserved the earthquake! Damn southern hempispheres!",
            "The Indonesians deserved that earthquake! They're Indians!",
            "The Pakistanis deserved that earthquake! They're Terrrists!",
            "Go home Terrrrists!",
            "Don't touch my Medicare!",
            "Socialism sucks!",
            "Sarah Palin is our goddess!",
            "Rush is right!",
            "Osama is still alive!",
            "Obama isn't an American citizen!",
            "Obama and Osama are the same!",
            "Science is GAY!",
            "There is no need for science in a technology driven world!",
            "Send all the immigrants home!",
            "Destroy all Democrats!",
            "Destroy all Independents!",
            "One nation under God!",
            "Glenn Beck hates black people!",
            "Glenn Beck hates everyone!",
            "Repect are country! Speak English!",
            "Let Mitt Fix Washinton!",
            "Thank you Fox News for keeping us informed!",
            "How gullible and stupid do you think we are!",
        });

        my_locations = ( {
            "Tehran",
            "Havana",
            "Pyongyang",
            "Moscow",
            "Springfield",
            "Coruscant",
            "Caracas",
            "Kabul",
            "Baghdad",
            "New York",
            "Las Vegas",
            "Bombay",
            "Mumbai",
            "Mexico City",
            "Kabul",
            "Tripoli",
            "Jerusalem",
            "Cloud City",
        });

    }
}

