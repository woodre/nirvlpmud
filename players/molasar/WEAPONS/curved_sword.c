
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
  if(!arg) return;
     set_name("sword");
     set_alias("curved sword");
     set_short("A curved sword");
     set_long("A wicked looking curved sword.\n");
     set_value(125);
     set_class(10);
     set_weight(2);
}

