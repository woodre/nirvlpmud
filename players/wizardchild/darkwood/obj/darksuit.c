/* darksuit.c: suit of darkness */
inherit "obj/armor";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("suit");
  set_alias("suit of darkness");
  set_short("A suit of darkness");
  set_long("In addition to the darkness from the trees, this suit probably helped the\n"
          +"shadow to remain invisible. Unfortunately for you, however, he didn't leave\n"
          +"an instruction set on how to use it.\n");
  set_ac(3);
  set_type("armor");
  set_weight(6);
  set_value(3000+random(600));
}
id(str) { return str == "suit" || str == "suit of darkness"; }
