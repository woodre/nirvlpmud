#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A large tree";
long_desc =
  "  You are about 25 feet from the ground at this point.  You are well\n"+
  "hidden from below.  The tree is much larger than it looked from your\n"+
  "vantage point on the ground.  The branches are spaced farther apart\n"+
  "higher up which will make climbing higher much more hazzardous.  As\n"+
  "you look up through the limbs and leaves, there appears to be some\n"+
  "kind of opening in the trunk.\n";

items = ({
  "branches","Thick, sturdy limbs which will support much",
  "limbs","Branches sprouting off of the trunk",
  "leaves","Green, healthy oak leaves",
  "opening","It's too far up to see well",
});

dest_dir = ({
  "players/eurale/Glade/eg4.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("climb","climb");
}

search() {
  write("You search through the leaves and find nothing special.\n");
  return 1; }
  
/* changed 2004.09.12 -forbin (was never updated for new stat system
   made being over 85% carry a slight detriment for thematic reasons
climb(str) {
int num;
if( (!str) || str == "tree" || str == "oak") {
num = random(26);
  if(tp->query_attrib("luc") > num) {
    tp->move_player("higher#players/eurale/Glade/oak2.c");
    return 1; }
  else {
    write("As you reach to grab a higher branch, you lose your footing\n"+
	  "and plummet to the ground... OOOF!\n");
    tp->move_player("falling#players/eurale/Glade/eg4.c");
    tp->hit_player(random(80));
    return 1; }
return 1; }
}
*/

climb(string str) {
  int num;
  int myweight, carry, ratio;
  if((!str) || str == "tree" || str == "oak") {
    num = random(35);
    carry = (int)this_player()->query_level();
    carry += 6;
    carry += (int)this_player()->query_attrib("str")/5;
    myweight= (int)this_player()->query_local_weight();
    ratio = myweight / carry;
    if(ratio > 85) num += 3;
    if(this_player()->query_attrib("luc") > num) {
      this_player()->move_player("higher#players/eurale/Glade/oak2.c");
      return 1; 
    }
    else {
      write("As you reach to grab a higher branch, you lose your footing\n"+
	    "and plummet to the ground... OOOF!\n");
      this_player()->move_player("falling#players/eurale/Glade/eg4.c");
      this_player()->hit_player(random(80));
      return 1; 
    }
    return 1; 
  }
}
