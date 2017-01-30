/******************************************************************************
 *  
 *  File:           proc.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 4/19/01.
 *  
 *  Notes:			Proctologist: Ouch
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
#include "/players/vital/dest/dest.h"

inherit "/players/vital/closed/std/monster.c";

int pain;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sphincterani");
  set_alt_name("doctor");
  set_alias("Doctor Sphincterani");
  set_short("Doctor Sphincterani");
  set_long(
"  The Good Doctor John Sphincterani\n\
This is a good old-fashioned proctologist. He still makes house \n\
calls and wants to make you better. He has some special skills \n\
that will make you cringe.\n"
  );
  set_al(-(random(200)));
  set_gender("male");
  set_race("human");
  set_level(20);
  set_dead_ob(this_object());

  set_chat_chance(5);
  load_chat("Dr. Sphincterani says: \"Do you need an exam?\"\n");
  load_chat("The doctor looks you over knowingly.\n");
  set_a_chat_chance(5);
  load_a_chat("Dr. Sphincterani says: \"Ooooo, Boy! This is going to hurt.\"\n");
  load_a_chat("Dr. Sphincterani says: \"Let me touch your soul!\"\n");
  load_a_chat("The doctor pulls on a new set of rubber gloves.\n");
  set_chance(15);
  set_spell_mess1("The doctor probes the inner being of his patient.\n");
  set_spell_mess2("Dr. Sphincterani bends you over and makes you scream.\n");
  set_spell_dam(5+random(40));
  add_money(6500);
}

id(str) { return str == "dr" || str == "doc" || str == "Doc" || str == "proctologist" || str == "masichist" || str == name || str == alias || str == race || str == alt_name; }

init() { pain = 0; }

heart_beat() {
  ::heart_beat(); /* This calls the heart_beat in monster.c to handle attacks. */
  if(attacker_ob) {
    if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("wil") <
    random(50) && !pain) {
      move_object(clone_object(ACADIE+"obj/pain.c"),attacker_ob);
      say("The doctor pushes "+attacker_ob->query_name()+"'s head down between "+
        attacker_ob->query_objective()+" knees \n\and begins to give an exam to "+
        attacker_ob->query_possessive()+" lower gastro-intestinal exam.\n");
      pain=1;
    }
  }
}

monster_died() {
  object rubgloves;
  object corpse;
  corpse=present("corpse",environment());
  if(corpse) {
    rubgloves=clone_object(ACADIE+"obj/rubgloves.c");
    move_object(rubgloves,this_object());
    say("\nDr. Sphincterani says: \"Why? I only wanted to probe...er, help people.\"\n");
  }
}
