/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Main
//  Function:     Heal
//  Create Date:  2003.07.05
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        
//   -3 use heal that splits 18 tox: 9 soak, 9 stuff  
//   -heals for 50 hps and 50 sps each use [50 'heal pts']
//   -heals for 150 total 'heal pts'
//   -COST= 1500 - figured as below:
//     (18*3)/(50*3) = 0.40 = 10/pt. = 150*10 = 1500
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
#define C NORM+GRN

string newshort;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("dhuez");
  add_alias("leaves");
  add_alias("dhuez leaves");
  add_alias("d'huez");
  add_alias("d'huez leaves");
  set_short("d"+C+"'"+N+"Huez "+C+"leaves"+N);
  set_long("\n");
  set_type("bits");
  set_msg("You greedily stuff a handful of leaves into your mouth.\n");
  set_msg2(" eats a few bits of d'Huez leaves.\n");
  add_cmd("eat");
  add_cmd("use");
  set_heal(50,50);
  set_charges(3);
  set_soak(9);
  set_stuff(9);
  set_value(500);
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
    return "d"+C+"'"+N+"Huez "+C+"leaves >"+HIW+charges+C+"<"+N;
  }
  else return "d"+C+"'"+N+"Huez "+C+"leaves"+N;
}

long() { 
  write(
    "  A small clutch of long thin leaves.  Marked with colorful\n"+
    "stripes of varying width, they hardly look edible - but\n"+
    "the leaves of the d'Huez tree are tasty none the less.\n");
  if(charges == 1) {
    write(
      "There appears to be "+C+charges+N+" more bite left.\n"+
      "To heal yourself: 'use' or 'eat' the leaves.\n");
  }
  else 
    write(
      "There appears to be "+C+charges+N+" more bites left.\n"+
      "To heal yourself: 'use' or 'eat' the leaves.\n");
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
    write("There is "+C+charges+N+" more bite left.\n");
  }
  else if(charges == 0) { write(""); }  
  else write("There are "+C+charges+N+" more bites left.\n");
  if(!charges) {
    write("You stuff the last bits of d'Huez leaves into your mouth.\n");
  }
}
