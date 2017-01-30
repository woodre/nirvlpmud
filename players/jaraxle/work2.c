
#include "/players/jaraxle/define.h"
#define TP this_player()
#define NAME "jaraxle"
inherit "room/room";
int shield, RANDOM;

reset(arg) {
   if(arg) return;
   
   
   long_desc =
   "A sparse working area with nothing but a desk and chair. You may\n"+
   "turn your privacy shield (on/off). There are also hidden exits to\n"+
   "the 'church' and the 'post' office.\n";
   set_light(0);
   
   items = ({
         "chair","A creaky old wooden chair",
         "desk","A scarred old desk with the intial 'B' carved in it",
});
   
}

short(){ 
return "";
}

init() {
   ::init();
   add_action("church","church");
  add_action("post", "post");
  add_action("off", "off");
  add_action("church", "church");
   if(this_player()->query_real_name() != NAME && shield == 1) {
      write("You feel an electric shock and see a FLASH of white light\n"+
         "as you rebound off some surrounding shield.\n");
      this_player()->move_player("off the shields#room/church");
      return 1; }
}

church() {
   TP->move_player("church#room/church.c");
   command("look",this_player());
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
