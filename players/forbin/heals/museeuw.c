/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Main
//  Function:     Heal
//  Create Date:  2003.07.05
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        
//   -4 use heal that splits 8 tox: 4 soak, 4 stuff  
//   -heals for 50 sps each use [33 'heal pts']
//   -heals for 133 total 'heal pts'
//   -COST= 1900 - figured as below:
//    (8*4)/((50*4)*2/3) = .24 => .24 -> 14 * ((50*4)*2/3) = 1862 -> 1900
//  Notable Changes:
//    -2004.07.13 switched to /obj/generic_heal [Forbin]            
*/

#include "/players/forbin/define.h"
inherit "/obj/generic_heal.c";

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
#define SOAKPER  (USOAK*100)/(USER->query_max_soak())
#define STUFFPER (USTUFF*100)/(USER->query_max_stuff())
#define INTOXPER (UINTOX*100)/(USER->query_max_intox())
#define C NORM+HIM

string newshort;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("museeuw");
  add_alias("tonic");
  add_alias("museeuw tonic");
  set_short(C+"Museeuw "+HIW+"Tonic"+N);
  set_long("\n");
  set_type("sips");
  set_msg("You greedily stuff a handful of leaves into your mouth.\n");
  set_msg2(" eats a few bits of d'Huez leaves.\n");
  add_cmd("drink");
  add_cmd("sip");
  add_cmd("use");
  set_heal(0,50);
  set_charges(4);
  set_soak(4);
  set_stuff(4);
  set_value(400);
  set_msg_soaked(C+"You are too soaked to use it!"+N);
  set_msg_stuffed(C+"You are too stuffed to use it!"+N);
  set_msg_precharges(C+">"+HIW);
  set_msg_postcharges(C+"<"+N);
  set_type_single("use"); 
  set_empty_msg("");   
}

query_weight() { return 1; }

query_save_flag() { return 1; }

short() { 
  object a, e;
  if(((a = this_player()) && (e = environment()) && (e == a)) 
     || ((a = this_player()) && (a->query_level() >= 40))) {  
    return C+"Museeuw "+HIW+"Tonic"+C+" >"+HIW+charges+C+"<"+N;  
  }
  else return C+"Museeuw "+HIW+"Tonic"+N;
}

long() { 
  write(
    "  A large round decanter with a strange, glowing pink liquid.  Shiny,\n"+
    "white flecks float wildly about as you swirl the substance around.\n");
  if(charges == 1) {
    write(
      "There is enough left for "+C+charges+N+" more sip.\n"+
      "To heal yourself: 'use' or 'sip' the tonic.\n");
  }
  else 
    write(
      "There is enough left for "+C+charges+N+" more sips.\n"+
      "To heal yourself: 'use' or 'sip' the tonic.\n");
}

show_charges() { }

show_heal_mon() {
  write(C+"          ["+HIW+USERHP+N+C+"|"+N+USERMHP+C+"]-["+HIW+USERSP+N+C+"|"+N+USERMSP+C+"]\n"+N);
  if(SOAKPER > 99)  { write(C+"             ("+N+"soak"+C+"  ["+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER > 9 && SOAKPER < 100)   { write(C+"             ("+N+"soak"+C+"  [ "+HIW+SOAKPER+N+C+"%]\n"+N); }
  if(SOAKPER < 10)  { write(C+"             ("+N+"soak"+C+"  [  "+HIW+SOAKPER+N+C+"%]\n"+N); } 
  if(STUFFPER > 99) { write(C+"             ("+N+"stuff"+C+" ["+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"stuff"+C+" [ "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(STUFFPER < 10) { write(C+"             ("+N+"stuff"+C+" [  "+HIW+STUFFPER+N+C+"%]\n"+N); }
  if(INTOXPER > 99) { write(C+"             ("+N+"intox"+C+" ["+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER > 9 && SOAKPER < 100)  { write(C+"             ("+N+"intox"+C+" [ "+HIW+INTOXPER+N+C+"%]\n"+N); }
  if(INTOXPER < 10) { write(C+"             ("+N+"intox"+C+" [  "+HIW+INTOXPER+N+C+"%]\n"+N); }  
  if(charges == 1) {
    write("There is "+C+charges+N+" more sip left.\n");
  }
  else if(charges == 0) { write(""); }
  else 
    write("There are "+C+charges+N+" more sips left.\n");
  if(!charges) {
    write("You finish off the last swallow of the tonic.\n");
  }
}
