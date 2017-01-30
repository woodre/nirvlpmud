inherit "obj/treasure";
int inout;

reset(arg) {
  if(arg) return;
  set_id("ptest");
    set_alias("ptest");
    set_weight(0);
    set_value(0);
set_short("ptest");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
 
}
init(){

   add_action("setter", "setter");
   
}

revive_kid() {

    if(inout) {
	write("it says 1\n");
	return 1;
	}
	else {
	write("it says 0\n");
	return 1;
	}
}

setter() {

  if(inout) {
    write("You deactivate the shields.\n");
    inout=0;
    return 1;
  }
  else {
    write("You activate the shields.\n");
    inout=1;
    return 1;
  }
}
query_inout() { return inout; }