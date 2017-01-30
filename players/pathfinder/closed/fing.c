#define JN capitalize(this_player()->query_name())
#define lcheck if(this_player()->query_level() >20)
#define find(str) find_living(str)
#define idle query_idle(find_living(str))
#define online if(find(str)&&(find(str)->query_invis()==0 || this_player()->query_real_name() == "zatar"))
string name, pretitle, called_from_ip, title, lastime, race;
string guild_name, messages, new, al_title, session, kingdom_name;
string test_character, player_killing;
int age, guild_rank, is_invis, muffle;
int level, ex_lv, new_mail, gender;
query_auto_load() { return "/players/mouzar/closed/finger:"; }
id(str) { return str=="finger" || str == "mouz-finger"; }
short() { return "A finger"; }
long() {write("This is a finger.  As you can see.  It has magical properities\n"+
              "that let you see info on a person.  To use it type 'finger <person>'.\n"+ 
              "You can also donate an extra finger to a person without one by typing\n"+
              "'donate <player>'.  If for any reason you want to lose it type 'lose \n"+
              "finger'.  You can type just finger and get another who listing.\n"+
              "Mail Mouzar if you have any problems with this little finger.\n");
        return 1;
}
get() { return 1; }
drop() { return 1; }
init() {
  add_action("finger","finger");
  add_action("no_finger","lose");
  add_action("donate","donate");
}
donate(str) {
  if(!str) return;
  if(str == this_player()->query_name()) return;
  if(!find_living(str)) {
    write("You can not give a finger to someone who isn't here!\n");
    return 1;
  }
  if(present("mouz-finger",find_living(str))) {
    write(capitalize(str)+" has an extra finger already.\n");
    return 1;
  }
  if(!present(str,environment(this_player()))) {
    write("You don't want to be throwing the finger across the mud!\n");
    return 1;
  }
  write("There is a scream in the background as you produce a finger for "+capitalize(str)+".\n");
  say("There is a scream in the background.\n");
  say(capitalize(this_player()->query_name())+" gives and extra finger to "+capitalize(str)+".\n");
  tell_object(find_living(str), "You notice the finger is still warm.\n");
  move_object(clone_object("/players/mouzar/closed/finger"),find_living(str));
  return 1;
}
finger(str) {
  int i;
  object chk;
  if(!str) {fwho(); return 1;} 
  if(!restore_object("players/"+str)) {
    write("That person does not exist.\n");
    return 1;
  }
  if(pretitle) write(pretitle+" "); 
  write(capitalize(name)+" "+title+" ("+al_title+")");
  if(gender == 1) write(" {Male}");
  if(gender == 2) write(" {Female}");
  if(gender == 3) write(" {Neuter}");
  write("\n");
  write("Level:  :"+level);
  write("\n");
  if(guild_name) write("Guild:  "+guild_name);    
  if(guild_rank) {
    write("     \tGuild rank:  "+guild_rank+"\n");
  }
if(guild_name && !guild_rank) write("\n");
  write("Age:    ");
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
  if(player_killing) write("Player Killer!\n");
  lcheck write("ip# "+called_from_ip+"\n");
  online {
    write(capitalize(name)+" is logged on now.\n"); 
    if(interactive(find(name)) &&idle  > 60) write("Idle for "+idle/60+" min\n");
  } else {
    write("Last called on "+lastime+"\n"); 
  }
  if (!restore_object("/post_dir/" + name) || messages == "") return 1;
  new = "";
  if (new_mail)
  new = " new";
  write(capitalize(name)+" has"+new+" mail.\n");
  return 1;
}
fwho(str) {
  int x;
  object us;
  if(str) return;
  us=users();
  us=bubble_sort(us,"query_level");
  write("Name            PK?     Lo-=*=--=*=--=*=--=*=--=*=--=*=--=*=-\n");
  for(x=0;x<sizeof(us);x++) {
   if(environment(us[x]))
    if(us[x]->query_invis() < this_player()->query_level() || this_player()->query_real_name() == "ryltar") {
      if(present("mouz-finger",us[x])) write("*"); else write(" ");
      write(capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())<7) write("\t\t"); else write("\t");
      if(us[x]->query_player_killing()) write("yes"); else write("no");
      write("\t");
      if(!environment(us[x]))write("Logging in");
      else write(environment(us[x])->short());
      write("\n");
      }
    }
  return 1;
}
no_finger(str) {
  if(str != "finger") return;
  if(str == "finger") destruct(this_object());
   return 1;
}
