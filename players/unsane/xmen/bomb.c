inherit "obj/treasure";
reset(arg){
if(arg) return;
set_id("bomb");
set_short("A Bomb");
set_long("It's a good thing that Sabertooth hadn't set the timing device on this\n"+
"thing.  It is now defused.\n");
set_value(500);
set_weight(1);
}
