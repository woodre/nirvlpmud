inherit "/obj/armor";

void reset(int arg){
    if(arg) return;
    ::reset(arg);
    set_name("robes");
    set_alias("robe");
    set_short("Rump's Robes");
    set_long("Meticulously crafted robes for Rumplemintz's Test Char.\n");
    set_type("armor");
    set_ac(5);
  set_params("other|evil", 2, 90, 0);
    set_value(100);
    set_weight(2);
}
