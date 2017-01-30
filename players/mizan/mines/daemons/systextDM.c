#include "../definitions.h"
#include "/obj/ansi.h"

string *emptiness_msg;


get() { return 0; }
short() { return "A server named (systext)"; }
id(str) { return str == "systext" || str == "server"; }

reset(arg)
{
	move_object(this_object(), DAEMON_HOME);
	if(arg) return;

}

get_emptiness_msg()
{
	if(!emptiness_msg)
	{
		emptiness_msg = ({
		"You see only the infinite nothingness of the void beyond.",
		"The power of the force stops you, you hoser.",
"A thing of beauty is a joy forever: its loveliness increases; it will never pass into nothingness.",
"Eternal nothingness is fine if you happen to be dressed for it.",
"Every word is like an unnecessary stain on silence and nothingness.",
"God made everything out of nothing, but the nothingness shows through.",
"I wondered a little why God was such a useless thing. It seemed a waste of time to have him. After that he became less and less, until he was... nothingness.",
"If it is nothingness that awaits us, let us make an injustice of it; let us fight against destiny, even though without hope of victory.",
"If you give people nothingness, they can ponder what can be achieved from that nothingness.",
"Nothing is more dreadful in life than the profound thought that death may only greet you with eternal nothingness.",
"Nothingness not being nothing, nothingness being emptiness.",
"One does not kill oneself for love of a woman, but because love - any love - reveals us in our nakedness, our misery, our vulnerability, our nothingness.",
"People have their own deaths as well as their own lives, and even if there is nothing beyond death, we shall differ in our nothingness.",
"Service which is rendered without joy helps neither the servant nor the served. But all other pleasures and possessions pale into nothingness before service which is rendered in a spirit of joy.",
"The feelings of my smallness and my nothingness always kept me good company.",
"The monuments of the nations are all protests against nothingness after death; so are statues and inscriptions; so is history.",
"The world is chaos. Nothingness is the yet-to-be-born god of the world.",
"To pin your hopes upon the future is to consign those hopes to a hypothesis, which is to say, a nothingness. Here and now is what we must contend with.",
"When I write down my thoughts, they do not escape me. This action makes me remember my strength which I forget at all times. I educate myself proportionately to my captured thought. I aim only to distinguish the contradiction between my mind and nothingness. ",
"Nothing proceeds from nothingness, as also nothing passes away into non-existence.",
"Nothing happens until something moves.",
"Why and Wherefore set out one day, To hunt for a wild Negation. They agreed to meet at a cool retreat On the Point of Interrogation.",
"Nothing to do but work, Nothing to eat but food, Nothing to wear out but clothes, To keep one from going nude.",
"Nothing's new, and nothing's true, and nothing matters.",
"It is the silence between the notes that makes the music; it is the space between the bars that holds the tiger.",
"Nothing can be born of nothing, nothing can be resolved into nothing. ",
"It is, no doubt, an immense advantage to have done nothing, but one should not abuse it.",
"They laboriously do nothing.",
"Madam, you have bereft me of all words. Only my blood speaks to you in my veins, And there is such confusion in my powers As, after some oration fairly spoke By a beloved prince, there doth appear Among the buzzing pleased multitude, Where every something being blent together Turns to a wild of nothing, save of joy Expressed and not expressed.",
"It is better to have a little than nothing.",
"A life of nothing's nothing worth, From that first nothing ere his birth, To that last nothing under earth.",
"Nothing, thou elder brother e'en to shade. ",
		});
	}
	else return emptiness_msg[random(sizeof(emptiness_msg))];
}
