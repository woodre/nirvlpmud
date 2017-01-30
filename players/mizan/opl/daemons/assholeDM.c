#include "../definitions.h"
#include "/obj/ansi.h"

string *snaps_fat;
string *snaps_misc;
string *snaps_nasty;
string *snaps_stupid;
string *snaps_ugly;
string *snaps_old;
string *snaps_poor;

get() {
    return 0;
}
short() {
    return "A server named (mamasnaps)";
}
id(str) {
    return str == "mamasnaps" || str == "server";
}

query_snap_fat() {
    return snaps_fat[random(sizeof(snaps_fat))];
}

query_snap()
{
    int i;
    i = random(9);

    switch (i)
    {
    case 1:
        return query_snap_fat();
    case 2:
        return query_snap_nasty();
    case 3:
        return query_snap_stupid();
    case 4:
        return query_snap_ugly();
    case 5:
        return query_snap_old();
    case 6:
        return query_snap_poor();
    default:
        return query_snap_misc();
    }
}

reset(arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);
    if (arg) return;

    snaps_fat = ( {
 
	"Your family tree must be a cactus because everybody on it is a prick.",
	"You must have been born on a highway because that's where most accidents happen.",
	"Your birth certificate is an apology letter from the condom factory.",
	"Why don't you slip into something more comfortable -- like a coma.",
	"You do realize makeup isn't going to fix your stupidity?",
	"I'd like to see things from your point of view but I can't seem to get my head that far up my ass.",
	"Am I getting smart with you? How would you know?",
	"I don't exactly hate you, but if you were on fire and I had water, I'd drink it.",
	"You are proof that God has a sense of humor.",
	"It's better to let someone think you are an idiot than to open your mouth and prove it."
	"Do you wanna lose ten pounds of ugly fat? Cut off your head.",
	"Shut up, you'll never be the man your mother is.",
	"I love what you've done with your hair. How do you get it to come out of the nostrils like that?",
	"Well I could agree with you, but then we'd both be wrong.",
	"You are so old, your birth-certificate expired.".
	"I look into your eyes and get the feeling someone else is driving.",
	"Come again when you can't stay quite so long.",
	"You are so stupid, you'd trip over a cordless phone.",
	"If assholes could fly, this place would be an airport!",
	"Are you always an idiot, or just when I'm around?",
	"Don't you need a license to be that ugly?",
	"You stare at frozen juice cans because they say, 'concentrate'.",
	"You're as useless as a screen door on a submarine.",
	"So, a thought crossed your mind? Must have been a long and lonely journey.",
	"You may not be the best looking girl here, but beauty is only a light switch away!",
	"Do you still love nature, despite what it did to you?",
	"Looks like you traded in your neck for an extra chin!",
	"Ordinarily people live and learn. You just live.",
	"You are so old, you fart dust.",
	"You occasionally stumble over the truth, but you quickly pick yourself up and carry on as if nothing happened.",
	"If I want your opinion, I'll give it to you.",
	"Aww, it's so cute when you try to talk about things you don't understand.",
	"You are proof that evolution CAN go in reverse.",
	"If you spoke your mind, you'd be speechless.",
	"Shock me, say something intelligent.",
	"I may be fat, but you're ugly, and I can lose weight.",
	"I heard you took an IQ test and they said you're results were negative.",
	"Jesus loves you, everyone else thinks you're an asshole!",
	"I wish you no harm, but it would have been much better if you had never lived.",
	"If a crackhead saw you, he'd think he needs to go on a diet.",
	"Being around you is like having a cancer of the soul.",
	"I've seen people like you, but I had to pay admission!",
	"Learn from your parents' mistakes - use birth control!",
	"If what you don't know can't hurt you, you're invulnerable.",
	"It looks like your face caught on fire and someone tried to put it out with a hammer.",
	"Hey, you have somthing on your chin... no, the 3rd one down.",
	"Don't feel sad, don't feel blue, Frankenstein was ugly too. 		20
	"We all sprang from apes, but you didn't spring far enough. 		10
	"If you had another brain, it would be lonely. 		7
	"I don't know what makes you so stupid, but it really works! 		9
	"Even if you were twice as smart, you'd still be stupid! 		4
	"Brains aren't everything. In your case they're nothing. 		7
	"The best part of you is still running down your old mans leg. 		7
	"You're as useful as an ashtray on a motorcycle. 		6
	"When was the last time you could see your whole body in the mirror? 		6
	"Maybe if you ate some of that makeup you could be pretty on the inside. 		6
	"I'd like to help you out. Which way did you come in? 		6
	"Your mom must have a really loud bark! 		3
	"Is your name Maple Syrup? It should be, you sap. 		11
	"Are your parents siblings? 		16
	"Just reminding you there is a very fine line between hobby and mental illness. 		5
	"You act like your arrogance is a virtue. 		4
	"Ever since I saw you in your family tree, I've wanted to cut it down. 		5
	"Beauty is skin deep, but ugly is to the bone. 		6
	"I hear the only place you're ever invited is outside. 		19
	"100,000 sperm, you were the fastest? 		3
	"You must think you're strong, but you only smell strong. 		2
	"Yeah you're pretty, pretty stupid 		1
	"Nice tan, orange is my favorite color. 		2
	"Your parents hated you so much you bath toys were an iron and a toaster 		1
	"You'll make a great first wife some day. 		2
	"Please tell me you don't home-school your kids. 		9
	"For those who never forget a face, you are an exception. 		4
	"You're the reason why women earn 75 cents to the dollar. 		4
	"When anorexics see you, they think they need to go on a diet. 		6
	"You are so old, even your memory is in black and white. 		11
	"People like you are the reason I work out. 		4
	"You're stupid because you're blonde.
    });

}
