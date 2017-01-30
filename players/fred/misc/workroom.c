
#include "/open/ansi.h"
#define TP this_player()
#define NAME "pestilence"
inherit "room/room";
int shield;

reset(arg) {
  if(arg) return;

long_desc =
  "This is the lobby of the Hotel Pestilence.  This is where the\n"+
  "wizard named pestilence likes to reside.\n";

set_light(1);

items = ({
  "couch","A large comfortable couch.",
  "desk","A scarred old desk with the intial 'B' carved in it",
});
}

short(){
 return ""+HIK+capitalize(this_player()->query_real_name())+" is Swirling in Disease"+NORM+""; }

init() {
  ::init();
  add_action("church","church");
  add_action("amity","amity");
  add_action("club","club");
  add_action("beach","beach");
  add_action("ozfest","ozfest");
  add_action("dangel","dangel");
  add_action("on"); add_verb("on");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
 }

church() {
  TP->move_player("church#room/church.c");
  return 1; }

club() {
  TP->move_player("club#/players/pestilence/club/room/parking.c");
  return 1; }

beach() {
  TP->move_player("beach#/players/pestilence/Cahara/room/beach.c");
  return 1; }

ozfest() {
  TP->move_player("ozfest#/players/pestilence/ozfest/field.c");
  return 1; }

dangel() {
  TP->move_player("dangel#/players/pestilence/dangel/manti.c");
  return 1; }
amity() {
  TP->move_player("amity#/players/pestilence/amity/room/nmain1.c");
  return 1; }

static on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
  return 1; }
