id(str) { return str == "sign"; }
short() { return "Delnoch, 3 North"; }
long() {
write("A wooden road sign, pointing north to Delnoch Pass.\n");
  }

init() {
    add_action("read","read");
       }

read(str) {
    if(!str) return 0;
    if(str == "sign") {
    say((this_player()->query_name())+" reads the sign.\n");
    write("A tag on the sign says:\nNirvana public works dept.\n"+
    "Sign #1723462\n");
    return 1;
    }
return 0;
}
