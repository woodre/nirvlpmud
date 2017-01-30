#include "/players/hippo/rvd.h"
string messages, new_name;
int num_messages, new_score;
object who;
#define SCORES "players/hippo/quest_1/highscores"

id(str) { return str =="scores" || str=="list"; }
short() { return ("Hippo's Brain Game Highscore List");}
long() {
    write("Hippo's brain Game Highscore List.\n");
    if (num_messages == 0) {
        write("The high score list is empty.\n");
        return;
    }
    write("   name          score     name          score"+
          "     name          score\n");
    headers();
}
get() { write("You own it now.\n"); return 1;}
drop() { write("Dropped it.\n"); return 0; }

headers() {
    string name,rest;
    int high_score;
    int i,j,tmp;
    i=0;j=0;
    rest=messages;
    while(rest!=0 && rest!="" && rest!="\n") {
        tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
        if (tmp != 2 && tmp != 3) {
            write("Shit, the list is corrupted (Headers-part).\n");
            return;
        }
        name=extract(capitalize(name+"             "),0,12);

        j++;
        i++;
        if (j==3)
        {   j=0;
            write(i+") "+name+" "+high_score+"\n");
        }
        else
        {   write(i+") "+name+" "+high_score+" \t");
        }
    }
    write("\n");
    return 1;
}
