#include "/players/forbin/ansi.h"

#define ROOT "/players/forbin/realms/"
#define FOREST ROOT+"flame_forest/RMS/"
#define SAL ROOT+"salam/RMS/"
#define RUINS ROOT+"ruins/RMS/"

string File;      /* File name of room object */  
string *Allowed;  /* Array of people allowed to use this */
int TimerLength;  /* Length of time between cycles */
int Timer;        /* Counter of time between cycles */
string Report;    /* Report flag, valid flags:  off, long, and short */

/* Prototype Declaration */
void cycle_reset(string file);

id(str) { return (str == "cycle daemon"); }

short() { 
  return HBRED+HIR+"Reset Cycle Daemon ["+HBRED+HIW+Timer+HBRED+HIR+"/"+
         HBRED+HIW+TimerLength+HBRED+HIR+
         "]|||["+HBRED+HIW+((Timer * 100) / TimerLength)+"%"+HBRED+HIR+"]|||["+HBRED+HIW+
         (-(Timer - TimerLength))+HBRED+HIR+"]"+NORM;  
}

query_prevent_shadow() { return 1; }

void long() { 
  if(this_player() && this_player()->query_level() > 99) {
    tell_object(this_player(),
      HBRED+HIR+"\n                                                     \n"+
      HBRED+HIW+"            Forbin's Reset Cycle Daemon              \n"+HBRED+HIR+
      " This device controls the reset cycle for the areas  \n"+
      " of the Wizard Forbin.  If you don't know what you   \n"+
      " are messing with, the best advice would be to leave \n"+
      " well enough alone.                                  \n"+
      "   To start the Daemon:      '"+HBRED+HIW+"start_cycle"+HBRED+HIR+"'           \n"+
      "   To stop the Daemon:       '"+HBRED+HIW+"stop_cycle"+HBRED+HIR+"'            \n"+
      "   To reset Flame Forest:    '"+HBRED+HIW+"cycle forest"+HBRED+HIR+"'          \n"+
      "   To reset Salamite Caves:  '"+HBRED+HIW+"cycle salamite"+HBRED+HIR+"'        \n"+
      "   To reset The Ruins:       '"+HBRED+HIW+"cycle ruins"+HBRED+HIR+"'           \n"+
      "   To reset entrance/                                \n"+
      "              heal shack     '"+HBRED+HIW+"cycle main"+HBRED+HIR+"'            \n"+
      "   To reset all areas:       '"+HBRED+HIW+"cycle all"+HBRED+HIR+"'             \n"+
      "                                                     \n"+
      "     '"+HBRED+HIW+"set_time <#>"+HBRED+HIR+"'      sets Timer to #             \n"+
      "     '"+HBRED+HIW+"set_length <#>"+HBRED+HIR+"'    sets TimeLength to #        \n"+
      "     '"+HBRED+HIW+"check_time"+HBRED+HIR+"'        shows Timer and TimerLength \n"+
      "     '"+HBRED+HIW+"set_report <arg>"+HBRED+HIR+"'  sets the reporting feature  \n"+
      "        valid args:  "+HBRED+HIW+"off"+HBRED+HIR+", "+HBRED+HIW+"short"+
      HBRED+HIR+", "+HBRED+HIW+"long                \n"+
      HBRED+HIR+"                                                     \n"+NORM);
  }
}

status drop() { return 0; }
status get() { return 0; }

init() {
  if(!query_allowed(this_player()->query_real_name())) return 1;
  add_action("cmd_start_cycle","start_cycle");
  add_action("cmd_stop_cycle","stop_cycle");
  add_action("cmd_cycle","cycle");
  add_action("cmd_set_time","set_time");
  add_action("cmd_set_length","set_length");
  add_action("cmd_check_time","check_time");
  add_action("cmd_set_report","set_report");
}

void reset(int arg) { 
  if(arg) return; 
  Timer = 0;
  TimerLength = 780; /* defaults to 39 minutes */
  Allowed = ({ "forbin", "boltar", "fred" });
  Report = "short";
}

status query_allowed(string name) {
  if(!Allowed || !sizeof(Allowed)) 
    return 0;
  if(index(Allowed, name) > -1) 
    return 1;
  else
    return 0;
}

void set_fake_hb(int arg) {
  while(remove_call_out("fake_hb") != -1) ;
  if(arg) call_out("fake_hb", 3);
}

status cmd_set_report(string arg) {
  if(arg == "off") Report = "off";
  else if(arg == "short") Report = "short";
  else if(arg == "long") Report = "long";
  else {
    tell_room(environment(this_object()),
      "Valid reporting arguments are:  off, short, long\n"+
      "Reporting set to: 'short' by default.\n");
    Report = "short";
    return 1;
  }
  tell_room(environment(this_object()),
    "Reporting set to: '"+arg+"'.\n");
  return 1;
}

status cmd_start_cycle()  {
  set_fake_hb(1);
  tell_room(environment(this_object()),
    "Reset Cycle Daemon Fake HB Started.\n");
  return 1;
}

status cmd_stop_cycle()  {
  set_fake_hb(0);
  tell_room(environment(this_object()),
    "Reset Cycle Daemon Fake HB Stopped.\n");
  return 1;
}

status cmd_check_time() {
  tell_object(this_player(),
    "\n    Current TimeLength set to:  "+TimerLength+"\n"+
    "    "+Timer+" increments have gone by.\n"+
    "    "+(TimerLength - Timer)+" increments left to go before next cycle.\n");
  return 1; 
}

status cmd_set_time(string arg) {
  int num;
  if(!arg) return 0;
  sscanf(arg, "%d", num);
  if(num > TimerLength) num = TimerLength - 1;
  if(num < 1) num = 1;
  Timer = num;
  tell_room(environment(this_object()),
    short()+"\n");
  return 1; 
}

status cmd_set_time_length(string arg) {
  int num;
  if(!arg) { 
    TimerLength = 780; 
    tell_room(environment(this_object()),
      short()+"\n"); 
    return 1; 
  }
  sscanf(arg, "%d", num);
  if(num < 1) num = 1;  
  if(num > 2400) num = 2400;
  TimerLength = num;
  tell_room(environment(this_object()),
    short()+"\n");
  return 1; 
}  

status cmd_cycle(string arg) {
  int n;
  if(this_player() && 
     (int)this_player()->query_level() < 100 &&
     (string)this_player()->query_real_name() != "forbin") {
    tell_object(this_player(), "You may not use this.\n");
    return 1;
  } 
  if(!arg) return 0;
  n = 0;

  if(arg == "forest") {
    while(n < 44) {
      switch(n) {
        case 0:  File = FOREST+"ff01_01"; break; 
        case 1:  File = FOREST+"ff01_02"; break;
        case 2:  File = FOREST+"ff01_04"; break;
        case 3:  File = FOREST+"ff01_05"; break;
        case 4:  File = FOREST+"ff01_07"; break;
        case 5:  File = FOREST+"ff01_09"; break;
        case 6:  File = FOREST+"ff02_01"; break;
        case 7:  File = FOREST+"ff02_02"; break;
        case 8:  File = FOREST+"ff02_03"; break;
        case 9:  File = FOREST+"ff02_04"; break;
        case 10: File = FOREST+"ff02_06"; break;
        case 11: File = FOREST+"ff02_07"; break;
        case 12: File = FOREST+"ff02_08"; break;
        case 13: File = FOREST+"ff02_09"; break;
        case 14: File = FOREST+"ff03_01"; break;
        case 15: File = FOREST+"ff03_02"; break;
        case 16: File = FOREST+"ff03_03"; break;
        case 17: File = FOREST+"ff03_05"; break;
        case 18: File = FOREST+"ff03_06"; break;
        case 19: File = FOREST+"ff03_08"; break;
        case 20: File = FOREST+"ff03_09"; break;
        case 21: File = FOREST+"ff04_02"; break;
        case 22: File = FOREST+"ff04_03"; break;
        case 23: File = FOREST+"ff04_04"; break;
        case 24: File = FOREST+"ff04_05"; break;
        case 25: File = FOREST+"ff04_06"; break;
        case 26: File = FOREST+"ff04_07"; break;
        case 27: File = FOREST+"ff04_08"; break;
        case 28: File = FOREST+"ff04_09"; break;
        case 29: File = FOREST+"ff05_01"; break;
        case 30: File = FOREST+"ff05_02"; break;
        case 31: File = FOREST+"ff05_03"; break;
        case 32: File = FOREST+"ff05_04"; break;
        case 33: File = FOREST+"ff05_06"; break;
        case 34: File = FOREST+"ff05_07"; break;
        case 35: File = FOREST+"ff05_09"; break;
        case 36: File = FOREST+"ff06_01"; break;
        case 37: File = FOREST+"ff06_02"; break;
        case 38: File = FOREST+"ff06_03"; break;
        case 39: File = FOREST+"ff06_04"; break;
        case 40: File = FOREST+"ff06_05"; break;
        case 41: File = FOREST+"ff06_06"; break;
        case 42: File = FOREST+"ff06_08"; break;
        case 43: File = FOREST+"ff06_09"; break;
      }
    cycle_reset(File);
    n++;
    }
  }
  return 1; 
}

status cycle_reset(string file) {
  object ob, *inv;
  int i;
  int pcount;   /* player count */
  int hcount;   /* hurt monster count */  
  int kcount;   /* kid count */
  int lcount;   /* living count */
  int ptcount;  /* pet count */
  int mcount;   /* monster guild count */
  int bcount;   /* magic box count */
  string pnames;  /* names of all players in room */
  
  ob = find_object(file+".c");
  
  if(!ob) {
    if(Report == "long") {
      tell_room(environment(this_object()),
        file+" is not loaded.\n");
      return 1;
    }
  }
  
  pcount = hcount = kcount = lcount = ptcount = mcount = bcount = 0;
  pnames = "";
  
  inv = all_inventory(ob);
  
  for(i=0; i < sizeof(inv); i++) {
    if(inv[i]->is_player()) {
      pcount++;
      if(pcount == 1) pnames = capitalize((string)inv[i]->query_real_name());
      else pnames += ", "+capitalize((string)inv[i]->query_real_name());
    }
    if(inv[i]->is_npc() && 
      (int)inv[i]->query_hps() < (int)inv[i]->query_mhp()) hcount++;
    if(inv[i]->is_kid()) kcount++;
    if(inv[i]->is_pet()) ptcount++;    
    if(inv[i]->fellow_monster()) mcount++;
    if(living(inv[i])) lcount++;
    if(inv[i]->id("magic box")) bcount++;
  }
  
  if(pcount) {
    if(Report == "long") {    
      if(pcount == 1)
          tell_room(environment(this_object()),
            "There is "+pcount+" player in "+file+"\n"+
            "Player present: "+pnames+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+pcount+" players in "+file+"\n"+
          "Players present: "+pnames+"\n");
    }
  }
  if(hcount) {
    if(Report == "long") {        
      if(hcount == 1)
        tell_room(environment(this_object()),
          "There is "+hcount+" npc hurt in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+hcount+" npcs hurt in "+file+"\n");
    }          
  }   
  if(kcount) {
    if(Report == "long") {        
      if(kcount == 1)
        tell_room(environment(this_object()),
          "There is "+kcount+" kid in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+kcount+" kids in "+file+"\n");
    }          
  }  
  if(ptcount) {
    if(Report == "long") {        
      if(ptcount == 1)
        tell_room(environment(this_object()),
          "There is "+ptcount+" pet in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+ptcount+" pets in "+file+"\n");
    }
  }  
  if(mcount) {
    if(Report == "long") {        
      if(kcount == 1)
        tell_room(environment(this_object()),
          "There is "+mcount+" Monster Bot (e.g. Mizan Monster Guild) in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+mcount+" Monster Bots (e.g. Mizan Monster Guild) in "+file+"\n");
    }
  }  
  if(bcount) {
    if(Report == "long") {            
      if(bcount == 1)
        tell_room(environment(this_object()),
          "There is "+bcount+" Magic Box in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There are "+bcount+" Magic Boxes in "+file+"\n");
    }
  }  

  if(pcount || hcount || kcount || ptcount || mcount || bcount)
    return 1;
    
  destruct(ob);
  if(Report != "off") {          
    tell_room(environment(this_object()),
      file+" has been updated.\n");
    if(lcount) {
      if(lcount == 1)
      tell_room(environment(this_object()),
          "There was "+lcount+" living object in "+file+"\n");
      else
        tell_room(environment(this_object()),
          "There were "+lcount+" living objects in "+file+"\n");
    }
  }    
  return 1;
}

void fake_hb() {
  set_fake_hb(0); 
  if(!environment(this_object())) {
    set_fake_hb(0);
    return;
  }
  Timer++;
  if(Timer > TimerLength) {
    this_object()->cycle("all");
    if(find_player("forbin")) {
      tell_object(find_player("forbin"),
        "Reset Cycle Daemon:  AREAS CLEANED.\n");
    }
  Timer = 0;
  }
  set_fake_hb(1);   
}
