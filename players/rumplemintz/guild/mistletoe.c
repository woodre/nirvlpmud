#define GCLVL 15
#define NAME this_player()->query_real_name()
#define TPQGR this_player()->query_guild_rank()
#define CNAME capitalize(NAME)
#define THIS environment(this_object())
#define ENVIRONMENT file_name(environment(this_player()))
#define LEVEL this_player()->query_level();
#define corpse_heal 5*(this_player()->query_guild_rank())

#include <ansi.h>
#include "/players/rumplemintz/guild/spells/hell_fire.h"

string g_title, fname;
int    follow, monitor, shushed;

int query_shush() { return shushed; }

/*
query_auto_load(){return "/players/rumplemintz/guild/mistletoe:";}
*/

int GLVL() {
  if(THIS && THIS->query_real_name() == "rumplemintz") {
    return 1000;
  }
  else
  if(THIS && THIS->query_real_name() == "dersharp") {
    return 500;
  }
  else
  if(THIS && THIS->query_guild_rank()>0) {
    return this_player()->query_guild_rank();
  }
}


reset(arg){
  tell_object(environment(this_object()), "You have a new mistletoe.\n");
  if(arg) return;
  set_light(1);
  follow = 0;
  monitor=1;
  shushed=0;
  set_heart_beat(1);
  if(GLVL()>999) g_title = ("The Guild Master Druid");
  else if(GLVL()>499) g_title = ("The Assistant Guild Master Druid");
  else if(GLVL()>22) g_title = ("the Hierophant of the Cabal");
  else if(GLVL()>21) g_title = ("the Arcane Hierophant");
  else if(GLVL()>20) g_title = ("the Mystic Hierophant");
  else if(GLVL()>19) g_title = ("the Numinous Hierophant");
  else if(GLVL()>18) g_title = ("the Hierophant Master");
  else if(GLVL()>17) g_title = ("the Hierophant Adept");
  else if(GLVL()>16) g_title = ("the Hierophant Initiate");
  else if(GLVL()>15) g_title = ("the Hierophant Druid");
  else if(GLVL()>14) g_title = ("the Grand Master Druid");
  else if(GLVL()>13) g_title = ("the Grand Druid");
  else if(GLVL()>12) g_title = ("the Archdruid");
  else if(GLVL()>11) g_title = ("the Great Druid");
  else if(GLVL()>10) g_title = ("the Grand Druid Patriarch");
  else if(GLVL()>9) g_title = ("the Druid Patriarch");
  else if(GLVL()>8) g_title = ("the Druid Lama");
  else if(GLVL()>7) g_title = ("the Druid Bishop");
  else if(GLVL()>6) g_title = ("the Druid Elder");
  else if(GLVL()>5) g_title = ("the Druid Curate");
  else if(GLVL()>4) g_title = ("the Druid Vicar");
  else if(GLVL()>3) g_title = ("the Druid Priest");
  else if(GLVL()>2) g_title = ("the Druid Adept");
  else if(GLVL()>1) g_title = ("the Druid Acolyte");
  else g_title = ("the Druid Cantrip");
}

heart_beat(){
  string tmp;
  if(THIS->query_level()<20){
    sscanf(g_title,"%s",tmp);
    THIS->set_title(tmp);
  }
  if(follow==1){
    if(!find_living(fname)){
      follow=0;
      tell_object(THIS,"The person you were following is not on the game.\n");
    } else {
      if(!present(fname, environment(THIS))){
        tell_object(THIS,"You follow "+capitalize(fname)+".\n");
      move_object(THIS,environment(find_living(fname)));
      command("look",THIS);
    }
  }
  if(THIS->query_attack() && monitor==1){
    tell_object(THIS,"HP-> "+THIS->query_hp()+
                "/"+THIS->query_mhp()+
     "  SP-> "+THIS->query_sp()+
     "/"+THIS->query_msp());
    tell_object(THIS,"\n");
    }
  }
}

drop() { return 1; }

get() { return 1; }

string gtitle(int i) {
  if (i) {
    switch(this_player()->query_guild_rank()) {
    case 1..14: return "Druid";
    case 15: return "GMD";
    case 16..23: return "Hierophant";
    case 24: return "Shiznit!";
    case 25..500: return "Asst Guild Master";
    case 1000: return "Guild Master Druid";
    }
  }
  else
    switch(this_player()->query_guild_rank()) {
    case 1000:
      return "The Guild Master Druid";
    case 500:
      return "The Assistant Guild Master Druid";
    case 24:
      return "The Shiznit!";
    case 23:
      return "The Hierophant of the Cabal";
    case 22:
      return "The Arcane Hierophant";
    case 21:
      return "The Mystic Hierophant";
    case 20:
      return "The Numinous Hierophant";
    case 19:
      return "The Hierophant Master";
    case 18:
      return "The Hierophant Adept";
    case 17:
      return "The Hierophant Initiate";
    case 16:
      return "The Hierophant Druid";
    case 15:
      return "The Grand Master Druid";
/*
      this_player()->set_al_title("[GMD]");
*/
    case 14:
      return "The Grand Druid";
    case 13:
      return "the Archdruid";
    case 12:
      return "the Great Druid";
    case 11:
      return "the Grand Druid Patriarch";
    case 10:
      return "the Druid Patriarch";
    case 9:
     return "the Druid Lama";
    case 8:
      return "the Druid Bishop";
    case 7:
      return "the Druid Elder";
    case 6:
      return "the Druid Curate";
     case 5:
      return "the Druid Vicar";
    case 4:
      return "the Druid Preist";
    case 3:
      return "the Druid Adept";
    case 2:
      return "the Druid Acolyte";
    case 1:
      return "the Druid Cantrip";
    }
}

int set_gtitle() {
  string tit;
  tit = gtitle(0);
  this_player()->set_title(HIG + tit + NORM + "");
  if ((int)this_player()->query_guild_rank() == 15)
    this_player()->set_al_title("[GMD]");
}

extra_look() {
  return capitalize(this_player()->query_name())+" seems to be at ease with nature.\n";
}

short(){return "Mistletoe";}

long(){
  write("This is your Druid Mistletoe.  Only the coolest can posses it!\n"+
        "     type \"mistletoe\" for a list of commands.\n");
}

id(str){
  return str == "mistletoe" || str == "druidmistletoe" ||
         str == "GUILD"     || str == "Dguild";
}

mo(){
  if(monitor==1){
    monitor=0;
    write("Hit Point Monitor: OFF\n");
    return 1;
  }
  write("Hit Point Monitor: ON\n");
  monitor=1;
  return 1;
}

init(){
/*------------------Help files--------------------*/
  add_action("Help",            "mistletoe");
  add_action("hell_fire","hellfire");
  add_action("Help1",           "mistletoe1");
  add_action("Help2",           "mistletoe2");
  add_action("Help3",           "mistletoe3");
  add_action("Help4",           "mistletoe4");
  add_action("Help5",           "mistletoe5");
  add_action("Help6",           "mistletoe6");
  add_action("Help7",           "mistletoe7");
  add_action("Help8",           "mistletoe8");
  add_action("Help9",           "mistletoe9");
  add_action("Help10",          "mistletoe10");
  add_action("Help11",          "mistletoe11");
  add_action("Help12",          "mistletoe12");
  add_action("Help13",          "mistletoe13");
  add_action("Help14",          "mistletoe14");
  add_action("GMDHelp",         "GMDHelp");
/*------------------------------------------------*/
  add_action("guild_talk",      "mt");
  add_action("guild_emote",     "me");
  add_action("guild_news",      "news");
  add_action("guild_levels",    "levels");
  add_action("guild_health",    "mo");
  add_action("guild_wimpy",     "gwimpy");
  add_action("leave_guild",     "leaveguild");
  add_action("guild_shush",     "shush");
  add_action("guild_who",       "gw");
  add_action("guild_all",       "ga");
  add_action("guild_wiz",       "gz");
  add_action("NEW_who",         "Whom");
  add_action("emote",           "emote");
  add_action("fix_me",          "renew");
  add_action("note",            "note");
  if(GLVL()>=2)
   add_action("guild_follow",  "follow");
  add_action("coming_of_age",   "ca");
  add_action("rest_eternal",    "re");
  add_action("guild_marry",     "marry");
  add_action("animal_friend",   "af");
  add_action("detect_balance",  "db");
  add_action("detect_poison",   "dp");
  add_action("entangle",        "ent");
  add_action("faerie_fire",     "ff");
  add_action("invis_animal",    "ia");
  add_action("locate_animal",   "loc");
  add_action("pass_without",    "pt");
  add_action("precipitation",   "precip");
  add_action("purify_water",    "pw");
  add_action("shillelagh",      "shillelagh");
  if(GLVL()>=15)
   add_action("commander_emote","ce");
  add_action("commander_tell",  "ct");
  add_action("guild_level", "level");

  if(this_player()==environment() && !this_player()->query_guild_name())this_player()->set_guild_name("druid");
  set_heart_beat(1);
}

Help(){
  cat("/players/rumplemintz/guild/spells/mistletoe_help");
  return 1;
}

Help1(){
  cat("/players/rumplemintz/guild/spells/mistletoe_help1");
  return 1;
}

Help2(){
  if(GLVL()<2){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help2");
  return 1;
}

Help3() {
  if(GLVL()<3){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help3");
  return 1;
}

Help4(){
  if(GLVL()<4){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help4");
  return 1;
}

Help5() {
  if(GLVL()<5){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help5");
  return 1;
}

Help6(){
  if(GLVL()<6){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help6");
  return 1;
}

Help7() {
  if(GLVL()<7){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help7");
  return 1;
}

Help8(){
  if(GLVL()<8){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help8");
  return 1;
}

Help9() {
  if(GLVL()<9){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help9");
  return 1;
}

Help10(){
  if(GLVL()<10){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help10");
  return 1;
}

Help11() {
  if(GLVL()<11){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help11");
  return 1;
}

Help12(){
  if(GLVL()<12){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help12");
  return 1;
}

Help13() {
  if(GLVL()<13){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help13");
  return 1;
}

Help14(){
  if(GLVL()<14){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/mistletoe_help14");
  return 1;
}

GMDhelp(){
  if(GLVL()<15){
    write("You are not the Grand Master Druid, you can't do that.\n");
    return 1;
  }
  cat("/players/rumplemintz/guild/spells/GMD_help");
  return 1;
}

guild_levels(){
   write("'`'`'`'`'`'`'`'`'`'`'`'`'`Titles'`'`'`'`'`'`'``'`'`'`'`'`'`'`'`\n");
   write("\n");
   write("Level 1000. . . . . . . . . . . . . . . .The Guild Master Druid\n");
   write("Level 500. . . . . . . . . . . The Assistant Guild Master Druid\n");
   write("Level 23. . . . . . . . . . . . . . the Hierophant of the Cabal\n");
   write("Level 22 . . . . . . . . . . . . . . . . .the Arcane Hierophant\n");
   write("Level 21. . . . . . . . . . . . . . . . . the Mystic Hierophant\n");
   write("Level 20 . . . . . . . . . . . . . . . .the Numinous Hierophant\n");
   write("Level 19. . . . . . . . . . . . . . . . . the Hierophant Master\n");
   write("Level 18 . . . . . . . . . . . . . .  . . .the Hierophant Adept\n");
   write("Level 17. . . . . . . . . . . . . . . . the Hierophant Initiate\n");
   write("Level 16 . . . . . . . . . . . . . . . . . the Hierophant Druid\n");
   write("Level 15. . . . . . . . . . . . . . . . .the Grand Master Druid\n");
   write("---------------------------------------------------------------\n");
   write("Level 14 . . . . . . . . . . . . . . . . . . . .the Grand Druid\n");
   write("Level 13. . . . . . . . . . . . . . . . . . . . . the Archdruid\n");
   write("Level 12 . . . . . . . . . . . . . . . . . . . .the Great Druid\n");
   write("Level 11. . . . . . . . . . . . . . . the Grand Druid Patriarch\n");
   write("Level 10 . . . . . . . . . . . . . . . . . .the Druid Patriarch\n");
   write("Level  9. . . . . . . . . . . . . . . . . . . . .the Druid Lama\n");
   write("Level  8 . . . . . . . . . . . . . . . . . . . the Druid Bishop\n");
   write("Level  7. . . . . . . . . . . . . . . . . . . . the Druid Elder\n");
   write("Level  6 . . . . . . . . . . . . . . . . . . . the Druid Curate\n");
   write("Level  5. . . . . . . . . . . . . . . . . . . . the Druid Vicar\n");
   write("Level  4 . . . . . . . . . . . . . . . . . . . the Druid Priest\n");
   write("Level  3. . . . . . . . . . . . . . . . . . . . the Druid Adept\n");
   write("Level  2 . . . . . . . . . . . . . . . . . . .the Druid Acolyte\n");
   write("Level  1. . . . . . . . . . . . . . . . . . . the Druid Cantrip\n");
   write("'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'\n");
   write("Everyone starts at guild level one, as a Druid Cantrip.\n");
   write("There can only be one of each level above Grand Druid.\n");
   return 1;
}

emote(str){
  say(capitalize(this_player()->query_name())+" "+str+"\n");
  write(capitalize(this_player()->query_name())+" "+str+"\n");
  return 1;
}

/*  guild_wimpy(arg) {
  string direc;
  int pts;
  set_heart_beat(1);
  if(!arg){
    write("Just in case you can't figure this out:\n");
    write("Usage:  gwimpy <hp> <dir>\n");
  }
  if(!arg){
    whimpy_on=0;
    write("Gwimpy mode off.\n");
    return 1;
  }
  sscanf(arg,"%d %s",pts,direc);
  whimpy_on=1;
  if(pts){whimpy_pts=pts;}
  if(whimpy_pts > this_player()->query_mhp()){
    write("You must set your gwimpy level below your max hp.\n");
    return 1;
  }
  whimpy_dir=direc;
  write("You are set to gwimpy at "+whimpy_pts+" and run "+whimpy_dir+"\n");
  write("Gwimpy engaged.\n");
  return 1;
} */

guild_level(arg){
  string name,title;
  int level,xp,glevel,gxp;
  if(!arg) {
    write("Use: level <name>\n"); return 1;
  }
  if(!find_player(arg)) {
    write("Sorry, that player is not currently on.\n");
    return 1;
  }
  name=capitalize(find_player(arg)->query_name());
  level=find_player(arg)->query_level();
  xp=find_player(arg)->query_exp();
  glevel=find_player(arg)->query_guild_rank();
  gxp=find_player(arg)->query_guild_exp();
  title=find_player(arg)->query_title();
  write("Level:\n\t"+name+"  "+title+"\n\t\t"+level+"  "+glevel+"\n\t\t"+xp+"   "+gxp+"\n");
  return 1;
}

NEW_who(){
  object list;
  int kill,i,level,invis;
  string name,pk,tab,ed,guild,loc;
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Edit"+"\t"+"pk"+"\t"+"Guild\t"+"Where\n");
  write("<<------------------------------------------------------------------------>>\n");
  for(i = 0; i<sizeof(list); i++){
    name = capitalize(list[i]->query_real_name());
    if(environment(list[i])){
      if(environment(list[i])->short()){
        loc = environment(list[i])->short();
      }
    } else {
      loc = "Unknown";
    }
    level = list[i]->query_level();
    invis = list[i]->query_invis();
    kill = list[i]->query_pl_k();
    ed = "  ";
    guild = list[i]->query_guild_name();
    if(in_editor(list[i])){ed = "ed";}
    if(kill == 0){pk = "no";}
    if(kill == 1){pk = "yes";}
    if(invis == 18){
      if(this_player()->query_level() > level -1){
        tab = "\t\t";
        if(strlen(name) > 7){tab = "\t";}
        write(name+tab+level+"\t"+ed+"\t"+pk+"\t"+guild+"\t"+loc+"\n");
      }
    }
    if(invis == 0){
      tab = "\t\t";
      if(strlen(name) > 7){tab = "\t";}
      write(name+tab+level+"\t"+ed+"\t"+pk+"\t"+guild+"\t"+loc+"\n");
    }
  }
  return 1;
}

guild_shush(){
  if(shushed==1){
    write("Guild Tell messages: ON\n");
    shushed=0;
    return 1;
  }
  write("Guild Tell messages: OFF\n");
  shushed=1;
  return 1;
}

guild_news(){
  cat("/players/rumplemintz/guild/news");
  return 1;
}

note(str){
  if(!str){
    write("What do you want to put in the suggestion box?\n");
    return 1;
  }
  write_file("/players/rumplemintz/guild/LOGS/ideas",capitalize(NAME)+" wrote you:\n"+str+"\n------------------------\n");
  write("The note has been dropped in the box, thank you very much!\n");
  return 1;
}

rest_eternal(){
  int x;
  object corp;
  if(this_player()->query_sp()<3){
    write("You don't have enough spell points to do that.\n");
    return 1;
  }
  if(GLVL()< 2){
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!present("corpse",environment(this_player()))){
    write("There is no corpse in this room.\n");
    return 1;
  }
  corp=present("corpse",environment(this_player()));
  destruct(corp);
  this_player()->add_hit_point(corpse_heal);
  lessp(2);
  write("You release the soul/spirit of the corpse, and feel revitalized.\n");
  say(CNAME+" releases the soul of the corpse.\n");
  return 1;
}

whois(low,hi){
  object people;
  string sex;
  object bad;
  int a,n,cnt;
  cnt=0;
  people=users();
  write("-Name-\t\t-Sex- -Lvl- -Location-\n");
  for(n=0; n<sizeof(people); n++){
    if(people[n]->query_guild_name()=="druid"){
      if(people[n]->query_invis() > this_player()->query_level()) {
        write("");
      } else {
        if(people[n]->query_guild_rank()<hi && people[n]->query_guild_rank()>low) {
          cnt++;
          write(capitalize(people[n]->query_real_name()));
          if(strlen(people[n]->query_real_name())>7){ write("\t"); }
          else { write("\t\t"); }
          sex=people[n]->query_gender();
          if(sex=="male") sex="M";
          else if(sex=="female") sex="F";
          else sex="C";
          write(sex+"\t  ");
          write(people[n]->query_guild_rank()+"\t ");
          write(environment(people[n])->short());
        }
        if(people[n]->query_invix()>0) write(" (invis)");
        if(query_idle(people[n]) > 120)
          write(" (idle:"+(query_idle(people[n])/60)+")");
        bad=present("Dguild",people[n]);
        if(bad->query_shush()==1) write(" (shushed)");
        write("\n");
      }
    }
  }
  write(">>> "+cnt+" people listed.\n");
  return 1;
}

guild_who(){
  whois(0,(GCLVL+9));
  return 1;
}

guild_all(){
  whois(0,1001);
  return 1;
}

guild_wiz(){
  whois((GCLVL+8),1001);
  return 1;
}

guild_talk(str){
  object people;
  object bad;
  int n, x;
  if(!str){
    write("Tell guildmembers what?\n");
    return 1;
  }
  people = users();
  for(n=0; n<sizeof(people); n++){
    if(people[n]->query_guild_name()=="druid"){
      bad=present("Dguild",people[n]);
      if(bad->query_shush()==0 && people[n]->query_guild_rank()>0){
        tell_object(people[n],HIG+"< "+
                    gtitle(1) +
                    " >"+CNAME+": " + str + NORM + "\n");
      }
    } else {
      x = random(10);
      if(x<5 && present(people[n],environment(this_player())) && people[n]->query_level() < 20){
        tell_object(people[n],"The trees make some noises.\n");
      }
    }
  }
  return 1;
}

lessp(i){
  this_player()->add_spell_point((-1 * i));
  return 1;
}

guild_emote(str){
  int i;
  object people;
  string mand,rest;
  int lev;
  if(str){
    if(sscanf(str,"%sH>< %s",mand,rest)){
      lev=GCLVL;
      str=rest;
    } else lev=1;
  }
  if(this_player()->query_guild_rank()<lev) {
    write("You can't do that!\n");
    return 1;
  }
  if(!str){
    write("What do you want to emote?\n");
    return 1;
  }
  people=users();
  if(lev<GCLVL) lev=0;
  for(i=0; i<sizeof(people); i++){
    if (((people[i]->query_guild_name()=="druid")
       && people[i]->query_guild_rank()>(lev-1))
      || people[i]->query_real_name()=="rump") {
      if(!present("Dguild",people[i])->query_shush()){
        if(lev)
          tell_object(people[i],"\n"+HIG+">>>"+CNAME+" "+str+NORM+"\n");
        else
        tell_object(people[i],"\n"+HIG+"->>"+CNAME+" "+str+NORM+"\n");
      }
    }
  }
  lessp(2);
  if(lev)
    write("You Hierophant_emote:\n"+CNAME+" "+str+"\n");
  else
  write("You guild_emote:\n"+CNAME+" "+str+"\n");
  return 1;
}

commander_emote(str){
  if(GLVL()<GCLVL){
    write("You aren't a high enough level to do that yet.\n");
    return 1;
  }
  if(!str){
    write("Hierophant emote what?\n");
    return 1;
  }
  guild_emote(HIG+"><H>< "+str+NORM);
  return 1;
}

guild_follow(str){
  if(!str){
    if(follow==1){
      follow=0;
      write("You are no longer following anybody.\n");
    } else {
      write("You weren't following anybody.\n");
      follow=0;
    }
    return 1;
  }
  if(this_player()->query_sp()<20){
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(!present(str,environment(this_player()))){
    write("That person is not here.\n");
    follow=0;
    return 1;
  }
  fname=str;
  lessp(20);
  follow=1;
  write("You are now following "+capitalize(fname)+".\n");
  return 1;
}

commander_tell(str){
  object people,bad;
  int n, x;
  if(GLVL()<GCLVL){
    write("You are not a Hierophant!\n");
    return 1;
  }
  people=users();
  for(n=0; n<sizeof(people); n++)
    if ((people[n]->query_guild_name()=="druid") &&
         people[n]->query_guild_rank()>(GCLVL-1))
      if(present("Dguild",people[n])->query_shush()==0)
      tell_object(people[n],"<H>"+CNAME+"<D>: "+str+"\n");
  return 1;
}

fix_me(){
  object it;
  it=clone_object("/players/rumplemintz/guild/mistletoe");
  move_object(it,this_player());
  write("You now have new mistletoe.\n");
  set_gtitle();
  destruct(this_object());
  return 1;
}
