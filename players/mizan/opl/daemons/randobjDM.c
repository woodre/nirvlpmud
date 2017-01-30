#include "../definitions.h"
#include "/obj/ansi.h"

string *my_album_names;
string *my_film_names;
string *my_store_names;
string *my_ahnuld_snaps;
string *my_random_cars;
string *my_film_quotes;
string *my_phantom_shitter_song;
int phantom_shitter_song_bar;
string *song_colors;
string *my_gummy_bear_insults;
string *my_nightmares;


get() {
    return 0;
}

short() {
    return "A server named (randobj)";
}

id(str) {
    return str == "randobj" || str == "server";
}


string get_album_name() {
    return my_album_names[random(sizeof(my_album_names))];
}

string get_film_name() {
    return my_film_names[random(sizeof(my_film_names))];
}

string get_store_name() {
    return my_store_names[random(sizeof(my_store_names))];
}

string get_ahnuld_snap() {
    return my_ahnuld_snaps[random(sizeof(my_ahnuld_snaps))];
}

string get_random_car() {
    return my_random_cars[random(sizeof(my_random_cars))];
}

string get_film_quote() {
    return my_film_quotes[random(sizeof(my_film_quotes))];
}

string sing_phantom_shitter_song()
{
    string result;
    /* 11/21/05 Earwax: made it colorful :) */
    if (phantom_shitter_song_bar == (sizeof(my_phantom_shitter_song) - 1))
        phantom_shitter_song_bar = 0;

    result = song_colors[random(16)]+ U + my_phantom_shitter_song[phantom_shitter_song_bar] + NORM + NORM + "\n" ;
    phantom_shitter_song_bar ++;
    return result;

}

string get_gummy_bear_insult()
{
    return my_gummy_bear_insults[random(sizeof(my_gummy_bear_insults))];
}

string get_nightmare()
{
    return my_nightmares[random(sizeof(my_nightmares))];
}


void render_shoop(object room)
{
    if(!room) return;

    tell_room(room, "\n"); 
    tell_room(room, HBWHT + HIK + "O" + NORM + " " + HBWHT + HIK + "o" + NORM + "\n");
    tell_room(room, HBRED + HIW + "/--" + NORM + HIK + "___________________________________________" + NORM + "\n");
    tell_room(room, HBRED + HIW + "|" + HBWHT + HIK + U + " BLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARGH!!!! " + NORM + "\n");
    tell_room(room, HBRED + HIW + "\\_/" + NORM + "\n\n");

}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_random_cars = ( {
            "Ford Festiva",
            "Hyundai Excel",
            "Chevy Aveo",
            "Honda Fit",
            "Smart Car",
            "Ford Pinto",
            "Trabant",
            "Chevy Chevette",
            "AMC Pacer",
            "Yugo GV",
            "Pontiac Aztek",
	    "Zundapp Janus",
            "Reliant Robin",
            "BMW Mini",
	    "BMW Isetta",
	    "Toyota Corolla",
        });


        my_ahnuld_snaps = ( {
            "Screw you, Benny!",
            "He was Sub-Zero, now he's Plain Zero!",
            "It's not a tumoah!",
            "I'll be back.",
            "Stick around!",
            "You're not sending me to the cooler.",
            "All right everyone. Chill. Chill!",
            "You should not drink and bake.",
            "It's simple. If it jiggles, it's fat.",
            "See you at the party, Richter.",
            "Come on Cohaagen, give these people some air!",
            "Who is your daddy, and what does he do?",
            "Come on! Do it! Come on, kill, do it! Kill me!",
            "I need your clothes, your boots, and your motorcycle.",
            "Who told you, you could eat my cookies?",
            "Allow me to break the ice.",
            "Let off some steam, Bennett!",
            "Eeaaaaaargh!",
            "I am the gummy bear of candy cornia!",
        });

        my_album_names = ( {
            "'Way Out West', by Mae West",
            "'All or Nothing', by Milli Vanilli",
            "'Girl You Know It's True', by Milli Vanilli'",
            "'My World', by Justin Bieber",
            "'Songs for Gay Dogs', by Paddy Roberts",
            "'Kenny G', by Kenny G",
            "'G Force', by Kenny G",
            "'Gravity', by Kenny G",
            "'Duotones', by Kenny G",
            "'Silhouette', by Kenny G",
            "'Breathless', by Kenny G",
            "'The Moment', by Kenny G",
            "'Classics in the Key of G', by Kenny G",
            "'Paradise', by Kenny G",
            "'At Last...The Duets Album', by Kenny G",
            "'I'm in the Mood for Love...', by Kenny G",
            "'Rhythm & Romance', by Kenny G",
            "'Heart & Soul', by Kenny G",
            "'Fool's Game', by Michael Bolton",
            "'Everybody' Crazy', by Michael Bolton",
            "'How Can We Be Lovers?', by Michael Bolton",
            "'To Love Somebody', by Michael Bolton",
            "'Drift Away', by Michael Bolton",
            "'Bittersweet World', by Ashlee Simpson",
            "'I Am Me', by Ashlee Simpson",
            "'Bittersweet World', by Ashlee Simpson",
            "'Red, Red Wine', by UB40",
            "'Joey Lawrence', by Joey Lawrence",
            "'Soulmates', by Joey Lawrence",
            "'Measure of a Man', by Clay Aiken",
            "'Merry Christmas with Love', by Clay Aiken",
            "'A Thousand Different Ways', by Clay Aiken",
            "'On My Way Here', by Clay Aiken",
            "'Tried And True', by Clay Aiken",
            "'Meet Miley Cyrus', by Miley Cyrus",
            "'Breakout', by Miley Cyrus",
            "'Can't Be Tamed', by Miley Cyrus",
            "'To The Extreme', by Vanilla Ice",
            "'Mind Blowin', by Vanilla Ice",
        });


        my_film_names = ( {
            "'The Notebook (2004)'",
            "'The Time Traveler's Wife (2009)'",
	    "'Cool As Ice (1991)'",
        });


        my_store_names = ( {
            "2b bebe",
            "7 For All Mankind",
            "A|X Armani Exchange",
            "Adidas",
            "Aeropostale",
            "AG Adriano Goldschmied",
            "American Apparel",
            "American Eagle Outfitters",
            "Ann Taylor Factory Store",
            "Anne Fontaine",
            "Balenciaga",
            "Banana Republic Factory Store",
            "Barneys New York Outlet",
            "Bass",
            "BCBG Max Azria",
            "Ben Sherman",
            "Benetton",
            "Betsey Johnson",
            "Bottega Veneta",
            "Brioni",
            "Brooks Brothers Factory Store",
            "Brunello Cucinelli",
            "Burberry",
            "Calvin Klein Men's",
            "Calvin Klein Women's",
            "Catherine Malandrino",
            "CH Carolina Herrera",
            "Chico's",
            "Chloe",
            "Columbia Sportswear Company",
            "Converse",
            "Diane Von Furstenberg",
            "Diesel",
            "Dior",
            "DKNY",
            "Dolce & Gabbana",
            "Dunhill",
            "Ecko Unltd",
            "Ed Hardy",
            "Eddie Bauer Outlet",
            "Elie Tahari",
            "Escada Company Store",
            "Esprit",
            "Etro",
            "Fendi",
            "G-Star Raw",
            "Gap Outlet",
            "Giorgio Armani",
            "Giorgio Armani Holiday Store",
            "Gucci",
            "Guess Factory Store",
            "Hickey Freeman / Bobby Jones",
            "Hugo Boss",
            "Izod",
            "J.Crew",
            "Jockey",
            "Joe's Jeans",
            "John Varvatos",
            "Jones New York",
            "Juicy Couture",
            "Kasper",
            "Kenneth Cole",
            "L'eggs Hanes Bali Playtex",
            "La Perla",
            "Lacoste",
            "Last Call by Neiman Marcus",
            "Levi's Outlet Store",
            "Loro Piana",
            "Lucky Brand",
            "Lululemon Athletica",
            "M Missoni",
            "Maidenform",
            "Marni",
            "MaxMara",
            "MaxStudio.com",
            "Michael Kors",
            "Nautica",
            "Nike Factory Store",
            "The North Face",
            "Oakley Vault",
            "Oscar de la Renta",
            "PacSun",
            "Perry Ellis",
            "Polo Ralph Lauren",
            "Prada",
            "Puma",
            "Ralph Lauren",
            "Reebok",
            "Roberto Cavalli",
            "Rock & Republic",
            "Saks Fifth Avenue Off 5th",
            "Salvatore Ferragamo",
            "Sarar",
            "Spyder",
            "St. John Outlet",
            "Superdry",
            "Theory",
            "Theory Men",
            "Thomas Pink",
            "Timberland",
            "Tommy Bahama",
            "Tommy Hilfiger",
            "Tory Burch",
            "True Religion",
            "TSE",
            "Under Armour",
            "Valentino",
            "Van Heusen",
            "Versace",
            "Vilebrequin",
            "Vineyard Vines",
            "Wolford",
            "Yves Saint Laurent",
            "Zegna Outlet Store",
            "Carter's",
            "The Children's Place Outlet",
            "Disney Store Outlet",
            "Gymboree Outlet",
            "J.Crew | Crewcuts",
            "NauticaKids",
            "OshKosh B'gosh",
            "Polo Ralph Lauren Children",
            "Stride Rite Keds Sperry",
            "Tommy Hilfiger Kids",
            "Adidas",
            "Aerosoles",
            "Aldo",
            "Bally",
            "Bass",
            "Clarks Bostonian",
            "Cole Haan",
            "Converse",
            "Crocs",
            "E Active by Easy Spirit",
            "Easy Spirit",
            "Ecco",
            "Geox",
            "Giuseppe Zanotti Design",
            "Hush Puppies Merrell Sebago",
            "Jimmy Choo",
            "Johnston & Murphy",
            "Kenneth Cole",
            "Naturalizer",
            "Nike Factory Store",
            "Nine West",
            "Puma",
            "Reebok",
            "Rockport",
            "Saks Fifth Avenue Off 5th",
            "Salvatore Ferragamo",
            "Saucony",
            "Skechers",
            "Sperry / Saucony",
            "Stride Rite Keds Sperry",
            "Timberland",
            "Tod's",
            "Ugg Australia",
            "Bottega Veneta",
            "Coach",
            "Coach Men's",
            "Dooney & Bourke",
            "Dunhill",
            "Furla",
            "Gucci",
            "Judith Leiber",
            "Kate Spade",
            "Kipling",
            "Longchamp",
            "The Luggage Factory",
            "Samsonite",
            "Tumi",
            "Brighton Collectibles",
            "Claire's Accessories",
            "Coach",
            "Coach Men's",
            "Cole Haan",
            "David Yurman at The London Jewelry Collection",
            "Fossil",
            "Guess Factory Accessories",
            "Judith Ripka",
            "Kate Spade",
            "LeSportsac",
            "Lids for Less",
            "Michael Kors",
            "Movado Company Store",
            "Solstice Sunglass Outlet",
            "Sunglass Hut",
            "Sunglass Station",
            "Swarovski",
            "TAG Heuer",
            "Time Factory Watch Outlet",
            "Ultra Diamonds",
            "Zales Outlet",
            "Corningware Corelle Revere",
            "Crate and Barrel",
            "Frette",
            "Le Creuset",
            "Le Gourmet Chef",
            "Lenox",
            "Pratesi",
            "Ralph Lauren Home",
            "Bare Escentuals",
            "Bose",
            "The Cosmetics Company Store",
            "Crabtree & Evelyn",
            "Designer Fragrances",
            "Elizabeth Arden",
            "Godiva Chocolatier",
            "Headline News",
            "Judith Leiber",
            "L'Occitane",
            "Lancome - The Company Outlet",
            "Lladro",
            "Perfumania",
            "Sony",
            "Swarovski",
            "Toys'R' Us Outlet",
            "Travelex Currency Exchange",
            "Victorinox Swiss Army",
            "Vitamin World",
            "Yankee Candle",
        });

        my_film_quotes = ( {
            "Beetlejuice, Beetlejuice, Beetlejuice!",
            "It's showtime!",
            "They're heeeere!",
            "Hey you guys!",
            "Good morning, Vietnam!",
            "I love the smell of napalm in the morning. You know, one time we had a hill bombed, for 12 hours. When it was all over, I walked up. We didn't find one of 'em, not one stinkin' dink body. The smell, you know that gasoline smell on the whole hill. Smelled like ... victory.",
            "Say 'hello' to my little friend!",
            "I'm your Huckleberry.",
            "Hello, my name is Inigo Montoya. You killed my father. Prepare to die.",
            "Heeeeere's Johnny!",
            "Khaaaaan!",
            "Bueller....Bueller...Bueller?",
            "They call me Mr. Tibbs!",
            "Bond...James Bond.",
            "A martini...shaken, not stirred.",
            "Shall...we...play...a...game?",
            "Alrighty then!",
            "The numbers all go to 11!",
            "To infinity...and beyond!",
            "Well, la-de-da.",
            "Yeah baby, yeah!",
            "I know kung fu.",
            "I have come here to chew bubblegum and kick ass, and I'm all out of bubblegum.",
            "Who are you?",
            "I'm your worst nightmare.",
            "I know you are, but what am I?",
            "Surely, you can't be serious.",
            "I am serious, and don't call me Shirley.",
            "I pity the fool.",
            "You talkin' to me?",
            "You've gotta ask yourself a question: do I feel lucky? ...well, do ya, punk?!?",
            "WHAT IS YOUR MAJOR MALFUNCTION, NUMBNUTS?!?",
            "There can be only one.",
            "Aw, crap.",
            "YOU SHALL NOT PASS!",
            "THIS IS SPARTA!",
            "Of course, you know, this means WAR!",
            "Houston, we have a problem.",
            "Lions and tigers and bears, oh my!",
            "Warriors, come out to play-ee-ay!",
            "I must break you.",
            "Shit just got real.",
            "I'm as mad as hell, and I'm not gonna take this anymore!",
            "It's clobberin' time!",
            "Here comes the pain!",
            "HULK SMASH!",
            "Go ahead, make my day.",
            "Time to nut up or shut up.",
            "Resistance is futile.",
            "Get off my plane.",
            "Get away from her, you BITCH!!!",
            "Take your stinking paws off me, you damn dirty ape!",
            "Run, Forrest, run!",
            "I'll be back.",
            "I'm too old for this shit.",
            "Thank you for your cooperation.",
            "Loser!",
            "Ding-dong, the witch is dead!",
            "I want my two dollars!",
            "SHOW ME THE MONEY!!!",
            "Greed, for lack of a better word, is good.",
            "Very nice, how much?",
            "One MILLION dollars!",
            "I'll buy that for a dollar!",
            "Excellent!",
            "Bogus.",
            "The horror.....the horror.",
            "You can't handle the truth!",
            "YES, they deserved to die, and I hope they burn in hell!",
            "Damn you. Goddamn you all to hell!",
            "Snap out of it!",
            "Why so serious?",
            "We're on a mission from God.",
            "Shaa, and monkeys might fly out of my butt!",
            "As if!",
            "I sell drugs to the community!",
            "You're a disease, and I'm the cure.",
            "Yipee kayaye, motherfucker!",
            "Hoo-ah!",
            "Cowabunga!",
            "I feel the need...the need for speed.",
            "If you build it, he will come.",
            "You're only supposed to blow the bloody doors off!",
            "Machete don't text.",
            "You're gonna need a bigger boat.",
            "Badges? We don't have no badges. We don't need no badges. I don't have to show you any stinking badges!",
            "I am your father.",
            "I see dead people.",
            "Toto, I have a feeling we're not in Kansas anymore.",
            "...and this one time, at band camp...",
            "HOLY SCHNIKES!!!",
            "Great scott!",
            "INCONCEIVABLE!!!",
            "My momma always said, 'Life is like a box of chocolates: you never know what you're gonna get.",
            "It's alive! It's alive! IT'S ALIVE!!!",
            "Gooble gobble, gooble gobble. We accept her! We accept her! Gooble gobble, gooble gobble. One of us! One of us!",
            "Alright, Mr. DeMille, I'm ready for my close-up.",
            "I ate his liver with some fava beans and a nice chianti.",
            "THE POWER OF CHRIST COMPELS YOU!!!",
            "I'm gonna make him an offer he can't refuse.",
            "Soylent Green is people!",
            "I know it was you, Fredo. You broke my heart. You broke my heart!",
            "You don't understand! I coulda had class! I coulda been a contender. I coulda been somebody, instead of a bum, which is what I am.",
            "Here's lookin' at you, kid.",
            "Never give up, never surrender!",
            "Goonies never say die!",
            "They may take our lives, but they'll never take...OUR FREEDOM!",
            "Frankly, my dear, I don't give a damn.",
            "Oh, behave!",
            "What do you mean, I'm funny?",
            "Just when I thought I was out, they pull me back in!",
            "They're back!",
            "E.T. phone home.",
            "There's no place like home.",
            "Yo, Adrian!",
            "Schwing!",
            "Hey Stella! HEY STELLA!!!",
            "You...complete me.",
            "You had me at 'hello'.",
            "I'm not bad. I'm just drawn that way.",
            "Why don't you come up sometime, and see me?",
            "Ssssssssssssmokin'!",
            "Mrs. Robinson, you're trying to seduce me!",
            "I'll have what she's having.",
            "My precious!",
            "It's a trap!",
            "Wax on, wax off. Wax on, wax off.",
            "SON OF A - ... That's gonna leave a mark.",
            "My bad!",
            "Is it safe?",
            "Yes, sensei!",
            "Hey! I'm walking here! I'm walking here!",
            "Sounds like SOMEBODY'S got a case of the Mondays!",
            "Uhh....yeah.",
            "Forget about it.",
            "In this country, you gotta make the money first. Then, when you get the money, you get the power. Then when you get the power, THEN you get the woman!",
            "I'm the king of the world!",
            "Hakuna Matata!",
            "Toga, toga, toga toga!",
            "Feed me, Seymour!",
            "I'm sorry, Dave. I'm afraid I can't do that.",
            "Rosebud.",
            "Pay no attention to that man behind the curtain!",
            "Forget it, Jake. It's Chinatown.",
            "Live long and prosper.",
            "May the Force be with you.",
            "Hasta la vista...baby.",
            "That'll do, Pig.",
            "It's over, Johnny.",
            "After all, tomorrow is another day.",
            "In case I don't see ya...good afternoon, good evening, and goodnight.",
        });

        my_phantom_shitter_song = ( {
            "Yes. As I stand here before you today, I acknowlege I am the Phantom Shitter that has plagued our office for the past 2 months. Yes, I know this idea is from Flight of the Intruder. ",
            "I just need to come clean.",
            "It was me who took the upper-decker in stall 2 of the womens bathroom",
            "It was me who shat in the upper riht hand drawer of the VPs desk",
            "That horrid smell in the copy room? You guessed it. I took down a ceiling tile, crapped, and put it back up.",
            "The cute new intern? It's my fault she left. She left her purse in her cube overnight. Yep, I got it.",
            "The anal retentive accounting woman? You know her, she nitpicks every expense you have. Wel to make you all feel better, last week, at 1am on a weeknight, I removed the cover from her computer, shit, and then reassembled. i have no doubt that was the cause of the 4 hours of closed door meetings the next day.",
            "Shall I continue?",
            "Yes.",
            "The office managers coffee cup. I apologize for this one because I had Taco Bell. It was more of anal piss than crap, but nonetheless, the boss had to go toStarbucks the next morning.",
            "The turd in the trunk of the office 'luxury ford taurus?' Mine also.",
            "Oh, and that wasnt dog crap sitting in a nice pile on the sidewalk leadin g to the main entrance. Come on, when was the last time you saw a 250 lb dog?",
            "How about the fudge in the freezer of the fridge. It has been in there for 6 weeks. I pity the fool who removes the plastic cover.",
            "I take secret pleasure in the terror I cause. I try to keep my activities intentionally random. hree days in a row here, then a 2 week hiatus. You never know when I will strike. Our office is a bg target. The shitting will continue until I get that friggin raise I was promised 6 months ago. Good luck, the next round will be worse, and I've started drinking Metamucil.",
            "I am still the Phantom Shitter. Although I had taken some time off, I want you to know, that much like Arnold Schwarzenegger, I AM BACK. First let me explain my departure. I had gotten two bonuses, which almost felt like raises (even though they were a one time deal) and I had gotten promoted. Promoted? Yes! I thought I would finally get that raise I had been entitled to, and lobbying for through my defecation terrorism. The 1st pay check of that raise came in last month. Four hundred motherfucking dollars! Not per week or per month. Per year!!! As a result, the Phantom Shitter has returned to my office, and boy is he pissed.",
            "I announced my return to my co-workers my taking a dump, and then using to the toilet paper to write 'I'm back' in shit across the reception room. My boss saw this, yelled 'oh fuck' and called the police.",
            "The smell growing in the men's locker room? You guessed it, I shat on a paper plate, placed it in one of the vented lockers, and slapped on a Master lock. That should fossilize in a few months.",
            "The stained carpet in the main hallway? Me also. When I had diarrhea a few weekends ago, I drove to the office (making several stops along the way) at 3am. I stripped naked, and taking a page out of my dog's playbook, crab-walked down the hallway while expelling a liquid stream of greenish shit. I am impressed with my own distance of 30+ feet.",
            "It was me who dropped the corn-filled turds in not one, but all three of the boss's coffee cups. Starbucks again motherfucker!!!",
            "The missing fichus tree? Um, yeah, I definitely got it. What added to my enjoyment was that it took a week for the secretary to identify the cause of the smell. I had to laugh out loud when I saw that fichus hanging half out of the dumpster one morning.",
            "The missing fish tank in the chief engineer's office? I really let a man-sized turd go in that one. Rumor has it when the CE saw the poop floating near his now dead fish, he through the whole damn thing in the parking lot behind the office.",
            "To allay suspicion, I even shat in my own trash can one night. One day's unpleasantness is indeed a small price to pay for my continued activities.",
            "It was me who shat on the portrait of the company founder. Only part of it rolled off when the picture was re-hung.",
            "It was me that shit near the intake of our HVAC system.",
            "It was me that crapped in the Executive bathroom's urinal",
            "And it will be me that does not stop until everyone here quits, or I get a damned raised, beyond the friggin COLA. I will keep you all updated as this progresses over the next few months.",
            "LOVE, AND EVER TRULY YOURS...",
            "The Phantom Shitter!",
        });

        song_colors = ( {
            RED, BLK, GRN, YEL, BLU, MAG, CYN, WHT,
            HIK, HIR, HIG, HIY, HIB, HIM, HIC, HIW
        });

        my_gummy_bear_insults = ({
	    "Oh, hey man... what are you doing?",
 	    "Hey, hey man, chill, you know?",
	    "Hey, don't pee on the rug, okay?",
	    "Dude, relax... what are you... nuts?",
	    "Yo, stop being so... crazy... man!",
	    "What the hell? That kinda hurts... dude",
	    "Hey man! This just can't abide... man...",
	    "Hey... HEY!",
	    "What the hell... dude?!",
	    "Hey man!",
	    "Yeah... yeah, YEAH... yeah...",
	    "Hey, you're not being so cool right about now.",
	    "Watch it!",
	    "Yo man! What is the point, man?!",
	    "Who the fuck are the Knutsens?",
	    "Hey... man... dude... stop that... okay?",
	    "Hey, this really isn't very funny... man!",
	    "Hey.",
	    "Yo.",
	    "What are you doing?",
	    "Dude.",
	    "Dude? Dude... what's going on here?",
	    "Hey!",
	});

        my_nightmares = ({
            "are being attacked by cannibal prostitutes",
            "are being eaten alive by zombie prostitutes",
            "are being beaten to a pulp by an army of toddlers",
            "are forced to pull a train with your dingus",
            "wander endlessly in a city-sized Walmart",
            "fall helplessly into a vat of boiling diarrhea",
        });

    }
}

