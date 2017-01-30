inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("The piece of paper");
set_alias("paper");
set_long("This appears to be a piece of a longer piece of parchment.\n"+
"The lettering is strange and appears to be gibberish. This really could \n"+ 
"anything, including junk?\n");
   set_weight(0);
    set_value(1000);
set_save_flag(1);
}
id(str) {return str =="mid" || str == "middle"|| str == "two"; }
    
