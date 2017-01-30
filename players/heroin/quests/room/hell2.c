#include "room.h"
 
object god, heroin;
realm() {return "NT";}
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
extra_reset() {
    object money;
    if (!god || !living(god)) {
        god = clone_object("obj/monster_lars");
        call_other(god, "set_name", "SATAN");
        call_other(god, "set_level", 100);
        call_other(god, "set_hp", 99999);
        call_other(god, "set_wc", 50);
        call_other(god, "set_al", -1000);
       call_other(god, "set_ac", 50);
        call_other(god, "set_short", "SATAN : Any explanation really needed?");
        call_other(god, "set_long",
                       "This is THE fallen Angel himself, in all his glory. \n" +
"You cannot defeat him with your wit or with you\n"+
                      "sword.  You better hope you know what you're doing!\n");
        move_object(god, this_object());
    }
}
 
ONE_EXIT("players/heroin/quests/room/hell1.c", "leave",
      "THE PRINCE OF << DARKNESS >>",
"This is it! You are standing in front of the main man himself.\n" +
"He is pissed, you better do something soon!!\n" +
"Hope you brought the right equipment!?!?.\n",1)
 
init() {
  ::init();
  add_action("read","read");
}
 
read(){
object parch;
if(present("parchment",this_player())) {
write("Scrambling for an answer, and in desperation you pull the\n");
write("piece of parchment from your pocket.  Even though you have\n" +
"tried to read it before, it suddenly makes sense:  In perfect tone.\n\n\n" +
"you read the paper:  \n" +
"(parts of it now missing..you're so careless!)\n"+
"<<< Death and Hatred to mankind>>\n"+
"<< Poisoning our brainwashed minds>>\n"+
"<< Day of Judgement--God is calling>>\n"+
"<< On their knees the warpigs crawling>>\n"+
"<< Begging mercy for their sins>>\n"+
" \n"+
"Suddenly, Satan reaches down and snatchs\n"+
"the parchment from your hands...\n"+
"He laughs and spreads his wings\n"+
"Congratulations, You have Completed this Quest.\n"+ 
"You have solved my riddle..Now by the rules of the hunt\n"+
"I can destroy Angst and his petty Masters.\n"+
"You have inevertinately led to your masters' and the demise.\n"+
" of the whole human race....\n"+
" THANK YOU....AND HAVE A NICE DAY!\n");
parch = present("parchment",this_player());
destruct(parch);
this_player()->set_quest("*sabbath*");
/* DO NOT CHANGE THE QUEST NAME AGIAN DAMMIT. LEAVE it this way FOREVER.
   change it agian and make more work for me and I WILL demote.
   I have had to deal with this changing back and forth 4 times now!
   -Bp
*/
return 1;
}
else {
write("What?? What do you want to read your silly bible!!! \n"+
"I'm sorry but its way too late for that!.\n");
write("Go pray with the other silly mortals!\n");
move_object(this_player(),"room/church");
command("look",this_player());
return 1;
}
}    
