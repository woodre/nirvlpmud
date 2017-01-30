/*
 * scanner.c - object for judging strength of object.  Shows the player
 * a "power rating" which is obtained as followed: (wc+ac)*level+hp
 * Should give them some idea of how powerful a monster is without
 * giving too much away.
 * Illarion - 10-24-98
 */
 
inherit "players/illarion/obj/clothes";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_id("scanner");
  set_alias("device");
  set_short("An odd looking device with a green lens");
  set_long(
"This interesting-looking artifact is made of a metal you can't identify,\n"+
"attached to a green lens that seems to be made of some kind of plastic.\n"+
"Looking at it closely, you decide you might be able to wear it with the\n"+
"lens over your eye.\n");
  set_wear_mess("wear_self","After a little fiddling, the device attaches "+
                            "itself to the side of your head, and the lens "+
                            "flips itself over your eye.");
  set_wear_mess("remove_self","You pull on the scanner, and it comes away "+
                              "easily.");
  set_wear_mess("wear_room","&NAME& attaches an odd-looking device with a "+
                            "lens to the side of &POSS& head.");
  set_wear_mess("remove_room","&NAME& removes some sort of device from the "+
                              "side of &POSS& head.");
  set_weight(1);
}
void init() {
  ::init();
  add_action("scan_look","look");
  add_action("scan_look","exa");
  add_action("scan_look","l");
  add_action("scan_look","examine");
}
void do_scan(object thing) {
  int pl;
  string rating;
  write("The lens over your eye suddenly comes to life.\n");
  if(thing->is_player()) {
    write(GRN+" >> Power Level: "+NORM+"unavailable"+GRN+" <<\n"+NORM);
    return;
  }
  pl=((int)thing->query_wc()+(int)thing->query_ac());
  pl*=(int)thing->query_level();
  pl+=(int)thing->query_hp();
  pl=(pl-(pl/10))+random(pl/5);  /* +/- 5 % variation */
  switch(pl) {
    case 1..300:     rating=YEL+"harmless"; break;
    case 301..600:   rating=GRN+"nearly harmless"; break;
    case 601..900:   rating=HIG+"average"; break;
    case 901..1200:  rating=HIY+"above average"; break;
    case 1201..1500: rating=RED+"powerful"; break;
    case 1501..1800: rating=HIM+"very powerful"; break;
    default:         rating=HIR+"extremely powerful"; break;
  }
  write(GRN+" >> Power Level: "+rating+GRN+" <<\n"+NORM);
  return;
}
int scan_look(string str) {
  object thing;
  if(!str) return 0;
  if(!worn_by) return 0;
  if(query_verb()=="l" || query_verb()=="look")
    if(!sscanf(str,"at %s",str)) return 0;
  if(!(thing=present(str,environment(TP)))) return 0;
  if(!living(thing)) return 0;
  do_scan(thing);
  return 0;
}
