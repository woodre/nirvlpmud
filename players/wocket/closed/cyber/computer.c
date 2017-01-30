#include "/players/dune/closed/guild/lib/DEFS.h"
#include "/players/dune/closed/guild/lib/COLOR.h"
#define DEST "/players/wocket/closed/cyber/computer_room.c"

get() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
id(str) { return str == "cyberdaemon" ||
                 str == "processor" ||
                 str == "computer" ||
                 str == "CYBERDAEMON"; }

string oldphase, phase;
string comstatus;
int tendnum, phasenum;
int shutdown;

short() { return "CYBERDAEMON, the CyberNinja Central Processor"; }
long() {
      write(   
"     CYBERDAEMON is the central processing unit for the CyberNinja\n"+
"guild. It towers high above and around you. Various sub-supercomputer\n"+
"hubs connect via white-hot high bandwidth links to create a web\n"+
"of pure computation. At the center, a black orb sparkles with\n"+
"multitudes of atomic stardust process executions. Within the dazzling\n"+
"black orb floats a tiny blue chrysanthemum. For along with all the\n"+
"incredible quantitative might before you, a precious natural element\n"+
"maintains a perfect system-wide balance.\n"+
"     You may view the system 'diags' to display the current computation\n"+
"phase. CYBERDAEMON runs in cycles of repeating phases which act to\n"+
"change and control energy flow and network routing between CyberNinjas.\n");
}

init() {
  add_action("readmap","diags");
  add_action("tend","tend");
  add_action("reboot","reboot");
  if( (RN == EMP1) || (RN == EMP2) ||
      (TP->query_level() >= 100) ) {
     add_action("forcephase","forcephase");
     add_action("history", "phases");
     }
  }

reset(arg) {
   computer_sequence();
    tendnum = 3;
   tending();
   move_object(this_object(),DEST);
   }

computer_sequence() {
  int tyme;

/* if it is shutdown we doing need to do all this */
    if (shutdown == 1){
    return 1;
    }
  /* get the current time in seconds, since 1970 */
  tyme = time();
  /* reduce it to the last 12 hours */
  while(tyme > 10000000000) tyme -= 10000000000;
  while(tyme > 1000000000) tyme -= 1000000000;
  while(tyme > 100000000) tyme -= 100000000;
  while(tyme > 10000000) tyme -= 10000000;
  while(tyme > 1000000) tyme -= 1000000;
  while(tyme > 100000) tyme -= 100000;
  while(tyme > 43200) tyme -= 43200;
  /* convert from seconds to hours */
  tyme = tyme / 3600;
  /* monthnum in a range of 0 to 12 hours */
  phasenum = tyme;

  switch(phasenum) {  /* phases change every 1 hour */
   case 0:      phase = "solosomatic"; break;
   case 1:      phase = "metamorphic"; break;
   case 2:      phase = "halcyon nexus"; break;
   case 3:      phase = "neurosonic"; break;
   case 4:      phase = "holotech"; break;
   case 5:      phase = "robotronic"; break;
   case 6:      phase = "synthellectual"; break;
   case 7:      phase = "hyperdream"; break;
   case 8:      phase = "androidal"; break;
   case 9:      phase = "cybernautic"; break;
   case 10:     phase = "teledigital"; break;
   case 11..12: phase = "deathmachine"; break;
   }

  if(phase != oldphase) {
   say("CyberDaemon says: phase transformation executed.\n");
   cyberdaemon_talk(CAP(phase)+" phase transformation executed\n");
   oldphase = phase;
   }
  call_out("computer_sequence", 300);
  return 1; 
}

int getcomstatus(){
if(tendnum){
switch(tendnum){
case 1..10:     comstatus = "nearing shutdown"; break;
case 11..50:    comstatus = "operating poorly"; break;
case 51..100:   comstatus = "operating moderatly"; break;
case 101..150:  comstatus = "operating smoothly"; break;
case 151..190:  comstatus = "operating effeciantly"; break;
case 191..200:  comstatus = "operating surpremely"; break;
}
}
return 1;
}

string query_phase() { return phase; } /* let other objects find */
                                       /* out what phase it is   */
string query_comstatus(){
return comstatus;
}
int query_phasenum() { return phasenum; } /* find out the number */
                                          /* of the phase it is in */
int query_tendnum() { return tendnum; }
int query_shutdown() { return shutdown;}

forcephase() { 
  say(TPN+" tinkers with a few of CyberDaemon's switches and buttons.\n");
  write("Jumpstarting CyberDaemon phase sequence.\n");
  computer_sequence(); 
  return 1; 
}

history() {
  write("Phase List of CyberDaemon:.\n");
  write(  "solosomatic\n"+
          "metamorphic\n"+
          "halcyon nexus\n"+
          "neurosonic\n"+
          "holotech\n"+
          "robotronic\n"+
          "synthellectual\n"+
          "hyperdream\n"+
          "androidal\n"+
          "cybernautic\n"+
          "teledigital\n"+
          "deathmachine\n");
  return 1;
}

readmap(){
  say(TPN+" analyzes CyberDaemon's diagnostics.\n");
  write("~~~~~CyberDaemon Diagnostics~~~~~\n");
    if(shutdown == 1){
  write("CyberDaemon is shutdown.\n");
  return 1;
}
getcomstatus();
  write("CyberDaemon is currently in "+CAP(phase)+" phase.\n");
  write("CyberDaemon is currently "+comstatus+".\n");
  return 1;
}

cyberdaemon_talk(str) {
  if(!str) return 1;
  overchannel("Msg from CyberDaemon: "+str+"\n");
  return 1;
}

overchannel(str) {
/* For announcements */
   object everyone, member;
   int i;
   everyone = users();
   for(i = 0; i < sizeof(everyone); i++) {
      member = present("implants", everyone[i]);
      if(member && member->muffled() < 1) 
        tell_object(everyone[i],
                 BLINK+BOLD+"<<_CYBERNET_>>>"+OFF+OFF+" "+str+"\n");
      }
   return 1;
}

int tend(string str){
    if (!str || str != "computer"){
       notify_fail("What would you like to tend?\n");
    return 0;
  }
if (shutdown == 1){
    notify_fail("The computer is shutdown.\nYou must reboot it.\n");
    return 0;
}
tendnum += 50+random(25);
  TP->add_spell_point(-20);
    write("You have tended to the computer.\n");
    say(this_player()->query_name()+" has tended to the computer.\n");
        cyberdaemon_talk("Updating new input\n");
return 1;
}

tending(){
    tendnum -= 1;
    if (tendnum == 0){
    shutdown = 1;
    cyberdaemon_talk("Shutting down\n");
    return 1;
}
    if (tendnum < 10) {
    cyberdaemon_talk("Shutdown in "+tendnum+" minutes.\n");
  }
  call_out("tending",60);
return 1;
}

int reboot(string str){
    if(!str || str != "computer"){
      notify_fail("What would you like to reboot?\n");
      return 0;
    }
       if(shutdown != 1){
         write("The computer is already active.\n");
     return 1;
    }
    cyberdaemon_talk("Rebooting...\n");
    shutdown = 0;
    tendnum = 10+random(50);

    this_player()->add_spell_point(-100-random(100));
    tending();
    computer_sequence();
    return 1;
}
