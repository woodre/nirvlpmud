
#include "/players/pathfinder/closed/esc.h"
#define TP this_player()
#define TO this_object()
#define ENVTO this_object()
#define ENVTP environment(this_player())
#define QRN query_real_name()
#define QN query_name()
#define RN this_player()->query_real_name()
#define CAP capitalize
#define MARK present("shadow-mark",this_player())
#define BOLD "[1m"
#define NOSTYLE "[0m"
#define BNAME BOLD + CAP(TP->QRN) + NOSTYLE
#define ENV environment
#define NEW_ORB "/players/pathfinder/closed/shadow/items/new_orb.c"
#define BLACK_ORB "/players/pathfinder/closed/shadow/obj/black_orb.c"
#define OLD_ORB "/players/blue/closed/shadow/obj/black_orb.c"
#define HELPPATH "/players/pathfinder/closed/shadow/help/"
#define POOL "/players/pathfinder/closed/shadow/obj/sp_pool.c"
#define SLAVE "/players/pathfinder/closed/shadow/new/shadow.c"

init_argument(str) {
  string in;
  in = MARK->query_login_string();
  /* if the player is invisible, it will not announce their */
  /* arrival to the other guild members */
  if(TP->query_invis())
    guild_echo("\n" + "[<" + BNAME + ">] " + in);
  write("\nWelcome to the "+ BOLD + "NEW" + NOSTYLE + " Shadow Guild.\n");
  write("To get the latest news type 'shadownews'.\n");
  write("\n\nOh, by the way, the Shadows are under new management.\n");
  write("If you have any questions, comments, bitches, gripes mail"+
        " Pathfinder.\n");
  if(TP->query_level() < 20) TP->set_al_title(BOLD+"<SHADOW>"+NOSTYLE);
  return 1;
}

end_the_game() {
  string out;
  out = MARK->query_logout_string();
  if(TP->query_invis())
    guild_echo("[<>]" + BNAME + "[<>] " + out);
  MARK->save_me();
  return 1;
}


refresh_mark(obj) {
  object mark;
  mark = present("shadow-mark", obj);
  move_object(mark,"players/pathfinder/closed/shadow/rooms/advance");
  write("Refreshing your Shadowy essence...");
  move_object(mark, obj);
  write("Done!\n");
  return 1;
}

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
  mesg = "[<"+CAP(TP->query_name())+">] "+str+"\n";
  guild_echo(mesg);
  return 1;
}

guild_emote(str) {
  string mesg;
  if(!str) { write("Shadow emote what?\n"); return 1; }
  mesg = "[*]> "+CAP(TP->query_name())+" "+str+"\n";
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
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
write("Name\t\tRank\tLocation\n");
write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  for(n = 0; n < sizeof(people); n++) {
    mark = present("shadow-mark", people[n]);
    if(mark && (!(people[n]->query_invis() > 18))) {

      mesg = pad ((CAP(people[n]->QRN)), 16);

/* Old Way
      if(strlen(people[n]->QRN) < 8) mesg = CAP(people[n]->QRN)+"\t\t";
      else mesg = CAP(people[n]->QRN)+"\t";
*/
      mesg += people[n]->query_guild_rank()+"\t";
      mesg += environment(people[n])->short() + "\n";
      write(mesg);
      i++;
      }
    }
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  write("There are "+i+" Shadows logged in.\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
  return 1;
}

    
other_who() {
  object *people, who;
  int n, i;
  string mesg, temp;
  string envt;
        
  people = users();
  n = i = 0;
write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
write("Name\t\tLevel\tGuild\t\tLocation\n");
write( 
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
  for(n = 0; n < sizeof(people); n++) {
    if((people[n]->query_invis() < 18) && (people[n]->query_name()) &&
       (ENV(people[n])) && (people[n]->query_level() > 0)) {
      mesg = pad ((CAP(people[n]->QRN)), 24);
  
/* Old Way  
      if(strlen(people[n]->QRN) < 8) {
        mesg = CAP(people[n]->QRN) + "\t\t";
      } else {
        mesg = CAP(people[n]->QRN) + "\t";
        }
*/    
      mesg += people[n]->query_level() + "\t";
      temp = people[n]->query_guild_name();
      if(!temp) {
        mesg += "None\t";
      } else {
        if(strlen(temp) < 8) { mesg += CAP(temp) + "\t"; }
        else { mesg += CAP(temp); }
      }
        mesg += "\t";
      if(!(envt = ENV(people[n])->short()) || !ENV(people[n])) {
        envt = "Location Unknown\n";
      }
      mesg += envt;
      write(mesg);
      i++;
      }
    }
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
  write("There are "+i+" People logged into Nirvana.\n");
  write(
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
  return 1;   
}
         
      
set_shadow_monitor(str) {
  int monitor;      
  monitor = MARK->query_monitor();
  if(str == "attack") {
    MARK->set_monitor(-1);
    write("Monitor set to attack.\n");
    MARK->heart_me();
    return 1;
    }
  if(!str) {
    MARK->set_monitor(0);
    return 1;
    }
  if(!str || !sscanf(str,"%d",monitor)) {
    write("Usage: mon <number/attack>.\n");
    return 1;
    }   
  if(!monitor || monitor == 0) {
    write("Monitor is off.\n");
    MARK->set_monitor(0);
    return 1;
    }
  write("Monitor time set to "+monitor+"\n");
  MARK->set_monitor(monitor);
  MARK->heart_me();
  return 1;
}
  
  
shadow_monitor(obj) {
  object att;
  int msp, mhp, sp, hp, intox, oppsh, ohp, omhp, shp, mshp;
  int stuff, soak;
  string mesg;
  msp = obj->query_msp();
  mhp = obj->query_mhp();
  sp = obj->query_sp();
  hp = obj->query_hp();
  intox = obj->query_intoxination();
  stuff = obj->query_stuffed();
  soak = obj->query_soaked();
  mesg = " <hp> ["+hp+"/"+mhp+"] ";
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


  
add_to_sp_pool(amt) {
  if(!amt) {
    write("Usage: donate <amt>\n");
    return 1;
  }
  POOL->add_to_pool(amt); /* call function to add_to_pool */
  return 1;  
}
  
    
take_from_sp_pool(amt) {
  if(!amt) {
    write("Usage: retrieve <amt>\n");
    return 1;
  } 
  POOL->take_from_pool(amt); /* call function to take_from_pool */
  return 1;
}       


count_sp_in_pool() {
  write("There are currently " + POOL->query_pool() + " spell points" +
        " in the pool.\n");
  return 1;
}
    
check_pool() {
  if(TP->query_level() > 19) {
    write("Number of times spell point pool used since reset: " +
          POOL->query_uses() + ".\n");
    return 1;
  }
  return 0;
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
   say(CAP(TP->QRN) + " lets " + possessive(TP) +
       " shadow fall over the corpse.\n");
   say("It shrivels into dust and scatters.\n");
   return 1;  
}
    
    
drain_damage(str) {
  int amt; 
  if(!str) {
    write("Usage: dd <amt>\n");
    return 1;
    }
  if((!sscanf(str,"%d",amt)) == 1) return;
  if(amt < 0) { write("You can't have a negative drain!\n"); return 1;
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
  who = present(str, ENVTP);
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
  
    
update_follow(obj) {
  object mark;
  mark = present("shadow-mark", obj);   
  write("You follow "+CAP((mark->query_follow())->query_real_name())+"\n");
  move_object(obj,ENV(mark->query_follow()));
  say(CAP(obj->query_name())+" stealthily enters the room following behind "+
      CAP((obj->query_follow())->query_name())+".\n");
  command("glance",obj);
  return 1;
}
    
    
     
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
      
    
stat_shadow(str) {
  object who, mark;
  if(!str) { write("Usage: gstat <who>\n"); return 1; }
  who = find_player(str);
  if(!who) { write(CAP(str)+" isn't on.\n"); return 1; }
  mark = present("shadow-mark",who);
  if(!mark) { write(CAP(str)+" is not a Shadow!\n"); return 1; }
  write(
"\n"+"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  

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
"\n"+"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
  return 1;
}
 
    
change_startup(str) {
  if(!str) {
    write("This will let you change your place of startup to either the\n");
    write("guild hall or the village church.  You can choose either.\n\n");
    write("Usage: startme <church/hall>\n");
    return 1;
  }
  if(str == "hall") {
    TP->set_home("/players/pathfinder/closed/shadow/rooms/meeting");
    return 1;
    }
  if(str == "church") {
    TP->set_home("/room/church");
    return 1;
  }
  write("Usage: startme <church/hall>\n");
  return 1;
}
  
  
call_darkness() {
  object room, dark;
  string dummy;
  if(sscan(file_name(ENVTP), "obj/%s", dummy)) {
    write("You cannot cast that spell here!\n");
    return 1;
  }
  if(!less_pts(20)) { return 0; }
  room = ENVTP;
  if(present("darknessobject",ENVTP)) {
    write("There is already a Darkness present!\n");
    return 1;
    }
  write("You call upon your shadowy soul to come fill the room.\n");
  tell_room(room,
    "You feel the light fading as a shadowy darkness fills the room.\n");   
  dark = clone_object("/players/pathfinder/closed/shadow/items/darkness.c");
  move_object(dark, room);
  return 1;
}

 
check_alignment(str) {
  object monster;
  if(!level_check(2)) return 0;
  if(!str) {
    write("Who do you want to check?\n");
    return 1;  
  }
  monster = present(str,ENVTP);
  if(!monster) {
    write(CAP(str)+" is not on the mud.\n");
    return 1;
    }
  if(!living(monster)) {
    write(CAP(str)+" is not a living thing!\n");
    return 1;
  }  
  if(!less_pts(5)) return 1;
  if(monster->query_alignment() > 1000) {
    write(CAP(str)+"'s alignment is: Very Good\n");
    return 1;
  }
  if(monster->query_alignment() < 1001 && monster->query_alignment() > -1) {
    write(CAP(str)+"'s alignment is: Neutral - Good\n");
    return 1;
  }
  if(monster->query_alignment() > -1000 && monster->query_alignment() < 0) {
    write(CAP(str)+"'s alignment is: Neutral - Evil\n");
    return 1;
  }
  if(monster->query_alignment() < -1000) {
    write(CAP(str)+"'s alignment is: Very Evil\n");
    return 1;  
  }
  return 1;
}
    
     
guild_stat() {
  write(TP->short()+"\n");
  write("<>Level: "+TP->query_level()+
   "\t\t\t<>Extra Level: "+TP->query_extra_level()+"\n");
  write("<>Hit Points: "+TP->query_hp()+
    "/"+TP->query_mhp()+"\t\t<>Experience: "+
    TP->query_exp()+"\n");
  write("<>Spell Points: "+
    TP->query_sp()+"/"+TP->query_msp()+"\t\t<>Shadow Experience: "+
    TP->query_guild_exp()+"\n");
  write("<>Armor Class: "+TP->query_ac()+"\t\t\t<>Shadow Level: "+
   TP->query_guild_rank()+"\n");
  write("<>Alignment: "+TP->query_al_title()+"\n");
  write("<>Gold: "+TP->query_money()+"\t\t\t<>Quest points: "+
   TP->query_quest_point()+"\n");
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
    
   
toggle_summon(str) {
  if(!str) { if(MARK->query_summon() == 1) {
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
    if(comm && comm->query_shlevel() > 8 && comm->query_muffled() == 0) {
      tell_object(people[n], str);
      }
    }
  return 1;
}
       
commander_talk(str) {
  string mesg;
  if(!level_check(10)) return 0;
  mesg = "[<c>"+CAP(TP->QN)+"<>] "+str+"\n";
  commander_echo(mesg);
  return 1;
}
  
  
commander_emote(str) {
  string mesg;
  if(!level_check(10)) return 0;
  mesg = "[<c>]"+CAP(TP->QN)+" "+str+"\n";
  commander_echo(mesg);
  return 1;
}
  
   
      
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
    
     
old_promote_shadow(str) {
   object shadow_ob, player;
   int num;
   string per;
  string CN;
  CN = TP->QRN;
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
        "promoted by "+CN+".\n");
   if(num == 0)
      tell_object(player, "Your experience has been corrected.\n");
   write_file("/players/pathfinder/closed/shadow/logs/promote",
              TP->QRN+" promoted "+CAP(player->query_name())+" "+num+"\("+
          shadow_ob->query_shlevel()+"\)\n");
   return 1;
}
    
   
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
  who = find_living(str);
  if(!who) {
    write("They aren't on the mud.\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/shadow");
  move_object(mark,who);
  tell_object(who,"You have been given a Shadow mark.\n");
  write("You have given a Shadow mark to "+CAP(str)+"\n");
  return 1;
}
  
  
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
    newgxp = NEW_ORB->cost_at_level(level);
  exp(newgxp);
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
  
  
shadow_news() {
  information("news");
  return 1;
}
     
  
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
  if(!monster) {
    write(CAP(str)+" isn't present!\n");
    return 1;
  }
  if(!monster->query_npc()) {
    write("You cannot use this spell for player killing.\n");
    return 1;
  }
  dam = 5 + random(15);
  if(!less_pts(25)) { return 0; }
  TP->spell_object(monster,"shadow scream",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  say("You cover your ears from the terrible sounds of the shadows\n" +
      "wailing in tremendous agony!\n");
  write("You begin to chant words that cause the shadowy figures hidden\n" +
        "in the room to scream in agonizing pain, causing " + monster->QN +    
        "'s\n" +
        "ears to bleed profusely.\n");
  MARK->set_spell_time(time());  
  return 1;
}

shadow_spell(str) {
  object monster;
  int dam;
  if(!level_check(4)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_real_name();
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
  str = monster->query_name();
  dam = 15 + random(25);
  if(!less_pts(40)) return;
  TP->spell_object(monster,"shadow_atk",dam,0);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("Your shadow moves away from you and attacks " + CAP(str) + "\n"+
        "then returns faithfully back.\n");
  say("You see " + CAP(TP->QN) + "'s move away from " + possessive(TP) + "\n" +
      "as it attacks " + CAP(str) + " and returns to its owner.\n");
  MARK->set_spell_time(time());  
  return 1;
}
    
  
attack_shadow(str) {
  object monster;
  int dam, mhp;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_real_name();
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
  str = monster->query_name();
  dam = 24 + random(45);
  if(!less_pts(80)) return;
  TP->spell_object(monster,"attack_shadow",1,0);
  mhp = monster->query_hp();
  if(mhp < dam) {   
    monster->heal_self(-(mhp - 1));
  } else {
    monster->heal_self(-dam);  
  }
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You cast a protective darkness upon the room for a brief moment.\n");
  write("Figures that shun the light take advantage of the darkness to\n");
  write("appear and attack " + CAP(str) + ".\n");
  say("You see the room grow dark as you feel several figures move by you\n"+
      "in the dark.  When the light returns you see " + CAP(str) + " looks\n" +
      "much weaker.\n");
  MARK->set_spell_time(time()); 
  return 1;
}
    
  
drain_monster(str) {
  object monster;
  int dam;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_real_name();
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
  str = monster->query_name();  
  dam = MARK->query_drain_damage();
  if(!less_pts(dam)) return;
  TP->spell_object(monster,"drain",dam,0);
  if(monster && !mons(str)+" draining its life away.\n");
  say(CAP(TP->QRN)+" casts a shadow upon "+
    CAP(str)+" draining its life away.\n");
  MARK->set_spell_time(time());
  return 1;
}
  
    
    
shadow_death(str) {
  object monster;
  int dam;
  if(!level_check(7)) return 0;
  if(!time_check()) { return 0; }
  if(!str && (!TP->query_attack())) {
    write("Who do you want to attack?\n");
    return 1;
  }
  else if(TP->query_attack() && !str) {
    str = (TP->query_attack())->query_real_name();
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
  str = monster->query_name();
  if(!TP->add_hit_point(-50) && !less_pts(70)) return;
  dam = random(40) + random(40) + 40;
  if(monster->query_hp() < dam) {
    dam = (monster->query_hp() - 1);
  }
  monster->heal_self(-dam);
  if(monster && !monster->query_attack()) monster->attack_object(TP);
  write("You cast your shadow upon "+CAP(str)+" draining its life away.\n");
  say(CAP(TP->QRN)+" casts a shadow upon "+
   CAP(str)+" draining its life away.\n");
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
  
  
add_shadow_ac_p1() {
  object protect;
  if(MARK->query_bonus() == 2) {
    write("You already have a shadowy protectiveness surrounding you!\n");
    return 1;
  }
  if(present("armor_plus_three", TP)) {
    write("You already have a shadowy protectiveness surrounding you!\n");
    return 1;
  }
  if(!less_pts(25)) return 1;
  write("You can feel a shadowy protectiveness form around you.\n");
  say("A shadowy protiveness forms around " + CAP(TP->QRN) + ".\n");
  protect = clone_object("/players/pathfinder/closed/shadow/items/armor_p1.c");
  move_object(protect, TP);
  return 1;
}

  
add_shadow_ac_p3() {
  object protect, other, parts, obj1, obj2;
  string who;
  if(MARK->query_bonus()) {
    write("You already have a shadowy protectiveness surrounding you!\n");
    return 1;
  }
  if(present("armor_plus_three", TP)) {
    write("You already have a shadowy protectiveness surrounding you!\n");
    return 1;
  }
  if(!present("armor_part_one", ENVTP)) {
    if(!less_pts(60)) return 1;
    parts = clone_object("/players/pathfinder/closed/shadow/items/arm_pt1.c");
    parts->set_caster(TP->QRN);
    write("You begin forming the shadowy darkness into a protective\n");
    write("aura.\n");
    say(CAP(TP->QRN) + " begins manipulating the shadows.\n");
    move_object(parts, ENVTP);
    return 1;
  }
  if(present("armor_part_one", ENVTP)) {
    if(!less_pts(60)) return 1;
    parts = present("armor_part_one", ENVTP);
    write("You complete the formation of the shadows into a protective\n");
    write("aura.\n");
    say(CAP(TP->QRN) + " completes the manipulation of the shadows.\n");
    who = parts->query_caster();
    other = find_player(who);
    obj1 = clone_object("/players/pathfinder/closed/shadow/items/armor_p3.c");
    obj2 = clone_object("/players/pathfinder/closed/shadow/items/armor_p3.c");
    move_object(obj1, TP);
    move_object(obj2, other);
    destruct(parts);
    return 1;
  }
  return 1;
}
    
  
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
  say("You see "+CAP(RN)+
    "'s shadow grow weaker as their physical self grows stronger.\n");
  
  return 1; 
}
    
    
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
  say("You see "+CAP(RN)+
    "'s shadow grow weaker as their physical self grows stronger.\n");
  return 1;
}
    
  
fade_to_player(str) {
  object who, nshad;
  if(!level_check(6)) return 0;
  if(!str) { write("Usage: fade <player>\n"); return 1; }
  who = find_player(str);
  if(!who) {
    write("I could not find "+CAP(str)+" anywhere.\n");
    return 1;
    }
  if(!present("shadow-mark",who)) { 
    write(CAP(str)+" isn't a Shadow!\n"); 
    return 1;  
  }
  nshad = present("shadow-mark",who);
  if((ENVTP->realm() == "NT") || (ENV(who)->realm() == "NT") || 
  nshad->query_summon() == 0) {
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
  item = present(what, who);
  if(!item) {
    write("You do not have a "+what+"\n");
    return 1;
    }
  if(!less_pts(20)) return 0;
  write("You call upon a shadow servant to deliver a "+what+" to "+
        CAP(person)+"\n");
  tell_object(who,"You see a shadow servant arrive out of the shadows.\n");
  tell_object(who,"It hands you a "+what+"\n");
  tell_object(who,CAP(TP->QRN)+" sends you a "+what+".\n");
  if(!transfer(item,who)) {
    write("Your servant reports that the delivery was unsuccessfulelivery was successful.\n");
    return 1;
    }
  return 1;
}
    
     
recruit_shadow(str) {
  object who, mark;
  if(!level_check(4)) return 0;
  if(!str) { 
    write(capitalize(str)+" is not present!\n");
    return 1;
    }
  who = present(who, ENVTP);
  if(!who) { 
    write(capitalize(str)+" is not present!\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/items/recruit.c");
  move_object(mark, who);
  write("You have recruited "+CAP(str)+
    " and they may now join the guild.\n");
  return 1;
}
    

less_pts(str) {
  int amt, sps, hps;
  sps = TP->query_sp();
  hps = TP->query_hp();
  amt = str;
  if(TP->query_level() > 19) return 1;
  if(MARK->query_points() == 1) {
    if((sps < amt)) {
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

peace_room() {
 object ob;
 if(!level_check(3)) return 0;
 if(!less_pts(35)) { return 0; }
 ob=first_inventory(ENVTP);
   while (ob) {
     if (living(ob)) {
       if (ob->query_attack()) {
         (ob->query_attack())->stop_fight();
         (ob->query_attack())->stop_fight();
         ob->stop_fight();
         ob->stop_fight();
         }
       }  
     ob = next_inventory(ob);
     }
    
  write("You raise your hands high into the air as a thick cloud of shadows\n");
  write("fill the room as the fighting stops.\n");
  write("You raise your hands high into the air " + 
   " as a thick cloud of shadows\n");
  saite("You cannot be in combat to cast this spell!\n");
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
  if(ENV(obj)->query_light() == 0) heal += ((1/2)*(obj->query_guild_rank()));
  heal += 10;
  write("You feel your shadowy essence grow stronger by the moment.\n");
  obj->heal_self(heal);
  if(mark->query_heal_called() > obj->query_guild_rank() * 30) {
    tell_object(obj,"You come out of your healing state\n");
    mark->reset_heal_called();
    mark->set_shadow_healing(0);
    mark->unheart_me();
  }
  return 1;  
}  
  
   
stop_heal() {
  write("You force yourself out of your immateriel state and stop healing\n");
  say(CAP(TP->QRN)+" comes into a more materiel state.\n");
  MARK->reset_heal_called();
  MARK->set_shadow_healing(0);
  MARK->unheart_me();
  return 1;
}     
  
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
    transfer(weap,TP);
    return 1;
    }
  if((str == "blade") && (less_pts(70)) && (level_check(4))) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/blade.c");
    say("A shadow is cast over the room as it goes dark.\n");
    say(CAP(RN)+" pulls a blade from the da if(str == "dagger" && less_pts(50) && level_check(2)) {
    weap = clone_object("/players/pathfinder/closed/shadow/weapons/dagger.c");
    say("A shadow is cast over the room as it goes dark.\n");
    say(CAP(RN)+" pulls a dagger from the darkness.\n");
    weap->set_owner(RN);
    transfer(weap,TP);
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
    write("Hit points will not be drained.n");
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
     
   
do_combat_stuff(obj) {
  /* if the player is attacking another shadow then stop combat */
  if((obj->query_attack())->query_guild_name() == "shadow") {
    tell_object(obj,"You cannot fight another shadow!\n");
    obj->stop_fight();
    obj->stop_fight();
    (obj->query_attack())->stop_fight();
    (obj->query_attack())->stop_fight();
    return 1;
  }  
  if((ENV(obj))->query_light() == 0) {
    if((random(100) < 75) && ((obj->query_attack())->query_npc())) {
      if((obj->query_attack())->query_hp() > 2) {
        (obj->query_attack())->add_hit_point(-2);
      }
    }
 
    /* extra damage for guild members that pk, in the dark only and */
    /* not against other players */
  
    if(obj->query_pl_k() && ((obattack())->add_hit_point(-(random(3)));
        }
      }
    }
  }
}  
    
level_check(amt) {
  if(TP->query_guild_level() > amt || TP->query_level() > 19) return 1;
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
  write("You have left the Shadow guild.\n");
  TP->set_guild_name(0);
  MARK->dest_guild_obj();
  return 1;
}  


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
   

shadow_grin(str) {
  object who;
  if(!str) {
    write("You cause the room to grow dark as you grin.\n");
    say(CAP(TP->QN)+" causes the lights to go dim as"+
        " they grin\n");
    return 1;
    }
  who = find_living(str);
  if(!who) {
    write("Shadow grin at who?\n");
    return 1;
  }
  if(present(str,ENVTO) {
    write("You grin darkly at " + CAP(str) + ".\n");
    tell_object(who,CAP(TP->QN)+" grins with a shadowy darkness at you\n");
    say(CAP(TP->QN)+" grins darkly at "+CAP(str)+".\n");
  }
  else
    write("You grin darkly at " + CAP(str) + " from afar.\n");
    tel) {
  object who;
  if(!str) {
    say("You see the shadows start to stir as "+CAP(TP->QN)+
      " smiles.\n");
    return 1;
    }
  who = find_living(str);
  if(!who) {
    write("Shadowly smile at who?\n");
    return 1;
  }
  if(present(str, ENVTP) {
    write("You drive a shiver down " + CAP(str) + "'s spine as you smile at" +
          " them.\n");
    tell_object(who,CAP(TP->QN)+" drives a shiver up your spine as " +
      possessive(TP) + " give you a hollow shadowy smile.\n");
    say(CAP(TP->QN)+" drives shivers down your spine as " +
      possessive(TP + " cast a shadowy smile at "+CAP(str)+".\n");
  }
  else {
    write("You drive a shiver down " + CAP(str) + "'s spines as you smile at" +
          " them.\n");
    tell_object(who,CAP(TP->QN)+" drives a shiver up your spine as " +
      possessive(TP) + " give you a hollow shadowy smile.\n");
  }
  return 1;
}
 
  
shadow_say(str) {
  if(!str) {
    write("What do you want to say?\n");
    return 1;
  }  
  write("You said: " + BOLD + str + NOSTYLE + "\n");
  say(CAP(TP->QN) + " says: " + BOLD + str + NOSTYLE + "\n");
  return 1;
}

 
