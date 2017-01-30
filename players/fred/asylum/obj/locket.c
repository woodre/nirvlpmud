inherit "/obj/armor";
#include <ansi.h>
#define tpn this_player()->query_name()
int opened, closed;

reset(arg) {
  opened = 0;
  closed = 0;
  if(arg) return;
  ::reset(arg);
  set_name("necklace");
  set_short("A "+BOLD+HIY+"golden"+NORM+" necklace");
  set_long(
  "  An old golden necklace that once belonged to a patient\n"+
  "at F.I.A. At the end of the necklace is a small locket with\n"+
  "a small clasp on the side.\n");
  set_type("misc");
  set_ac(2);
  set_weight(1);
  set_value(800);
}
  
query_save_flag(){
  return 1; }

init(){
  ::init();
    add_action("open_it","open");
    add_action("close_it","close");
    add_action("blah","look");
    add_action("blah","l");
  }

open_it(str){
  if(!str){ write("What would you like to open?\n"); return 1; }
  if(str == "locket"){
  if(opened){
    write("The locket is already opened!\n");
    return 1; }
  write("You push on the small clasp and open up the locket.\n");
  say(tpn+" opens the locket.\n");
  opened = 1;
  closed = 0;
  return 1; }
 }

close_it(str){
  if(!str){ write("What would you like to close?\n"); return 1; }
  if(str == "locket"){
  if(closed){
    write("The locket is already closed!\n");
    return 1; }
  write("You squeeze the locket between your fingers and it snaps shut.\n");
  say(tpn+" closes the locket.\n");
  closed = 1;
  opened = 0;
  return 1; }
  }

blah(str){
  if(str == "at clasp"){
    write("A small clasp used to open the locket.\n");
    return 1; }
  if(str == "at locket"){
  if(opened){
    write("A small golden locket that is open. There is a small picture\n"+
          "inside of it and some initials carved into the back.\n");
    return 1; }
  else{
    write("A small golden locket that is closed. Perhaps you could open it.\n"+
          "There are some initials carved into the back of the locket.\n");
    return 1; }
  }
  if(str == "at picture"){
  if(opened){
    write("An old black and white picture of a mother and her small child.\n");
    return 1; }
  else{
    write("The locket isn't open.\n");
    return 1; }
  }
  if(str == "at initials"){
    write("The initials S.O are carved into the locket.\n");
    return 1; }
  }
