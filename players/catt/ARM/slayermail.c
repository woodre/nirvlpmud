inherit "obj/armor";
  reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("slayer splintmail");
    set_alias("splintmail");
    set_short("Slayer splintmail");
    set_long("This is the splintmail of a Black Slayer Captain. It is\n"+
             "black in color with silver riveting. Use it well.\n");
    set_value(1500);
    set_weight(5);
    set_ac(3);
    set_type("armor");
}
