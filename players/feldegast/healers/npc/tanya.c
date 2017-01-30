/*
File: tanya.c
Author: Feldegast
Date: 12-11-01
Description:
  The proprietor of the kitchen in the healer guild hall.
*/

#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tanya");
  set_alt_name("tallbroom");
  set_alias("kitchen proprietor");
  set_short("Tanya Tallbroom");
  set_long(
    "Tanya Tallbroom is an obviously elder woman, perhaps in her\n"+
    "sixties, but still unbowed by age.  She stands six feet tall\n"+
    "and a long flowing mane of white hair flows down her back.\n"+
    "She is the mistress of the kitchen and keeps an iron grip on\n"+
    "her domain.  You may "+BOLD+"list"+NORM+" and "+BOLD+"buy"+NORM+" from her.\n"
  );
  set_gender("male"); /* "male","female" */
  set_race("human");
  set_level(11);
  set_wc(15);
  set_ac(9);
  set_hp(165);
  set_al(600);
  set_chat_chance(5);
  load_chat("Tanya putters about her kitchen.\n");
  load_chat("Tanya kneeds some bread.\n");
  load_chat("Tanya chops vegetables industriously.\n");
}
