inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("onion");
  set_alias("onion");
  set_weight(1);
  set_value(25);
  set_strength(5);
  set_short("A magical onion");
  set_long("A magical onion which can make\n"+
  "heaven cry.\n");
  set_eating_mess(" indulges in an onion?\n");
}
          
