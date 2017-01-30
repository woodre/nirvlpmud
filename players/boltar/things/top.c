
string namewc;
string description,lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
string auto_load;
string quests;
string gender;
int level, experience, money, age;

finger(str) {
    int days, hours, minutes, seconds;
    quests = 0;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    auto_load = 0;
    if (!str) {
        write("Usage: finger [player name]\n");
        return 1;
    }
    restore_object("players/"+str);
    if (!name) {
        write("That player does not exist.\n");
        return 1;
    }
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
    write(capitalize(name)+" "+description+"\n");
    write("Gender: " + gender +"\n");
    write("Level: "+level+"\n");
    write("Experience: "+experience+"\n");
    write("Money: "+money+"\n");
    write("Quests: "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+called_from_ip+"\n");
    write("Last login was at: "+lastime+"\n");
    show_age();
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    write("Auto Load string is: "+auto_load+"\n");
    return 1;
}

show_age() {
    int i;

    write("Age:\t");
    i = age;
    if (i/43200) {
       write(i/43200 + " days ");
       i = i - (i/43200)*43200;
    }
    if (i/1800) {
       write(i/1800 + " hours ");
       i = i  - (i/1800)*1800;
    }
    if (i/30) {
       write(i/30 + " minutes ");
       i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
}


short()
{
   tell_object(environment(this_object()), this_player()->query_real_name() + " looked at you.\n");
     environment(this_object())->heal_self(50);
     return "A small wood top";
}

query_value()
{
        return 0;
}

  query_weight() {   return 1; }
long()
{
    write("A small wooden top, It needs some sanding.\n");
}

init() {
     add_action("spin","spin");
     add_action("finger","finger");
}

id(str) {
    return str == "top" || str == "wooden top";
}

spin(str) {
    if (str && !id(str))
        return 0;
write ("You kneel down and spin the top on the ground.\n");
write ("The spinning top relaxes you.\n");
say(call_other(this_player(), "query_name") +
    " spins a top. (playing with toys, jheesh.).\n");
    return 1;
}

get() {
     write("You pick up the top and get a splinter.\n");
    return 1;
}
query_auto_load() {
   return "players/boltar/things/top.c:";
}
drop() { return 1; }
