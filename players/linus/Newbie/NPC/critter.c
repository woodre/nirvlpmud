#include "/players/linus/def.h"
inherit "/obj/monster.c";
int eek_i_died;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_aggressive(0);
set_race("critter");
set_dead_ob(TO);
switch(random(20)) {
case 0..4: critter1(); break;
case 5..9: critter2();break;
case 10..14: critter3();break;
case 15..19: critter4();break;
default: critter1();break;
 }
}
critter1() {
eek_i_died=1;
switch(random(3)) {
  case 0: set_short("A small "+YEL+"rabbit"+NORM);
 set_long("A small "+YEL+"brown rabbit"+NORM+" with long, floppy ears.  He hops around looking\n"+
 "for some grass to eat.\n"); break;
  case 1: set_short("A small "+HIK+"rabbit"+NORM);
 set_long("A small "+HIK+"grey rabbit"+NORM+" with long, floppy ears.  He hops around looking\n"+
 "for some grass to eat.\n"); break;
  case 2: set_short("A small rabbit");
 set_long("A small "+HIW+"white rabbit"+NORM+" with long, floppy ears.  He hops around looking\n"+
 "for some grass to eat.\n"); break;
  default: set_short("A small rabbit");
 set_long("A small "+YEL+"brown rabbit"+NORM+" with long, floppy ears.  He hops around looking\n"+
 "for some grass to eat.\n"); break;
}
set_name("rabbit");
set_alias("rabbit");
set_alt_name("bunny");
set_level(5);
set_hp(75);
set_ac(5);
set_wc(8);
set_chat_chance(10);
  load_chat("The rabbit hops around...\n");
  load_chat("The rabbit wiggles his nose.\n");
}
critter2() {
eek_i_died=2;
set_short("A small "+WHT+"grey squirrel"+NORM);
set_long(
"A "+WHT+"grey squirrel"+NORM+" with a soft white belly and a bushy tail.  He\n"+
"searches the ground for nuts to eat, chattering while he searches.\n");
set_name("squirrel");
set_level(5);
set_hp(75);
set_ac(5);
set_wc(7);
set_chat_chance(10);
  load_chat("The squirrel searches around for some nuts.\n");
   load_chat("The squirrel chatters...\n");
}
critter3() {
eek_i_died=3;
set_short("A small raccoon");
set_long(
"A small raccoon.  The black 'mask' around his eyes makes him look like\n"+
"a little thief.\n");
set_name("raccoon");
set_level(6);
set_hp(75);
set_ac(5);
set_wc(9);
set_chat_chance(3);
 load_chat("The raccoon scampers about...\n");
}
critter4() {
eek_i_died=4;
set_short("A small chipmunk");
set_long(
"A small chipmunk.  It is brown in color, and has a white and black\n"+
"stripe that runs from it's head to it's tail.\n");
set_name("chipmunk");
set_level(3);
set_hp(55);
set_ac(4);
set_wc(7);
set_chat_chance(3);
load_chat("The chipmunk forages around for some nuts.\n");
}
id(str) { return (::id(str) || str == "critter"); }
monster_died() {
if(eek_i_died  == 1) {
tell_room(environment(TO),"With a final blow, the rabbit's foot is torn from it's body.\n"),
 MO(CO("/players/linus/Newbie/obj/r_foot.c"),environment(TO));
return 1;
}
if(eek_i_died  == 2) {
tell_room(environment(TO),"With a final blow, the squirrel's tail is ripped from it's body.\n"),
 MO(CO("/players/linus/Newbie/obj/s_tail.c"),environment(TO));
return 1;
}
if(eek_i_died == 3) {
tell_room(environment(TO),"With a final blow, the raccoon's tail is torn from it's body.\n"),
 MO(CO("/players/linus/Newbie/obj/r_tail.c"),environment(TO));
return 1;
}
if(eek_i_died == 4) {
tell_room(environment(TO),"With a final blow, the chipmunk's tail is ripped from it's body.\n"),
 MO(CO("/players/linus/Newbie/obj/c_tail.c"),environment(TO));
return 1;
}
}

