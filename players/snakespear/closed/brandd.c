#include "/players/snakespear/closed/ansi.h"


id(str) { return str == "brand"; }

reset() {}
string color;
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



long() {
  choose_color(); 
  write(color+"A rather large brand of a lion.  It seems very magical.\n\n"+
       "It has an inscription that says you can use this in these ways:\n"+
       "\t\twt         <player> <msg>\n"+
       "\t\twte        <player> <emote>\n"+
       "\t\twee        <player> <echo>\n"+
       "\t\twec        <player> <silent echo>\n"+
       "\t\tzrace      <player> <race>\n"+
       "\t\tztitle     <player> <title>\n"+
       "\t\tzalign     <player> <alignment>\n"+
       "\t\tzpretitle  <player> <pretitle>\n"+
       "\n"+
       "\t\tNew Feature: fin <playername>\n"+
       "\t\t\t\tSwho  (Kewl Who List)\n"+NORM);
}

short() { return HIB+"A tribal "+HIC+"brand"+NORM+HIB+" of a lion"+NORM; }

init() {
    if(!environment()) detruct(this_object());
    if(this_player()->query_real_name() != "snakespear") destruct(this_object());
    say(HIB+"The "+HIR+"brand "+HIB+"hisses as Snakespear's flesh burns.\n"+NORM);
    say(HIR+"Snakespear winces briefly, then smiles.\n"+NORM);
    write(HIB+"The "+HIR+"brand "+HIB+"hisses as your flesh burns.\n"+NORM);
    write(HIR+"As the pain runs it's course, you smile.\n"+NORM);
    add_action("ztitle","ztitle");
    add_action("zrace","zrace");
    add_action("zpretitle","zpretitle");
    add_action("zalign","zalign");
    add_action("wiz_tell", "wt");
    add_action("wiz_mote", "wte");
    add_action("wiz_ech", "wee");
    add_action("wiz_eco", "wec");
    add_action("talk", "say");
    add_action("ffinger","fin");
    add_action("swho","Swho");
}

talk(str) {
    if (str==0) {
        say(call_other(this_player(),"query_name",0)+" has nothing to say.\n");
        write("You have nothing to say.\n");
        return 1;
    }
    say(HIR+call_other(this_player(),"query_name",0)+" says \""+NORM+str+HIR+"\"\n"+NORM);
    write(HIR+"You say \""+NORM+str+HIR+"\"\n"+NORM);
    return 1;
}

ztitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  what=NORM+"the "+HIR+"Vampiric "+GRY+"Un"+HIR+"Lord of Hate"+NORM;
  find_player(who)->set_title(what);  
  return 1;
}
zpretitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  what=GRY+"Shadowing Death with Pleasure";
  find_player(who)->set_pretitle(what);
  return 1;
}

zalign(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  what=HIY+"O"+HIR+"T"+HIG+"M"+GRY+"F"+HIM+"S"+NORM;
  find_player(who)->set_al_title(what);
  return 1;
}

zrace(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  what=HIR+"Djinn"+NORM;
  find_player(who)->set_race(what);
  return 1;
}

wiz_tell(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Tell what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(!(find_player(who))->query_interactive()) {
      write(BLINK+HIR+capitalize(who)+" is disconnected.\n"+NORM);
   }
   if(in_editor(find_player(who))) {
      write("Person is in edit...\n");
      return 1;
   }
   tell_object(plyr,HIB+"~*{"+HIC+"SS"+HIB+"}*~ "+HIW+myname+" speaks: "+color+what+NORM+"\n");
   write("You tell "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}

wiz_mote(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) {
      write("Emote what?\n");
      return 1;
   }
   if(sscanf(str,"%s %s",who,what) != 2) {   
      write("Emote <who> <what>?\n");
      return 1;
   }
   plyr = find_living(who);   
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) {
      write(capitalize(who) +" is not online now.\n");
      return 1;
   }
   if(!(find_player(who))->query_interactive()) {
      write(BLINK+HIR+capitalize(who)+" is disconnected.\n"+NORM);
   }
   if(in_editor(find_player(who))) {
      write("Person is in edit...\n"); return 1;
   }
   tell_object(plyr,HIB+"~*{"+HIC+"SS"+HIB+"}*~ "+color+myname+" "+what+NORM+"\n");
   write("Emoted to "+capitalize(who)+": "+color+myname+" "+what+NORM+"\n");
   return 1;
}
wiz_ech(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Echo what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Echo <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(!(find_player(who))->query_interactive()) {
      write(BLINK+HIR+capitalize(who)+" is disconnected.\n"+NORM);
   }
   if(in_editor(find_player(who))) {
      write("Person is in edit...\n"); return 1;
   }
   tell_object(plyr,HIB+"~*{"+HIC+"SS"+HIB+"}*~ "+color+what+NORM+"\n");
   write("You SS echo to "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}
wiz_eco(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Echo what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Echo <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!(find_player(who))->query_interactive()) {
      write(BLINK+HIR+capitalize(who)+" is disconnected.\n"+NORM);
   }
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(in_editor(find_player(who))) {
      write("Person is in edit...\n"); return 1;
   }
   tell_object(plyr,what+"\n");
   write("You echo to "+capitalize(who)+": "+what+"\n");
   return 1;
}

swho() {
string name, spaces, where;
int count, i, t, amt, invis, lvl, xlvl, lvle;

object list, scratch;
list = users();
count = 1;
write("\n"+
"     Name            Level             Location\n"+
"<----------------------------------------------------------------------->\n");
for (i<0; i<sizeof(users()); i++) {
  name = list[i]->query_real_name();
  invis = list [i]->query_invis();
  lvl = list[i]->query_level();
  xlvl = list[i]->query_extra_level();
  scratch = environment(list[i]);
  if(scratch && lvl < 10001) {
    where = call_other(scratch, "short");
  amt = (15 - strlen(name));
  spaces = " ";
  for(t=0; t<amt; t++) {
    spaces = spaces + " ";
    }
  name = capitalize(name) + spaces;
  lvle  = lvl+"\+"+xlvl+"\t";
if (count < 10)
   write("  "+count+": " + name + lvle + where + "\n");
else
   write (" "+count+": "+ name + lvle + where +"\n");
count += 1;
        }
  }
write(
"<----------------------------------------------------------------------->\n");
  return 1;
}


ffinger(str) {
if(!str) { write("Usage: fin <name>\n"); return 1;}
/*if(!restore_object("players/"+str)) {
   write("That player does not exist!\n"); return 1;} */
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


choose_color() {
   int blah;
   blah = random(14);
   switch(blah) {
   case 0:	color = RED; break;
   case 1:      color = GRN; break;
   case 2:      color = YEL; break;
   case 3:	color = BLU; break;
   case 4:	color = MAG; break;
   case 5:	color = CYN; break;
   case 6:      color = BOLD+BLK; break;
   case 7:      color = HIR; break;
   case 8:	color = HIG; break;
   case 9:	color = HIY; break;
   case 10:	color = HIB; break;
   case 11:	color = HIM; break;
   case 12:	color = HIC; break;
   case 13:     color = HIW; break;
 /*case 14:     color = BLINK+HIR; break;
   case 15:     color = BLINK+HIG; break;
   case 16:     color = BLINK+HIY; break;
   case 17:     color = BLINK+HIB; break;
   case 18:     color = BLINK+HIM; break;
   case 19:     color = BLINK+HIC; break;
   case 20:     color = BLINK+HIW; break;*/
   }
   return 1;
}

drop() { return 1; }

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }
