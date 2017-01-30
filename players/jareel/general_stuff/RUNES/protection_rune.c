/* Rune will add +1 to a armors ac */

#include "/players/jareel/define.h"
#define tp this_player()->query_name()
#define tg this_player()->query_gender()

  inherit "obj/treasure";

  reset(arg) {
    if(arg) return;

  set_id("rune");
  set_short(HIK +"A Protection Rune"+ NORM);
  set_long(
    "\n"+
    "\n"+
    "\n");
  set_weight(1);
  set_value(2000);
}


init() {
  ::init();
  add_action("enscribe","enscribe");
  }
  
enscribe(str) {

  int BE;

  string path, num;
 
    if(!str) {write(BOLD +"What do you wish to enscribe?\n"+ NORM); return 1;}
      if(present(str,this_player())->armor_class() > 0) {
      BE=(present(str,this_player())->armor_class());
      present(str,this_player())->set_ac(BE +1);
      write(HIK +"The Protection Rune"+NORM+" is "+BOLD+"absorbed"+NORM+" into "+str+".\n"+ NORM);
      command("remove "+str,this_player());
      command("wear "+str,this_player());
    destruct(this_object());
    return 1;}}
