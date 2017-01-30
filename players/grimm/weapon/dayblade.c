inherit "obj/weapon";
object owner;

reset(arg) {
  if (arg) return;
        set_name("dayblade");
        set_alt_name("blade");
        set_short("DayBlade");
        set_long("This is a very unique weapon, it has an aura of good around it.\n");
        set_class(14);
        set_weight(6);
        set_value(9000);
}

query_save_flag() { return 0; }

query_auto_load() { return "/blah"; }
