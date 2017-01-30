inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
    set_short("Woodstock '94 T-Shirt (worn)");
    set_alias("shirt");
    set_alias("t-shirt");
    set_long("This is the official Woodstock '94 T-Shirt!\n"+
             "Wear it with pride!\n");
 
    set_weight(0);
    set_value(0);
}
    id(str) { return str == "shirt" || str == "t-shirt"; }
    
