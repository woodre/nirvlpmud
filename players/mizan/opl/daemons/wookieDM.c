/*****************************************************************************
 *      File:                   wookieDM.c
 *      Function:               Reponsible for the wookiees
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

#include "../definitions.h"
string *my_wookie_names;
string *my_chats;
string *my_facts;
int fact_bar;

get() {
    return 0;
}
short() {
    return "A server named (wookie)";
}
id(str) {
    return str == "wookie" || str == "server";
}

string get_aargh()
{
    return my_chats[random(sizeof(my_chats))];
}

string get_fact()
{
    string result;
    if (fact_bar == (sizeof(my_facts) - 1))
        fact_bar = 0;

    result = my_facts[fact_bar];

    fact_bar ++;
    return result;
}


string get_name() {
    return my_wookie_names[random(sizeof(my_wookie_names))];
}

void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_wookie_names = ( {
            "Tarfloo",
	    "Arfarf",
            "Arfarfarrrrgh",
	    "Weroshyr",
	    "Lowshyyk",
            "Graasheel",
            "Fartbacca",
	    "Frorral",
            "Saraprragh",
            "Fraagshaag",
            "Rrawbacca",
            "Mrugbacca",
            "Towshyr",
            "Chogtarfloo",
	    "Tarzakka",
            "Mrugtamba",
	    "Fraaagh",
            "Chalmuggra",
            "Flaargh",
            "Nyaarghshyyk",
            "Larshyr",
            "Fragnargh",
            "Towtarfloo",
            "Frorbacca",
            "Saratarfloo",
            "Nanracca",
            "Garbacca",
            "Twinkle Tits",
            "Fangshaarg",
        });

        my_chats = ({
            "AAAaaaaargh!",
            "Wwwwwuuuraaaaaagh!",
        });

        my_facts = ({
"The time difference between when Tyrannosaurus and Stegosaurus lived is greater than the time difference between Tyrannosaurus and now.",
"During the Mongol Empire in the thirteenth and fourteenth centuries, Mongolian forces were fighting Germans and Japanese at the same time...",
"...and these two peoples had no idea of the others' existence! This wouldn't be attempted again until the 1940s.",
"The pyramids were as old to the Romans as the Romans are to us.",
"In the 1920's Canada had a plan for a surprise invasion of the United States in the event of war.",
"The plan was to move troops as far south as possible then as soon as serious resistance was met retreat to the border using scorched earth tactics.",
"All this was to buy time for assistance from Britain and Japan.",
"The Russo-Japanese War technically lasted over 100 years.",
"When Russia and Japan declared war in 1904, Montenegro was allied with Russia at the time, and also declared war.",
"However, being a tiny principality at the time, Montenegro didn't really participate in the war other than sending a few volunteer troops.",
"When the Treaty of Portsmouth was signed in 1905, Montenegro's involvement was overlooked.",
"It wasn't until 2006 that Japan and Montenegro realized they were technically still at war, and another peace treaty was signed.",
"In about 240 B.C.E., the Greek mathematician Eratosthenes calculated, with astounding accuracy for his time, the circumference of the earth.",
"According to Wikipedia, he came up with the measurement of about 252,000 'stadia.'",
"Though the exact size of said 'stadion' is in dispute, historians believe he would have used the measurement of the then contemporary Egyptian stadion.",
"He did after all, conduct his measurements in Egypt. Such a stadion would have measured about 157.5 meters.",
"This puts his measurement for the earth's circumference at about 39,690 kilometers, astoundingly close to our current measurement of 40,075 km.",
"Columbus's detractors were absolutely correct. He was trying to sail to the East Indes, remember, and went against the scholarly consensus of the day (incorrectly) on three counts.",
"He underestimated the earth's circumference to be 30,200 km because he didn't realize the estimates he were using were in Arabic miles.",
"He overestimated the size of the Eurasian landmass, and overestimated the distance between Japan and continental Asia.",
"If he hadn't run into the Americas, he would have starved to death as predicted.",
"When Inuits were first discovered they had no idea there were other humans on the planet.",
"In Australia, the Aboriginal Kuuk Thaayore people use compass directions for every spatial cue.",
"For example, 'There is an ant on your southeast leg.' The people's traditional greeting is 'Where are you going?'.",
"Essentially this required that each person be familiar with the cardinal directions at all times.",
"Perhaps as a result, these people have been shown to be more skilled at dead reckoning than any other population.",
"When asked to order a set of picture cards, they instinctively arrange them not from left to right or right to left, but from east to west, no matter what direction they are facing.",
"Shortly before the assassination of Abraham Lincoln by John Wilkes Booth, Lincoln's son Robert was in New Jersey at a train station when he fell off of the platform and on to the tracks.",
"Immediately a hand reached down and grabbed his collar, pulled him back onto the platform, and saved his life.",
"Who was the man who saved him? None other than Edwin Booth, the older brother of John Wilkes Booth.",
"It's worth noting that Edwin did not recognize Robert; in fact it was the other way around.",
"Edwin was a renowned actor and Robert immediately recognized who he was. Edwin did not find out who he had saved until much later.",
"That John Tyler (10th president born 1790) has two living GRANDSONS as of March 2011.",
"Tyler has two living grandsons through his son Lyon Gardiner Tyler (1853.1935). Lyon Gardiner Tyler, Jr., was born in 1924, and Harrison Ruffin Tyler was born in 1928.",
"Mississippi didn't ratify the 13th amendment (Prohibition of slavery) until 1995, only 16 years ago.",
"In Europe between the 14th and 17th centuries, people were occasionally afflicted with 'dancing mania,' in which large groups would begin to dance in the streets, as if in a trance.",
"Often they would dance until the point of passing out. The phenomenon is well documented and is largely not understood.",
"Several hundred years ago, a group of Maori set sail from New Zealand into the unknown South Pacific.",
"Whether by luck or skill, they landed on a remote archipelago known now as the Chatham Islands, some 500 miles away.",
"They lost all contact with their fellow tribesmen on New Zealand and formed a tight-knit, egalitarian community known as the Moriori and lived in peace for over 100 years.",
"Then, one day in the 1830s, a group of Maori, who had by this point established contact with English settlers, hitched a ride on a seal-hunting ship and sailed back to the same island.",
"Seeing its potential as a settlement, the Maori, as was their custom, slaughtered or enslaved every single Moriori. The Moriori did not fight back; they had never known violence.",
"In 1842, a merchant ship called the 'Mary Celeste' was discovered completely abandoned in the Atlantic ocean.",
"The cargo was almost completely untouched and there was more than enough food and water. No sign of struggle, mutiny etc. The crew never turned up. ",
"During 14th century Korea, Admiral Yi Sun Shin singlehandedly stopped the Japanese invasion during Japans conquest of Asia.",
"In 26 naval battles, he didnt lose once and achieved flawless victory. Every battle, he was outnumbered, some times 100:1.",
"There were many battles where he takes a handful of ships (13), and defeats hundreds upon hundreds.",
"He was able to do this because he was a master tactician and used every advantage he could find whether it was wind direction, tide changes, boat formation, and natural geography.",
"His achievements in history is unparalleled, yet not many people have heard of this man due to his birth surroundings.",
"The Spaniards landed in a world where people breathed fire (smoking tobacco) had hot and cold running indoor plumbing and built structures that dwarfed anything in Europe.",
"The population of Tenochtitlan was around 150k where as London at the time was around 50,000.",
"When asked why they needed so much gold Cortes replied, 'Because we Spaniards have a disease called greed which only gold can cure'",
"In a single afternoon, 40 thousand Roman soldiers were slaughtered by Hannibal at the battle of Cannae.",
"A slaughter of this proportion in a single afternoon wasn't matched until World War 1.",
"When Hannibal led his forces through the Alps, he got to a point where the war elephants couldn't pass.",
"Hannibal said fuck it, built some roads for his elephants and went on his way. The Roman defense against war elephants was to cut off their trunk and cause them to panic.",
"A more common defense against elephants was to drench pigs in tar and light them on fire.",
"Apparently elephants hate both fire and pigs burning alive that must make some disturbing sounds.",
"It dates to the 200s AD, and is from the Kushan Empire in what's now Afghanistan and Pakistan.",
"On it is written 'BODDO' in Greek letters ... around a figure readily recognizable as Buddha.",
"Around the same time that Christianity was taking over the Roman Empire, there was a Greek-speaking Buddhist civilization in central Asia.",
"These were the ancestors of the folks who built those giant Buddha statues that the Taliban blew up a few years ago.",
"They spoke the same language as classical Western civilization; they certainly traded with the Roman Empire.",
"There never was a hard boundary between 'Eastern' and 'Western' civilizations, and there are not hard boundaries between nations or cultures today.",
"There was, and is, a constant exchange of ideas, goods, language, and people amongst adjacent human settlements throughout the world.",
"People are not even remotely so different from one another as they pretend to be.",
"There are records of Buddhist monks traveling around the Roman empire around the time that Jesus is said to have been alive.",
"This is especially interesting given the many similarities between Christianity and Buddhism.",
"Back in 401 BC, Cyrus I, a usurper to the Persian throne hired ten thousand Greek mercenaries to help him in his takeover.",
"Starting in Sardes on the Ionian coast, Cyrus and the Army of the Ten Thousand, as they were bad-assedly known, enjoyed a successful campaign across the Persian empire until Cyrus was killed at the battle of Cunaxa.",
"The Ten Thousand (their numbers now around 6,500) were then betrayed by Tissaphernes, one of Cyrus' allies and their generals were captured and executed.",
"Instead of surrendering, the Ten Thousand elected their own leaders and went about the business of fighting their way out of the empire to the Black Sea port of Trebizond, over 400 miles away, across deserts and through mountains, fighting off the Persian army the entire way.",
"About 70000 years ago the human population was reduced to near extinction, about 2000 individuals.",
"They also theorize that if that Spanish flu had broken out in the middle ages instead of the Bubonic Plague we might not have made it either.",
"Puma Punku was an ancient site in South America similar to Pyramids in Egypt.",
"However, Puma Punku was built by an ancient civilization that has no trace of written language, let alone geometry, to construct these structures.",
"Although the structures do not stand today, the remains of them are startling.",
"Cleopatra lived closer in time to us than she did to the creation of the Pyramids.",
"Cleopatra was the first member of her dynasty to bother to learn Egyptian. They'd been ruling Egypt for almost 300 years.",
"On March 30, 1981 there was an assassination attempt on President Reagan.",
"Jerry Parr was one of the Secret Service agents on duty, in fact he was the one that pushed President Reagan into the limousine after hearing the gunshots.",
"While driving back to the White House (standard procedure since at the time it was believed the President was uninjured), Agent Parr noticed that the President was bleeding and ordered the limo to immediately turn around and go to George Washington Hospital.",
"This decision no doubt saved President Reagan's life.",
"Agent Parr had wanted to be in the Secret Service since a young boy, when he watched a 1939 movie called 'Code of the Secret Service', with a young unknown actor playing the part of Agent Brass Bancroft.",
"That actor made some more movies and eventually entered politics, becoming Governor of California and later..... President of the United States.",
"Indeed, a young Ronald Reagan played a role in a movie which caused a young boy to make a career choice - and then save the actor president's own life 42 years later.",
"The Japanese attacked the mainland US multiple times, from shellings from submarines to incendiary bombs on balloons.",
"The captain of a Japanese submarine actually attacked Santa Barbara, CA. The Japanese also captured US territory (The Aleutian Islands in Alaska) as a way to trick the US in to dispatching carriers to the islands.",
"The Japanese wanted to trap the US carriers and sink them, but the US code breakers used ingenious techniques to figure out the plan, and in turn surprised the Japanese fleet at Midway, sinking 3 of Japan's 4 largest carriers.",
"There are many sunken German U boats right off the coast of the US, many within easy diving distances.",
"These are protected by international law as grave sites since many are still sealed with the bodies of the sailors.",
"There were many Japanese soldiers that didn't know of the surrender, and kept fighting on for decades.",
"Teruo Nakamura was the last Japanese soldier to surrender in 1974.",
"The Luftwaffe were insanely far along in their aviation and missile designs.",
"The reasons why we were able to get to the moon, have great jets, and our early missile technology were mainly from German scientists that were taken to the US or Russia after WWII.",
"The MiG-15, the workhorse of the Soviet Union, was primarily of German designs. The Germans were years ahead of their time, especially with fighter jets.",
"Bayer, the major German pharmaceutical company that made the origin aspirin, tested this drug and many others forcefully and through disgusting experiments on Jews and others in concentration camps.",
"A good amount of medical knowledge is known today from horrifying human experimentation on live and fully aware individuals in the concentration camps.",
"There is the story of Wojtek, the beer drinking soldier bear. He was officially a soldier, carried munitions, drank beer, ate cigarettes, and wrestled with humans.",
"He served with distinction carrying artillery shells alongside soldiers of the Free Polish Army in the Allied offensive during the battle of Monte Cassino.",
"Singapore was the most important British territory during the start of WWII. It was pretty much a fortress that was heavily armed and ready for any sort of naval attack.",
"The British could never imagine Malaysia could be invaded and the Japanese trek the jungles to invade Singapore, which they did.",
"The Malay jungles were insanely dense, but instead of trekking through them, the Japanese stole 30,000 bikes from the Malays and biked their way all the way to Singapore.",
"On Singapore, they had a bunch of battleship type cannons that were armed with penetrative shells meant for ships, but not explosive shells meant for infantry.",
"They turned the cannons away from the sea, but failed to stop the Japanese. 80,000 British led troops failed to stop 30,000 Japanese, and it was the largest British surrender in their history.",
"Eugenics was practiced in two Canadian provinces during the 1930's. This was due to the Sexual Sterilization Act  , and occurred in Alberta and British Columbia.",
"Thousands of individuals were sterilized against their will due to their race, IQ, unemployment, mental illness, or many other reasons.",
"The day after Thursday, 4 October 1582 was Friday, 15 October 1582. This marked the transition between the Julian calender and the Gregorian calender.",
"Basil I was born as an Armenian peasant to parents held captive by the Bulgarian Khan.",
"He eventually escaped back to Byzantine territory and became the Byzantine emperor Michael III's bodyguard and companion due to his wrestling prowess.",
"Michael eventually raised Basil up to be co-emperor. When Michael began to favor another courtier, Basil assassinated him and became the sole emperor of one of the most powerful empires in the world.",
"Basil ruled for almost 20 years. The Byzantines considered him one of their greatest emperors and the dynasty he founded ruled over a Byzantine Golden Age.",
"Biologically speaking, grains domesticated humans.",
"It shaped our culture to plant it, water it, fertilize it, and protect it from competing species on every continent on the planet except Antarctica.",
"So complete is human domestication that if grains disappeared now, homo sapiens would likely go extinct.",
"When Alexander the Great decided to attack the city of Tyre, he ran into a problem: Tyre was an island, and he had no boats.",
"No matter; he had his men construct a bridge amidst the hail of arrows from the walls of Tyre. Then he crossed the bridge and conquered the city.",
"2500 years later, the centuries of accumulated silt and sand have turned that man-made bridge into a full-scale, permanent geological feature. Tyre is, to this day, no longer an island",
"Napoleon marched his troops under the Brandenburg Gate in 1804 after he invaded Germany.",
"Hitler marched his troops under the Arc de Triomphe in Paris during WWII as an act of revenge. Europeans have quite long memories.",
        });

    }
}

