inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("Carpathian Armor");
   set_short("Carpathian Armor");
   set_alias("armor");
   set_type("armor");
   set_ac(4);
   set_weight(3);
   set_value(4578);
   set_long("This is body armor of the Ancient Carpathians!\n");
}
wear(arg) {                                                            
    int x;                                                                    
    x = worn;                                                                
    if (!::wear(arg))    
        return 0;                    
    if (worn && !x) {                           
        write("As you wear the armor you feel very evil.\n");
    }
    return 1;
}

remove(str) {     
    if (!id(str))                                              
    return 0;                                                         
    if (!worn) {                                                       
        return 0;                                                     
    }                                                                         
   write("As you remove the armor you feel less evil.\n");
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;                                                     
    worn = 0;                            
    return 1;                                
}
