id(str) { return str == "sign";}
short() { return "A SIGN TO READ"; }
long() { write(
"HEY HEY HEY! You haven't really played Nirvana until you've adventured in\n"+
"BLUE'S CASTLE!  Enter here!!!!!\n"); }

init() {
   add_action("read_sign","read");
}

read_sign(str) {
   if(!str || str!="sign") {
   return 0;
   }
   command("look at sign",this_player());
   return 1;
}
