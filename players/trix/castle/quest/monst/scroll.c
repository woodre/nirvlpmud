reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="scroll") return 1;
        return 0;
}

long() {
        write( "A white stone scroll on with it's engraved the scene of a man kneeling in\n"+
               "front of a huge statue\n");
}

short()
  { return "A stone scroll"; }

get() {
        return 1;
}
drop() {
        return 0;
}
