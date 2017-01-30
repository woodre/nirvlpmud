/*
  testit.c - test new .h files
*/

#include "/players/nooneelse/black/lib/bat_message.h"

inherit "/obj/treasure";

id(str) { return str == "testit"; }

short() { return "A small testing device (testit)"; }

init() {
  add_action("message_bat","mbat");
}
