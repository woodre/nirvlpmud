inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_short("A pile of dust");
   set_weight(1);
   set_value(1);
   set_id("dust");
}
