inherit "obj/treasure";

reset(arg) {

  if(arg) return;
  set_id("tester");
    set_alias("tester");
    set_weight(0);
    set_value(0);

set_short("tester");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
    }

init(){
   add_action("revive_kids", "fd");
   
}
/* prototype */
void query_foo();

revive_kids() {
  int i;
  object obj;
  string str;
  obj = "/players/data/closed/test/room_obj.c";
  /*
  if("query_foo") {
  */
  if(query_foo()) {
    write("it says 1.\n");
    return 1;
  } else {
    write("it says 0.\n");
  return 1;
  }
}
query_foo() 
{ 
  return call_other("/players/data/closed/test/room_obj.c","query_inout",1); 
}


