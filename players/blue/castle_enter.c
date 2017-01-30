#define DEST "room/plane2"


id(str) { return str == "castle"; }

short() {
   return "The Castle of Mael";
}

long() {

   write("A once beautiful castle now lies in complete ruins...\n");
   write("Something draws you into it\n");
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
