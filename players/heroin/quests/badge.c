inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
set_short("A badge");
set_alias("badge");
set_long("A badge: AGENT OF THE ELDERS <*CLOUT*>\n");
   set_weight(1);
    set_value(100);
set_save_flag(1);
}
 id(str) { return str == "badge" || str == "badge"; }
get(){return 1;}
drop() {return 1;}
