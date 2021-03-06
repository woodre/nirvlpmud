#include "../defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("ball");
  set_alias("crystal_mage_ball");
  set_short(HIC+"Crystal Ball"+NORM);
  set_long(
"This is a smooth ball made of clear crystal.  Inside the ball you\n"+
"see swirling colors obscured by mist and darkness.  This is an\n"+
"exceptionally powerful magical item that can be used to "+BOLD+"view"+NORM+"\n"+
"or "+BOLD+"survey"+NORM+" someone.  You may also "+BOLD+"dismiss"+NORM+" it.\n");
  set_weight(2);
  set_value(0);
}

void init() {
  add_action("cmd_survey","survey");
  add_action("cmd_view","view");
  add_action("cmd_dismiss", "dismiss");
}

int will_check() {
  write("You gaze into the crystal ball and attempt to focus its power...\n");
  if((int)this_player()->query_attrib("wil") < random(22)) {
    write("You lose your concentration and your mind is blasted by uncontrolled\n"+
          "psychic energy.\n");
    this_player()->raise_will_power(-1);
    this_player()->add_hit_point(-random(20));
    return -1;
  }
  return 0;
}

int cmd_survey(string str) {
  object person;
  object ob;

  if(!str) {
    write("Usage: survey <living>\n");
    return 1;
  }

  person=find_player(str);

  if(!person)
    person=find_living(str);

  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }

  if((int)TP->query_level() < (int)person->query_invis()) {
    write(str+" can not be found.\n");
    return 1;
  }

  if((int)person->is_player() && (int)person->query_level() > 20) {
    write("You cannot survey a wizard.\n");
    return 1;
  }

  if(will_check())
    return 1;

  say(TPN+" gazes into the crystal ball.\n");

  environment(person)->long();

  ob = first_inventory(environment(person));

  while (ob) {
    string sh;
    sh=(string)ob->short();
    if(sh) write(sh + ".\n");
    ob=next_inventory(ob);
  }

  if((int)this_player()->query_attrib("wil") < random(24))
    tell_room(environment(person),"You sense someone watching you.\n");
  else if((int)this_player()->query_attrib("wil") < random(21))
    tell_room(environment(person),"You sense "+TPN+" watching you.\n");

  return 1;
}

int cmd_view(string str) {
  object blank;

  blank=clone_object("/players/feldegast/obj/blank.c");

  if(!str) { write("Usage: view <player>\n"); return 1;}

  blank->load_info(str);

  destruct(blank);

  return 1;
}

int cmd_dismiss(string str)
{
  if(str == "ball" || str == "crystal ball")
  {
    TP->add_weight(-2);
    write("With a wave of your hand, the crystal ball disappears.\n");
    say("With a wave of "+(string)TP->query_possessive()+" hand, "+TPN+" dismisses " + (string)TP->query_possessive() + " crystal ball.\n");
    destruct(this_object());
    return 1;
  }
  notify_fail("Dismiss what?\n");
  return 0;
}

int drop() { return 1; }
