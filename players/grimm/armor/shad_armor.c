inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("Shadow Armor");
   set_short("Shadow Armor");
   set_type("armor");
   set_alias("armor");
   set_ac(4);
   set_weight(3);
   set_value(4598);
   set_long("This is the body armor of shadows.\n");
}
wear(arg) {                                                            
    int x;                                                                    
    x = worn;                                                                
    if (!::wear(arg))    
        return 0;                    
    if (worn && !x) {                           
        write("As you wear the armor you feel a darkness surround you.\n");
    }
    return 1;
}

remove(str) {     
    if (!id(str))                                              
    return 0;                                                         
    if (!worn) {                                                       
        return 0;                                                     
    }                                                                         
   write("As you remove the armor you feel the light begin to surround you again.\n");
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;                                                     
    worn = 0;                            
    return 1;                                
}
