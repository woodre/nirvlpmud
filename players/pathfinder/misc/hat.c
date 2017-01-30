inherit "obj/treasure";
 
reset(arg) {
 if(arg) return;
   set_short("An Official Pathfinder fan club hat. (worn)");
    set_alias("hat");
    set_long("You have an official Pathfinder fan club hat!\n"+
             "wear it with pride!\n");
 
    set_weight(0);
    set_value(0);
}
    id(str) { return str == "hat"; }
    
