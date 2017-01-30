int pregnancy,phys_at;
string messages;
int new_mail;
string wkrm,hostname, new;
string mailaddr;
string title;		/* Our official title. Wiz's can change it. */
string pretitle;
string race;
string al_title;
string called_from_ip;	/* IP number used last time */
string guild_name;
string lastime;  /*last login time */
int player_killing; /* can attack/be attacked by other players */
int guild_rank, guild_exp;
string guild_file;
string home;       
int ex_lv;   
int age;
int strength, intelligence, stamina, will_power, magic_aptitude, piety, stealth;
int crime; /* have we been bad.  players */
int money;              /* Amount of money on player. */
int luck,lucky;
string name;            /* Name of object. */
string gender;
int level;              /* Level of monster. */
int hit_point,spell_points,max_spell;          /* Number of hit points of monster. */
int max_hp;
int experience;         /* Experience points of monster. */
int quest_point;

id(str) { return str == "finger";}
get() { return 1;}
drop() { return 1;}

long() { write("Usage fin <name\n"); }

init() { 
if(this_player()->query_level() < 20) { return 1;} 
 add_action("ffinger","fin"); }

ffinger(str) {
string nme;
if(!str) { write("Usage: fin <name>\n"); return 1;}
if(this_player()->query_level() < 40) {
  write("Disabled for wizards under 40.\n");
  return 1;
}
if(!restore_object("players/"+str)) {
   nme = explode(str,"");
   if(!restore_object("pfiles/"+nme[0]+"/"+str)) {
   write("That player does not exist!\n"); return 1;} }
   if(player_killing) write("<PK> ");
   write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")  \n\n");
    write("Level: "+level+" + "+ex_lv+"  ");
    write("Coins: "+money+"     ");
    write("Experience: "+experience+"  \n");
    write("Race: "+race+"  ");
    write("Gender: " + gender +"  ");
    write("Height & weight: " +phys_at[1]+" feet "+phys_at[2]+" inches "+phys_at[3]+" lbs.\n");
    if(pregnancy){ pregnancy = age-pregnancy;
    write("Pregnancy: "+ pregnancy+" / 16200\n");}
    write("Hit points: "+hit_point+"/"+max_hp+"     ");
    write("Spell points: "+spell_points+"/"+max_spell+"   ");
    write("Quest points: "+quest_point+"\n");
    write("Guild Name: "+guild_name+"  ");
    write("Guild Rank: "+guild_rank+"  Guild Xp: "+guild_exp+"\n");
    if(guild_file) write("Guild File: "+guild_file+"\n");
    write("Home: "+home+"\n\n");
   write("Strength:       "+strength+"   Stamina:      " + stamina + "        Will Power: "+will_power + "\n");
write("Magic aptitude: " + magic_aptitude + "   Piety:        "+piety+"        Stealth:    "+stealth+"\n");
write("Luck:           " + luck + "   Intelligence: " +intelligence + "\n\n");
   if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+hostname + " ("+called_from_ip+")   \n");
    write("At Time: "+lastime+"\n");
    if (!restore_object("post_dir/" + name) || messages == "") return 1;
  new = "";
  if (new_mail)
  new = " new";
  write(capitalize(name)+" has"+new+" mail.\n");
   if (find_player(str)) write("This player is logged on.\n");
     else write("This player is not currently logged on.\n");
return 1;}
