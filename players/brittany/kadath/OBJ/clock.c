inherit "obj/treasure";

reset(arg) {
  set_id("clock");
   set_short("A coffin-shaped clock");
  set_long(
"A coffin-shaped clock, that ticked curiously, it bore a dial\n"+
"with hieroglypics on it.");
  set_weight(1000);
  set_value(0);
}


get() { return 0; }  
