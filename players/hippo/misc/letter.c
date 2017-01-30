#include "/players/hippo/bs.h"
id(str) { return str == "letter"; }
reset() {}
long() { write("This is a letter from Hippo. Read it, it's about new stuff.\n");}
short() { return "A 'Read this!' - letter from Hippo."; }
init() {
    add_action("read","read");
}

read (str) {
        if(!str) {
                write("What do you want to read?\n");;
                return 1;
                }
     if(str == "letter") {
write("   *** GAMES ***\n"+
"\nHere is a little note from Hippo about some new games he added to Nirvana\n"+
"lately. You know the '51-brain game' of course, and some of you have\n"+
"already played BlackJack. This BlackJack is a bit changed, which\n"+
"means it has realy become BlackJack now. Besides, there is another\n"+
"cardgame '21' available from the same game-machine now.\n"+
"Completely new is the Oware game. This is a typical African game, which\n"+
"is a two-player-game. You make a stake and can win money from each\n"+
"other, a new challenging element in Nirvana. The best thing to find\n"+
"out how it works is just try it out. I'm sure you will like it, as\n"+
"much as you like '51'.\n"+
"\nWhere to get it?\n"+
"Enter my body: s,8e,shake hand from church. There go 'nose' and you\n"+
"find the game-machine. All you have to do is push one of the buttons\n"+
"and you receive one of those wonderfull games for free!!\n"+
"For questions, complaints or critical comments.. just mail me.\n"+
"\nGreetings, Hippo.\n");
return 1;
}
        return 0;
}

get()  { return 1; }
