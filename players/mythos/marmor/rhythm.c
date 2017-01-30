inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("rhythm");
  set_short("Rhythm");
  set_type("armor");
  set_long("This is an aural form of rhythm.  You feel\n"+
           "the beat of the music swirl around you as you\n"+
           "touch this....\n");
  set_ac(5);
  set_weight(2);
  set_value(1000);
}

