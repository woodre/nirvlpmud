/* fhat.c: flannel hat */
inherit "obj/armor";
string owner;
set_owner(str) { owner = lower_case(str); }
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("hat");
  set_alias("flannel hat");
  set_short("A Logger's flannel hat");
  set_long("This hat was evidentally cut by a maniac. Unfortunately, it does not come\n"
          +"with any sort of instruction set, so only the person who created it would\n"
          +"be able to wear it.\n");
  set_type("helmet");
  set_ac(1);
  set_value(1);
  set_weight(2);
  set_save_flag();
}
init() { 
  add_action("wear", "wear");
  ::init();
}
wear(str) {
  if(!id(str)) return 0;
  if(this_player()->query_real_name() != owner) 
    write("You try and try, but are unable to wear this hat.\n");
  else
    ::wear(str);
  return 1;
}
