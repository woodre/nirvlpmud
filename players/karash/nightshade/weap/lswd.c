inherit "obj/weapon";
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(14);
                set_value(500);
                set_weight(3);
                set_alias("sword");
                set_short("Longsword");
   set_long("An ordinary longsword that has a blue glow coming"+
" from the blade\n");
}
}
