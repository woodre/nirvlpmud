#include "defs.h"

inherit ROOM;

int statue;

void reset(int arg) {
  if(!present("merchant") && random(5))
    move_object(clone_object(MON_PATH+"mapseller.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Sudakan: Gate plaza";
  long_desc=
    "  At the main entrance to the city of Sudakan is the first of the\n"+
    "great plazas that the city is famous for.  Merchants and nomads\n"+
    "bustle about the plaza doing their daily business.  In the center of\n"+
    "the plaza is the statue of some fierce creature on a pedestal. Near\n"+
    "the great gate to the city is a tavern from which you hear the\n"+
    "sounds of laughter and music.\n"+
    "  Streets: Plow  Gold  Farmer\n"+
    "  Locations: Gate  Tavern\n";
  items=({
    "plaza","The plaza is in a hexagonal shape, each side approximately\n"+
            "thirty meters.  At the top three 'points', streets lead further\n"+
            "into the city while at the bottom point is the gate which leads\n"+
            "back into the desert",
    "statue","The statue depicts a strange creature with the body of a goat,\n"+
             "the head of a lion, and the tail of a dragon.  A plaque on the\n"+
             "pedestal asks the question:\n"+
             "        'We travel much yet prisoners are\n"+
             "           And close confined to boot\n"+
             "      Yet with any horse we will keep pace\n"+
             "             And always go on foot\n"+
             " 'What are we called?'  You may 'answer' the question",
    "gate","The great gates to the city are currently spread open to travellers",
  });
  dest_dir=({
    PATH+"stab.c","farmer",
    PATH+"smark.c","gold",
    PATH+"smerch.c","plow",
    PATH+"stav1.c","tavern",
  });
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
  add_action("cmd_gate","gate");
}

int cmd_answer(string str) {
  if(!str) {
    notify_fail("Answer <what>?\n");
    return 0;
  }
  if(statue) {
    write("The statue isn't there anymore.\n");
    return 1;
  }
  write("You look boldly into the statue's snarling face and say:\n"+
        "\t\"The answer is '"+capitalize(str)+"'.\"\n");
  if(str != "spurs" && str != "spur") {
    write(HIM+"A dark shadow envelops you, leaving you weakened and drained.\n"+NORM);
    say(HIM+"A dark shadow envelops "+TPN+".\n"+NORM);
    this_player()->add_spell_point(-((int)this_player()->query_sp()));
    return 1;
  }
  tell_room(this_object(),BOLD+"The statue starts and shudders into life!\n"+NORM);
  move_object(clone_object(MON_PATH+"stone_chimera.c"),this_object());
  statue=1;
  items[3]="It isn't there anymore";
  return 1;
}

int cmd_gate(string str) {
  say(TPN+" leaves Sudakan through the gate.\n");
  move_object(TP,(object)MAP->query_location(6,7));
  say(TPN+" comes out of the city.\n");
  write("You step through the gates.\n");
  command("look",TP);
  return 1;
}

query_coords() { return ({ 6,7 }); }
