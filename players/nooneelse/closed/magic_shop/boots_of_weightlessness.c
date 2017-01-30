/*
  boots_of_weightlessness.c
*/

inherit "obj/armor";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("boots");
  set_ac(1);
  set_weight(1); /* was originally -15... i have made it 1 - mythos <2-7-96> */
  set_value(2000);
  set_short("Extremely light boots");
  set_long("A pair of extremely light leather boots.\n"+
           "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
  set_type("boots");
}

query_save_flag() { return 1; }
