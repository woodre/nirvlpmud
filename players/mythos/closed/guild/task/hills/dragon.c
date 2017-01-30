#include "/players/mythos/closed/guild/def.h"
int mo, aa, bb, cc, dd, ff, viv, df, invis_level;
int wand, syy, wandr, sd_mode_num, form;
int listen;
int h;
object atts,inatt,shs,block;
string ttt;
string sd_name;
string RRN, follow_name;
object prev_room;

inherit "players/mythos/closed/guild/spells/monster2";

reset(arg) {
::reset(arg);
  if(arg) return;
    RRN = HIR;
    viv = 1;
    prev_room = 0;
    invis_level = 0;
    form = 0;
    listen = 1;
    df = wand = wandr = syy = sd_name = sd_mode_num = 0;
    ttt = 0;
    follow_name = RED+"Lilith"+NORM;
    set_name(RED+"Lilith"+NORM);
    set_race("dragon");
    set_alias("lilith");
    set_short(HIB+"Lilith"+NORM+" the "+HIR+"D"+NORM+RED+"rag"+NORM+"on");
    set_long("A large red dragon.  Glittering scales reflect your face\n"+
             "a thousand times.  The massive eyes that gaze back at you\n"+
             "seem deep, like that of DEATH itself.  Powerful muscles\n"+
             "ripple beneath the hard outer scales of this beast.\n");
    set_al(-10000);
    set_hp(20000);
    set_level(100);
    set_wc(90);
    set_ac(30);
    set_can_kill(1);
    set_heal(10,10);
    set_a_chat_chance(10);
    set_dead_ob(this_object());
    load_a_chat("The dragon roars!\n");
    load_a_chat("Razor sharp claws rip open the earth as the dragon attacks!\n");
    set_mass_chance(33);
    set_mass_dam(random(200)+20);
    set_mass_spell(BLU+"\n\t\t################################"+NORM+
                   HIR+"\n\t\tFIrE rains down upon everything!\n"+NORM+
                     BLU+"\t\t################################\n\n"+NORM); 
    set_chance(33);
    set_spell_dam(200);
    set_spell_mess1(RRN+"Flame blasts down upon the Dragon's enemy!\n"+NORM);
    set_spell_mess2(RRN+"Flame blasts into you!\n"+NORM);
    set_mult(4);
    set_mult_chance(50);
    set_mult_dam1(10);
    set_mult_dam2(100);
    mo = aa = bb = cc = dd = ff = 0;
    move_object(clone_object("/players/mythos/closed/play/key.c"),this_object());
    call_out("checks",3);
    call_out("battle",3);
}

id(str) { return str == "dragon" || str == "lilith" || str == "Lilith" ||
                   str == follow_name; }

query_real_name() { return follow_name; }

query_name() { return follow_name; }

init() {
  ::init();
#ifndef __LDMUD__
  add_action("exx");add_xverb("");
#else
 add_action("exx", "", 3);
#endif
  if(tl > 19) {
    add_action("ddest","destruct",3);
  }
  if(tpn == "mythos" || tpn == "priest" || tpn == "meshitsukai") {
    add_action("ddd","drag");
    add_action("dgg","dsp");
    add_action("did","din",);
    add_action("dmd","dmv");
    add_action("sic","sic");
    add_action("dfd","dfo");
    add_action("dw","wander");
    add_action("dm","spys");
    add_action("go","seek");
    add_action("shape","morph");
    add_action("llisten","ears");
    add_action("sd","s&d");
    add_action("ddt","track");
    add_action("lhelp","lilith");
  }
}

checks() {    
   switch(random(12)) {
     case 0: RRN = HIR; break;
     case 1: RRN = HIG; break;
     case 2: RRN = HIY; break;
     case 3: RRN = HIB; break;
     case 4: RRN = HIM; break;
     case 5: RRN = HIC; break;
     case 6: RRN = RED; break;
     case 7: RRN = GRN; break;
     case 8: RRN = YEL; break;
     case 9: RRN = BLU; break;
     case 10: RRN = MAG; break;
     case 11: RRN = CYN; break;
   }
   this_object()->set_spell_mess1(RRN+"Flame blasts down upon the Dragon's enemy!\n"+NORM);
   this_object()->set_spell_mess2(RRN+"Flame blasts into you!\n"+NORM);
   if(hit_point < 20000) {
   mo = mo + 1;
   if(mo > 10) {
     tell_room(ep,"The wounds of the DRAGON seem to heal at an astonishing rate!\n"); 
     hit_point = hit_point + 100 + random(100); 
     if(hit_point > 20000) hit_point = 20000;
     mo = 0; }
     } else { mo = 0; }
call_out("checks",3);
return 1;}

battle() {
if(sd_mode_num || query_attack()) {
   if(!prev_room) { 
     prev_room = ep;
     block = clone_object("/players/mythos/closed/play/blockage.c");
     block->start_block_shadow(ep);
   }
   if(prev_room != ep) {
     if(!living(ep)) {
         block = clone_object("/players/mythos/closed/play/blockage.c");
         block->start_block_shadow(ep);
     }
     prev_room = ep;
   }
   } 
inatt = this_object()->query_attack();
atts = all_inventory(ep);
     for(h=0;h<sizeof(atts);h++) {
       if(atts[h] != this_object()) {
        if(atts[h]->query_attack() && atts[h]->query_attack() == this_object()) {
         if(atts[h]->query_npc() && !present("adder",atts[h])) {
           move_object(clone_object("/players/mythos/closed/guild/spells/adder.c"),
                       atts[h]);
           shs = clone_object("/players/mythos/closed/guild/spells/wither.c");
           shs->start_heal_shadow(atts[h]);
         }
         if(atts[h]->query_hp() < 50 && atts[h] != this_object()->query_attack()) {
           atts[h]->heal_self(-50);
           hit_point = hit_point + 50;
           if(hit_point > 20000) hit_point = 20000;
           tell_room(ep,HIR+"The Dragon fries "+
                             capitalize(atts[h]->query_name())+
                            " with a bolt of "+NORM+BLU+"PURE ENERGY!\n"+NORM);
           tell_object(atts[h],
           "Suddenly a bolt of energy slams into you and everything goes black!\n");
         if(inatt) {
          this_object()->attack_object(atts[h]);
          this_object()->attack_object(inatt); 
         }
         else {
          this_object()->attack_object(atts[h]);
         }
         }
        }
     }
     }
calll_out("battle",3);
return 1;}

heart_beat() {
  if(!viv) viv = 1;
  if(form == 1) shape(0);
  remove_call_out("dddf");
  remove_call_out("wandering");
   if(this_object()->query_attack() == this_object()) {
     this_object()->stop_fight();
     tell_room(ep,"The dragon stops attacking itself and its wounds heal up!\n");
     hit_point = hit_point + 10000;
     if(hit_point > 20000) hit_point = 20000;
   }
   if(sd_mode_num) {
   if((this_object()->query_attack())->is_player() &&
      (this_object()->query_attack())->query_level() > 19) {
      move_object(clone_object("/players/mizan/closed/force-quit.c"),
      this_object()->query_attack());
      sd_mode_num = 0;
    } }
     if(!aa && hit_point < 16500) { 
       aa = 1; 
     (this_object()->query_attack())->add_exp(100000);
     }
     if(!bb && hit_point < 12500) { 
       bb = 1; 
     (this_object()->query_attack())->add_exp(100000);
     }
     if(!cc && hit_point < 8000) { 
       cc = 1; 
     (this_object()->query_attack())->add_exp(100000);
     }
     if(!dd && hit_point < 5000) { 
       dd = 1; 
     (this_object()->query_attack())->add_exp(100000);
     }
     if(!ff && hit_point < 1000) { 
       ff = 1; 
     (this_object()->query_attack())->add_exp(100000);
     }
if(hit_point < 800) { 
    tell_room(ep,HIR+"The DRAGON goes berzerk!\n"+NORM);
    this_object()->set_wc(150);
    this_object()->set_ac(40);
  } else {
  this_object()->set_wc(90);
  this_object()->set_ac(30); }
  ::heart_beat();
}

monster_died() {
object ssees;
int jij;
  write_file("/players/mythos/closed/guild/DRAGON",
    ctime(time())+" Main: "+(this_object()->query_attack())->query_real_name()+
    "\n");
    ssees = all_inventory(ep);
    for(jij = 0; jij < sizeof(ssees); jij++ ) {
      if(ssees[jij] != this_object() && 
         ssees[jij] != (this_object()->query_attack())) {
         write_file("/players/mythos/closed/guild/DRAGON",
         "\tOther: "+ssees[jij]->query_real_name()+"\n");
      }
    }
return 0;}

query_prevent_shadow() { return 1;}

destruct(object who) {
  if(who == this_object()) return 1;
}

query_invis() { 
  if(!viv) invis_level = 0;
  if(viv) invis_level = 100000;
  return invis_level; }

query_interactive(){
     return 1;}

zap_object() { return 1;}

run_away() { return 1;}

query_gender() { return "female"; }

hit_player(arg) {
  int damm;
  damm = arg;
  if(damm > 50) damm = 50;
  ::hit_player(damm);
}

heal_self(arg) {
  int much;
  much = arg;
  if(much < -50) much = -50;
  ::heal_self(much);
}

sic(str) {
  if(!str) return 0;
  if(present(str,ep)) {
    if(!living(present(str,ep))) { write(GRN+"Not living.\n"+NORM); return 1;}
    this_object()->attack_object(present(str,ep));
  return 1;}
  write(BLU+"Not here.\n"+NORM);
return 1;}

ddest(str) { 
   if(viv) { write(HIB+"Lilith's aura prevents you from doing that.\n"+NORM); 
          return 1;}
  if(!str) return 0;
  if(id(str)) { write(HIB+"Lilith's aura prevents you from doing that.\n"+NORM); 
          return 1;}
}

ddd(str) {
string what;
if(!str) return 0;
  if(sscanf(str,"get %s",what) == 1) {
    if(!present(what,ep)) { 
      tell_object(this_object(),"Not here to get.\n");
     return 1;}
     move_object(present(what,ep),this_object());
     if(viv && present(what,ep)->short()) 
       tell_room(ep,"Lilith takes "+present(what,ep)->short()+".\n");
     return 1;}
  if(sscanf(str,"drop %s",what) == 1) {
    if(!present(what)) { 
      tell_object(this_object(),"Not here to drop.\n");
     return 1;}
     move_object(present(what),ep);
     if(viv && present(what)->short()) 
       tell_room(ep,"Lilith drops "+present(what)->short()+".\n");
     return 1;}
  this_object()->init_command(str);
return 1;}

dgg(str) {
string line,msg,who,msg2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",line,msg) != 2) return 0;
  if(line == "g") line = "gossip";
  if(line == "r") line = "risque";
  if(line == "gossip" || line == "risque") {
    emit_channel(line,"Lilith "+line+"s: "+msg+"\n");
  return 1;
  }
  if(line == "ge") line = "gossip";
  if(line == "re") line = "risque";
  if(line == "gossip" || line == "risque") {
    emit_channel(line,"("+line+") Lilith "+msg+"\n");
   return 1;
  }
  if(line == "say" || line == "'") {
    tell_room(ep,"Lilith says: "+msg+"\n");
    return 1;
  }
  if(line == "e" || line == ":") {
    tell_room(ep,"Lilith "+msg+"\n");
    return 1;
  }
  if(line == "tell" || line == "t" || line == "fe") {
    if(sscanf(msg,"%s %s",who,msg2) != 2) return 0;
    if(!find_player(who)) { write("Not here to communicate.\n") ; return 1;}
    if(line == "fe") {
    tell_object(find_player(who),"Lilith "+msg2+" from afar.\n");
    tell_object(this_object(),"You "+who+": "+msg2+" from afar.\n");
    return 1;}
    tell_object(find_player(who),"Lilith tells you: "+msg2+"\n");
    tell_object(this_object(),"You tell "+who+": "+msg2+"\n");
    return 1;
  }
  write("Wrong command.\n");
return 1;} 

did(arg) {
  if(!arg) { 
    if(viv != 1) {
    write("Invis off\n");
    tell_room(ep,"Lilith fades into existance.\n");
    this_object()->set_chat_chance(10);
    viv = 1;
    if(form == 0) {
    this_object()->set_short(HIB+"Lilith"+NORM+" the "+HIR+"D"+NORM+RED+"rag"+NORM+"on");
            this_object()->set_long("A large red dragon.  Glittering scales reflect your face\n"+
             "a thousand times.  The massive eyes that gaze back at you\n"+
             "seem deep, like that of DEATH itself.  Powerful muscles\n"+
             "ripple beneath the hard outer scales of this beast.\n");
     }
    if(form == 1) { this_object()->set_short("Lilith the Ravish");
            this_object()->set_long(""+
            "Before you stands a most erotic sight.  Long dark hair\n"+
            "cascades down a body so breathtaking.  Eyes of brightest\n"+
            "green gaze at you with an intensity that infames your \n"+
            "desires.  Features so delicate and yet so sensous seem\n"+
            "to cry out for your touch.  She is all that one could ever\n"+
            "want, all that one could ever dream.\n"); 
    }
    }
    return 1;}
    if(viv != 0) {
    write("Invis on.\n");
    viv = 0;
    this_object()->set_chat_chance(0);
    tell_room(ep,"Lilith vanishes.\n");
    this_object()->set_short(); }
return 1;}

dmd(str) {
  if(!str) { 
    if(!viv) { move_object(this_object(),"/players/mythos/prac/test.c"); return 1;}
    else { this_object()->move_player("up#players/mythos/prac/test.c"); return 1;}
  return 1;}
  if(str == "church") {
  if(viv) { this_object()->move_player("church#room/church.c"); return 1;}
  else { move_object(this_object(),"/room/church.c"); return 1;}
  return 1;}
  if(viv && form == 0) tell_room(ep,"Lilith flows out of the room.\n");
  if(viv && form == 1) tell_room(ep,"Lilith walks out of the room.\n");
  move_object(this_object(),str);
  if(viv && form == 0) tell_room(ep,"Lilith flows into the room.\n");
  if(viv && form == 1) tell_room(ep,"Lilith steps into the room.\n");
return 1;}

dfd() {
  if(!df) {
    write("Lilith now follows you.\n");
    df = 1;
    call_out("dddf",3);
  return 1;}
  else {
    write("Lilith no longer follows you.\n");
    df = 0;
    remove_call_out("dddf");
  return 1;}
return 1;}

dddf() {
if(!find_player("mythos")) { viv = 0; dmd("/room/void.c"); return 1;}
  if(ep != environment(find_player("mythos"))) {
  if(viv &&  form == 0) tell_room(ep,"Lilith flows out of the room.\n");
  if(viv &&  form == 1) tell_room(ep,"Lilith walks out of the room.\n");
  move_object(this_object(),environment(find_player("mythos")));
  if(viv && form == 0) tell_room(ep,"Lilith flows into the room.\n");
  if(viv &&  form == 1) tell_room(ep,"Lilith steps into the room.\n");
  if(!viv) tell_object(find_player("mythos"),
    "Lilith whispers: I'm here, dear.\n");
  }
call_out("dddf",3);
return 1;}

go(str) {
object targ;
  targ = find_player(str);
  if(!targ) { 
    if(find_player("mythos")) {
    tell_object(find_player("mythos"),"Can not go to "+str+".\n");
    }
    if(find_player("priest")) {
    tell_object(find_player("priest"),"Can not go to "+str+".\n");
    }
    if(find_player("meshitsukai")) {
    tell_object(find_player("meshitsukai"),"Can not go to "+str+".\n");
    }
  return 1;}
  if(ep == environment(targ)) { return 1; }
  if(viv && form == 0) tell_room(ep,"Lilith flows out of the room.\n");
  if(viv && form == 1) tell_room(ep,"Lilith walks out of the room.\n");
  follow_name = str;
  move_object(this_object(),environment(targ));
  follow_name = RED+"Lilith"+NORM;
  if(viv && form == 0) tell_room(ep,"Lilith flows into the room.\n");
  if(viv && form == 1) tell_room(ep,"Lilith steps into the room.\n");
return 1;}

dw(str) {
int po; 
 if(!str) po = 3;
 if(str) sscanf(str,"%d",po);
  if(po == 1) {
  remove_call_out("wandering");
   wandr = 2; write("Wander mode on <includes wizes>.\n"); 
  call_out("wandering",3); return 1;}
  if(po == 0) { wandr = 1; write("Wander mode on.\n"); 
  call_out("wandering",3); return 1;}
  wandr = 0;
  remove_call_out("wandering");
  write("Wander mode off.\n");
return 1;}

lhelp() {
  write("Following commands are:\n"+
        "  sic <name>   attacks another\n"+
        "  drag <command>  commands lilith\n"+
        "  dps  <messege>  makes Lilith speak\n"+
        "       g ge r re ' : t fe\n"+
        "  din  <arg>      invisibility\n"+
        "  dmv  <string>   moves Lilith\n"+
        "  dfo             follow toggle\n"+
        "  seek  <name>    goto player name\n"+
        "  track  <name>   tracks player name\n"+
        "  ears            toggles listen mode\n"+
        "  spys            toggle spy mode\n"+
        "  morph <int>     shape change\n"+
        "         0 = dragon, 1 = woman\n"+
        "  s&d   <name>    search and destroy\n"+
        "  wander <int>    toggles wander mode\n"+
        "         1 includes wizes, 0 doesnt\n"+
        "         anything else turns it off\n");
return 1;}

wandering() {
object fools;
int zz;
fools = users();
zz = random(sizeof(fools));
if(wandr == 0) return 1;
if(fools[zz]->query_level() > 19 && wandr == 1) {
  call_out("wandering",10);
return 1;}
go(fools[zz]->query_real_name());
call_out("wandering",100 + random(100));
return 1;}

sd(str) {
  if(!str) return 0;
  if(str == "unagi") { 
  remove_call_out("sd_mode"); sd_mode_num = 0; 
  write("S&D mode off\n"); return 1;}
  if(!find_player(str)) { write("NOT IN PLAY.\n"); return 1;}
  if(str == "mythos") return 1;
  go(str);
  sd_mode_num = 1;
  wandr = 0;
  this_object()->attack_object(present(str,ep));
  sd_name = str;
  call_out("sd_mode",3);
return 1;}

dm() { 
  if(syy) { syy = 0; write("Spy mode off.\n"); return 1;}
  syy = 1;
  write("Spy mode on.\n");
return 1;}

exx(str) {
if(syy) {
  write_file("/players/mythos/closed/play/tell/lilith",
       ctime(time())+" "+tpn+"  "+str+"\n");
}
}

sd_mode() {
if(sd_mode_num == 0) return 1;
  if(!find_player(sd_name)) {
    dmd("/room/void.c");
    call_out("sd_mode",10);
  return 1;}
  if(ep != environment(find_player(sd_name))) {
    viv = 1;
    go(sd_name);
  }
  if(this_object()->query_attack()) {
    if(!((this_object()->query_attack())->id(sd_name))) {
      this_object()->attack_object(present(sd_name,ep));
    } 
    if(this_object()->query_attack() != find_player(sd_name)) {
      destruct(present(sd_name,ep));
    }
  } else {
    this_object()->attack_object(present(sd_name,ep));
  }
call_out("sd_mode",10);
return 1;}

ddt(str) {
string hey,ho;
  if(!str) { write("Tracking off.\n"); ttt = 0; remove_call_out("tracking"); return 1;}
  if(sscanf(str,"%s %s",hey,ho) != 2) return 0;
  write("tracking "+str+"\n");
  remove_call_out("tracking");
  tracked(str);
return 1;}

tracked(str) {
int seker;
 seker = 0;
  sscanf(str,"%s %d",ttt,seker);
  if(seker != 0) seker = 1;
  if(!find_player(ttt)) { 
    if(find_player("mythos")) {
    tell_object(find_player("mythos"),"Can not go to "+ttt+".\n");
    }
    if(find_player("priest")) {
    tell_object(find_player("priest"),"Can not go to "+ttt+".\n");
    }
    if(find_player("meshitsukai")) {
    tell_object(find_player("meshitsukai"),"Can not go to "+ttt+".\n");
    }
    dmd("/room/void.c");
    did(1);
    ttt = 0;
  return 1;}
  did(!seker);
  syy = 1; 
  go(ttt);
call_out("tracking",3);
return 1;}

tracking() {
if(!find_player(ttt)) { 
    if(find_player("mythos")) {
    tell_object(find_player("mythos"),"Can not go to "+ttt+".\n");
    }
    if(find_player("priest")) {
    tell_object(find_player("priest"),"Can not go to "+ttt+".\n");
    }
    if(find_player("meshitsukai")) {
    tell_object(find_player("meshitsukai"),"Can not go to "+ttt+".\n");
    }
    dmd("/room/void.c");
    ttt = 0;
  return 1;}
  go(ttt);
call_out("tracking",3);
return 1;}

shape(str) {
string mop;
  if(!str) return 0;
  sscanf(str,"%d",form);
  switch(form) {
    case 0: this_object()->set_short(HIB+"Lilith"+NORM+" the "+HIR+"D"+NORM+RED+"rag"+NORM+"on");
            this_object()->set_long("A large red dragon.  Glittering scales reflect your face\n"+
             "a thousand times.  The massive eyes that gaze back at you\n"+
             "seem deep, like that of DEATH itself.  Powerful muscles\n"+
             "ripple beneath the hard outer scales of this beast.\n");
             mop = "Suddenly, Lilith grows.\n"+
                   "What was a ravishing woman now is a greeat beast that\n"+
                   "towers over you- terror fills your being!\n";
             break;
    case 1: this_object()->set_short("Lilith the Ravish");
            this_object()->set_long(""+
            "Before you stands a most erotic sight.  Long dark hair\n"+
            "cascades down a body so breathtaking.  Eyes of brightest\n"+
            "green gaze at you with an intensity that infames your \n"+
            "desires.  Features so delicate and yet so sensous seem\n"+
            "to cry out for your touch.  She is all that one could ever\n"+
            "want, all that one could ever dream.\n"); 
            mop = "The Dragon's eyes flash and suddenly its form wavers.\n"+
                  "Everything goes dark for a second....\n"+
                  "No longer towers a dragon of great strength and power,\n"+
                  "instead in its place stands a woman.\n";
            break;
  }
  if(viv) tell_room(ep,mop);
  if(!viv) { if(find_player("mythos")) 
    tell_object(find_player("mythos"),"Lilith is in form "+form+"\n");
  }
return 1; }


llisten() {
  if(!listen) { listen = 1; write("Ears on.\n");}
  else { listen = 0; write("Ears off.\n");
  }
return 1; }

catch_tell(str) {
    string who, what;
    if (sscanf(str, "%s tells you: %s", who, what) == 2) {
    if(find_player("mythos")) {
    tell_object(find_player("mythos"),
    RED+capitalize(who)+" tells Lilith: "+what+"\n"+NORM);
    }
    if(find_player("priest")) {
    tell_object(find_player("priest"),
    RED+capitalize(who)+" tells Lilith: "+what+"\n"+NORM);
    }
    if(find_player("meshtsukai")) {
    tell_object(find_player("meshitsukai"),
    RED+capitalize(who)+" tells Lilith: "+what+"\n"+NORM);
    }
    }
    else {
    if(listen) {
      if(find_player("mythos")) {
      tell_object(find_player("mythos"),
      RED+"Lilith hears: "+str+"\n"+NORM);
      }
      if(find_player("priest")) {
      tell_object(find_player("priest"),
      RED+"Lilith hears: "+str+"\n"+NORM);
      }
      if(find_player("meshtsukai")) {
      tell_object(find_player("meshitsukai"),
      RED+"Lilith hears: "+str+"\n"+NORM);
      }
    } else { return; }
    }
    return;
}
