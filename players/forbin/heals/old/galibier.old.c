/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Main
 *  Function:     Heal
 *  Create Date:  2003.08.12
 *  Last Edit:    2004.06.10 -Forbin
 *  Notes:        Thanks to Jaraxle and Maledicta for superb examples of
 *                  how to code a heal from scratch.
 *                3 use heal that splits 6 tox: 3 soak, 3 stuff.  
 *                Heals for 50 hps and 50 sps.  
 *                COST= 2100 - figured as below:
 *                    (12*3)/(50*3) = 0.24 = 14/pt. = 150*14 = 2100
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
#define C RED
#define N NORM

int Uses;

id(str) { return (str == "root" || str == "galibier" ||
                  str == "galibier root"); }

short() { return C+"Galibier"+N+" Root "+C+">"+N+HIW+Uses+N+C+"<"+N; }

long() { 
  write("  A small length of Galibier Root.  Gnarled and twisted, pecked\n"+
        "with knots and cuts - this red root hardly looks appealing.  A\n"+
        "sweet smell surrounds it, making you hungry.  There appears to be\n");
  if(Uses == 1) {
    write("enough left for "+C+Uses+N+" more nibble.\n"+
          "To heal yourself: 'use' or 'eat' the root.\n");
  }
  else write("enough left for "+C+Uses+N+" more nibbles.\n"+
             "To heal yourself: 'use' or 'eat' the root.\n");
}

query_value() { return (Uses * 700); }
query_save_flag() { return 1; }
query_weight() { return 1; }
get() { return 1; }

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
  if(USER->query_stuffed() + 6 > USER->query_level() * 8) {
    write(C+"You are too stuffed to use it!\n"+N);
      return 1;
  }
  if(USER->query_soaked() + 6 > USER->query_level() * 8) {
    write(C+"You are too soaked to use it!\n"+N);
      return 1;
  }
  if(!call_other(TP, "eat_food", 6) || !call_other(TP, "drink_soft", 6)) return 0;
  write("You nibble on a piece of the root.\n");
  say(USERN+" nibbles on some Galiber root.\n");
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
    write("There is "+C+Uses+N+" more nibble left.\n");
  }
  else write("There are "+C+Uses+N+" more nibbles left.\n");
  if(!Uses) {
    write("You nibble the final piece of the root.\n");
    TO->set_weight(0);
    USER->recalc_carry();
    destruct(TO);
      return 1;
  }
    return 1;
}
