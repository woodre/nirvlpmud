inherit "obj/treasure.c";
  reset(arg) {
    ::reset(arg);
      if(arg)
         return;
      set_name("torpedo shield");
      set_alias("ttoy");
      set_short("Torpedo Shield");
      set_long("Photon Torpedo Shield.\n");
      set_value(2750);
      set_weight(4);
  }
