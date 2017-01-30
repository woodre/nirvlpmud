
inherit "obj/weapon";

reset(arg) {
     ::reset(arg);
     if(!arg)
  return;
      set_name("longsword");
     set_alias("sword");
     set_weight(2);
     set_class(12);
     set_value(400);
}

