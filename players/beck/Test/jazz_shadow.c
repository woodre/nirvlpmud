
id(str) {return str=="sharkstooth" || str=="tooth"; }
reset () {}
short() {
return "A Sharks Tooth";
}
long() {
write("This is a fossil of the tooth of a Great White Shark.\n");
return 1;
}
query_value() { return 100; }
get() {
return 1;
}
query_weight() { return 1; }
init(){
if(this_player()->query_real_name() == "becktest" || this_player()->query_real_name() == "snowtest"){
add_action("start","start");
add_action("stop","stop");
add_action("quit","quit");
}
}
object ob;
start(){
ob = clone_object("/players/beck/Lib/Shadow.c");
ob->start_shadow(this_player());
return 1;
}
stop(){
ob->stop_shadow();
return 1;
}
quit(){
ob->stop_shadow();
return;
}
