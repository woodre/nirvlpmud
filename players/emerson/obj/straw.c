inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Straw");
    set_alias("straw");
    set_long("This straw looks like it's got some pizza stuck in it.\n");
   set_weight(2);
    set_value(1000);
}

