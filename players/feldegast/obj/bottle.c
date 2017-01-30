#include "defs.h"

object djinn;
int uncorked;

int g;

inherit "/obj/treasure.c";

get() { return g; }

void reset(int arg) {
  if(arg==0) {
    g=1;
    set_id("bottle");
    set_short("An antique bottle");
    set_long(
  "This bottle is an ancient relic predating even the Majiri\n"+
  "civilization.  It is constructed of fine porcelain with a\n"+
  "light blue glaze.  Strange letters, written in gold and in\n"+
  "a foreign tongue run around the bottle's rim.  The top of\n"+
  "the bottle is sealed with wax.\n"
    );
    set_weight(1);
    set_value(455);
  }
  if(arg==2) {
    set_long(
      "This bottle is an ancient relic predating even the Majiri\n"+
      "civilization.  It is constructed of fine porcelain with a\n"+
      "light blue glaze.  Strange letters, written in gold and in\n"+
      "a foreign tongue run around the bottle's rim.  The top of\n"+
      "the bottle is unsealed, and you hear the jingling of gold\n"+
      "coins inside it.  Perhaps you should 'shatter' the bottle\n"+
      "to get them out?\n"
    );
    set_value(5500+random(1000)); /* Cost to purchase included */
    g=1;
    uncorked=1;
  }
  set_save_flag(1);
}

void init() {
  if(uncorked && environment()==TP) {
    add_action("cmd_break","shatter");
    add_action("cmd_break","break");
  }
  else {
    add_action("cmd_open","open");
    add_action("cmd_open","uncork");
  }
}

int cmd_open(string str) {
  if(!str || !id(str)) {
    notify_fail(query_verb()+" what?\n");
    return 0;
  }
  if(creator(environment(TP))!="feldegast") {
    notify_fail("Nothing happens.  You recork the bottle.\n");
    return 0;
  }
  move_object(this_object(),environment(TP));
  write("You uncork the bottle and immediately drop it as it begins\n"+
        "shaking and green mist rises up from it.\n");
  say(TPN+" opens "+short_desc+" and drops it immediately as\nmist begins to rise from it.\n");
  call_out("summon", 2, TP);
  g=0;
  TP->add_weight(-local_weight);
  return 1;
}

void summon(object targ) {
  tell_room(environment(),"A fearsome djinn coalasces from the mist!\n");
  djinn=clone_object(MON_PATH+"djinn.c");
  move_object(djinn,environment());
  call_out("summon2", 1, targ);
}

void summon2(object targ) {
  tell_room(environment(djinn),"Djinn picks up the bottle.\n");
  move_object(this_object(),djinn);
  call_out("summon3", 2, targ);
  reset(2);
}
  
void summon3(object targ) {
  tell_room(environment(djinn),"Djinn says: For two thousand three hundred and thirteen years I have\n"+
                    "  been imprisoned in this bottle.\n");
  call_out("summon4",3,targ);
}

void summon4(object targ) {
  tell_room(environment(djinn),
"Djinn says: If you had released me after one thousand eight hundred and\n"+
"  fifty-six years, I would have showered you with riches, women, and\n"+
"  power.\n");
  call_out("summon5",2,targ);
}

void summon5(object targ) {
  tell_room(environment(djinn),
"Djinn says: But you have waited four hundred fifty seven years too\n"+
"  long and now you have made me very "+HIR+"ANGRY"+NORM+"!!!\n");
  if(targ && present(targ,environment(djinn)))
    djinn->attack_object(targ);
  djinn->set_aggressive(1);
}

int cmd_break(string str) {
  object money;
  if(!str || !id(str)) {
    notify_fail("Pour what?\n");
    return 0;
  }
  write("You toss the bottle at the ground.  It shatters into dozens\n"+
        "of fragments, revealing the riches inside.\n");
  say(TPN+" shatters an antique bottle on the ground, revealing the\n"+
      "riches inside of it.\n");
  money=clone_object("/obj/money.c");
  money->set_money(value);
  move_object(money,environment(TP));
  TP->add_weight(-local_weight);
  destruct(this_object());
  return 1;
}
  
