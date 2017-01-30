#include "/players/vertebraker/ansi.h"
enable_cmds();
stop_cmds();

#define User environment()
#define TOU(x) tell_object(User, x)
#define QA query_attack()


void do_emote()
{
    while(remove_call_out("do_emote") != -1);
    if(!User || (int)User->query_level() > 19) return;
    if(random(3)) { call_out("do_emote", 1000); return; }
    if(0 == random(4))
      TOU("You hear a voice calling to you...\n");
    else if(0 == random(4))
      TOU("The mark of Shardak spreads warmth around your body.\n");
    else if(0 == random(4))
      TOU("Your veins pulse with the blood of the dark gods.\n");
    else if(0 == random(4))
      TOU("Your lips twist into a crooked grin...\n");
    else if(!random(10000))
    {
      if(User->QA) return;
TOU(
"Your vision goes blank..\n\n\
You miss Gabriel.\n\
<<<<  HP 45302/58602 SP 425/58602 I 0% F 0% S 0% T 0% AHP 6/10 >>>>\n\
Gabriel smiles at you and casts a spell of calming.\n");
      stop_cmds();
      call_out("part_two", 4);
    }
    else
    {
      TOU("The goodness in your soul seems to dissipate...\n");
      User->add_alignment(-(random(25)));
    }
    call_out("do_emote", 1000);
}

void part_two()
{
    if(!User) return;
    TOU(
"Gabriel says, \"Why must we fight, brother?  You know Father\n\
will just destroy you!\"\n");
    call_out("part_three",3);
}

void part_three()
{
    if(!User) return;
    TOU(
"You say, \"He shunned me.. I was one of HIS chosen!  And he would\n\
hold those lifeless creatures down on that disgusting world of Nirvana\n\
in such high regard!\"\n");
    call_out("part_four",3);
}

void part_four()
{
    if(!User) return;
    TOU(
"Gabriel shakes his head.\n\
\"Didn't Father teach you anything?  The Creatures are the Plan...\n\
we are only messengers!\", Gabriel replies.\n");
   call_out("part_five",3);
}

void part_five()
{
    if(!User) return;
    TOU(
"You say, \"Then I wish no longer to be part of this...\"\n\
You chant quietly...\n");
    call_out("part_six",3);
}

void part_six()
{
    if(!User) return;
    TOU(
"Gabriel says, \"Wait!  Shardak!  No!\"\n\
Gabriel leaps at you wildly!\n");
    call_out("part_seven",4);
}

void part_seven()
{
    if(!User) return;
    TOU(HIR + 
"\n\n\tHUGE BALLS OF FLAME RAIN DOWN FROM THE SKY!\n\n\n" + NORM);
    TOU(
"Gabriel leaps back and glances toward the heavens...\n\
At the last moment, he kneels down in prayer...\n");
    call_out("conclusion", 3);
}

conclusion()
{
    if(!User) return;
    TOU(
"Gabriel is engulfed in flames!\n\n\
Gabriel screams in torturous agony and explodes in a puff of smoke!\n");
    TOU(
"You laugh maniacally...\n\n\
Suddenly, your vision comes back into focus.\n");
    enable_cmds();
}

