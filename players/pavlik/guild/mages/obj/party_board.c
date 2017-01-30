#include "/players/pavlik/closed/colors.h"
#define NOTES "players/pavlik/mages/obj/party_notes"
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
 return str == "bulletin board" || str == "board" || str == "bboard" ||
 str == "book" || str == "journal" || str == "tome";
}

long(){
 write(
 "The adveturer's journal is a book where Mage's can recount tales of\n"+
 "conquering and cleverness.  The journal contains notes left by other\n"+
 "members of the guild.  You can leave your exciting sotre (or random\n"+
 "thought) with 'note <topic>'.\n");
 if(num_messages == 0){
  write("There are no entries in the journal.\n");
 return;
 }
 write("There are "+num_messages+" entries in the journal.\n");
 say(call_other(this_player(), "query_name")+" leafs through the journal.\n");
 headers();
}

short() {
 return MAG+"The Adventurer's Journal ["+HIM+num_messages+
 " entries]"+NORM;
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
    add_action("new"); add_verb("note");
    add_action("new"); add_verb("post");
    add_action("read"); add_verb("read");
    add_action("remove"); add_verb("remove");
}

reset(arg) {
    if (arg)
        return;
    restore_object(NOTES);
}

headers() {
    string hd, body, rest;
    int i, tmp;

    i = 1;
    rest = messages;
    while(rest != 0 && rest != "") {
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        write(i + ":\t\b\b\b\b\b" + hd + "\n");
        i += 1;
    }
}

new(hd) {
    if (!hd)
        return 0;
    if (who && environment(who) == environment(this_object())) {
        write(call_other(who, "query_name") + " is busy writing.\n");
        return 1;
    }
    if (num_messages == 30) {
        write("You have to remove an old message first.\n");
        return 1;
    }
    if (strlen(hd) > 50) {
        write("Too long header to fit the paper.\n");
        return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Give message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
        string wday,surplus,month,day;
        int number;
        sscanf(ctime(time()),"%s %s %s %d:%s",wday,month,day,number,surplus);
        new_hd = wday+" "+month+" "+day+"\t"+"\b\b| "  +new_hd+
        " ("+capitalize(this_player()->query_real_name()) +")";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object(NOTES);
        write("Ok.\n");
        who = 0;
        return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if (i > num_messages) {
        write("Not that number of messages.\n");
        return 1;
    }
    rest = messages;
    while(rest != 0 && rest != "") {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        if (i == 0) {
            say(call_other(this_player(), "query_name") +
                  " reads a note titled '" + hd + "'.\n");
            write("The note is titled '" + hd + "':\n\n");
            write(body);
            return 1;
        }
    }
    write("Hm. This should not happen.\n");
}

remove(str) {
    string hd, body, rest,contname;
    int i, tmp;
    contname=this_player()->query_real_name();
    if(this_player()->query_guild_rank() < 72) 
    {
    write("You cannot do that.\n");
       return 1;
     }   

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if (i > num_messages) {
        write("Not that number of messages.\n");
        return 1;
    }
    rest = messages;
    messages = "";
    while(rest != 0 && rest != "") {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        if (i == 0) {  
            say(call_other(this_player(), "query_name") +
                  " removed a note titled '" + hd + "'.\n");
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
        save_object(NOTES);
            return 1;
        }
        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}
