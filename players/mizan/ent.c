int descr;
#define DEST2 "players/mizan/dirt.c"
string nums;
reset(arg) {
  if(!nums) {
    nums=allocate(7);
nums[0]="pink";
  nums[1]="green";
  nums[2]="blue";
  nums[3]="red";
  nums[4]="purple";
  nums[5]="orange";
  nums[6]="yellow";
  }
  descr=random(6);
   if(arg) return;
  move_object(this_object(), "/room/wild1.c");
}

destme(str) {
  if(str == "tub" || str == "jello") {
    write("I DON'T THINK SO!\n");
    write_file("/players/mizan/closed/CASTLE_LOG", (this_player()->query_real_name()) + " dested the castle for NO fucking reason whatsoever.\n");
    return 1;
  }
  return 0;
}

/* I am NOT paranoid! I put this cmd in because some fucker enjoys desting
    the castle. Nice hat. *spit*
 */

id(str) { return str == "tub" || str == "jello"; }
is_castle() { return 1; }
short() {
  return "A tub of " + nums[descr] + " jello";
}

long() {
  write("You see a large wooden tub filled with jello. You poke it. It quivers.\n"+
  "You smell it. Mmmm... Yummy. You lick it... It tastes good. \n"+
  "Somehow, you have a curious urge to 'dive' into it...\n");
}

init() {
  add_action("destme","dest");
  add_action("destme","destruct");
  add_action("long_entry","dive");
  add_action("short_entry","down");
}

long_entry() {
write("You dive into the jello! *Sploop!* *Blork* \n\n");
  write("A strange voice lectures: Type 'help jello' for a list of extended commands!\n");
  call_other("/players/mizan/closed/LiquidRoomDM.c", "bleat", "You hear a soft 'bloop' as someone dives into ether-muck.\n"); 
  this_player()->move_player("into the jello#players/mizan/etheriel/ROOMS/spoogle.c");
  if(this_player()->query_level() < 3) {
    if(!present("panicbutton", this_player())) {
    write("A complementary panic button appears in your inventory...\n");
    move_object(clone_object("players/mizan/etheriel/items/panic-btn2"), this_player());
    }
  }
  return 1;
}

short_entry() {
  call_other("/players/mizan/closed/LiquidRoomDM.c", "bleat", "You hear a soft 'bloop' as someone dives into ether-muck.\n");
  this_player()->move_player("into the jello#players/mizan/etheriel/ROOMS/spoogle.c");
  return 1;
}

