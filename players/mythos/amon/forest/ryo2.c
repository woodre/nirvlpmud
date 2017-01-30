inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("ryo");
  set_short();
  set_alias("ryo");
  set_race("spirit");
  set_long("A bodiless head of a woman.\n"+
    "She died in tormet and she now longs for life again.\n"+
    "It is said that should she drink of the blood of the\n"+
    "Jinro- half man half beast, she will live again.\n");
  set_hp(500);
  set_level(20);
  set_al(-500);
  if(random(2)) set_wc(30);
  else set_wc(45);
  set_ac(17);
  set_aggressive(1);
  if(!random(3)) set_whimpy();
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Something whispers in your ear, 'I need blood...'\n");
  load_chat("The darkness presses down on you like a heavy weight.  You feel tired...\n");
  load_a_chat("Something is really, really WRONG!\n");

  set_chance(30);
  set_spell_dam(20);
  set_spell_mess1("Something is really, really WRONG!\n");
  set_spell_mess2("The head flies at you... it passes by and you feel a great pain in your neck!\n"+
    "Your Blood is slurped up by the Ryo.\n");

  gold=clone_object("obj/money");
  gold->set_money(random(4000)+2000);
        /*  Point of note: 2000 +random(4000)  averages 4000 coins i.e. legal limit */
  move_object(gold,this_object());
}


#include "/players/mythos/amon/hb_ag.h"


run_away() {
  object here;
  int i, j;
  
  here = environment();
  if(is_npc) {
  i = 0;
    if(!random(7)) {
  j = random(12) + 1;
       tell_room(environment(this_object()),"Ryo runs away!\n");
      if (j == 1) move_player("runs away#players/mythos/aroom/forest/forestr.c");
      if (j == 2) move_player("runs away#players/mythos/aroom/forest/forestr2.c");
      if (j == 3) move_player("runs away#players/mythos/aroom/forest/forest2.c");
      if (j == 4) move_player("runs away#players/mythos/aroom/forest/forest3.c");
      if (j == 5) move_player("runs away#players/mythos/aroom/forest/forest4.c");
      if (j == 6) move_player("runs away#players/mythos/aroom/forest/forest5.c");
      if (j == 7) move_player("runs away#players/mythos/aroom/forest/forest6.c");
      if (j == 8) move_player("runs away#players/mythos/aroom/forest/forest7.c");
      if (j == 9) move_player("runs away#players/mythos/aroom/forest/forest8.c");
     if (j == 10) move_player("runs away#players/mythos/aroom/forest/forest9.c");
     if (j == 11) move_player("runs away#players/mythos/aroom/forest/forestr.c");
     if (j == 12) move_player("runs away#players/mythos/aroom/forest/forestr2.c");
    } 
  if (here == environment()) {
    say(cap_name + " tried, but failed to run away.\n", this_object());
    tell_object(this_object(),
		"Your legs tried to run away, but failed.\n");
  } else {
    tell_object(this_object(), "Your legs run away with you!\n");
  } }
} 
