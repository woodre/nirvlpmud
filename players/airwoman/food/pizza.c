inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("pizza");
  set_weight(1);
  set_value(25);
  set_strength(10);
  set_short("A Pizza");
  set_long("A sushi pizza which includes live anchovies...\n");
  set_eater_mess("You take a bite of the pizza....\n"+
                "You feel the little fishy squirming around your\n"+
        " throat.  YUM YUM.  You eat the whole thing.\n");
 
 
  set_eating_mess(" eats a toxic pizza.\n");
}      
