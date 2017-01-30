#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(OBJ_PATH+"plague.c"),this_object());
  move_object(clone_object(OBJ_PATH+"plague.c"),this_object());
  move_object(clone_object(OBJ_PATH+"plague.c"),this_object());
  set_name("plaguelord");
  set_alt_name("lord");
  set_short(HIM+"Plaguelord"+NORM);
  set_long(
"This creature that was once a man is covered in open sores, oozing\n"+
"pus.  Its breath is poison and its touch is death.  In the final\n"+
"days of the Majiri empire, a lowly and inexperienced magelord made\n"+
"a foolish pact with dark powers, thinking that he would gain enough\n"+
"power to aid in the fight against Jal-Hab.  The pact resulted in the\n"+
"putrefication of both his body and his soul, and the magelords creeped\n"+
"even closer to extinction.\n"
  );
  set_gender("male");
  set_race("majiri");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(480);
  set_heal(3,1);
  set_al(-800);
  set_chat_chance(4);
  load_chat("Pus dribbles down the Plaguelord's body.\n");
  load_chat("The Plaguelord hisses in pain.\n");
  load_spell(40,15,0,
    GRN+"\nThe Plaguelord breathes a poisonous cloud of gas!\n\n"+NORM,
    GRN+"\nThe Plaguelord breathes a poisonous cloud of gas!\n\n"+NORM);
  load_spell(20,15,0,
    YEL+"\nThe stench of the Plaguelord's rotting flesh assails you!\n\n"+NORM,
    YEL+"\nThe stench of the Plaguelord's rotting flesh assails #ATT#!\n\n"+NORM);
}

heart_beat() {
  object plague;
  ::heart_beat();
  if(attacker_ob && !present("poison",attacker_ob) && attacker_ob->query_attrib("sta") < random(23)) {
    plague=clone_object(OBJ_PATH+"poison2.c");
    move_object(plague,attacker_ob);
    tell_object(attacker_ob,BOLD+"\nThe Plaguelord grins evilly as it touches your skin.\n"+NORM+
                                HIY+"You have been infected.\n\n"+NORM);
    say(attacker_ob->query_name()+" has been infected.\n");
  }
}
