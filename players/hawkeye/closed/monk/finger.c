
string name, called_from_ip, title, al_title, guild_name, mailaddr;
string lastime, cap_name;
string ghost,player_killing;
id(str){ return str == "finger" || str == "monk_obj"; }
int level, ex_lv, age;

short() { return "A Monk Finger"; }

long() {
     write("Type 'finger <who>.'\n");
}

init() {
     add_action("finger","finger");
}
drop() {return 1;}

finger(str) {
     object who;
     name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
     guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;
     ghost=0;player_killing=0;
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
     string header;
     header=(capitalize(name) + " " + title + " (" + al_title + ") ");
     if(level>19 && level<100)
          header+=("<Wizard>");
     else if(level>99 && level<10000)
          header+=("<Senior Wizard>");
     else if(level>9999)
          header+=("<God>");
     write(format(header, 75));
    if(ghost) {
     write(capitalize(name) + " is a ghost.\n");
}
     write("Level: " + level + "\tExtra Level: " + ex_lv + "\n");
     if(!guild_name)
          guild_name="none";
     guild_name=lower_case(guild_name);
     write("Guild name: " + guild_name + "\n");
      if(player_killing) {
          write(capitalize(name) + " is a Player Killer.   ");
}
          write("Last called from: " + called_from_ip + "\n");
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

