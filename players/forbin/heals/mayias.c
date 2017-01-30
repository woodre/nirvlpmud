/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Main
//  Function:     Heal
//  Create Date:  2003.07.05
//  Last Edit:    2004.07.22 -Forbin
//  Notes:        
//   -3 use heal that splits 6 tox: 3 soak, 3 stuff  
//   -heals for 50 hps and 50 sps each use [50 'heal pts']
//   -heals for 150 total 'heal pts'
//   -COST= 1500 - figured as below:
//     (6*3)/(50*3) = 0.12 = 22/pt. = 150*22 = 3300
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
#define C NORM+HIK

string newshort;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mayias");
  add_alias("bark");
  add_alias("mayias bark");
  add_alias("bark of mayias");
  set_short(C+"Bark"+N+" of the Mayias"+N);
  set_long("\n");
  set_type("bites");
  set_msg("You begin to gnaw on the Mayias bark.\n");
  set_msg2(" gnaws on some bark of the Mayias.\n");
  add_cmd("eat");
  add_cmd("use");
  set_heal(50,50);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(1000);
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
    return newshort = "Mayias "+C+"bark >"+HIW+charges+C+"<"+N;
  }
  else return "Mayias "+C+"bark"+N;
}

long() { 
  write("  A large strip of dark brown bark.  Similar to the outer\n"+
        "bark of a pine tree, it is said that the Mayias tree has\n"+
        "very good healing powers.  There looks to be enough bark\n");
  if(charges == 1) {
    write("left for "+C+charges+N+" more bite.\n"+
          "To heal yourself: 'use' or 'eat' the bark.\n");
  }
  else write("left for "+C+charges+N+" more bites.\n"+
             "To heal yourself: 'use' or 'eat' the bark.\n");
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
    write("You eat the final bits of the bark.\n");
  }
}
