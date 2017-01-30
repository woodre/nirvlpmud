#include "../definitions.h"
#include "/obj/ansi.h"


string *my_stories;
int current_story;
int story_pointer;

get() {
    return 0;
}

short() {
    return "A server named (opl)";
}
id(str) {
    return str == "opl" || str == "server";
}

string get_story() 
{
    return my_stories[random(sizeof(my_stories))];
}

string tell_story()
{
    string result;

    if (story_pointer == (sizeof(my_stories) - 1))
        story_pointer = 0;

    result = HIY + U + my_stories[story_pointer] + NORM + NORM + "\n" ;
    story_pointer ++;
    return result;
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    story_pointer = 0;

    if (!arg)
    {
        my_stories = ({

              "There was the one time I had to go to a Halloween party...",
              "My buddies wanted someone in a full body mascot costume...",
              "But I did them better, I just showed up as myself! Ha ha ha...",
              "Well, I did wear a Detroit Pistons jersey and had a giant foam finger.",
              "The prank we were pulling involved me popping out of a closet to scare people.",
              "While waiting for the next victim in the closet, a couple barged in...",
              "They saw me there and laughed, assuming I was a decoration...",
              "So then proceeded to have sex in the closet...",
              "Five minutes later: 'BOO!'",

              "Ha! Ha! Ha!",
              "Yeah, you should have seen the look on their faces, it was CLASSIC!",
              "You really should pace yourself though!",
              "Anyway...",

              "I'm not really into trash talking, but this is my favorite NBA trash talking story...",
              "The Celtics were playing the Pacers on Christmas day...",
              "Before the game, during warmups, Larry Bird went over to Chuck Person to make a little conversation.",
              "He told Chuck that he had a Christmas present for him, which he would give him later...",
              "At one point on the game, Chuck was on the Pacers' bench to get a little rest...",
              "Bird had the ball, and went to the three point line, right next to where Chuck was sitting.",
              "He looked at Chuck...",
              "He shot the ball, while looking at Chuck...",
              "He said \"Merry fuckin' Christmas.\"",
              "Swoosh.",
              "Ha ha ha! Gotta love 'Larry Legend'. Even if you're not a Celtics fan you have to appreciate that.",
              "He's definitely the trash talking KING!",


              "That reminds me of something that happened way back...",

              "Once I tried inventing a new sport...",
              "...it involved a cross between badminton and hand grenades.",
              "I called it 'Badass-minton'.",
              "It didn't work out too well. I lost half the volunteers who signed up in just one day.",

              "Hey, I got another joke here...",
              "Long ago lived a seaman named Captain Bravo. He was a manly man who showed no fear in facing his enemies.",
              "One day, while sailing the seven seas, a lookout spotted a pirate ship and the crew became frantic.",
              "Captain Bravo bellowed, \"Bring me my red shirt!\"",
              "The first mate quickly retrieved the captain's red shirt and while wearing the bright red frock Bravo led his men into battle and defeated the pirates.",
              "Later on that day, the lookout spotted not one, but two pirate ships.",
              "The captain again called for his red shirt and once again, though the fighting was fierce, they was victorious over the two ships.",
              "That evening, all the men sat around on the deck recounting the day's triumphs and one of them asked the captain, \"Sir, why do you call for your red shirt before battle?",
              "The captain replied, \"If I am wounded in the attack, the shirt will not show my blood and thus, you men will continue to fight, unafraid.\"",
              "All of the men sat in silence and marveled at the courage of such a manly man as Captain Bravo.",
              "As dawn came the next morning, the lookout spotted not one, not two, but TEN pirates ships approaching from the horizon.",
              "The first mate asked, \"Shall I bring your red shirt?\"",
              "Captain Bravo calmly replied, \"No. Get me my brown pants.\"",


              "Hah! Well I got another joke, and I'm sure you'll like this one!",
              "An old man is sitting on his porch when he sees a young boy walking down the street dragging something behind him.",
              "He calls out to the boy, \"Hey son, what you got there?\" to which the boy replies, \"It's duct tape, I'm gonna go catch me some ducks.\"",
              "The old man laughs and he calls out, \"You fool, you can't catch ducks with duct tape!\"",
              "The little boy laughs and continues on his way, returning a few short hours later.",
              "Behind him, he is dragging 8 ducks, all wrapped up in the duct tape.",
              "The old man can't believe his eyes.",

              "The next day, the old man is sitting on his porch again and along comes the little boy dragging something behind him.",
              "When the old man asks what he's got this time, the boy replies, \"It's a spool of chicken wire, I'm going to catch some chickens in it.\"",
              "Well the old man begins to laugh quite hard, telling the boy, \"You fool, you can't catch chickens with chicken wire.\"",
              "The boy laughs himself, and says back, \"That's what you said about the duct tape,\"",
              "He continues on his way, with the old man laughing like crazy.",
              "A few hours later the old man is surprised to see the boy coming back.",
              "He is even more shocked to see that behind him he is dragging 10 chickens, all tangled up in the chicken wire.",
              "He simply can't believe his eyes again.",

              "The next day, the old man is sitting there wondering what the little boy will be up to next.",
              "Sure enough he sees him coming down the street with something in his hand.",
              "He calls out to the boy, \"Hey son, what you go there today?\"",
              "The boy responds, \"It's a pussy willow.\"",
              "The man then replies, \"Hang on son, I'll get my hat!\"",

              "Oh yeah, I got another one!",
              "Check this one out...",

              "One day there was a hippie who got on a bus.",
              "The bus was very crowded and the man took a seat next to a young nun.",
              "He was very attracted to the nun, because she was surprisingly beautiful.",
              "After getting his courage up, he finally said to the nun \"Wanna fuck?\"",

              "The nun, disgusted, told the bus driver to stop the bus and she got off.",
              "The man was very disappointed and he moved up to the front of the bus to wait for his stop.",

              "Seeing that the young hippie was upset, the bus driver decided to help him out.",
              "He said to the young man, \"I know that nun. Every night, she goes to the grave yard at 9:00 to pray at the grave of her friend.\"",
              "\"If you go there and pretend that you are Jesus, there is no way she would turn down God.s request.\"",
              "\"Just tell her that you are Jesus and ask her to have sex with you.\"",

              "This gave the hippie great hope.",
              "That night, he went to the graveyard, and sure enough, there was the nun.",
              "As she kneeled down, he decided to make his move.",
              "He walked over to her, dressed in a white robe with a hood and said to the nun \"I am Jesus Christ, you will have sex with me!\"",
              "Now, of course the nun could not deny the power of God, so she agreed. \"I just have one request,\" said the nun, \"it has to be anal sex, so I can remain a virgin and continue in my sisterhood.\"",
              "The disguised hippie agreed and the two had sex.",

              "When they were done, the man thought that it would be funny to reveal his identity to the nun.",
              "He took off his robe, revealing himself.",

              "\"HA HA you dumb bitch!! I'm not Jesus, I'm the hippie!\" He exclaimed.",

              "Much to the young man.s surprise, the nun took off her gown, revealing a gray jumpsuit. Laughing, she yelled \"HA HA! I'm not the nun, I'm the bus driver!\"",


        });


    }
}

