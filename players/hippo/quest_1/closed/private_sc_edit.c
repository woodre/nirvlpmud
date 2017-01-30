string messages, new_name;
int num_messages, new_score;
object who;
#define SCORES "players/hippo/quest_1/highscores"

id(str) {
    return str == "scores";
}

long() {
    write("This is the Hippo Brain Game Highscore list.\n");
    if (num_messages == 0) {
        write("The high score list is empty.\n");
        return;
    }
    write(" Rank  player  score\n");
    headers();
}
get() {return 1;}
drop() {return 0;}

short() {
    return ("The Hippo Brain Game Highscore list");
}

init() {
add_action("newsc","new");
add_action ("remove","remove");
add_action("destroy","destroy");
}

reset(arg) {
    if (arg)
        return;
    restore_object(SCORES);
}

headers() {
    string name,rest;
    int high_score;
    int i,tmp;
    i = 1;
    rest = messages;
    while(rest!=0 && rest!="" && rest!="\n") {
      tmp=sscanf(rest,"\n%s\n%d\n%s",name,high_score,rest);
        if (tmp != 2 && tmp != 3) {
            write("Shit, the list is corrupted. Mail Hippo about it!\n");
            return;
        }
        write(" [" +i +"]:\t" + name + "\t"+ high_score + "\n");
        i += 1;
        if(i==11)
            {return;}
    }
}

newsc(hd) {
    string done,rest,name;
    int tmp,i,high_score;
    string new_name;
    int new_score;
    done = "no";
    i=1;
    if(!hd) { return 0; }
        new_name = capitalize(this_player()->query_real_name());
    tmp=sscanf(hd,"%d",new_score);
    rest = messages;
    messages="\n";
    while(rest!="\n" && rest!="" && rest!="0") {
      tmp=sscanf(rest,"\n%s\n%d\n%s",name,high_score,rest);
        if (tmp != 2 && tmp != 3) {
            write("Shit, the list is corrupted. Mail Hippo about it!\n");
            return 0; }
        if(new_score<high_score && done != "yes") {
            i+=1;
            done = "yes";
            messages=messages+new_name+"\n"+new_score+"\n";
        }
            i+=1;
        if(i<11) {
        messages=messages+name+"\n"+high_score+"\n";
        }
    }
    if (messages == "\n") {
        messages=messages+new_name+"\n"+new_score+"\n";
    }
    if(i<11 && done != "yes") {
        messages=messages+new_name+"\n"+new_score+"\n";
        }
        num_messages += 1;
        if (num_messages > 10) {num_messages = 10;}
        new_name = 0;
        new_score = 0;
        save_object(SCORES);
        return 1;
}

destroy(arg)
{   if (arg=="scores")
    {   messages = "";
        num_messages = 0;
        save_object(SCORES);
    return 1;
    }
    return 0;
}
