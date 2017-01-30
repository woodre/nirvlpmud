/* Raymond Joseph Teller */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    object gold;
    gold=clone_object("obj/money");
    gold->set_money(random(51)+250);
    move_object(gold,this_object());
  }
  set_name("teller");
  set_alias("teller");
  set_alt_name("entertainer");
  set_short("Teller");
  set_race("human");
  set_long("Teller favors the audience with an impish grin, his dark\n\
eyes flashing with mischief and a deep intelligence.\n\
Dressed in a snazzy gray three piece suit, his lean,\n\
diminuntive frame and short, dark hair with receding\n\
hairline contrast markedly with the appearance of \n\
his larger, louder partner.\n");
  set_level(11);
  set_ac(8 + random(2));
  set_wc(14 + random(2));
  set_hp(165);
  set_al(-500);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(30);
  /* Regular chats */
  load_chat("Teller systematically swallows one hundred needles and a\n\
length of thread, to the utter disgust and amazement of the\n\
audience, then regurgitates a string of threaded needles.\n");
  load_chat("Teller smiles brightly as he feeds a fluffy, white\n\
bunny into the business end of a woodchipper!\n");
  load_chat("Teller dramatically slices at the shadow of a rose projected\n\
on the wall....then grins as pedals from the live rose beside\n\
it fall silently to the floor.\n");
  load_chat("Teller somehow walks through ..... a cow!\n");
  load_chat("Teller grins, displaying the .357 Magnum\n\
bullet he caught in his mouth!\n");
  /* Combat chats */
  load_a_chat("Teller somehow wriggles out of your grip!\n");
  load_a_chat("Teller tries to stuff you into the woodchipper!\n");
  load_a_chat("Teller viciously spits a needle at your eye!\n");
  set_dead_ob(this_object());
}

/* Teller will regurgitate a needle from the act upon his death.  */
  
monster_died(ob)
{
  tell_room(environment(),
      "\n\tTeller sputters, convulsing in his final death throes, then\n\
\n\tcoughs up a long, "+RED+"BLOOD-SOAKED"+YEL+" NEEDLE"+NORM+
" from his act!\n\n");
  move_object(clone_object("/players/aingeal/casino/treasure/needle.c"));
}

