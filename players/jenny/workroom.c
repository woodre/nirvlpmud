#include "/players/jenny/define.h"
inherit "/players/jenny/room";
int shield,THESHORT,justfriends;
string WORKROOMSHORT;

reset(arg) {
/*
 * this thing should not be cloned.
 * bugs out. -verte 
 *
   if(!present("display"))  {
     MOCO("/players/cosmo/hslist/svds_new.c"),this_object()); 
     WORKROOMSHORT = RED+"The Penalty Box"+NORM;
}
 *
 */

  if(arg) return;

long_desc =
  "This is a small closed off area along the ice surface of Joe Louis\n"+
  "Arena.  There is a small bench, which has room for about 3 players\n"+
  "to sit comfortably.  Through the plexiglass, you have a perfect\n"+ 
  "view of the game.\n";

set_light(1);
set_smell(""+YEL+"You breathe in the musty smell of the penalty box."+NORM+"");
set_listen(""+RED+"You hear the crowd erupt in joy as a goal is scored."+NORM+"");

items = ({
  "bench","An uncomfortable wooden bench",
  "plexiglass","This keeps you from getting hit by an errant puck",
  "game","Fedorov just scored.  Detroit is up 3-1",
});
}
short() {
   return WORKROOMSHORT; }
init() {
   if(TP->query_real_name() !="jenny")  {
   command("french jenny",TP); }
     ::init();

   add_action("church","church");
   add_action("ninjaz","cybers");
   add_action("trapdoor","expell");
   add_action("givetool","gettool");
   add_action("on","on");
   add_action("post","post");
   add_action("friends","friends");
   add_action("off","off");

     if(TPRN != "jenny" && shield == 1) {
        write("You feel an electric shock and see a FLASH of white light\n"+
        "as you rebound off some surrounding shield.\n");
           TP->move_player("off the shields#room/church");
              return 1; }
     if(TPRN == "jenny" || TPRN == "jaraxle" || TPRN == "brittany" || TPRN == "eurale" || TPRN == "dragnar" || TPRN == "catwoman" || TPRN == "jareel" || TPRN == "angelique") {
        write(RED+"Welcome "+CAP(TPRN)+"."+NORM+"\n"+
        "\n");
           return 1; }

        else if(justfriends == 1) {
           write("Jenny doesn't want you here.  Maybe you will be more welcome\n"+
           "in the church.\n");
               TP->move_player("off the shields#room/church");
                  return 1; }}

ninjaz() {
   if(TPRN == "jenny" || TPRN == "jentest") {
   move_object(TP,"/players/dune/closed/guild/rooms/guildhall.c");
   command("look",TP);
   return 1; }}

church() {
  TP->move_player("church#room/church.c");
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
    return 1; }
 
friends() {
   if(justfriends != 1) {
      write("Only friends may enter now.\n");
      justfriends = 1; return 1; }
   if(justfriends = 1) {
      write("Anyone can enter now.\n");
      justfriends = 2; return 1; }
         return 1; }

on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n"); 
  shield = 1;
  return 1; }

off() {
  if(TPRN != "jenny" && TPRN != "jentest") { 
    write("You are not allowed to do that!!!!!!!\n");
    return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
    return 1; }

redwings(){
     WORKROOMSHORT = BOLD+WHT+"Center Ice - "+RED+"Joe Louis Arena"+NORM;
          return 1;}
duke(){ 
     WORKROOMSHORT = BLU+"Hazzard County Jail"+NORM;
          return 1;}
eighties(){
     WORKROOMSHORT = RED+"The Cosby Residence"+NORM;
          return 1;}
bundy(){
     WORKROOMSHORT = CYN+"Al Bundy's Bathroom"+NORM;
          return 1;}


givetool() {
   if(TPRN == "jenny" || TPRN == "jentest") {
      MOCO("/players/jenny/closed/stick/stick.c"),TP);
         return 1;}}
