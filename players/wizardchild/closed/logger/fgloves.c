/* fgloves.c: flannel gloves */
inherit "obj/armor";
string owner;
set_owner(str) { owner = lower_case(str); }
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("gloves");
  set_alias("flannel gloves");
  set_short("A Logger's pair of gloves");
  set_long("A rough cut pair of gloves, hardly sufficient protection from the elements.\n"
          +"They will, however, protect a Logger's hands. It appears that only the\n"
          +"person who made these could wear them.\n");
  set_type("misc");
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
    write("You try and try, but are unable to wear these gloves.\n");
  else
    ::wear(str);
  return 1;
}
