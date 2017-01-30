reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="statue"||str=="grey statue") return 1;
        return 0;
}

long() {
        write( "A statue made of grey marble on witch chiseled on the shape of an orc.\n");
}

short()
  { return "A grey statue"; }


get() {
        return 0;
}
drop() {
        return 0;
}
