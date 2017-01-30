inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("A Bloody Tongue");
set_alias("Tounge");
set_long("This is the cut-off tongue of Adolf Hitler\n"+
"The flesh is still warm even though you cut it off hours ago?\n");
   set_weight(0);
    set_value(5000);
set_save_flag(1);
}
 id(str) { return str == "tongue" || str == "tonge"; }
   
