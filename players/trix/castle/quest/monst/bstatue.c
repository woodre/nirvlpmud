reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="statue"||str=="black statue") return 1;
        return 0;
}

long() {
        write( "A statue made of black marble on witch chiseled on the shape of an orc.\n");
}

short()
  { return "A black statue"; }


get() {
        return 0;
}
drop() {
        return 0;
}
