inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("helmet");          
  set_short("Football Helmet");
  set_long(
  "  A football helmet featuring your favorite teams \n"+
  "logo on the side.  A chin strap dangles off to one \n"+
  "side of the helmet.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
