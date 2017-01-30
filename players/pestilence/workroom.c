
#include "/open/ansi.h"
#define TP this_player()
#define NAME "pestilence"
inherit "room/room";
int shield,i;

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
dest_dir = ({
"/players/pestilence/closed/dark/room/dhall.c","east",
/*
"/players/pestilence/arena/room/entry.c","west",
"/players/pestilence/closed/destroyer/room/hall.c","north",
"/room/church.c","north",
*/
});


}

init() {
  ::init();
  add_action("church","church");
  add_action("ice","ice");
  add_action("amity","amity");
  add_action("club","club");
  add_action("beach","beach");
  add_action("stop","east");
  add_action("ozfest","ozfest");
  add_action("hospital","hospital");
  add_action("dangel","dangel");
  add_action("post","post");
  add_action("on","on");
  add_action("post","post");
  add_action("off","off");
if(this_player()->query_real_name() != NAME && shield == 1) {
  write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
 }

short() {
  i = random(22);
if(this_player())
switch(i){


    case 0..1: return "CyberNinja Main Guild Hall [n,e,w,u,d]";
  break;

    case 2..3: return "Templar Inner-Chamber "+HIW+"["+NORM+"Fortress Stone"+HIW+"]"+NORM+" [s,u]";
  break;

    case 4..5: return "Village green [n,w,e]"+NORM+"";
  break;

    case 6..7: return "A grotto";
  break;

    case 8..9: return ""+HIG+"Dark Matter"+NORM+"";
  break;

    case 10..11: return ""+HIR+"SandStorm"+NORM+" [out,nexus]";
  break;

    case 12..13: return "Village church";
  break;

    case 14..15: return "Necromancer Stronghold [n,s,e,w,d]"+NORM+"";
  break;

    case 16..17: return ""+RED+"Power Ranger "+BLU+"Command Center"+NORM+"";
  break;

    case 18..19: return "Plane of Etheriel [many exits]";
  break;
    case 20..21: return "The Law Enforcers' meeting hall";
  break;
}
  else return "Pestilence's workroom"; /* v */
}

church() {
  TP->move_player("church#room/church.c");
  return 1; }

club() {
  TP->move_player("club#/players/pestilence/club/room/parking.c");
  return 1; }

ice() {
  TP->move_player("ice#/players/pestilence/ice/room/entry.c");
  return 1; }

beach() {
  TP->move_player("beach#/players/pestilence/Cahara/room/beach.c");
  return 1; }

ozfest() {
  TP->move_player("ozfest#/players/pestilence/test/field.c");
  return 1; }

dangel() {
  TP->move_player("dangel#/players/pestilence/dangel/manti.c");
  return 1; }
hospital() {
  TP->move_player("hospital#/players/pestilence/hospital/room/lobby.c");
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
stop() {
if(this_player()->query_level() > 18) { return 0; }
else{
write("Your too puny to go east.\n");
return 1; }
}
