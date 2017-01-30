/*
 *     opouch.c             
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */


inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("pouch");
   set_short("Oak's Fairy Dust Pouch");
   set_long(
   "A small silky pouch that holds magical fairy dust.\n");
   set_weight(0);
   set_value(4000 + random(1000));
}
 init() {
     ::init();
   add_action("open","open");
   add_action("put","put");

   }

   open(arg) {

   if(arg != "pouch") {

   notify_fail("Open what?\n");
   return 0;
  }

   write("You try to open the pouch, but can't!\n");

   return 1; }


   put(arg) {

   if(arg != "pouch") {

   notify_fail("Put what?\n");
   return 0;
  }

   write("You try to put something in the pouch, but cant!\n");

   return 1; }
