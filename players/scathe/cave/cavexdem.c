#include "lib.h"
inherit ROOM;
int R;

void create() {
    ::create();
/*  Moving this to reset() - once per reboot is silly - Rumplemintz
R = 1;
*/
    set_short("A Dark Place...");
    set_long("\
A dark cold room with a huge demon sitting in the middle of it.\n\
The dark stone walls have indentations all over them where the\n"+
"stone has chipped away and fallen.  The demon looks very happy\n"+
"to see you and that makes you wonder.\n");
    set_light(1);
    set_exits(([
        "south": "/players/scathe/cave/cavex4",
        ]));
}

void reset(int arg) {
    object monster;

    ::reset(arg);
    R=1;
    if (!present("demon", this_object())) {
        monster=clone_object("/players/scathe/monsters/demon");
        move_object(monster, this_object());
    }
}

init() {
  ::init();
  add_action("search","search");
}

search(str) {
object ob;
#if 0
if(present("demon")) {
#else
  if (present("guardian")) {
#endif    /* Changed to guardian instead of demon, as shardaks show up as
             'demon' -- Rumplemintz */
  write("The Guardian Demon laughs and hisses...\n");
  return 1; }
if(!str) { write("You search the floor and find nothing.\n"); return 1; }
/* Changing to allow 'indentations' as in the description - Rumplemintz
if(str == "indentation" && R == 1) {
*/
if(str == "indentation" || str == "indentations")
  if (R == 1) {
  write("You search the dark indentations and find a rod piece..\n");
  ob = clone_object("players/scathe/closed/rod3.c");
  move_object(ob,this_player());
  R = 0;
  return 1; }
else {
  write("You search the indentation and find only dust.\n");
  return 1; }
}
