inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("flagon");
  set_short("A flagon");
  set_long("A tall flagon made out of pewter.  There is a dragon\n"+
           "carved into its side.\n");
  set_value(300);
  set_weight(1);
}
