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

void init() { add_action("cmd_weight","weight"); }

status
cmd_weight(string str) {
   int coinage;
  object who;

  who = find_player(str);
  if(!who) {
    write("Not found.\n");
  }
  who->recalc_carry();
  write("OK, done.\n");
  return 1;
}
