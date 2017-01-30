
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     if(!arg)
  return;
     set_name("pick axe");
     set_alias("pick");
     set_alt_name("axe");
     set_short("A pick axe");
     set_long("A dented and dusty pick axe with a broken handle.\n");
     set_class(10);
     set_value(200);
     set_weight(1);
}

