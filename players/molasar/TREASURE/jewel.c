
inherit "obj/treasure";

reset(arg) {
     if(arg) return;
     set_id("jewel");
     set_alias("large jewel");
     set_short("A large jewel");
     set_long("A extremely valuable jewel.\n");
      set_weight(1);
      set_value(500);
}

