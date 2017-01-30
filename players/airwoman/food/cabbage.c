inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("cabbage");
  set_alias("cabbage");
  set_weight(1);
  set_value(25);
  set_strength(20);
  set_short("A magical cabbage");
  set_long("A bud of a cabbage patch kid i suppose...\n"+
        "if they do hatch from cabbages...\n"+
        "Anyway eat it.  Cabbages are good for you...\n");
  set_eater_mess("You crunch on some raw cabbage.... CRUNCHHH\n");
  set_eating_mess(" munches on some cabbages.\n");
}

