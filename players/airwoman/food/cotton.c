inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("cotton");
  set_alias("cotton");
  set_alt_name("candy");
  set_weight(1);
  set_value(25);
  set_strength(10);
  set_short("Cotton Candy");
  set_long("Some pink fluffy cotton candy that melts in your mouth "+
            "and your hand!\n\n");
  set_eater_mess("You put some cotton in your mouth....mmmm....\n");
 
 
  set_eating_mess(" eats some fluffy cotton candy.\n");
}      
  
