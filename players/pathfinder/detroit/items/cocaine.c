inherit "obj/treasure";
 
id(str) { return str == "cocaine" || str == "line"; }
short() { return "Line of Cocaine"; }
long() {
write("You look at the line of cocaine wearily.  You can almost feel the\n"+
"rush of the cocaine through your system by just looking at it.  You just want to \n"+
"'sniff cocaine' to use it.\n");
}
query_value() { return 10000; }
query_weight() { return 1; }
query_save_flag() { return 1; }
reset(arg) {
  if(arg) return;
    
}
 
init() {
  ::init();
  add_action("do_drug","sniff");
 
}
 
do_drug(str){
  object tp;
  tp = this_player();
  if(!str || (str != "cocaine" && str != "line")) {
    write("What are you trying to do?\n");
    return 1;
    }
  if(!tp->drink_alcohol(25)) {
    return 1;
    }
  if(str == "cocaine" || str == "line") {
    tp->heal_self(400);
    write("You bring the line of cocaine up to your nose and sniff.\n");
    write("You feel more invigorated now!\n");
    say(capitalize(tp->query_name())+" brings the line of cocaine to his nose and sniffs.\n");
    destruct(this_object());
    return 1;
    }
}

