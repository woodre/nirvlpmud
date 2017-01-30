inherit "obj/armor";

reset(arg){
  ::reset(arg);
                  
  set_name("dark armor");
  set_short("A blackened suit of full plate");
  set_alias("plate");
  set_long("The formor suit of plate mail from a high clerist knight, this\n"+
           "armor has been corrupted by the blackened influence of the\n"+
           "death knight. A large black cross is emblazened across the\n"+
           "breastplate of the suit.\n");
  set_type("armor");
  set_ac(4);
  set_weight(3);
  set_value(7700);
}

