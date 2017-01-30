/* 10/09/05 - Earwax - Added set_guild_file(PATH+"guildob.c") */
/* 10/09/05 - Earwax - Added guild_login() as well, and GI id */
/* 12/12/2006 - Rumplemintz - Changed PATH in DEF file to point to new dir */

/* THE BASE NECROMANCER OBJECT */

/* def's included by skull -Bp
 #include "defs.h"
*/
#include "skull.h"
/* color, ansi.h included by defs included by skull -Bp
#include COLOR
*/
#define BAR  "\t<----------------------------------------------------------->\n"
#define SPACE "       "

int blood, eye, heart, skin, soul, spine;
int cdust;
int val;
int g_level;
int muffle;
string enter_msg, leave_msg;
static int icutmyself;

/* hidden */
int emdeaths, sacrifice;
int harvs, harvest;

/* Earwax 10/09/05: This no longer necessary
query_auto_load() {return "/players/wocket/necro/guildob.c:"; }
*/

id(str) {
  if(previous_object()) {
    if(!snow_idcheck(previous_object()))
      return (str == "GI" || str == GUILD_ID || str == "skull" || str == "pouch" || str == "necro_pouch");
  }
  return (str == "GI" || str == GUILD_ID || str == "skull" || str == "pouch" || str == "necro_pouch" || str == "notarmor");
}  

snow_idcheck(obj){
  if(!obj) return 1;
  if(obj->armor_class() > 0){
    if(obj->query_type() == "armor"){
        if(obj->query_weight() > 2)
          return 1;
        else
          return 0;
    }
    if(obj->query_weight() > 1)
      return 1;
  }
  return 0;
}

short() { return "A small, brightly polished skull.\nComponent pouch"; }
long(str) {
  string arg1,arg2;
  int int1,int2;

  if(!str) str = "skull";
  if(sscanf(str,"%s %s",arg1,arg2) != 2) arg1 = str;
  if(arg1 == "skull"){
    write("A skull taken from a treasured victory of long ago.\n"+
          "The skull has been meticulously cleaned and taken\n"+
          "care of. The symbol of a true Necromancer.  There seems\n"+
          "to be some writings carved into the back.  You might be\n"+
          "able to 'read' the 'skull'.\n");
  }
  if(arg1 == "pouch"){
    string msg;
    write("Darkened leather stained with many unknown substances makes\n"+
          "up the component pouch that is used primarily to store spell\n"+
          "components. A small drawstring holds it closed.\n");
    msg = "\tYour pouch currently contains:\n";
    if(blood){
      msg+= "\t  "+BOLD+blood+OFF+" vial";
      if(blood > 1) msg+="s";
      msg+=" of blood\n";
    }
    if(skin){
      msg+= "\t  "+BOLD+skin+OFF+" skin";
      if(skin > 1) msg+="s";
      msg+="\n";
    }
    if(eye){
      msg+= "\t  "+BOLD+eye+OFF+" eye";
      if(eye > 1) msg+="s";
      msg+="\n";
    }
    if(spine){
      msg+= "\t  "+BOLD+spine+OFF+" spine";
      if(spine > 1)  msg+="s";
      msg+="\n";
    }
    if(heart){
      msg+= "\t  "+BOLD+heart+OFF+" heart";
      if(heart > 1) msg+="s";
      msg+="\n";
    }
    if(soul){
      msg+= "\t  "+BOLD+soul+OFF+" soul";
      if(soul > 1) msg+="s";
      msg+="\n";
    }
    write(msg);
    say(tpn+" searches through "+environment()->query_possessive()+
        " component pouch for a moment.\n");
  }
}

drop() { return 1;}
get() { return 1;}

extra_look() {
  write(environment()->query_name()+" has a small "+BOLD+"skull"+OFF+
        " tattoo upon "+environment()->query_possessive()+" forehead.\n");
  if(icutmyself)
    write(environment()->query_name()+" has several lacerations across "+
          environment()->query_possessive()+" wrists.\n");
}

/* Earwax 10/07/05: Switched this to guild_login()
init_arg(){
*/
guild_login() {
  string news;
  int i,a,b,c;
  this_player()->set_guild_file(PATH+"/guildob.c"); /* Earwax */
  this_player()->set_home(PATH+"room/necro2");
  move_object(clone_object("/players/guilds/necro/guildob.c"), this_player());
  destruct(this_object());
}

login_trimed_off() {
  string news;
  int i,a,b,c;
  news = read_file(PATH+"/NEWS");
  news = explode(news,"\n");
  b = sizeof(news);
  write("\n"); 
  write("\t<"+HIR+"Necromantic News"+OFF+
        ">----------------------------------------->\n");
  for(i=0;i<b;i++){
    write(SPACE+BOLD+BLK+cutstring(news[i],70)+OFF+"\n");
  }
  write(BAR);
  write("\n");
  call_out("intro",2);
}

void intro(){
  tell_object(ep,BOLD+
              "\n\nYou awake in the center of the Necromancer Guildhall.\n\n"+
              OFF);
  command("look",ep);
  tell_object(ep,"->>");
}

init() {
  if (this_player()) {
    this_object()->guild_login();
    destruct(this_object());
  }
  if(this_object())
    if(environment(this_object()))
      if(environment(this_object()) == this_player()) {
        if(!restore_object(SAVE+tprn)) {
          if(restore_object(SAVE+"bak/"+tprn)){
            write("Your services are no longer needed for testing the "+
                  " necromancer guild.\nThankyou for your time.\n");
            tp->set_home("/room/church");
            tp->add_guild_rank(-tp->query_guild_rank());
            tp->add_guild_exp(-tp->query_guild_exp());
            tp->set_guild_name();
            move_object(tp,"/room/church");
            tp->save_me();
            destruct(this_object());
            return 1;
          }
          blood = 25;
          eye = 0;
          heart = 0;
          skin = 0;
          soul = 0;
          spine = 0;
          cdust = 0;
          g_level = 1;
          save_object(SAVE+tprn);
        }
        if(tp->query_level() < 20) {
          tp->set_guild_name("necromancer");
          if(tp->query_guild_rank() != g_level) 
            tp->add_guild_rank(g_level - tp->query_guild_rank());
          tp->set_home("/players/wocket/necro/room/necro2.c");
          tp->set_pretitle("|");
          necro_title();
          if (tp->query_guild_file() != (PATH+"/guildob.c"))
            tp->set_guild_file(PATH+"/guildob.c");
          write("<"+BOLD+"NECRO"+OFF+"> Guild Status Restored.\n");
          save_me();
          tp->save_character();
        }
        CHAT_D->resetchannel();
        /* basic guild abilities */
#ifndef __LDMUD__ /* Rumplemintz */
        add_action("spell_hook");add_xverb("");
        add_action("cmd_hook");add_xverb("");
        add_action("emote_hook");add_xverb("");
#else
        add_action("spell_hook", "", 3);
        add_action("cmd_hook", "", 3);
        add_action("emote_hook", "", 3);
#endif
        if(tpl > 20){
#ifndef __LDMUD__ /* Rumplemintz */
          add_action("admin_hook");add_xverb("");
#else
          add_action("admin_hook", "", 3);
#endif
        }
        add_action("deathcheckme","deathcheckme");
        deathcall();
        wimpycall();
        add_action("sub_comp","get");
        add_action("sub_comp","take");
        add_action("add_comp","put");
        add_action("move_pouch","give");
        add_action("quit","quit");
        add_action("necro_quit","leave_guild");
        add_action("necro_save","nsave");
        add_action("necro_update","nupdate");
        add_action("necro_title","ntitle");
#ifndef __LDMUD__ /* Rumplemintz - doesn't work quite like you're trying */
        add_action("necro_block","missile",2);
        add_action("necro_block","shock",2);
        add_action("necro_block","fireball",2);
        add_action("necro_block","sonic",2);
        add_action("necro_block","invisible",5);
#else
        add_action("necro_block", "missile", -2);
        add_action("necro_block", "shock", -2);
        add_action("necro_block", "fireball", -2);
        add_action("necro_block", "sonic", -2);
        add_action("necro_block", "invisible", -5);
#endif
        add_action("necro_block","pose");
        add_action("read_me","read");
        add_action("polish_me","polish");
        add_action("necro_obit", "deaths");
#ifndef __LDMUD__ /* Rumplemintz */
        add_action("newsay");add_xverb("'");
#else
        add_action("newsay", "'", 3);
#endif
      }
}

newsay(str){
  command("say "+str,tp);
  return 1;
}

query_guild_title() {
  string title;
 /* changed from if(g_level) verte */
  if(intp(g_level))
  switch(g_level){
    case 1:      title = "the Apprentice Necromancer"; break;
    case 2..3:   title = YEL+"the Harvester of the Dead"+OFF; break;
    case 4..5:   title = "the "+HIR+"Defiler"+OFF+" of "+HIR+"Graves"+OFF; break;
    case 6..8:   title = BOLD+BLK+"the Necromancer"+OFF; break;
    case 9:      title = BOLD+"the Minister of Souls"+OFF; break;
  }
  if(this_player()->query_real_name() == "sebastian"){
    title = BOLD+BLK+"the Necromanic Scribe"+OFF;
  }
  return title;
}

set_muffle(m){ muffle = m; }
query_muffled(){ return muffle; }

save_me() { g_level = ep->query_guild_rank(); save_object(SAVE+epn); return 1; }

necro_save() { save_me(); tell_object(ep,"You begin to meticulously clean your skull until it shines.\n"+
                                         "<"+HIR+"NECRO"+OFF+"> Guild status saved.\n"); return 1; }

polish_me(str){
  if(!str){
    notify_fail("What would you like to polish?\n");
    return 0;
  }
  if(str != "skull"){
    notify_fail("That is not something you can polish.\n");
    return 0;
  }
  necro_save();
  return 1;
}

necro_update() {
  save_me();
  write("<"+HIR+"NECRO"+OFF+"> Guild Status Saved.\n");
  move_object(clone_object(PATH+"/guildob.c"),tp);
  write("<"+BOLD+BLK+"NECRO"+NORM+"> Guild Status Updated.\n");
  destruct(this_object());
return 1; }

necro_title() {
 string title;
  switch(g_level){
    case 1:      title = "\b, the Apprentice Necromancer"; break;
    case 2..3:   title = "\b, "+YEL+"the Harvester of the Dead"+OFF; break;
    case 4..5:   title = "\b, the "+HIR+"Defiler"+OFF+" of "+HIR+"Graves"+OFF; break;
    case 6..8:   title = "\b, "+BOLD+BLK+"the Necromancer"+OFF; break;
    case 9:      title = "\b, "+BOLD+"the Minister of Souls"+OFF; break;
  }
  if(this_player()->query_real_name() == "sebastian"){
    title = "\b, "+BOLD+BLK+"the Necromanic Scribe"+OFF;
  }
  tp->set_title(title);
  write("<"+HIW+"NECRO"+NORM+"> Necromancer Title Set.\n");
return 1; 
}

necro_quit() {
  tp->set_guild_name(0);
  tp->add_exp(tp->query_guild_exp());
  tp->add_guild_exp(-tp->query_guild_exp());
  tp->add_guild_rank(-tp->query_guild_rank());
  tp->set_home("/room/church");
  tp->set_guild_file(0); /* Earwax 10/09/05 */
  tp->add_exp(-(tp->query_exp()/2));
  tp->set_attrib("sta",1);
  tp->reset(1);
  command("save",tp);
  write(BOLD+"The Spirits tell you, \""+OFF+"FOOL!"+BOLD+"\"\n");
  CHAT_D->sub_membr(tp);
  CHAT_D->chat_line("has left the guild",tp->query_real_name(),1);
  rm("/"+SAVE+tpn+".o");
  destruct(this_object());
return 1; 
}

quit() {
  necro_save();
  CHAT_D->resetchannel();
}

necro_block() {
  if(tp->query_level() < 20) {
    write(ROD+" The Realm of Death disdains the use of that spell.\n");
    this_player()->add_hit_point(-random(10));
    return 0; 
  }
}

read_me(str){
string msg;
int gl;
  if(!str){
    notify_fail("What would you like to read?\n");
    return 0;
  }
  if(str != "skull"){
    notify_fail("That is not something you can read here.\n");
    return 0;
  }
  gl = this_player()->query_guild_rank();
    write("The carvings on the back of the skull read:\n\n");
    write("Basic   -  necro(nc), necro who(necros), nupdate, polish skull, leave_guild\n"+
          "            ntitle, muffle necro, channel necro\n");
    write("Level 1 -  chill, harvest, claim dagger, embalm corpse, evoke ghouls, dismember\n"+
          "            consider\n");
  if(gl > 1){
    write("Level 2 -  consume corpse, embrace death, grasp, excavate corpse\n");
  }
  if(gl > 2){
    write("Level 3 -  dig grave, drain, animate skeleton, consecrate gravesite\n");
  }
  if(gl > 3){
    write("Level 4 -  summon ghastly stench, cloak, anguish, echo\n");
  }
  if(gl > 4){
    write("Level 5 -  disease, graft, siphon\n");
  }
  if(gl > 5){
    write("Level 6 -  bloodmoon, raise portal\n");
  }
  if(gl > 6){
    write("Level 7 -  summon pestilence, decay\n");
  }
  if(gl > 7){
    write("Level 8 -  abandon, animate zombie\n");
  }
  if(gl > 8){
    write("Level 9 -  reanimate, wither\n");
  }
  msg = "";
  if(sacrifice){
    msg = "Other   -  ";
    if(sacrifice)
      msg += "sacrifice ";
    write(msg+"\n");
  }
  write("\n");
  return 1;
}

comp_cost() {
cat(DOCS+"/comp_costs.txt");
return 1;
}

checklev(int gl,lev){
  if(!ep) return;
  if(gl > ep->query_guild_rank()){
    tell_object(ep,"You do not have the knowledge for that spell.\n");
    return 0;
  }
  if(lev > ep->query_level()){
    tell_object(ep,"You aren't experienced enough to use that spell.\n");
    return 0;
  }
  return 1;
}

necro_who() {SPELL_D->necro_who(); return 1; }

wimpycall(){
  if(ep->query_wimpy()){
    tell_object(ep,ROD+"The Realm of Death distains your cowardice.\n");
    tell_object(ep,BOLD+"You are stricken with pain as your heart constricts.\n"+OFF);
    ep->add_hit_point(- (ep->query_level()*3));
  }
call_out("wimpycall",random(1000));
}

deathcall(){
  while(remove_call_out("deathcall") != -1); /* 07/19/06 Earwax */
  if (!environment()) return; /* 07/19/06 Earwax */
  command("deathcheckme",environment(this_object()));
  call_out("deathcall",20);
}

deathcheckme(){
  DEATH_D->newdeathcheck();
  return 1;
}

spell_hook(str){
  int i;
  string temp;
  string arg1,arg2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",arg1,arg2) != 2){
    arg1 = str;
  }
  if(arg1 == "") return 0;
  i = strlen(arg1);
  if(arg1[i-1] == 046) return 0;
  temp = SPELLS+"/"+arg1+".c";
  if(file_size(temp) > 0){
    if(tp->query_dead()){
      notify_fail("You have no control over the dark arts as one of the dead.\n");
      return 0;
    }
    if(tp->test_dark()){
      notify_fail("You can not see your component pouch.\n");
      return 0;
    }
    if(temp->cmd(arg2))
      return 1;
    }
  return 0;
}

emote_hook(str){
  int i;
  string temp;
  string arg1,arg2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",arg1,arg2) != 2){
    arg1 = str;
  }
  if(arg1 == "") return 0;
  i = strlen(arg1);
  if(arg1[i-1] == 046) return 0;
  temp = EMOTES+"/"+arg1+".c";
  if(file_size(temp) > 0){
    if(temp->cmd(arg2))
       return 1;
  }
  return 0;
}

cmd_hook(str){
  int i;
  string temp;
  string arg1,arg2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",arg1,arg2) != 2){
    arg1 = str;
  }
  if(arg1 == "") arg1 = "blah";
  i = strlen(arg1);
  if(arg1[i-1] == 046) return 0;
  temp = CMDS+"/"+arg1+".c";
  if(file_size(temp) > 0){
    if(temp->cmd(arg2))
       return 1;
  }
  return 0;
}

admin_hook(str){
  int i;
  string temp;
  string arg1,arg2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",arg1,arg2) != 2){
    arg1 = str;
  }
  if(arg1 == "") return 0;
  i = strlen(arg1);
  if(arg1[i-1] == 046) return 0;
  temp = ADMIN+"/"+arg1+".c";
  if(file_size(temp) > 0){
    if(temp->cmd(arg2))
       return 1;
  }
  return 0;
}

/*  COMPONENT POUCH */

add_blood(int num){ blood += num; save_me();}
add_skin(int num){ skin += num; save_me();}
add_eye(int num){ eye += num; save_me();}
add_spine(int num){ spine += num; save_me();}
add_heart(int num){ heart += num; save_me();}
add_soul(int num){ soul += num; save_me();}
add_cdust(int num){ cdust += num; save_me();}
add_val(int num) { val += num; save_me();}
set_val(arg) { val = arg; necro_save(); return 1; }

query_blood() {return blood; }
query_skin() {return skin; }
query_eye() {return eye; }
query_spine() {return spine; }
query_heart() {return heart; }
query_soul() {return soul; }
query_cdust() {return cdust; }
query_val() { return val; }
query_g_level() {return g_level; }

add_comp(str) {
string bodypart;
object comp;
  if(!str) return 0;
  sscanf(str,"%s in pouch",bodypart);
  if(!bodypart) return 0;
  switch(bodypart){
    case "blood":    bodypart = "blood"; break;
    case "bloods":   bodypart = "blood"; break;
    case "vial":     bodypart = "blood"; break;
    case "vials":    bodypart = "blood"; break;
    case "skin":     bodypart = "skin";  break;
    case "skins":    bodypart = "skin";  break;
    case "eye":      bodypart = "eye";   break;
    case "eyes":     bodypart = "eye";   break;
    case "spine":    bodypart = "spine"; break;
    case "spines":   bodypart = "spine"; break;
    case "soul":     bodypart = "soul";  break;
    case "souls":    bodypart = "soul";  break;
    case "heart":    bodypart = "heart"; break;
    case "hearts":    bodypart = "heart"; break;
    default: write("There is no room for your "+bodypart+" in the component pouch.\n");
             return 1;
  }
    if(comp = present("necro_"+bodypart,tp)) {
          write("You put the "+bodypart+" in your component pouch.\n");
    say(tpn+" puts some "+bodypart+" into "+tpp+" pouch.\n");
          call_other(to,"add_"+bodypart,comp->query_amount());
    save_me();
    destruct(comp);
    tp->recalc_carry();
          return 1;
     } else {
    write("There is no room for "+str+" in your component pouch.\n");
  return 1; }
}

sub_comp(str) {
string bodypart,temp;
  if(!str){
    return 0;
  }
  sscanf(str,"%s from pouch",bodypart);
  if(!bodypart) return 0;
  if(bodypart != "blood" && 
     bodypart != "skin"  && 
     bodypart != "eye"   && 
     bodypart != "spine" &&
     bodypart != "soul"  && 
     bodypart != "heart"){
    write("There is no "+bodypart+" in the component pouch.\n");
    return 1; }
    if(call_other(to,"query_"+bodypart) > 0) {
      if(!tp->add_weight(1)){
        write("You can not carry the "+bodypart+".\n");
       return 1;
      }
      write("You remove some "+bodypart+" from the component pouch.\n");
      say(tpn+" removes some "+bodypart+" from the component pouch.\n");
      call_other(to,"add_"+bodypart,-1);
      save_me();
      temp = BODYPARTS+"/"+bodypart+".c";
      move_object(clone_object(temp),tp);
      tp->recalc_carry();
      return 1;
    } 
    else {
      write("There is no "+bodypart+" in the component pouch.\n");
      return 1; }
} 

move_pouch(str){
string what,who;
  if(!str){ return 0; }
  sscanf(str,"%s to %s",what,who);
  if(!what || !id(what)) return 0;
  if(!who || who != tprn) return 0;
  move_object(to,tp);
  return 1;
}

/* HIDDEN SPELLS */
add_harvs(i){
  harvs += i;
  if(harvs > 1000 && !harvest){
    write(BOLD+"Through much dedication and practice you feel have gained the skill\n"+
               "to harvest with a larger weapon.\n"+OFF);
    harvest = 1;
  }
}

add_emdeaths(i){
string file; 
  emdeaths += i;
  if(emdeaths >= 2 && !sacrifice ){
    call_out("add_spell",10,({ "sacrifice", }) );
  }
} 

set_emdeaths(i){ emdeaths = i; }
set_sacrifice(i){ sacrifice = i; }
set_harvest(i){ harvest = i; }

query_emdeaths(){ return emdeaths; }
query_sacrifice(){ return sacrifice; }
query_harvest(){ return harvest; }

add_spell(arg){
  tell_object(ep,ROD+" The realm of death is pleased with your dedication.  \n"+
                 BOLD+"      You have been empowered with a new spell.\n"+OFF);
  tell_object(ep,"You can now cast "+arg[0]+".\n");
  call_other(this_object(),"set_"+arg[0],1);
  save_me();
}

/* ATMOSPHERE */ 
add_icutmyself(i){ icutmyself = icutmyself+i; }
set_icutmyself(i){ icutmyself = i; }
query_icutmyself(){ return icutmyself;}

amihealed(){
  remove_call_out("amihealed");
  icutmyself--;
  if(icutmyself < 1){
    tell_object(environment(),"The wounds on your wrists have healed.\n");
    environment()->remote_say("The wounds on "+environment()->query_name()+"'s wrists have healed.\n");
  }
  else{
    call_out("amihealed",40);
  }
}
 
necro_obit()
{
  call_other("/players/wocket/necro/obj/deathlog", "deathlog", 0);
  write("  <"+HIR+"Necromantic Death Notice"+OFF+">------------------------------------------------->\n\n");
  write("     Player        Time                Killed by\n\n");
  tail("/players/wocket/necro/log/deathlog");
  write("\n");
  write("  Level scale:  "+GRN+"Low  "+HIY+"Mid  "+NORM+RED+"High  "+BOLD+"Great  "+MAG+"Legendary\n"+OFF);
  write(BOLD+"  *"+OFF+" - Killed by Sparring.\n\n");
  write("  <-------------------------------------------------------------------------->\n");
  return 1;
}
       
