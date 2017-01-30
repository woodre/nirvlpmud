reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="counter") return 1;
        return 0;
}

long() {
        write( "counter\n");
}

short()
  { return "counter"; }
init()
{
  add_action( "count","count");
}
count(){ int a;
    for(a=1;a<=20;a++) write(50+(250*a)/19+"\n");
    return 1;
 }

get() {
        return 1;
}
drop() {
        return 0;
}
