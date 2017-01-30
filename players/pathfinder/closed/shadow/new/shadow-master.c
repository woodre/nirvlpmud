#include "/players/pathfinder/closed/esc.h"
#define TP this_player()
#define TO this_object()
#define ENVTO this_object()
#define ENVTP environment(this_player())
#define QRN query_real_name()
#define RN this_player()->query_real_name()
#define CAP capitalize
#define MARK present("shadow-mark",this_player())
#define BOLD ESC + "[1m"
#define NOSTYLE ESC + "[0m"
#define ENV environment
#define BLACK_ORB "/players/pathfinder/closed/shadow/obj/black_orb.c"
#define OLD_ORB "/players/blue/closed/shadow/obj/black_orb.c"
#define HELPPATH "/players/pathfinder/closed/shadow/help/"
#define POOL "/players/pathfinder/closed/shadow/items/sp_pool"
 
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
  if(!str) { write("Shadow tell what?\n"); return 1; }
  mesg = "[<"+BOLD+CAP(TP->query_name())+NOSTYLE+">] "+str+"\n";
  guild_echo(mesg);
  return 1;
}
 
guild_emote(str) {
  string mesg;
  if(!str) { write("Shadow emote what?\n"); return 1; }
  mesg = "[*]> "+BOLD+CAP(TP->query_name())+NOSTYLE+" "+str+"\n";
  guild_echo(mesg);
  return 1;
}
 
guild_who() {
  object people, mark;
  int n, i;
  string mesg;
  people = users();
  n = i = 0;
 
write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
write("Name\t\tRank\tLocation\n");
write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  for(n = 0; n < sizeof(people); n++) {
    mark = present("shadow-mark", people[n]);
    if(mark && (!(people[n]->query_invis() > 18))) {
 
      if(strlen(people[n]->QRN) < 8) mesg = CAP(people[n]->QRN)+"\t\t";
      else mesg = CAP(people[n]->QRN)+"\t";
      mesg += people[n]->query_guild_rank()+"\t";
      mesg += environment(people[n])->short() + "\n";
      write(mesg);
      i++;
      }
    }
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  write("There are "+i+" Shadows logged in.\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}
pk_who() {
  object who;
  int i, j;
  string mesg;
        
  who = users();
  j = 0;
  
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
);
  write("\t\t\tPK Who\n");
  write("Name\t\tLevel\tGuild\t\tLocation\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
); 
    
  for(i = 0; i < sizeof(who); i++)
  {
    if(who[i]->query_pl_k() && (who[i]->query_invis() == 0) &&
       ENV(who[i]))
    {
      if(strlen(who[i]->query_real_name()) < 8)
      {
        mesg = CAP(who[i]->query_real_name()) + "\t\t";
      }   
      else
      {
        mesg = CAP(who[i]->query_real_name()) + "\t";
      }
      mesg += who[i]->query_level() + "\t";
      if(!who[i]->query_guild_name())
      {
        mesg += "None\t\t";

      }
      else
      {
        mesg += who[i]->query_guild_name() + "\t\t";
      }
      if(!ENV(who[i])->short())
      {
        mesg += "Location Unknown";
      }
      else
      {
        mesg += ENV(who[i])->short();
      }
      write(mesg + "\n");
      j++;
    }
  }
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
);
  write("Total PKers on: " + j + ".\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
);
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
write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
write("Name\t\tLevel\tGuild\t\tLocation\n");
write(
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
      write(mesg);
      i++;
      }
    }
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  write("There are "+i+" People logged into Nirvana.\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}
 
/* Sets the Shadow's monitor to attack or a certain level */
 
set_shadow_monitor(str) {
  int monitor;
  monitor = MARK->query_monitor();
  if(str == "attack") {
    MARK->set_monitor(-1);
    MARK->clear_mon_count();
    write("Monitor set to attack.\n");
    MARK->heart_me();
    return 1;
    }
  if(!str) {
    MARK->set_monitor(0);
    MARK->clear_mon_count();
    return 1;
    }
  if(!str || !sscanf(str,"%d",monitor)) {
    write("usage: shp <num/attack>.\n");
    return 1;
    }
  if(!monitor || monitor == 0) {
  write("Monitor is off.\n");
    MARK->set_monitor(0);
    MARK->clear_mon_count();
    return 1;
    }
  write("Monitor time set to "+monitor+"\n");
  MARK->set_monitor(monitor);
  MARK->heart_me();
  return 1;
}
 
/* Status Line for the Shadow Monitor */
 
shadow_monitor(obj) {
  object att, mark;
  int msp, mhp, sp, hp, intox, oppsh, ohp, omhp, shp, mshp;
  int stuff, soak;
  string mesg;
  mark = present("shadow-mark",obj);
  msp = obj->query_msp();
  mhp = obj->query_mhp();
  sp = obj->query_sp();
  hp = obj->query_hp();
  intox = obj->query_intoxination();
  stuff = obj->query_stuffed();
  soak = obj->query_soaked();
  mesg = " ";
  if(obj->query_attack()) {
   if(((obj->query_attack())->query_attack())->query_real_name() == obj->QRN) {
    mesg += BOLD;
   }
  }
  mesg += "<hp> ["+hp+"/"+mhp+"] ";
  if(obj->query_attack()) {
   if(((obj->query_attack())->query_attack())->query_real_name() == obj->QRN) {
    mesg += NOSTYLE;
   }
  }
  mesg += "<sp> ["+sp+"/"+msp+"] ";
  if(intox > 0) mesg += "<intox> ["+intox+"] ";
  if(stuff > 0) mesg += "<stuffed> ["+stuff+"] ";
  if(soak > 0) mesg += "<soak> ["+soak+"]";
  if(obj->query_attack()) {
    att = obj->query_attack();
    if(att) {
      mesg += " <opp> [";
      ohp = att->query_hp();
      omhp = att->query_mhp();
      if(ohp && omhp) {
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
  tell_object(obj,mesg);
  return 1;
}
 

/* Speak so only Shadows can hear it and understand it */
 
shadow_speak(str) {
  object ob;
  ob = first_inventory(ENVTP);
  while(ob) {
    if(present("shadow-mark",ob) && ob != TP)
      tell_object(ob, CAP(TP->QRN)+" shadow speaks: "+str+"\n");
    else if(ob != TP) tell_object(ob,"You see the shadows move as they "+
      "listen intently.\n");
    ob = next_inventory(ob);
   }
  write("You shadow speak: "+str+"\n");
  return 1;
}
 
/* General all-purpose emote */
 
emote_me(str) {
  if(!str) { write("Emote What?\n"); return 1; }
  tell_room(environment(TP),CAP(RN)+" "+str+"\n");
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
   if(!heal) heal = 10;
   destruct(present("corpse",ENVTP));
   TP->heal_self(heal);
   write("You empty the corpse of its remaining energy.\n");
   say(CAP(TP->QRN)+" lets their shadow fall over the corpse.\n");
   tell_room(ENV(TP),"It shrivels into dust and scatters.\n");
   return 1;
}
 
/* Set the players Drain Damage */
 
drain_damage(str) {
  int amt;
  if(!str) {
    write("Usage: dd <amt>\n");
    return 1;
    }
  if((!sscanf(str,"%d",amt)) == 1) return;
  if(amt < 0) { write("You cannot have a negative drain!\n");
    return 1;
  }
 
  if(((amt > (TP->query_guild_rank() * 6)) || (amt > 50)) &&
      (TP->query_level() < 20)) {
    write("You can only drain up to "+(TP->query_guild_rank() * 6)+
                   " points.\n");
    return 1;
    }
  MARK->set_drain_damage(amt);
  write("Drain Damage set at: "+MARK->query_drain_damage()+"\n");
  return 1;
}
 
/* Who to follow? */
 
follow_who(str) {
  object who;
  if(!str) {
    write("Usage: follow <player/off>.\n");
    return 1;
    }
  if(str == "off") {
    write("You are now following no one.\n");
    MARK->set_follow(0);
    return 1;
    }
  who = find_living(str);
  if(!who) {
    write("Can't find "+CAP(str)+" on the game.\n");
    return 1;
    }
  if(!present(who,ENV(TP))) {
    write(CAP(str)+" isn't present.\n");
    return 1;
    }
  if(who->query_level() > 20) {
    write("You can't follow wizards.\n");
    return 1;
    }
  if(who->query_ghost()) {
    write("You can't follow a ghost.\n");
    return 1;
    }
  if(!less_pts(20)) {
   write("You don't have enough energy.\n");
   return 1;
   }
  tell_object(who,"You are being followed by "+CAP(RN)+".\n");
  write("You now follow "+CAP(str)+".\n");
  MARK->set_follow(who);
  MARK->heart_me();
  return 1;
}
 
/* Update the follow */
 
update_follow(obj) {
  object mark;
  mark = present("shadow-mark", obj);
  tell_object(obj,"You follow "+CAP((mark->query_follow())->query_name())+"\n");
  move_object(obj, ENV(mark->query_follow()));
  say(CAP(obj->query_name())+" stealthily enters the room following behind "+
      CAP((mark->query_follow())->query_name())+".\n");
  command("look",obj);
  return 1;
}
 
/* Muffle For Shadows */
 
muffle_shadow(str) {
  if(!str) { write("Usage: muffsh <on/off/stat>\n"); return 1; }
  if(str == "on") {
    if(MARK->query_muffled() == 1) {
      write("You are already muffled.\n");
      return 1;
      }
    write("You are now muffled\n");
    MARK->set_muffled(1);
    return 1;
    }
  if(str == "off") {
    if(MARK->query_muffled() == 0) {
      write("You are already NOT muffled.\n");
      return 1;
      }
    write("You are now NOT muffled.\n");
    MARK->set_muffled(0);
    return 1;
    }
  if(str == "stat") {
    if(MARK->query_muffled() == 0) {
    write("You are NOT muffled.\n");
    return 1;
    }
    write("You are muffled.\n");
    return 1;
    }
  write("Usage: muffsh <on/off/stat>\n");
  return 1;
}
 
/* Let a GC peek at another guild members stats */
 
stat_shadow(str) {
  object who, mark;
  if(!str) { write("Usage: gstat <who>\n"); return 1; }
  who = find_player(str);
  if(!who) { write(CAP(str)+" isn't on.\n"); return 1; }
  mark = present("shadow-mark",who);
  if(!mark) { write(CAP(str)+" is not a Shadow!\n"); return 1; }
  write(
"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  write("Name: "+CAP(who->query_real_name())+"\n");
  write("\nShadow Level: "+who->query_guild_rank()+"\n");
  write("Shadow Experience: "+who->query_guild_exp()+"\n");
  write("Shadow Points: "+mark->query_shpts()+"\n");
  write("Drain Damage at: "+mark->query_drain_damage()+"\n");
  write("Points Being Drained First: ");
  if(mark->query_pt_select() == 1) write("Shadow points.\n");
  else write("Spell Points.\n");
  write("\n");
  write(
"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  return 1;
}
 
/* Lets a player change their startup location  from the church
  to the guild hall and back */
 
change_startup(str) {
  if(!str) { write("Usage: startme <church/hall>\n"); return 1; }
  if(str == "hall") { 
    TP->set_home("/players/pathfinder/closed/shadow/rooms/meeting");
    return 1;
    }
  if(str == "church") { TP->set_home("/room/church"); return 1; }
  return 1;
}
 
/* Lets a player call in a shadowy darkness to fill a room and make it dark */
 
call_darkness() {
  object room, dark;
  string dummy;
  if(sscanf(file_name(ENVTP), "room/%s", dummy)) {
    write("You cannot cast that spell in this room!\n");
    return 1;
  }
  if(!MARK->query_light()) {
    write("You can't cast a darkness in a dark room!\n");
    return 1;
  }
  room = ENVTP;
  if(present("darknessobject",ENVTP)) {
    write("There is already a Darkness present!\n");
    return 1;
  }
  if(!less_pts(20)) { return 0; }
  write("You call upon your shadowy soul to come fill the room.\n");
  tell_room(room,
    "You feel the light fading as a shadowy darkness fills the room.\n");
  dark = clone_object("/players/pathfinder/closed/shadow/items/darkness.c");
  move_object(dark, room);
  return 1;
}
 
/*
call_darkness() {
  object room, dark;
  if(!less_pts(20)) { return 0; }
  room = ENVTP;
  if(present("darknessobject",ENVTP)) {
    write("There is already a Darkness present!\n");
    return 1;
    }
  ENVTP->set_light(0);
  write("You call upon your shadowy soul to come fill the room.\n");
  tell_room(room,
    "You feel the light fading as a shadowy darkness fills the room.\n");
  dark = clone_object("/players/pathfinder/closed/shadow/items/darkness.c");
  move_object(dark, room);
  return 1;
}
*/
 
/* Determine the Alignment of the monster */
 
check_alignment(str) {
  object monster;
  if(!level_check(2)) return 0;
  if(!str) { 
    write("Who do you want to check?\n");
    return 1; 
  }
  monster = present(str, ENVTP);
  if(!monster) { 
    write(CAP(str)+" is not on the mud.\n");
    return 1;
    }
  if(!present(monster,ENVTP)) { 
    write(CAP(str)+" is not present!\n");
    return 1;
  }
  if(!less_pts(5)) return 1;
  write(CAP(str)+"'s alignment is: "+monster->query_alignment()+"\n");
  return 1;
}
 
/* Guild Status line */
 
guild_stat() {
  write(TP->short()+"\n");
  write("<>Level: "+TP->query_level()+"\t\t\t<>Extra Level: "+TP->query_extra_level()+"\n");
  write("<>Hit Points: "+TP->query_hp()+"/"+TP->query_mhp()+"\t\t<>Experience: "+            TP->query_exp()+"\n");
  write("<>Spell Points: "+TP->query_sp()+"/"+TP->query_msp()+"\t\t<>Shadow Experience: "+TP->query_guild_exp()+"\n");
  write("<>Armor Class: "+TP->query_ac()+"\n");
  write("<>Alignment: "+TP->query_alignment()+"\n");
  write("<>Shadow Points: "+MARK->query_shpts()+"\t\t<>Shadow level: "+TP->query_guild_rank()+"\n");
  write("<>Gold: "+TP->query_money()+"\t\t\t<>Quest points: "+TP->query_quest_point()+"\n");
  write("\n\n");
  if(MARK->query_muffled() == 1) write("You are muffled.\n");
    else write("You are not muffled.\n");
  if(MARK->query_points() == 0) write("Hit points will not be drained\n");
    else write("Hit points will be drained.\n");
  if(MARK->query_summon() == 0) write("Not allowing summons.\n");
    else write("Allowing summons.\n");
   write("Drain doing "+MARK->query_drain_damage()+" points of damage.\n");
   return 1;
}
 


/* Sets their availability to be summoned, or to be jumped to */
 
toggle_summon(str) {
  if(!str) { write("Usage: tsum <on/off/stat>\n"); return 1; }
  if(str == "on") {
    if(MARK->query_summon() == 1) {
      write("You can already summon or be summoned!\n");
      return 1;
      }
    MARK->set_summon(1);
    write(
      "Summon now set, people can summon you and you can summon players.\n");
    return 1;
    }
  if(str == "off") {
    if(MARK->query_summon() == 0) {
      write("Your summon is already off.\n");
      return 1;
      }
    MARK->set_summon(0);
    write("Your summon is now off.\n");
    return 1;
    }
  if(str == "stat") {
    if(MARK->query_summon() == 1) {
      write("Your summon is set.\n");
      return 1;
    } else {
      write("Your summon is not set.\n");
      return 1;
      }
    }
  return 1;
}
 
/* 
  -------------------------
  Guild Commander Functions
  -------------------------
*/  
 
set_gc_title() {
  if(!level_check(10)) return 0;
  TP->set_title("the Grandmaster of the Shadows");
  return 1;
}
 
commander_echo(str) {
  object people, comm;
  int n;
  if(!level_check(10)) return 0;
  people = users();
  for(n = 0; n < sizeof(people); n++) {
    comm = present("shadow-mark", people[n]);
    if(comm && people[n]->query_guild_rank() > 8 && comm->query_muffled() == 0) {
      tell_object(people[n], str);
      }
    }
  return 1;
}
 
commander_talk(str) {
  string mesg;
  if(!level_check(10)) return 0;
  mesg = "[<c>"+BOLD+CAP(TP->query_name())+NOSTYLE+"<>] "+str+"\n";
  commander_echo(mesg);
  return 1;
}
 
commander_emote(str) {
  string mesg;
  if(!level_check(10)) return 0;
  mesg = "[*]> "+BOLD+CAP(TP->query_name())+NOSTYLE+" "+str+"\n";
  commander_echo(mesg);
  return 1;
}
 
/* Commander stuff for the old guild object */
/* and some for newer guild object */
 
/* force update on the old object */
 
old_force_update(str) {
  object who, mark;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: oldupd <who>\n"); return 1; }
  who = find_living(str);
  mark = present("shadow-mark",who);
  if(!who || !present("shadow-mark",who)) {
    write(CAP(str)+" is not a shadow or NOT on the mud!\n");
    return 1;
    }
  tell_object(who,"A guild commander has updated your mark.\n");
  write("You updated "+CAP(str)+"'s mark.\n");
  mark->update_me();
  return 1;
}
 
/* give a shadow back their mark from the old object */
 
old_hand_mark(str) {
  object who, mark;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: oldmark <who>\n"); return 1; }
  who = find_living(str);
  if(!who) {
    write("They aren't on the mud.\n");
    return 1;
    }
  mark = clone_object("/players/blue/closed/shadow/shadow");
  move_object(mark,who);
  tell_object(who,"You have been given a Shadow mark.\n");
  write("You have given a Shadow mark to "+CAP(str)+"\n");
  return 1;
}
 
/* Promotes a shadow from old guild */
 
old_promote_shadow(str) {
   object shadow_ob, player;
   int num;
   string per;
   if(sscanf(str, "%s %d", per, num) != 2) {
      write("Usage: oldpromote <person> <levels>.\n");
      return 1;
   }
   player = find_player(per);
   if(!player) {
      write("Cannot locate "+per+".\n");
      return 1;
   }
   shadow_ob = present("shadow-mark", player);
   if(!shadow_ob) {
      write("That person is not a shadow.\n");
      return 1;
   }
   if(!shadow_ob->promote_me(num)) {
      write("You must promote between the levels of 1 and 12.\n");
      return 1;
   }
   write("Done.\n");
   if(num > 0)
   tell_object(environment(shadow_ob), "You have been "+
      "promoted by "+TP->QRN+".\n");
   if(num == 0)
      tell_object(player, "Your experience has been corrected.\n");
   write_file("/players/pathfinder/closed/shadow/logs/promote",
              TP->QRN+" promoted "+CAP(player->query_name())+" "+num+"\("+
          shadow_ob->query_shlevel()+"\)\n");
   return 1;
}
 
/* Force a shadow to update his/her mark */
 
force_update(str) {
  object who, mark;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: upd <who>\n"); return 1; }
  who = find_living(str);
  mark = present("shadow-mark",who);
  if(!who || !present("shadow-mark",who)) {
    write(CAP(str)+" is not a shadow or NOT on the mud!\n");
    return 1;
    }
  tell_object(who,"A guild commander has updated your mark.\n");
  write("You updated "+CAP(str)+"'s mark.\n");
  mark->update_me();
  return 1;
}
 
hand_mark(str) {
  object who, mark;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: mark <who>\n"); return 1; }
  who = find_living(str);
  if(!who) {
    write("They aren't on the mud.\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/new/shadow");
/*
  mark = clone_object("/players/pathfinder/closed/shadow/shadow");
*/
  move_object(mark,who);
  tell_object(who,"You have been given a Shadow mark.\n");
  write("You have given a Shadow mark to "+CAP(str)+"\n");
  return 1;
}
 
/* Banish a shadow from the guild Guild Commanders only! */
 
banish_shadow(str) {
  object who, mark;
  int gxp, grank;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: banish <who>\n"); return 1; }
  who = find_living(str);
  if(!who) { 
    write(CAP(str)+" is not around.\n"); 
    return 1; 
  }
  mark = present("shadow-mark",who);
  if(!mark) {
    write(CAP(str)+" is not a Shadow!\n");
    return 1;
  }
  tell_object(who,"You have been banished from the shadows by "+
              CAP(TP->QRN)+"\n");
  write("You have banished "+CAP(str)+" from the shadows\n");
  tell_object(who,"If you would like your mark back please mail Pathfinder\n");
  tell_object(who,"regarding the circumstances.\n");
  gxp = who->query_guild_exp();
  grank = who->query_guild_level();
  who->set_guild_exp(-gxp);
  who->set_guild_level(-grank);
  who->set_guild_name(0);
  mark->dest_guild_object();
  mark->revoke_me();
  return 1;
}
 
/* Promotes a shadow */
 
promote_shadow(str) {
  object who, mark;
  string person;
  int level, oldgxp, newgxp;
  if(!level_check(10)) return 0;
  if(!str) { write("Usage: promote <who> <level>\n"); return 1; }
  if((!sscanf(str,"%s %d",person,level)) == 2) return 0;
  who = find_living(person);
  if(!who) { write(CAP(person)+" is not on!\n"); return 1; }
  mark = present("shadow-mark", who);
  if(!mark) {
    write(CAP(person)+" isn't a Shadow!\n");
    return 1;
    }
  if((level + who->query_guild_rank())< 0) { write(
    "You can't promote someone to a negative level!\n"); 
    return 1; 
    }
  oldgxp = who->query_guild_exp();
  if((who->query_guild_rank() + level) < 9)
  {
    newgxp = BLACK_ORB->cost_at_level(level);
  }
  else 
  { 
    newgxp = 6900000; 
  }
  who->add_guild_exp(-oldgxp);
  who->add_guild_exp(newgxp);
  who->add_guild_rank(level);
  tell_object(who,"You have been promoted to rank "+
    (who->query_guild_rank())+" by "+CAP(RN)+"\n");
  write("You promoted "+CAP(person)+" to rank "+
    (who->query_guild_rank())+"\n");
  write_file("/players/pathfinder/closed/shadow/logs/promo.log",
    CAP(RN)+" promoted "+CAP(person)+" to level "+
    (who->query_guild_rank())+"\n");
  return 1;
}
 
/* adds guild xps to a shadow */
 
add_shadow_xp(str) {
  object who, mark;
  int oldgxp, amt;
  string player;
  if(!level_check(10)) return 0;
  if(!str) {
    write("Usage: agxp <player> <amt>\n");
    return 1;
    }
  if((!sscanf(str,"%s %d",player,amt)) == 2) return;
  who = find_player(player);
  if(!player) { 
    write("I could not find "+CAP(player)+" on here.\n"); 
    return 1; 
  }
  mark = present("shadow-mark",who);
  if(!mark) { write(CAP(player)+" is not a Shadow\n"); return 1; }
  oldgxp = who->query_guild_exp();
  who->add_guild_exp(amt);
  tell_object(who,"You feel more experienced.\n");
  write("You give "+CAP(player)+" "+amt+" gxps for a total of "+
    (who->query_guild_exp())+"\n");
  write_file("/players/pathfinder/closed/shadow/logs/xp.log",CAP(RN)+
    " gave "+CAP(player)+" "+amt+" gxps for a total of "+
    who->query_guild_exp()+"\n");
  return 1;
}
add_to_pool(amt)
{
  int num;
  
  if(!amt)
  {
    write("What do you want to donate?\n");
    return;
  }
   
  if(!sscanf(amt, "%d", num) == 1)
  {
    write("Usage: donate <amt>\n");
    return 1;
  }
   
  POOL->add_to_pool(num);
  return 1;
}
 
take_from_pool(amt)
{
  int num;
  
  if(!amt)
  {
    write("What do you want to take?\n");
    return;
  }
  
  if(!sscanf(amt, "%d", num) == 1)
  {
    write("Usage: withdraw <amt>\n");
    return 1;
  }
  
  POOL->take_from_pool(num);
  return 1;
}

query_usage()
{
  if(TP->query_level() < 21) return 0;
  write("Number of uses of pool: " + POOL->query_uses() + ".\n");
  return 1;
}

query_pool()
{
  write("Number of spell points in pool: " + POOL->query_pool() + ".\n");
  return 1;
}

 
/* get a pair of shadow shadez */
 
get_shadez() {
  object shadez;
  shadez = clone_object("/players/pathfinder/closed/shadow/shades.c");
  if(!less_pts(10)) return 0;
  write("You focus your darkness onto your hand and a pair of shades apear.\n");
  tell_room(ENV(TP),CAP(TP->QRN)+" focus's their attention upon their hand and a pair of shades appear.\n");
  move_object(shadez,TP);
  return 1;
}

/* shadow news */

 
shadow_news() {
  information("news");
  return 1;
}

/* information on guild */
 
information(str) {
   int lines;
   string file;
   if(TP->query_guild_rank() > 8 && str == "gc") {
   file = HELPPATH + str;
   } else if(TP->query_guild_rank() < 9 && str == "gc") { return; }
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
 
/* Screaming Shadows Spell */
 
shadow_scream(str) {
  object monster;
  int dam;
  if(!level_check(2)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) { 
    write("Who do you want to attack?\n"); 
    return 1; 
    }
  else if(TP->query_attack() && !str) { 
    str = (TP->query_attack())->query_real_name(); 
    }
  monster = present(str, ENVTP);
  if(!monster) return 1;
  if(!present(monster,ENVTP)) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  dam = 10 + random(15);
  if(!less_pts(25)) { return 0; }
  TP->spell_object(monster,"shadow scream",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  say("You hear an ear piercing scream from the shadowy\n"+
                  "darkness of the room.\n");
  write("You call upon your shadowy powers to make the shadows\n"+
                 "scream in agony\n");
  MARK->set_spell_time(time());
  return 1;
}
 
/* Call upon your shadowy forces to attack the monster */
 
shadow_spell(str) {
  object monster;
  int dam;
  if(!level_check(4)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) { write("Who do you want to attack?\n"); return 1; }
  else if(TP->query_attack() && !str) { str = (TP->query_attack())->query_real_name(); }
  monster = present(str, ENVTP);
  if(!monster) return 1;
  if(!present(monster,ENVTP)) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  str = monster->query_real_name();
  dam = 15 + random(25);
  if(!less_pts(40)) return;
  TP->spell_object(monster,"shadow_atk",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You call upon your shadowy powers to come and attack "+CAP(str)+".\n");
  say("You see the shadows in the room attack "+CAP(str)+"\n");
  MARK->set_spell_time(time());
  return 1;
}
 
/* Attack a monsters shadow */
 
attack_shadow(str) {
  object monster;
  int dam, mhp;
  if(!level_check(6)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) { write("Who do you want to attack?\n"); return 1; }
  else if(TP->query_attack() && !str) { str = (TP->query_attack())->query_real_name(); }
  monster = present(str, ENVTP);
  if(!monster) return 1;
  if(!present(monster,ENVTP)) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  dam = 35 + random(35);
  if(!less_pts(60)) return;
/*
  TP->spell_object(monster,"attack_shadow",dam,0);
  TP->spell_object(monster,"attack_shadow",1,0);
*/
  mhp = monster->query_hp();
  if(mhp < dam) {
    monster->heal_self(-(mhp - 1));
  } else {
    monster->add_hit_point(-dam);
  }
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You call upon your powers of the darkness to come and attack\n");
  write(CAP(str)+"'s shadow.\n");
  say("You see "+CAP(str)+"'s shadow grow weaker.\n");
  MARK->set_spell_time(time());
  return 1;
}
 
/* Drain life from a monster */
 
drain_monster(str) {
  object monster;
  int dam;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) { write("Who do you want to attack?\n"); return 1; }
  else if(TP->query_attack() && !str) { str = (TP->query_attack())->query_real_name(); }
  monster = present(str, ENVTP);
  if(!monster) { write("No one of that name here!\n"); return 1;
  }
  if(!present(monster,ENVTP)) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  dam = MARK->query_drain_damage();
  if(!less_pts(dam)) return;
  TP->spell_object(monster,"drain",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  tell_object(TP,"You cast your shadow upon "+CAP(str)+" draining its life away.\n");
  say(CAP(TP->QRN)+" casts a shadow upon "+CAP(str)+" draining its life away.\n");
  MARK->set_spell_time(time());
  return 1;
}
 


plague_monster(str) {
  object monster, plague;
  if(!level_check(8)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_name();
  }
  monster = present(str, ENVTP);
  if(!monster) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  if(present("plague_object",monster)) {
    write(CAP(str)+" already has the plague!\n");
    return 1;
  }
  if(TP->query_alignment() > 0) {
    write("You feel your good side take shape and prevent you from\n"+
          "casting this spell!\n");
    return 1;
  }
  str = monster->query_name();
  if(!less_pts(150)) return;
  plague = clone_object("/players/pathfinder/closed/shadow/items/plague.c");
  TP->spell_object(monster,"plague",50,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You use your evil powers to conjure up the plague to come and\n"+
        "attack "+CAP(str)+"\n");
  say("You see "+CAP(TP->QRN)+" cast an evil aura upon the room as "+
        CAP(str)+" grows sick.\n");
  plague->set_caster(TP->QRN);
  move_object(plague, monster);
  MARK->set_spell_time(time());
  return 1;
}


opp_shad_attack_opp(str) {
  object monster, shadatk;
  if(!level_check(8)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    write("You must specify who to attack!\n");
    return 1;
  }
  monster = present(str, ENVTP);
  if(!monster) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  if(present("shadow_attack_object",monster)) {
    write(CAP(str)+" has their shadow already attacking them!\n");
    return 1;
  }
  str = monster->query_name();
  if(!less_pts(100)) return;
  shadatk = clone_object("/players/pathfinder/closed/shadow/items/shad_atk.c");
  TP->spell_object(monster,"opp_shadow_attack",30,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You use your mastery of the shadows to force " + CAP(str) + "'s\n" +
        "shadow to turn on their master and attack them!\n");
  say("You notice something extremely odd when you see " + CAP(str) + "'s\n" +
      "shadow start pummeling its owner, doing massive damage!\n");
  shadatk->set_caster(TP->QRN);
  move_object(shadatk, monster);
  MARK->set_spell_time(time());
  return 1;
}


/* Death type spell to do major damage to an opponent */
 
shadow_death(str) {
  object monster;
  int dam;
  if(!level_check(8)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) { write("Who do you want to attack?\n"); return 1; }
  else if(TP->query_attack() && !str) { str = (TP->query_attack())->query_real_name(); }
  monster = present(str, ENVTP);
  if(!monster) return 1;
  if(!present(monster,ENVTP)) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  str = monster->query_name();
  if(!less_pts(120)) return;
  dam = random(40) + random(40) + 40;
  TP->spell_object(monster,"death",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You cast your shadow upon "+CAP(str)+" draining its life away.\n");
  say(CAP(TP->QRN)+" casts a shadow upon "+CAP(str)+" draining its life away.\n");
  MARK->set_spell_time(time());
  return 1;
}
 
/* give a monster the plague */
 
/* Change hit points to spell points */
 
transfer_hp_to_sp(str) {
  int hps, sps, amt;
  if(!level_check(5)) return 0;
  if(!str) { write("Usage: pheal <amt>\n"); return 1;
    }
  if((!sscanf(str,"%d",amt)) == 1) return 1;
  hps = TP->query_hp();
  sps = TP->query_sp();
  if(amt > hps) { 
    write("You don't have enough hit points!\n"); 
    return 1; 
  }
  TP->add_spell_point(amt);
  TP->add_hit_point(-amt);
  write("You can feel your shadow grow stronger as your body grows weaker.\n");
  say("You see "+CAP(RN)+"'s shadow grow stronger as their physical self grows weak.\n");
  
  return 1;
}
 
/* change spell points to hit points */
 
transfer_sp_to_hp(str){
  int hps, sps, amt;
  if(!level_check(4)) return 0;
  if(!str) { write("Usage: mheal <amt>\n"); return 1; }
  if((!sscanf(str,"%d",amt)) == 1) return 1;
  hps = TP->query_hp();
  sps = TP->query_sp();
  if(amt > sps) { 
    write("You don't have enough spell points!\n"); 
    return 1; 
  }
  TP->add_hit_point(amt);
  TP->add_spell_point(-amt);
  write("You can feel your shadow grow weaker as your body grows stronger.\n");
  say("You see "+CAP(RN)+"'s shadow grow weaker as their physical self grows stronger.\n");
  return 1;
}
  
/* Guild teleport to another guild member */
 
fade_to_player(str) {
  object who, nshad;
  if(!level_check(6)) return 0;
  if(!str) { write("Usage: fade <player>\n"); return 1; }
  who = find_player(str);
  if(!who) {
    write("I could not find "+CAP(str)+" anywhere.\n");
    return 1;
    }
  if(!present("shadow-mark",who)) { write(CAP(str)+" isn't a Shadow!\n"); return 1; }
  nshad = present("shadow-mark",who);
  if((ENVTP->realm() == "NT") || (ENV(who)->realm() == "NT")) {
    write("You start to cast your shadow as you feel a force stopping you.\n");
    return 1;
    }
  if(!less_pts(65)) { 
    write("You don't have enough power!\n"); 
    return 1;
  }
  write("You cast your shadow upon the area which you stand and arrive\n");
  write("next to your fellow Shadow.\n");
  tell_object(who,"You feel the presence of another Shadow enter the room.\n");
  move_object(TP,environment(who));
  return 1;
 
}
 
/* This is the function for a shadow to send something to another shadow */
 
send_to_shadow(str) {
  object who, mark, item;
  string person, what;
  if(!level_check(3)) return 0;
  if(!str) { 
    write("Usage: sendto <who> <what>\n");
    return 1;
    }
  if(!sscanf(str,"%s %s",person, what) == 2) {
    write("Usage: sendto <who> <what>\n");
    return 1;
    }
  who = find_living(person);
  if(!who) {
    write(CAP(person)+" is not online!\n");
    return 1;
    }
  mark = present("shadow-mark", who);
  if(!mark) { 
    write(CAP(person)+" is not a Shadow!\n");
    return 1;
    }
  item = present(what, TP);
  if(!item) {
    write("You do not have a "+what+"\n");
    return 1;
    }
  write("You call upon a shadow servant to deliver a "+what+" to "+
        CAP(person)+"\n");
  tell_object(who,"You see a shadow servant arrive out of the shadows.\n");
  tell_object(who,"It hands you a "+what+"\n");
  tell_object(who,CAP(TP->QRN)+" sends you a "+what+".\n");
  move_object(item,who);
  if(!present(what,who)) {
    write("Your servant reports that the delivery was unsuccessful\n");
    return 1;
    }
  else {
    write("You shadow servant reports the delivery was successful.\n");
    return 1;
    }
  return 1;
}
 
/* recruit new guild members */
 
recruit_shadow(str) {
  object who, mark;
  if(!level_check(4)) return 0;
  if(!str) {
    write(capitalize(str)+" is not present!\n");
    return 1;
    }
  who = find_living(who);
  if(!present(who,ENVTP)) {
    write(capitalize(str)+" is not present!\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/items/recruit.c");
  move_object(mark, who);
  write("You have recruited "+capitalize(str)+" and they may now join the guild.\n");
  return 1;
}
 
goto_guild() {
  if(!less_pts(20)) return 1;
  write("You call upon your shadowy powers to fill the room with darkness.\n");
  write("When the darkness clears you find yourself in the safety of the guild hall.\n");
  say("A Darkness fills the room.  When the darkness fades you notice\n");
  say(CAP(RN)+" is gone.\n");
  move_object(TP,"/players/pathfinder/closed/shadow/rooms/meeting");
  say("The room fills with darkness and takes the shape of "+CAP(RN)+"\n");
  return 1;
}
 
/* Lowers the players spell or shadow points the appropriate amount */
/* so that the spells work right when passed only 0 sps to drain */
 
less_pts(str) {
  int amt, sps, hps;
  sps = TP->query_sp();
  hps = TP->query_hp();
  amt = str;
  if(TP->query_level() > 19) return 1;
  if(MARK->query_points() == 1) {
    if((sps < amt) && (sps > ((1/2) * amt))) {
/* will drain hit points ONLY if the players have at least 1/2 their */
/* spells casting cost in hps */    
      if(hps < (amt - sps)) {
        write("You do not have enough points!\n");
        return 0;
      } else {
        TP->add_spell_point(-sps);
        TP->add_hit_point(-(amt - sps));
        return 1;
      }
    } else {
      TP->add_spell_point(-(amt));
      return 1;
    }
  } else { 
/* if the player doesn't want hit points drained */
    if(sps < amt) {
      write("You do not have enough points!\n");
      return 0;
    } else {
      TP->add_spell_point(-amt);
      return 1;
    }
  }
  return 0;
}
/* less_pts() */
 
/* casts peace within a room */
 
peace_room() {
 object ob;
 if(!level_check(3)) return 0;
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
 
  write("You raise your hands high into the air as a thick cloud of shadows\n");
  write("fill the room as the fighting stops.\n");
  say(CAP(RN)+" raises their hands high into the air as shadows fill the room, making\n");
  say("it dark as all the fighting stops.\n");
  return 1;
}
 
start_shadow_healing() {
  if(!level_check(4)) return 0;
  if(TP->query_attack()) { 
    write("You cannot be in combat to cast this spell!\n");
    return 1;
  }
  if(MARK->query_shadow_healing() == 1) { 
    write("You are already healing your shadow!\n");
    return 1;
  }
  if(!less_pts(65)) {
    return 1;
  }
  MARK->reset_heal_called();
  MARK->set_shadow_healing(1);
  MARK->heart_me();
  write("You turn yourself into a shadow as you begin to heal your essence\n");
  return 1;
}
  
 
heal_da_shadow(obj) {
  object mark;
  int heal;
  mark = present("shadow-mark", obj);
  heal = 0;
  if(obj->query_attack()) { return 1; }
  if(set_light(0) == 0) heal += (obj->query_guild_rank())/2;
  heal += 10;
  tell_object(obj,"You feel your shadowy essence grow stronger by the moment.\n");
  tell_object(obj,"Heal pts : " + heal + "\n");
  obj->heal_self(heal);
  if(mark->query_heal_called() > (obj->query_guild_rank() * 20)) {
    mark->set_shadow_healing(0);
    mark->reset_heal_called();
    tell_object(obj,"You return to a more solid state as you finish healing\n");
  }
  return 1;
}

/* stop healing */

 
stop_heal() {
  write("You force yourself out of your immateriel state and stop healing\n");
  say(CAP(TP->QRN)+" comes into a more materiel state.\n");
  MARK->reset_heal_called();
  MARK->set_shadow_healing(0);
  return 1;
}

/*
// new and improved forge spell  10-7-94
*/
 
forge_weapon(str) {
  object weap;
  if(!str) {
    write("Usage: forge <weapon>\n");
    return 1; }
  if((str == "sword") && (less_pts(90)) && (level_check(6))) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/sword.c");
    say("A shadow is cast over the room as it goes dark.\n");
    say(CAP(RN)+" pulls a sword from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  if((str == "blade") && (less_pts(70)) && (level_check(4))) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/blade.c");
    say("A shadow is cast over the room as it goes dark.\n");
    say(CAP(RN)+" pulls a blade from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  if(str == "dagger" && less_pts(50) && level_check(2)) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/dagger.c");
    say("A shadow is cast over the room as it goes dark.\n");
    say(CAP(RN)+" pulls a dagger from the darkness.\n");
    weap->set_owner(RN);
    move_object(weap,TP);
    return 1;
    }
  return 1;
}
 
use_hit_points(str) {
  if(!str) {
    write("Usage: points <yes/no/stat>\n");
    return 1;
    }
  if(str == "yes") {
    MARK->set_points(1);
    write("Hit points being drained after spell points.\n");
    return 1;
    }
  if(str == "no") {
    MARK->set_points(0);
    write("Hit points will not be drained after spell points.\n");
    return 1;
    }
  if(str == "stat") {
    if(MARK->query_points() == 1) {
      write("Hit points will be drained.\n");
      return 1;
      }
    write("Hit points will not be drained.\n");
    return 1;
    }
  return 1;
}
 
check_time() {
  call_other("/room/church.c","long","clock");
  return 1;
}
 
time_check() { 
  if(time() - MARK->query_spell_time() < 3) {
    write("It is too soon!\n");
    return 0;
    }
  return 1;
}
 
/* This is the section which will check who the player is attacking */
/* whether it is a player or not, if they are in the dark or not */
 
do_combat_stuff(obj) {
  /* if the player is attacking another shadow then stop combat */  
  if((obj->query_attack())->query_guild_name() == "shadow") {
    write("You cannot fight another shadow!\n");
    obj->stop_fight();
    (obj->query_attack())->stop_fight();
    return 1;
  }
  if((ENV(obj))->set_light(0) == 0) {
    if((random(100) < 75) && ((obj->query_attack())->query_npc())) {
      if((obj->query_attack())->query_hp() > 2) {
        (obj->query_attack())->heal_self(-2);
      }
    }
    
    /* extra damage for guild members that pk, in the dark only and */
    /* not against other players */
    
    if(obj->query_pl_k() && ((obj->query_attack())->query_npc())) {
      if(random(100) < 60) {
        if((obj->query_attack())->query_hp() > 5) {
          (obj->query_attack())->heal_self(-(random(3)));
        } 
      }
    }  
  }
} 
/* do_combat_stuff(obj) */  
 
/* check a players guild level before using a spell */
 
level_check(amt) {
  if(amt <= TP->query_guild_rank() || TP->query_level() > 19) return 1;
  else {
    write("You need to be "+amt+" guild level before you can use\n");
    write("this spell.\n");
    return 0;
  }
  return 0;
}
 
leave_shadows() {
  int gxp, grank, exp;
  gxp = TP->query_guild_exp();
  grank = TP->query_guild_rank();
  exp = TP->query_experience();
  TP->add_guild_exp(-gxp);
  TP->add_guild_rank(-grank);
  TP->set_guild_name(0);
  TP->add_experience(-exp/6);
  write("You lose 1/6th of your experience for leaving a guild.\n");
  write( "You have left the Shadow guild.\n");
  TP->set_guild_name(0);
  MARK->dest_guild_obj();
  return 1;
}
 
shadow_grin(str) {
  object who;
  if(!str) { 
    write("You grin shadowly.\n");
    say(CAP(TP->QRN)+" causes the lights to go dim as"+
      " they grin\n");
    return 1;
    }
  who = find_living(str);
  if(!who) { 
    write("Shadow grin at who?\n");
    return 1;
    }
  write("You shadowly grin at "+CAP(who->query_name())+"\n");
  tell_object(who,CAP(TP->QRN)+" grins with a shadowy darkness at you\n");
  say(CAP(TP->QRN)+" grins darkly at "+CAP(str)+"\n");
  return 1;
}
 
smile_shadow(str) {
  object who;
  if(!str) {
    write("You make the room grow darker as you smile.\n");
    say("You see the shadows start to stir as "+CAP(TP->QRN)+
      " smiles.\n");
    return 1;
    }
  who = find_living(str);
  if(!who) {
    write("Shadowly smile at who?\n");
    return 1;
    }
  write("You smile shadowly at "+CAP(who->query_name())+"\n");
  tell_object(who,CAP(TP->QRN)+" drives a shiver up your spine as they "+
    "give you a hollow shadowy smile\n");
  say(CAP(TP->QRN)+" drives shivers down your spine as they "+
    "cast a shadowy smile at "+CAP(str)+"\n");
  return 1;
}
 

/* sets the players login and logout messages */
 
set_login_string(str) {
  if(!str) {
    write("usage: setin <msg>\n");
    return 1;
  }
  MARK->set_in_string(str+"\n");
  write("Login string set to: "+str+"\n");
  return 1;
}
 
set_logout_string(str) {
  if(!str) {
    write("usage: setout <msg>\n");
    return 1;
  }
  MARK->set_out_string(str+"\n");
  write("Logout string set to: "+str+"\n");
  return 1;
}
 
review_strings() {
  write("Login String: "+MARK->query_in_string());
  write("Logout String: "+MARK->query_out_string());
  return 1;
}
 
 

