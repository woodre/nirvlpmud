#include "../def.h"

inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;
  set_name("elisia blackstaff");
  set_alt_name("elisia");
  set_alias("blackstaff");
  set_short("Elisia Blackstaff");
  set_long(
    "Elisia Blackstaff is the lean, beak-nosed weapon-master of the\n"+
    "healers.  Her brown, spiky hair is cut short.  She wears a short\n"+
    "mannish jacket and dark leather pants.\n"
  );
  set_gender("female"); 
  set_race("human");
  set_level(20);
  set_wc(31);
  set_ac(17);
  set_hp(460);
  set_al(500);
  set_chat_chance(5);
  load_chat("Elisia's staff whistles through the air as she practices.\n");
  load_chat("Elisia stops her practice for a moment to nod a greeting at you.\n");
  load_chat("Elisia says: I can "+BOLD+"train"+NORM+" you in the use of staves, if you'd like.\n");
  set_a_chat_chance(3);
  load_a_chat("Elisia, smooth and cat-like, moves in for the kill!\n");
  load_a_chat("Elisia's twirls her staff around body and grins confidently.\n");
  set_chance(15);
  set_spell_mess1(
    "The iron tip of Elisia's staff moves with a blur as it hits its target\n"+
    "  with a\t*T H W A P*!\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
    "The iron tip of Elisia's staff moves with a blur as it hits you\n"+
    "  with a \t*T H W A P*!\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(35);
}

void init()
{
  ::init();
  add_action("cmd_train", "train");
}

int cmd_train(string str)
{
  int freexp;
  int rank;

  if(!MYOB)
  {
    write("Elisia says: I only train members of the Healers guild.\n");
    return 1;
  }

  if((int)TP->query_extra_level())
    freexp = (int)call_other(TP, "query_exp") - (int)call_other("/room/exlv_guild","get_next_exp", (int)TP->query_extra_level()-1);

  else
    freexp = (int)TP->query_exp() - (int)call_other("/room/adv_guild","get_next_exp", (int)TP->query_level()-1);

  rank = (int)MYOB->query_staff_skill() + 1;

  if(rank >= 5)
  {
    write("Elisia says: I'm sorry, but I don't know what else I can teach you.\n");
    return 1;
  }

  if(freexp < 100000)
  {
    write("Elisia says: I'm sorry, but you don't have enough experience to\n\tpick up any more staff techniques.\n");
    return 1;
  }

  TP->add_exp(-100000);
  MYOB->set_staff_skill(rank);

  write("Elisiah trains you in the skills and techniques of staff combat.\n");
  switch(rank)
  {
    case 1: write("You are now adequate with a staff.\n"); break;
    case 2: write("You are now average with a staff.\n"); break;
    case 3: write("You are now skilled with a staff.\n"); break;
    case 4: write("You are now a master with the staff.\n"); break;
  }

  return 1;
}
