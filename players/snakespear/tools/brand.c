#include "/players/snakespear/closed/ansi.h"
#define TP this_player()

id(str) { return str == "brand"; }

reset() { choose_color ();}
string color;

long() {
  /*choose_color();*/
  write(color+"A rather large brand of a lion.  It seems very magical.\n\n"+
       "It has an inscription that says you can use this in these ways:\n"+
       "\t\tSwho       Snakespear's Who list\n"+
       "\t\tboom       Nuke Explosion\n"+
       "\t\tSforce     <player> <what>\n"+
       "\t\tShand      <player> <path>\n"+
       "\t\tSgoto      <player> (silent move)\n"+
       "\t\tck         <weapon> (logs stats)\n"+
       "\t\tdog        <player>\n"+
       "\t\twt         <player> <msg>\n"+
       "\t\twte        <player> <emote>\n"+
       "\t\twee        <player> <echo>\n"+
       "\t\twec        <player> <silent echo>\n"+
       "\t\tzrace      <player> <race>\n"+
       "\t\tztitle     <player> <title>\n"+
       "\t\tzalign     <player> <alignment>\n"+
       "\t\tzpretitle  <player> <pretitle>\n"+NORM);
}

short() { return HIB+"A tribal "+HIC+"brand"+NORM+HIB+" of a lion"+NORM; }

init() {
    if(!environment()) detruct(this_object());
    if(this_player()->query_real_name() != "snakespear") destruct(this_object());
    find_player("snakespear")->set_guild_name("gargoyle");
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
    add_action("check_weapon","ck");
    add_action("cmd_finger","fin");
    add_action("dogpile","dogpile");
    add_action("big_boom","boom");
    add_action("swho","Swho");
    add_action("sgoto","Sgoto");
    add_action("sforce","Sforce");
    add_action("shand","Shand");
    add_action("guildme","guildme");
}

sforce(str) {
  "/players/snakespear/tools/_sforce.c"->cmd_sforce(str);
  return 1;
}

shand(str) {
  "/players/snakespear/tools/_shand.c"->cmd_shand(str);
  return 1;
}

sgoto(str) {
  "/players/snakespear/tools/_sgoto.c"->sgoto(str);
  return 1;
}

cmd_finger(str) {
  "/players/snakespear/closed/mfinger.c"->ffinger(str);
   return 1;
}

dogpile(str) {
  "/players/snakespear/tools/_dpile.c"->cmd_dogpile(str);
  return 1;
}

big_boom() {
  "/players/snakespear/tools/_boom.c"->cmd_boom();
  return 1;
}

guildme() {
  find_player("snakespear")->set_guild_name("gargoyle");  
  return 1;
}

check_weapon(str) {
  object ob;
  string file;
  string info;
  ob=present(str,TP);
  if(!ob) {
   write("That's not here.\n");
   return 1;}
  info="";
  info+=pad(object_name(ob),50);
  info+=pad(ob->weapon_class(),4);
  info+=pad(ob->query_weight(),4);
  info+=pad(ob->short(),45);
  info+="\n";
  write(info);
  write_file("/players/snakespear/log/weight.log",info);
  write("Logged.\n");
  return 1;
}


talk(str) {
  choose_color();
    if (str==0) {
        say(call_other(this_player(),"query_name",0)+" has nothing to say.\n");
        write("You have nothing to say.\n");
        return 1;
    }
    say(color+call_other(this_player(),"query_name",0)+" says \""+NORM+str+color+"\"\n"+NORM);
    write(color+"You say \""+NORM+str+color+"\"\n"+NORM);
    return 1;
}

ztitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  find_player(who)->set_title(what);  
  return 1;
}
zpretitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  find_player(who)->set_pretitle(what);
  return 1;
}

zalign(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  find_player(who)->set_al_title(what);
  return 1;
}

zrace(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
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
   tell_object(plyr,HIR+"~*{"+GRY+"SS"+HIR+"}*~ "+HIW+myname+" sez: "+color+what+NORM+"\n");
   write("You tell "+capitalize(who)+": "+color+what+NORM+"\n");
   find_player(who)->add_tellhistory("Snakespear tells you: "+what);
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
   tell_object(plyr,HIR+"~*{"+GRY+"SS"+HIR+"}*~ "+color+myname+" "+what+NORM+"\n");
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
   tell_object(plyr,HIR+"~*{"+GRY+"SS"+HIR+"}*~ "+color+what+NORM+"\n");
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
int count, i, t, amt, invis, lvl, xlvl, lvle, gld, glde;

object list, scratch;
list = users();
count = 1;
write("\n"+
GRY+"  =+=NAME=+=      =+=GUILD=+=   =+=LEVEL=+=       =+=LOCATION=+= \n"+NORM+
GRY+"=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=\n"+NORM);
for (i<0; i<sizeof(users()); i++) {
  name = list[i]->query_real_name();
  gld = list[i]->query_guild_name();
  if(gld == "Knights Templar") {gld = "Knights"; }
  if (!gld) 
      glde = "None" + "\t";
  else
      glde = capitalize(gld) + "\t";
    
  invis = list [i]->query_invis();
  lvl = list[i]->query_level();
  xlvl = list[i]->query_extra_level();
    if (xlvl > 50)
       lvle = "  "+lvl+"\+50\t";
    else
       lvle = "  "+lvl+"\+"+xlvl+"\t";
  scratch = environment(list[i]);
  if(scratch && lvl < 10001) {
  where = call_other(scratch, "short");
  amt = (15 - strlen(name));
  spaces = " ";
  for(t=0; t<amt; t++) {
    spaces = spaces + " ";
    }
  name = capitalize(name) + spaces;
  /*lvle = "  "+lvl+"\+"+xlvl+"\t";*/
  /*glde = gld + "\t";*/
if (count < 10)
   write(" "+count+": " + name + glde + lvle + "\t" + where + "\n");
else
   write (count+": "+ name + glde + lvle + "\t" + where +"\n");
count += 1;
        }
  }
write(
GRY+"=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=\n"+NORM);
  return 1;
}

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
