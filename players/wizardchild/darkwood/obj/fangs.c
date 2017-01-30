/* fangs.c: snake fangs */
inherit "obj/weapon";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("fangs");
  set_alias("snake fangs");
  set_short("A pair of snake fangs");
  set_long("A small pair of pure white fangs, obviously from a snake. Despite their sharp\n"
          +"ends, they probably could not do much damage due to their size.\n");
  set_class(10);
  set_weight(1);
  set_value(945);
}
id(str) { return str == "fangs" || str == "snake fangs"; }
