inherit "obj/armor";

string desc;
reset(arg) {
        if (arg) return;
        set_name("custom gloves");
        set_short("custom gloves");
        set_alias("gloves");
        set_ac(1);
        set_weight(1);
        set_value(0);
        set_type("glove");
        set_long("Custom gloves made for "+this_player()->query_name()+".\n");
        desc="gloves";
}
init() {
   add_action("name","namegloves");
}
name(short) {
   if(!short) return 1;
   desc = short;
   set_short(short);
   set_long("Some custom gloves made for "+this_player()->query_name()+".\n");
return 1; }
wear(arg) {                                                            
    int x;                                                                    
    x = worn;                                                                
    if (!::wear(arg))    
        return 0;                    
    if (worn && !x) {                           
        write("You wear the "+desc+".\n");
    }
    return 1;
}

remove(str) {     
    if (!id(str))                                              
    return 0;                                                         
    if (!worn) {                                                       
        return 0;                                                     
    }                                                                         
   write("You remove "+desc+".\n");
   say(this_player()->query_name()+" removes  "+desc+".\n");
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;                                                     
    worn = 0;                            
    return 1;                                
}
