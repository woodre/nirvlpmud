/* scroll for ~/ed area[s] by vertebitch@nirvy */

#include "../../define.h"
inherit ITEM;
static int r;


void reset(int x) {
   if(x) return;
   set_id("scroll");
   set_alias("note");
   set_value(20+random(10));
   set_weight(0); /* it's a piece of paper, it shouldn't have a weight */ }

void init() {
   ::init();
   add_action("do_open","open");
   add_action("do_close","close");
   add_action("do_read","read"); }

int do_open(string str) {
   if(id(str) && !r) {
      write("You open up the scroll...\n");
      r = 1;
      return 1; }
   else return 0; }

int do_close(string str) {
   if(id(str) && r) {
      write("You close up the scroll...\n");
      r = 0;
      return 1; }
   else return 0; }

int do_read(string str) {
   if(id(str) && r) {
      write(
         "\nYou read the scroll...\n\n"+
         "\tFrom a path of darkness drawn through the forest\n"+
         "\techoes the footsteps of a great warrior.  Unconventional\n"+
         "\tthough he may be, He will save us from the Evil\n"+
         "\twhich has penetrated these woods.  Weak though\n"+
         "\the may look, he is Humanity's only hope......\n"+
         "\tHe has been beaten down by the evil... Rescue him....\n"+
         "\tHead north from here, and proceed to travel the compass\n"+
         "\tpath clockwise, starting from where the North Star shines....\n"+
         "\tPlease... Help him... Save my Soul......\n"+
         "Crusted bloodstains rest at the bottom of this note, but you can make\n"+
         "out the name \"Professor Knowleby\" scrawled at the bottom.\n\n"+
         "A simple picture of a dark-haired man with a metal gauntlet standing\n"+
         "atop a castle has been drawn on the opposite side of the scroll.\n\n");
      return 1; } else return 0; }

string short() {
   return "A tattered scroll"; }

void long() {
   write 
   ("This is a tattered, yellowed scroll.  It looks like it has been\n"
      +"stained with blood.\n");
   if(!r) return write("You can open it up.\n");
   else return write("You can read it.\nOr, close it up, if you wanted to.\n"); }

