#include "/room/std.h"
#include "/players/cosmo/closed/ansi.h"
#define NAME "cosmo"

int shield;

reset(arg) {
  if (arg)
    return;
  no_clean=1;
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("on"); add_verb("on");
  add_action("off"); add_verb("off");
  add_action("dc"); add_verb("dc");
  add_action("advance"); add_verb("advance");
  add_action("pub"); add_verb("pub");
  add_action("apartment"); add_verb("apartment");
#else
  add_action("on", "on");
  add_action("off", "off");
  add_action("dc", "dc");
  add_action("advance", "advance");
  add_action("pub", "pub");
  add_action("apartment", "apartment");
#endif
  set_light(1);
  if(this_player()->query_real_name() != NAME && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off the defense shield.\n");
    this_player()->move_player("off the shields#room/church");
  }
}

static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
}

static off() {
   if (call_other(this_player(), "query_real_name", 0) != NAME) {
     write("You are not allowed to do that!!!!!!!\n");
     return 1;
   }
   shield = 0;
   write("shields deacivated.\n");
   return 1;
}

short() {
   string *names, *weapons, *rooms;
   string name, weapon, room, color, str;

   names = ({ "Ms. Scarlett", "Col. Mustard", "Miss White", "Mr. Green",
      "Professor Plum", "Mrs. Peacock" });
   weapons = ({ "rope", "knife", "lead pipe", "wrench", "revolver",
      "candlestick" });
   rooms = ({ "Lounge", "Dining Room", "Hall", "Study", "Kitchen", "Library",
      "Billiards Room", "Conservatory", "Ballroom" });
   name = names[random(sizeof(names))];
   weapon = weapons[random(sizeof(weapons))];
   room = rooms[random(sizeof(rooms))];
   color=get_color();
   str = color+name+NORM+" in the "+color+room+NORM+" with the "+
      color+weapon+NORM;
   return str;
}

string get_color() {
   int blah;
   string clr;
   blah = random(14);
   switch(blah) {
     case 0:  clr = RED; break;
     case 1:  clr = GRN; break;
     case 2:  clr = YEL; break;
     case 3:  clr = BLU; break;
     case 4:  clr = MAG; break;
     case 5:  clr = CYN; break;
     case 6:  clr = BOLD+BLK; break;
     case 7:  clr = HIR; break;
     case 8:  clr = HIG; break;
     case 9:  clr = HIY; break;
     case 10: clr = HIB; break;
     case 11: clr = HIM; break;
     case 12: clr = HIC; break;
     case 13: clr = HIW; break;
   }
   return clr;
}

long() {
   write("\n\nExits exist to: dc, apartment, pub, advance.\n");
}

advance() {
   this_player()->move_player("advance#room/adv_guild.c");
   return 1;
}

dc() {
  this_player()->move_player("district#/players/cosmo/dc/rooms/entrance");
  return 1;
}

pub() {
  this_player()->move_player("pub#room/pub2");
  return 1;
}

apartment() {
  this_player()->move_player("Jerry's place#/players/cosmo/apt/rooms/lobby");
  return 1;
}
