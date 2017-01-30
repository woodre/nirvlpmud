inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("shades");
  set_alias("helmet");
  set_short("A Pair of Cool Shades");
  set_long("A really cool looking pair of shades or sunglasses they appear\n" +
           "to be the type that the Terminator or mister hip himself\n" +
           "wears those great peril sensitive shades\n\n");
  set_value (400);
  set_weight(1);
  set_ac(1);
  set_type("helmet");
}
