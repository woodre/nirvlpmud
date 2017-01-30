inherit "obj/treasure";
 
reset(arg) {
        if (arg) return 1;
        set_id("bowl");
        set_alias("bowl");
        set_weight(2);
        set_short("A magical bowl");
        set_long("This magical bowl is used to hold only\n"+
        "the tears from heaven.\n");
 
}
