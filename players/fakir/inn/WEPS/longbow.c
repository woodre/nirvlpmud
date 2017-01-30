inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("longbow");
  set_alias("longbow");
  set_short("A longbow");
  set_long("This longbow is made of layered hardwood bound with leather.\n"+
    "It would take quite an arm to pull it to full draw.\n");
  set_class(15);
  set_weight(1);
  set_value(500);
  
}
