inherit "obj/treasure";

inherit "/players/data/weather/timedep";
string depspace;

reset(arg) {

  if(arg) return;
  set_id("watch");
    set_alias("watch");
    set_weight(0);
    set_value(0);
    
set_short("a watch");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
    }
	

init(){
  add_action("what_time", "timer");

}

set_timedep4();

what_time() {
int TD_DAY4_WHEN;
string TD_DAY4_WHAT;
write(localtime(),TD_DAY4_WHAT);

return 1;
}

