inherit "obj/armor";
reset(arg){
   ::reset(arg);
    set_short("A Fishing Hat");
   set_arm_light(0);
set_long(
  "Henry Blake's fishing hat, looks fun to wear.\n");
   set_ac(2);
   set_weight(2);
   set_value(600);
   set_alias("hat");
   set_name("hat");
   set_type("helmet");
}

/* Added by Snow, 11/99 */
do_special(owner) {
  if(creator(environment(owner)) != "hawkeye") {
    if(!random(100)) tell_object(owner,"You feel silly wearing a fishing hat for protection outside of MASH.\n");
    return -random(2)-1; }
  return 0; }
