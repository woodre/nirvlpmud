#include "def.h"

inherit ROOM;

reset(arg) {
  if(arg) return;
  set_no_teleport(1);
  set_light(1);
  short_desc=HIG+"Garden"+NORM+" of "+HIB+"Portals"+NORM;
  long_desc=
"  This is an orderly garden, filled with carefully pruned bushes and\n"+
"beautiful flowers in full bloom.  The paths are made out of carefully\n"+
"placed marble tiles which form the garden into complex geometric\n"+
"patterns.  In the center of the garden is a circular plaza with a\n"+
"rune-inscribed monolith in the middle.  At even intervals around the\n"+
"plaza are many rectangular portals, glowing azure in the mid-day light.\n"+
"Plaques at the foot of each portal indicates where they lead.\n";
  items=({
    "bushes","Beautiful growths of thick emerald vegetation",
    "flowers","A veritable cornucopia of colors and scents",
    "paths","The marble paths from which the castle takes its name criss-cross\n"+
            "the garden",
    "tiles","Beautiful marble tiles about a meter square",
    "plaza","The plaza is formed by six giant 'pie' slices of marble tile and is\n"+
            "about ten meters in diameter",
    "monolith","A ten foot tall marble monolith inscribed with glowing magical runes",
    "runes","You cannot decipher the exact meaning of the glowing runes on the\n"+
            "monolith",
    "portals","The portals stand roughly eight feet tall and a yard wide, but are\n"+
              "only two-dimensional.  They have no depth.  You can make out strange\n"+
              "swirling patterns within the azure light, but no details",
    "plaques","According to the plaques, the portals lead to the following locations:\n"+
              "\tshrine\tvillage\tangel\tsea\n"+
              "\tplain \tforest\n"
  });
  dest_dir=({
    ROOMPATH+"grove.c", "north",
    ROOMPATH+"workshop","west",
    ROOMPATH+"garden2", "east",
    ROOMPATH+"hall",    "south"
  });
}
init() {
  ::init();
  add_action("cmd_teleport","shrine");
  add_action("cmd_teleport","village");
  add_action("cmd_teleport","angel");
  add_action("cmd_teleport","sea");
  add_action("cmd_teleport","plain");
  add_action("cmd_teleport","forest");
}
cmd_teleport() {
  string dest;
  if(TP->query_sp() < 10) {
    write("You haven't the magical strength to survive the journey.\n");
    return 1;
  }
  switch(query_verb()) {
    case "shrine": dest="/players/feldegast/shrine.c";break;
    case "village": dest="/room/vill_green";break;
    case "angel": dest="/room/south/sforst45";break;
    case "sea": dest="/room/sea";break;
    case "plain": dest="/room/plane3";break;
    case "forest": dest="/room/forest10";break;
  }
  TP->add_spell_point(-random(10));
  write("You step into the "+HIB+"azure portal"+NORM+" and find yourself\n"+
        "somewhere else.\n");
  say(TPN+" steps into an "+HIB+"azure portal"+NORM+".\n");
  move_object(TP,dest);
  command("look",TP);
  say("An "+HIB+"azure portal"+NORM+" opens and "+TPN+" steps out.\n");
  return 1;
}

