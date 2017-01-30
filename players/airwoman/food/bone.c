inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("bone");
  set_alias("bone");
  set_weight(1);
  set_value(25);
  set_strength(10);
  set_short("A bone full of marrow");
  set_long("Thoreau was actually sucking the marrows out of bones\n"+
            "Why dont you try eating the bone...\n\n");
  set_eater_mess("You crunch on the bone...It is full of life...\n");
  set_eating_mess(" eats a bone full of marrow.\n");
}      
