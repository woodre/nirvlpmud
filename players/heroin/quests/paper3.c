inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("The bottom section");
set_alias("paper");
set_long("This appears to be a piece of a longer piece of parchment.\n"+
"The lettering is strange and appears to be gibberish. You are sure \n"+ 
"it is part of letter..except the signiture seems to be symbols of the\n"+
"zodiac?\n");
   set_weight(0);
    set_value(1000);
set_save_flag(1);
}
id(str) {return str == "third" || str == "bottom" || str == "three";}
 
