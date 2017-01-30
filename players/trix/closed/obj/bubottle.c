query_auto_load() {     return "/players/trix/closed/obj/bubottle.c:"; }
reset(arg) {
        if(arg) return;
}
id( str ) {
        if(str=="bottle") return 1;
        return 0;
}
long() {
        write( "A small baby blue bottle filled with soapy liquid to blow bubbles.\n");
}
short()
  { return "A bubble bottle"; }
init()
{
  add_action( "blow","blow");
}
blow()
{ write("You pull the ring out of the bottle ang begin to blow bubbles...\n"+
        "       ..oooOOO0000.0...o.o.0.o0.o..o.oO)o.oo.0.o...\n");
  say(this_player()->query_name()+" pulls the ring out of the bottle ang begins to blow bubbles\n"+
      "       ..oooOOO0000.0...o.o.0.o0.o..o.oO)o.oo.0.o...\n");
  return 1;
}
get() {
        return 1;
}
drop() {
        return 1;
}
