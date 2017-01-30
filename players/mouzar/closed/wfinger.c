#define online if(find_living(str))
string name, pretitle, called_from_ip, title, lastime;
string guild_name, messages, new, al_title, quests, gender;
int strength, stamina, will_power, magic_aptitude, piety; 
int stealth, luck, intelligence;
int age, guild_rank, guild_exp, experience, max_hp, max_spell, hit_point;
int level, ex_lv, new_mail, spell_points, quest_point;
int strength, will_power, magic_aptitude, piety, stealth, luck;
int stuffed, soaked, intoxicated;
int money, player_killing;
id(str) { return str=="finger"; }
query_auto_load() {return "/players/mouzar/closed/wfinger.c:"; }
short() { return "A Wiz finger"; }
long() { write("This is a very magical finger.  It was taken off a a wizard\n"+
               "it still holds some of a wizard's magical powers.  Use it by:\n"+
     	      "'finger player' to see terribly important data on that player.\n"); }
get() { return 1; }
drop() { return 1; }
init() {
  if(this_player()->query_real_name() == "mouzar")
  add_action("finger","fin");
}
 
finger(str) {
  int i;
  if(!str) return;
  if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {
    if(restore_object("players/interactive_saved/"+lower_case(str))) {
      write("***************-Inactive-***************\n");
    } else { write("That players doesn't exist!\n");
    return 1;
  }
  }
  if(pretitle) write(pretitle+" ");
  write(capitalize(name)+" "+title+" ("+al_title+")\n");
  write("Experience:  "+experience+"  \tMoney:  "+money+"\n");
  write("Level:  "+level+"\t\tExtra Level:  "+ex_lv+"\n");
  write("Hp:  "+hit_point+"<|>"+max_hp+"\t\tSp:  "+spell_points+"<|>"+max_spell+"\n");
  write("Guild:  "+guild_name+"\t\tGuild rank:  "+guild_rank+"\n");
  write("Guild exp:  "+guild_exp+"\n");
  write("Sex:  "+gender+"\n");
  if(player_killing) write("Player Killer!\n");
  if(soaked) write("Soaked:  "+soaked+"\n");
  if(intoxicated) write("Intox:  "+intoxicated+"\n");
  if(stuffed) write("Stuffed:  "+stuffed+"\n");
  if(quests){ write(quests+"\n");
  write("Quest points:  "+quest_point+"\n");
  }
  write("Strength:        "+strength+"\tStamina:       "+stamina+"\tWill Power:  "+will_power + "\n");
  write("Magic aptitude:  "+magic_aptitude+"\tPiety:         "+piety+"\tStealth:     "+stealth+"\n");
  write("Luck:            "+luck+"\tIntelligence:  "+intelligence + "\n");
  
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
  write("ip# "+called_from_ip+"\n");
  online {write(capitalize(name)+" is logged on now.\n"); 
  } else {
  write("Last called on "+lastime+"\n"); 
  }
  if (!restore_object("post_dir/" + name) || messages == "") return 1;
  new = "";
  if (new_mail)
  new = " new";
  write(capitalize(name)+" has"+new+" mail.\n");
  return 1;
}
  
