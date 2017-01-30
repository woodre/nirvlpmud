#include "/players/mythos/closed/ansi.h"
/*
#include "/closed/handshake.h"
*/
inherit "players/mythos/closed/play/frame";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shikigami");
  set_level(200);
  set_short("Shikigami");
  set_long("A small white bird.\n");
  set_race("avatar");
  set_gender("female");
  snoops("reflex");
}