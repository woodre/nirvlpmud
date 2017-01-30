inherit "obj/treasure";


reset(arg){
set_short("........");
set_weight(1);
set_long(
   "Not that long, not that large, maybe just a plain 7 inches tool\n"+
   "useful to give pleasure to friends and lovers.  It can be softly\n"+
   "manipulated and in such a case it might harden.  Also, for safety\n"+
   "purposes, it can be covered by a thin fabric or a plastic.  A man\n"+
   "can use it with a woman only when she okayed him.  Otherwise,\n"+
   "the Police can be called.\n");
  }


init(){
  ::init();
  
  }


id(str) {return str=="hammer";}