inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("The spiked collar of a pit bull");
   set_short("The spiked collar of a pit bull");
   set_alias("collar");
   set_ac(1);
   set_weight(1);
   set_value(525);
   set_type("amulet");
   set_long("This is the spiked collar of a pit bull.\n");
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
