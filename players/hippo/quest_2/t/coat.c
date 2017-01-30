reset(arg) {
        if(arg) return;
}

id( str ) {
   if (str=="jelly coat") return 1;
        return 0;
}

long() {
   write("This is a jelly coat, which protects the completed female\n"+
      "eggs from intruders. Only a complete spermatocyte can pass\n"+
      "this barrier.\n");
}

short()
   { return "A Jelly Coat"; }

get() {
        return 1;
}
drop() {
        return 0;
}
