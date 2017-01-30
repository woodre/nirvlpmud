inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("sample");
  set_alias("sample");
  set_alt_name("tissue");
  set_weight(1);
  set_value(150);
  set_strength(20);
set_short("Tissue sample");
set_long("The tissue sample of an unknown creature. Looks edible tho.\n");
set_eater_mess("You grimace as you down the tissue sample. Its a\n"+
               "little tough to chew but you can handle it.\n");
set_eating_mess(" grimaces as they chow down on a tissue sample.\n");
}

