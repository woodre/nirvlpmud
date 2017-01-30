reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="amulet"||str=="trixamulet") return 1;
        return 0;
}

long() {
        write("An octagonal brass amulet with the mark of some ancient forgotten nation.\n");
}

short()
  { return "A brass amulet";}

get() {
        return 1;
}
drop() {
        return 0;
}
