#include "defs.h"

inherit ROOM;

int statue;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Sudakan: Plaza of the Merchants";
  long_desc=
    "  The plaza of the merchants bustles with the activity of the city's\n"+
    "buyers and sellers, hawking and purchasing their goods.  Wagons of\n"+
    "vegetables are carted about as livestock are herded to their new\n"+
    "owners.  In the center of the plaza is a statue of some fierce\n"+
    "creature sitting upon a pedestal.  On the east side of the plaza,\n"+
    "opposite the three streets is a neat looking shop.  To the side\n"+
    "of the shop is an alley.\n"+
    "  Streets: Sultan  Scroll  Plow\n"+
  "  Locations: Shop  Tailor\n";
  items=({
    "plaza","The plaza is a neat little circle perhaps eighty meters across,\n"+
            "with various shops and accounting houses on its edges.  To the\n"+
            "west, three streets head to the northwest, west, and southwest",
    "goods","You are fascinated by the myriad goods brought through this city:\n"+
            "Spices from the islands to the northwest, ore from the west, gold\n"+
            "and livestock from the imperial seat to the southeast",
    "statue","The statue depicts a strange creature with the body of a horse,\n"+
             "and the head and torso of a man.  A plaque on the pedestal asks\n"+
             "the question:\n"+
             "         'I work when I play\n"+
             "          and play when I work\n"+
             "          What am I called?'\n"+
             "You may 'answer' the question",
    "alley", "There is an alley next to the shop",
    "shop", "A sign above the door reads 'Sakadi's Fine Goods'",
  });
  dest_dir=({
    PATH+"sroy.c","sultan",
    PATH+"smark.c","scroll",
    PATH+"sgate.c","plow",
    PATH+"sshop.c","shop",
    PATH+"stailor.c","tailor",
    PATH+"salley.c", "alley",
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
  add_action("cmd_enter", "enter");
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
  if(str != "bard" && str!="musician" && str!="player") {
    write(HIM+"A dark shadow envelops you, leaving you weakened and drained.\n"+NORM);
    say(HIM+"A dark shadow envelops "+TPN+".\n"+NORM);
    this_player()->add_spell_point(-((int)this_player()->query_sp()));
    return 1;
  }
  tell_room(this_object(),BOLD+"The statue starts and shudders into life!\n"+NORM);
  move_object(clone_object(MON_PATH+"stone_centaur.c"),this_object());
  statue=1;
  items[5]="There is no statue";
  return 1;
}

int cmd_enter(string str) {
  if(str!="alley") {
    notify_fail("Enter what?\n");
    return 0;
  }
  say(TPN+" enters the alley.\n");
  move_object(TP,PATH+"salley.c");
  say(TPN+" arrives.\n");
  command("look",TP);
  return 1;
}

query_coords() { return ({ 6,7 }); }
