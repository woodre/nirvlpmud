#include "defs.h"

inherit ROOM;

int statue;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Sudakan: The Royal Plaza";
  long_desc=
    "  The Royal Plaza is by far the most majestic of the five plazas of\n"+
    "Sudakan.  The Sultan's palace, its golden minarets shining in the\n"+
    "sun overlooks the tiled plaza, which is surrounded by a circle of\n"+
    "magnificently fluted and adorned columns.  In the center of the\n"+
    "plaza is the statue of some fierce creature on a pedestal.  Half a\n"+
    "turn away from the palace is a shop set well apart from the others\n"+
    "and constructed from white marble.\n"+
    "  Streets: Sword  Ruby  Sultan\n"+
    "  Locations: Magic(shop)  Barracks\n";
  items=({
    "plaza","The plaza has five sides, each approximately sixty meters\n"+
            "across.  Beyond the line of columns are a row of shops and\n"+
            "the manses of minor nobles and functionaries of the Sultan.\n"+
            "Three streets lead to the southwest, south, and southeast",
    "palace","The Sultan's palace is a beautiful sight to behold, the culmination\n"+
             "of centuries of an elite aristocracy's oppression of the lower classes.\n"+
             "It is surrounded by dozens of guards, each with the strict orders not to\n"+
             "let any adventurers come in just for a visit",
    "columns","You scratch your head and try to figure out what they're there\n"+
              "for.  Eventually, you decide that they're there to look pretty.\n"+
              "After a moment more, you decide that they do",
    "statue","The statue depicts a strange creature with the body of a lion,\n"+
             "the head of a man, a porcupine's quills, and the tail of a\n"+
             "scorpion. A plaque on the pedestal asks the question:\n"+
             "\t\t'I go around in circles,\n"+
             "\t\t But always straight ahead\n"+
             "\t\t Never complain,\n"+
             "\t\t No matter where I am led.\n"+
             "\t\t What am I?'\n"+
             "You may 'answer' the question",
  });
  dest_dir=({
    PATH+"stab.c","sword",
    PATH+"smark.c","ruby",
    PATH+"smerch.c","sultan",
    PATH+"smagic.c","magic",
    PATH+"smagic.c","shop",
    PATH+"barrack1.c","barracks",
  });
  move_object(clone_object(MON_PATH+"mystic.c"),this_object());
}

string short() {
  return short_desc;
}

void long(string str) {
  if(!str) write(long_desc);
  else ::long(str);
}

void init() {
  ::init();
  add_action("cmd_answer","answer");
}

int cmd_answer(string str) {
  if(!str) {
    notify_fail("Answer <what>?\n");
    return 0;
  }
  if(statue) {
    write("Nothing happens.\n");
    return 1;
  }
  write("You look boldly into the statue's snarling face and say:\n"+
        "\t\"The answer is '"+capitalize(str)+"'.\"\n");

  if(str != "wheel") {
    write(HIM+"A dark shadow envelops you, leaving you weakened and drained.\n"+NORM);
    say(HIM+"A dark shadow envelops "+TPN+".\n"+NORM);
    this_player()->add_spell_point(-((int)this_player()->query_sp()));
    return 1;
  }
  tell_room(this_object(),BOLD+"The statue starts and shudders into life!\n"+NORM);
  move_object(clone_object(MON_PATH+"stone_mant.c"),this_object());
  statue=1;
  items[7]="The statue isn't there anymore";
  if(present("mystic")) {
    tell_room(this_object(),"Zytanno flees in terror!\n");
    command("ruby",present("mystic"));
  }
  return 1;
}

query_coords() { return ({ 6,7 }); }
