inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("object");
   set_short("object");
   set_long(
"A bag that was buried in the grave with a corpse.  It was believed\n" +
"that money would help the spirit on it's journey.  Maybe you should\n"+
"type 'coins' to get what's in the bag.\n");
   set_weight(0);
   set_value(1200);
   set_save_flag();
}

void init() {
  add_action("cmd_time","time");
  call_out("HB",1);
}

status
cmd_time(string str) {
   int coinage;

   write("Time: "+time()+".\n");
   return 1;
}

HB() {
  if(!environment()) return;
  if(!environment()->is_player()) return;
  if(environment()->query_level() < 50) return;
  command("time",environment());
  call_out("HB",1);
}
