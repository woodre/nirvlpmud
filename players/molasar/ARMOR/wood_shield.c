
inherit "obj/armor";

reset(arg) {
     if(!arg)
     ::reset(arg);
      set_name("shield");
     set_alias("wood shield");
     set_short("A wood shield");
     set_long("A medium sized shield made of thick sturdy wood.\n");
     set_ac(1);
     set_type("shield");
     set_weight(2);
}

