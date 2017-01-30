inherit "obj/treasure";
int tim;
int timdi;
int itimdi;
int today;
int day,daysec,secday,tim;

reset(arg) {
   say("Reset!\n");
   if(arg) return;
   set_short("A Stat Razer");
   set_alias("razer");
   set_id("razer");
 set_long("A Stat Razer.  type 'raze' to raise the stat it is \n"+
  "currently set for'\n");
   set_weight(0);
   set_value(0);
}
init() {
   add_action("raze","raze");
}
raze() {
   int piet;
   piet = this_player()->query_strength();
   this_player()->raise_strength(-piet);
   this_player()->raise_strength(100);
   return 1;
}
