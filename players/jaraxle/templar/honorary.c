#include "security.h"
#include "/players/boltar/things/esc.h"
#include "/players/dragnar/closed/ansi.h"
#define USER environment()
#define TP this_player()
#define CHUNK 20

#define CRIM "/players/boltar/templar/daemon/Criminal.c"
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define LOG "/players/maledicta/templar/log/Ally"
#define USOB environment(this_object())

#include "/players/boltar/templar/lib/_bow.h"
#include "/players/boltar/templar/lib/_salute.h"
#include "/players/boltar/templar/lib/_warn.h"

/* Awards that a Knight can obtain:
  1 The Crystal Shield   - Died for someone else in pk. (6)
  2 The Platinum Circlet - Pked a criminal.             (4)
  3 The Silver Circlet   - Assisted a Pk on a criminal. (2)
  4 The Emerald Droplet  - Misc. Assistance/other.      (1)
*/ 
int council;
static int horsed;  /* added by verte */

int award1;
int award2;
int award3;
int award4;
int total_awards;
int elite;
static string more_file;        /* Used by the more command */
static int more_line;
int block;           /* Block templar channel */
static int worn;
string locked;
static object owner;

init(){
 if(!environment()) return;
  restore_object("players/jaraxle/templar/members/"+TP->query_real_name());
  add_action("leave_templar", "leave_templars");
  add_action("new_quit", "quit");
   add_action("go_afk", "afk");
   add_action("go_return", "return");
   add_action("cmd_warn", "warn");
   add_action("cmd_salute","salute");
   add_action("cmd_bow","bow");
   add_action("award", "award");
   add_action("make_elite","elite");
   add_action("unelite","relite");
   add_action("lock_member","suspend");
   add_action("unlock_member","restore");
   add_action("remove_member", "expel");
   add_action("align_it", "align");
  add_action("home","home");
   add_action("wear","wear");
   add_action("remove","remove");
   add_action("record","record");
   add_action("read_record","read_record");
   add_action("tail_record","tail_record");
   add_action("info_help", "info");
   /**** Communication ******/
   add_action("send","tc");
   add_action("sende","tce");
   add_action("ally_line", "att");
   add_action("ally_emote", "ate");
   add_action("ally_who", "awho");
   add_action("ally_help", "ahelp");
   add_action("remove_ally", "unally");
   add_action("guildwho","templar");
   add_action("guildwho","tw");
   add_action("fixtitle","fixtitle");
   add_action("block","block");
   add_action("criminal_who","cwho");
   add_action("criminal","criminal");
   add_action("pardon","pardon");
   owner = TP;
   owner->set_guild_name("Knights Templar");
 if(USER->query_guild_rank() > 8) council = 1;
 if(USER->query_guild_rank() < 9) council = 0;

 if(elite && TP->query_guild_rank() > 8){ 
     tell_object(environment(),
     "\n\n\nNOTICE:\n"+
     "USE '"+HIR+"elite"+NORM+"' to make a knight an elite member -OR- '"+HIR+"relite"+NORM+"' to remove them.\n\n\n");
     tell_object(environment(),
     "\n\n"+HIG+"You may now 'align <who>' to check alignment.  However, this will cost you 6 sps.\n\n\n"+NORM);
     }
if(TP->query_level() < 20)
     sende("has entered the game.",5);
  }


align_it(str){
 object boo;
   int al;
   string aln;
	if(USER->query_ghost()) return 0;
   if(!str){ 
     tell_object(USER, "Detect alignment of who?\n"); 
     return 1; 
     }
   if(USER->query_sp() < 2){
     tell_object(USER, "You do not have the energy.\n");
     return 1;
     }
   boo = present(str, environment(USER));
   if(!boo){ 
     tell_object(USER, "You do not see "+str+" here.\n");
     return 1;
     }
   if(!living(boo)){ 
     tell_object(USER, "That is not a living thing!\n"); 
     return 1; 
     }
   tell_object(USER,
   "You concentrate on "+capitalize(str)+"...\n");
   al = boo->query_alignment();
if(al == 0){ aln = "Neutral"; }
else if(al > 0){
  switch(al){
   case 641..10000: aln = "White Lord"; break;
   case 321..639:   aln = "Paladin";    break;
   case 161..320:   aln = "Crusader";   break;
   case 81..160:    aln = "Good";       break;
   case 41..80:     aln = "Honorable";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 }
else if(al < 0){
  al = - al;     
   switch(al){
   case 641..10000: aln = "Lord of Evil"; break;
   case 321..639:   aln = "Black Knight";    break;
   case 161..320:   aln = "Infamous";   break;
   case 81..160:    aln = "Evil";       break;
   case 41..80:     aln = "Malicious";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 } 
 USER->add_spell_point(-2);
 tell_object(USER, capitalize(str)+" is of "+HIW+aln+NORM+" alignment.\n");
	return 1;
}


info_help(str) {
  if(elite){
   if (!str){
      more("/players/maledicta/templar/einfo/basics.nfo");
      return 1;
      }
   if (file_size("/players/maledicta/templar/einfo/"+str+".nfo")) {
      cat("/players/maledicta/templar/einfo/"+str+".nfo");
      return 1;
      }
   write("There is no information on that.\n");
   return 1;
   }

   if (!str) {
      more("/players/maledicta/templar/ninfo/basics.nfo");
      return 1;
   }
   if (file_size("/players/maledicta/templar/ninfo/"+str+".nfo")) {
      cat("/players/maledicta/templar/ninfo/"+str+".nfo");
      return 1;
   }
   write("There is no information on that.\n");
   return 1;
}


save_ob() { 
 string nom;
 nom = environment(this_object())->query_real_name();
 if(!nom) return;
 save_object("players/jaraxle/templar/members/"+nom);
 return 1;
}


new_quit(){
  write("Templar Object...\n");
  save_object("players/jaraxle/templar/members/"+TP->query_real_name());
  write("Saved...\n");
if(USER->query_level() < 20){
  sende("has left the game.",5);
  }
  return;
  }

leave_templar(){
  write("You decide to abandon the Templars.\n");
  move_object(this_player(), "room/church");
  USER->add_guild_rank(-USER->query_guild_rank());
  USER->set_home(0);
  USER->set_guild_name("warrior");
  if(present("warrior_gob", this_player())){
  present("warrior_gob", this_player())->set_templar(0);
  }
  rm("/players/jaraxle/templar/members/"+TP->query_real_name()+".o");
  destruct(this_object());
  return 1;
  }  


query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }


id(str) {
object teee,yeee;
yeee=environment(this_object());
if(yeee)
teee=environment(yeee);
if(teee) {
  if(present("cross",teee)) 
    return str == "ND" || str == "GI" || str == "ND" || str == "KnightTemplar" || str == "templar cross" ||
	str == "KnightInvite";
}
if(elite){
return str == "ND" || str == "cross" || str == "GI" || str == "cape" ||
   str == "cross" || str == "KnightTemplar" || str == "KnightInvite";
}
   return str == "ND" || str == "cross" || str == "GI" ||
   str == "cross" || str == "KnightTemplar" || str == "KnightInvite";
}


query_auto_load(){ return "/players/maledicta/templar/honorary.c:"; }


extra_look(){
if(elite)
return environment()->query_name()+" wears a burgundy shoulder cape "+BOLD+"["+NORM+RED+"Elite Guard"+NORM+BOLD+"]"+NORM+"\n"+
       award2+" Platinum Circlets, "+award3+" Golden Circlets, "+award4+" Emerald droplets, and\n"+
       award1+" Crystalline Shields"; 
}

go_afk(){
ally_emote("goes AFK.");
sende("goes AFK.");
return 1;
}

go_return(str){
if(str) return;
ally_emote("RETURNS.");
sende("RETURNS.");
return 1;
}

make_elite(str){
object ob;
if(TP->query_guild_rank() < 9) return 0;
if(!str){
write("Put who into the elite order?\n");
return 1;
  }
if(!find_living(str)){
write("That person is not logged on.\n");
return 1;
}
ob = present("KnightTemplar", find_living(str));
if(!ob){
 write("That person is not a knight!\n");
 return 1;
 }
if(ob->query_elite()){ write("They are already an elite!\n"); return 1; }
if(ob) ob->set_elite(1);
write("You make "+str+" an Elite Guardsman.\n");
tell_object(find_living(str),
"You are placed within the ranks of the Mighty Elite Guard.\n"+
"Shouldering the huge responsibility, you are welcomed into\n"+
"their ranks with open arms.\n");
return 1;
}

unelite(str){
object ob;
if(TP->query_guild_rank() < 9) return 0;
if(!str){
write("Take who out of the Elite order?\n");
return 1;
  }
if(!find_living(str)){
write("That person is not logged on.\n");
return 1;
}
ob = present("KnightTemplar", find_living(str));
if(!ob){
 write("That person is not a knight!\n");
 return 1;
 }
if(!ob->query_elite()){ write("They aren't an elite!\n"); return 1; }
if(ob) ob->set_elite(0);
write("You remove "+str+" from the Elite Guardsman.\n");
tell_object(find_living(str),
"You are removed from the Elite Guard of the Knights!\n");
return 1;
}

set_elite(i){
if(!i){
 tell_object(environment(),
 "You are removed from the Elite Guard!\n");
 elite = 0;
 return 1;
 }
else{
 elite = 1;
tell_object(environment(),
"You are welcomed into the Elite Guardsmen of the Knights Templar.\n");
return 1;
 }
}

query_elite(){ return elite; }


wear(str) {
   if (!id(str)) return 0;
   if (worn) {
      write("You are already wearing your cross.\n");
      return 1;
   }
   worn = 1;
   write("You feel a surge of power as you don your cross.\n");
   say(TP->query_name()+" wears "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}


remove(str) {
   if (!id(str)) return 0;
   if (!worn) {
      write("You are not wearing your cross.\n");
      return 1;
   }
   worn = 0;
   write("You feel weakened.\n");
   say(TP->query_name()+" removes "+
      TP->query_possessive()+" Cross of the Knights Templar.\n");
   write("Ok.\n");
   return 1;
}


short() {
   if(elite && owner && !worn) 
    return RED+owner->query_name()+"'s "+NORM+BOLD+"Cross of the Knights Templar"+NORM+"";
   if(elite && owner && worn) 
    return RED+owner->query_name()+"'s "+NORM+BOLD+"Cross of the Knights Templar "+NORM+RED+"("+NORM+BOLD+"worn"+NORM+RED+")"+NORM+"";
   if (!owner) return "Someone's Cross of the Knights Templar";
   if (worn) return owner->query_name()+"'s Cross of the Knights Templar (worn)";
   return owner->query_name()+"'s Cross of the Knights Templar";
}

long(str) {
if(str == "cape" && elite){
write("This is the short half cape that covers the right shoulder\n"+
      "of an Elite Guardsman. Along its rim is a place for all of\n"+
      "the medals you might have earned over your career.\n");
if(award1){
write(award1+" Crystalline Shields.\n");
}
if(award2){
write(award2+" Platinum Circlets.\n");
}
if(award3){
write(award3+" Golden Circlets.\n");
}
if(award4){
write(award4+" Emerald droplets.\n");
  }
}
else{
   write("The Red on White cross of The Knights Templar.\n");
   write("For a list of commands, type info.\n");   
   }
 }

add_award1(int i){
if(!i) return;
award1 += i;
save_ob();
}

add_award2(int i){
if(!i) return;
award2 += i;
save_ob();
}

add_award3(int i){
if(!i) return;
award3 += i;
save_ob();
}

add_award4(int i){
if(!i) return;
award4 += i;
save_ob();
}
award(str){
string pername,perreason;
int perdeed;
object whom;
object tobj;
if(!elite) return 0;
if(!str){
write("award <who>#<1,2,3, or 4>#<reason>\n"+
      "info award for more information.\n");
return 1;
}
if(sscanf(str, "%s#%d#%s", pername, perdeed, perreason) != 3){
write("award <who>#<1,2,3, or 4>#<reason>\n"+
      "info award for more information.\n");
return 1;
}
whom = find_living(pername);
if(!whom){
write("You cannot find "+pername+".\n");
return 1;
}
if(!present("KnightTemplar", whom)){
write("They are not a Templar!\n");
return 1;
}
tobj = present("KnightTemplar", whom);
if(!tobj->query_elite()){
write("That Knight is not an elite!\n");
return 1;
}
if(perdeed < 1 || perdeed > 4){
write("1, 2, 3, or 4.  Use info award for more information.\n");
return 1;
}
write_file("/players/maledicta/templar/log/awards",
TP->query_real_name()+" "+ctime(time())+" awarded "+pername+", "+perdeed+", "+perreason+".\n");
if(perdeed == 1){
tobj->add_award1(1);
tell_object(whom,
"You have been awarded the Crystalline Shield for your bravery in death.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Crystalline Shield.\n");
sende("has awarded "+capitalize(pername)+" the Crystalline Shield!\n");
return 1;
}
if(perdeed == 2){
tobj->add_award2(1);
tell_object(whom,
"You have been awarded the Platinum Circlet for your victory over Evil.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Platinum circlet.\n");
sende("has awarded "+capitalize(pername)+" the Platinum Circlet!\n");
return 1;
}
if(perdeed == 3){
tobj->add_award3(1);
tell_object(whom,
"You have been awarded the Golden Circlet for your Assistance against Evil.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Golden Circlet.\n");
sende("has awarded "+capitalize(pername)+" the Golden Circlet!\n");
return 1;
}
if(perdeed == 4){
tobj->add_award4(1);
tell_object(whom,
"You have been awarded the Emerald Droplet for your deeds.\n"+
"Congratulations. ("+TP->query_real_name()+").\n");
write("You award "+pername+" the Emerald Droplet.\n");
sende("has awarded "+capitalize(pername)+" the Emerald Droplet!\n");
return 1;
}
return 1;
}



ally_help() {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   list = users();

myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" calls for assistance!\n"+
			       "               Location: "+environment(this_player())->short()+"\n");
          if(this_player()->query_attack()){
         tell_object(list[i],
                   "               Fighting: "+this_player()->query_attack()->query_name()+"\n");
		  }
		  
		  } 
        }
	 
   return 1;
}



ally_who() {
   int i, z, ally;
   object *list;

   list = users();
   write(HIB);
   write(pad("",40,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+HIB+"@\n");
   write(NORM+HIB);
   write("@"+pad("",38,'~')+"@\n");
   write("@"+pad("",38)+"@\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {

     ally = ALLY->Query(list[i]->query_real_name());
     if(!environment(list[i]) || list[i]->query_level() > 19) continue;
     if(ally) {
       write(HIB+"@  "+HIW+pad(list[i]->query_name(),14)+NORM);
      z++;

      if (list[i]->query_pl_k())
         write(list[i]->query_level() + "*\t");
      else
         write(list[i]->query_level() + "\t");

     if (!list[i]->query_guild_name())
       write(pad("None",15));
     else
       write(pad(capitalize(list[i]->query_guild_name()),15));
     write(HIB+"@\n");
     }
   }
   if(!z) write(HIB+"@  "+NORM+pad("No Allies logged in.",36)+NORM+HIB+"@\n");
   write(HIB);
   write("@"+pad("",38)+"@\n");
   write(pad("",40,'@')+"\n");
   write(NORM);
   return 1;
}

remove_ally(string who) {
  if(!who) {
    write("unally <name>\n");
    return 1;
  }
  if(find_living(lower_case(who))){
	  if(present("KnightInvite", find_living(who))){
		  tell_object(find_living(who),
			  "You have been removed from the Knight Alliance.\n");
		  destruct(present("KnightInvite", find_living(who)));
	  }
  }
  ALLY->Delete(who);
  write_file(LOG, ctime(time())+": "+capitalize(this_player()->query_real_name())+" removed "+capitalize(who)+".\n");
  return 1;
}

ally_emote(str) {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Use: ate <what>\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightInvite",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" "+str+"\n");
       }
   }
/* added by verte */
"/obj/user/chistory"->add_history("Knight Alliance",
BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+" "+str);
   return 1;
}

ally_line(str) {
   object list;
   object cross;
   int i;
   string myname; string history; /* added by verte */
   if(block) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Use: att <what>\n"); return 1; }
   list = users();
if(str == "history" || str == "-h")
{
history = "/obj/user/chistory"->query_history("Knight Alliance");
write(history+"\n");
return 1;
}
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightInvite",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str=format(str,60);
myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], 
			  BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+": "+str+"\n");
       }
   }
/* added by verte */
"/obj/user/chistory"->add_history("Knight Alliance",
 BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+": "+str);
   return 1;
}


send(str) {
   string history; /* added by verte */
   object list;
   object cross;
   int i;
   string myname;
   if(locked){
   write("Your powers are suspended, you are not allowed on the channel.\n");
   return 1;
   }
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ history patch by verte $ */
if(str == "history" || str == "-h")
{
	history = "/obj/user/chistory"->query_history("Knights Templar");
write(history+"\n");
	return 1;
}
/* $ end history patch by verte $ */
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str += "\n";
"/obj/user/chistory"->add_history("Knights Templar",
esc+"[0m"+esc+"[0m"+esc+"[32m"+"(templar) "+this_player()->query_name()+esc+"[0m: "+str);
myname = capitalize((string)this_player()->query_real_name());
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "(templar) "+myname+esc+"[0m: "+
            str+"\n");
       }
   }
   /*
   for (i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && cross->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the templar channel.\n");
   }
  */
   return 1;
}



query_block() { if (block == 3) return 0; else return block; }



block(str) {
   if(str=="enter") {
   block = 3;
     write("Templar Channel on, enter/exit messages off.\n");
   return 1;
  }
   block = !block;
   write("Templar block: ");
   if (block) write("on\n");
   else write("off\n");
   return 1;
}

guildwho() {
   object list;
   string env;
   int namelen;
   int i;
   int b;
   int namlen;
   int spacelen;
   write("\n");
   cat("/players/maledicta/templar/ninfo/head");
   list = users();
   for(i=0; i<sizeof(list);i++) {
      if(present("KnightTemplar",list[i]) && !list[i]->query_invis()) {
         namlen = strlen(list[i]->query_name());
         spacelen = 15-namlen;
if(list[i]->query_level()>9) {
if(present("KnightInvite", list[i])->query_elite()){
write("@   ["+list[i]->query_level()+"] "+HIR+"E"+NORM+""+
"\t"+list[i]->query_name());
}
else{
write("@   ["+list[i]->query_level()+"] "+list[i]->query_guild_rank()+
"\t"+list[i]->query_name());
 }
}
if(list[i]->query_level()<10) {
if(present("KnightInvite", list[i])->query_elite()){
write("@   [0"+list[i]->query_level()+"] "+HIR+"E"+NORM+""+
"\t"+list[i]->query_name());
}
else{
write("@   [0"+list[i]->query_level()+"] "+list[i]->query_guild_rank()+
"\t"+list[i]->query_name());
 }
}
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
    if(environment(list[i]))
       {
         env = environment(list[i])->short();
         namelen = strlen(env);
         spacelen = 47 - namelen;
      }
    if(environment(list[i]))
         write(environment(list[i])->short());
    else write("no location");
         for(b=0;b<spacelen;b++) {
            write(" ");
         }
         write("@\n");
       }
   }
write("@                                                                             @\n");
write("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   write("\n");
   return 1;
}


fixtitle() {
   string title;
   if(elite && TP->query_guild_rank() >= 9){
   title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Templar General"+NORM;
   }
   else if(elite){
   title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Elite Guardsman"+NORM;
   }
   else if(TP->query_guild_rank() >= 8){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Grand Marshall"+NORM;
   }
   else if(TP->query_guild_rank() == 7){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Marshall"+NORM;
   } 
   else if(TP->query_guild_rank() == 6){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"High Commander"+NORM;
   }
   else if(TP->query_guild_rank() == 5){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Commander"+NORM;
   }
   else if(TP->query_guild_rank() == 4){
   title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Knight"+NORM;
   }
   else if(TP->query_guild_rank() == 3){
   title = BOLD+"Knight Errant ["+NORM+BLU+"Templar"+NORM+BOLD+"]"+NORM;
   }
   else if(TP->query_guild_rank() == 2){
   title = BLU+"Shield-Bearer ["+NORM+BOLD+"Templar"+NORM+BLU+"]"+NORM;
   }
   else{
   title = BLU+"Templar Squire"+NORM;
   }
   TP->set_title(title);
   write("Title fixed.\n");
   return 1;
}


sende(str,arg) {
   object list;
   object cross;
   string myname;
   int i;
   if(locked) return 0;
   if(block && block!=3) {
     write("You are blocking the Templar Channel.\n");
     return 1;
   }
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
if(str == "block") {
for(i=0;i<sizeof(list);i++) {
cross = present("KnightTemplar",list[i]);
if(cross && cross->query_block()) {
write(list[i]->query_name()+" is blocking the Templar channel.\n");
}
}
return 1;
}
/* $ color by verte */
str = "/players/vertebraker/closed/std/color"->filter_msg(str);
/* $ end color by verte */
str += "\n";
/*   $ history patch by verte  $ */
"/obj/user/chistory"->add_history(
"Knights Templar",esc+"[0m"+esc+"[0m"+esc+"[32m(templar) "+this_player()->query_name()+esc+"[0m "+str);
/*   $ end history patch by verte $ */
myname = capitalize((string)this_player()->query_real_name());
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && !cross->query_block()) {
      if(arg != 5 || !cross->query_eblock()) 
          tell_object(list[i], esc+"[0m"+esc+"[0m"+esc+"[32m"+
          "(templar) "+myname+esc+"[0m "+
            str+"\n");
       }
   }
    /*
   for (i=0; i<sizeof(list); i++) {
      cross = present("KnightTemplar",list[i]);
      if (cross && cross->query_block() && !list[i]->query_invis())
         write(list[i]->query_name() +" is blocking the templar channel.\n");
   }
   */
   return 1;
}


home(){ 
   if(TP->query_level() > CREATE) return 0;
  if(TP->query_home() == "/room/church" || TP->query_home() == 0){
     TP->set_home("/players/maledicta/templar/rooms/phase_hall.c");
     write("Home now set to Fortress Stone.\n");
     return 1;
   }
    TP->set_home("/room/church");
    write("Home now set to the Village Church.\n");
     return 1;
}

add_council(arg) {
  if(!this_player()) return;
  if(this_player()->query_guild_rank() < 10 ) return;
  council += arg;
  return 1;
}
query_council() { return council; }



remove_member(str) 
{
  object rmd,rmdc;

  if(!council) return 0;
  if(!str) {
    write("You must name someone to remove from the guild.\n");
    return 1; 
  }
  rmd=find_player(str);
  if(!rmd) {
    write("Cannot be found.\n");
    return 1;
  }
  if(rmd->query_guild_name() != "Knights Templar") {
    write(str+" is not a Knight!\n");
    return 1;
  }
  if(rmd == this_player()) {
    write("Can't expel yourself.\n");
    return 1;
  }
  if(present("warrior_gob", rmd)){
  rmd->set_title("the Dishonored Ex-Knight");
  rmd->add_guild_rank(-(rmd->query_guild_rank()));
  rmd->set_home(0);
  present("warrior_gob", rmd)->set_templar(0);
  destruct(present("KnightTemplar", rmd));
  rm("/players/jaraxle/templar/members/"+rmd->query_real_name()+".o");
  }
  else{ 
  rmd->set_guild_file(0);
  rmd->set_home(0);
  rmd->add_guild_rank(-(rmd->query_guild_rank()));
  rmd->set_guild_name(0);
  rmd->add_guild_exp(-(rmd->query_guild_exp()));
  rmd->set_title("the Dishonored Ex-Knight");
  rmdc=present("KnightTemplar",rmd);
  if(rmdc) {
    rmdc->save_banish();
    destruct(rmdc);
   }
  }
  rmd->save_me();
  tell_object(rmd,this_player()->query_name()+" has removed your status as a Templar.\n");
  write(str+" has been removed from the Templars.\n");
  sende("has removed "+rmd->query_name()+" from the Knights Templar.\n");
  write_file("/players/maledicta/templar/SPONSOR", TP->query_real_name() +
  " REMOVED " + rmd->query_real_name() + " " +
  extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+"\n");
  return 1;
}

status
record(string str) {
  string who,why;
  int type;
  object ob;

  if(!str || !sscanf(str, "%s %d %s",who,type,why)) {
    write("Usage: record <who> <type(1-6)> <reason>\n");
    write("Type 'info record' for more info.\n");
    return 1;
  }
  if(!why) {
    write("You must supply a reason. 'record' for more info.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob && this_player()->query_level() < 21) {
    write(capitalize(who)+" is not logged on.\n");
    return 1;
  }
  if(ob && ob->query_level() > 19) {
    write("Wizards can't be logged.\n");
    return 1;
  }
  write_file("/players/maledicta/templar/log/record",extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+" From: "+TP->query_real_name()+" > "+who+" "+type+" "+why+"\n");
  write("Adding "+who+" to the list.\n");
  CRIM->Insert(who, type);
  return 1;
}

read_record() {
  more("/players/boltar/templar/daemon/criminal_record");
  return 1;
}

tail_record() {
tail("/players/boltar/templar/daemon/criminal_record");
return 1;
}
more(str) {
  string tmore;
  string pwd,tilda,blah;
     if(!pwd) pwd="";
    if (!str)
	return 0;
   tmore = str;
   blah = pwd;
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
     tilda=extract(tmore,1,strlen(tmore));
     tmore = "/players/"+TP->query_real_name()+tilda;
    }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   if(file_size(tmore) < 1) {
       write("That file does not exist.\n");
       return 1;
    }
    more_file = str;
    more_line = 1;
    if (cat(more_file, more_line, CHUNK) == 0) {
	write("No such file\n");
	return 1;
    }
    input_to("even_more");
    write("More: (line " + (CHUNK + 1) + ") ");
    return 1;
}

static even_more(str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("EOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

tail_file(path)
{
    if (!path)
	return 0;
    if (!tail(path))
	return 0;
    return 1;
}

set_locked(str) { locked = str; }
clear_locked() { locked = 0; }
query_locked() { return locked; }
lock_member(str) {
  object loc,locgo;

  if(!council) return 0;
  if(!str) { write("Who?\n"); return 1; }
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  if(locgo->query_locked()) {
    write(capitalize(str)+" is already suspended.\n");
    return 1;
  }
  locgo->set_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been suspended.\n");
  tell_object(loc,"Your guild abilities have been suspended by "+
    this_player()->query_name()+"\n");
  write_file("/players/maledicta/templar/log/Suspend",ctime(time())+" "+this_player()->query_name()+" suspended "+capitalize(str)+".\n");
  return 1;
}

unlock_member(str) {
  object loc,locgo;

  if(!council) return 0;
  if(!str) { write("Who?\n"); return 1; }
  loc = find_player(str);
  if(!loc) {
    write("cannot find "+str+".\n");
    return 1;
  }
  locgo=present("KnightTemplar",loc);
  if(!locgo) {
    write(str+" does not have a cross.\n");
    return 1;
  }
  if(!locgo->query_locked()) {
    write(capitalize(str)+" is not suspended.\n");
    return 1;
  }
  locgo->clear_locked(this_player()->query_real_name());
  write(str+"'s guild abilities have been restored.\n");
  tell_object(loc,"Your guild abilities have been restored by "+
    this_player()->query_name()+"\n");
  write_file("/players/maledicta/templar/log/Suspend",ctime(time())+" "+this_player()->query_name()+" restored "+capitalize(str)+".\n");
  return 1;
}


/* criminal_who rewritten by verte to support locations, et al */

criminal_who() {
   int i, z, crim, verte_desc;
   object *us;
   us = users();
   write(GRN);
   write(pad("",69,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:\t\tLocation:\t\t"+NORM+GRN+"    @\n");
   write(NORM+GRN);
   write("@"+pad("",67,'~')+"@\n\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(us); i++) {      
      crim = "/players/boltar/templar/daemon/Criminal"->Query(us[i]->query_real_name());
      if(!environment(us[i]) || us[i]->query_level() > 19 || "/players/boltar/templar/daemon/Ally"->Query(us[i]->query_real_name())) continue;
if(us[i]->query_invis() && us[i]->query_level() >= this_player()->query_level()) continue;
      if(crim || (us[i]->query_level() > 8 && us[i]->query_alignment() < -40)) {
         if(!environment(us[i]) || !environment(us[i])->short()) verte_desc = "Logging In";
         else verte_desc = environment(us[i])->short();
         if(crim)
            if(us[i]->query_attack())
            write(GRN+"  "+BOLD+RED+"*"+pad(us[i]->query_name(),14)+NORM);
         else
            write(GRN+"   "+BOLD+RED+pad(us[i]->query_name(),14)+NORM);
         else 
            if(us[i]->query_attack())
            write(GRN+"  "+NORM+HIR+"*"+NORM+pad(us[i]->query_name(),14));
         else
            write(GRN+"   "+NORM+pad(us[i]->query_name(),14));
         z++;
         if (us[i]->query_pl_k())
            write(us[i]->query_level() + "*\t");
         else
            write(us[i]->query_level() + "\t");
         if (!us[i]->query_guild_name())
            write(pad("None",15));
         else
            write(pad(capitalize(us[i]->query_guild_name()),15));
         if(!us[i]->query_invis() || !us[i]->query_level() <= this_player()->query_level()) write(verte_desc+"\n");
         else write("\n");
       }
   }
   if(!z) write(GRN+"  "+NORM+pad("No Criminals logged in.",36)+"\n");
   write(GRN+"\n");
   write(pad("",69,'@')+"\n");
   write(NORM);
   write(HIR+"Red"+NORM+": criminals  White: Evil players\n");
   return 1;
}

status
criminal(string str) {
  if(!str) return 0;
  if(CRIM->Query(str)) write(CRIM->DetailedQuery(str));
  else write(capitalize(str)+" is not a criminal.\n");
  return 1;
}

status
pardon(string str) {
  string who,why;

  if(!str) return 0;
  if(sscanf(str,"%s %s",who,why)) {
    write_file("/players/maledicta/templar/log/pardon",extract(ctime(time()),4,15)+extract(ctime(time()),19,24)+" From: "+TP->query_real_name()+" > "+who+" "+why+"\n");
    CRIM->Delete(who);
    return 1;
  }
  else {
    write("Usage: pardon <who> <reason>\n");
    return 1;
  }
}


/* $ start horse junk added by verte $ */
set_horsed(x)
{
horsed = x;
}

query_horsed()
{
return horsed;
}
/* $ end horse junk added by verte $ */

do_run(x)
{
    if(TP->query_mounted())
    {
      write("You cannot run while on horseback!\n");
      return 1;
    }
}











