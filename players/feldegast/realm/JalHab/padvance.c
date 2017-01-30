#include "defs.h"
#include "/room/tune.h"
#define BANNED ({ "healer", "polymorph", "knights templar", "symbiote" })

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("p'chilik"))
    move_object(clone_object(MON_PATH+"pchilik"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="The Training Hall";
  long_desc=
"  Warriors from near and far have come to train with the renowned\n\
master of martial combat known as P'chilik.  Various platforms and\n\
practice mats are placed around this training hall.  Against the left\n\
wall are a row of practice dummies.\n\
Commands: advance, raise <attribute>\n";
  items=({
    "platforms","Raised platforms made out of wood, for students to learn balance",
    "mats","The mats are stuffed with desert weeds, but at least they'll"+
           "break your fall a little",
    "dummies","Practice dummies for practicing moves when nobody else will\n"+
              "play with you",
  });
  dest_dir=({
    PATH+"pwell.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_advance","advance");
  add_action("cmd_raise","raise");
}

int cmd_advance(){
  if(member_array(this_player()->query_guild_name(),BANNED) != -1) {
    notify_fail("P'chilik says: I cannot train you.\n");
    return 0;
  }
  if(this_player()->query_level() > 18){
    write("P'chilik says: I cannot teach you any more.\n");
    return 1;
  }
  "/room/adv_guild"->advance();
  return 1;
}

cmd_raise(str) {
  string attrib,raise,thing;
  int new,expcost,current,minexp;
  if(!present("p'chilik")) {
    write("There is no one here to teach you.\n");
    return 1;
  }
  if(member_array(this_player()->query_guild_name(),BANNED) != -1) {
    notify_fail("P'chilik says: I cannot train you.\n");
    return 0;
  }
  if (str !="str" && str !="sta" && str != "wil" && str != "mag" && str !="pie" && str != "ste" && str != "luc" && str != "int")
  {
    write ("Raise what?\n");
    return 1;
  }
  if(this_player()->query_guild_name() == "paladin") {
    write("You must raise your attributes at your guild hall.\n");
    return 1;
  }
  if(this_player()->query_guild_name() == "Knights Templar") {
    if(str == "mag" && this_player()->query_attrib("mag") > 11) {
      write("Knights Templar may not raise their magical aptitude above 12\n");
      return 1;
    }
    if(str == "ste" && this_player()->query_attrib("ste") > 9) {
      write("Knights Templar may not raise their stealth above 10\n");
      return 1;
    }
  }
  if (call_other(this_player(), "query_level", 0) > 19) {
    write("wizards cannot advance attributes.\n");
    return 1;
  }
  if (str == "str") attrib = "strength";
  if (str == "sta") attrib = "stamina";
  if (str == "wil") attrib = "will_power";
  if (str == "mag") attrib = "magic_aptitude";
  if (str == "pie") attrib = "piety";
  if (str == "ste") attrib = "stealth";
  if (str == "luc") attrib = "luck";
  if (str == "int") attrib = "intelligence";
  raise = "raise_" + attrib;
  current = call_other(this_player(), "query_attrib", str);
  new = current + 1;
  if (current < 11) expcost = -ATTRIB_COST;
  if (current < 12 && current > 10) expcost = -3*ATTRIB_COST/2;
  if (current < 14 && current > 11) expcost = -ATTRIB_COST_TWO;
  if (current < 16 && current > 13) expcost = -4*ATTRIB_COST_TWO/3;
  if (current < 18 && current > 15) expcost = -ATTRIB_COST_THREE;
  if (current < 21 && current > 17) expcost = -4*ATTRIB_COST_THREE/3;
  if (current > 19) {
    write (attrib + " is at highest possible value.\n");
    return 1;
  }
  if(this_player()->query_extra_level() < 1)
    minexp = this_player()->query_exp() - call_other("/room/adv_guild", "get_next_exp",this_player()->query_level()-1);
  if(this_player()->query_extra_level() > 0)
    minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
  if (expcost < -minexp) {
    write ("You don't have enough experience available to raise an attribute.\n");
    return 1;
  }
  switch(str) {
    case "str": write("You pump some weights, do some push-ups, and stomach crunches.\n"+
                      "You feel stronger now.\n");
                break;
    case "sta": write("You race around the village a few dozen times in the midday sun,\n"+
                      "developing your endurance.  You feel much more endurable.\n");
                break;
    case "wil": write("You engage P'chilik in a staring contest.  After hours have passed, you blink,\n"+
                      "but you feel much stronger willed now.\n");
                break;
    case "mag": write("P'chilik whispers to you the secrets of the desert, words of wisdom, and the\n"+
                      "legends of the gods.  You feel your knowledge of the arcane increase.\n");
                break;
    case "pie": write("P'chilik teaches you of the Seven Gods of Allandria: The Sage, The Builder,\n"+
                      "The Hunter, The Maiden, The Stranger, The Guardian, and The Trickster.  After\n"+
                      "listening to him, you feel more at peace with the Gods.\n");
                break;
    case "ste": write("P'chilik teaches you how to move stealthily through the desert, using shrubs\n"+
                     "to conceal yourself, and how to place your feet so that you make no noise.\n");
                break;
    case "luc": write("P'chilik says: There is no chance in this world.  We make our own odds.  All\n"+
                      "that is necessary is that we bend the world to our needs.  You feel luckier.\n");
                break;
    case "int": write("P'chilik lectures you on the histories and philosophies of Allandria, then\n"+
                      "challenges you with cunning riddles and puzzles.  You feel smarter.\n");
                break;
  }

  call_other(this_player(), raise, 1);
  call_other(this_player(), "add_exp", expcost);
  return 1;
}
