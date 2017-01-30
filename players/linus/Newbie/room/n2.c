#include "/players/linus/def.h"
inherit "/room/room.c";
int i, bees, shook;
   reset(arg){
  if(!present("bee",TO)) {
   for(i=0; i<5+random(5); i++) {
  MO(CO("/players/linus/Newbie/NPC/bee2.c"),TO);
}
}
if(arg) return;
     set_light(1);
     shook = 0;
     short_desc = GRN+"The hundred acre wood"+NORM;
     long_desc = GRN+
  "The forest floor is covered with soft, green grass.  Tall trees\n"+
  "grow throughout the forest, along with flowering shrubbery.  A small\n"+
  "dirt footpath can be seen meandering around the trees.  A large oak\n"+
  "tree stands near the footpath.  Hanging from one of its branches is\n"+
  "a large beehive.\n"+NORM;
    items = ({
       "tree","A large oak tree that has stood the test of time",
       "oak","A large oak tree that has stood the test of time",
       "oak tree","A large oak tree that has stood the test of time",
       "forest floor","Soft green grass covers the forest floor",
       "floor","Soft green grass covers the forest floor",
       "forest","Grass, trees, and flowering shrubbery make up the forest",
       "branch","A strong branch on an oak tree that a beehive hangs from",
       "trees","Oak, maple, pine, and others make up the forest.  Some have been around for\n"+
               "decades, and others are saplings",
       "saplings","Young oak, maple and pine trees",
       "beehive","Yellow in color, the beehive is round shaped and appears to be built\n"+
                 "out of a paper-like substance.  It wouldn't be wise to disturb the hive",
       "hive","Yellow in color, the beehive is round shaped and appears to be built\n"+
              "out of a paper-like substance.  It wouldn't be wise to disturb the hive",
       "substance","A paper-like substance that is produced by bees.  It is yellow in color",
       "footpath","Brown dirt where grass will no longer grow",
       "grass","Soft green grass that covers the forest floor",
       "path","Brown dirt where grass will no longer grow",
       "shrubbery","It is bright green in color, covered with small yellow and red flowers",
       "shrub","It is bright green in color, covered with small yellow and red flowers",
       "bushes","It is bright green in color, and covered in small red and yellow flowers",
       "flowers","Small yellow and red flowers",
       "flower","A small yellow and red flower",
          }); 
    dest_dir = ({
         NEWB+"n1.c","south",
         NEWB+"n3.c","north"
          });
 }
init() {
  ::init();
  add_action("Listen","listen");
  add_action("Smell","smell");
 /* Added following add_actions to clone more bees */
  add_action("Disturb","poke");
  add_action("Disturb","shake");
  add_action("Disturb","disturb");
}
Listen() {
   write("The soft buzzing of bees can be heard from within the beehive.\n");
 return 1;
}
Smell() {
  write("The lovely fragrance of the flowers stimulates the senses.\n");
 return 1;
}
 /* Will clone more bees if the beehive is disturbed */
 /* Uses a call_out sequence and will do a max of 20 bees */
 /* with no more than 10 in a room at any one time. */
Disturb(arg) {
  if(!arg || arg != "hive") { FAIL("Do what?\n"); return 0; }
  if(arg == "hive" && shook == 0) {
 write("You disturb the beehive...\n");
 say(TPN+" disturbs the beehive...\n");
 call_out("bees_coming_out", 6);
 bees = 1;
 shook = 1;
 return 1;
}
 else write("You disturb the beehive, but nothing happens.\n");
           say(TPN+" disturbs the beehive, but nothing happens.\n");
return 1;
}
how_many_bees() { return bees; }
bees_coming_out() {
 if(!present("bee 10", TO)) {
 bees ++;
 MO(CO("/players/linus/Newbie/NPC/bee2.c"), TO);
 tell_room(TO,"A bee flies out to defend the hive!\n");
  }
 if(bees > 19) return;
 else call_out("bees_coming_out", 6);
}
