/* fjacket.c: flannel jacket. */
inherit "obj/armor";
string owner;
set_owner(str) { owner = lower_case(str); }
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("jacket");
  set_alias("flannel jacket");
  set_short("A Logger's flannel jacket");
  set_long("A rugged and well-worn piece of flannel, which has been crudely cut as\n"
          +"armor. By the crudeness of this cut, it appears that only the original\n"
          +"owner could wear it.\n");
  set_type("armor");
  set_ac(2);
  set_value(2);
  set_weight(2);
  set_save_flag();
}
id(str) { return str == "jacket" || str == "flannel jacket"; }
init() { add_action("wear", "wear"); ::init(); }
wear(str) {
  if(!id(str)) return 0;
  if(this_player()->query_real_name() != owner) 
    write("You try to wear the jacket, but you are unable to put it on.\n");
  else 
    ::wear(str);
  return 1;
}
