/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Main
 *  Function:     Heal
 *  Create Date:  2002.07.04
 *  Last Edit:    2004.06.10 -Forbin
 *  Notes:        Thanks to Jaraxle and Maledicta for superb examples of
 *                  how to code a heal from scratch.
 *                3 use heal that splits 6 tox: 3 soak, 3 stuff.  
 *                Heals for 50 hps and 50 sps.  
 *                COST= 3300 - figured as below:
 *                    (6*3)/(50*3) = 0.12 = 22/pt. = 150*22 = 3300
 *  Notable Changes:            
 */

#include "/players/forbin/define.h"

#define USER     this_player()
#define USERN    USER->query_name()
#define USERHP   USER->query_hp()
#define USERMHP  USER->query_mhp()
#define USERSP   USER->query_sp()
#define USERMSP  USER->query_msp()
#define UPOS     USER->query_possessive()
#define USOAK    USER->query_soaked()
#define USTUFF   USER->query_stuffed()
#define UINTOX   USER->query_intoxication()
#define SOAKPER  (USOAK*100)/(USER->query_level()*8)
#define STUFFPER (USTUFF*100)/(USER->query_level()*8)
#define INTOXPER (UINTOX*100)/(USER->query_level()+3)
#define C HIK
#define N NORM

int Uses;

id(str) { return (str == "bark" || str == "mayias" || str == "mayias bark" 
               || str == "bark of the mayias"); }

short() { return C+"Bark"+N+" of the Mayias "+C+">"+N+HIW+Uses+N+C+"<"+N; }

long() { 
  write("  A large strip of dark brown bark.  Similar to the outer\n"+
        "bark of a pine tree, it is said that the Mayias tree has\n"+
        "very good healing powers.  There looks to be enough bark\n");
  if(Uses == 1) {
    write("left for "+C+Uses+N+" more bite.\n"+
          "To heal yourself: 'use' or 'eat' the bark.\n");
  }
  else write("left for "+C+Uses+N+" more bites.\n"+
             "To heal yourself: 'use' or 'eat' the bark.\n");
}

query_value(){ return (Uses * 700); }
query_save_flag(){ return 1; }
query_weight(){ return 1; }
get(){ return 1; }

reset(arg) {
  if(arg) return;
  Uses = 3;
}

init() {
  add_action("use_heal","use");
  add_action("use_heal","eat");
}

use_heal(str) {
  if(!id(str)) { notify_fail("Eat what?\n"); return 0; }
  if(!str) { notify_fail("Eat what?\n"); return 0; }
  if(environment(TO) != USER) return 0;
  if(USER->query_stuffed() + 3 > USER->query_level() * 8) {
    write(C+"You are too stuffed to use it!\n"+N);
      return 1;
  }
  if(USER->query_soaked() + 3 > USER->query_level() * 8) {
    write(C+"You are too soaked to use it!\n"+N);
      return 1;
  }
  if(!call_other(TP, "eat_food", 3) || !call_other(TP, "drink_soft", 3)) return 0;
  write("You begin to gnaw on the bark.\n");
  say(USERN+" gnaws on some Bark of the Mayias.\n");
  USER->heal_self(50);
  USER->recalc_carry();
  write(C+"          ["+HIW+USERHP+N+C+"|"+N+USERMHP+C+"]-["+HIW+USERSP+N+C+"|"+N+USERMSP+C+"]\n"+N);
  if(SOAKPER > 99)  { write(C+"             ("+N+"soak"+C+"  ["+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER > 9 && SOAKPER < 100)   { write(C+"             ("+N+"soak"+C+"  [ "+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER < 10)  { write(C+"             ("+N+"soak"+C+"  [  "+HIW+SOAKPER+N+C+"%]\n"+N); } 
  if(STUFFPER > 99) { write(C+"             ("+N+"stuff"+C+" ["+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"stuff"+C+" [ "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER < 10) { write(C+"             ("+N+"stuff"+C+" [  "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(INTOXPER > 99) { write(C+"             ("+N+"intox"+C+" ["+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"intox"+C+" [ "+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER < 10) { write(C+"             ("+N+"intox"+C+" [  "+HIW+INTOXPER+N+C+"%]\n"+N); }  Uses -= 1;
  if(Uses == 1) {
    write("There is "+C+Uses+N+" more bite left.\n");
  }
  else write("There are "+C+Uses+N+" more bites left.\n");
  if(!Uses) {
    write("You eat the final bits of the bark.\n");
    TO->set_weight(0);
    USER->recalc_carry();
    destruct(TO);
      return 1;
  }
  return 1;
}
