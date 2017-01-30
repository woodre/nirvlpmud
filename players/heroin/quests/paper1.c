inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("The top half");
set_alias("paper");
set_long("This appears to be a piece of a longer piece of parchment.\n"+
"The lettering is strange and appears to be gibberish.  By the \n"+ 
"placement of letters this appears to be a letter?!?!\n");
   set_weight(0);
    set_value(1000);
set_save_flag(1);
}
id(str) {return str == "one" || str == "top" || str == "one";}
     
