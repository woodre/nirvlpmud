inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("The cloak of Malachi");
    set_short("The cloak of Malachi");
   set_alias("cloak");
   set_ac(1);
   set_weight(2);
   set_value(600);
   set_type("misc");
set_long("This is the cloak of Malachi. It is black and very long.\n");
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
