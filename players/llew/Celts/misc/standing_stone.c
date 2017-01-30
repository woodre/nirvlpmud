inherit "obj/treasure";

reset(arg) {
   if(arg) return;
      set_short("A large standing stone");
   set_id("stone");
   set_value(0);
   set_weight(30);
   set_long("A large standing stone about three feet high with some\n"+
      "archaic symbols written across the top.\n"+
      "An arrow points to the west.\n");
}

init() {
   ::init();
   add_action("read","read");
}

read() {
   write("West lies the sacred cairne wherein the druid\n"+
      "resides in peace.  Kill him if you think you are smart,\n"+
      "if you think you are powerful.  Be warned: the druid\n"+
      "doesn't take kindly to being attacked.  He will do\n"+
      "everything in his power to not only survive, but to\n"+
      "repay his attackers.  And he has a lot of power to spend...\n\n"+
      "Those few to have defeated the protector:\n\n");
   tail("players/llew/closed/logs/druid_death");
   write("\n");
   return 1;
}
