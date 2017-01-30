reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="hook"||str=="trixhook") return 1;
        return 0;
}

long() {
        write("This is a heavy iron hook with the mark of Trixtown, there's a barely readable\n"+
              "sign printed on it.\n");
}

short()
  { return "An iron hook"; }
init()
{ add_action("read","read");
}
read(str)
{ if(str!="sign") return;
  write("The sign printed on the hook says:\n"+
         "\"City of Trixtown-Sewer and Drainage system Department\".\n");
  return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
