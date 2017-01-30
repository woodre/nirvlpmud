reset(arg) {
        if(arg) return;
}

 long() {
write("You are looking at what appears to be note written on some sort\n"+
"of leather parchment.  As you look closer, you notice written in\n"+
"in blood at the top is the word HEROIN..the rest appears to be \n"+
"gibberish of some sort.  You feel confident that with some work you\n"+
"could translate the gibberish and then READ the PAPER.  As you begin\n"+
"translating- you stop and think about what's in your hands. You \n"+
"wonder: if the writing is in blood, then that must mean that this\n"+
"leathery paper, must be human flesh....yakk, you lose your lunch.\n");
           return 1;
        }

 short() {
        return "Heroin's paper";
        }
query_auto_load() {
return "/players/heroin/info.c:";
move_object("/room/vill_green.c");
}

id(str) {
        if( str == "paper" ) return 1;
        return 0;
}

init() {
        add_action( "read" , "read");

        return 1;
       }
read(arg)
  {  if (arg=="paper") 
{ write(" Heroin:      \n"+
"By the time this reaches you, our work will be complete.  As you\n"+
"ordered I have assembled for you the ultimate hunt.  I have gathered\n"+
"from far and wide a plethera of the most honorable and pathetic \n"+
"creatures, I have ever had the pleasure of hunting.  The creatures\n"+
"vary in strength and endurance, however hunters under level 12 will\n"+
"most likely find themselves as trophys..DEAD.  As you instructed\n"+
"the rewards of the hunt are both many and generous.  As to keep it\n"+
"entertaining...I have located it where mere mortals can stumble upon it.\n"+
"From their church, I have placed it 1s,4w,2n,1w.  May their Gods\n"+
"have mercy upon their unfortunate souls.\n"+
"Also, for the less advanced, there is a new NEWBIE zone.  All they have to do\n"+
"is type NEWBIE in the main room....hehhehehehehhheheheheh\n"+
"Your Humble Servant,\n"+
"Angst, the GameMaster\n");
      return 1;
     }
   else { return 0; }
}


get() {
write("Dont ya want to share with others...piggy?\n");
        return 0;
}

drop() {
        return 0;

}
