inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("tail");
   set_short("A tail");
   set_long("A long gray tail with a tuft of fluff at one end and a pin stuck in the other.\n");
   set_value(150);
   set_weight(1);
}
