/* Original code by Bastion (Bastian)
 * Modified by Wizardchild
 */
 
#define P(x) pad(x, -5)
 
string name, called_from_ip, title, al_title, guild_name, mailaddr;
string pretitle, lastime, cap_name;
int no_give,level, ex_lv, age;
int experience, money;
int strength, intelligence, stamina, will_power, piety, stealth,
magic_aptitude,luck;
int player_killing;
int guild_rank, guild_exp; string guild_file;
status privs;
 
finger(str) { return cmd_finger(str); }
cmd_finger(str) {
  object who;
  if(str=="batarsis" || str=="Batarsis") {
write("Batarsis the Bad (evil)\n");
write("Level:          19+4 \n");
write("Guild name:     none\n");
write("Player killer:   Yes\n");
write("Last called at: ");
if(find_living("batarsis")) write("Not logged off.\n");
else write("Unknown\n");
write("Age: 8 days 7 hours 46 minutes 20 seconds.\n");
return 1;
}
if(str=="Marie" || str=="marie") {
  if(this_player())
  if((string)this_player()->query_prison() == "yes" ||
    (string)this_player()->query_prison() == "/players/boltar/closed/zx.c") {
  write("That player does not exist.\n");
  return 1;
}
}

  name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
  guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;
  if(!str) {
    write("You must enter a player's name.\n");
    return 1;
  }
/*
  restore_object("players/"+lower_case(str));
*/
if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {  
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
       write("-----Reactivation possible after: "+ctime(no_give+1296000)+"\n");
       write("----------------------------------------------------\n");
     }
     if(restore_object("banish/"+lower_case(str)))
       write("------------BANISHED------------BANISHED------------\n");
}
  if(!name) {
    write("No such player exists.\n");
    return 1;
  }
  privs = this_player()->query_level() >= 40;
  print_stats();
  return 1;
}
 
print_stats() {
  string header;
  object bb;
  header=(capitalize(name) + " " + title + " (" + al_title + ") ");
if(pretitle)
  header=(pretitle + " " + capitalize(name) + " " + title + " (" + al_title + ") ");
  if(level>19 && level<100)
    header+=("<Wizard>");
  else if(level>99 && level<10000)
    header+=("<Senior Wizard>");
  else if(level>9999)
    header+=("<God>");
/*
  write(format(header, 75));
*/
  write(header+"\n");
write("Level:"+pad(level+(ex_lv?"+"+ex_lv:""),-14)+(privs?"  Experience:"+pad(experience,-9):"")+"\n");
if(privs) write("Money:"+pad(money,-14)+"\n");
  if(!guild_name)
    guild_name="none";
  guild_name=lower_case(guild_name);
if(strlen(guild_name) > 8) write("Guild name: "+guild_name+"\n");
else write("Guild name: "+pad(guild_name,-8)+"\n");
  if(privs) {
write("Guild Rank:"+pad(guild_rank,-9)+"  Guild Exp:"+pad(guild_exp,-10)+"\n");
    write("Attributes:\n");
write("Mag:"+P(magic_aptitude)+"  Sta:"+P(stamina)+"  Str:"+P(strength)+"  Ste:"+P(stealth)+"\n");
write("Int:"+P(intelligence)+"  Wil:"+P(will_power)+"  Pie:"+P(piety)+"  Luc:"+P(luck)+"\n");
    write("Player killer: "+(player_killing?"Yes":"No")+"\n");
    if(!mailaddr) mailaddr = "none";
    write("E-mail address: "+mailaddr+"\n");
    write("Last called from: " + called_from_ip + "\n");
  } else write("Player killer: "+pad((player_killing?"Yes":"No"),-5)+"\n");
  write("Last called at: ");
  bb = find_player(name);
  if((bb && !bb->query_invis()) || (bb && bb->query_invis() && bb->query_level() < this_player()->query_level()))
    write("Not logged off.\n");
  else
    write(lastime+"\n");
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
}
