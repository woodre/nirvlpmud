#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  set_id("sign");
  set_short("A Sign Concerning Heroin's castle.  <read sign>");
  set_long("You may wish to read the sign.\n");
  set_weight(100000);
  set_value(0);
}
init() {
  ::init();
  add_action("read","read");
}

read(str) {
 if(str && str == "sign") {
   write("Heroin's Castle has been temporarily closed\n"+
         "for repairs.  There is a memory leak that must be\n"+
         "addressed.  Will re-open soon.\n\n"+
         "                                 - The Management\n");
   return 1;}
}

