reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="trixpendant"||str=="pendant") return 1;
        return 0;
}

long() {
        write( "An electrum pendant symbol of an archaic cult, you can see the picture of a\n"+
               "powerful and evil God engraved on it.\n");
}

short()
  { return "An electrum pendant"; }

get() {
        return 1;
}
drop() {
        return 0;
}
