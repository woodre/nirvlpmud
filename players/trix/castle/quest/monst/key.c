reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="trixkey"||str=="key") return 1;
        return 0;
}

long() {
        write( "An old key made of bone, maybe it can be used to open...\n");
}

short()
  { return "A bone key"; }

get() {
        return 1;
}
drop() {
        return 0;
}
