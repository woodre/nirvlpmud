#include "defs.h"

inherit ROOM;

int statue;
object pen;

void reset(int arg) {
  if(!arg) {
  set_light(1);
  short_desc="Sudakan: Tabernacle Square";
  long_desc=
    "  Unlike the other four plazas of Sudakan, Tabernacle Square does\n"+
    "not bustle with crowds of travellers or merchants.  Instead, it is\n"+
    "filled with somber looking men, morose priests, and solemn pilgrims.\n"+
    "The statue of some fierce creature perched upon a pedestal sits in\n"+
    "the middle of the plaza.  Surrounding the plaza are temples and\n"+
    "shrines devoted to various deities.\n"+
    "  Streets: Farmer  Temple  Sword\n"+
    "  Locations: Shrine\n";
  items=({
    "plaza","This plaza is seven sided, each side approximately forty meters\n"+
            "across.  Three streets lead to the northeast, east, and southeast",
    "statue","The statue depicts a strange creature with the body of a large\n"+
             "vulture and the head of an old crone.  A plaque on the pedestal\n"+
             "asks the question:\n"+
             "              'Black when bought\n"+
             "                 Red when used\n"+
             "             Grey when thrown away\n"+
             "                  What am I?'\n"+
             "You may 'answer' the question",
  });
  dest_dir=({
    PATH+"sgate.c","farmer",
    PATH+"smark.c","temple",
    PATH+"sroy.c","sword",
    PATH+"stemple.c","shrine",
  });
  }
  if(!pen) {
    pen=clone_object(MON_PATH+"penitent.c");
    move_object(pen,this_object());
  }
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
    write("You're a little late, don't you think?\n");
    return 1;
  }
  str=lower_case(str);
  write("You look boldly into the statue's hideous face and say:\n"+
        "\t\"The answer is '"+capitalize(str)+"'.\"\n");

  if(str != "coal") {
    write(HIM+"A dark shadow envelops you, leaving you weakened and drained.\n"+NORM);
    say(HIM+"A dark shadow envelops "+TPN+".\n"+NORM);
    this_player()->add_spell_point(-((int)this_player()->query_sp()));
    return 1;
  }
  tell_room(this_object(),BOLD+"The statue starts and shudders into life!\n"+NORM);
  move_object(clone_object(MON_PATH+"stone_harpy.c"),this_object());
  items[3]="Sorry, I must've misplaced it.  It's not here anymore";
  statue=1;
  if(present("penitent")) {
    tell_room(this_object(),"The penitent runs away in fear!\n");
    command("shrine",present("penitent"));
  }
  return 1;
}

query_coords() { return ({ 6,7 }); }
