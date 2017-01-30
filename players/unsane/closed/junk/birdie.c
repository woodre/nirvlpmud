inherit "/obj/treasure";
int second;
init(){
second = 50;
set_heart_beat(1);
add_action("yes","Yes");
add_action("yes","yes");
add_action("no","No");
add_action("no","no");
}
heart_beat() {
object ob;
second -= 1;
if (second > 0)
{return;}
set_heart_beat(0);
ob=environment();
if(call_other(ob,"query_level")) {
destruct(this_object());
}
}
yes() {
write("You accept the stupid plastic microphone.\n");
move_object(clone_object("players/unsane/closed/junk/wmike"),this_player());
destruct(this_object());
return 1; }
no() {
write("You never were very cool.\nDon't even deserve a mike.\n");
destruct(this_object());
return 1; }
