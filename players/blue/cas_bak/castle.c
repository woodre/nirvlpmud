#define DEST "room/plane2"


id(str) { return str == "castle"; }

short() {
   return "The Castle of Mael";
}

long() {

   write("A once beautiful castle now lies in complete ruins...\n");
   write("Something draws you into it\n");
}

init() {
  add_action("Enter","enter");
}

Enter(str) {
if(str == "castle") {
  this_player()->move_player("castle#players/blue/castle/entrance.c");
  return 1; }
}

get() { return 0; }
drop() { return 1; }
value() { return 0; }
weight() { return 100000; }

reset(arg) {
   object pool;
    if (arg)
        return;
   
   move_object(this_object(), DEST);

}

is_castle(){return 1;}
