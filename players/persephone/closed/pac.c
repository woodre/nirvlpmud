inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("eyepatch");
  set_alias("helmet");
  set_short("Evil Black Eyepatch");
  set_long("An extremely evil looking eyepatch that looks so cool you\n" +
           "simply must get one for yourself\n");
  set_value (6800);
  set_weight(2);
  set_ac(2);
  set_type("helmet");
  set_save_flag(0);
}
