#include "/players/mythos/dmon/def.h"
static int hit_point;
static object attacker_ob;
#include "/players/mythos/dmisc/power/ra_dam.h"
#define RECALL "players/mythos/dmisc/power/play/"
#define epn ep->query_real_name()
int level,xp;


id(str) { return str == "heka" || str == "ka" || str == "eye" || str == "playka"; }

short() { return RED+"Kah"+NORM; }

long() { write(""+
               "The wisdom that Ra/Re (may His anger never rain down upon us)\n"+
               "has bestowed upon the people.  The third eye to which one\n"+
               "is to become enlightened.  The divine power to which all \n"+
               "must bow down before.\n"+
               "Open the eye.\n");
        }

query_prevent_shadow() { return 1; }

drop() { return 1; }
get() { return 0; }

init() {
  if(ep == tp) {
  add_action("open","open");
  }
}

open(str) {
  if(str) {
    if(id(str)) {
      write("You open the eye and all becomes clear!\n");
      write("You have become 'enlight'ened.\n");
      if(!restore_object(RECALL+tpn)) {
        level = 1;
        xp = 0;
        save_object(RECALL+tpn);
      }
      add_action("saved","praise");
      add_action("info","enlight");
      add_action("grant","offer");
      add_action("res","res");
      add_action("tongues","tg");
      if(tl > 99) {
        add_action("shift","shift");
        add_action("slip","slip");
      }
    return 1; }
  }
}

info(str) {
object targ;
string msg;
  if(str && this_player(1)->query_level() < 100 || 
    !query_ip_number(this_player(1))) str = 0;
  if(!str) {
    if(strlen(epn) < 8) msg = "\t\t\t";
    else msg = "\t\t";
    tell_object(this_player(1),RED+
    "---------------------------------0-------------------------------\n"+NORM+
    "  Name:                    Power:           Gifts:          \n"+
    "      "+capitalize(epn)+msg+level+"\t\t"+xp+"\n\n"+
    "  Skills:                  \n");
    tell_object(this_player(1),
    "  praise                               saves stats\n"+
    "  enlight                              shows this menu\n"+
    "  offer                                offers xp to Re\n"+
    "  res                                  update\n"+
    "  tg                                   tongues: speech and who\n");
    if(ep->query_level() > 99) {
    tell_object(this_player(1),
    "  slip <var> <int>                     does a shift on the self\n"+
    "  shift <name> <var> <int>             sets target's heka's var\n");
    }
    tell_object(this_player(1),RED+"\n"+
    "---------------------------------0-------------------------------\n"+NORM);
  }
  else {
    targ = find_player(str);
    if(targ) targ = present("heka",targ);
    else { write("Target is not within the realm's confines.\n"); return 1; }
    if(!targ) { write("Target is not enlightened.\n"); return 1; }
    targ->info();
  }
return 1; }
  

saved() {  save_object(RECALL+tpn); 
              tell_object(ep,"You praise the glory of Re.\n");
              tell_room(environment(ep),TPN+" kneels and bows low in prayer.\n");
              return 1; }

static slip(str) {
  if(!str) { write("usage: slip <var> <int>\n"); return 1; }
  shift(tpn+" "+str);
return 1; }

static shift(str) {
string name,var;
object targ;
int num;
  if(!str) { write("usage: shift <name> <var> <int>\n"); return 1; }
  if(sscanf(str,"%s %s %d",name,var,num) != 3) return 0;
  targ = find_player(name);
  if(targ) targ = present("heka",targ);
  else { write("target not within confines of realm.\n"); return 1; }
  if(!targ) { write("Target is not enlightened.\n"); return 1; }
  if(num == -66) return 0;
  if(call_other(targ,"set_"+var,num) != -66) 
    write("You have set "+name+"'s Heka's "+var+" to "+num+"\n");
  else 
    write("Either your access is limited or the var does not exist as a settable.\n");
return 1; }

set_level(n) { 
    if(this_player(1)->query_level() < 100 || !query_ip_number(this_player(1))) return -66;
    level = n;
    saved();
return 1; }

query_level(n) { if(!n) return level; else if(level == n) return 1; else return 0;}

set_xp(n) {
  if(this_player(1)->query_level() < 100 || !query_ip_number(this_player(1))) return -66;
  xp = n;
  if(xp > 10000 && xp < 100000) set_level(2);
  if(xp > 99999 && xp < 300000) set_level(3);
  if(xp > 299999 && xp < 575000) set_level(4);
  if(xp > 574999 && xp < 850000) set_level(5);
  if(xp > 849999 && xp < 1200000) set_level(6);
  if(xp > 1199999 && xp < 1800000) set_level(7);
  if(xp > 1799999 && xp < 2500000) set_level(8);
  if(xp > 2499999 && xp < 5000000) set_level(9);
  if(xp > 4999999 && xp < 10000000) set_level(10);
  if(xp > 9999999) set_level(xp/10000000 + 10); 
  saved();
  command("open eye",ep);
return 1; }

query_xp() { return xp; }

set_axp(n) {
if(this_player(1)->query_level() < 100 || !query_ip_number(this_player(1))) return -66;
  set_xp(xp+n);
return 1; } 

static grant(str) {
int sac;
sac = 0;
  if(!str) { write("You must offer something. Give a number\n"); return 1; }
  sscanf(str,"%d",sac);
  if(sac < 1) {
    write("Amen-Ra has been angered.  To attempt to fool a god is stupid.\n");
    tp->zap_object(tp);
  return 1; }
  set_axp(sac);
  tp->add_exp(-sac);
  tp->reset(1);
  write("You have given "+sac+" xp to Amen-Re.\n");
return 1; }

res() {
object new;
  new = clone_object("/players/mythos/dmisc/power/pluck.c");
  move_object(new,ep);
  tell_object(ep,"Do not forget to reopen the eye as you close the old one.\n");
  destruct(this_object());
return 1; }

static tongues(str) {
string msg,msg2;
int h;
object ob;
if(!str) {
  ob = users();
  h = 0;
  while(h<sizeof(ob)) {
    if(present("playka",ob[h])) {
     if(tl > 99) write("Security check: pass- You will see invis as well\n");
      write(RED+
      "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"+NORM);
      if(!ob[h]->query_invis() || tl > 99) {
      if(ob[h]->query_invis()) write(BLU);
      write(capitalize(ob[h]->query_real_name()));
      write(NORM);
      write("\t");
      if(strlen(ob[h]->query_real_name()) < 8) write("\t");
      write(present("playka",ob[h])->query_level());
      write("\t"+RED+ob[h]->query_hp()*10/ob[h]->query_mhp()+NORM+"/10 [hp]");
      write("  "+BLU+ob[h]->query_sp()*10/ob[h]->query_msp()+NORM+"/10 [sp]");
      if(ob[h]->query_attack()) 
      write("   ATK: "+(ob[h]->query_attack())->short()); }
      write(RED+"\n"+ 
      "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"+NORM);
    }
 h++; }
}
if(str) {
  h = 0;
  ob = users();
  if(sscanf(str,"*%s",msg2) == 1) {
    msg = " "+msg2+"\n"; }
  else { msg = " intones: "+str+"\n"; }
  while(h<sizeof(ob)) {
  if(environment(ob[h])) {
    if(creator(environment(ob[h])) == "mythos") {
      if(present("playka",ob[h]) || ob[h]->query_real_name() == "mythos") {
        tell_object(ob[h],
        RED+capitalize(tp->query_name())+NORM+msg);
      }
      else {
        tell_object(ob[h],"The wind carries the sound of voices to your ears.\n");
      }
    }
 }
 h++;}
}
return 1; }
