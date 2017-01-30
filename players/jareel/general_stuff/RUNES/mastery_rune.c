/* Rune will add +1 to a weapons wc */

#include "/players/jareel/define.h"
#define tp this_player()->query_name()
#define tg this_player()->query_gender()

  inherit "obj/treasure";

  reset(arg) {
    if(arg) return;

  set_id("rune");
  set_short(HIK +"A Crafted Dwarven Rune of Mastery"+ NORM);
  set_long(
HIK+" ~-~-~---~-~---~-~--~--\n"+
"|                      |\n"+
"|    |                 |\n"+
"|    |                 |\n"+
"|    |_________        |     I have infused this piece of metal with a\n"+
"|    |      /          |     rune of mastery.  This will allow you to\n"+
"|    |     /           |     hit true to your target.  You only need to\n"+
"|    |    /            |     choose the weapon you wish to 'enscribe'.\n"+
"|    |   /             |                     \n"+
"|    |  /              |                   -Graoum Master BlackSmith                  \n"+
"|    | /               |\n"+
"|    |/                |\n"+
"|    |                 |\n"+
"|    |                 |\n"+
"|                      |\n"+
"|                      |\n"+
" ~-~-~---~-~---~-~--~--\n"+NORM);

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
      if(present(str,this_player())->weapon_class() > 0) {
      BE=(present(str,this_player())->weapon_class());
      present(str,this_player())->set_class(BE +1);
      write(HIK +"The Mastery Rune"+NORM+" is "+BOLD+"absorbed"+NORM+" into "+str+".\n"+ NORM);
      command("unwield "+str,this_player());
      command("wield "+str,this_player());
    destruct(this_object());
    return 1;}}
