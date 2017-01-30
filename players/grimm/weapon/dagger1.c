inherit "obj/weapon";

reset(arg) {
  if (arg) return;
        set_name("vampire dagger");
        set_alt_name("dagger");
        set_short("Vampire Dagger");
        set_long("A dagger with a handle made from the bones from human\n"+
                 "mortals.  It has an eight inch blade on it.");
        set_class(6);
        set_weight(3);
        set_value(300);
}
