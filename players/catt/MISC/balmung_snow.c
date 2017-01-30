/* changed by wizardchild 7/23
   this object should not have a heart_beat, moved to call_out
*/
id(str) { return str == "drift"; }
short() { return "snow drift"; }
long() {
 write("This is a drift of snow caused by Balmung, the Artic Blade.\n");
 return 1; }
reset(arg) {
  if(arg) return;
  call_out("dest_me", 150);
           }
dest_me() {
  tell_room(environment(this_object()),"A drift of snow melts.\n");
  destruct(this_object());
}
