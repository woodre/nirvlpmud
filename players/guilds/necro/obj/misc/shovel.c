inherit "obj/treasure";

reset(arg){
    if(arg) return;
    set_id("shovel");
    set_alias("large shovel");
    set_short("A large shovel");
    set_long("A large shovel made out of metal with a small wooden handle.  The wood is\n"+
      "painted painted red while the metal is black.  Small patches of rust and\n"+
      "dirt has collected upon it.\n");
    set_weight(2);
    set_value(100);
}
