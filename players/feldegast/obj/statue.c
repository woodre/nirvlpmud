inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_short("A statue of a falcon");
  set_long(
"This delicate statue is made from the finest silver and molded\n"+
"into the form of a falcon in flight.\n"
  );
  set_weight(2);
  set_id("statue");
  set_value(800);
}
