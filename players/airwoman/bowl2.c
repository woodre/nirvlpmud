inherit "obj/treasure";
 
reset(arg) {
        if (arg) return 1;
        set_id("bowl2");
        set_alias("bowl");
        set_weight(2);
        set_short("A bowl full of heavenly tears");
        set_long("The bowl is now holding the tears from heaven.\n"+
        "Be careful!  U dont want to spill it.\n");
 
}
