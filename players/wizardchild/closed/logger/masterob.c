/* players/wizardchild/closed/logger/masterob.c: master object for loggers  */
/* DO NOT BE MESSING HERE WITHOUT A GOOD REASON                             */
/* I hate reading sloppy code, so this sucker is organized as follows:      */
/* common commands come first, then rank by rank, then GC and GW commands   */
/* pet commands have been placed near the front..                           */
/* cabin commands come after pet commands..                                 */
/* I may or may not have a few commands of my own stuck in at the end       */

/* misc defines - names and checks */
#define MVER      "Logger's Guild Master Object - Prototype"
#define SVER      "Logger's Guild Slave Object - Prototype"

#define RLNAME    capitalize(this_player()->query_real_name())
#define NAME      this_player()->query_name()
#define THERE(s)  present("logger pack", s)
#define ME        this_player()
#define PLAYER(s) find_player(s)
#define write(s)  tell_object(ME, s)
#define CP(s)     capitalize(s)
#define LWR(s)    lower_case(s)

/* dir defines */
#define ROOT_DIR  "/players/wizardchild/closed/logger/"
#define CABIN_DIR "/players/wizardchild/closed/logger/cabin/"
#define ROOM_DIR  "/players/wizardchild/closed/logger/room/"
#define SAVE_DIR  "players/wizardchild/closed/logger/users/"
#define HELP_DIR  "/players/wizardchild/closed/logger/help/"

mapping *map;
/*>< NON-PLAYER COMMANDS ><*/
reset(arg) {
  if(arg)
    return ;
  map = (["ban_logger":"banish","gver":"guild_ver","PAUL":"paul_bunyun","bark":"grow_bark",
       "tlog":"toss_log","plant":"freeze","sharpen":"sharpen_weap","call":"call_pet",
       "lmon":"toggle_mon","follow":"set_follow","gp":"swap_gp","gs":"guild_status",
       "stable":"stable_mode"]);
}
/* returns possesive for player's gender */
query_gender_term(ob) {
  return (ob->query_gender() == "male" ? "his" : (ob->query_gender() == "female" ? "her" : "its"));
}
/* guildmaster's channel */
lmaster(str) {
  object ob;
  int i,sizeusers;
  ob = users();
  sizeusers = sizeof(ob);
  for(i = 0; i < sizeusers; i++)
    if(THERE(ob[i])) tell_object(ob[i], "[>Guildmaster<]: "+str+"\n");
  return 1;
}
checked_restore(gstatus) {
  status clean_out;
  switch(gstatus) {
  case 0:
    write("You are currently suspended from this guild.");
    clean_out = 1;
    break;
  case -1:
    write("You have been banished from this guild.");
    clean_out = 1;
    break;
  case -2:
    clean_out = 1;
    unjoin_player(ME);
    break;
  default: break;
  }
  if(clean_out)
    write("Mail Wizardchild if you have a problem with this.\n");
  return clean_out;
}
unjoin_player(ob) {
  THERE(ob)->set_gstatus(-1);
  ob->add_guild_exp(-THERE(ob)->query_gxp());
  ob->add_guild_rank(-THERE(ob)->query_grank());
  ob->set_guild_name(0);
  ob->set_guild_file(0);
  log_drop("dropped from guild",ob->query_real_name());
}
update_guild_stats(ob) {
  ob->set_guild_name("logger");
  ob->set_guild_file(ROOT_DIR+"guild_ob.c");
  ob->add_guild_rank(-ob->query_guild_rank());
  ob->add_guild_exp(-ob->query_guild_exp());
  ob->add_guild_rank(THERE(ob)->query_grank());
  ob->add_guild_exp(THERE(ob)->query_gxp());
}
handle_odd(func, arg) {
  return call_other(this_object(), map[func], arg);
}
/*>< END NON PLAYER COMMANDS ><*/

/*>< PET COMMANDS ><*/
/*Some clarification: these commands are routed throught the pets themselves*/
namepet(str) {
  object pet;
  pet = THERE(ME)->query_pet();
  if(!pet) {
    write("Hmm...you don't seem to have a pet.\n");
    return 1;
  }
  if(!pet->query_stable() && pet->query_mhp() % (random(3)+1)) pet->set_myname("foo");
  else pet->set_myname(str);
  write("Pet name set to "+pet->query_myname()+".\n");
  say(NAME+" changes his pet's name.\n");
  pet->init();
  return 1;
}
/* this configs the pet */
load_pet(ob) {
  object pet;
  int rank, stable, hp;
  string type;
  mapping ranks; 
  mapping hps;
  ranks = (["eagle":4, "beaver":3,"duck":2]);
  hps = (["eagle":150, "beaver":110,"duck":70]);
  if(!ob)
    return 0;
  pet = THERE(ob)->query_pet();
  if(!pet) {
    write("Hmm, you don't seem to have a pet...\n");
    return 0;
  }
  rank = THERE(ob)->query_grank();
  stable = THERE(ob)->query_stable_mode();
  pet->set_stable(stable);
  stable = !stable;
  type = pet->query_type();
  rank *= (ranks[type]);
  hp = (hps[type]+(stable*20));
  pet->set_name("pet");
  pet->set_ac(3);
  pet->set_can_kill(1);
  pet->set_ep(rank*5);
  pet->set_hp(hp);
  pet->set_wc(((3*rank/2) > 16 ? 16 : (3*rank/2)));
  pet->set_level((rank > 14 ? 14 : rank));
  move_object(clone_object(ROOT_DIR+"pet_toy"), pet);
  pet->home();
  return 1;
}
end_pet_fight(ob) {
  string owner;
  object atk;
  atk = ob->query_attack();
  if(!atk)
    return 0;
  owner = ob->query_owner();
  tell_object(PLAYER(owner), CP(ob->query_myname())+" tells you: I cannot lead in combat.\n");
  ob->stop_fight();
  atk->stop_fight();
  atk->attack_ob(PLAYER(ob->query_owner()));
  PLAYER(owner)->attack_ob(atk);
}
stop_pet_protect(ob) {
  object atk; 
  string owner;
  atk = ob->query_attack();
  owner = ob->query_owner();
  atk->attack_ob(PLAYER(owner));
  say(CP(ob->query_myname())+" stops protecting his owner.\n");
  tell_object(PLAYER(owner), CP(ob->query_myname())+" tells you: I can no longer protect you.\n");
}
petsay(str) {
  object pet;
  pet = THERE(ME)->query_pet();
  write(CP(pet->query_myname())+" tells you: "+str);
  return 1;
}
attack_msg(str) {
  string type;
  type = (THERE(ME)->query_pet())->query_type();
  if(type == "eagle")
    write("Your eagle comes circling out of the sky and lands its claws in "+CP(str)+"!\n");
  else if(type == "beaver")
    write("Your beaver waddles up to "+CP(str)+" and bites his ankle!\n");
  else
    write("Your duck comes screaming out of the sky and lands a crap on "+CP(str)+"!\n");
  return 1;
}
do_something(str) {
  int rf;
  string args;
  object pet, atk;
  pet = THERE(ME)->query_pet();
  if(!pet) {
    write("Hmm...you don't seem to have a pet.\n");
    return 1;
  }
  if(!str) {
    petsay("Did you want something?\n");
    return 1;
  }
  if(!pet->query_stable()) {
    rf = random(15);
    if(rf == 4) {
      petsay("Oh, that can wait until tommorrow.\n");
      say(CP(pet->query_myname())+" ignores his owner.\n");
      return 1;
    } else if(rf == 0 && random(20) <= 7) {
      petsay("I'm going out for lunch...\n");
      say(NAME+"'s pet goes out for lunch.\n");
      move_object(pet, "room/church");
      tell_room("room/church", CP(pet->query_myname())+" ran away from his owner.\n");
      return 1;
    }
  }
  if(sscanf(str, "say %s", args) == 1) {
    write("[Pet] "+CP(pet->query_myname())+" says: "+args+"\n");
    say("[Pet] "+CP(pet->query_myname())+" says: "+args+"\n");
  } else if(sscanf(str, "kill %s", args) == 1) {
    if(!ME->query_attack())
      petsay("You must remember, in combat, you're a leader, not a follower.\n");
    else if(!pet_ok_monster(args,pet) || (find_living(args) && find_living(args) != ME->query_attack()))
      petsay("I cannot fight that monster.("+pet_ok_monster(args,pet)+")\n");
    else {
      pet->set_fight(1);
      pet->attacked_by(find_living(args));
      find_living(args)->attacked_by(pet);
      pet->attack();
      attack_msg(args);
      pet->heart_on();
      say(NAME+" orders their pet to attack!\n");
    }
  } else if(sscanf(str, "follow %s", args) == 1) {
    if(args == "me") {
      pet->set_follow(1);
      pet->heart_on();
      petsay("I will now follow you.\n");
    } else if(args == "off") {
      pet->set_follow(0);
      petsay("I will no longer follow you.\n");
    } else
      petsay("I can only follow you.\n");
  } else if(str == "score") {
    write("Score for: "+CP(pet->query_myname())+"\n");
    write("Hps: "+pet->query_hp()+" of "+pet->query_mhp()+"\n");
    if(pet->query_fight())
      write("Atk: "+(pet->query_attack())->query_name()+"\n");
    write("Follow: "+(pet->query_follow() ? "On" : "Off")+"\n");
    write("Stable: "+(pet->query_stable() ? "On" : "Off")+"\n");
  } else if(str == "go home") {
    write(CP(pet->query_myname())+" gives you a final glance, and returns to the wild.\n");
    say(NAME+" releases "+query_gender_term(ME)+" pet.\n");
    THERE(ME)->dest_pet();
  } else if(str == "protect me") {
    if(pet->query_protect()) {
      petsay("I am allready protecting you.\n");
      return 1;
    }
    if(!ME->query_attack()) {
      petsay("Nobody is attacking you.\n");
      return 1;
    }
    if(ME->query_attack() == pet) return 0;
    write(CP(pet->query_myname())+" moves between you and your foe.\n");
    pet->set_protect(1);
    atk = PLAYER(pet->query_owner())->query_attack();
    atk->attack_ob(pet);
    pet->attack_ob(atk);
    pet->protect();
    say(NAME+" is guarded by "+query_gender_term(ME)+" pet.\n");
  } else
    petsay("I don't know how to do that.\n");
  return 1;
}
/*>< END PET COMMANDS ><*/

/*>< CABIN COMMANDS ><*/
/* note that all these commands are preceded by c_ and have ob as an arg */
c_enter(ob) {
  if(environment(ME) != ob) {
    write("You enter your cabin.\n");
    ME->move_player("to "+query_gender_term(ME)+" cabin#"+file_name(ob));
  } else return 0;
  return 1;
}
c_leave(ob) {
  if(environment(ME) == ob) {
    write("You leave the cabin.\n");
    if(present("cabin invite", ME)) {
      ME->move_player("the cabin#room/church");
      present("cabin invite", ME)->self_dest();
    } else {
      ME->move_player("the cabin#"+ROOM_DIR+"cabinrm.c");
    }
  } else return 0;
  return 1;
}
/* this involves a teleport, if this is a problem mail me */
c_invite(str,ob) {
  object who, inv;
  string where;
  int cost;
  if(environment(ME) != ob) return 0;
  who = PLAYER(str);
  if(!who) {
    write("That player was not found.\n");
    return 1;
  }
  if(who->query_level() >= 20 && who->query_real_name() != "wizardchild") {
    write("Wizards can get here by themselves.\n");
    return 1;
  }
  if(environment(who) == ob) {
    write("That player is allready here.\n");
    return 1;
  }
  where = file_name(environment(who));
  if(sscanf(where, "/players/wizardchild/closed/logger/%s", where) != 1)
    cost = 30;
  if(ME->query_sp() < cost) {
    write("You do not have enough spell points.\n");
    return 1;
  }
  ME->add_spell_point(-cost);
  inv = clone_object(CABIN_DIR+"invite.c");
  inv->set_cabin(ob->query_owner());
  inv->set_cabin_ob(ob);
  move_object(inv, who);
  tell_object(who, "You have been invited to "+NAME+"'s log cabin. Type 'visit_cabin', or\n");
  tell_object(who, "'dont_visit' to not visit. You have a limited amount of time to decide.\n");
  say(NAME+" invites someone.\n");
  write("You invite "+CP(str)+" to your cabin.\n");
  return 1;
}
c_list(str,ob) {
  object in_cabin;
  int i;
  if(str != "items") {
    write("Usage: list items\n");
    return 1;
  }
  in_cabin = ob->query_in_cabin();
  if(in_cabin[0])
    write("You have the following items in your cabin:\n");
  else
    write("You have nothing in your cabin.\n");
  for(i = 1; in_cabin[i-1]; i++) 
    write("<"+i+">: "+(in_cabin[i-1]->short())+"\n");
  return 1;
}
c_get_item(str,ob) {
  int i;
  object cob, *in_cabin;
  in_cabin = ob->query_in_cabin();
  if(sscanf(str, "%d", i) != 1) {
    if(str != "all") {
      write("Usage: get <#|all>\n");
      return 1;
    }
    for(i = 0; in_cabin[i]; i++) {
      cob = clone_object(in_cabin[i]);
      if(!ME->add_weight(cob->query_weight())) {
        write("You cannot carry any more.\n");
        destruct(cob);
      } else {
        write("You take: "+cob->short()+"\n");
        move_object(cob, ME);
        in_cabin[i] = 0;
      }
    }
    THERE(ME)->add_gpoints((-i*5 > THERE(ME)->query_gpoints() ? -THERE(ME)->query_gpoints() : -i*5));
  } else {
    if(i < 1 || i > 10) { 
      write("That is not a valid number.\n");
      return 1;
    }
    if(!in_cabin[i-1])
      write("You do not have that many items.\n");
    else {
      cob = clone_object(in_cabin[i-1]);
      if(!ME->add_weight(ob->query_weight())) {
        write("You cannot carry that much.\n");
        THERE(ME)->set_in_cabin(in_cabin);
        ob->set_in_cabin(in_cabin);
        return 1;
      }
      move_object(cob, ME);
      write("You focus briefly and retrieve "+cob->short()+" from your cabin.\n");
      THERE(ME)->add_gpoints(-10);
    }
  }
  for(i = 0; in_cabin[i]; i++) ;
  while(i < sizeof(in_cabin)) {
    in_cabin[i-1] = in_cabin[i];
    i++;
  }
  THERE(ME)->set_in_cabin(in_cabin);
  ob->set_in_cabin(in_cabin);
  return 1;
}
c_drop_item(str,ob) {
  int i,crap,cycle;
  string tmp;
  object cob,dumpob,*in_cabin;
  in_cabin = ob->query_in_cabin();
  for(i = 0; i < sizeof(in_cabin) && in_cabin[i]; i++) ;
  if(i == 10) {
    write("There is no more space.\n");
    return 1;
  }
  if(str == "all") {
    cob = first_inventory(ME);
    while(cob) {
      if(i == 10) {
        write("You can store no more objects.\n");
        THERE(ME)->set_in_cabin(in_cabin);
        ob->set_in_cabin(in_cabin);
        return 1;
      }
      if(cob->query_save_flag()) {
        write("This item cannot be stored.\n");
        cycle = 1;
      }
      if(cob->drop()) {
        write("You cannot drop this item.\n");
        cycle = 1;
      }
      if(!cycle) {
        sscanf(file_name(cob), "%s#%d", tmp, crap);
        in_cabin[i++] = tmp;
        dumpob = cob;
        ME->add_weight(-(cob->query_weight()));
      }
      cob = next_inventory(cob);
      if(dumpob) destruct(dumpob);
      cycle = 0;
    }
  } else {
    cob = present(str, ME);
    if(!cob) {
      write("You do not have that.\n");
      return 1;
    }
    if(cob->query_save_flag()) {
      write("That object cannot be stored.\n");
      return 1;
    }
    if(cob->drop()) {
      write("You cannot drop that.\n");
      return 1;
    }
    sscanf(file_name(cob), "%s#%d", tmp, crap);
    in_cabin[i] = tmp;
    ME->add_weight(-(cob->query_weight()));
    destruct(cob);
  }
  THERE(ME)->set_in_cabin(in_cabin);
  ob->set_in_cabin(in_cabin);
  return 1;
}
/*>< END CABIN COMMANDS ><*/

/*>< CHAR MANAGEMENT ><*/
/* auto save on exit */
end_game() { 
  object ob;
  THERE(ME)->save_me(); 
  if(THERE(ME)->query_pet()) {
    THERE(ME)->dest_pet();
    write("Your pet craps on your foot for neglecting it.\n");
    command("pretitle My pet crapped on my foot, says", ME);
  }
  if(THERE(ME)->query_has_truck()) {
    write("Your truck slips into a nearby canyon.\n");
    THERE(ME)->dest_truck();
  }
  ob = first_inventory(THERE(ME));
  if(ob) command("retrieve all", ME);
  lmaster(ME->query_name()+" has left for the forest.\n");
}
/* this produces: [<HP:xxx/xxx><SP:xxx/xxx><GP:xxx/xxx>] */
display_mon(ob) {
  tell_object(ob,"[<HP:"+ob->query_hp()+"/"+ob->query_mhp()+">");
  tell_object(ob, "<SP:"+ob->query_sp()+"/"+ob->query_msp()+">");
  tell_object(ob, "<GP:"+THERE(ob)->query_gpoints()+"/"+THERE(ob)->query_max_gpoints()+">]\n");
}
/*>< END CHAR MANAGEMENT ><*/

/*>< COMMON COMMANDS ><*/
/* toggle muffle */
lchan(str) {
  if(str == "off") {
    if(THERE(ME)->query_gmuffle()) write("You are already muffled.\n");
    else { write("You fill your ears with sap.\n"); THERE(ME)->set_gmuffle(1); }
  } else if(str == "on") {
    if(!THERE(ME)->query_gmuffle()) write("You are already on that channel.\n");
    else { write("You wash out your ears.\n"); THERE(ME)->set_gmuffle(0); }
  } else write("Usage: lchan <on|off>\n");
}
/* guild channel talk */
lt(str) {
  object ob;
  int i;
  int sizeusers;
  ob = users();
  sizeusers = sizeof(ob);
  for(i = 0; i < sizeusers; i++)
    if(THERE(ob[i]) && !THERE(ob[i])->query_gmuffle()) tell_object(ob[i], "[>"+NAME+"<]: "+str+"\n");
  return 1;
}
/* guild channel emote */
le(str) {
  object ob;
  int i;
  int sizeusers;
  ob = users();
  sizeusers = sizeof(ob);
  for(i = 0; i < sizeusers; i++)
    if(THERE(ob[i]) && !THERE(ob[i])->query_gmuffle()) tell_object(ob[i], "[<Logger>] "+NAME+" "+str+"\n");
  return 1;
}
/* help manager */
lhelp(str) {
  int worked;
  if(str == "gc") {
    if(THERE(ME)->query_grank() < 15) 
      write("There is no help on that topic.\n");
    else
      cat(HELP_DIR+str);
  } else {
    worked = cat(HELP_DIR+str);
    if(!worked) 
      write("There is no help on that topic.\n");
  }
  return 1;        
}
/* toggle pet mode */
stable_mode(str) {
  if(str == "on") {
      write("You are now in stable mode. Don't fear, your pets will be passive.\n");
      THERE(ME)->set_stable_mode(1);
  } else if(str == "off") {
      write("You are now in un-stable mode. Your pets will be stronger, but wilder.\n");
      THERE(ME)->set_stable_mode(0);
  } else 
    write("You are currently in "+(THERE(ME)->query_stable_mode() ? "stable" : "unstable")+" mode.\n");
  return 1;
} 
/* guild status */
guild_status() {
  object pet;
  string name,rank,xp,point,maxpt,pt,mufl,mon,stbl,aswp;
  int m;
  m = THERE(ME)->query_mon();
  name = extract("|Name: "+NAME+            "                       ",0,32);
  rank = extract("|Rank: "+THERE(ME)->query_grank()+    "                         ",0,32);
  xp   = extract("|Gexp: "+THERE(ME)->query_gxp()+      "                         ",0,32);
  point= extract("|Gpts: "+THERE(ME)->query_gpoints()+  "                         ",0,32);
  maxpt= extract("|Max : "+THERE(ME)->query_max_gpoints()+"                          ",0,32);
  mon  = extract("|Mon : "+(!m?"Off":(m==1?"Combat mode":"Always on"))+"               ",0,32);
  pet = THERE(ME)->query_pet();
  if(pet)
    pt = extract("|Pet : "+pet->query_myname()+"                       ",0,32);
  mufl = extract("|Muff: "+(THERE(ME)->query_muffle() ? "On" : "Off")+"                        ",0,32);
  stbl = extract("|Stbl: "+(THERE(ME)->query_stable_mode()?"On":"Off")+"                        ",0,32);
  m = THERE(ME)->query_autoswap();
  aswp = "|Aswp: "+(m?"On":"Off");
  if(m) aswp += ", "+(THERE(ME)->query_swap_amt())+" at "+(THERE(ME)->query_swap_at());
  aswp = extract(aswp+"                                                  ",0,32);
  write(">------Loggers Guild Status------<\n");
  write(name+ "|\n");
  write(rank+ "|\n");
  write(xp+   "|\n");
  write(point+"|\n");
  write(maxpt+"|\n");
  write(mon  +"|\n");
  if(pt) write(pt+"|\n");
  write(mufl+ "|\n");
  write(stbl+ "|\n");
  write(aswp+ "|\n");
  write(">--------------------------------<\n");
  return 1;
}
/* guild who */
lw() {                 
  object ob;
  int i, num;
  int sizeusers;
  string name,rank,location;
  ob = users();
  sizeusers = sizeof(ob);
  write(" ____________________________________________________________________________\n");        
  write("<______________________________Loggers guild who_____________________________>\n");
  write("[> Name:          Rank:    Location:                                        <]\n");     
  for(i = 0; i < sizeusers; i++) {
    if(THERE(ob[i]) && ob[i]->query_invis() < ME->query_level()) {
      name = extract(ob[i]->query_name()+"           ",0,15);
      rank = extract(THERE(ob[i])->query_grank()+"      ",0,6);
      location = extract(environment(ob[i])->short()+"                                                  ",0,48);
      write("[> "+name+rank+location+" <]\n");
      num++;
    } 
  }    
  write(" ____________________________________________________________________________\n");
  if(num > 9) 
    write("<_________________There are currently "+num+" loggers connected.___________________>\n");
  else
    write("<__________________There are currently "+num+" loggers connected.__________________>\n");
  return 1;
}
/* MUD who */
nwho() {
  object ob;
  int i, num;
  int sizeusers;
  string name,level,guild,location;
  ob = users();
  sizeusers = sizeof(ob);
  write(" ____________________________________________________________________________\n");        
  write("<_______________________________Loggers MUD who______________________________>\n");
  write(">Name:           Level:  Guild:         Location:                            <\n");
  for(i = 0; i < sizeusers; i++) {
    if(ob[i]->query_invis() < ME->query_level()) {
      name = extract(ob[i]->query_name()+"               ",0,15);
      level = extract(ob[i]->query_level()+"       ",0,7);
      if(ob[i]->query_guild_name()) 
        guild = extract(ob[i]->query_guild_name()+"           ",0,14);      
      else
        guild = "None           ";
      if(environment(ob[i]))
        location = extract(environment(ob[i])->short()+"                                 ",0,32);
      else location = extract("location unknown                             ",0,32);
      write("[> "+name+level+guild+location+" <]\n");
      num++;
    }
  }
  write(" ____________________________________________________________________________\n");        
  if(num > 9) 
    write("<_________________There are currently "+num+" players connected.__________________>\n");
  else
    write("<__________________There are currently "+num+" players connected._________________>\n");
  return 1;
}
/* store item in pack */
store(str) {
  object ob;
  if(!str) return 0;
  ob = present(str, ME);
  if(!ob) {
    write("You do not have that object.\n");
    return 1;
  }
  if(ob->drop()) {
    write("That item cannot be moved.\n");
    return 1;
  }
  write("You open up your backpack and throw your "+str+" in.\n");
  move_object(ob, THERE(ME));
  ME->add_weight(-(ob->query_weight()));
  say(NAME+" stores "+str+"\n");
  return 1;
}
/* get the item back */
retrieve(str) {
  object ob;
  if(!str) return 0;
  if(str == "all") {
    ob = first_inventory(THERE(ME));
    while(ob) {
      if(!ME->add_weight(ob->query_weight())) {
        write("You cannot carry any more.\n");
        break;
      }
      write("Retrieved: "+ob->short()+"\n");
      move_object(ob, ME);
      ob = next_inventory(ob);
    }
    say(NAME+" retrieves some items.\n");
    write("Done.\n");
    return 1;  
  }
  ob = present(str, THERE(ME));
  if(!ob) {
    write("You do not have that object stored.\n");
    return 1;
  }
  if(ob == THERE(ME)) {
    write("Ha, ha, ha. You make me laugh.\n");
    return 1;
  }
  if(!ME->add_weight(ob->query_weight())) {
    write("You cannot carry that much.\n");
    return 1;
  }
  write("You reach into your backpack and pull out "+str+"\n");
  move_object(ob, ME);
  say(NAME+" retrieves "+str+"\n");
  return 1;
}
/* update our stats */
new_pack() { 
  THERE(ME)->save_me(); 
  THERE(ME)->restore_player(ME->query_real_name()); 
  return 1; 
}
/*>< END COMMON COMMANDS ><*/

/*>< GUILD LOGGING COMMANDS ><*/
guild_bug(str) {
  write_it("Bug: "+str+"\n");
  write("Ok, thank you for reporting this bug.\n");
  return 1;
}
guild_typo(str) {
  write_it("Typo: "+str+"\n");
  write("Ok, thank you for reporting this typo.\n");
  return 1;
}
guild_comment(str) {
  write_it("Comment: "+str+"\n");
  write("Ok, thank you for your input.\n");
  return 1;
}
write_it(str) {
  write_file(ROOT_DIR+"PLAYER.BTC", "<"+ctime(time())+"> "+RLNAME+"; "+str);
  return 1;
}
log_drop(str, myname) {
  write_file(ROOT_DIR+"DROPPED", "<"+ctime(time())+"> ("+myname+") <-> "+str+"\n");
}
log_err(str, myname) {
  write_file(ROOT_DIR+"ERROR", "<"+ctime(time())+"> ("+myname+") <-> "+str+"\n");
}

/*>< END GUILD LOGGING COMMANDS ><*/

/*>< ABILITY CALLED COMMANDS ><*/
/* this just returns whether a player has at least x gps */
has_gp(x) {
  return (THERE(ME)->query_gpoints() >= x ? 1 : 0);
}
is_ok_monster(str) {
  return (find_living(str) && present(str, environment(ME)) && !find_living(str)->is_kid() && ME->valid_attack(find_living(str)));
}
pet_ok_monster(str,ob) {
  int x;
  x = 1;
  if(!find_living(str)) x = 0;
  write(x+",");
  if(!present(str, environment(ob))) x = 0;
  write(x+",");
  if(find_living(str)->is_kid()) x = 0;
  write(x+",");
  if(!ob->valid_attack(find_living(str))) x = 0;
  write(x+",");
  if(find_living(str) == PLAYER(str)) x = 0;
  write(x+"\n");
  return x;
/*  return (find_living(str) && present(str, environment(ob)) && !find_living(str)->is_kid() && ob->valid_attack(find_living(str)) && find_living(str) != PLAYER(str)); */
}
/* this docks amt hps from monster str, takes gp gps */
hit_monster(str,amt,gp) {
  object ob;
  if(!ME->query_attack()) {
    write("You must be fighting to use this spell.\n");
    return 2;
  }
  if(!str) str = LWR((ME->query_attack())->query_name());
  ob = present(str, environment(ME));
  if(!ob) {
    write("That monster is not here.\n");
    return 2;
  }
  if(!ME->valid_attack(ob)) {
    write("You cannot attack that!\n");
    return 2;
  }
  if(ob->is_kid()) {
    write("You cannot attack a kid.\n");
    return 2;
  }  
  if(!has_gp(gp)) {
    write("You do not have enough guild points.\n");
    return 2;
  }
  ob->attacked_by(ME);
  ob->hit_player(amt);
  THERE(ME)->add_gpoints(-gp);
  return 1;
}  
/*>< END ABILITY CALLED COMMANDS ><*/

/*>< RANK 1 COMMANDS ><*/
/* light spell */
light(str) {
  if(str != "fire" && str != "a fire") return 0;
  if(!has_gp(10)) {
    write("You do not have enough guild points.\n");
  } else {
    THERE(ME)->add_gpoints(-10);
    write("You grab a stick from the ground and wrap a cloth around it.\n");
    write("By knocking two stones together near the cloth, you manage to\n");
    write("create a source of light.\n");
    say(NAME+" creates a light source.\n");
    THERE(ME)->lights();  
  }
  return 1;
}
/* toggle monitor - 0 = off, 1 = combat, 2 = always */
toggle_mon(str) {
  int mon;
  if(!str) {
    mon = THERE(ME)->query_mon();
    write("Monitor is: ");
    if(mon == 0)      write("Always off.\n");
    else if(mon == 1) write("Combat only.\n");
    else              write("Always on.\n");
  } else if(str == "off") {
    THERE(ME)->set_mon(0);
    write("Monitor turned off.\n");
  } else if(str == "on") {
    THERE(ME)->set_mon(1);
    THERE(ME)->heart_on();
    write("Monitor set to combat mode.\n");
  } else if(str == "always on") {
    THERE(ME)->set_mon(2);
    THERE(ME)->heart_on();
    write("Monitor turned always on.\n");
  } else 
    write("Usage: mon <off|on|always on>\n");
  return 1;
}
/* set up follow */
set_follow(str) {
  string follow;
  follow = THERE(ME)->query_following();
  if(!str) {
    if(follow) write("Currently following: "+follow+".\n");
    else write("Not currently following anybody.\n");
  } else if(str == "off") {
    write("No longer following "+follow+".\n"); 
    THERE(ME)->set_following(0);
  } else {
    if(!PLAYER(str) || environment(PLAYER(str)) != environment(ME) || PLAYER(str)->query_invis() > ME->query_level()) 
      write("That player was not found.\n");
    else if(PLAYER(str)->query_level() >= 20) 
      write("You cannot follow a wizard.\n");
    else {
      tell_object(PLAYER(str), NAME+" begins following you.\n");
      THERE(ME)->set_following(str);
      THERE(ME)->heart_on();
      write("Now following: "+CP(str)+"\n");
    }
  }
  return 1;
}
/* forge command */
/* axe costs 500 coins+15 gpoints, hatchet is 350+10,knife is 250+10 */
forge(str) {
  object weap;
  int money, gp;
  string what;
  if(str == "axe" || str == "axe") {
    money = 500;
    gp = 15;
    what = "axe";
  } else if(str == "knife") {
    money = 250;
    gp = 10;
    what = str;
  } else if(str == "hatchet") {
    money = 350;
    gp = 10;
    what = str;
  } else {
    write("You are unable to forge that weapon.\n");
    return 1;
  }
  if(!has_gp(gp) || ME->query_money() < money) {
    write("You lack the funding to forge a "+what+".\n");
    return 1;
  }
  ME->add_money(-money);
  THERE(ME)->add_gpoints(-gp);
  write("You use your skills to start a small fire.\n");
  set_light(1);
  write("Carefully, you heat the "+money+" gold coins on nearby rocks.\n");
  write("You then take a heavy stick, and with some cheap iron ore, you melt the gold\n");
  write("onto the edge of the stick.\n");
  weap = clone_object(ROOT_DIR+"hot_weap.c");
  weap->set_type(what);
  move_object(weap, environment(ME));
  write("You must wait for your new weapon to cool off.\n");
  THERE(ME)->wait_func("cooled",gp,0);
  return 1;
}
/* this function lets the player grab the new weapon - note above */
cooled(x,ob) {
  object weap;
  string what;
  tell_object(ob, "Your weapon has cooled off.\n");
  weap = present("hot_weap", environment(ob));
  if(!weap) {
    log_err("hot weapon created but lost.");
    tell_object(ob,"Error: your weapon is missing from this area.\n");
    return 1;
  }
  what = weap->query_type();
  destruct(weap);
  weap = clone_object(ROOT_DIR+what+".c");
  move_object(weap, ob);
  say(ob->query_name()+" forges a "+what+".\n");
  return 1;
}
/* swap ability */
swap_gp(str) {
  int amt;
  if(sscanf(str, "%d hp", amt) == 1 && str == amt+" hp") {
    if(ME->query_hp() < amt-1) 
      write("You do not have enough hit points.\n");
    else if(amt <= 0) 
      write("Boy, aren't you funny.\n");
    else {
      ME->add_hit_point(-amt);
      THERE(ME)->add_gpoints(amt);
      say(NAME+" strengthens "+query_gender_term(ME)+" ability by weakening physically.\n");
      write("You concentrate briefly and feel weaker, but more capable.\n");
    }
  } else if(sscanf(str, "%d", amt) == 1 || sscanf(str, "%d sp", amt) == 1) {
    if(amt <= 0) 
      write("Boy, aren't you funny.\n");
    else if(ME->query_sp() < amt)
      write("You do not have enough spell points.\n");
    else {
      ME->add_spell_point(-amt);
      THERE(ME)->add_gpoints(amt);
      say(NAME+" strengthens "+query_gender_term(ME)+" ability by weakening mentally.\n");
      write("You concentrate breifly and feel dumber, but more capable.\n");
    }
  } else 
    write("Usage: gp <amt> [hp|sp]   (default is sp)\n");
  return 1;
}  
/*>< END RANK 1 COMMANDS ><*/

/*>< RANK 2 COMMANDS ><*/
/* throw wood chips at a foe */
chips(str) {
  if(hit_monster(str,(4+random(3)),10) == 2) return 1;
  write("You reach into your pocket and grab a handful of wood chips.\n");
  write("With great courage, you toss them in your opponents face!\n");
  write(CP(str)+" yells: You bastard! I'll kill your sorry ass!\n");
  say(NAME+" blinds "+CP(str)+" with a handful of wood chips!\n");
  return 1;
}
/* send on object/hp/sp/gp to another player (LARGE) */
send(str) {
  string who, what;
  object ob;
  int amt;
  if(sscanf(str, "%d %s to %s", amt, what, who) == 3) {
    if(!(what == "hp" || what == "sp" || what == "gp")) {
      write("You can only send hp, sp, and gp.\n");
      return 1;
    }
    if(amt <= 0) {
      write("Oh, boy, you're cool guy.\n");
      return 1;
    }
    ob = PLAYER(who);
    if(!ob) {
      write("That player could not be found.\n");
      return 1;
    }
    if(what == "hp") {
      if(ME->query_hp() < amt-1) {
        write("You do not have enough hit points.\n");
        return 1;
      }
      write("You call a red tailed hawk from the skys to help you.\n");
      write("As the hawk approaches, you strain physically and transfer "+amt+" hit points to\n");
      write("it. As if in acknowledgement, the hawk nods to you, and flys off to "+who+".\n");
      say(NAME+" is aided by a red tailed hawk.\n");
      ME->add_hit_point(-amt);
      if(!THERE(PLAYER(who))) { amt -= random(11); if(amt < 0) amt = 0; }
      PLAYER(who)->add_hit_point(amt);
      tell_object(PLAYER(who), "A red tailed hawk flies in from "+NAME+"s direction. He slowly lands\n");
      tell_object(PLAYER(who), "on your shoulder. He strains slightly, and you feel stronger.\n");
    } else if(what == "sp") {
      if(ME->query_sp() < amt) {
        write("You do not have enough spell points.\n");
        return 1;
      }
      write("You call a red tailed hawk from the skys to help you.\n");
      write("As the hawk approaches, you strain mentally and transfer "+amt+" spell points to\n");
      write("it. As if in acknowledgement, the hawk nods to you, and flys off to "+who+"\n");
      ME->add_spell_point(-amt);
      if(!THERE(PLAYER(who))) { amt -= random(11); if(amt < 0) amt = 0; }
      PLAYER(who)->add_spell_point(amt);
      tell_object(PLAYER(who), "A red tailed hawk flies in from "+NAME+"s direction. He slowly lands\n");
      tell_object(PLAYER(who), "on your shoulder. He strains slightly, and you feel smarter.\n");
    } else {
      if(!has_gp(amt)) {
        write("You do not have neough guild points.\n");
        return 1;
      }
      if(!THERE(PLAYER(who))) {
        write("That player is not a logger.\n");
        return 1;
      }
      write("You call a red tailed hawk from the skys to help you.\n");
      write("As the hawk approaches, your capability weakens, and "+amt+" guild points are\n");
      write("sent to it. As if in acknowledgement, the hawk nods to you, and flys off to "+who+"\n");
      THERE(ME)->add_gpoints(-amt);
      THERE(PLAYER(who))->add_gpoints(amt);
      tell_object(PLAYER(who), "A red tailed hawk flies in from "+NAME+"s direction. He slowly lands\n");
      tell_object(PLAYER(who), "on your shoulder. He strains slightly, and you feel more capable.\n");
    }
  } else if(sscanf(str, "%s to %s", what, who) == 2) {
    if(!PLAYER(who)) {
      write("That player could not be found.\n");
      return 1;
    }
    ob = present(what, ME);
    if(!ob) {
      write("You do not seem to have that.\n");
      return 1;
    }
    if(!has_gp(5)) {
      write("You need 5 gps for this command.\n");
      return 1;
    }
    write("You call a red tailed hawk from the skies to help you.\n");
    write("Carefully, you throw "+what+" into the air. With unnerving coordination,\n");
    write("the hawk catches it. He slowly flies off towards "+who+".\n");
    say(NAME+" is aided by a red tailed hawk.\n");
    THERE(ME)->add_gpoints(-5);
    move_object(ob, PLAYER(who));
    ob = PLAYER(who);
    tell_object(ob, "A hawk circles overhead.\n");
    tell_object(ob, "Slowly, it desends to your altitude. On its final circle, it drops\n");
    tell_object(ob, what+" in your hands.\n");
  } else {
    write("Usage: send <obj|amt> [hp|sp|gp] to <player>\n");
    write("As in: send 40 hp to bozo\n");    
    write("       send boogeyman to yomama\n");
  }
  return 1;
}
butcher() {
  object corpse;
  int amt;
  corpse = present("corpse", environment(ME));
  if(!corpse) corpse = present("corpse", ME);
  if(!corpse) {
    write("There is no corpse here to butcher.\n");
    return 1;
  }
  amt = THERE(ME)->query_guild_rank() * 2;
  amt = (amt > 10 ? 10 : amt);
  destruct(corpse);
  write("You butcher the corpse and eat the remains.\n");
  write("Survivalism sucks, eh?\n");
  say(NAME+" butchers a corpse.\n");
  THERE(ME)->add_gpoints(amt);
  return 1;
}
/* guild speedster */
truck() {
  object ob;
  if(THERE(ME)->query_has_truck()) {
    write("You allready have a truck!\n");
    return 1;
  }
  if(!has_gp(35)) {
    write("You lack the guild points to do that.\n");
    return 1;
  }
  ob = clone_object(ROOT_DIR+"speedster.c");
  ob->set_owner(ME->query_real_name());
  THERE(ME)->set_truck(ob);
  move_object(ob, environment(ME));
  write("You run to the local truck dealership and buy yourself a truck.\n");
  say(NAME+" buys a speedster.\n");
  THERE(ME)->add_gpoints(-35);
  return 1;
}
splinter(str) {
  if(hit_monster(str,(4+random(2)),10) == 2) return 1;
  write("You pick up a nearby stick and jam its splinters into your foe!\n");
  say(NAME+" drives some splinters into "+query_gender_term(ME)+" foe!\n");
  return 1;
}
autoswap(str) {
  if(!str) {
    write("Autoswapping is currently "+(THERE(ME)->query_autoswap()?"on":"off")+".\n");
    return 1;
  }
  if(str == "on")
    THERE(ME)->set_autoswap(1);
  else if(str == "off")
    THERE(ME)->set_autoswap(0);
  write("Autoswapping is now "+str+".\n");
  if(str == "on")
    write("Remember that autoswapping only works while in combat, or when following.\n");
  return 1;
}
/*>< END RANK 2 COMMANDS ><*/

/*>< RANK 3 COMMANDS ><*/
/* duck costs 1000 coins and 20 gpoints for 50+(rank*5) hps (max 80)    */
/* beaver costs 2000 coins and 40 gpoints for 90+(rank*5) hps (max 120) */
/* eagle costs 4000 coins and 60 gpoints for 160 hps                    */
/* duck = rank 3, beaver = rank 6, eagle = rank 9                       */
/* Unstable mode adds 20 hps for each pet                               */
call_pet(str) {
  object pt;
  if(!str) return 0;
  if(THERE(ME)->query_pet()) {
    write("You allready have a pet!\n");
    return 1;
  }
  pt = clone_object(ROOT_DIR+"pet.c");
  if(str == "duck" || str == "wood duck") {
    if(ME->query_money() < 1000 || !has_gp(20)) {
      write("You lack the resources to call this pet.\n");
      destruct(pt);
      return 1;
    }
    THERE(ME)->add_gpoints(-20);
    ME->add_money(-1000);
    write("You pull out your duck call.\n");
    write("QUACK QUACK QUACK\n");
    write("Your duck responds, and flys to the guild hall.\n");
    pt->set_type("Duck");
  } else if(str == "beaver" || str == "mountain beaver") {
    if(THERE(ME)->query_grank() < 6) return 0;
    if(!has_gp(40) || ME->query_money() < 2000) {
      write("You lack the resources to call this pet.\n");
      destruct(pt);
      return 1;
    }
    THERE(ME)->add_gpoints(-40);
    ME->add_money(-2000);
    write("You knock your fist on a nearby tree.\n");
    write("THUMP THUMP\n");
    write("In the distance, you can see your beaver running to the guild hall.\n");
    pt->set_type("Beaver");
  } else if(str == "eagle" || str == "bald eagle") {
    if(THERE(ME)->query_grank() < 8) return 0;
    if(!has_gp(60) || ME->query_money() < 4000) {
      write("You lack the resources to call this pet.\n");
      destruct(pt);
      return 1;
    }
    THERE(ME)->add_gpoints(-60);
    ME->add_money(-4000);
    write("You warm up your voice a little, and release a high pitched scream\n");
    write("EEEEEEEEEEEEEEEEEEEEEE!!!!\n");
    write("A nearby Eagle replies, and travels to the guild hall.\n");
    pt->set_type("Eagle");
  } else {
    write("There are no "+str+"s in the forest that reply to your calls.\n");
    destruct(pt);
  }
  if(pt) {
    THERE(ME)->set_pet(pt);
    pt->set_owner(RLNAME);
    say(NAME+" calls a pet.\n");
  }
  return 1;
}
/* swap <x>  - hp to sp */
swap(str) {
  int amt;
  if(!str) return 0;
  if(sscanf(str, "%d", amt) != 1) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(amt <= 0) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(ME->query_hp()-1 < amt) {
    write("You do not have enough hit points.\n");
    return 1;
  }
  ME->add_hit_point(-amt);
  ME->add_spell_point(amt);
  write("You concentrate breifly and feel smarter, but weaker.\n");
  say(NAME+" grows smarter.\n");
  return 1;
}
lheal(str) {
  int amt;
  if(!str) return 0;
  if(sscanf(str, "%d", amt) != 1) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(amt <= 0) { 
    write("That is not a valid number.\n");
    return 1;
  }
  if(ME->query_sp() < amt) {
    write("You do not have enough spell points.\n");
    return 1;
  }
  ME->add_hit_point(amt);
  ME->add_spell_point(-amt);
  write("You concentrate breifly and heal your wounds.\n");
  say(NAME+" grows stronger.\n");
  return 1;
}
/* create some armor */
flannel(str) {
  object ob;
  if(!has_gp(10)) {
    write("You do not have enough guild points.\n");
    return 1;
  }
  if(str == "jacket") {
    if(!has_gp(15)) 
      write("You do not have enough guild points.\n");
    else {
      THERE(ME)->add_gpoints(-15);
      ob = clone_object(ROOT_DIR+"fjacket.c");
      ob->set_owner(RLNAME);
      move_object(ob, ME);
      write("You pull out a large piece of flannel from your bag, and cut it into a jacket.\n");
      say(NAME+" cuts a jacket.\n");
    }
  } else if(str == "gloves") {
    THERE(ME)->add_gpoints(-10);
    ob = clone_object(ROOT_DIR+"fgloves.c");
    ob->set_owner(RLNAME);
    move_object(ob, ME);
    write("You pull out a small piece of flannel from your bag, and cut it into crude gloves.\n");
    say(NAME+" cuts a pair of crude gloves.\n");
  } else if(str == "hat") {
    THERE(ME)->add_gpoints(-10);
    ob = clone_object(ROOT_DIR+"fhat.c");
    ob->set_owner(RLNAME);
    move_object(ob, ME);
    write("You pull out a small piece of flannel from your bag, and cut it into a hat.\n");
    say(NAME+" cuts a hat.\n");
  } else 
    write("You can only cut a flannel hat, a flannel jacket, and a flannel pair of gloves.\n");
  return 1;
}
hall() {
  object env;
  env = environment(ME);
  if(!has_gp(30)) {
    write("You do not have enough ability points.\n");
    return 1;
  }
  if(env->realm()) {
    write("You cannot teleport from this room.\n");
    return 1;
  }
  THERE(ME)->add_gpoints(-30);
  write("You climb a nearby tree.\n");
  write("After some jumping around, you climb down a different tree into the guild\n");
  write("hall.\n");
  say(NAME+" climbs a nearby tree.\n");
  ME->move_player("swiftly#"+ROOM_DIR+"g_hall.c");
  say(NAME+" climbs down a nearby tree.\n");
  return 1;
}
gborrow(str) {
  object bank;
  int a;
  if(!str || !sscanf(str, "%d", a)) {
    write("Usage: borrow <amt>\n");
    return 1;
  }
  call_other(ROOT_DIR+"room/advance", "??");
  bank = present("bank", find_object(ROOT_DIR+"room/advance"));
  if(!bank) {
    write("Bank not found.\n");
    return 1;
  }
  if(a <= 0) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(a > bank->query_maxtake()) {
    write("You cannot take that many guild points at one time.\n");
    return 1;
  }
  if(a > bank->query_gp()) {
    write("There are not that many guild points.\n");
    return 1;
  }
  if(THERE(ME)->query_max_gpoints()-THERE(ME)->query_gpoints() < a) {
    write("You cannot take that many guild points.\n");
    return 1;
  }
  if(bank->add_gp(-a) != -a) 
    write("Error withdrawling guild points.\n");
  else {  
    write("You borrow "+a+" guild points.\n");
    lmaster(this_player()->query_name()+" borrows "+a+" guild points.\n");
    THERE(ME)->add_gpoints(a);
  }
  return 1;
}
gdonate(str) {
  int a;
  object bank;
  if(!str || !sscanf(str, "%d", a)) {
    write("Usage: donate <amt>\n");
    return 1;
  }
  call_other(ROOT_DIR+"room/advance", "??"); /* make sure it is loaded */
  bank = present("bank", find_object(ROOT_DIR+"room/advance"));
  if(!bank) {
    write("Bank not found.\n");
    return 1;
  }
  if(a <= 0) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(a+bank->query_gp() > 1000) {
    write("The bank cannot hold that many guild points.\n");
    return 1;
  }
  if(THERE(ME)->query_gpoints() < a) {
    write("You do not have that many guild points.\n");
    return 1;
  }
  if(bank->add_gp(a) != a) 
    write("Error donating guild points.\n");
  else {
    write("You donate "+a+" guild points.\n");
    THERE(ME)->add_gpoints(-a);
    lmaster(this_player()->query_name()+" donates "+a+" guild points.\n");
  }
  return 1;
}
/*>< END RANK 3 COMMANDS ><*/

/*>< RANK 4 COMMANDS ><*/
end_fight() {
  object ob;
  if(!has_gp(15)) { write("You do not have enough guild points.\n"); return 1; }
  THERE(ME)->add_gpoints(-15);
  ob = first_inventory(environment(ME));
  write("You stand between the fighting parties.\n");
  say(NAME+" steps between the feuding parties and forces them apart.\n");
  while(ob) { 
    if(living(ob) && ob->query_attack()) { (ob->query_attack())->stop_fight(); ob->stop_fight(); }
    ob = next_inventory(ob); 
  }
  say(NAME+" says: There will be no fighting in this room!\n");
  write("You say: There will be no fighting in this room!\n");
  return 1;
}
camp_out() {
  object ob, action;
  int i;
  if(environment(ME)->query_drop_castle()) {  
    write("You cannot camp out this close to town!\n");
    return 1;
  } 
  ob = first_inventory(environment(ME));
  while(ob) {
    if(ob != ME && living(ob)) {
      write("You cannot camp out when others are near!\n");
      return 1;
    }
    ob = next_inventory(ob);
  }
  if(!has_gp(20)) {
    write("You lack the 20 guild points to do this.\n");
    return 1;
  }
  THERE(ME)->add_gpoints(-20);
  write("You gather some sticks and some large branches.\n");
  write("Quickly, you group them together and lie down on them, resting your soul.\n");
  say(NAME+" camps out.\n");
  write("As you lay down, you feel the need to stay idle.\n");
  action = clone_object(ROOT_DIR+"no_action.c");
  /* this object will destruct itself if the player does anything */
  move_object(action, ME);
  for(i = 1; i <= 5; i++)
    THERE(ME)->wait_func("sleeping", i*10, i);
  return 1;
}
sleeping(i,ob) {
  object bleh;
  int num;
  sscanf(i, "%d", num);
  if(num < 5)
    tell_object(ob, "Sleeping...\n");
  else {
    bleh = present("no_action", ob);    
    if(!bleh) 
      tell_object(ob, "As you wake up, you still feel pained. Apparently, you were too active.\n");
    else {
      tell_object(ob, "You waken refreshed and smiling, feeling stronger than before.\n");
      ob->heal_self(40);
      destruct(bleh);
    }
  }
  return 1;
}
/* light stick on fire, burn foe with fire */
flame(str) {
  object atk;
  if(hit_monster(str,10+(random(15)),35) == 2) return 1;
  atk = ME->query_attack();
  write("You grab a stick and light it on fire!\n");
  write("With great courage, you wave the stick at your foe until it lights!\n");
  if(!atk) return 1;
  write(atk->query_name()+" is burnt severely!\n");
  say(NAME+" lights his foe on fire.\n");
  say(atk->query_name()+" is burnt severely!\n");
  return 1;
}
set_swap(str) {
  int amt, at;
  if(!str || sscanf(str, "%d %d", amt, at) != 2) {
    write("Usage: set_swap <amt> <at>\n");
    return 1;
  }
  if(amt <= 0 || at < 0) {
    write("Invalid number.\n");
    return 1;
  }
  if(at+amt > THERE(ME)->query_max_gpoints() ||
        amt > THERE(ME)->query_max_gpoints()) {
    write("You cannot overswap.\n");
    return 1;
  }
  THERE(ME)->set_swap_at(at);
  THERE(ME)->set_swap_amt(amt);
  write("Set to swap "+amt+" sp to gp when gp reach "+at+".\n");
  return 1;
}
/*>< END RANK 4 COMMANDS ><*/

/*>< RANK 5 COMMANDS ><*/
sharpen_weap(str) {
  object ob;
  ob = present(str, ME);
  if(!ob) {
    write("You do not have that.\n");
    return 1;
  }
  if(!ob->query_broke()) {
    write("That item is not broken.\n");
    return 1;
  }
  if(!has_gp(20)) {
    write("You need 20 ability points for this spell.\n");
    return 1;
  }
  THERE(ME)->add_gpoints(-20);
  write("You pick up some nearby stones, and using your skill, you sharpen the weapon\n");
  write("to a usable level.\n");
  ob->fix_weapon();
  return 1;
}
/* tree someone */
freeze(str) {
  string old_short;
  int wc, old;
  object ob;
  if(THERE(ME)->query_freeze()) {
    write("You have allready planted a monster.\n");
    return 1;
  }
  if(!str) return 0;
  if(!is_ok_monster(str)) {
    write("That is not a valid monster.\n");
    return 1;
  }
  ob = ME->query_attack();
  if(!ob || ob != present(str, environment(ME))) {
    write("You must be fighting before you use this spell.\n");
    return 1;
  }
  if(!has_gp(30)) {
    write("You do not have enough guild points.\n");
    return 1;
  }
  THERE(ME)->set_freeze();
  ob->attacked_by(ME);
  old = ob->query_wc();
  old_short = ob->short();
  write("You concentrate breifly, and "+str+" turns into a tree!\n");
  THERE(ME)->add_gpoints(-30);
  wc = old - THERE(ME)->query_grank();
  if(wc < 3) wc = 3;
  ob->set_wc(wc);
  ob->set_short(old_short+" <TREE>");
  THERE(ME)->wait_func("recover", 15, old+"|"+old_short+"|"+str);
  say(NAME+" turns "+query_gender_term(ME)+" foe into a tree!\n");
  return 1;
}
recover(amt,me) {
  object ob;
  string short, mn;
  int wc;
  sscanf(amt, "%d|%s|%s", wc, short,mn);
  ob = find_living(mn);
  if(ob) {
    ob->set_wc(wc);
    ob->set_short(short);
    tell_object(me, short+" breaks free from its shell!\n");
  }
  if(THERE(me)->query_freeze()) THERE(me)->set_freeze();
  return 1;
}
toss_log(str) {
  if(hit_monster(str,(random(5)),5) == 2) return 1;
  write("You wildly throw a log at your foe!\n");
  say(NAME+" wildly throws a log at "+query_gender_term(ME)+" foe.\n");
  return 1;
}  
/*>< END RANK 5 COMMANDS ><*/

/*>< RANK 6 COMMANDS ><*/
grow_bark() {
  int old_ac;
  int rank;
  if(THERE(ME)->query_ac_plus()) {
    write("You are allready using this spell.\n");
    return 1;
  }
  old_ac = ME->query_ac();  
  if(!has_gp(20)) {
    write("You do not have enough guild points.\n");
    return 1;
  }
  rank = THERE(ME)->query_grank();
  write("You use your ability to strengthen your skin.\n");
  write("As you watch, your skin becomes darker.\n");
  say(NAME+" grows darker.\n");
  ME->add_ac((rank/3));
  THERE(ME)->set_ac_plus();
  THERE(ME)->wait_func("back_ac", 20, old_ac);
  return 1;
}
back_ac(in,ob) {
  ob->set_ac(in);
  tell_object(ob, "The effect has worn off, and your skin returns to normal color.\n");
  say(ob->query_name()+" returns to normal.\n");
  if(THERE(ob)->query_ac_plus()) THERE(ob)->set_ac_plus();
  return 1;
}  
branch(str) {
  if(hit_monster(str,(7+random(6)),20) == 2) return 1;
  write("You look up into the sky, and high above see a branch.\n");
  write("Reaching into your pack, you grab your pocket knife, and throw it at the\n");
  write("base of the branch. It makes a clean cut, and the branch falls on your foe.\n");
  say(NAME+" drops a branch on "+query_gender_term(ME)+" foe!\n");
  return 1;
}
/*>< END RANK 6 COMMANDS ><*/

/*>< RANK 7 COMMANDS ><*/
snap(str) {
  if(hit_monster(str,(4+random(9)),17) == 2) return 1;
  write("You walk backwards a few steps and feel a branch against your back.\n");
  write("Slowly, you back up and make it bend, until...\n");
  write("S N A P ! ! !\n");
  write("The branch goes flying over your body and into your foe's face!\n");
  say(NAME+" thwaps "+query_gender_term(ME)+" foe with a twanged tree branch!\n");
  return 1;
}
sizeup(str) {
  int me, him;
  object h;
  me = (ME->query_level())+(ME->query_ac()*2)+(ME->query_wc()*2)+
       (ME->query_exp()/40000)+(THERE(ME)->query_grank())-30;
  if(!str || !find_living(str)) {
    write("Sizeup who?\n");
    return 1;
  }
  h = PLAYER(str);
  if(environment(h) == environment(ME))
    him = (h->query_level())+(h->query_ac()*2)+(h->query_wc()*2)+
          (h->query_exp()/40000)+(THERE(h) ? THERE(h)->query_grank()-30:0);
  else 
    write("That monster is not here.\n");
  if(him && me) {
    write("You evaluate "+CP(str)+" carefully, then look at yourself.\n");
    write("You have been given a combat score of "+me+".\n");
    write(CP(str)+" has been given a combat score of "+him+".\n");
  }
  return 1;
}
/*>< END RANK 7 COMMANDS ><*/

/*>< RANK 8 COMMANDS ><*/
/* land a tree on an opponent */
tree(str) {
  object ob;
  object ob2;
  if(!present("logger axe", ME)) {
    write("You must have an axe to use this command.\n");
    return 1;
  }
  ob2 = ME->query_attack();
  if(!ob2) {
    write("You must be fighting to use this spell.\n");
    return 1;
  }
  if(!str) str = LWR(ob2->query_name());
  if(!is_ok_monster(str)) {
    write("That is not a valid monster.\n");
    return 1;
  }
  if(!has_gp(40)) {
    write("You do not have enough ability points.\n");
    return 1;
  }
  ob = clone_object(ROOT_DIR+"tree.c");
  move_object(ob, environment(ME));
  THERE(ME)->add_gpoints(-40);
  write("You take your mighty axe and swing 180 degress, landing a fierce blow in a tree.\n");
  say(NAME+" begins to chop down a tree.\n");
  ob->attacked_by(ME);
  command("kill mooga", ME);
  return 1;
}

/* in tree.c, the monster should call monster_dead && this func */
finish_tree(me) {
  int i;
  object ob;
  tell_object(me,"As the tree falls to the ground, you jump out of the way!\n");
  i = random(9);
  ob = me->query_attack();
  if(i == 0) {
    if(hit_monster(LWR(ob->query_name()),(10+random(10)),0) == 2) return 1;
    tell_object(me, "The tree bairly knicks your foe!\n");
    say(me->query_name()+" bairly knicks "+query_gender_term(me)+" foe with a falling tree.\n");
  } else {
    if(hit_monster(LWR(ob->query_name()),(20+random(40)),0) == 2) return 1;
    tell_object(me,"The enormous tree lands directly on your foe!\n");
    say(me->query_name()+" lands a tree directly on "+query_gender_term(me)+" foe's head!\n");
  }
  return 1;
}      
/* big bad power spell - drops sta and str by 1 */
paul_bunyun(str) {
  if(hit_monster(str, (30+random(35)), 10) == 2) return 1;
  write("You scream at the top of your lungs for help!\n");
  write("While you are screaming, "+CP(str)+" slashes viciously at you!\n");
  write("You feel weeker!\n");
  ME->raise_stamina(-1);
  ME->raise_strength(-1);
  say(NAME+" screams:   H E L P ! ! ! ! ! ! ! ! !\n");
  write("Out of the forest comes Paul Bunyun! He immediately sees your pain,\n");
  write("pulls out his huge axe, and swipes at "+CP(str)+" with a fierce blow!\n");
  say("From nowhere, Paul Bunyun comes and slashes the hell out of "+CP(str)+"!\n");
  return 1;
}
/*>< END RANK 8 COMMANDS ><*/

/*>< RANK 15 COMMANDS (GC) ><*/
/* talk on GC channel */
lct(str) {
  object ob;
  int i;
  int sizeusers; /* Pathfinder 06-06-95 */
  ob = users();
  sizeusers = sizeof(ob); /* Pathfinder 06-06-95 */
/* Pathfinder 06-06-95 
  for(i = 0; i < sizeof(users()); i++) {
*/
  for(i = 0; i < sizeusers; i++) {
    if(THERE(ob[i]) && THERE(ob[i])->query_grank() >= 15)
        tell_object(ob[i], "[->"+NAME+"<-]: "+str+"\n");  
  }
  return 1;
}
/* emote on GC channel */
lce(str) {
  object ob;
  int i;
  int sizeusers; /* Pathfinder 06-06-95 */
  ob = users();
  sizeusers = sizeof(ob); /* Pathfinder 06-06-95 */
/* Pathfinder 06-06-95 
  for(i = 0; i < sizeof(users()); i++) {
*/
  for(i = 0; i < sizeusers; i++) {
    if(THERE(ob[i]) && THERE(ob[i])->query_grank() >= 15)
        tell_object(ob[i], "[>-<] "+NAME+" "+str+"\n");
  }
  return 1;
}
/* stat another logger */
gstat(str) {
  object plyr;
  if(!str) return 0;
  plyr = PLAYER(str);
  if(!plyr || plyr->query_invis() > ME->query_level()) {
    write("That player is not logged in.\n");
    return 1;
  }
  if(!THERE(plyr)) {
    write("That player is not a logger.\n");
    return 1;
  }
  write(">----------------------------------<\n");
  write("Name   : "+plyr->query_name()+"\n");
  plyr = THERE(plyr);
  write("Gxp    : "+plyr->query_gxp()+"\n");
  write("Rank   : "+plyr->query_grank()+"\n");
  write("Gpts   : "+plyr->query_gpoints()+"\n");
  write("Maxgpts: "+plyr->query_max_gpoints()+"\n");
  write("Muffle : ");
  write((plyr->query_gmuffle() ? "On" : "Off")+"\n");
  write(">----------------------------------<\n");
  return 1;
}
npack_all() {
  int i;
  int sizeusers; /* Pathfinder 06-06-95 */
  object ob;
  ob = users();
  sizeusers = sizeof(ob); /* Pathfinder 06-06-95 */
/* Pathfinder 06-06-95
  for(i = 0; i < sizeof(ob); i++) {
*/
  for(i = 0; i < sizeusers; i++) {
    if(THERE(ob[i]))
      npack(THERE(ob[i])->query_real_name());
  }
  return 1;
}
/* give a player a new pack */
npack(str) {
  object ob;
  if(str == "all")
    return npack_all();
  if(!str || !PLAYER(str) || PLAYER(str)->query_invis() > ME->query_level()) {
    write("Player not found.\n");
    return 1;
  }
  if(!THERE(PLAYER(str))) {
    if(PLAYER(str)->query_guild_name() == "logger") {
      write("This player is missing a guild object. Please notify Wizardchild. Object will be restored.\n");
      ob = clone_object(ROOT_DIR+"guild_ob.c");
      move_object(ob, PLAYER(str));
      tell_object(PLAYER(str), "You are given a new backpack.\n");
    } else
      write("That player is not a logger!\n");
    return 1;
  }
  write("Updating backpack...");
  ob = THERE(PLAYER(str));
  ob->save_me();
  write("All your items must be removed from your pack, to prevent against loss.\n");
  command("retrieve all", PLAYER(str));
  destruct(ob);
  ob = clone_object(ROOT_DIR+"guild_ob.c");
  move_object(ob, PLAYER(str));
  ob->restore_player(LWR(str));
  tell_object(PLAYER(str), "Your backpack has been updated.\n");
  return 1;
}
/* promote someone in guild */
gprom(str) {
  int amt;
  string who;
  if(!str || sscanf(str, "%s %d", who, amt) != 2) {
    write("Usage: gprom <who> <rnk>\n");
    return 1;
  }
  if(!PLAYER(who) || PLAYER(who)->query_invis() > ME->query_level()) {
    write("Player not found.\n");
    return 1;
  }
  if(who == "wizardchild" && ME->query_real_name() != who) {
    write("That's a bad way to use this function.\n");
    return 1;
  }
  if(!THERE(PLAYER(who))) {
    write("That player is not a logger!\n");
    return 1;
  }
  if(THERE(ME)->query_grank() < 20 && (amt > 8 || amt < 1)) {
    write("You cannot promote anybody to rank "+amt+".\n");
    return 1;
  }
  THERE(PLAYER(who))->set_grank(amt); 
  tell_object(PLAYER(who), "You have been promoted to rank "+amt+".\n");
  write("You promote "+CP(who)+" to rank "+amt+".\n");
  write_file(ROOT_DIR+"PROMO", "<"+ctime(time())+"> "+RLNAME+", "+who+", "+amt+".\n");
  return 1;
}
/*>< END RANK 15 COMMANDS ><*/

/*>< RANK 20 COMMANDS ><*/
banish(str) {
  object plyr;
  if(!str) return 0;
  plyr = PLAYER(str);
  if(!plyr) {
    write("Player not found.\n");
    return 1;
  }
  if(!THERE(plyr)) {
    write("Player is of a different guild.\n");
    return 1;
  }
  write("This function has been given to you for a purpose. Make sure you use it for\n");
  write("that purpose.\n");
  if(!plyr->set_gstatus(-2)) {
    write("Error banishing player.\n");
    write_file(ROOT_DIR+"BAN_ERR", ctime(time())+" "+ME->query_real_name()+", while banishing "+str+"\n");
  } else {
    write_file(ROOT_DIR+"BANISH", ctime(time())+" "+str+" was banished by "+ME->query_real_name()+"\n");
    plyr->save_me();
    plyr->restore_player();
  }
  return 1;
}
/* print current version */
guild_ver() {
  write(MVER+"\n");
  write(SVER+"\n");
  return 1;
}
/* The following is ONLY for me; gods have override (say your welcome) */
gob(str) {
  string who, what, args;
  int arg;
  object plyr;
  if(RLNAME != "Wizardchild" && ME->query_level() < 10000) return 0;
  if(sscanf(str, "%s %s %d", who, what, arg) == 3) {
    plyr = PLAYER(who);
    if(!plyr) {
      write("Player not logged in.\n");
      return 1;
    }
    if(!THERE(plyr)) {
      write("That player is not a logger.\n");
      return 1;
    }
    write("Player: "+who+"\n");
    write("Command: "+what+"; argument: "+arg+"\n");
    write("Returns: ");
    write(call_other(THERE(plyr), what, arg));
    write("\n");
  } else if(sscanf(str, "%s %s %s", who, what, args) >= 2) {
    plyr = PLAYER(who);
    if(!plyr) {
      write("Player not logged in.\n");
      return 1;
    }
    if(!THERE(plyr)) {
      write("That player is not a logger.\n");
      return 1;
    }
    write("Player: "+who+"\n");
    write("Command: "+what+"; argument: "+args+"\n");
    write("Returns: ");
    write(call_other(THERE(plyr), what, args));
    write("\n");
  } else
    write("Failed command.\n");
  return 1;
}
slogo(str) {
  string logo;
  logo = read_file(ROOT_DIR+"logo");
  if(find_living(str))
    tell_object(find_living(str), logo);
  else if(str == "shout")
    shout(logo);
  else if(str == "here")
    tell_room(environment(ME), logo);
  else
    write("Unknown channel.\n");
  return 1;
}
