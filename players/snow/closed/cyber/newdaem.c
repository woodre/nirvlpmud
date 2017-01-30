/* Do not remove - mizan */

#define S10flag "/players/snow/closed/cyber/newdaem"
#define S10DAM_CAP 50

/* end change */

#include "color.h"
#include "definitions.h"

id(str) { return str == "daemon"; }
short () {return "CyberNinja daemon";}
long() {write("This is the CyberNinja guild daemon.\n");}

info_database(string str) {
/* takes str and refers to files in docs directory */
  string file, topic, all;
  if(!str) {
     cat("/players/snow/closed/cyber/docs/main_menu");
    return; }
  if(sscanf(str, "%s %s", topic, all)) {
     file = "/players/snow/closed/cyber/docs/" + topic;
    file = shorted_file(file);
    if(all == "all") {
      if (file_size(file) >= 0) {
        cat(file);
        return; }
      else {
        write("There is no help on that cyber topic.\n");
        return; }
      }
    if(all != "all") {
      write("Usage: cyber [topic]   or   cyber [topic] all.\n");
      return; }
    }
  if(sscanf(str, "%s", topic)) {
      file = "/players/snow/closed/cyber/docs/" + topic;
      file = shorted_file(file);
      if (file_size(file) >= 0) {
         if(find_menu(file)) {
           cat(file);
           return; }
         call_other("/players/snow/closed/cyber/_more.c",
                   "more_file", file);
         return; }
      write("There is no help on that cyber topic.\n");
      return; }
  write("Usage: cyber [topic]   or   cyber [topic] all.\n");
}

officer_database(string str) {
/* takes str and refers to files in fax directory */
  string file, topic, all;
  if(!str) {
    cat("/players/snow/closed/cyber/fax/fax_menu");
    return; }
  if(sscanf(str, "%s %s", topic, all)) {
    file = "/players/snow/closed/cyber/fax/" + topic;
    file = shorted_file(file);
    if(all == "all") {
      if (file_size(file) >= 0) {
        cat(file);
        return; }
      else {
        write("There is no help on that fax topic.\n");
        return; }
      }
    if(all != "all") {
      write("Usage: fax [topic]   or   fax [topic] all.\n");
      return; }
    }
  if(sscanf(str, "%s", topic)) {
     file = "/players/snow/closed/cyber/fax/" + topic;
      file = shorted_file(file);
      if (file_size(file) >= 0) {
         if(find_menu(file)) {
           cat(file);
           return; }
         call_other("/players/snow/closed/cyber/_more.c",
                   "more_file", file);
         return; }
      write("There is no help on that fax topic.\n");
      return; }
  write("Usage: fax [topic]   or   fax [topic] all.\n");
}

int find_menu(string str) {
  string menustr;
  if(sscanf(str, "%smenu", menustr) == 1) return 1;
  if(sscanf(str, "%sshort", menustr) == 1) return 1;
  return 0;
}

string shorted_file(string str) {
  string files;
  files = str + "short";
  if(file_size(files) >= 0) str = files;
  return str;
}


object IP(object ob) {
/* This function is similar to a #define, it just
 * returns the guild object on the player specified.
 */
   object guild_object;
   guild_object = present("implants", ob);
   return guild_object;
}

update_implants() {
/* Simply updates the guild object */
   object implants, this_ob;
   implants = clone_object("/players/snow/closed/cyber/implants.c");
   move_object(implants, this_player());
   this_ob = present("implants", this_player());
   destruct(this_ob);
   present("implants", this_player())->init(1);
   return 1;
}


enhance(string str) {
/* Used for guild level promotions/demotions */
  int new_lev, current_lev, low_new_xp;
  string who;
  object targ;
  if(!str) {
    write("Usage: enhance <member> <newlevel>.\n");
    return;}
  if(!sscanf(str, "%s %d", who, new_lev)) {
    write("Usage: enhance <member> <newlevel>.\n");
    return;}
  if(!IP(find_player(who))) {
    write("User "+capitalize(who)+" is not valid.\n");
    return;}
  targ = find_player(who);
  current_lev = IP(targ)->guild_lev();
  if (new_lev == current_lev) {
    write(capitalize(who)+" is already of quality "+new_lev+"\n");
    return;}
  if (new_lev < 0) {
    write("You cannot drop a member below quality 0.\n");
    return;}
  if((new_lev > 10) && (targ->query_level() > 19)) {
    write("Be sure to read the help files on levels.\n");
    write_file(log+"ENHANCE", RN+" enhanced "+targ->query_real_name()+
                              " from quality "+current_lev+" to "+
                              new_lev+". ("+ctime()+")\n");
    TE(targ, "You have been changed to quality "+new_lev+".\n");
    TE(targ, "You should read the help files on wiz members.\n");
    IP(targ)->set_rank(new_lev);
    targ->add_guild_rank(new_lev - current_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    targ->add_guild_exp(-targ->query_guild_exp());
    targ->add_guild_exp(low_new_xp);
    IP(targ)->save_me();
    targ->save_me();
    return;}
  if (new_lev > 10) {
    write("Be sure to read the help files on levels.\n");
    write_file(log+"ENHANCE", RN+" enhanced "+targ->query_real_name()+
                              " from quality "+current_lev+" to "+
                              new_lev+". ("+ctime()+")\n");
    TE(targ, "You have been promoted to level "+new_lev+".\n");
    IP(targ)->set_rank(new_lev);
    targ->add_guild_rank(new_lev - current_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    IP(targ)->save_me();
    targ->add_guild_exp(-targ->query_guild_exp());
    targ->add_guild_exp(low_new_xp);
    targ->save_me();
    IP(targ)->update_implants();
    return;
    }
  if (new_lev > current_lev) {
    TE(targ, "You have been enhanced to quality "+new_lev+".\n");
    write_file(log+"ENHANCE", RN+" promoted "+targ->query_real_name()+
                              " from quality "+current_lev+" to "+
                              new_lev+". ("+ctime()+")\n");
    IP(targ)->set_rank(new_lev);
    targ->add_guild_rank(new_lev - current_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    IP(targ)->save_me();
    targ->add_guild_exp(-targ->query_guild_exp());
    targ->add_guild_exp(low_new_xp);
    targ->save_me();
    IP(targ)->update_implants();
    return;}
  if(new_lev < current_lev) {
    TE(targ, "You have been demoted to a quality of "+new_lev+"\n");
    write_file(log+"ENHANCE", RN+" demoted "+targ->query_real_name()+
                              " from quality "+current_lev+" to "+
                              new_lev+". ("+ctime()+")\n");
    IP(targ)->set_rank(new_lev);
    targ->add_guild_rank(new_lev - current_lev);
    low_new_xp = low_exp(new_lev);
    IP(targ)->set_xp(low_new_xp);
    IP(targ)->save_me();
    IP(targ)->update_implants();
    targ->add_guild_exp(-targ->query_guild_exp());
    targ->add_guild_exp(low_new_xp);
    targ->save_me();
    return;}
}

addxp(string str) {
/* Used for guild xp promotion/demotion/setting */
  int amount;
  string who;
  object whoob;
  if(!str) {
    write("Usage: addxp <member> <amount>.\n");
    return;}
  if(!sscanf(str, "%s %d", who, amount)) {
    write("Usage: addxp <member> <amount>.\n");
    return;}
  if(!IP(find_player(who))) {
    write("User "+capitalize(who)+" is not valid.\n");
    return;}
  whoob = find_player(who);
  IP(whoob)->add_xp(amount);
  whoob->add_guild_exp(amount);
  whoob->save_me();
  IP(whoob)->save_me();
  if(amount >= 0)
    write("You alter "+capitalize(who)+"'s guild xp by +"
      +amount+".\n");
  else write("You alter "+capitalize(who)+"'s guild xp by "
      +amount+".\n");
  write_file(log+"ADDXP", RN+" altered "+whoob->query_real_name()+
                          "'s guild xp by "+amount+". ("+ctime()+")\n");
}


int low_exp(int level) {
/* Returns the base xp for the level specified */
  int xp;
  switch(level) {
    case 0:     xp = 0;         break;
    case 1:     xp = 5000;       break;
    case 2:     xp = 20000;      break;
    case 3:     xp = 50000;     break;
    case 4:     xp = 90000;    break;
    case 5:     xp = 140000;    break;
    case 6:     xp = 230000;    break;
    case 7:     xp = 330000;    break;
    case 8:     xp = 450000;    break;
    case 9:     xp = 600000;    break;
    case 10:    xp = 800000;    break;
    }
  if(level > 10) xp = 800000;
  return xp;
}

int xp_list(int xp) {
/* Returns guild level for xp specified */
  if(xp <  5000)    { return 0;  }
  if(xp <  20000)   { return 1;  }
  if(xp <  50000)   { return 2;  }
  if(xp <  90000)  { return 3;  }
  if(xp <  140000)  { return 4;  }
  if(xp <  230000)  { return 5;  }
  if(xp <  330000)  { return 6;  }
  if(xp <  450000) { return 7;  }
  if(xp <  600000) { return 8;  }
  if(xp <  800000) { return 9;  }
  if(xp >= 800000) { return 10; }
  return 0;
}

string guild_title(int level) {
/* Returns guild title for guild level specified */
  string title;
  switch(level) {
    case 100:title = "the __Emperor__";           break;
    case 50: title = "the Grand Regent";          break;
    case 13: title = "the Daimyo";                break;
    case 12: title = "the Shogun";                break;
    case 11: title = "the CyberNinja WarLord";    break;
    case 10: title = "the CyberNinja WarLord";    break;
    case 9:  title = "the Elder CyberNinja";      break;
    case 8:  title = "the Master CyberNinja";     break;
    case 7:  title = "the Adept CyberNinja";      break;
    case 6:  title = "the CyberNinja";            break;
    case 5:  title = "the CyberKnight";           break;
    case 4:  title = "the CyberWarrior";          break;
    case 3:  title = "the CyberBlade";            break;
    case 2:  title = "the CyberPunk";             break;
    case 1:  title = "the CyberPuke";             break;
    case 0:  title = "the NetRunner";             break;
    }
  if ((level > 13) && (level != 50) && (level != 100))
    title = "the Defective";
  return title;
}

set_guild_title() {
/* Changes the member's guild title */
  string new_title;
  if(IP(TP)) {
    new_title = guild_title(IP(TP)->guild_lev());
    if(new_title == "defective") {
       write("There is no title for your quality level.\n");
       write("Please have your quality level changed.\n");
       return; }
    TP->set_title(new_title);
    write("Your title is now "+new_title+".\n");
    TP->save_character();
    return;}
}

help_levels() {
/* Shows xp and title for each guild level */
  int i;
  write("List of levels and experience for CyberNinja guild\n");
  write("________________________ ____________ ______ ____ ___ __\n");
  write(" LEVEL       XP          TITLE                     COST\n");
  write("________________________ ____________ ______ ____ ___ __\n");
  for(i = 0; i <= 10; i++) {
    write(pad("Level "+i, 12));
    write(pad(low_exp(i), 10));
    write("  ");
    write(pad(guild_title(i), 27));
    write(pad(call_other(
              "/players/snow/closed/cyber/rooms/meditation.c", 
              "cost_to_advance", i), 10));
    write("\n");
    }
  write("________________________ ____________ ______ ____ ___ __\n");
}

rank_info() {
/* Simple sc command for a member, showing guild info */
  int level, degree;
  string art;
  degree = IP(TP)->query_degree();
  level = IP(TP)->query_art_level();
  art = IP(TP)->query_art();
  write(TPN+"'s CyberNinja guild info......\n");
  write("(O )( O)(O )( O)(O )( O)(O )( O)(O )( O)(O )( O)\n");
  if(RN == EMP1 || RN == EMP2) write("You are the EMPEROR.\n");
  if(IP(TP)->regent()) write("You hold the title of Grand Regent.\n");
  if(IP(TP)->shogun()) write("You hold the title of Shogun.\n");
  if(IP(TP)->minister())  write("You hold the title of Minister.\n");
  if(IP(TP)->sensei()) write("You hold the title of Sensei.\n");
  if(IP(TP)->head_referee()) write("You hold the title of Head Referee.\n");
  if(IP(TP)->referee()) write("You hold the title of Referee.\n");
  write("Quality Level: "+IP(TP)->guild_lev()+"\n");
  write("Guild Xp: "+IP(TP)->guild_exp()+"\n");
  write("Ninjitsu Discipline: "+art+"\n");
  write("Belt: "+belt_color(level, art)+"");
  if(degree > 0) write(", degree "+degree+"\n");
  else write("\n");
  write("Choice of Weapon: "+IP(TP)->query_weapon()+"\n");
  write("Credit Balance: "+IP(TP)->balance()+"\n");
  write("( O)(O )( O)(O )( O)(O )( O)(O )( O)(O )( O)(O )\n");
}
 
other_rank_info(string str) {
/* To find another person's guild info */
  int level, degree;
  string art;
  object ob;
  if(!find_player(str)) {
    write(capitalize(str)+" is not on now or does not exist.\n");
    return; }
  ob = find_player(str);
    if(ob->query_invis()) {
    write(capitalize(str)+" is not on or does not exist.\n");
    return 1;}
  if(!IP(ob)) {
    write(capitalize(str)+" is not a guild member.\n");
    return; }
  degree = IP(ob)->query_degree();
  level = IP(ob)->query_art_level();
  art = IP(ob)->query_art();
  TE(TP,OPN+"'s CyberNinja guild info......\n");
  TE(TP,"(* )( *)(* )( *)(* )( *)(* )( *)(* )( *)(* )( *)\n");
  if(ORN == EMP1 || RN == EMP2) TE(TP,"You are the EMPEROR.\n");
  if(IP(ob)->regent()) TE(TP,"You hold the title of Grand Regent.\n");
  if(IP(ob)->shogun()) TE(TP,"You hold the title of Shogun.\n");
  if(IP(ob)->minister())  write("You hold the title of Minister.\n");
  if(IP(ob)->sensei()) TE(TP,"You hold the title of Sensei.\n");
  if(IP(ob)->head_referee()) TE(TP,"You hold the title of Head Referee.\n");
  if(IP(ob)->referee()) TE(TP,"You hold the title of Referee.\n");
  TE(TP,"Quality Level: "+IP(ob)->guild_lev()+"\n");
  TE(TP,"Guild Xp: "+IP(ob)->guild_exp()+"\n");
  TE(TP,"Ninjitsu Discipline: "+art+"\n");
  TE(TP,"Belt: "+belt_color(level, art)+"");
  if(degree > 0) TE(TP,", degree "+degree+"\n");
  else TE(TP,"\n");
  TE(TP,"Choice of Weapon: "+IP(ob)->query_weapon()+"\n");
  TE(TP,"Credit Balance: "+IP(ob)->balance()+"\n");
  TE(TP,"( *)(* )( *)(* )( *)(* )( *)(* )( *)(* )( *)(* )\n");
}

net_channel_emote(str) {
/* Guild channel emote */
   int i;
   object people, memb;
   if(!str) {
      write("Usage nem <emote>.\n");
      return 1;}
   people = users();
   for(i = 0; i<sizeof(people); i++) {
      memb=IP(people[i]);
      if(memb && memb->muffled() < 1) {
         tell_object(people[i],"\n"+
           RED+"(CYBER)"+OFF+" "+TPN+" "+str+"\n");
       }
   }
   return 1;
}

net_muffle_channel(str) {
/* Guild channel muffle */
  int muff;
  muff = IP(TP)->muffled();
   if(!str) {
      write("Useage: line <on/off>\n");
      return;
   }
  if(str == "off") {
      if(muff == 1) {
         write("You already are muffled.\n");
         return;}
      else
         muff = 1;
      write("You are now muffled.\n");
      IP(TP)->set_muffle(muff);
      return;
   }
   if(str == "on") {
      if(muff == 0) {
         write(" You were not muffled.\n");
         return;
         }
      else muff = 0;
      write("You are now on the CyberNet.\n");
      IP(TP)->set_muffle(muff);
      return;
      }
}

net_who()  {
int b,glev,artlev,deg;
string type,art;
object ob;
ob = users();

write("\n");
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
  write("Ninja          Quality    Discipline     Belt     Line      Rank\n");
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");

for(b=0;b<sizeof(ob);b+=1)  {
  if(!ob[b]->query_invis()) {
  if(present("CyberNinja Implants",ob[b]))  {
   glev = IP(ob[b])->guild_lev();
   art = IP(ob[b])->query_art();
   artlev = IP(ob[b])->query_art_level();
   deg = IP(ob[b])->query_degree();
   write("  ");
   write(pad(CAP(ob[b]->query_name()),15));
   write(pad(IP(ob[b])->guild_lev(),6));
   write("  ");
   if(art)
   write(pad(art, 14));
   else write(pad("none",14));
   write("  ");
   if(deg > 0)
    write(pad(belt_color(artlev,art)+" "+deg,10));
   else write(pad(belt_color(artlev,art),10));
   if(IP(ob[b])->muffled() > 0) {write(pad("Off",6));}
   else write(pad("On",6));
   type = guild_title(glev);
   if(IP(ob[b])->referee()) type = "Referee";
   if(IP(ob[b])->head_referee()) type = "Head Referee";
   if(IP(ob[b])->sensei()) type = "Sensei";
   if(IP(ob[b])->minister()) type = "Minister";
   if(IP(ob[b])->shogun()) type = "Shogun";
   if(IP(ob[b])->daimyo()) type = "Daimyo";
   if(IP(ob[b])->regent()) type = "Regent";
   if(ob[b]->query_real_name() == EMP1) type = "Emperor";
   if(ob[b]->query_real_name() == EMP2) type = "Emperor";
   write(pad(type,22));
   write("\n");
   }
  }
 }
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
       "~~~~~~~~~~~~~~~\n\n");
return 1;
}

n_con() {
  int hps, sps;
  string name, loc;
  int b;
  object ob;
  ob = users();
  write("\n");
  write("<>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~<>\n"+
  " Ninja           HP    SP     Location\n"+
  "<>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~<>\n");
  for(b=0;b<sizeof(ob);b+=1) {
  if(!ob[b]->query_invis()) {
      if(present("either implants",ob[b])) {
  name = ob[b]->query_name();
  loc = environment(ob[b])->short();
  hps = (ob[b]->query_hp() * 100) / ob[b]->query_mhp();
  sps = (ob[b]->query_sp() * 100) / ob[b]->query_msp();
  write(" "+
    pad(name,15)+" "+pad(hps+"%",5)+" "+pad(sps+"%",7)+" "+loc+"\n");
      }
    }
  }
  write("<>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~<>\n");
  return 1;
}

up_who()  { /*A high-rank who that shows pk stuff with color*/
int b, level, pk, xlev;
string gname, room;
object * ob;
ob = users();
 
write("\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
write("Player          Level    Guild         Location\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
 
 for(b=0;b<sizeof(ob);b+=1)  {
   if(!ob[b]->query_invis()) {
     level = ob[b]->query_level();
     xlev = ob[b]->query_extra_level();
     gname = ob[b]->query_guild_name();
     pk = ob[b]->query_pl_k();
     if(environment(ob[b]))
     room = environment(ob[b])->short();
     else room = "unknown";
       if(level >= 12 && level < 20) {
         if(pk) write(RED+pad(CAP(ob[b]->query_name()),15)+OFF);
           else write(pad(CAP(ob[b]->query_name()),15));
          write(" ");
         if(!xlev) write(pad(level,6));
           else write(pad(level+"+"+xlev,6));
         write(" ");
         if(gname) {
           if(gname == "cyberninja")     
             write(BOLD+pad("CyberNinja",15)+OFF);
             else write(pad(gname, 15)); }
           else write(pad("none", 15));
         write(" ");
         if(ob[b]->query_fight_area() == file_name(ENV(ob[b])))
           write(RED+"->"+OFF+room);
           else write(room);
         write("\n");
       }
   }
 }
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
       "~~~~~~~~~~~~~~~\n\n");
return 1;
}

trans_to(string str) { /*Transport to other ninja*/
  object here, there, ninto;
  string wheree;
  string here_realm, there_realm;
  here = environment(this_player());
  here_realm = here->realm();
  if(!str) { write("Usage: transto <ninja>\n"); return; }
  ninto = find_player(str);
  if(!ninto) { write("<~>"+CAP(str)+" cannot be found.\n");
               return; }
  if(ninto->query_guild_name() != "cyberninja") {
    write(CAP(str)+" is not a CyberNinja.\n"); return; }
  if(ninto->query_level() > 19) {
    write("<~>"+CAP(str)+" cannot be found.\n"); RE; }
  there = ENV(ninto);
  there_realm = there->realm();
  if(TP->query_spell_point() < 200) {
    write("You cannot trans yourself, you are too low on power.\n");
    return; }
  if(here_realm == "NT") {
    write("You cannot trans from your location.\n");
    return; }
  if(there_realm == "NT") {
    write("You cannot trans to that location.\n");
    return; }
 
  if(wheree = call_other("obj/base_tele","teleport")) {
      this_player()->move_player("with an astonished look#"+wheree); }
  else {
  say(TPN+"s body vaporizes into nothing.\n");
  TR(there, TPN+" transfers in.\n");
  move_object(this_player(), there);
  write("Your body disintegrates into invisible matter particles.\n");
  write("You trans yourself to "+CAP(str)+"...\n\n");
  command("look",TP); }
  call_other(TP, "add_spell_point", -200);
  return 1;
}

hide_in_shadows() {
  /* command to hide in shadows */
  object ob;
  if(present("_drivers_seat_",
     environment(this_player()))) {
    write("You are already hiding in shadows.\n");
    return 1; }

  if(environment(this_player())->realm() == "NT") {
    write("The shadows magically resist your attempts to use them.\n");
    return 1; }

  if(this_player()->query_attack()) {
    if(this_player()->query_spell_point() < 75) {
      write("You feel too drained to attempt this.\n");
      return 1; }
    this_player()->add_spell_point(-75);
  } else {
   if(this_player()->query_spell_point() < 40+random(5)) {
    write("Your energies are too weak to hide in shadows.\n");
    return 1; }
   this_player()->add_spell_point(-40-random(5));
  }ob = clone_object(
       "/players/snow/closed/cyber/objects/hide.c");
  move_object(ob, environment(this_player()));
  if(!TP->query_invis()) {
    say(TP->query_name()+" disappears into the shadows.\n");
  }
  move_object(this_player(), ob);
  write("You hide in shadows.\n");
  write("For info, type 'look at shadows'.\n");
  return 1;
}

net_channel(str) {
/* Guild channel */
   object everyone, member;
   int i;
   if(!str) {
      write("Usage: net <message>.\n");
      return;}
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = IP(everyone[i]);
      if(member && member->muffled() < 1) {
        tell_object(everyone[i],
    RED+"CYBERNET~~~"+END+" "+BOLD+TPN+END+" "+RED+">>>"+END+" "+str+"\n");
        }
      }
   return 1;
}

overchannel(str) {
/* For announcements */
   object everyone, member;
   int i;
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = IP(everyone[i]);
      if(member && member->muffled() < 1) 
        tell_object(everyone[i],
                 BLINK+BOLD+"<<_CYBERNET_>>>"+OFF+OFF+" "+str+"\n");
      }
   return 1;
}

other_channel(str) {
/* For entering */
   object everyone, member;
   int i;
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = IP(everyone[i]);
      if(member && member->muffled() < 1)
        tell_object(everyone[i],
                 BLUE+"<<_LINKING_>>>"+OFF+" "+str+"\n");
      }
   return 1;
}

check_time() {
/* Command to find time on church clock */
  call_other("/room/church.c","long","clock");
  return;
}

execute(string str) {
  string file;
  int guild_xp, guild_rank, real_exp;
  object corpse, ob;
  if(!str) {
    write("Execute who?\n");
    write("Note: This is to be done in only drastic circumstances.\n");
    write("Use the 'suspend' command for lighter situations.\n");
    return; }
  if(!IP(find_player(str))) {
    write("User "+capitalize(str)+" is not valid.\n");
    return; }
  ob = find_player(str);
  guild_xp = IP(ob)->guild_exp();
  guild_rank = IP(ob)->guild_lev();
  real_exp = call_other(ob, "query_exp", 0);
  IP(ob)->set_xp(-guild_xp);
  IP(ob)->set_rank(-guild_rank);
  IP(ob)->set_guild_name(0);
  ob->set_guild_name(0);
  ob->add_guild_exp(-ob->query_guild_exp());
  ob->add_guild_rank(-ob->query_guild_rank());
  ob->set_title("the Dishonored CyberNinja");
  ob->set_guild_file(0);
  ob->set_home("room/church");
  file = "/players/snow/closed/cyber/ninjas/"+
         ((string)ob->query_real_name())+".o";
  if(file_size(file) >= 0) rm(file);
  TR(EO, OPN+"'s cyberlinks are disconnected.\n");
  TR(EO, OPN+"'s implants are removed, painfully.\n");
  TR(EO, OPN+" is forced to kneel upon a small platform.\n");
  TR(EO, "An attendant hands "+TPN+" a sharp long-bladed katana.\n");
  TR(EO, TPN+" wields the katana and raises it high in the air.\n");
  TR(EO, "With one quick swing "+OPN+"'s head flies off.\n");
  overchannel(OPN+
              " has been banished with great dishonor from the Ninjas.\n");
  write_file(log+"EXECUTE", capitalize(str)+" was executed by "+
                         RN+". ("+ctime()+"\n");
  IP(ob)->save_me();
  ob->save_me();
  ob->hit_player(100000);
  destruct(present("implants", ob));
}

unsuspend(string str) {
  object ob, imp;
  if(!str) {
    write("Unsuspend who?\n");
    return; }
  if(!IP(find_player(str))) {
    write("User "+capitalize(str)+" is not valid.\n");
    return; }
  ob = find_player(str);
  imp = clone_object("/players/snow/closed/cyber/implants.c");
  IP(ob)->set_suspended(0);
  move_object(imp, ob);
  IP(ob)->save_me();
  ob->set_guild_title();
  TE(ob, "You have been reestablished into the CyberNinjas.\n");
  write_file(log+"SUSPEND", 
    capitalize(str)+" was reestablished by "+RN+". ("+ctime()+")\n");
}

suspend(string str) {
  int guild_xp, guild_rank, real_exp;
  object corpse, ob;
  if(!str) {
    write("Suspend who?\n");
    return; }
  if(!IP(find_player(str))) {
    write("User "+capitalize(str)+" is not valid.\n");
    return; }
  ob = find_player(str);
  IP(ob)->set_suspended(1);
  ob->set_title("is suspended from the CyberNinjas");
  TE(ob, "You have been suspended from the CyberNinjas.\n");
  TE(ob, "Mail an Emperor or Regent if you have a problem with this.\n");
  write_file(log+"SUSPEND", 
    capitalize(str)+" was suspended by "+RN+". ("+ctime()+")\n");
  IP(ob)->save_me();
  destruct(IP(ob));
}

recruit_member(string who) {
/* Way to recruit new guild members */
  object ob;
  if(!who) {
    write("Usage: recruit <who>\n");
    return;}
  if(!find_player(who)) {
    write("User "+WHO+" not found.\n");
    return;}
  ob = find_player(who);
  if(present("way of the cyberninja", ob)) {
    TE(TP, OPN+" is already recruited in the CyberNinjas.\n");
    return; }
  if(already_in_a_guild(ob)) {
     TE(TP,OPN+
       " is a member of another guild.\n");
     return;}
  if(ob->query_level() < 6) {
     TE(TP,OPN+
       " is not level six yet.\n");
     return;}
  else {
    write_file(log+"RECRUIT", RN+" recruited "+WHO+" ("+ctime()+")\n");
    write("You have shown "+WHO+" the Way of the CyberNinja.\n");
    TR(EO, TPN+" has shown "+WHO+" the Way of the CyberNinja.\n");
    move_object(clone_object("/players/snow/closed/cyber/recruitob.c"),
                ob);
    TE(ob, "You have been shown the Way of the CyberNinja.\n"+
           "Learn it, and you will soon be along the path\n"+
           "to greater destiny.\n");
    return; }
}

int already_in_a_guild(object ob) {
/* Checks if player is in another guild */
  if((ob->query_guild_name() != 0) ||
     (ob->query_guild_exp() != 0)  ||
     (ob->query_guild_file() != 0) ||
     (ob->query_guild_rank() != 0)) {
       return 1;}
  return 0;
}

listEnhancements(string str) {
/* shows all enhancements the person has */
object ob;
if(!str) {
  write("Your enhancements are....\n");
  showItemfunc(TP, TP);
  return; }
if(!find_player(str)) {
  write("No such player.\n");
  return; }
ob = find_player(str);
if(!IP(ob)) {
  write(OPN+" is not a CyberNinja.\n");
  return; }
  if(IP(TP)->shogun() 	||
       RN == EMP1 || RN == EMP2) {
  write(OPN+"'s enhancements are....\n");
  showItemfunc(ob, TP);
  return; }
}

show_use() { /* Shows enhancements in use */
  write("\n");
  write("    ENHANCEMENTS IN USE   \n");
  write("\n");
  if(IP(TP)->query_blad_on()) write(RED+"  Blades"+OFF+"\n");
  if(IP(TP)->query_bion_on()) write(RED+"  Bionics"+OFF+"\n");
  if(IP(TP)->query_armor_on()) write(BROWN+"  SubDermal Armor"+OFF+"\n");
  if(IP(TP)->query_regen()) write(BLUE+"  Regeneration"+OFF+"\n");
  if(IP(TP)->query_rejuv()) write(BLUE+"  Rejuvenation"+OFF+"\n");
  if(IP(TP)->query_convert_on()) write(GREEN+"  Conversion"+OFF+"\n");
  if(IP(TP)->query_equil()) write(GREEN+"  Equilibration"+OFF+"\n");
  if(IP(TP)->query_digest()) write(BOLD+"  Digestion"+OFF+"\n");
  if(IP(TP)->query_light_on()) write(YELLOW+"  Biolight"+OFF+"\n");
  write("\n");
  return 1;
}

showItemfunc(object ob, object me) {
/* ob stores the member of interest, me stores the checker */
write("______________________________\n");
if(IP(ob)->item_eyes()) TE(me, "cybereyes\n");
if(IP(ob)->item_corpse()) TE(me, "organic converter\n");
if(IP(ob)->item_activate_droid()) TE(me, "droid\n");
if(IP(ob)->item_stun()) TE(me, "stun ray\n");
if(IP(ob)->item_bionics()) TE(me, "bionics\n");
if(IP(ob)->item_blades()) TE(me, "blades\n");
if(IP(ob)->item_electricflux()) TE(me, "electric flux\n");
if(IP(ob)->item_magneticflux()) TE(me, "magnetic flux\n");
if(IP(ob)->item_heatflux()) TE(me, "heat flux\n");
if(IP(ob)->item_flash()) TE(me, "biolight\n");
if(IP(ob)->item_emt()) TE(me, "emotion controller\n");
if(IP(ob)->item_legs()) TE(me, "leg actuators\n");
if(IP(ob)->item_convert()) TE(me, "matter converter\n");
if(IP(ob)->item_weplink()) TE(me, "smartweapon link ["+
  IP(ob)->item_weplink()+"]\n");
write("______________________________\n");
}

coinsTocredits(string str) {
int num, bal, total;
 if(!str) {
   write("Usage: creditcoins or cc <amount>\n");
   return; }
 if(!sscanf(str, "%d", num)) {
   write("Usage: creditcoins or cc <amount>\n");
   return; }
 if(num < 0) {
   write("You cannot change credits back to coins.\n");
   return;}
 if(num == 0) {
   write("To change coins to credits, enter an amount > 0\n");
   return;}
 if(TP->query_money() < num) {
   write("You do not have that much coins.\n");
   return;}
 bal = IP(TP)->balance();
 total = bal + num;
 if(total >= 200000) {
   total = 200000 - bal;
   write("The maximum credit limit is 200000 @'s.\n");
   write("You can change only "+total+" more coins into @'s.\n");
   return; }
 TP->add_money(-num);
 IP(TP)->addToBalance(num);
 write("You change "+num+" coins to credits.\n");
 IP(TP)->save_me();
return;
}

query_balance() {
   write("Your credit balance is: "+
   IP(TP)->balance()+" @'s\n");
}

guild_balance() {
   object everyone, member;
   int i, bal;
   everyone = users();
        write("Guild balances...........................\n");
   for(i = 0; i < sizeof(everyone); i++) {
    if(!everyone[i]->query_invis()) {
      if(IP(everyone[i])) {
        member = IP(everyone[i]);
        bal = member->balance();
        write(pad(CAP(everyone[i]->query_name()), 20));
        write(bal+" @'s\n");
      }
    }
   }
}

advance_art(string str) {
   object ob;
   object mem;
   int artlevel, newlevel, level, xp,
       lowxp, reqxp, freexp, temp, degree;
   string art;
   if(!str) {
      write("Usage: train <who>\n");
      return;}
   if(!IP(present(str, environment(this_player())))) {
      write("There is no member named "+capitalize(str)+" here.\n");
      return;}
   ob = find_player(str);
   art = "Ninjitsu";
   mem = present("CyberNinja Implants", ob);
   artlevel = mem->query_art_level();
   newlevel = artlevel + 1;
   if(newlevel >= 17) {
     write(str+" cannot advance further in Ninjitsu.\n");
     TE(ob, "You are already Grandmaster of Ninjitsu.\n");
     return; }
   level = mem->guild_lev();
   if(level == 0) {
     write(str+" is too low of quality to train in any disciplines.\n");
     TE(ob, "You try to train but fail.\n");
     return; }
   if((artlevel >= 4) && (level < 3)) {
     write(str+" is too low of quality to train in any disciplines.\n");
     TE(ob, "You try to train but fail.\n");
     return; }
   if((artlevel >= 6) && (level < 6)) {
     write(str+" is too low of quality to train in any disciplines.\n");
     TE(ob, "You try to train but fail.\n");
     return; }
   xp = mem->guild_exp();
   lowxp = low_exp(level);
   if(newlevel <= 7) reqxp = art_exp(newlevel);
   else reqxp = 200000; /* 200k xp to advance in black belt degrees */
   freexp = xp - lowxp;
   degree = newlevel - 6;
   if(degree > 0) mem->set_degree(degree);
   if(freexp >= reqxp) {
     if(artlevel == 0) {
       mem->set_art(art);
       TE(ob, "You are introduced to the discipline of "+art+".\n");
       TR(EO, TPN+" introduces "+str+" to the discipline of "+art+".\n");
       TR(EO, str+" is now a white belt in "+art+".\n");
      TE(ob, "A white belt is given to you.\n");
       write("You introduce "+str+" to the discipline of "+art+".\n");
       write(str+" begins as a white belt.\n");
       }
     if((newlevel < 7) && (newlevel > 1)) {
TE(ob, "You advance in the discipline of Ninjitsu!\n");
    TR(EO, TPN+" trains "+str+" in the discipline of Ninjitsu\n");
    TR(EO, str+" is now a "+belt_color(newlevel,art)+" in Ninjitsu.\n");
       write(str+" advances in the discipline of "+art+".\n");
       write("You remove "+str+"'s "+belt_color(artlevel,art)+
             " belt and replace it with a "+belt_color(newlevel,art)+
             " belt.\n");
       TE(ob, "You take off your "+belt_color(artlevel,art)+
             " belt and put on a "+belt_color(newlevel,art)+" belt.\n");
          }
     if(newlevel >= 7) {
       TE(ob, "You advance to a black belt of degree "+degree+".\n");
       write("You place a shiny red mark on "+str+"'s black belt.\n");
       TR(EO, str+" advances to a black belt of degree "+degree+".\n");
       TR(EO, TPN+" places a shiny red mark on "+str+"'s black belt.\n");
       TE(ob, "Shiny red markings are added to your black belt.\n");
       }
     if((belt_color(newlevel,art) == "black") && (newlevel == 10)) {
       TE(ob, "You have mastered the discipline of "+art+"!\n");
       TR(EO, str+" has just mastered the discipline of "+art+".\n");
       write_file("/players/snow/closed/cyber/docs/masters",
                  OPN+", Master of "+capitalize(art)+". ("+ctime()+")\n");
       overchannel(ob->query_real_name()+
                   " has mastered the discipline of "+art+"!\n");
       }
     if((belt_color(newlevel,art) == "black") && (newlevel == 16)) {
       TE(ob, "You have achieved Grandmaster status in the\n"+
              "the discipline of "+art+"!\n");
       TR(EO, str+" has become Grandmaster of "+capitalize(art)+".\n");
       write_file("/players/snow/closed/cyber/docs/grandmasters",
                  OPN+", Grandmaster of "+capitalize(art)+". ("+ctime()+")\n");
       overchannel(OPN+
                   " has become Grandmaster of "+art+"!\n");
       empower(ob->query_real_name()+" sensei yes");
       }
     temp = newlevel - 6;
     if(temp == 10) {
       write("You have achieved the status of Sensei!\n");
       }
     mem->set_art_level(newlevel);
     mem->add_xp(-reqxp);
     if(degree > 0) mem->set_degree(degree);
     write_file(log+"TRAIN", TPN+" trained "+str+" to level "+newlevel+
       " in "+capitalize(art)+". ("+ctime()+")\n");
     mem->save_me();
     mem->update_implants();
     return;}
   if(freexp < reqxp) {
     temp = reqxp - freexp;
     write(str+" does not have enough free guild experience.\n");
     TE(ob, "You do not have enough free guild experience.\n");
     TE(ob, "You need "+temp+
           " more experience points to learn "+art+".\n");
     return;}
}


int art_exp(int level) {
 int xp;
 switch(level) {
   case 1:    xp = 5000; break;
   case 2:    xp = 15000; break;
   case 3:    xp = 30000; break;
   case 4:    xp = 60000; break;
   case 5:    xp = 100000; break;
   case 6:    xp = 200000; break;
   case 7:    xp = 400000; break;
   }
 return xp;
}

help_belt_levels() {
  /* Gives cost of experience for each belt level */
  int i;
  TE(TP, "Belt          Experience\n");
  TE(TP,"============================================\n");
  for(i = 1; i <= 7; i++) {
    write(pad(
    capitalize((string)belt_color(i,0))
    +"          ", 15));
    write(art_exp(i)+"\n");
    }
  TE(TP,"... 200000 for each black belt degree\n");
  TE(TP,"============================================\n");
  return 1;
}

string belt_color(int level) {
 string belt;
 if(level >= 7) level = 7;
 switch(level) {
     case 0:   belt = "none"; break;
     case 1:   belt = "white"; break;
     case 2:   belt = "purple"; break;
     case 3:   belt = "blue"; break;
     case 4:   belt = "green"; break;
     case 5:   belt = "brown"; break;
     case 6:   belt = "red"; break;
     case 7:   belt = "black"; break;
     }
 return belt;
}

report(string str) {
  if(!str) {
    write("What do you wish to report?\n");
    write("Remember to include the name of the tournament.\n");
    return 1; }
  write_file("/players/dune/closed/guild/tournaments/reports",
     RN+" reports: "+str+"  ("+ctime()+")\n");
  write("You file your report.\n");
  return 1;
}

tourney() {
   write("Looking up tournament info...\n");
   call_other("/players/snow/closed/cyber/_more.c",
              "more_file", 
              "/players/dune/closed/guild/tournaments/reports");
   return 1;
}

refassist(string who) {
  object ob;
  if(!who) {
    write("Who do you want to make referee?\n");
    return 1; }
  if(!present(who, environment(TP))) {
    write(capitalize(who)+" is not here.\n");
    return 1; }
  if(!find_player(who)) {
    write("You can only make players referees.\n");
    return 1; }
  ob = find_player(who);
  if(IP(ob)->referee()) {
    write(capitalize(who)+" is already a referee.\n");
    return 1; }
  IP(ob)->set_referee(1);
   IP(ob)->save_me();
   IP(ob)->update_implants();
  tell_object(ob, TPN+" has made you referee.\n");
  write("You make "+OPN+" a referee.\n");
  overchannel(OPN+" has become referee.\n");
  write_file(log+"REFEREE", RN+" made "+ob->query_real_name()+
    " a referee. ("+ctime()+")\n");
  return 1;
}

unref(string who) {
  object ob;
  if(!who) {
    write("Who do you want to fire?\n");
    return 1; }
  if(!present(who, environment(TP))) {
    write(capitalize(who)+" is not here.\n");
    return 1; }
  if(!find_player(who)) {
    write(capitalize(who)+" is not a player.\n");
    return 1; }
  ob = find_player(who);
  if(!IP(ob)->referee()) {
    write(capitalize(who)+" is not a referee in the first place.\n");
    return 1; }
  IP(ob)->set_referee(0);
  IP(ob)->save_me();
  IP(ob)->update_implants();
  tell_object(ob, TPN+" has fired you from the referee position.\n");
  write("You fire "+OPN+" from the referee position.\n");
  overchannel("Referee "+OPN+" has been fired by "+TPN+".\n");
  write_file(log+"REFEREE", 
    RN+" fired referee "+ob->query_real_name()+". ("+ctime()+")\n");
  return 1;
}

all_file_watcher(string str) {
  string file;
  if(!str) {
    write("You may access the following data logs.\n");
   ls("/players/snow/closed/cyber/log");
    return 1; }
  file = "/players/snow/closed/cyber/log/"+str;
  if(file_size(file) >= 0) {
    write("You access the "+str+" data log.\n");
    call_other("/players/snow/closed/cyber/_more.c",
               "more_file", file);
    return 1; }
  write("There is no "+str+" data log.\n");
  return 1; }

end_file_watcher(string str) {
  string file;
  if(!str) {
    write("You may access the following data logs.\n");
    ls("/players/snow/closed/cyber/log");
    return 1; }
   file = "/players/snow/closed/cyber/log/"+str;
  if(file_size(file) >= 0) {
    write("You access the "+str+" data log.\n");
    tail(file);
    return 1; }
  write("There is no "+str+" data log.\n");
  return 1; }

match(string str) { /* counts kills for pk fights */
  object ob;
  int mylevel, targlevel, combatlevel;
  mylevel = this_player()->query_level();
  if(!str) {
    write("Who do you want to challenge?\n");
    return 1; }
  if(!present(str, environment(this_player()))) {
    write(capitalize(str)+" is not here.\n");
    return 1; }
  if(present("deathmatch_object", TP)) {
    write("You are already involved in a deathmatch.\n");
    return 1; }
  if(!find_player(str)) {
    write("You can only challenge other players.\n");
    return 1; }
  ob = find_player(str);
  if(ob == this_player()) {
    write("You cannot challenge yourself to a death match.\n");
    return 1; }
  targlevel = ob->query_level();
  combatlevel = mylevel - targlevel;
  if(combatlevel >= 5) {
    write("Your little death match is deemed unworthy.\n");
    return 1; }
  if(ob->query_ghost()) {
    write("You cannot challenge a ghost!\n");
    return 1; }
  if(!ob->query_pl_k()) {
    write("You can only attack other player killers.\n");
    return 1; }
  if(!this_player()->query_pl_k()) {
    write("You are not a player killer!\n");
    write("Type 'kill_players' to set your pk flag.\n");
    return 1; }
  write("You have challenged "+capitalize(str)+
        " to a match of death.\n");
  tell_object(ob, "You have been challenged by "+
                  TPN+" to a match of death.\n");
  move_object(clone_object("/players/dune/closed/guild/deathmatches/deathob.c"),
    TP);
  call_out("observe_match", 1, RN+" "+str);
  return 1;
}

observe_match(string str) {
  object targ, ob;
  string mename, targname, name;
  sscanf(str, "%s %s", mename, targname);
  mename = lower_case(mename);
  targname = lower_case(targname);
  ob = find_player(mename);
  targ = find_player(targname);
  name = targ->query_name();
  name = capitalize(name);
  if(!present(targ, environment(ob))) {
    tell_object(ob, "The death match is terminated.\n");
    if(present("deathmatch_object", ob)) 
      destruct(present("deathmatch_object", ob));
    return 1; }
  if(targ->query_ghost()) {
    overchannel(OPN+" has defeated "+capitalize(targ->query_real_name())
    +" in a death match!\n");
    IP(ob)->add_kills(1);
    IP(ob)->save_me();
    IP(ob)->get_deathmatch_permission(1);
    command("log_my_deathmatch "+mename+" "+targname, ob);
    tell_object(ob, "You have received one kill.\n");
    tell_object(ob, "You now have "+IP(ob)->query_kills()+" kills.\n");
    if(present("deathmatch_object", ob))
      destruct(present("deathmatch_object", ob));
    return 1; }
  call_out("observe_match", 1, mename+" "+targname);
  return 1;
}

log_my_deathmatch(string jumble) {
  object winner, loser;
  string mename, targname;
  if(!IP(TP)->query_deathmatch_permission()) return 0;
  sscanf(jumble, "%s %s", mename, targname);
  winner = find_player(mename);
  loser  = find_player(targname);
  write_file("/players/dune/closed/guild/deathmatches/"+
    winner->query_real_name(), capitalize(winner->query_name())+
    " (level "+winner->query_level()+
    ") killed "+loser->query_real_name()+
    " (level "+loser->query_level()+") on "+ctime()+".\n");
  IP(TP)->get_deathmatch_permission(0);
  return 1;
}

deaths(string str) {
  string file, namme;
  object everyone;
  int i, kills;
  if(!str) {
    file = "/players/dune/closed/guild/deathmatches/"+RN+"";
  if ((file_size(file) >= 0) && (file_size(file) < 1000)) {
    write("Your death match record....\n");
    cat(file);
    return 1; }
  if (file_size(file) >= 1000) {
    write("Your death match record....\n");
    call_other("/players/dune/closed/guild/_more.c","more_file",file);
    return 1; }
    write("You have no death match record.\n");
    return 1; }
  if(str == "list") {
    everyone = users();
    write("~~~~~~~~~~~~~~~~~Death Match Kills~~~~~~~~~~~~~~~~~\n");
    write("Name              Kills          Title\n");
    write("___________________________________________________\n");
    for(i = 0; i < sizeof(everyone); i++) {
      if(IP(everyone[i])) {
        kills = IP(everyone[i])->query_kills();
        namme = everyone[i]->query_name();
        write(pad(CAP(namme), 20));
        write(pad(kills, 10));
        if(kills <= 0) write("Commoner\n");
        if(kills >= 1 && kills <= 4) write("Initiate Assassin\n");
        if(kills >= 5 && kills <= 10) write("Assassin\n");
        if(kills >= 11 && kills <= 20) write("Expert Assassin\n");
        if(kills >= 21 && kills <= 40) write("Senior Assassin\n");
        if(kills >= 41 && kills <= 60) write("Elder Assassin\n");
        if(kills >= 61 && kills <= 99) write("Master of Assassins\n");
        if(kills >= 100) write("Grandfather of Assassins\n");
        }
      }
     write("___________________________________________________\n");
     return 1; }
  file = "/players/dune/closed/guild/deathmatches/"+str+"";
  if ((file_size(file) >= 0) && (file_size(file) < 1000)) {
    write(capitalize(str)+"'s death match record....\n");
    cat(file);
    return 1; }
  if (file_size(file) >= 1000) {
    write(capitalize(str)+"'s death match record....\n");
    call_other("/players/dune/closed/guild/_more.c","more_file",file);
    return 1; }
  write("No death match record on file for "+capitalize(str)+".\n");
  return 1;
}

empower (string str) {
   object ob;
   string who, type, flag;
   if(!str) {
    write("Usage: empower <who> [type] [yes/no]\n");
    write("Where type is: referee\n"+
          "               head_referee\n"+
          "               sensei\n"+
          "               minister\n"+
          "               shogun\n"+
          "               regent\n");
     return;}
   if(!sscanf(str, "%s %s %s", who, type, flag)) {
    write("Usage: empower <who> [type] [yes/no]\n");
    write("Where type is: referee\n"+    
          "               head_referee\n"+
          "               sensei\n"+
          "               minister\n"+
          "               shogun\n"+   
          "               regent\n");
     return;}
   if(!find_player(who)) {
     write("No such player.\n");
     return; }
   ob = find_player(who);
   if(!IP(ob)) {
     write(WHO+" is not a CyberNinja.\n");
     return; }
   if( (type == "sensei") ||
       (type == "minister") || 
       (type == "shogun") || 
       (type == "regent") ||
       (type == "head_referee") || 
       (type == "referee") ) {
     if((flag == "yes") || (flag == "no")) {

       if(type == "regent") {
         if(RN == EMP1 || RN == EMP2) {}
         else {
           write("Only an Emperor can empower Regents.\n");
           return; }
         if(flag == "yes") {
           if(IP(ob)->regent()) {
             write(WHO+" is already regent.\n");
             return;}
           else {
             write("You empower "+WHO+" with Regent abilities!\n");
             IP(ob)->set_regent(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has made you Regent!\n");
             overchannel(OPN+" has become the Regent!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Regent. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->regent()) {
             write(WHO+" is not Regent in the first place.\n");
             return;}
           else {
             write("You take away "+WHO+"'s Regent abilities.\n");
             IP(ob)->set_regent(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed your Regent abilities.\n");
             overchannel(OPN+" is no longer Regent.\n");
             write_file(log+"EMPOWER", RN+" removed "+ob->query_real_name()+
                          " from Regent. ("+ctime()+")\n");
         return;}
           }}

       if(type == "sensei") {
         if(flag == "yes") {
           if(IP(ob)->sensei()) {
             write(WHO+" is already Sensei.\n");
             return;}
           else {
             write(WHO+" is empowered with Sensei abilities.\n");
             IP(ob)->set_sensei(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, "You have become Sensei!\n");
             overchannel(OPN+" has become sensei!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Sensei. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->sensei()) {
             write(WHO+" is not Sensei in the first place.\n");
             return;}
           else {
             write("You take away "+WHO+"'s Sensei abilities.\n");
             IP(ob)->set_sensei(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed your Sensei abilities.\n");
             overchannel(OPN+" is no longer Sensei.\n");
             write_file(log+"EMPOWER", RN+" removed "+ob->query_real_name()+
                          " from Sensei. ("+ctime()+")\n");
             return;}
           }}
       if(type == "minister") {
         if(flag == "yes") {
           if(IP(ob)->minister()) {
             write(WHO+" is already a Minister.\n");
             return;}
           else {
             write("You empower "+WHO+" with Minister abilities.\n");
             IP(ob)->set_minister(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, "You have become Minister!\n");
             overchannel(OPN+" has become Minister!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Minister. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->minister()) {
             write(WHO+" is not Minister in the first place.\n");
             return;}
           else {
             write("You remove "+WHO+" from the Ministry.\n");
             IP(ob)->set_minister(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed you from the Ministry.\n");
             overchannel(TPN+" has removed "+OPN+" from the Ministry.\n");
             write_file(log+"EMPOWER", RN+" removed "+
                          ob->query_real_name()+
                          " from Minister. ("+ctime()+")\n");
             return;}
           }}

       if(type == "shogun") {
         if(RN == EMP1 || RN == EMP2 || IP(TP)->regent()) {}
         else {
           write("Only an Emperor or Regent can empower Shoguns.\n");
           return; }
         if(flag == "yes") {
           if(IP(ob)->shogun()) {
             write(WHO+" is already Shogun.\n");
             return;}
           else {
             write("You empower "+WHO+" with Shogun abilities.\n");
             IP(ob)->set_shogun(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has made you Shogun!\n");
             overchannel(OPN+" has become Shogun!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Shogun. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->shogun()) {
             write(WHO+" is not Shogun in the first place.\n");
             return;}
           else {
             write("You take away "+WHO+"'s Shogun abilities.\n");
             IP(ob)->set_shogun(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed your Shogun abilities.\n");
             overchannel(OPN+" is no longer Shogun.\n");
             write_file(log+"EMPOWER", RN+" removed "+ob->query_real_name()+
                          " from Shogun. ("+ctime()+")\n");
             return;}
           }}
       if(type == "referee") {
         if(flag == "yes") {
           if(IP(ob)->referee()) {
             write(WHO+" is already Referee.\n");
             return;}
           else {
             write("You empower "+WHO+" with Referee abilities.\n");
             IP(ob)->set_referee(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has made you Referee!\n");
             overchannel(OPN+" has become Referee!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Referee. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->referee()) {
             write(WHO+" is not Referee in the first place.\n");
             return;}
           else {
             write("You take away "+WHO+"'s Referee abilities.\n");
             IP(ob)->set_referee(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed your Referee abilities.\n");
             overchannel(OPN+" is no longer Referee.\n");
             write_file(log+"EMPOWER", RN+" removed "+ob->query_real_name()+
                          " from Referee. ("+ctime()+")\n");
             return;}
           }}
       if(type == "head_referee") {
         if(flag == "yes") {
           if(IP(ob)->head_referee()) {
             write(WHO+" is already Head Referee.\n");
             return;}
           else {
             write("You empower "+WHO+" with Head Referee abilities.\n");
             IP(ob)->set_head_referee(1);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has made you Head Referee!\n");
             overchannel(OPN+" has become head referee!\n");
             write_file(log+"EMPOWER", RN+" made "+ob->query_real_name()+
                          " a Head Referee. ("+ctime()+")\n");
             return;}
           }
         if(flag == "no") {
           if(!IP(ob)->head_referee()) {
             write(WHO+" is not Head Referee in the first place.\n");
             return;}
           else {
             write("You take away "+WHO+"'s Head Referee abilities.\n");
             IP(ob)->set_head_referee(0);
             IP(ob)->save_me();
             IP(ob)->update_implants();
             TE(ob, TPN+" has removed your Head Referee abilities.\n");
             overchannel(OPN+" is no longer Head Referee.\n");
             write_file(log+"EMPOWER", RN+" removed "+ob->query_real_name()+
                          " from Head Referee. ("+ctime()+")\n");
             return;}
           }}
     }
    write("Usage: empower <who> [type] [yes/no]\n");
    write("Where type is: referee\n"+
          "               head_referee\n"+
          "               sensei\n"+
          "               minister\n"+
          "               shogun\n"+
          "               regent\n");
    return;
   }
   write("Usage: empower <who> [type] [yes/no]\n");
   write("Where type is: referee\n"+
          "               head_referee\n"+
          "               sensei\n"+
          "               minister\n"+
          "               shogun\n"+
          "               regent\n");
   return;
}

show_attacks() {
  cat("/players/snow/closed/cyber/docs/attacks");
  return 1;
}

setArtLevel(string str) {
  object ob;
  string who, art, belt;
  int currentlevel, level, degreelevel;
  if(!str) { 
    write("Usage: set_art_level <player> <level>\n");
    return;}
  if(!sscanf(str, "%s %d", who, level)) {
    write("Usage: set_art_level <player> <level>\n");
    return;}
  if(!IP(find_player(who))) {
    write("Not a valid user.\n");
    return; }
  if(level < 0) {
    write("Not a valid level.\n");
    return;}
  ob = IP(find_player(who));
  currentlevel = ob->query_art_level();
  if(level == currentlevel) {
    write(WHO+" is already of discipline level "+level+".\n");
    return; }
   art = "Ninjitsu";
  belt = belt_color(level, art);
  if(level < 7) 
    TE(EO, "Your belt has been changed to "+belt+" by "+TPN+".\n");
  if(level >= 7) {
    degreelevel = level - 6;
    TE(EO, "Your black belt degree has been changed to "+
           degreelevel+".\n"); }
  if(degreelevel > 0) ob->set_degree(degreelevel);
  write_file(log+"ARTS",
    RN+" changed "+WHO+"'s discipline level from "+currentlevel+
    " to "+level+". ("+ctime()+")\n");
  ob->set_art_level(level);
  ob->save_me();
  ob->update_implants();
}

setWeapon(string str) {
  object ob;
  string who, weapon, currentweapon;
  if(!str) { 
    write("Usage: set_weapon <player> <weapon>\n");
    return;}
  if(!sscanf(str, "%s %s", who, weapon)) {
    write("Usage: set_weapon <player> <weapon>\n");
    return;}
  if(!IP(find_player(who))) {
    write("Not a valid user.\n");
    return; }
  if( !("/players/dune/closed/guild/rooms/weaponry.c"->
      isAweapon(weapon))) {    
    write("Not a valid weapon.\n");
    write("Weapon will be set anyway.\n");
    }
  ob = IP(find_player(who));
  currentweapon = ob->query_weapon();
  if(weapon == currentweapon) {
    write(WHO+" is already using that weapon.\n");
    return; }
  TE(EO, "Your weapon has been changed to "+weapon+" by "+TPN+".\n");
  write_file(log+"WEPS", 
    RN+" set "+WHO+"'s weapon from "+currentweapon+" to "+
    weapon+". ("+ctime()+")\n");
  ob->set_weapon(weapon);
  ob->save_me();
  ob->update_implants();
}

addCredits(string str) {
/* Used for guild credit promotion/demotion/fixing */
  int amount;
  string who;
  object whoob;
  if(!str) {
    write("Usage: add_credits <member> <amount>.\n");
    return;}
  if(!sscanf(str, "%s %d", who, amount)) {
    write("Usage: add_credits <member> <amount>.\n");
    return;}
  if(!IP(find_player(who))) {
    write("User "+capitalize(who)+" is not valid.\n");
    return;}
  whoob = find_player(who);
  IP(whoob)->addToBalance(amount);
  IP(whoob)->save_me();
  if(amount >= 0)
    write("You alter "+capitalize(who)+"'s guild credits by +"
      +amount+".\n");
  else write("You alter "+capitalize(who)+"'s guild credits by "
      +amount+".\n");
  write_file(log+"BANK", 
    RN+" altered "+whoob->query_real_name()+"'s guild credits by "+
    amount+". ("+ctime()+")\n");
}

enable_strike_attack(str) {
  if(!str) { write("Usage: setsa <attack>.\n"); return 1; }
  if(!valid_strike(str, TP->query_level()) ) {
    write("Usage: setsa <attack name>.\n"); return 1; }
  IP(TP)->set_strike_attack(str);
  write("Strike attack set to < "+str+" >. Now 'sa' to use.\n");
  return 1;
}

valid_strike(string str, int num) {
/* Check to see if we can use attack...
   'num' is my art level */
  if(str == "chop" || str == "forearm" ||
     str == "finger_jab" || str == "side_kick") {
    if(num > 0) return 1;
    else return 0; }
  if(str == "reverse_kick" || str == "backfist" ||
     str == "drop_kick" || str == "palm_thrust") {
    if(num > 1) return 1;
    else return 0; }
  if(str == "fierce_punch" || str == "head_clap" ||
     str == "elbow_jab" || str == "knee") {
    if(num > 2) return 1;
    else return 0; }
  if(str == "roundhouse" || str == "thrust_kick" ||
     str == "uppercut") {
    if(num > 3) return 1;
    else return 0; }
  if(str == "lock_and_punch" || str == "choke_grab" ||
     str == "lock_and_twist") {
    if(num > 4) return 1;
    else return 0; }
  if(str == "rapid_fist_strike" || str == "rapid_kick" ||
     str == "lock_and_elbow") {
    if(num > 5) return 1;
    else return 0; }
  if(str == "lock_and_throw" || str == "pressure_point") {
    if(num > 6) return 1;
    else return 0; }
 return 0;
}
 
strike(string str) {
  string side, name, Name, where, rmess, mymess;
  string gen, att, who, has, tpp;
  object g_ob, targ, ob;
  int dam, rand_dam, maxdam, cost, artlev, ran, yards;
  int xdam, sdmg, randnum, percent, fail, hp;
  int slev;
  if(!str) { write("Usage: st <attack> <who>\n"); return 1; }
  if(!sscanf(str,"%s %s",att,who)) {
    if(!MEAT) { write("Usage: st <attack> <who>\n"); return 1; }
    who = MEAT->query_real_name();
    att = str;
  }
  if(!valid_strike(att, TP->query_level()) ) {
    write("You don't know the "+att+" attack.\n"); return 1; }
  ob = TP;
  targ = present(who,environment(ob));
  if(!targ) {
    write("You see no '"+who+"' to strike...\n");
  return 1; }
  if(!valid_attack(targ, ob)) {
    if(check_location(ob, targ)) { }
    else {
      TE(ob,"You cannot attack "+WHO+".\n");
      return; }
    }
    if(targ->is_player() && !check_location(ob, targ)) {
      TE(ob,"You cannot attack "+WHO+".\n");
      return; }
  g_ob = present("implants", ob);
  artlev = g_ob->query_art_level();
  if (ob->query_spell_point() < 1) {
    TE(ob,"You are low on power.\n");
    return;}
  gen = ob->query_possessive();
  name = targ->query_name();
  Name = CAP(name);
  yards = (random(7))+10;
  ran = (random(2))+1;
  if(ran == 1) side = "left";
  if(ran == 2) side = "right";
  where = randhit();
  switch(att) {
case "chop":
  mymess = "You make a knife-hand and chop "+Name+" "+where+".\n";
  rmess = OPN+" makes a knife-hand and chops "+Name+" "+where+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "forearm":
  mymess = "You quickly thrust your forearm upwards, snapping "+Name+"'s\n"+
           "head painfully backwards.\n";
  rmess = OPN+" quickly thrusts "+gen+" forearm upwards, snapping "+Name+"'s\n"+
          "head painfully backwards.\n";
  slev = 1;
  dam = 2; cost = 2; break;
case "finger_jab":
  mymess = "You fuse your fingers together and thrust them "+where+
        " of "+Name+".\n";
  rmess = OPN+" fuses "+gen+" fingers together and thrusts them "+where+
        " of "+Name+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "side_kick":
  mymess = "You spin sidewards and kick "+Name+" "+where+".\n";
  rmess = OPN+" spins sidewards and kicks "+Name+" "+where+".\n";
  slev = 1;
  dam = 3; cost = 3; break;
case "reverse_kick":
  mymess = "You turn completely around and back-kick "+Name+" "+where+".\n";
  rmess = OPN+" turns completely around and back-kicks "+Name+" "+where+".\n";
  slev = 2;
  dam = 7; cost = 7; break;
case "backfist":
  mymess = "You snap your "+side+" wrist and hit "+Name+" "+where+".\n";
  rmess = OPN+" snaps "+gen+" "+side+" wrist and hits "+Name+" "+where+".\n";
  slev = 2;
  dam = 6; cost = 6; break;
case "drop_kick":
  mymess = "You acrobatically drop to the ground and kick upwards.\n"+
           "You hit "+Name+" "+where+"!\n";
  rmess = OPN+" acrobatically drops to the ground and kicks upwards.\n"+
      OPN+" hit "+Name+" "+where+"!\n";
  slev = 2;
  dam = 7; cost = 7; break;
case "palm_thrust":
  mymess = "You thrust out your "+side+" palm with all your bodily might,\n"+
           "and hit "+Name+" "+where+"!\n";
  rmess = OPN+" thrusts out "+gen+" "+side+" palm with all \n"+
          gen+" bodily might and hits "+Name+" "+where+"!\n";
  slev = 2;
  dam = 6; cost = 6; break;
case "fierce_punch":
  mymess = "You punch "+Name+" "+where+" with one hell of a whopper!\n";
  rmess = OPN+" punches "+Name+" "+where+" with one hell of a whopper!\n";
  slev = 3;
  dam = 10; cost = 10; break;
case "head_clap":
  mymess = "You smack both your hands right between "+Name+"'s head.\n";
  rmess = OPN+" smacks both "+gen+" hands right between "+Name+"'s head.\n";
  slev = 3;
  dam = 11; cost = 11; break;
case "elbow_jab":
  mymess = "You force your "+side+" elbow at "+Name+", "+where+"!\n";
  rmess = OPN+" forces "+gen+" "+side+" elbow at "+Name+", "+where+"!\n";
  slev = 3;
  dam = 10; cost = 10; break;
case "knee":
  mymess = "You force your "+side+" knee "+where+" of "+Name+".\n";
  rmess = OPN+" forces "+gen+" "+side+" knee "+where+" of "+Name+".\n";
  slev = 3;
  dam = 11; cost = 11; break;
case "roundhouse":
  mymess = "You spin around your "+side+" foot and kick "+Name+" "+
         where+"!\n";
  rmess = OPN+" spins around "+gen+" "+side+" foot and kicks "+Name+" "+
         where+"!\n";
  slev = 4;
  dam = 13; cost = 13; break;
case "thrust_kick":
  mymess = "You force all your weight into your kick, and hit\n"+
           Name+" "+where+"!\n";
  rmess = OPN+" forces all "+gen+" weight into "+gen+" kick, and hits\n"+
          Name+" "+where+"!\n";
  slev = 4;
  dam = 12; cost = 12; break;
case "uppercut":
  mymess = "You smoothly smack "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  rmess = OPN+" smoothly smacks "+Name+" "+where+" with a "+side+
        "uppercut!\n";
  slev = 4;
  dam = 12; cost = 12; break;
case "lock_and_punch":
  mymess = "You grapple "+Name+" and connect a solid punch "+where+"!\n";
  rmess = OPN+" grapples "+Name+" and connects a solid punch "+where+"!\n";
  slev = 5;
  dam = 15; cost = 15; break;
case "choke_grab":
  mymess = "You grab "+Name+"'s throat and choke like there's no tomorrow!\n";
  rmess = OPN+" grabs "+Name+"'s throat and chokes like there's no tomorrow!\n";
  slev = 5;
  dam = 15; cost = 15; break;
case "lock_and_twist":
  mymess = "You grab "+Name+" "+where+" and twist all the juices out!\n";
  rmess = OPN+" grabs "+Name+" "+where+" and twists all the jout!\n";
  slev = 5;
  dam = 13; cost = 13; break;
case "rapid_fist_strike":
  mymess = "You deliver a few thousand fist strikes "+where+" of "+Name+"!!\n";
  rmess = OPN+" delivers a few thousand fist strikes "+where+" of "+Name+"!!\n";
  slev = 6;
  dam = 16; cost = 16; break;
case "rapid_kick":
  mymess = "You kick "+Name+" a few times, a few more, and a few more!\n"+
           "Whoa, and they all hit "+where+"!\n";
  rmess = OPN+" kicks "+Name+" a few times, a few more, and a few more!\n"+
          "Whoa, and they all hit "+where+"!\n";
  slev = 6;
  dam = 18; cost = 18; break;
case "lock_and_elbow":
  mymess = "You cleverly lock "+Name+" and force your elbow "+where+"!\n";
  rmess = OPN+" cleverly locks "+Name+" and forces "+gen+" elbow "+where+"!\n";
  slev = 6;
  dam = 16; cost = 16; break;
case "lock_and_throw":
  mymess = "With a quick maneuver, you take hold and toss "+Name+" "+
        yards+" yards!\n";
  rmess = "With a quick maneuver, "+OPN+" takes hold and tosses "+Name+" "+
        yards+" yards!\n";
  slev = 7;
  dam = 24; cost = 24; break;
case "pressure_point":
  mymess = "You strike "+Name+" in a VITAL pressure point!\n";
  rmess = OPN+" strikes "+Name+" in a VITAL pressure point!\n";
  slev = 7;
  dam = 24; cost = 24; break;
    }

  /* Certain places hurt more than others */
  if(where == "right in the kisser") dam = dam + 3;
  if(where == "in the groin") dam = dam + 2;
if(where == "in the neck") dam = dam + 1;
  if(where == "in the torso") dam = dam - 1;
  if(where == "in the chest") dam = dam - 2;

  if(artlev < slev) { write("You must train to use this attack.\n");
    return 1; }
  if(artlev > 16) artlev = 16;
  hp = targ->query_hp();
  if(ob->query_sp() < (4 * cost / 3)) {
        TE(ob, "you become weak and fall flat on your face!\n");
        return 1; }
  if(dam >= hp) {
    TE(ob, "^You pull your blow^\n");
    /* Attacks can never kill a foe */
    return 1; }
  if(ob->query_ghost()) {
    write("Your insubstantial body does not allow physical attacks.\n");
    return 1;
  }
  if(targ->query_ghost()) {
    TE(ob, "Your attack swishes through thin air.\n");
    return 1; }

  randnum = random(100) + 1;
  fail = 100 - ((4 + artlev) * 4);
  if(randnum <= fail) {
    if(random(3) == 1) {
      /* total of 5% to 20% of failure */
      TE(ob, "()You fumble your attack()\n");
      return 1; }
    }

  rand_dam = dam + (artlev * 2);
  maxdam = rand_dam + dam;
  dam += random(rand_dam);
  cost += random(rand_dam);
  if(dam > 40) {
    cost = cost - (dam - 40)/5;  dam = 40; }
  if(maxdam > 50) maxdam = 50;

  if(dam > S10DAM_CAP) dam = S10DAM_CAP;

  ob->spell_object(targ,str,dam,cost,mymess,
      RED+"--------------------------------"+OFF+"\n",rmess);
if(dam < maxdam / 4) write(Name+" lets out a soft whimper.\n");
if(dam>maxdam/4 && dam<maxdam*3/4) write(Name+" screams in pain!\n");
if(dam >= maxdam *3/4) write(Name+" is DEVASTED by your attack!\n");

  if(targ) {
    if(!ob->query_attack()) ob->attack_object(targ);
    if(!targ->query_attack()) targ->attack_object(ob);
    }
  return 1;
}

/* do not remove */

query_s10shell() { return S10DAM_CAP; }
query_s10() { return S10DAM_CAP; }
query_s10_filename() { return S10flag; }
query_s10_serial() { return "879424"; }

string randhit() {
  int a;
  string msg;
  a = random(11) + 1;
  switch(a) {
    case 1:   msg = "right in the kisser"; break;
    case 2:   msg = "in the neck"; break;
    case 3:   msg = "in the groin"; break;
    case 4:   msg = "in the right shoulder"; break;
    case 5:   msg = "in the left shoulder"; break;
    case 6:   msg = "in the chest"; break;
    case 7:   msg = "in the chest"; break;
    case 8:   msg = "in the left leg"; break;
    case 9:   msg = "in the right leg"; break;
    case 10:  msg = "in the torso"; break;
    case 11:  msg = "right in the behind"; break;
    }
  return msg;
}

stun_blow(string str) {
  object targ, stunob;
  int mysp, mylev, oplev;
  int ARTLEV;
  ARTLEV = IP(TP)->query_art_level();
  stunob = clone_object("/players/snow/closed/cyber/stun_blow.c");
  mysp = TP->query_sp();
  mylev = TP->query_level();
  if(!str) { write("Usage: stun <player>.\n"); return 1; }
  targ = PRE(str,ENV(TP));
  if(!targ) { write(CAP(str)+" is not here.\n"); return 1; }
  if(!living(targ)) { write(CAP(str)+" is not alive!\n"); return 1; }
  if(targ != TP->query_attack()) {
    write("You must be fighting what you want to stun.\n"); return 1; }
  oplev = targ->query_level();
  if(PRE("stun_blow",targ)) {
    write(CAP(str)+" is already stunned!\n"); return 1; }
  if(mysp < ARTLEV) { 
    write("You lack the energy to perform the stunning blow.\n");
    return 1; }
  if(targ->is_player() && mylev < oplev) {
    write(CAP(str)+" is too strong for your stunning blow.\n");
    return 1; }
  write("You smash your fingers into "+CAP(str)+"'s neck!\n");
  TE(targ, "You feel a brief blinding pain!\n");
  TR(ENV(TP), CAP(str)+" goes limp and is stunned!\n");
  move_object(stunob, targ);
  stunob->destruct_stun(ARTLEV * 2);
  TP->add_spell_point(-ARTLEV);
  return 1;
}

int check_location(object ob, object targ) {
  if(EO->is_cyberninja_arena() && targ->is_player()) return 1;
  return 0;
}

valid_attack(object ob, object too) {
    int their_level, can_attack;
    string fight_area, name;
    object attacker_ob;
    attacker_ob = ob->query_attack();
    name = ob->query_name();
    if(call_other(ob, "is_player") && !call_other(ob, "query_interactive")) {
     TE(too,"You cannot attack disconnected players.\n");
    return 0;
    }
    if (call_other(ob, "is_player")) {
      if (call_other(ob, "query_level", 0) > 19) {
         if(check_location(too, ob)) return 0;
         TE(too,"You can't attack a wizard!\n");
        return 0;
       }
      if (call_other(too, "query_level", 0) > 19) {
         if(check_location(too, ob)) return 0;
        TE(too,"Wizards cannot attack players!\n");
        return 0;
       }
   }
   if(name=="guest" && !ob->query_npc()) return 0;
    /* If we're already fighting them, then it must be OK. */
   if(ob->query_fight_area() &&
      fight_area == file_name(environment(too))) {
     clear_crime();
     return 1;
     }
    if (ob == attacker_ob) return 1;
    /* They can always attack NPCs */
    if (call_other(ob, "query_npc")) return 1;
    if (call_other(ob, "is_player")) {
        if(check_location(too, ob)) return 0;
        TE(too, "Game rule: guild abilities such as this one\n"+
                 "are not to be used on players.\n");
         return 0; }
  /* Utter novices can't attack any other players */
  return 0;
}

goToGuild() {
  object here;
  string wheree;
  string here_realm;
  here = environment(this_player());
  here_realm = here->realm();
  if(TP->query_spell_point() < 55+random(5)) {
    write("You cannot atomize yourself, you are too low on power.\n");
    return; }
  if(here_realm == "NT") {
    write("Matter transfer is too dangerous from your location.\n");
    return; }
  if(wheree = call_other("obj/base_tele","teleport")) {
      this_player()->move_player("with an astonished look#"+wheree); }
  else {
  say(TPN+"s body vaporizes into nothing.\n");
  write("Your body disintegrates into invisible matter particles.\n");
  write("A magnetic transfer beam sucks you away...\n\n");
  TR("/players/snow/closed/cyber/rooms/teleport.c",
    TPN+" transfers in.\n");
  move_object(this_player(),
    "/players/snow/closed/cyber/rooms/teleport.c");
  command("look",TP); }
  call_other(TP, "add_spell_point", -(55+random(5)));
}

auto(string str) {
  /* sets the following automatics */
  if(!str) {
    write("Usage: auto [on/off]\n");
    return; }
  if(str == "on") {
    IP(TP)->set_auto(1);
    write("Your automatics are now on.\n");
    return; }
  if(str == "off") {
    IP(TP)->set_auto(0);
    write("Your automatics are now off.\n");
    return; }
  write("Usage: auto [on/off]\n"); 
}

wear(string str) {
/* ninjas are only able to wear light armor */
  object ob;
  if(!str) {
    write("Wear what?\n");
    return 0;
    }
  if(!present(str, TP)) {
    write("You do not have a "+str+" to wear.\n");
    return 1; }
  ob = present(str, TP);
  if(ob->id() == "nwep") return 1;
  if(ob->query_weight() > 2) {
    write("You cannot wear such heavy and restricting armor.\n");
    return 1; }
  call_other(ob, "wear", str);
}

color() {
  if(IP(TP)->query_color() == 1) {
    write("Color is now off.\n");
    IP(TP)->set_color(0);
    IP(TP)->save_me();
    update_implants();
    return; }
  write("Color is now on.\n");
  IP(TP)->set_color(1);
  IP(TP)->save_me();
  update_implants();
  return;
}



score() {
  int plev, ptox, ptuf, psok;
  int gbal, gwim;
  int preg;
plev = TP->query_level();
ptox = TP->query_intoxination();
ptuf = TP->query_stuffed();
psok = TP->query_soaked();
gbal = IP(TP)->balance();
gwim = IP(TP)->query_wimpy_hp();
  write(TP->short()+"\n");
  write(pad("Level: "+TP->query_level(), 32));
  write("Extra Level: "+TP->query_extra_level()+"\n");
  write(pad("Coins: "+TP->query_money(), 32));
  write("Experience: "+TP->query_exp()+"\n");
  write("Credits: "+gbal+"\n");
  write(pad("Hit Points: "+
         TP->query_hp()+"/"+TP->query_mhp(), 32));
  write("Energy: "+
         TP->query_sp()+"/"+TP->query_msp()+"\n");
  write("FluXcharges: "+IP(TP)->query_flux_charges()+"\n");
  write("Quest points: "+TP->query_quest_point()+"\n");
  TP->show_age();
  write("Time (CST): "+ctime(time())+"\n");
if(TP->query_wimpy()) 
  write("Wimpy mode.\n");
else
  write("Brave Mode\n");
  write("Intox ["+(ptox*100)/(plev+3)+"%]   "+
        "Soak ["+(psok*100)/(plev*8)+"%]   "+
        "Stuff ["+(ptuf*100)/(plev*8)+"%]\n\n");
  if(TP->query_pregnancy()) {
    preg = TP->query_age() - TP->query_pregnancy();
    if(preg > 4000)
    write("Pregnant: "+preg*100/16300+"%\n"); }
  return 1;
}

player_inventory() {
  object obj;
  obj = first_inventory(TP);
  if(!obj) {
    write("You are carrying nothing.\n");
    return 1;
  }
  write("\n"+BOLD+"-----CyberInventory-----"+OFF+"\n"+
        pad(" WEIGHT",17)+"ITEM\n\n");
  while (obj) {
    if(obj->short())
      write("[ "+pad(check_heavy(obj)+" ]",12)+obj->short()+"\n");
    obj = next_inventory(obj);
  }
  write("\n"+BOLD+"------------------------"+OFF+"\n");
  return 1;
}

check_heavy(object ob) {
  int w;
  string mess;
  w = ob->query_weight();
  if(w < 1) mess = "No Weight";
  if(w == 1 || w == 2) mess = "Very Light";
  if(w == 3 || w == 4) mess = "Light";
  if(w == 5 || w == 6) mess = "Heavy";
  if(w >= 7) mess = "Very Heavy";
  return mess;
}

bwho() {
  object * all;
  object opp;
  int i, total, hp, mhp;
  string statss;
  all = users();
  write("Player          Opponent            Opp's Health     Location.\n");
  write("____________________________________________________________________\n");
  for(i=0; i < sizeof(all); i++) {
    if(all[i]->query_attack() &&
       all[i]->query_invis() < TP->query_level() ) {
      opp = all[i]->query_attack();
      write(pad(capitalize(all[i]->query_name()), 16));
      write(pad(opp->query_name(), 20));
      hp = opp->query_hp();
      mhp = opp->query_mhp();
      statss = "good shape";
      if(hp < mhp - 20) statss = "slightly hurt";
      if(hp < mhp/2) statss = "somewhat hurt";
      if(hp < mhp/5) statss = "bad shape";
      if(hp < mhp/10) statss = "very bad shape";
      if(hp < mhp/20) statss = "verge of death";
      write(" ");
      write(pad(statss, 16));
      write(ENV(opp)->short()+"\n");
      total += 1;
      }
    }
  if(total == 0) write("Nobody is in battle.\n");
  write("____________________________________________________________________\n");
  return 1; 
}

new_start() {
  if(TP->query_home() == "/room/church.c" || 
     TP->query_home() == "room/church.c"  ||
     TP->query_home() == "/room/church"   ||
     TP->query_home() == "room/church"    ) {
     call_other(TP,"set_home","/players/snow/closed/cyber/rooms/guildhall.c");
     TP->save_me();
     write("You will now start in CyberNinja Grand Hall.\n");
     return 1; }
  write("You will now start in the Church.\n");
  call_other(TP,"set_home","/room/church.c");
  TP->save_me();
  return 1;
}


lead() {
  object ob;
  if(TP->query_spell_point() < 10) {
    write("You are too drained to do this.\n");
    return 1; }
  if(!TP->query_attack()) {
    write("You cannot lead a fight when not in combat.\n");
    return 1; }
  ob = TP->query_attack();
  TP->add_spell_point(-10);
  ob->attack_object(TP);
  TP->attack_object(ob);
  write("You boldly step into the heat of the battle!\n");
  say(TPN+" boldy steps into the heat of the battle!\n");
  return 1;
}

all_who()  {
int b, level, pk;
string gname, gen, room;
object * ob;
ob = users();

write("\n");
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");
  write("Player        Level    Guild       Pk   Gender   Location\n");
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~\n");

for(b=0;b<sizeof(ob);b+=1)  {
if(!ob[b]->query_invis()) {
   level = ob[b]->query_level();
   gname = ob[b]->query_guild_name();
   pk = ob[b]->query_pl_k();
   gen = ob[b]->query_gender();
   if(environment(ob[b]))
   room = environment(ob[b])->short();
   else room = "unknown";
   write(pad(CAP(ob[b]->query_name()),15)); write(" ");
   if(level >= 10000) write(pad("GOD",5));
   else write(pad(level,5));
   write(" ");
   if(gname) write(pad(gname, 13));
   else write(pad("none", 13));
   if(pk) write(pad("yes", 4));
   else write(pad("no", 4));
   write(pad(gen, 9));
   write(room);
   write("\n");
   }
 }
 write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
       "~~~~~~~~~~~~~~~\n\n");
return 1;
}

ninja_speak(str) {
   /* ability to speak own guild language */
   object ob;
   ob = first_inventory(ENV(TP));
   while(ob) {
      if( (IP(ob) && ob != TP) ||
           ob->query_real_name() == "_hide_in_shadows_vehicle_")
          tell_object(ob, TPN+" elates: "+str+"\n");
      else if(ob != TP) tell_object(ob, "You hear quiet voices in the room.\n");
      ob = next_inventory(ob);
   }
   write("You elate: "+str+"\n");
   return 1;
}

mask(string align) { 
  TP->set_al_title(align);
  write("You mask your alignment to "+align+".\n");
  return 1;  
}




/* ENHANCEMENT CODE */
cyberware() {
  /* method for players to see enhancement info */
  TE(TP, "You take out your handy CyberWare Manual.\n");
  move_object(clone_object(
    "/players/snow/closed/cyber/objects/cyberware_manual.c"),
    this_player());
  say(TPN+" takes out a thick manual.\n");
  return 1; 
}

string gen(object ob) {
  /* Not an enhancement.  This just calculates possessive */
  string gender, gen;
  gender = ((string)ob->query_gender());
  switch(gender) {
    case "male": gen = "his"; break;
    case "female": gen = "her"; break;
    case "creature": gen = "its"; break;
    }
  return gen;
}

corpse() {
  object ob;
  ob = present("corpse",ENV(TP));
  if(!ob) {
    write("There is no corpse here!\n");
    return 1; }
  call_other(TP,"heal_self",ob->heal_value());
  write("You dismember a corpse and burn it for fuel.\n");
  say(TPN+" dismembers a corpse and burns it for fuel.\n");
destruct(ob);
return 1;
}

reg() {
  if(IP(TP)->query_regen() == 1) {
    write("You stop the regeneration process.\n");
    IP(TP)->set_regen(0);
  return 1;
  }
  write("Your molecules recombine and begin regenerating.\n");
  IP(TP)->set_regen(1);
  IP(TP)->reg_beat();
  return 1;
}

rej() {
  if(IP(TP)->query_rejuv() == 1) {
    write("You stop the rejuvenation process.\n");
    IP(TP)->set_rejuv(0);
    return 1;
  }
  write("Your molecules burn and begin releasing energy.\n");
  IP(TP)->set_rejuv(1);
  IP(TP)->rej_beat();
  return 1;
}

regenerate(object ob) {
  int level, value, delay;
  level = IP(ob)->guild_lev();
  if(level > 12) level = 12;
  value = (level * 2 / 3) + 1;
  if(ob->query_sp() < 50) {
    TE(ob, "You have no more energy to continue regeneration.\n");
    TE(ob, "Regeneration terminated...\n");
    IP(ob)->set_regen(0);
    return 1; }
  if(ob->query_hp() >= ob->query_mhp()) {
    TE(ob, "You have fully regenerated.\n");
    TE(ob, "Regeneration terminated...\n");
    IP(ob)->set_regen(0);
    return 1; }
  ob->add_hit_point(value);              /* up to 6 hp healed */
  ob->add_spell_point(-(value));     /* up to 6 sp drained */
  TE(ob, "Regenerating...\n");
  return 1;
}

rejuvenate(object ob) {
  int level, value, delay;
  level = IP(ob)->guild_lev();
  if(level > 12) level = 12;
  value = (level * 2 / 3) + 1;
  if(ob->query_hp() < 50) {
    TE(ob, "You are too weak to continue rejuvenation.\n");
    TE(ob, "Rejuvenation terminated...\n");
    IP(ob)->set_rejuv(0);
    return 1; }
  if(ob->query_sp() >= ob->query_msp()) {
    TE(ob, "You have fully rejuvenated.\n");
    TE(ob, "Rejuvenation terminated...\n");
    IP(ob)->set_rejuv(0);
    return 1; }
  ob->add_spell_point(value);            /* up to 6 sp healed */
  ob->add_hit_point(-(value));       /* up to 6 hp drained */
  TE(ob, "Rejuvenating...\n");
  return 1;
}

equil() {
  if(IP(TP)->query_equil() == 1) {
    write("Bodily equilibration discontinued.\n");
    IP(TP)->set_equil(0);
  return 1;
  }
  write("Bodily equilibration begun.\n");
  IP(TP)->set_equil(1);
  IP(TP)->equil_beat();
  return 1;
}

equilibrate(object ob) {
  int ohp, osp;
  ohp = ob->query_hp();
  osp = ob->query_sp();
  if(osp - ohp < 3 && ohp - osp < 3) {
    write("Body equilibrated. Process stopped.\n");
    IP(ob)->set_equil(0);
  return 1;
  }
  if(ohp > osp) {
    ob->add_hit_point(-2);
    ob->add_spell_point(2);
  }
  if(osp > ohp) {
    ob->add_hit_point(2);
    ob->add_spell_point(-2);
  }
  TE(ob,"Equilibrating...\n");
  return 1;
}

power_wield() {
  object meat;
  meat = TP->query_attack();
  if(GLEV < 4) return 1;
  if(!meat) { write("Power attack can only be used in combat.\n");
              return 1; }
  if(!PRE(meat, ENV(TP))) return 1;
  TP->spell_object(meat,"Power Wield",random(20)+5,15,
               "You cut viciously into "+
                capitalize(meat->query_real_name())+".\n",
               TPN+" cuts viciously into you!\n",
               TPN+" cuts viciously into "+
                   capitalize(meat->query_real_name())+".\n");
return 1;
}

power_wield2() {
  object meat;
  meat = TP->query_attack();
  if(GLEV < 6) return 1;
  if(TP->query_level() < 12) {
    write("You must be player level 12 to use this.\n"); return 1; }
  if(!meat) { write("Power attack can only be used in combat.\n");
              return 1; }
  if(!PRE(meat, ENV(TP))) return 1;
  TP->spell_object(meat,"Power Wield",random(24)+8,20,
               "You cut viciously into "+
                capitalize(meat->query_real_name())+".\n",
               TPN+" cuts viciously into you!\n",
               TPN+" cuts viciously into "+
                   capitalize(meat->query_real_name())+".\n");
return 1;
}

power_wield3() {
  object meat;
  meat = TP->query_attack();
  if(GLEV < 10) return 1;
  if(TP->query_level() < 19) {
    write("You must be player level 19 to use this.\n"); return 1; }
  if(!meat) { write("Power attack can only be used in combat.\n");
              return 1; }
  if(!PRE(meat, ENV(TP))) return 1;
  TP->spell_object(meat,"Power Wield",random(30)+10,25,
               BOLD+"You cut viciously into "+
                capitalize(meat->query_real_name())+OFF+".\n",
               TPN+" cuts viciously into you!\n",
               TPN+" cuts viciously into "+
                   capitalize(meat->query_real_name())+".\n");
return 1;
}

electricflux(string who) { 
  /* concentrated dmg enhancement */
  object ob;
  int dmg;
  if(!who) {
    if(!TP->query_attack()) {
      write("Usage: eflux <target>\n");
    return 1;
    }
  else ob = TP->query_attack();
  }
  if(who) {
    if(!present(who, ENV(TP))) {
      write("There is no "+capitalize(who)+" here.\n");
    return 1;
    }
  else ob = present(who,ENV(TP));
  }
  if(ob->query_ghost()) {
    write("Your target is already dead.\n");
    return 1; }
  if(!ob->query_npc() && !check_location(TP,ob)) {
    write("You cannot flux that!\n"); return 1; }
  if(TP->query_spell_point() < 40) {
    write("Your energy reserves are too low.\n");
    return 1; }
  if(!IP(TP)->query_flux_charges() ) {
    write("You must charge your FluX before you can use it.\n");
    return 1; }
  IP(TP)->lower_flux_charges(1);
  if(IP(TP)->guild_level() + 85 < random(100) ) {
    write("Your flux generator backfires!\n");
    if(TP->query_attrib("wil") < random(40)) {
      write("Electricity crackles through your body!\n");
       TP->hit_player(random(IP(TP)->guild_lev()) + 1); }
    TP->add_spell_point(-(random(20)));
  return 1;
  }
  
  dmg = IP(TP)->guild_lev();
  dmg = dmg * random(4);
  dmg = dmg + 10;
  if(dmg > 40) dmg = 40;
  TP->add_spell_point(-dmg);
  TR(ET,
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"          "+BLUE+"- -- ---*--- -- -"+OFF+"\n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n"+
"                  "+BLUE+"|"+OFF+"        \n");
  TR(ET, "\n");
  TR(ET, TPN+" releases a burst of electric flux into "+OPN+"\n\n");
 ob->heal_self(-dmg);
 /*
  TP->add_spell_point(-(random(dmg) + random(20)));
  */
  if(ob) {
    if(!ob->query_attack()) ob->attack_object(TP);
    if(!TP->query_attack()) TP->attack_object(ob);
    }
  return 1;
}

charge_flux() {
  if(IP(TP)->query_charge_on()) {
    IP(TP)->set_charge_on(0);
    write("You stop charging your FluX.\n"); RE; }
  IP(TP)->set_charge_on(1);
  RE;
}
 
flux_charge(object ob) {
  int charges;
  if(!ob) return 1;
  charges = IP(ob)->query_flux_charges();
  if(charges >= (GLEV/2)+ 1 ) {
    TE(ob, BOLD+"FluX charger full [ "+charges+" ]"+OFF+"\n"); RE; }
  if(ob->query_sp() < 50) {
    TE(ob,"FluX charging would drain your energy supply too much.\n"+
          "Process halted. [ "+charges+" ]\n"); RE; }
  ob->add_spell_point(-8);
  IP(ob)->add_flux_charges(1);
  TE(ENV(TO), "FluX charging... [ "+charges+" ]\n");
  RE;
}

magneticflux(string who) { 
  /* concentrated dmg enhancement */
  object ob;
  int dmg;
  if(!who) {
    if(!TP->query_attack()) {
      write("Usage: mflux <target>\n");
    return 1;
    }
  else ob = TP->query_attack();
  }
  if(who) {
    if(!present(who, ENV(TP))) {
      write("There is no "+capitalize(who)+" here.\n");
    return 1;
    }
  else ob = present(who,ENV(TP));
  }
  if(ob->query_ghost()) {
    write("Your target is already dead.\n");
    return 1; }
  if(!ob->query_npc() && !check_location(TP,ob)) {
    write("You cannot flux that!\n"); return 1; }
  if(TP->query_spell_point() < 40) {
    write("Your energy reserves are too low.\n");
    return 1; }
  if(!IP(TP)->query_flux_charges() ) {
    write("You must charge your FluX before you can use it.\n");
    return 1; }
  IP(TP)->lower_flux_charges(1);
  if(IP(TP)->guild_level() + 85 < random(100) ) {
    write("Your flux generator backfires!\n");
    if(TP->query_attrib("wil") < random(40)) {
      write("Magnetic energy fries your links!\n");
       TP->hit_player(random(IP(TP)->guild_lev()) + 1); }
    TP->add_spell_point(-(random(20)));
  return 1;
  }
  dmg = IP(TP)->guild_lev();
  dmg = dmg * random(4);
  dmg = dmg + 10;
  if(dmg > 40) dmg = 40;
  TP->add_spell_point(-dmg);
  TR(ET, GREEN+"||||||||||"+OFF+"\n");
  TR(ET, GREEN+"||||||||||||||||||||"+OFF+"\n");
  TR(ET, GREEN+"||||||||||||||||||||||||||||||||||||||||"+OFF+"\n");
  TR(ET, TPN+" releases a burst of magnetic flux into "+OPN+"\n");
  TR(ET, GREEN+"||||||||||||||||||||||||||||||||||||||||"+OFF+"\n");
  TR(ET, GREEN+"||||||||||||||||||||"+OFF+"\n");
  TR(ET, GREEN+"||||||||||"+OFF+"\n");
 ob->heal_self(-dmg);
  if(ob) {
    if(!ob->query_attack()) ob->attack_object(TP);
    if(!TP->query_attack()) TP->attack_object(ob);
    }
  return 1;
}

heatflux(string who) { 
  /* concentrated dmg enhancement */
  object ob;
  int dmg;
  if(!who) {
    if(!TP->query_attack()) {
      write("Usage: hflux <target>\n");
    return 1;
    }
  else ob = TP->query_attack();
  }
  if(who) {
    if(!present(who, ENV(TP))) {
      write("There is no "+capitalize(who)+" here.\n");
    return 1;
    }
  else ob = present(who,ENV(TP));
  }
  if(ob->query_ghost()) {
    write("Your target is already dead.\n");
    return 1; }
  if(!ob->query_npc() && !check_location(TP,ob)) {
    write("You cannot flux that!\n");  return 1; }
  if(TP->query_spell_point() < 40) {
    write("Your energy reserves are too low.\n");
    return 1; }
  if(!IP(TP)->query_flux_charges() ) {
    write("You must charge your FluX before you can use it.\n");
    return 1; }
  IP(TP)->lower_flux_charges(1);
  if(IP(TP)->guild_level() + 85 < random(100) ) {
    write("Your flux generator backfires!\n");
    if(TP->query_attrib("wil") < random(40)) {
      write("Built-up heat makes your skin smoke and burn!\n");
       TP->hit_player(random(IP(TP)->guild_lev()) + 1); }
    TP->add_spell_point(-(random(20)));
  return 1;
  }
  dmg = IP(TP)->guild_lev();
  dmg = dmg * random(4);
  dmg = dmg + 10;
  dmg = random(20) + dmg;
  if(dmg > 40) dmg = 40;
  TP->add_spell_point(-dmg);
  if(dmg > ob->query_hp()) dmg = ob->query_hp() -1;
  TR(ET,
RED+"    ff                           f                  "+OFF+"\n"+
RED+"   ff        f                   ff         f     f "+OFF+"\n"+
RED+"  ff        f        f         fff        f     ff  "+OFF+"\n"+
RED+" fff      ff        fff      fffff       ff    ffff "+OFF+"\n");
  TR(ET, TPN+" releases a burst of heat flux into "+OPN+"\n\n");
 ob->heal_self(-dmg);
  if(ob) {
    if(!ob->query_attack()) ob->attack_object(TP);
    if(!TP->query_attack()) TP->attack_object(ob);
    }
  return 1;
}

speed_run() {
  /* way for players to clone up their speedters */
  if(present("leg actuators",TP)) {
    write("Your leg actuators are already activated.\n");
    return 1;
  }
  move_object(clone_object("/players/snow/closed/speed.c"),
              this_player());
  TE(TP, "You have activated your leg actuators.\n");
  tell_room(environment(TP), TPN+"'s leg muscles tense up.\n"+
           "____________________ __________ _____ ___ __ _\n");
  return 1;
}

flash() {
  /* light spell enhancement */
  int time;
  string name;
  mixed jumble;
  time = present("implants",TP)->guild_lev();
  time = time * 80;
  time = time + 1000;
  if(TP->query_spell_point() < 2) {
    write("You are too drained to do this.\n");
    return 1; }
  write("Glowing liquid courses through your veins.\n");
  write("Your body glows with an inner flourescent light.\n");
  say("Glowing liquid courses through "+TPN+"'s veins.\n");
  say(TPN+"'s body glows with an inner flourescent light.\n");
  IP(TP)->do_light(1);
  IP(TP)->set_light_on(1);
  TP->add_spell_point(-2);
  name = lower_case(TP->query_real_name());
  jumble = name+" "+time;
  call_out("stop", 1, jumble);
  return 1;
}

stop(mixed jumble) {
  string name;
  object ob;
  int time;
  sscanf(jumble, "%s %d", name, time);
  ob = find_player(name);
  time -= 1;
  if(time > 0) {
     jumble = name+" "+time;
     call_out("stop", 1, jumble);
     return 1; }
  TE(ob, "Your bodily glow fades away.\n");
  TE(ENV(ob), capitalize(ob->query_name())+
              "'s bodily glow fades.\n"+
              "The room light dims.\n");
  IP(TP)->do_light(-1);
  IP(TP)->set_light_on(0);
  return 1;
}

cyber_look(str) {
  string myinv, roominv, myenv;
  object eyesee;
  if(!str) {
    IP(TP)->do_light(2);
    write(BOLD+"**CyberEyes**"+OFF+"\n"+GREEN);
    command("look",TP);
    write(OFF);
    IP(TP)->do_light(-2);
  return 1;
  }
  write(BOLD+"**CyberEyes**"+OFF+"\n");
  myinv = first_inventory(TP);
  eyesee = PRE(str,ENV(TP));
  if(!eyesee) eyesee = PRE(str,myinv);
  if(!eyesee) { write(BOLD+"CyberEyes"+OFF+" do not detect "+str+".\n");
  return 1; }
  write(GREEN);
  IP(TP)->do_light(2);
  command("look at "+str, TP);
  IP(TP)->do_light(-2);
  write(OFF);
   return 1;
}

cyber_move(str) {
  if(!str) { write(BOLD+"**CyberMove**"+OFF+" in which direction?\n");
             return 1; }
  write(BOLD+"**CyberMove** "+CAP(str)+OFF+"\n"+GREEN); 
  IP(TP)->do_light(2);
  command(str,TP);
  IP(TP)->do_light(-2);
  write(OFF);
  return 1;
}

cyber_get(str) {
    string item;
    string container;
    object item_o;
    object container_o;
    int weight;
 
    if (!str) {
        write("Usage: cyberget <item>\n");
        return 1; }
    if (TP->query_ghost()) {
        write("Your incorporeal hand passes right through it.\n");
        return 1; }
 
    if (str == "all") {
        get_all(environment());
        return 1; }
 
    if (sscanf(str, "%s from %s", item, container) != 2) {
        if(!PRE(str,ENV(TP))) {
          write(BOLD+"[[ "+OFF+GREEN+str+OFF+BOLD+" ]] is not here."+
                OFF+"\n");
        return 1; }
        else if(get_ob(PRE(str,ENV(TP))) == 2)
             say(TPN+" takes: "+str+ ".\n");
        return 1; }
    container_o = present(container,TP);
    if(!container_o) container_o = PRE(container,ENV(TP));
    if (!container_o) {
        write("  [[ "+GREEN+container+OFF+" ]] is not here.\n");
        return 1; }
    if (!call_other(container_o, "can_put_and_get", 0)) {
        write("You can't do that!\n");
        return 1; }
    if (item == "all") {
        get_all(container_o);
        return 1; }
    item_o = present(item, container_o);
    if(!item_o) {
      write("There is no "+item+" in the "+container+".\n");
      return 1; }
    if(get_ob(item_o) == 2) {
    weight = item_o->query_weight();
    call_other(container_o, "add_weight", -weight);
    say(TPN+" takes "+item+" from "+container+".\n"); }
    return 1;
}
 
get_all(object from) {
   object ob;
   ob = first_inventory(from);
  while(ob) {
   if(get_ob(ob) == 2) 
   say(TPN+" takes: "+ob->short()+ ".\n");
   ob = next_inventory(ob);
  }
  return 1;
}
 
get_ob(object ob) {
  int weight;
  string item;
  if(  ob->short() && ob->get() && !ob->query_invis() &&
       !living(ob) && !call_other(ob, "drop", 1) &&
     !call_other(ob, "id", "soul") ) {
      weight = call_other(ob, "query_weight");
      item = ob->short();
      if(TP->add_weight(weight)) {
        write(BOLD+"You take [[ "+OFF+GREEN+item+OFF+BOLD+" ]]"+OFF+"\n");
        transfer(ob, this_player());
        TP->recalc_carry();
        return 2;
       }
    else
    write(BOLD+"[[ "+OFF+GREEN+item+OFF+BOLD+
               " ]] is too heavy or ungettable."+OFF+"\n");
  return 1; }
}

emt(string str) {
  /* peace,aggression,nauseating enhancement */
  object ob;
  string name;
    int level, cost, duration;
    object nob;
  if(!str) {
  write("Usage: emt [p/a]\n");
    return 1; }
  if(TP->query_spell_point() < 35) {
    write("Your energy reserves are too low.\n");
    return 1; }
  if(str == "p") {
    TP->add_spell_point(-35);
    ob=first_inventory(ENV(TP));
    while (ob) {
     if (living(ob)) {
      if(ob->query_attack()) {
           (ob->query_attack())->stop_fight();
      (ob->query_attack())->stop_hunter();
     (ob->query_attack())->stop_fight();
      ob->stop_fight();
      ob->stop_hunter();
           ob->stop_fight();
           }
      }
      ob = next_inventory(ob);
     }
    write("A visible wave pattern emanates from you.\n");
    write("A soft blue haze envelopes the room.\n");
    write("You feel at peace.\n");
    say("A visible wave pattern emanates from "+TPN+".\n");
    say("A soft blue haze envelopes the room.\n");
    say("You feel at peace.\n");
    return 1; }
  if(str == "a") {
    if(!ok_in_room(TP)) {
      write("You cannot do that here.\n");
      return 1; }
    ob=first_inventory(ENV(TP));
    while (ob) {
     if (living(ob)) {
        name = ob->query_name();
        name = lower_case(name);
        /*
        if(find_player(name)) {
          if(find_player(name)->query_pl_k() &&
             find_player(name)->query_level() < 20)
            find_player(name)->attack_object(TP); }
          */
        if(!find_player(name)) {
          if(find_player(name) == TP) ob = next_inventory(ob);
          if(ob->query_attack())
             (ob->query_attack())->attack_object(TP);
          ob->attack_object(TP); }
        }
      ob = next_inventory(ob);
     }
    write("A visible wave pattern emanates from you.\n");
    write("A bright red haze envelopes the room.\n");
    write("You have turned everyone against you!\n");
    say("A visible wave pattern emanates from "+TPN+".\n");
    say("A bright red haze envelopes the room.\n");
    say("You become insane!\n");
    return 1; }
  write("Usage: emt [p/a]\n");
  return 1; 
}

int ok_in_room(object ob) {
  object room;
  room = environment(ob);
  if( (room == find_object("/room/church.c")) ||
      (room == find_object("/room/adv_guild.c")) ||
      (room == find_object("/room/shop.c")) ||
      (room == find_object("/room/post.c")) )
    return 0;
  return 1; }
 
bionics() {
  /* added dmg enhancement */
  if(!TP) return;
  if(TP->query_spell_point() < 15) {
    write("Use of bionics is too draining for your state.\n");
    return 1; }
  if(IP(TP)->query_bion_on()) {
    write("You manually de-activate your bionics.\n");
    say(TPN+" manually de-activates "+TP->query_possessive()+
        " bionics.\n");
    IP(TP)->set_bion_on(0);
    return 1; }
  IP(TP)->set_bion_on(1);
  TP->add_spell_point(-15);
  write("Bionics engaged.\n");
  say(TPN+" engages "+GEN+" bionics.\n");
  IP(TP)->bion_beat();
  return 1;
}

blades() {
  /* added dmg enhancement */
  if(!TP) return;
  if(TP->query_spell_point() < 10) {
    write("You need more power to protract your blades.\n");
    return 1; }
  if(IP(TP)->query_blad_on()) {
    write("You retract your blades.\n");
    say(TPN+" retracts "+TP->query_possessive()+
        " blades.\n");
    IP(TP)->set_blad_on(0);
    return 1; }
  IP(TP)->set_blad_on(1);
  TP->add_spell_point(-10);
  write("Sharp blades emerge from your body.\n");
  say("Sharp blades emerge from "+TPN+"'s body.\n");
  IP(TP)->blad_beat();
  return 1;
}


matter_conversion() {
  object pob, ob;
  pob = present("transferobj",TP);
  if(pob) {
    destruct(pob);
    IP(TP)->set_convert_on(0);
    write("Matter conversion stopped.\n");
    return 1;
  }
  ob = clone_object("/players/snow/closed/transfer.c");
  move_object(ob,TP);
  pob = present("transferobj",TP);
  pob->energy_transfer();
  IP(TP)->set_convert_on(1);
  write("Matter conversion begun.\n");
  return 1;
}

activate_droid() {
  /* droid is not a pet, just a moving 'bag'... enhancement */
  object obdroid;
    obdroid = clone_object("/players/snow/closed/cyber/droid.c");
    if(find_object(TP->query_real_name()+"droid")) {
    write("You already have a droid.\n");
    return 1; }
  if(TP->query_spell_point() < 20) {
    write("You do not have enough energy to supply your droid.\n");
    return 1; }
  TP->add_spell_point(-20);
  move_object(obdroid,ET);
    obdroid->set_follname(TP->query_real_name());
    obdroid->set_droidid(TP->query_real_name()+"droid");
  write("Your droid's lights turn on.  It is active now.\n");
  say(TPN+" turns on "+GEN+" droid.\n");
  command("droidlink",TP);
  return 1; 
}

net_deaths() {
  write("You tap into the cybernet to check on recent player deaths...\n"+"\n");
  tail("/log/DEATHS");
  write("\n"+"Perhaps you should help some pk'rs make this list...\n");
return 1;
}

combat_retreat() {
  object meat;
  meat = TP->query_attack();
  if(!meat) {
    write("You have nothing to retreat from as you are not in combat!\n");
    return 1; }
      if(TP->query_spell_point() < 15) {
    write("You need more power.\n"); 
  return 1; }
  TP->add_spell_point(-15);
  write("You retreat from your attack!\n");
  say(TPN+" retreats from "+GEN+" attack!\n");
  if(meat->query_attack() == TP) {
    meat->stop_fight();
    meat->stop_fight();
    meat->stop_hunter();
  }
  TP->stop_fight();
  TP->stop_fight();
  TP->stop_hunter();
return 1;
}

scan_news() {
  write("You tap into the cybernet news...\n");
  cat("/players/snow/closed/cyber/docs/news");
  write("You close the news connection.\n");
return 1;
}

record(string str) {
  if(!str) {
    write("What do you wish to record?\n");
    return; }
  write_file(log+"RECORD", 
    "--------------------------------------------------\n"+
    "->"+capitalize(this_player()->query_real_name())+
    "   ("+ctime()+")\n"+
    str+"\n");
  write("Your message will be added to the guild record.\n");
  return 1;
}

upall()  {
  /* command to update all cyberninja implants */
  int b;
  object ob;
  ob = users();
 write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 for(b=0;b<sizeof(ob);b+=1)  {
  if(IP(ob[b]))  {
   IP(ob[b])->save_me();
   destruct(IP(ob[b]));
   move_object(clone_object(
               "/players/snow/closed/cyber/implants.c"),
               ob[b]);
   write(pad(ob[b]->query_name(),15));
   write(" updated.\n");
   }
 }
 write("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
return 1;
}

death_blow(string str) {
  /* process for finishing off opponents
      attempts to counteract the inability of other attacks to kill */
  object ob;
  string name;
  int level, hp;
  if(!str) {
    if(!TP->query_attack()) {
      write("Usage: deathblow or db <monster>.\n");
      return 1; }
      ob = TP->query_attack();
  }
  if(str) {
     if(!present(str, environment(TP))) {
       write(capitalize(str)+" is not here.\n");
       return 1; }
     ob = present(str, environment(TP));
  }
  if(!ob->query_npc() && !check_location(TP,ob)) {
    write("You cannot use death blow on that!\n"); return 1; }
  if(ob->query_ghost()) {
    write("Your target is already dead.\n");
    return 1; }
  name = RED+capitalize(ob->query_name())+OFF;
  hp = ob->query_hp();
  level = IP(TP)->query_art_level();
  level = level * 2;
  if(TP->query_spell_point() < level) {
    write("You lack power to perform the killing blow!\n");
    return 1; }
  if(hp <= level) {
    write("You strike "+name+" with a razor fist!\n");
    TP->add_spell_point(-level);
    TP->spell_object(ob,"DeathBlow",level,level,
      RED+"Your deathblow falls!\n"+OFF);
    if(!ob->query_attack()) ob->attack_object(TP);
    if(!TP->query_attack()) TP->attack_object(ob);
    return 1;
  }
  else write(name+" is too healthy to die.\n");
}

no_spell() {
  write("CyberNinjas cannot use mud spells.\n"); return 1; }

spy_room(string str) { 
  /* Shows environment of a player and what players are wielding */
  object player, room, allroom;
  int i;
  if(!str) { write("Usage: roomspy <player>.\n"); return 1; }
  player = find_player(str);
  if(!player) { write("Player ["+CAP(str)+"] not found.\n"); return 1; }
  if(player->query_invis()) {
    write("Player ["+CAP(str)+"] not found.\n"); return 1; }
  if(player->query_level() > 19) {
    write("The spy satellite does not function on wizards.\n"); return 1; }
  room = environment(player);
  allroom = all_inventory(room);
  write(BOLD+"~~~ CYBERNINJA SPY SATELLITE DOWNLOAD ~~~"+OFF+"\n");
  write("\n\n"+GREEN+"--["+room->short()+"]--"+OFF+"\n");
  write(room->long());
  for(i=0; i < sizeof(allroom); i++) {
    if(allroom[i]->short()) write(allroom[i]->short());
    if(allroom[i]->query_weapon()) {
      write("\n");
      write("  "+BOLD+"Using:"+OFF+":  "+allroom[i]->query_weapon()->short());
    }
    write("\n");
  }
  write("\n\n");
  TP->add_spell_point(-25);
  return 1;
}

power_scan(str) {
  object meat;
  int mlev, mhp, mmaxhp, msp, mmaxsp, mac, mwc;
  int align;
  string alignmsg;
  string levmsg, wearmsg, tmsg, spmsg, acmsg, powermsg;
  string wcmsg;
  int mpower, mtough;
  if(!str) {
    write("Powerscan what monster or player?\n");
  return 1;
  }
  meat = present(str,environment(TP));
  if(!meat) {
    write(capitalize(str)+" is not present.\n");
  return 1;
  }
  mlev = meat->query_level();
  mhp = meat->query_hp();
  mmaxhp = meat->query_mhp();
  msp = meat->query_sp();
  mmaxsp = meat->query_msp();
  mac = meat->query_ac();
  mwc = meat->query_wc();
  align = meat->query_alignment();
   if(mlev > 50) levmsg = "Oodles and Oodles";
   if(mlev > 25 && mlev < 51) levmsg = "Insane amounts";
   if(mlev > 20 && mlev < 26) levmsg = "Incredible";
   if(mlev > 15 && mlev < 21) levmsg = "Great";
   if(mlev > 10 && mlev < 16) levmsg = "Good";
   if(mlev > 5 && mlev < 11) levmsg = "Poor";
   if(mlev < 6) levmsg = "Very little";
   if(!levmsg) levmsg = "Unknown";
   if(mac > 50) acmsg = "Nearly Untouchable";
   if(mac > 30 && mac < 51) acmsg = "Tremendously tough";
   if(mac > 20 && mac < 31) acmsg = "Extremely hard to hit";
   if(mac > 15 && mac < 21) acmsg = "Very hard to damage";
   if(mac > 10 && mac < 16) acmsg = "Hard to damage";
   if(mac > 5 && mac < 11) acmsg = "Easy to damage";
   if(mac < 6) acmsg = "Very easy to hit and damage";
   if(!mac) acmsg = "Unknown";
   if(mwc > 100) wcmsg = "A godlike force **FEAR THIS**";
   if(mwc > 70 && mwc < 101) wcmsg = "Insane damage. You will be hurt";
   if(mwc > 50 && mwc < 71) wcmsg = "Extreme damage capabilities";
   if(mwc > 30 && mwc < 51) wcmsg = "Huge damage capability";
   if(mwc > 20 && mwc < 31) wcmsg = "Large damage capability";
   if(mwc > 15 && mwc < 21) wcmsg = "Average damage capability";
   if(mwc > 5 && mwc < 16) wcmsg = "Weak damage capability";
   if(mwc < 6) wcmsg = "Extremely weak damage capacity";
   if(!mwc) wcmsg = "Unknown";
   if(mhp > ((mmaxhp * 1) / 10)) wearmsg = "Extreme";
   if(mhp > ((mmaxhp * 3) /10)) wearmsg = "Very heavy";
   if(mhp > ((mmaxhp * 5) / 10)) wearmsg = "Heavy";
   if(mhp > ((mmaxhp * 7) / 10)) wearmsg = "Moderate";
   if(mhp > ((mmaxhp * 9) / 10)) wearmsg = "Slight";
   if(mhp == mmaxhp) wearmsg = "None";
   if(mhp < (mmaxhp / 10)) wearmsg = "Destruction imminent";
   if(!wearmsg) wearmsg = "Unknown";
   mpower = mac + mwc;
   if(mpower > 150) powermsg = "Godlike. Run... NOW";
   if(mpower < 151) powermsg = "Tremendously powerful. To be feared";
   if(mpower < 100) powermsg = "Incredibly powerful";
   if(mpower < 70) powermsg = "Extremely powerful";
   if(mpower < 50) powermsg = "Very powerful";
   if(mpower < 30) powermsg = "Moderate power";
   if(mpower < 20) powermsg = "Weak";
   if(mpower < 10) powermsg = "Very weak";
   if(!powermsg) powermsg = "Unknown";
   mtough = (mmaxhp / 25) + mac;
   if(mtough > 150) tmsg = "Godlike resistance to attacks";
   if(mtough < 151) tmsg = "Insanely tough. Protracted battle";
   if(mtough < 100) tmsg = "Tremendously tough. Protracted battle";
   if(mtough < 70) tmsg = "Incredibly tough. Long battle";
   if(mtough < 50) tmsg = "Very tough. Long battle";
   if(mtough < 30) tmsg = "Tough. Mid-length battle";
   if(mtough < 20) tmsg = "Fairly easy. Mid-length battle";
   if(mtough < 15) tmsg = "Easy. Short battle";
   if(mtough < 10) tmsg = "Very easy. Short battle";
   if(mtough < 5) tmsg = "Extremely easy. Very short battle";
   if(!tmsg) tmsg = "Unknown";
   if(mmaxsp > 0) {
     if(msp == mmaxsp) spmsg = "Full";
     if(msp < ((mmaxsp * 9) / 10)) spmsg = "Nearly full";
     if(msp < ((mmaxsp * 7) / 10)) spmsg = "Somewhat full";
     if(msp < ((mmaxsp * 5) / 10)) spmsg = "Mostly drained";
      if(msp < ((mmaxsp * 3) / 10)) spmsg = "Nearly depleted";
     if(msp < (mmaxsp / 10)) spmsg = "Depleted";
   }
   if(align > 500) alignmsg = "Bright White";
   if(align > 100 && align < 501) alignmsg = "White";
   if(align > -100 && align < 101) alignmsg = "Grey";
   if(align > -500 && align < -99) alignmsg = "Black";
   if(align < -499) alignmsg = "Jet Black";
   if(!spmsg) spmsg = "Unknown";
  TE(meat,"A scanning beam passes through your body.\n");
   write("BEGINNING SCANNING PROCESS...\n\n"+
         "--POWER:       "+powermsg+"\n"+
         "--TOUGHNESS:   "+tmsg+"\n"+
         "--ARMOR:       "+acmsg+"\n"+
         "--WEAPON:      "+wcmsg+"\n"+
         "--EXP VALUE:   "+levmsg+"\n\n"+
         "--BODY DAMAGE: "+wearmsg+"\n"+
         "--ENERGY:      "+spmsg+"\n\n"+
         "--ALIGNMENT:   "+alignmsg+"\n\n"+
         "SCANNING COMPLETE.\n");
  return 1;
}

matter_burn() {
  object meat;
  int mhp, hps;
  int damage, snum;
  hps = TP->query_hp();
  snum = TP->query_attrib("str");
  if(hps < 60) {
    write("The matter converter shuts down before critical damage is done.\n");
    return 1;
  }
  if(TP->query_sp() < 1) {
    write("You lack the energy to power the converter.\n");
    return 1; }
  damage = IP(TP)->guild_lev() + random(snum);
  TR(environment(TP),"***>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  write("You overload your matter converter!\n"+
        "Intense, burning pain rips through your musculature!\n");
  TR(environment(TP),TP->query_name()+" crumples in agony!\n");
  if(!TP->query_attack() ||
    (environment(TP->query_attack()) != environment(TP)) ) {
    TP->add_hit_point(-random(damage));
  TR(environment(TP),"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");
    return 1;
  }
  meat = TP->query_attack();
  if(!meat->is_player() || check_location(TP,meat)) {
  write("You channel some excess energy into "+meat->query_name()+"!\n");
TR(environment(TP),"Matter energy crashes into "+meat->query_name()+"!\n");
  meat->hit_player(random(damage*2));
  TP->add_hit_point(-damage);
  TP->add_spell_point(-random(damage));
  }
  if(snum > 10) {
    if(random(snum*5) == 1) {
      write("The conversion overload resulted in permanent damage!\n");
      call_other(TP,"add_attrib","str",-1);
    }
  }
  TR(environment(TP),"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<***\n");
  return 1;
}

meta_conversion() {
  if(IP(TP)->query_digest()) {
    write("Metabolic amelioration stopped.\n");
    IP(TP)->set_digest(0);
    return 1;
  }
  write("Metabolic amelioration begun.\n");
  IP(TP)->set_digest(1);
  call_out("digestion",10,TP);
  return 1;
}

digestion(object ob) {
  int INUM, in, st;
  int SNUM;
  st = ob->query_stuffed();
  in = ob->query_intoxination();
  INUM = (in * 10) / (ob->query_level() + 3);
  SNUM = (st * 10)/(ob->query_level() * 8);
  if(!IP(ob)->query_digest()) return 1;
  if(INUM > 7) call_out("digestion",10,ob);
  else call_out("digestion",15,ob);
  if(ob->query_spell_point() < 1) return 1;
  if(in > 1) {
    ob->add_intoxination(-1);
    ob->heal_self(2);
  }
  if(st > 2) {
    ob->add_stuffed(-2);
  }
  if(!in && !st) {
    TE(ob,"No matter to metabolize.\n");
    IP(ob)->set_digest(0);
    return 1;
  }
  ob->add_spell_point(-1);
  return 1;
}

weapon() {
/* gives a player their ninja weapon */
  int currentwep, artcost;
  string wepmaster;
  wepmaster = "/players/snow/closed/cyber/rooms/weaponry.c";
  currentwep = IP(TP)->query_weapon();
  if(!currentwep) {
    write("You do not have a weapon in the first place.\n");
    return;}
  if(! (wepmaster->isAweapon(currentwep)) ) {
    write("Your weapon does not exist.\n");
    return;}
  if(TP->query_spell_point() < 40) {
    write("You try to retrieve your weapon from cyberspace.\n");
    write("However, you are too low in energy.\n");
    return;}
  if(present("nwep",TP)) {
    write("You already have a weapon.\n");
  return 1;
  }
  call_other(TP, "add_spell_point", -40);
  currentwep = (wepmaster->findGoodNameForWeapon(currentwep));
  wepmaster->get_weapon(currentwep);
  write("You draw a "+currentwep+" out from cyberspace.\n");
  say(TPN+" draws a "+currentwep+" out from cyberspace.\n");
}
