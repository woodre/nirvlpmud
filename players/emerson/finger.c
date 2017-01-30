/* Original code by Bastion (Bastian)
 * Modified by Wizardchild
 */
 
#define P(x) pad(x, -5)
 
string name, called_from_ip, title, al_title, guild_name, mailaddr;
string lastime, cap_name;
int level, ex_lv, age;
int experience, money;
int strength, intelligence, stamina, will_power, piety, stealth,
magic_aptitude;
int player_killing;
int guild_rank, guild_exp; string guild_file;
status privs;
 
finger(str) { return cmd_finger(str); }
cmd_finger(str) {
  object who;
  name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
  guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;
  if(!str) {
    write("You must enter a player's name.\n");
    return 1;
  }
  restore_object("players/"+lower_case(str));
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
  header=(capitalize(name) + " " + title + " (" + al_title + ") ");
  if(level>19 && level<100)
    header+=("<Wizard>");
  else if(level>99 && level<10000)
    header+=("<Senior Wizard>");
  else if(level>9999)
    header+=("<God>");
  write(format(header, 75));
  write("Level:"+pad(level, -14)+(privs?"  Experience:"+pad(experience,-8):"")+"\n");
  write("Extra level:"+pad(ex_lv, -8)+(privs?"  Money:"+pad(money,-13):"")+"\n");
  if(!guild_name)
    guild_name="none";
  guild_name=lower_case(guild_name);
  write("Guild name:"+pad(guild_name,-9)+"\n");
  if(privs) {
    write("Guild Rank:"+pad(guild_rank,-9)+"  Guild Exp:"+pad(guild_exp,-9)+"\n");
    write("Attributes:\n");
    write("Mag:"+P(magic_aptitude)+"  Sta:"+P(stamina)+"  Str:"+P(strength)+"\n");
    write("Int:"+P(intelligence)+"  Wil:"+P(will_power)+"  Pie:"+P(piety)+"\n");
    write("Player killer: "+(player_killing?"Yes":"No")+"\n");
    if(!mailaddr) mailaddr = "none";
    write("E-mail address: "+mailaddr+"\n");
    write("Last called from: " + called_from_ip + "\n");
  }
  write("Last called at: ");
  if(find_player(name) && find_player(name)->query_invis() < 19)
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
