#include "/players/laera/closed/ansi.h"
#define TP this_player()
#define NAME "laera"
inherit "room/room";
int shield;

reset(arg) {
   if(arg) return;
   
short_desc = "Laera's Retreat";
   long_desc = HIW+
   "High cliff walls surround three sides of this secluded little\n"+
"cove.  A bright warm "+OFF+HIY+"sun"+OFF+HIW+" shines down from a clear blue "+OFF+HIB+"sky"+OFF+HIW+" and\n"+
   "overlooks an emerald green "+OFF+GRN+"sea"+OFF+HIW+".  Two palm trees stand peacefully\n"+
   "in the sand, offering a cooling shade from the hot sun.  A gentle\n"+
   "breeze blows, bringing with it the clean scent of water and the\n"+
   "enchanting fragrance of tropical flowers.\n"+OFF;
   set_light(1);
   
   items = ({
         "cliffs","A high rocky cliff reaches up into the sky",
         "cliff walls","A high rocky cliff reaches up into the sky",
         "walls","A high rocky cliff reaches up into the sky",
         "up","The clear blue sky goes on forever",
         "sky","The clear blue sky goes on forever",
         "sun","The bright sun burns warmly in the sky",
         "trees","Two tall palm trees sway in the gentle breeze",
         "palm trees","Two tall palm trees sway in the gentle breeze",
         "down","A few seashells are scattered over the fine white sand",
         "ground","A few seashells are scattered over the fine white sand",
         "sand","A few seashells are scattered over the fine white sand",
         "seashells","Assorted seashells dot the beach, gently placed there "+
         "by the tide",
         "water","The sea is calm and clear, stretching out to meet the sky "+
         "on the horizon",
         "sea","The sea is calm and clear, stretching out to meet the sky "+
         "on the horizon"
});
   
   dest_dir = ({
         "room/church.c","church",
});
   
}

init() {
   ::init();
   add_action("church","church");
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
