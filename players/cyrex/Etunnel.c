inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tunnel";

long_desc =
  "  Strangely, you have stumbled upon some sort of tunnel...  to your\n"+
  "surprise this tunnel seems extraordinarily new.  As you stare at \n"+
  "your new surroundings, you notice that the tunnel walls look like\n"+
  "they are all computerized with streaks of light flashing by.  Due\n"+
  "to all the blinking lights, you seem to be getting a headache.  You\n"+
  "sense a wierd feeling about the light.....\n\n";

items = ({
  "walls","Transluscent walls of flashing light.  It's dizzying to\n"+
	"to look at, disorienting... maybe you could find something\n"+
	"if you search them",
  "light","Flashing light... like a strobe",
  "lettering","Small but maybe you could read it",
});

dest_dir = ({
	"players/cyrex/shaft11.c","west",
});

}

init() {
 add_action("west", "west");
  add_action("search","search");
  add_action("insert","insert");
  add_action("read","read");
}

west(arg) {
 this_player()->move_player("west#players/cyrex/shaft11");
return 1;
}

search(str) {
if(!str) { write("You search the tunnel floor and find nothing.\n");
  return 1; }
if(str == "walls" || str == "wall") {
  write("You slide your hand over the wall and find a small hidden\n"+
	"slot with some lettering beside it.\n");
  return 1; }
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "lettering") {
  write("Access - Insert Card\n");
  return 1; }
}

insert(str) {
object ob;
ob = present("accesscard",this_player());
if(!str) { write("Insert what?\n"); return 1; }
if(str == "card" && !ob) {
  write("Apparently you don't have the correct card.\n");
  return 1; }
else {
  write("\n\n\n");
  write("The lights begin to speed up.......\n\n"+
	"you get dizzy and lightheaded.....\n\n"+
	"YOU PASS OUT!.....\n\n"+
  "and when you awaken, you're somewhere else.....\n\n\n");
  this_player()->move_player("light#players/cyrex/quest/rchamber.c");
/* Why destruct the card?  - Rumplemintz
  destruct(ob);
*/
  return 1; }
}
