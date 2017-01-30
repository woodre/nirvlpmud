/*
* This is a curse that the player can't get rid of.
* It prevents you from shouting.
*/

int start_time;

query_auto_load() {
   return "obj/shout_curse:" + start_time;
}

start(ob) {
   move_object(this_object(), ob);
   start_time = time();
   tell_object(ob, "You get a sore throat suddenly, without any reason.\n");
}

id(str) {
   return str == "shout_curse";
}

long() {
   write("How can you look at a curse ?\n");
}

drop() { return 1; }

init() {
   add_action("do_shout"); add_verb("shout");
   add_action("do_tell"); add_verb("tell");
    add_action("do_gossip"); add_verb("gossip");
    add_action("do_equip");  add_verb("equip");
    add_action("do_risque");  add_verb("risque");
    add_action("do_wiz");  add_verb("wiz");
    add_action("do_announce");  add_verb("announce");
    add_action("do_te");  add_verb("te");
    add_action("do_att");  add_verb("att");
    add_action("do_gemote");  add_verb("gemote");
    add_action("do_gtell");  add_verb("gtell");
    add_action("do_register");  add_verb("register");
    add_action("do_comm");  add_verb("comm");
    add_action("do_scan");  add_verb("scan");
    add_action("do_beam");  add_verb("beam");
    add_action("do_mode");  add_verb("mode");
    add_action("do_emote");  add_verb("emote");
    add_action("do_em");  add_verb("em");
}

do_shout() {
   if (time() < start_time + 1000) {
      write("You can't shout with a sore throat !\n");
      say(call_other(this_player(), "query_name") +
         " makes croaking sounds.\n");
      return 1;
   } else {
      destruct(this_object());
      return 0;
   }
}
do_tell(){
   if(time() < start_time + 1000){
      write("You can't tell with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}

do_gossip(){
   if(time() < start_time + 1000){
      write("You can't gossip with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_equip(){
   if(time() < start_time + 1000){
      write("You can't equip with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_risque(){
   if(time() < start_time + 1000){
      write("You can't risque with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_wiz(){
   if(time() < start_time + 1000){
      write("You can't wiz with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_announce(){
   if(time() < start_time + 1000){
      write("You can't announce with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_te(){
   if(time() < start_time + 1000){
      write("You can't te with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_att(){
   if(time() < start_time + 1000){
      write("You can't att with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_gemote(){
   if(time() < start_time + 1000){
      write("You can't gemote with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_gtell(){
   if(time() < start_time + 1000){
      write("You can't gtell with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_register(){
   if(time() < start_time + 1000){
      write("You can't register with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_comm(){
   if(time() < start_time + 1000){
      write("You can't comm with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_scan(){
   if(time() < start_time + 1000){
      write("You can't scan with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_beam(){
   if(time() < start_time + 1000){
      write("You can't beam with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_mode(){
   if(time() < start_time + 1000){
      write("You can't mode with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_emote(){
   if(time() < start_time + 1000){
      write("You can't emote with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
do_em(){
   if(time() < start_time + 1000){
      write("You can't em with a sore throat!!\n");
      say(call_other(this_player(),"query_name")+
         " makes croaking sounds.\n");
      return 1;
   }
   else {
      destruct(this_object());
      return 0;
   }
}
init_arg(str) {
   sscanf(str, "%d", start_time);
}

short() {
   return "A sore throat";
}
