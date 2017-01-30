inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("hood");
  set_short("A chainmail hood");
  set_long(
     " A sleek, lightweight hood made by the Durkor of Sivart.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(750);
}
