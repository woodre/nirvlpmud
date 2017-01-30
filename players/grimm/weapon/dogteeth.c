inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;
        set_name("teeth");
set_short("Vampire teeth");
set_long("A set of very sharp vapire teeth.\n");
        set_class(4);
        set_weight(1);
        set_value(100+random(30));
}
