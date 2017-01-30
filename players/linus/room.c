#include "/sys/lib.h"
#include "/players/linus/def.h"
inherit "/room/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 short_desc = GRN+"The hundred acre wood"+NORM;
 long_desc = GRN+
 "Tall green grass covers the ground of this large field.  A gentle\n"+
 "breeze blows through, causing the grass to sway, it's rhythmic motion\n"+
 "resembling waves in a body of water.  The sound of songbirds chirping\n"+
 "from within a forest that stands to the north.\n"+NORM;
  items = ({
 "grass","Tall, green grass",
 "footpath","Brown dirt where grass will no longer grow",
 "path","Brown dirt where grass will no longer grow",
 "forest","Oak, maple, and other assorted trees make up the forest",
 "trees","Oak, maple, and other assorted variety of trees",
 "field","Tall green grass covers the ground",
 "ground","Tall green grass covers the ground" });
 dest_dir = ({
 NEWB+"n2.c","north",
"/room/south/sforst10.c","southwest",
 });
 }
}
init() {
  ::init();
  add_action("Listen","listen");
}
Listen() {
  write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
