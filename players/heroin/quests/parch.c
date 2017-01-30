inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("Parchment : A poem- A letter ???");
set_alias("paper");
set_long("Before putting this together, you could of swore that it was\n"+
"a letter.  However, now it a appears to be a poem?? Or maybe both??\n"+
"I wonder who it belongs to?? Khan sure seemed concerned.  Maybe you\n"+
"should show someone much older and wiser than you?\n");
   set_weight(1);
    set_value(5000);
set_save_flag(1);
}
 id(str) { return str == "parchment" || str == "paper" || str == "letter"; }
   
