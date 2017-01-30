/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Main
 *  Function:     Heal
 *  Create Date:  2003.07.05
 *  Last Edit:    2004.06.10 -Forbin
 *  Notes:        Thanks to Jaraxle and Maledicta for superb examples of
 *                  how to code a heal from scratch.
 *                3 use heal that splits 20 tox: 10 soak, 10 stuff.  
 *                Heals for 50 hps and 50 sps.  
 *                COST= 1200 - figured as below:
 *                    (20*3)/(50*3) = 0.40 = 8/pt. = 150*8 = 1200
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
#define C HIY
#define N NORM

int Uses;

id(str) { return (str == "maillot" || str == "jaune" || str == "maillot jaune" 
               || str == "bar"); }

short() { return C+"Maillot Jaune >"+N+HIW+Uses+N+C+"<"+N; }

long() { 
  write("  A small, thin bar is wrapped in bright yellow foil.  Slightly\n"+
        "mushy, the bar is packed with several nutritional and restorative\n"+
        "supplements.  Not the best tasting food in the world, but it will\n");
  if(Uses == 1) {
    write("heal you.  There is "+C+Uses+N+" more bite left.\n"+
          "To heal yourself: 'use' or 'eat' the bar.\n");
  }
  else write("heal you.  There are "+C+Uses+N+" more bites left.\n"+
             "To heal yourself: 'use' or 'eat' the bar.\n");
}

query_value(){ return (Uses * 400); }
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
  if(USER->query_stuffed() + 10 > USER->query_level() * 8) {
    write(C+"You are too stuffed to use it!\n"+N);
      return 1;
  }
  if(USER->query_soaked() + 10 > USER->query_level() * 8) {
    write(C+"You are too soaked to use it!\n"+N);
      return 1;
  }
  if(!call_other(TP, "eat_food", 10) || !call_other(TP, "drink_soft", 10)) return 0;
  write("You take a large bite of the Maillot Jaune bar.\n");
  say(USERN+" takes a bite of an energy bar.\n");
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
    write("You stuff the last of the Maillot Jaune into your mouth.\n");
    TO->set_weight(0);
    USER->recalc_carry();
    destruct(TO);
      return 1;
  }
    return 1;
}