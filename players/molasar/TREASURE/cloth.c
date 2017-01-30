
inherit "obj/treasure";

reset(arg) {
     if(arg) return;
     set_id("cloth");
     set_alias("torn cloth");
     set_short("A piece of torn cloth");
     set_long("A piece of cloth torn from some garment with the words \n"+
              "\nDon't forget to set the blocks........\n"+
              "               up--down--up--up\n");
      set_weight(1);
      set_value(10);
}

