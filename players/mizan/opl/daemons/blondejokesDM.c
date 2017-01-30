/*****************************************************************************
 *      File:                   blondejokesDM.c
 *      Function:               Has a bunch of blonde jokes
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "../definitions.h"
string *my_blonde_jokes;

get() {
    return 0;
}
short() {
    return "A server named (blondejokes)";
}
id(str) {
    return str == "blondejokes" || str == "server";
}

string query_joke(int arg)
{
    if(!arg) return "";
    return my_blonde_jokes[arg];
}

int get_joke_index() {
    int i;
    int size;

    size = random(sizeof(my_blonde_jokes) / 2);

    for(i = 0; i < sizeof(my_blonde_jokes); i += 2)
    {
        if(i == size) return i;
    }
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {

        /* CREDITS: http://www.kellys.com/jokeb1.html
         */
        my_blonde_jokes = ( {
	    "You like this stuff?",
            "Am I funny? Of course!",

            "What's the difference between a blonde and a solar powered calculator?",
            "The blonde works in the dark!",

            "How can you tell if a blonde has been using the computer?",
            "The joystick is wet.",

            "What does a blonde put behind her ears to make her more attractive?",
            "Her ankles.",

            "What do you say to a Blonde that won't give in?",
            "Have another beer.",

            "What do Blondes say after sex?",
            "Thanks Guys.",

            "What do Blondes say after sex?",
            "Are you boys all in the same band?",

            "What do Blondes say after sex?",
            "Are all you guys on the same football team?",

            "How do you make a blonde's eyes twinkle?",
            "Shine a flashlight in their ear.",

            "What does a screen door and a blonde have in common?",
            "The more you bang it the looser it gets.",

            "What does a blond and a beer bottle have in common?",
            "They're both empty from the neck up.",

            "What do blonds and spaghetti have in common?",
            "They both wriggle when you eat them.",

            "Why was the blondes' belly button sore?",
            "Because her boyfriend was blonde too.",

            "How do you get a blond out of a tree?",
            "Wave.",

            "What do peroxide blonds and black men have in common?",
            "They both have black roots.",

            "What does a blonde owl say?",
            "What, what?",

            "What do you call a zit on a blonde's ass?",
            "A brain tumor.",

            "What do you get when you turn 3 blondes upside-down?",
            "Two brunettes.",

            "What's the Blonde's cheer?",
            "I'm blonde, I'm blonde, I'm B.L.O.N....ah, oh well.. I'm blonde, I'm blonde, yea yea yea...",

            "Why did the blonde scale the chain-link fence?",
            "To see what was on the other side.",

            "Why did the blonde fail at being a prostitute?",
            "Because she gave blow-jobs literally.",

            "Why did the blonde smile when she walked the marriage aisle?",
            "She realized she gave her last blowjob.",

            "Why do blondes give such good blowjobs?",
            "Because that's what they train for all their lives.",

            "Why did the blonde tattoo her zip code on her stomach?",
            "So her male would get delivered to the right box.",

            "Why did the blonde have tire tread marks on her back?",
            "From crawling across the street when the sign said 'DON'T WALK'.",

            "Why did the blonde keep a coat hanger in her back seat?",
            "In case she locks the keys in her car.",

            "Why did the blonde tip-toe past the medicine cabinet?",
            "So she wouldn't wake up the sleeping pills.",

            "Why did the deaf blonde sit on a newspaper?",
            "So she could lip read.",

            "Why did God create blondes?",
            "Because sheep can't bring beer from the fridge.",

            "Why did the blonde wear condoms on her ears?",
            "So she wouldn't get Hearing Aids.",

            "Why did the blonde drive into the ditch?",
            "To turn the blinker off.",

            "Why did the blonde try and steal a police car?",
            "She saw '911' on the back and thought it was a Porsche.",

            "Why didn't the blonde want a window seat on the plane?",
            "She'd just blow dried her hair and she didn't want it blown around too much.",

            "Why did the blonde stop using the pill?",
            "Because it kept falling out.",

            "Why did the blonde get so excited after she finished her jigsaw puzzle in only 6 months?",
            "Because on the box it said From 2-4 years.",

            "How do you confuse a blonde?",
            "Ask her to alphabetize a bag of M&Ms.",

            "Why does making a blonde alphabetize a bag of M&Ms work?",
            "Does 3 come before E or does it go between M and W?",

            "Why did the blonde call the welfare office?",
            "She wanted to know how to cook food stamps!",

            "What is the blonde's favorite potato chip?",
            "Free-to-lay (Frito-Lay).",

            "What is blond, brunette, blond, brunette, ....?",
            "A blond doing cartwheels.",

            "What is the connection between a blonde and a halogen headlamp?",
            "They both get screwed on the front of a Ford Escort.",

            "Did you hear about the blond skydiver?",
            "She missed the Earth!",

            "Did you hear about the blond who had two chances to get pregnant?",
            "She blew it both times!",

            "What do a moped and a blond have in common?",
            "They're both fun to ride until a friend sees you on one.",

            "How do you know when a blond's been in your fridge?",
            "Lipstick on the cucumbers!",

            "What do a blonde and an instant lottery ticket have in common?",
            "All you have to do is scratch the box to win.",

            "What is the difference between a blonde and an inflatable doll?",
            "About 2 cans of hair spray",

            "What's the quickest way to get into a blondes pants?",
            "Pick them up off the floor.",

            "Where do blondes go to meet their relatives?",
            "The vegetable garden.",

            "How many blondes does it take to play tag?",
            "One.",

            "What do you call four Blondes in a Volkswagon?",
            "Far-from-thinkin.",

            "Why don't they let Blondes swim in the ocean?",
            "Because they can't get the smell out of the tuna.",

            "What happened to the blonde tap dancer?",
            "She slipped off and fell down the drain.",

            "What is the irritating part around a blonde's vagina?",
            "The other guys waiting their turn.",

            "What did the blonde say when asked if she'd ever been picked up by 'the fuzz'?",
            "'No. But I've been swung around by the tits.'",

            "What did the blonde say when she looked into a box of Cheerios?",
            "Oh look! Donut seeds!",

            "What did the blonde name her pet zebra?",
            "Spot.",

            "What's a blonds' favourite rock group?",
            "Air Supply.",

            "Whats black and fuzzy and hangs from the ceiling?",
            "A blond electrician.",

            "Why are dumb blonde jokes so short?",
            "So brunettes can remember them.",

            "Why are blondes like cornflakes?",
            "Because they're simple, easy and they taste good.",

            "Why can't blondes put in light bulbs?",
            "They keep breaking them with the hammers.",

            "What is a cool refreshing drink for a blonde?",
            "Perri-air.",

            "Did you hear about the blonde coyote?",
            "Got stuck in a trap, chewed off three legs and was still stuck.",

            "When is it legal to shoot a blonde in the head?",
            "When you have a tire pump to reinflate it!",

            "What is a blonde's favorite part of a gas station?",
            "The Air Pump!",

            "Why was the blonde upset when she got her Driver's License?",
            "Because she got an F in sex.",

            "Did you here about the blonde who shot an arrow into the air?",
            "She missed.",

            "Why can't blondes be cattle ranchers?",
            "They can't keep their calves together!",

            "When does a brunette have 1/2 of a brain?",
            "After a dye job.",

            "What's a blonde's favorite nursery rhyme?",
            "Humpme Dumpme.",

            "What did the blonde customer say to the buxom waitress (reading her nametag)?",
            "'Debbie'...that's cute. What did you name the other one ?",

            "What goes VROOM, SCREECH,VROOM, SCREECH,VROOM, SCREECH?",
            "A blonde going through a flashing red light.",

            "Why are there lip stick stains on the steering wheel after a blonde drives a car?",
            "Because she blows the horn!",

            "Why is a blonde like a door knob?",
            "Because everybody gets a turn.",

            "Why is a blonde like railroad tracks?",
            "Because she's been laid all over the country.",

            "Did you hear about the blonde lesbian?",
            "She kept having affairs with men!",

            "What does a blonde do if she is not in bed by 10?",
            "She picks up her purse and goes home.",

            "To a blonde, what is long and hard?",
            "Grade 4.",

            "What is the definition of gross ignorance?",
            "144 blondes.",

            "Why is 68 the maximum speed for blonds?",
            "Because at 69 they blow a rod...",

            "What is the difference between a blonde and a refrigerator?",
            "A refrigerator doesn't fart when you pull your meat out of it.",

            "Did you hear about the blonde couple that were found frozen to death in their car at a drive-in movie theater?",
            "They went to see 'Closed for the Winter'.",

            "What is the definition of the perfect woman?",
            "A deaf and dumb blonde nymphomaniac whose father owns a pub.",

            "Why is a blonde like an old washing machine?",
            "They both drip when they're fucked.",

            "How would a blond punctuate the following?: 'Fun fun fun worry worry worry'",
            "Fun period fun period fun NO PERIOD worry worry worry!",

            "Why is the blonde's brain the size of a pea in the morning?",
            "It swells at night.",

            "A blonde is walking down the street with a pig under her arm. She passes a person who asks 'Where did you get that?'",
            "The pig says, 'I won her in a raffle!'",

            "A blonde ordered a pizza and the clerk asked if he should cut it in six or twelve pieces.",
            "'Six, please. I could never eat twelve pieces.'",

            "What's a blonde's idea of safe sex?",
            "Locking the car door.",

            "Why did the blonde keep failing her driver's test?",
            "Because every time the door opened, she jumped into the back seat.",

            "What did the blonde do when she heard that 90% of accidents occur around the home?",
            "She moved.",

            "What's five miles long and has an IQ of forty?",
            "A blonde parade.",

            "Why is it okay for blondes to catch cold?",
            "They don't have to worry about blowing their brains out.",

            "Did you hear about the blonde who tried to blow up her husband's car?",
            "She burned her lips on the tailpipe.",
        });


    }
}


