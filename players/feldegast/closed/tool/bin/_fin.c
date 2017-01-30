/* This is a modified melding of an object I found in /open */
/* probably Mythos' and the mud's finger object.  It's a */
/* spiffy finger command, to be exact. */
int no_give; /* This is to check inactive (I think) */
int pregnancy;
int *phys_at;
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
string whimpy_dir;
int whimpy;
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
string ok_edit;

id(str) { return str == "finger";}


int do_cmd(string str) {
  name=0;
if(!str) { write("Usage: fin <name>\n"); return 1;}
if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {  
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
      write("-----Reactivation possible after:"+
            ctime(no_give+1296000)+"\n");
       write("----------------------------------------------------\n");
    }
     if(restore_object("banish/"+lower_case(str)))
       write("------------BANISHED------------BANISHED------------\n");
}
    if(!name) {
      write("No such player exists.\n");
      return 1;
    }
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
   if (find_player(str)) write("This player is logged on.\n");
     else write("This player is not currently logged on.\n");
  if(ok_edit)
  {
    write("Edit flags: "+ok_edit+".\n");
  }
  write("Wimpy: "+whimpy_dir+" @ "+whimpy+".\n");
    if (!restore_object("post_dir/" + name) || messages == "") return 1;
  new = "";
  if (new_mail)
  new = " new";
  write(capitalize(name)+" has"+new+" mail.\n");
   if (find_player(str)) write("This player is logged on.\n");
     else write("This player is not currently logged on.\n");
return 1;}
