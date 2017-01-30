
/*   Bastion -- Last updated 3/22/95   */

string name, called_from_ip, title, al_title, guild_name, mailaddr;
string lastime, cap_name, hostname;
int level, ex_lv, age;
id(str) { return (str=="ND" || str=="finger" || str=="device"); }

short() { return "A finger device"; }

long() {
     write("Type 'finger <who>.'\n");
}

init() {
     add_action("finger","finger");
}

get() { return 1; }
drop() { return 1; }

finger(str) {
     object who;
     name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
     hostname=0;guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;
     if(!str) {
          write("You must enter a player's name.\n");
     return 1;
     }
     restore_object("players/"+lower_case(str));
     if(!name) {
          write("No such player exists.\n");
          return 1;
     }
     print_stats();
     return 1;
}

print_stats() {
     object who;
     string header, pos;
     header=(capitalize(name) + " " + title + " (" + al_title + ") ");
     if(level>19 && level<100)
          pos = "Wizard";
     else if(level>99 && level<700)
          pos = "Senior Wizard";
     else if(level>699 && level<10000)
          pos = "Archwizard";
     else if(level>9999)
          pos = "God";
     else
          pos = "Player";
     write(format(header, 75));
     write("Level: " + level + "\t\tExtra Level: " + ex_lv + "\n");
     if(!guild_name)
          guild_name="none";
     guild_name=capitalize(guild_name);
     write("Guild: " + guild_name + "\t\tPosition   : " + pos + "\n");
     if(!mailaddr)
          mailaddr="none";
     if(this_player()->query_real_name()=="bastion" ||
        this_player()->query_level() > 99 ||
        this_player()->query_real_name()=="womble") {
          write("E-mail address: " + mailaddr + "\n");
          write("Called from IP: " + called_from_ip + "\n");
          write("Called from host: " + hostname + "\n");
     }
     write("Last called at: ");
     if(find_player(name)) {
          who=find_player(name);
          if(who->query_invis() < 30)
               write("Not logged off.\n");
          else
               write(lastime + "\n");
     }
     else
          write(lastime + "\n");
     display_age();
     return 1;
}

display_age() {
     int i;
     write("Age: ");
     i=age;
     if(i/43200) {
          write(i/43200 + " days ");
          i=i - (i/43200) * 43200;
     }
     if(i/1800) {
          write(i/1800 + " hours ");
          i=i - (i/1800) * 1800;
     }
     if(i/30) {
          write(i/30 + " minutes ");
          i=i - (i/30) * 30;
     }
     write(i*2 + " seconds.\n");
     return 1;
}

query_auto_load() { return "/players/bastion/closed/finger:"; }
