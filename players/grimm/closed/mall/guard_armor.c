inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("A mall guard's armor");
   set_short("A mall guard's armor");
   set_alias("armor");
   set_ac(4);
   set_weight(3);
   set_value(2125);
   set_type("armor");
   set_long("This is the body armor of a mall guardsman.\n");
}
wear(arg) {                                                            
    int x;                                                                    
    x = worn;                                                                
    if (!::wear(arg))    
        return 0;                    
    if (worn && !x) {                           
    }
    return 1;
}

remove(str) {     
    if (!id(str))                                              
    return 0;                                                         
    if (!worn) {                                                       
        return 0;                                                     
    }                                                                         
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;                                                     
    worn = 0;                            
    return 1;                                
}
