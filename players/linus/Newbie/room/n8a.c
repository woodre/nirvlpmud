#include "/players/linus/def.h"
inherit "/room/room.c";
 reset(arg) {
if(!present("gopher",TO)) {
 MO(CO("/players/linus/Newbie/NPC/gopher.c"), TO);
 }
if(!present("fat_gopher",TO)) {
 MO(CO("/players/linus/Newbie/NPC/gopher2.c"), TO);
}
if(!present("female_gopher",TO)) {
 MO(CO("/players/linus/Newbie/NPC/gopher3.c"), TO);
}
  set_light(1);
  short_desc = GRN+"In the garden"+NORM;
  long_desc = GRN+
  "Rows and rows of vegetables grow in this garden.  There are many\n"+
  "rows of carrots, lettuce, radishes, beans and other vegetables.  Small\n"+
  "signs stand at the ends of the rows, telling what vegetable grows\n"+
  "there.  A white picket fence surrounds the garden, and a small gopher\n"+
  "hole can be seen in the northwest corner of the garden.\n"+NORM;
  items = ({
  "rows","Rows of vegetables growing in the garden",
  "garden","Rows of vegetables grow in this garden",
  "vegetables","Carrots, lettuce, radishes and beans growing in the garden",
  "carrots","Fine looking carrots growing in the garden",
  "lettuce","Large, leafy heads of lettuce growing in the garden",
  "radishes","Plump radishes growing in the garden",
  "beans","Delicious looking green beans growing in the garden",
  "signs","Small signs that tell what grows in each garden row",
  "fence","A white picket fence surrounds the garden",
  "gopher hole","A small hole in the ground dug by gophers",
  "hole","A small hole in the ground dug by gophers"  });
  dest_dir = ({ NEWB+"n8.c","exit" });
  }
 init() {
  ::init();
  add_action("enter_hole","enter");
  add_action("Listen","listen");
 }
 enter_hole(string str) {
  if(!str || str !="hole") { FAIL("What are you trying to enter?\n");  return 0; }
  if(str=="hole") {
write("You try to enter the hole, but are too big!\n");
say(TPN+" tries to enter the hole, but is too big!\n");
 return 1;
 }
}
Listen() {
  write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
