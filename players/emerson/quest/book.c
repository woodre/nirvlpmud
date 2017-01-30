inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Black Book");
    set_alias("book");
    set_long("This book contain the names of the Godfather's\n"+
    "Political Connections.\n");
   set_weight(2);
    set_value(1000);
}

