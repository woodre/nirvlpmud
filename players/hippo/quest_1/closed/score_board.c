#include "/players/hippo/rvd.h"
string messages, new_name;
int num_messages, new_score;
object who;
#define SCORES "players/hippo/quest_1/highscores"

id(str) { return str == "scores"||str=="board"; }
init() {
    add_action("add","add");
    add_action("destroy","destroy");
    add_action("remove","remove");
    add_action("help","help");
    return 1;
}
short() {return ("Hippo's Brain Game Highscore Board.");}
long() {
    write("Hippo's Brain Game Highscore Board.\n");
    if (num_messages == 0) {
        write("The high score list is empty.\n");
        return;
    }
    write("   name          score     name          score"+
          "     name          score\n");
    headers();
}
get() {write("You can't get that board!\n") ;return 0;}
drop() { return 1; }

help(str)
{   if(str=="scores")
    { if(CTP=="Hippo")
        {   write("Possible commands:\n"+
            "   help scores                  -> this message\n"+
            "   add <score> <name>           -> add a player and a score\n"+
            "   remove <num>                 -> remove that score number\n"+
            "   destroy scores               -> destroy the entire scorelist\n");
            return 1;
        }
    }
}
newsc(arg) {
    string rest,name,new_name;
    int tmp,high_score,new_score;
    if(sscanf(arg,"%d %s",new_score,new_name)!=2)
      { new_name = capitalize(this_player()->query_real_name()); }
    if(!new_score) {
        write("Hey.. something is wrong.. (newsc part).\n");
              return 0; }
    rest=messages;
    messages="";
    while(rest!="\n" && rest!="" && rest!=0) {
        tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
        if (tmp != 2 && tmp != 3) {
            write("Shit, I can't update the highscore list!!??.\n");
            return 0; }
        if(new_score<high_score) {
            messages=messages+new_name+" "+new_score+"\n"+
                     name+" "+high_score+"\n"+rest;
            save();
            return 1;
        }
        messages=messages+name+" "+high_score+"\n";
    }
    messages=messages+new_name+" "+new_score+"\n";
    save();
    return 1;
}

save() {
    num_messages++;
    new_name = 0;
    new_score = 0;
    save_object(SCORES);
    return 1;
}

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
remove(arg)
{   string name,rest;
    int high_score,i,j,tmp;
    if(this_player()->query_real_name()=="hippo")
    {   rest=messages;
        messages="";
        if(sscanf(arg,"%d",j)!=1)
        {   write("Argument should be the score number to remove.\n");
            return 1;
        }
        for(i=0;i<j-1;i++)
        {   tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
            if (tmp != 2 && tmp != 3) {
                write("Shit, the list is corrupted (remove-part).\n");
                return;
            }
            messages=messages+name+" "+high_score+"\n";
        }
        tmp=sscanf(rest,"%s %d\n%s",name,high_score,rest);
        messages=messages+rest;
        save();
        write("Score "+j+") "+name+" "+high_score+" removed.\n");
        return 1;
    }
    else
    {   write("Hey.. only Hippo is allowed to remove scores!!\n");
        say(capitalize(this_player()->query_real_name())+
            " tried to remove scores!! (But didn't succeed).\n");
        return 1;
    }
}
destroy(arg)
{   if (arg=="scores")
    {   if(capitalize(this_player()->query_real_name())=="Hippo")
        {   messages = "";
            num_messages = 0;
            save_object(SCORES);
            write("done.\n");
            return 1;
        }
        else
        {   write("Hey.. only Hippo is allowed to destroy scores!!\n");
            say(capitalize(this_player()->query_real_name())+
                " tried to destroy the scores!! (But didn't succeed).\n");
            return 1;
        }
    }
    return 0;
}
add(arg)
{   int s;
    string n;
    if (sscanf(arg,"%d %s",n,s)==2)
    {   if(this_player()->query_real_name()=="hippo")
        {   newsc(arg);
            write("done\n");
            return 1;
        }
        else
        {   write("Hey.. only Hippo is allowed to add scores!!\n");
            say(capitalize(this_player()->query_real_name())+
                " tried to add scores!! (But didn't succeed).\n");
            return 1;
        }
    }
    write("Syntax: add <score> <player name>.\n");
    return 1;
}
