string vars, query_list;
object stores, locale;
 
id(str) { return str == "finger";}
 
 
short() { return "A finger"; }
 
long() {
    write("Someone's half chewed finger nail.\n");
}
                 
init() {
     add_action("finger", "finger");  }
 
string lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
int level, experience, money, age;                               
 
finger(str) {
    int days, hours, minutes, seconds;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
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
    write("Level: "+level+"\n");
    write("Experience: "+experience+"\n");
    write("Money: "+money+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+called_from_ip+"\n");
    write("Last login was at: "+lastime+"\n");
    show_age();
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
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
       
