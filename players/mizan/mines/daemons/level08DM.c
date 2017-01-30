#include "../definitions.h"
string *my_mob_names;
string *my_captain_names;
string *my_mob_chats;
string *my_mob_achats;
string *my_captain_chats;
string *my_captain_achats;
string *my_boss_chats;
string *my_boss_achats;

get() { return 0; }
short() { return "A server named (l8dm)"; }
id(str) { return str == "l8dm" || str == "server"; }


string get_mob_name() { return my_mob_names[random(sizeof(my_mob_names))]; }
string get_captain_name() { return my_captain_names[random(sizeof(my_captain_names))]; }

string get_mob_chat() { return my_mob_chats[random(sizeof(my_mob_chats))]; }
string get_mob_achat() { return my_mob_achats[random(sizeof(my_mob_achats))]; }

string get_captain_chat() { return my_captain_chats[random(sizeof(my_captain_chats))]; }
string get_captain_achat() { return my_captain_achats[random(sizeof(my_captain_achats))]; }

string get_boss_chat() { return my_boss_chats[random(sizeof(my_boss_chats))]; }
string get_boss_achat() { return my_boss_achats[random(sizeof(my_boss_achats))]; }

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if(!arg)
    {
	my_mob_names = ({
"",
""
	});

        my_captain_names = ({
"",
""
        });


        my_mob_chats = ({
"Have two sex changes",
"Switch to Vonage",
"Hot sauce saline solution",
"Creamate my goldfish",
"Open Francis Ford Coppola's freezer",
"Exhume all Popes",
"Balloon ride with Pete Rose and family",
"Wear skis for a decade",
"Go from an innie to an outie",
"Never clap again ",
"Shoelace sandwich",
"Do four (4) items on Joey Buttafuoco's bucket list",
"Breathe next to a Bulgarian",
"Split a check with Larry David",
"Mumblecore marathon",
"Make fun of Ron Artest's hat",
"Learn to sing all of American Pie in Hebrew",
"Skywrite \"I Hate You Mom\"",
"Blend my iPhone and not videotape it",
"Do everything Fox News tells me to do for five days ",
"Bunk beds with Mark Wahlberg",
"Become fluent in Mandarin Chinese and then never use it",
"Conduct a week-long Team Edward conference",
"Give Kathy Griffin a blow job",
"Eat a Styrofoam turkey",
"Start Gaza Sailing Tours Inc",
"Sushi at Six Flags",
"Teach my mom what a blumpkin is",
"Polish Jesse James' Nazi medal collection",
"Tea with Tyson",
"Be a contestant on Jeopardy! drunk",
"Moderate a Harvard vs. Yale debate sober",
"Clean Bob Dylan's harmonica",
"Hike the rainforest in a tuxedo",
"Get a tattoo of the periodic table",
"Trade backpacks with a Muslim",
"Play a speciathlete 1 on 1",
"Fill the Stanley Cup with 5 Hour Energy and drink it",
"Take all my medical advice from Dr. J",
"Egg yolk popsicle ",
"Read the novel \"Push\" by Sapphire",
"Shave a bobcat",
"Call my nana a GILF",
"Register a star as the N-word",
"Drink a smoothie made of all my toiletries",
"Go on a date with someone I met on Digg",
"Hipster Thanksgiving",
"Bet my life savings on a pre-school soccer game",
"Edit Li'l Kim's autobiography",
"Read Glenn Beck a bedtime story ",
"Do a modern dance routine at Folsom Prison",
"Eat a car seat",
"Cuddle with Nancy Grace",
"Replace all beverages with SlimFast",
"Give a snake a back rub",
"Wear camo to church",
"Have Cher do my taxes",
"Hold a school assembly and tell all the kids Santa isn't real",
"Have a heart-to-heart with Mike Ditka's doctor",
"Have a fart-to-fart with Mike Ditka ",
"Watch a birthing video at the beginning of every day",
"Tutor Yoko Ono",
"Do the minimum that Jerry Falwell considered a \"gay experience\"",
"Candlelight dinner with Sharon Osbourne",
"Lifetime Little Mermaid ringtone",
"Rob the National Archives",
"Marinara sauce shower with garlic bread sponge",
"Set up 1-800-CRY-TO-ME",
"Attend the Puppy Bowl",
"Cole Slaw enema ",
"Swim a Great Lake",
"Defile any baseball legend's remains",
"Drive drunk across Iceland",
"Be John Starks' therapist or plumber",
"Lick a bedpan",
"Play Jesus in a live nativity scene with a raging boner",
"Throw a game of Family Feud",
"Every time someone mentions George Michael say \"You mean The King of Kings?\"",
"Join the Russian Navy",
"Go into business with Chien-Ming Wang ",
"Put a long-dead frog anywhere on or in my body",
"Grow a Hitler mustache",
"Listen to Middle Eastern jazz",
"Take advice from Pat Mora",
"Replace shaking hands with shouting \"rapist\"",
"Thumb war with Jim Abbott",
"Redo K-12",
"Eulogize a Nazi",
"Join an Everest expedition with no experience or gear",
"Be Bjork's translator ",
"Name my kid Courtney Love",
"Drink homemade Sprite Zero",
"Tunnel under the Meadowlands",
"Alphabetize DMX.s guns",
"Take a mob boss. daughter to junior prom",
"Bill Gates haircut",
"Arm-wrestle Carrot Top",
"Buy a private island and never visit it",
"Pogo stick polo",
"Segway through a hedge maze ",
"Replace all my water with flat Pepsi",
"Have Shaq proofread my dissertation",
"Mad TV Season 3",
"Tie Governor Paterson.s shoes together",
"Walk through the Holland Tunnel",
"Another Late Night with Jimmy Fallon",
"Uppercut from Manny Pacquaio",
"Befriend the Facebook killer",
"Be a garbageman in China",
"Make s.mores in church ",
"Be the executor of Cher.s last will and testament",
"Change my name to .HIV.",
"Drink Mike.s Hard Lemonade in public",
"Football with a porcupine",
"Frame the work of kindergarteners",
"Use heating pads as blankets",
"Clean Jay Leno or Rush Limbaugh.s garage",
"Bring a Civil War gun to the mall",
"Try to deposit Confederate money",
"Pray for Michael Crichton ",
"Tabouleh + hot tub",
"Train as a prison hygienist",
"Make a candle a day for the rest of my days",
"Any Morgan Spurlock experiment",
"Wear a Lord of the Rings wristwatch",
"Plan a Battlestar Galactica Bat Mitzvah",
"Blackmail a horse",
"Shaving cream sub",
"Jerk off during an earthquake",
"Wear a plague mask full of ranch dressing ",
"Fabricate a twin",
"Ex-lax smoothie before eulogizing",
"Dress like a lesbian",
"Go AWOL from the Peace Corps",
"Smack an Olsen Twin",
"Drink an entire chemistry set",
"Date Chris Hansen.s daughter",
"Wear molasses instead of socks",
"Drench the Bill of Rights in Schlitz",
"Debate a daddy longlegs ",
"Switch toothpaste and peanut butter",
"Hot Air Balloon with Don Imus",
"Live in a house full of drummers for a year",
"Get punched on a MegaTron",
"Eat a tuxedo",
"Defecate in a Kids'R'Us",
"Wear a baseball uniform to a funeral",
"Guest speaker at a doggie graduation",
"Knock over a Normandy Cross",
"Learn the French National Anthem ",
"Go on a potassium fast",
"Travel to Uruguay entirely on busses",
"Make a hobo hammock",
"Watch SuperBowl XXII with the Pope",
"Exhume all my pets",
"Paint Star Wars",
"Make this movie: Monkey Rock Star",
"Make a sweater for a giraffe",
"Sculpt Barack Obama out of milk chocolate",
"Be a defense attorney in Kid Kourt ",
"Doze off in an NHL locker room",
"Grab a drink with Paul Wolfowitz",
"Visit death row in a tankini",
"Make love to Serena Williams",
"Two-hand touch a trannie",
"Swallow jacks",
"Make and wear Count Chocula cologne",
"Insult an astronaut",
"Pay for admission to Madame Toussaud.s and chaperone Mel Gibson",
"Massage a lesbian ",
"Bring swastika JELL-O Jigglers to a middle school graduation",
"Watch Gladiator on mute",
"Eat a goatee",
"Tell a German writer/director I.ll do anything he wants",
"Steal Michael Vick.s identity",
"Get drunk in the same zip code as Madeleine Albright",
"Trade all my gizmos for Quiznos",
"Write a clown.s resume",
"Change all the lightbulbs at Shea Stadium",
"Crucify my cat ",
"Sleep in a vat full of stick bugs",
"Be Jerry Stiller's personal alarm",
"Cross-country rickshaw",
"Appear on an Iranian gameshow",
"Win an Iranian gameshow",
"Make Lemon Party my homepage",
"Audience member in People's Court",
"Watch a meteor shower with Andy Dick",
"Spy on Whoopi Goldberg in the tub",
"Translate the Autobiography of Malcolm X into English ",
"Stuff fudgcicles up my nose",
"Spend my IRA at Domino.s",
"Give Drew Carey a piggyback ride",
"Challenge a quadriplegic to a swordfight",
"Forget about email",
"Listen to her poetry",
"Hump a Sidewinder Missile",
"Advocate for the Zune",
"Online shop for dildos at the library",
"OD on the abortion pill ",
"Lick a baby",
"Rob Joni Mitchell.s grave",
"Get a cheetah drunk",
"Shake hands with a tollbooth attendant",
"Moonwalk I-95",
"Drink Demi Moore.s homemade wine",
"Be in charge of father's day for the NBA",
"Have a cell phone conversation with a bear",
"Fly the Pacific in a 1911 aircraft",
"Take a preteen.s betting advice ",
"Bowl a 300 game with no witnesses",
"Shake hands with Gary Busey",
"Rob a Barnes & Noble",
"Interview a dog",
"Blonde highlights",
"Ambassador to Paraguay for a day",
"Smoke my own socks",
"Play Monopoly with the Bush family",
"Take a shot of Purell",
"Hold in my BM for five days",
"Wear a shower cap to work",
"Read Lolita aloud to third graders",
"Yell on a plane",
"Don't acknowledge leap years ever",
"Claim everyday is my birthday on Facebook",
"Sleep with all my clothes on for a week",
"Taunt a python",
"Fold an American flag incorrectly on Labor Day",
"Assassinate a legend",
"Wear a yarmulke as a bathing suit ",
"Run a marathon backwards",
"Read Eleanor Roosevelt's diaries",
"Ball pit with Brad Pitt",
"Drop out of ITT Tech",
"Earn Guinness world record for not showering",
"Toenail sandwich",
"No oranges until deathbed",
"Salt n' Peppa reunion concert",
"BioSphere 3",
"Disagree with Peter Singer ",
"Murder a dolphin",
"Brunch with Travis Tritt",
"Print out Wikipedia",
"Pierce my ear with a three-hole punch",
"Pretend to be a Canadian",
"Eat only mustard for a week",
"Get really high at a screening of Gandhi",
"Lose any one toe",
"Shave my eyebrows asymmetrically",
"Bring nachos supreme onto Space Mountain ",
"Drive around Baghdad in an American Flag Mini Cooper",
"Sit through a condo pitch",
"Dognap Obama.s dog",
"Deny a holocaust",
"Wear glasses that constantly create the Ken Burns effect",
"Delete all the black people from my Blackberry",
"Volunteer for the Boston FD",
"Facebook photo on the toilet",
"Be the first openly gay candidate for Governor of Kansas",
"Take the heat for Chappaquiddick ",
"Santeria",
"50% blind in right eye, or 75% in left",
"Order an egg white omelet",
"Try earnestly to appreciate the Decembrists",
"Denounce America",
"Diving board into a pool of brown sauce",
"Drink the pee of a healthy, well hydrated woman",
"Let you do anything you want to me with an umbrella",
"Solve a murder",
"Be Andrew Dice Clay.s wingman ",
"Tase myself",
"Streak in a megachurch",
"Listen to NPR for 24 hours straight",
"Virtually any kind of medical testing",
"Sail around Somalia in a golden boat",
"The Pie Pod",
"Give up the Internet",
"Jalapeno in the ass",
"Vote for the Green Party from now on",
"Spoon with Ricky Martin ",
"Eat a cell phone",
"Reenact my entire bar mitzvah",
"Read all of Infinite Jest",
"Gay club in South Beach in just a speedo for an hour",
"Text \"ur a whore\" to every woman in my phone, including my mom",
"Let Dick Cheney ride me like a horse",
"Wear any hat, no matter how stupid",
"Level 2 or lower STD",
"Learn the banjo",
"Mormonism ",
"Make out with a dog",
"Shoot myself in the ankle or heel",
"Never have any form of salmon again",
"Pretend to be a feminist for a week",
"Watch the complete Kevin James 3x in a row",
"Eat two-week old Indian food, in India",
"Lick the sole of Bernie Madoff's foot",
"Gargle wood shavings + vermouth",
"Build a house of K'NEX and use it as shelter for two nights",
"Punch a bald eagle"
        });


        my_mob_achats = ({
"",
""
        });


        my_captain_chats = ({
"",
""
        });


        my_captain_achats = ({
"",
""
        });


        my_boss_chats = ({
"",
""
        });


        my_boss_achats = ({
"",
""
        });


    }
}

