#include "/players/pathfinder/closed/esc.h"
#define TP this_player()
#define TO this_object()
#define ENVTO this_object()
#define ENVTP environment(this_player())
#define QRN query_real_name()
#define RN this_player()->query_real_name()
#define CAP capitalize
#define BOLD "[1m"
#define NOSTYLE "[0m"
#define ENV environment
#define BLACK_ORB "/players/pathfinder/closed/shadow/obj/black_orb.c"
#define HELPPATH "/players/pathfinder/closed/shadow/help/"
 
int sh_xp, sh_lev, sh_pts, muffled, drain_damage, summon;
object ob;
 
/*  Normal guild functions -- like talk and emote and such.  
    9/30/94
*/
 
guild_echo(str) {
  object people, mark;
  int n;
  people = users();
  for(n = 0; n < sizeof(people); n++) {
    mark = present("shadow-mark",people[n]);
    if(mark && mark->query_muffled() == 0) {
      tell_object(people[n],str);
      }
    }
  return 1;
}
 
guild_tell(str) {
  string mesg;
  if(!str) { tell_object(TP,"Shadow tell what?\n"); return 1; }
  mesg = "<"+CAP(TP->query_name())+"> "+str+"\n";
  guild_echo(mesg);
  return 1;
}
 
guild_emote(str) {
  string mesg;
  if(!str) { tell_object(TP,"Shadow emote what?\n"); return 1; }
  mesg = "<> "+CAP(TP->query_name())+" "+str+"\n";
  guild_echo(mesg);
  return 1;
}
 
guild_who() {
  object people, mark;
  int n, i;
  string mesg;
  people = users();
  n = i = 0;
  
tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
tell_object(TP,"Name\t\tRank\tLocation\n");
tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  for(n = 0; n < sizeof(people); n++) {
    mark = present("shadow-mark", people[n]);
    if(mark && (!(people[n]->query_invis() > 18))) {
  
      if(strlen(people[n]->QRN) < 8) mesg = CAP(people[n]->QRN)+"\t\t";
      else mesg = CAP(people[n]->QRN)+"\t";
      mesg += mark->query_shlevel()+"\t";
      mesg += environment(people[n])->short() + "\n";
      tell_object(TP,mesg);
      i++;
      }
    }
  tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  tell_object(TP,"There are "+i+" Shadows logged in.\n");
  tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}

/* Other Who, for doing a who of everyone logged in */
 
other_who() {
  object *people, who;
  int n, i;
  string mesg, temp;
  string envt;
  
  people = users();
  n = i = 0;
tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
tell_object(TP,"Name\t\tLevel\tGuild\t\tLocation\n");
tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  for(n = 0; n < sizeof(people); n++) {
    if((people[n]->query_invis() < 18) && (people[n]->query_name()) &&
      (ENV(people[n])) && (people[n]->query_level() > 0)) {
      if(strlen(people[n]->QRN) < 8) {
        mesg = CAP(people[n]->QRN) + "\t\t";
      } else {
        mesg = CAP(people[n]->QRN) + "\t";
        }
      mesg += people[n]->query_level() + "\t";
      temp = people[n]->query_guild_name();
      if(!temp) {
        mesg += "None\t";
      } else {
        if(strlen(temp) < 8) { mesg += CAP(temp) + "\t"; }
        else { mesg += CAP(temp); }
      }
        mesg += "\t";
    if(!ENV(people[n])->short()) { envt = "Location Unknown\n"; }
      else { envt = ENV(people[n])->short() + "\n"; }
      mesg += envt;
      tell_object(TP,mesg);
      i++;
      }
    }
  tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  tell_object(TP,"There are "+i+" People logged into Nirvana.\n");
  tell_object(TP,
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}
     

/* Speak so only Shadows can hear it and understand it */
 
shadow_speak(str) {
  object ob;
  ob = first_inventory(ENVTP);
  while(ob) {
    if(present("shadow-mark",ob) && ob != TP)
      tell_object(ob, CAP(TP->QRN)+" shadow speaks: "+str+"\n");
    else if(ob != TP) tell_object(ob,"You see the shadows move as the "+
      "shadows listen intently.\n");
    ob = next_inventory(ob);
   }
  write("You shadow speak: "+str+"\n");
  return 1;
}
    

 
/* General all-purpose emote */
 
emote_me(str) {
  if(!str) { tell_object(TP,"Emote What?\n"); return 1; }
  tell_room(environment(TP),CAP(RN)+" "+str+"\n");
  return 1;
}
 
/* Status Line for the Shadow Monitor */
 
shadow_monitor() {
  object att, me, mark;
  int msp, mhp, sp, hp, intox, oppsh, ohp, omhp;
  int maxshp, shp;
  string mesg;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  msp = TP->query_msp();
  mhp = TP->query_mhp();
  sp = TP->query_sp();
  hp = TP->query_hp();
  maxshp = 5 * mark->query_shlevel();
  shp = mark->query_shpts();
  intox = TP->query_intox();
  mesg = "<hp> ["+hp+"/"+mhp+"] <sp> ["+sp+"/"+msp+"] <shpts> ["+shp+"/"+maxshp+"] <intox> ["+intox+"/"+(3*TP->query_level())+"]";
  if(TP->query_attack()) {
    att = TP->query_attack();
    if(att) {
      ohp = att->query_hp();
      omhp = att->query_mhp();
      if(ohp && omhp) {
      mesg += " <opp> [";
        if(ohp < (omhp/10)) {
          mesg += "VBS]";
          }
        else if(ohp < (omhp/5)) {
          mesg += "BS]";
          }
        else if(ohp < (omhp/2)) {
          mesg += "SWH]";
          }
        else if(ohp < (omhp - 20)) {
          mesg += "SLH]";
          }
        else {
          mesg += "GS]";
          }
        }
      }
    }
  mesg += "\n";
  tell_object(TP,mesg);
  return;
}

/* Banish a shadow from the guild Guild Commanders only! */

banish_shadow(str) {
  object who, mark;
  if(!str) { tell_object(TP,"Usage: bansh <who>\n"); return 1; }
  who = find_living(str);
  if(!who) { tell_object(TP,CAP(str)+" is not around.\n"); return 1; }
  mark = present("shadow-mark",who);
  if(!mark){tell_object(TP,CAP(str)+" is not a Shadow!\n");
    return 1;
  }
  tell_object(who,"You have been banished from the shadows by "+CAP(TP->QRN)+"\n");
  tell_object(TP,"You have banished "+CAP(str)+" from the shadows\n");
  tell_object(who,"If you would like your mark back please mail Pathfinder\n");
  mark->revoke_me();
  return 1;
}
 
empty_corpse(str) {
   int heal;
   object corpse;
   if(str) return;
   corpse = present("corpse", ENV(TP));
   if(!corpse) {
      write("There is no corpse here.\n");
      return 1;
   }
   heal = corpse->heal_value();
   if(!heal) heal = 5;
   destruct(present("corpse",ENVTP));
   TP->heal_self(heal);
   tell_object(TP,"You empty the corpse of its remaining energy.\n");
  tell_room(ENVTP,CAP(TP->QRN)+" lets their shadow fall over the corpse.\n");
   tell_room(ENV(TP),"It shrivels into dust and scatters.\n");
   return 1;
}
 
/* Set the players Drain Damage */
 
drain_damage(str) {
  object me, mark;
  int amt;
  me = find_living(TP->QRN);
  mark = present("shadow-mark", me);
  if(!str) {
    tell_object(TP,"Usage: dd <amt>\n");
    return 1;
    }
  if((!sscanf(str,"%d",amt)) == 1) return;
  if(amt < 0) { tell_object(TP,"You can't have a negative drain!\n"); return 1; }
  if(((amt > (mark->query_shlevel() * 6)) || (amt > 50)) && (me->query_level() < 20)) {
    tell_object(TP,"You can only drain up to "+(mark->query_shlevel() * 6)+" points.\n");
    return 1;
    }
  mark->set_drain_damage(amt);
  tell_object(TP,"Drain Damage set at: "+mark->query_drain_damage()+"\n");
  return 1;
}

update_follow(str) {
  object who;
  who = find_living(str);
  tell_object(TP,"You follow "+CAP(str)+"\n");
  move_object(TP,ENV(who));
  tell_room(ENV(TP),CAP(TP->QRN)+" arrives following in the shadow of "+CAP(str)+"\n");
  command("look",TP);
  return 1;
}


/* Muffle For Shadows */

muffle_shadow(str) {
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark", me);
  if(!str) { tell_object(TP,"Usage: muffsh <on/off/stat>\n"); return 1; }
  if(str == "on") {
    if(mark->query_muffled() == 1) {
      tell_object(TP,"You are already muffled.\n");
      return 1;
      }
    tell_object(TP,"You are now muffled\n");
    mark->set_muffled(1);
    return 1;
    }
  if(str == "off") {
    if(mark->query_muffled() == 0) {
      tell_object(TP,"You are already NOT muffled.\n");
      return 1;
      }
    tell_object(TP,"You are now NOT muffled.\n");
    mark->set_muffled(0);
    return 1;
    }
  if(str == "stat") {
    if(mark->query_muffled() == 0) {
    tell_object(TP,"You are NOT muffled.\n");
    return 1;
    }
    tell_object(TP,"You are muffled.\n");
    return 1;
    }
  tell_object(TP,"Usage: muffsh <on/off/stat>\n");
  return 1;
}
 
/* Let a GC peek at another guild members stats */

stat_shadow(str) {
  object who, mark;
  if(!str) { tell_object(TP,"Usage: gstat <who>\n"); return 1; }
  who = find_player(str);
  if(!who) { tell_object(TP,CAP(str)+" isn't on.\n"); return 1; }
  mark = present("shadow-mark",who);
  if(!mark) { tell_object(TP,CAP(str)+" is not a Shadow!\n"); return 1; }
  tell_object(TP,
"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  tell_object(TP,"Name: "+CAP(who->query_real_name())+"\n");
  tell_object(TP,"\nShadow Level: "+mark->query_shlevel()+"\n");
  tell_object(TP,"Shadow Experience: "+mark->query_shxp()+"\n");
  tell_object(TP,"Shadow Points: "+mark->query_shpts()+"\n");
  tell_object(TP,"Drain Damage at: "+mark->query_drain_damage()+"\n");
  tell_object(TP,"Points Being Drained First: ");
  if(mark->query_pt_select() == 1) tell_object(TP,"Shadow points.\n");
  else tell_object(TP,"Spell Points.\n");
  tell_object(TP,"\n");
  tell_object(TP,
"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}

/* Lets a player change their startup location  from the church
  to the guild hall and back */

change_startup(str) {
    if(!str) { tell_object(TP,"Usage: startme <church/hall>\n"); return 1; }
  if(str == "hall") { TP->set_home("/players/pathfinder/closed/shadow/rooms/meeting"); return 1; }
  if(str == "church") { TP->set_home("/room/church"); return 1; }
  return 1;
}

/* Lets a player call in a shadowy darkness to fill a room and make it dark */
 
call_darkness() {
  object room, dark;
  if(!less_pts(20)) { tell_object(TP,"You need more points\n"); return 1; }
  room = ENVTP;
  room->set_light(-1);
  tell_object(TP,"You call upon your shadowy soul to come fill the room.\n");
  tell_room(room,"You feel the light fading as a shadowy darkness fills the room.\n");
  dark = clone_object("/players/pathfinder/closed/shadow/items/darkness.c");
  move_object(dark, room);
  return 1;
}

/* Determine the Alignment of the monster */

check_alignment(str) {
  object monster;
  if(!str) { tell_object(TP,"Who do you want to check?\n");
    return 1; }
  monster = find_living(str);
  if(!monster) { tell_object(TP,CAP(str)+" is not on the mud.\n");
    return 1;
    }
  if(!present(monster,ENVTP)) { tell_object(TP,CAP(str)+" is not present!\n");
    return 1;
    }
  if(!less_pts(5)) return 1;
  tell_object(TP,CAP(str)+"'s alignment is: "+monster->query_alignment()+"\n");
  return 1;
}
/* Guild Status line */

guild_stat() {
   object me, mark;
   me = find_living(TP->QRN);
   mark = present("shadow-mark",me);
   tell_object(TP,TP->short()+"\n");
  tell_object(TP,"<>Level: "+TP->query_level()+"\t\t\t<>Extra Level: "+TP->query_extra_level()+"\n");
   tell_object(TP,"<>Hit Points: "+TP->query_hp()+"/"+TP->query_mhp()+"\t\t<>Experience: "+
            TP->query_exp()+"\n");
   tell_object(TP,"<>Spell Points: "+TP->query_sp()+"/"+TP->query_msp()+"\t\t<>Shadow Experience: "+mark->query_shxp()+"\n");
  tell_object(TP,"<>Armor Class: "+TP->query_ac()+"\n");
   tell_object(TP,"<>Alignment: "+TP->query_alignment()+"\n");
   tell_object(TP,"<>Shadow Points: "+mark->query_shpts()+"\t\t<>Shadow level: "+mark->query_shlevel()+"\n");
   tell_object(TP,"<>Gold: "+TP->query_money()+"\t\t\t<>Quest points: "+TP->query_quest_point()+"\n");
   tell_object(TP,"Unspent XPs: "+
   call_other(BLACK_ORB, "get_free"));
   tell_object(TP,"\n\n");
   if(mark->query_muffled() == 1) tell_object(TP,"You are muffled.\n");
      else tell_object(TP,"You are not muffled.\n");
   if(mark->query_points() == 0) tell_object(TP,"Spell points being drained first.\n");
    else tell_object(TP,"Shadow Points being drained first.\n");
    if(mark->query_summon() == 0) tell_object(TP,"Not allowing summons.\n");
    else tell_object(TP,"Allowing summons.\n");
   tell_object(TP,"Drain doing "+mark->query_drain_damage()+" points of damage.\n");
   return 1;
}

 
review_title() {
  object mark;
  mark = present("shadow-mark", TP);
  write("Login Message: "+mark->query_in());
  write("Logout Message: "+mark->query_out());
  return 1;
}
/* Sets their availability to be summoned, or to be jumped to */
 
toggle_summon(str) {
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark", me);
  if(!str) { tell_object(TP,"Usage: tsum <on/off/stat>\n"); return 1; }
  if(str == "on") {
    if(mark->query_summon() == 1) {
      tell_object(TP,"You can already summon or be summoned!\n");
      return 1;
      }
    mark->set_summon(1);
    tell_object(TP,"Summon now set, people can summon you and you can summon players.\n");
    return 1;
    }
  if(str == "off") {
    if(mark->query_summon() == 0) {
      tell_object(TP,"Your summon is already off.\n");
      return 1;
      }
    mark->set_summon(0);
    tell_object(TP,"Your summon is now off.\n");
    return 1;
    }
  if(str == "stat") {
    if(mark->query_summon() == 1) {
      tell_object(TP,"Your summon is set.\n");
      return 1;
    } else {
      tell_object(TP,"Your summon is not set.\n");
      return 1;
      }
    }
  return 1;
}

set_title_player(str) { 
  TP->set_title(str);
  return 1;
}

set_gc_title() {
  TP->set_title("the Grandmaster of the Shadows");
  return 1;
}
 
/*  Basic Commander functions....  tell, who, emote  
    10/1/94 
*/
 
commander_echo(str) {
  object people, comm;
  int n;
  people = users();
  for(n = 0; n < sizeof(people); n++) {
    comm = present("shadow-mark", people[n]);
    if(comm && comm->query_shlevel() > 8 && comm->query_muffled() == 0) {
      tell_object(people[n], str);
      }
    }
  return 1;
}
 
commander_talk(str) { 
  string mesg;
  mesg = "<c>"+CAP(RN)+"<> "+str+"\n";
  commander_echo(mesg);
  return 1;
}
 
commander_emote(str) {
  string mesg;
  mesg = "<c>"+CAP(RN)+" "+str+"\n";
  commander_echo(mesg);
  return 1;
}

/* Force a shadow to update his/her mark */

force_update(str) {
  object who, mark;
  if(!str) { tell_object(TP,"Usage: upd <who>\n"); return 1; }
  who = find_living(str);
  if(!who || !present("shadow-mark",who)) {
    tell_object(TP,CAP(str)+" is not a shadow or NOT on the mud!\n");
    return 1;
    }
  tell_object(who,"A guild commander has updated your mark.\n");
  tell_object(TP,"You updated "+CAP(str)+"'s mark.\n");
  command("update_me",who);
  return 1;
}

hand_mark(str) {
  object who, mark;
  if(!str) { tell_object(TP,"Usage: mark <who>\n"); return 1; }
  who = find_living(str);
  if(!present(who,ENVTP) || !who) {
    tell_object(TP,"They aren't present or NOT on the mud.\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/shadow");
  move_object(mark,who);
  tell_object(who,"You have been given a Shadow mark.\n");
  tell_object(TP,"You have given a Shadow mark to "+CAP(str)+"\n");
  return 1;
}

/* Promotes a shadow */
promote_shadow(str) {
  object who, mark;
  string player;
  int level, oldgxp, newgxp;
  if(!str) { tell_object(TP,"Usage: promote <who> <level>\n"); return 1; }
  if((!sscanf(str,"%s %d",player,level)) == 2) return 0;
  who = find_living(player);
  if(!who) { tell_object(TP,CAP(player)+" is not on the mud!\n"); return 1; }
  mark = present("shadow-mark", who);
  if(!mark) {
    tell_object(TP,CAP(player)+" isn't a Shadow!\n");
    return 1;
    }
  if(level < 0) { tell_object(TP,"You can't promote someone to a negative level!\n"); return 1; }
  oldgxp = mark->query_shxp();
  if(level < 9)
{
  newgxp = BLACK_ORB->cost_at_level(level);
} else { newgxp = 6900000; }
  mark->set_shxp(-oldgxp);
  mark->set_shxp(newgxp);
  mark->set_shlevel(level);
  tell_object(who,"You have been promoted to rank "+level+" by "+CAP(RN)+"\n");
  tell_object(TP,"You promoted "+CAP(player)+" to rank "+level+"\n");
  write_file("/players/pathfinder/closed/shadow/logs/promo.log",
    CAP(RN)+" promoted "+CAP(player)+" to level "+level+"\n");
  return 1;
}
 
/* adds guild xps to a shadow */
 
add_shadow_xp(str) {
  object who, mark;
  int oldgxp, amt;
  string player;
  if(!str) {
    tell_object(TP,"Usage: agxp <player> <amt>\n");
    return 1;
    }
  if((!sscanf(str,"%s %d",player,amt)) == 2) return;
  ob = find_player(player);
  if(!player) { tell_object(TP,"I could not find "+CAP(player)+" on here.\n"); return 1; }
  mark = present("shadow-mark",ob);
  if(!mark) { tell_object(TP,CAP(player)+" is not a Shadow\n"); return 1; }
  oldgxp = mark->query_shxp();
  mark->set_shxp(amt + oldgxp);
  tell_object(mark,"You feel more experienced.\n");
  tell_object(TP,"You give "+CAP(player)+" gxps for a total of "+amt+oldgxp+"\n");
  write_file("/players/pathfinder/closed/shadow/logs/xp.log",CAP(RN)+ " gave "+CAP(player)+" "+amt+" gxps for a total of "+amt+oldgxp+"\n");
  return 1;
}

/* get a pair of shadow shadez */

get_shadez() {
  object shadez;
  shadez =clone_object("/players/pathfinder/closed/shadow/shades.c");
  if(!less_pts(10)) return 0;
  tell_object(TP,"You focus your darkness onto your hand and a pair of shades apear.\n");
  tell_room(ENV(TP),CAP(TP->QRN)+" focus's their attention upon their hand and a pair of shades appear.\n");
  move_object(shadez,TP);
  return 1;
}
 
information(str) {
   int lines;
   object me, mark;
   string file;
   me = find_living(TP->QRN);
   mark = present("shadow-mark",me);
   if(mark->query_shlevel() > 8 && str == "gc") {
   file = HELPPATH + str;
   } else if(mark->query_shlevel() < 9 && str == "gc") { return; }
   file = HELPPATH+str;
   if(!read_file(file)) {
      write("No info on '"+str+"'.\n");
      return 1;
   }
   lines = sizeof(explode(read_file(file), "\n"));
   if(!lines) {
      write("No info found on "+str+".\n");
      return 1;
   }
   write(read_file(file, 1,lines)+"\n");
   return 1;
}

 
/*
// Spells as of 10-1-94
// Mike K(pathfinder)
*/
 
/* Drain life from a monster */
 
drain_monster(str) {
  object monster, me, mark;
  int dam;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  if(!str && (!TP->query_attack())) { tell_object(TP,"Who do you want to attack?\n"); return 1; }
  else if(TP->query_attack() && !str) { str = (TP->query_attack())->query_real_name(); }
  if(find_player(str)) { tell_object(TP,"You cannot attack players!\n"); return 1; }
  else monster = find_living(str);
  if(!monster) return 1;
  if(!present(monster,ENVTP)) {
    tell_object(TP,CAP(str)+" isn't present!\n");
    return 1;
    }
/* add check, coded at 4 am by mizan */
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
/* end */
  str = monster->query_name();
  dam = mark->query_drain_damage();
  if(!less_pts(dam)) return;
  TP->spell_object(monster,"drain",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  tell_object(TP,"You cast your shadow upon "+CAP(str)+" draining its life away.\n");
  tell_room(ENVTP,CAP(TP->QRN)+" casts a shadow upon "+CAP(str)+" draining its life away.\n");
  return 1;
}
 
/* Change hit points to spell points */
 
transfer_hp_to_sp(str) {
  int hps, sps, amt;
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  if(mark->query_shlev() < 5) return;
  if(!str) { tell_object(TP,"Usage: pheal <amt>\n"); return 1;
    }
  if((!sscanf(str,"%d",amt)) == 1) return 1;
  hps = TP->query_hp();
  sps = TP->query_sp();
  if(amt > hps) { tell_object(TP,"You don't have enough hit points!\n"); return 1; }
  TP->add_spell_point(amt);
  TP->add_hit_point(-amt);
  tell_object(TP,"You can feel your shadow grow stronger as your body grows weaker.\n");
  tell_room(ENVTP,"You see "+CAP(RN)+"'s shadow grow stronger as their physical self grows weak.\n");
  return 1;
}
 
/* change spell points to hit points */
 
transfer_sp_to_hp(str){
  int hps, sps, amt;
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  if(mark->query_shlev() < 3) return;
  if(!str) { tell_object(TP,"Usage: mheal <amt>\n"); return 1; }
  if((!sscanf(str,"%d",amt)) == 1) return 1;
  hps = TP->query_hp();
  sps = TP->query_sp();
  if(amt > sps) { tell_object(TP,"You don't have enough spell points!\n"); return 1; }
  TP->add_hit_point(amt);
  TP->add_spell_point(-amt);
  tell_object(TP,"You can feel your shadow grow weaker as your body grows stronger.\n");
  tell_room(ENVTP,"You see "+CAP(RN)+"'s shadow grow weaker as their physical self grows stronger.\n");
  return 1;
}
 
/* change between spell points and shadow points */
 
transfer_sp_shp(str) {
  string type;
  object me, mark;
  int num, shp, sp;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  shp = mark->query_shpts();
  sp = TP->query_sp();
  if(!str) { tell_object(TP,"Usage: transfer <amt> <shp/sp>\n");
    return 1;
    }
  if((!sscanf(str,"%d %s",num,type)) == 2) return;
  if(num < 0) { tell_object(TP,"You can't transfer negative points!\n"); return 1; }
  if(type == "shp") {
    if(shp < num) { tell_object(TP,"You don't have enough Shadow Points!\n"); return 1; }
    shp -= num;
    TP->add_spell_point(num);
    mark->set_shpts(shp);
    tell_object(TP,"You enhance your magical skill at the expense of your shadow.\n");
    return 1;
    }
  if(type == "sp") {
    if(sp < num) { tell_object(TP,"You don't have enough Spell Points!\n"); return 1; }
    shp += num;
    mark->set_shpts(shp);
    TP->add_spell_point(-num);
    tell_object(TP,"You enhance your shadow at the expense of your magic skills.\n");
    return 1;
    }
  tell_object(TP,"Usage: transfer <amt> <shp/sp>\n");
  return 1;
}
 
/* Guild teleport to another guild member */
 
fade_to_player(str) {
  object who, me, mark, nshad;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  if(!str) { tell_object(TP,"Usage: fade <player>\n"); return 1; }
  who = find_player(str);
  if(!who) {
    tell_object(TP,"I could not find "+CAP(str)+" anywhere.\n");
    return 1;
    }
  if(!present("shadow-mark",who)) { tell_object(TP,CAP(str)+" isn't a Shadow!\n"); return 1; }
  nshad = present("shadow-mark",who);
  if((ENVTP->realm() == "NT") || (ENV(who)->realm() == "NT") || nshad->query_summon() == 0) {
    tell_object(TP,"You start to cast your shadow as you feel a force stopping you.\n");
    return 1;
    }
  if(!less_pts(65)) { tell_object(TP,"You don't have enough power!\n"); return 1; }
  tell_object(TP,"You cast your shadow upon the area which you stand and arrive\n");
  tell_object(TP,"next to your fellow Shadow.\n");
  tell_object(who,"You feel the presence of another Shadow enter the room.\n");
  move_object(TP,environment(who));
  return 1;
}
 
/* recruit new guild members */
recruit_shadow(str) {
  object who, mark;
  if(!str) { 
    tell_object(TP,capitalize(str)+" is not present!\n");
    return 1;
    }
  who = find_living(who);
  if(!present(who,ENVTP)) {
    tell_object(TP,capitalize(str)+" is not present!\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/items/recruit.c");
  move_object(mark, who);
  tell_object(TP,"You have recruited "+capitalize(str)+" and they may now join the guild.\n");
  return 1;
}
 
goto_guild() {
  if(!less_pts(20)) return 1;
  tell_object(TP,"You call upon your shadowy powers to fill the room with darkness.\n");
  tell_object(TP,"When the darkness clears you find yourself in the safety of the guild hall.\n");
  tell_room(ENVTP,"A Darkness fills the room.  When the darkness fades you notice\n");
  tell_room(ENVTP,CAP(RN)+" is gone.\n");
  move_object(TP,"/players/pathfinder/closed/shadow/rooms/meeting");
  tell_room(ENVTP,"The room fills with darkness and takes the shape of "+CAP(RN)+"\n");
  return 1;
}
 
/* Lowers the players spell or shadow points the appropriate amount */
/* so that the spells work right when passed only 0 sps to drain */
 
less_pts(str) {
  int amt, sps, shpts, hps;
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  sps = TP->query_sp();
  shpts = mark->query_shpts();
  hps = TP->query_hp();
  amt = str;
  if(TP->query_level() > 19) return 1;
  if(mark->query_pt_select() == 1) {
    if(shpts < amt) {
      if(sps < (amt - shpts)) {
        tell_object(TP,"You do not have enough points!\n");
        return 0;
      } else {
        mark->set_shpts(0);
        TP->add_spell_point(-(amt - shpts));
        return 1;
      }
    } else {
      mark->set_shpts((amt-shpts));
      return 1;
    }
  } else {
    if(sps < amt) {
      if(shpts < (amt - sps)) {
        tell_object(TP,"You do not have enough points!\n");
      return 0;
      } else {
        shpts -= (amt - sps);
        mark->set_shpts(shpts);
        TP->add_spell_point(-sps);
        return 1;
      }
    } else {
      TP->add_spell_point(-amt);
      return 1;
    }
  }
  return 0;
}
 
/* casts peace within a room */
 
peace_room() {
 object ob, me, mark;
 me = find_living(TP->QRN);
 mark = present("shadow-mark", me);
  if(mark->query_shlevel() < 3) { tell_object(TP,"You are not high enough rank yet\n"); return 1; }
 if(!less_pts(35)) { return 0; }
 ob=first_inventory(ENVTP);
   while (ob) {
     if (living(ob)) {
       if (ob->query_attack()) {
         (ob->query_attack())->stop_fight();
         ob->stop_fight();
         ob->set_aggressive(0);
         }
       }
     ob = next_inventory(ob);
     }
 
  tell_object(TP,"You raise your hands high into the air as a think cloud of shadows\n");
  tell_object(TP,"fill the room as the fighting stops.\n");
  tell_room(ENVTP,CAP(RN)+" raises their hands high into the air as shadows fill the room, making\n");
  tell_room(ENVTP,"it dark as all the fighting stops.\n");
  return 1;
}
 
heal_da_shadow() { 
  object heal, me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark", me);
  if(present("heal_object",TP)) { tell_object(TP,"You already are healing your shadow!\n"); return 1; }
  if(mark->query_shlevel() < 4) {
    tell_object(TP,"You can't cast this yet!\n");
    return 1; 
    }
  if(!less_pts(50)) {
    return 1;
    }
  if(TP->query_attack()) { 
    tell_object(TP,"You cannot cast this while in combat!\n");
    return 1;
    }
  tell_object(TP,"You have your shadow encompass your physical self as you begin\n");
  tell_object(TP,"to heal the wounds of your body and mind.\n");
  heal = clone_object("/players/pathfinder/closed/shadow/items/heal_obj");
  heal->set_healtime(mark->query_shlevel()*3);
  move_object(heal,TP);
  return 1;
}
/*
 
// new and improved forge spell  10-7-94
*/

 
forge_weapon(str) {
  object weap, me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark",me);
  if(!str) {
    tell_object(TP,"Usage: forge <weapon>\n");
    return 1; }
  if((str == "sword") && (less_pts(90)) && (mark->query_shlevel() > 6)) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/sword.c");
    tell_room(ENVTP,"A shadow is cast over the room as it goes dark.\n");
    tell_room(ENVTP,CAP(RN)+" pulls a sword from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  if((str == "blade") && (less_pts(70)) && (mark->query_shlevel() > 4)) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/blade.c");
    tell_room(ENVTP,"A shadow is cast over the room as it goes dark.\n");
    tell_room(ENVTP,CAP(RN)+" pulls a blade from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  if(str == "dagger" && less_pts(50) && mark->query_shlevel() > 2) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/dagger.c");
    tell_room(ENVTP,"A shadow is cast over the room as it goes dark.\n");
    tell_room(ENVTP,CAP(RN)+" pulls a dagger from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  return 1;
}
 
which_points(str) {
  object me, mark;
  me = find_living(TP->QRN);
  mark = present("shadow-mark", me);
  if(!str) {
    tell_object(TP,"Usage: points <sp/shp/stat>\n");
    return 1;
    }
  if(str == "shp") {
    mark->set_points(1);
    tell_object(TP,"Shadow points being drained first.\n");
    return 1;
    }
  if(str == "sp") {
    mark->set_points(0);
    tell_object(TP,"Spell points being drained first.\n");
    return 1;
    }
  if(str == "stat") {
    if(mark->query_points() == 1) {
      tell_object(TP,"Shadow Points being drained first.\n");
      return 1;
      }
    tell_object(TP,"Spell Points being drained first.\n");
    return 1;
    }
  return 1;
}
 
/*
// Servant commands  10-1-94
// MK (pathfinder)
*/

