#include "../DEFS.h"

#define PHASES ({"solosomatic", "metamorphic", "halcyon nexus", "neurosonic", "holotech", "robotronic", "synthellectual", "hyperdream", "androidal", "cybernautic", "teledigital", "deathmachine", "morpheus"})

string oldphase, phase;
string comstatus;
int phasenum;


status get()       { return 0; }
int query_weight() { return 0; }
int query_value()  { return 0; }


status id(string str)
{
  return str == "cyberdaemon" ||
         str == "CyberDaemon" ||
         str == "Cyberdaemon" ||
         str == "processor"   ||
         str == "computer"    ||
         str == "cpu"         ||
         str == "CYBERDAEMON";
}


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
"     You may view the system 'diags' to display the current phase.\n"+
"You may also view a list of all computation phases with 'phases'.\n"+
"CYBERDAEMON runs in cycles of repeating phases which act to change\n"+
"and control energy flow and network routing between CyberNinjas.\n");
}


init()
{
  add_action("readmap","diags");
  add_action("history",   "phases");
  if (TRN == OWNER1 || 
      TRN == OWNER2 ||
      TP->query_level() >= 100)
  {
     add_action("forcephase","reboot");
  }
}


reset(arg)
{
  computer_sequence();
  move_object(this_object(), GUILDLEAD);
}


void cyberdaemon_talk(string str)
{
  if (!str) return;
  call_other(CHANNELD, "overchannel", str);
}


void computer_sequence()
{
  string* phases;
  int tyme;

  phases = PHASES;

  /* get the current time in seconds, since 1970 */
  tyme = time();
  /* reduce it to the last 12 hours */
  while(tyme > 2147483647) tyme -= 2147483647;
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

  /* phases change every 1 hour */
  phase = phases[phasenum];

  if (phase != oldphase)
  {
   say("CyberDaemon says: phase transformation executed.\n");
/*
   cyberdaemon_talk(capitalize(phase)+" phase transformation executed\n");
*/
   oldphase = phase;
  }
  while(remove_call_out("computer_sequence") != -1);
/* Ghetto fix, use heart_beat to start call_out cause of ld castle loading -Bp
  call_out("computer_sequence", 300);
*/
  set_heart_beat(1);
}

heart_beat() {
/*
  call_out("computer_sequence", 300);
*/
  set_heart_beat(0);
}

string query_phase() { return phase; } /* let other objects find */
                                       /* out what phase it is   */
int query_phasenum() { return phasenum; } /* find out the number */
                                          /* of the phase it is in */


status forcephase()
{
  say(TPN+" tinkers with a few of CyberDaemon's switches and buttons.\n");
  write("Jumpstarting CyberDaemon phase sequence.\n");
  computer_sequence(); 
  return 1;
}


status history()
{
  int i;
  string msg;
  string *phases;
  phases = PHASES;
  msg = "Phase list of CyberDaemon:\n"+LINE;
  for (i=0; i < sizeof(phases); i++) msg+= "  "+capitalize(phases[i])+"\n";
  write(msg);
  return 1;
}


status readmap()
{
  say(TPN+" analyzes CyberDaemon.\n");
  write("~~~~~CyberDaemon Status~~~~~\n");
  write("Current Phase:  "+capitalize(phase)+"\n");
  write("Previous Phase: "+capitalize(oldphase)+"\n");
  return 1;
}
