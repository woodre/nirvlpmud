inherit "obj/monster";
   reset(arg) {
/*

*/
     ::reset(arg);
        set_name("trixie");
        set_wc(3);
        set_ac(10);
        set_level(3);
        set_alias("mytoy");


/*
  You redifine the various functions in the same format as this not using call_other just set_?() or load_?() put the
 same stats as trixie in this definitions for any functions to defined such as notify
  You would define them after the reset format.
   Haji
 .

}
