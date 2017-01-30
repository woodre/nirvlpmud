reset(arg) {
        if(arg) return;
}

id( str ) {
   if(str=="chromosomes"||str=="female chromosomes") return 1;
        return 0;
}

long() {
   write("These are 22 of the 23 female chromosomes. There is one\n"+
      "special chromosome missing: the one which defines these\n"+
      "chromosomes as female ones. If you don't get it, read the\n"+
      "anatomic guide. If the chromosomes are complete, you could\n"+
      "probably try to make a real functional egg?\n");
}

short()
   { return "female chromosomes";}

get() {
        return 1;
}
drop() {
        return 0;
}
