inherit "obj/armor";
init() {
  add_action("disintigrate","disintigrate");
  ::init(); }
reset(arg) {
   if (arg) return;
   set_name("Ring of Disintigration");
   set_short("Ring of Disintigration");
   set_alias("ring");
   set_ac(1);
   set_weight(2);
   set_value(500);
   set_type("ring");
   set_long("A finely engraved ring.  There is a note on the side that says\n"
+"DISINTIGRATE <Target>.\n");
}
wear(arg) {                                                            
    int x;                                                                    
    x = worn;                                                                
    if (!::wear(arg))    
        return 0;                    
    if (worn && !x) {                           
    write("You feel power glide through your body as you wear the ring.\n");
    }
    return 1;
}

remove(str) {     
    if (!id(str))                                              
    return 0;                                                         
    if (!worn) {                                                       
        return 0;                                                     
    }                                                                         
   write("A surge of power leaves your body as you remove the ring.\n");
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;                                                     
    worn = 0;                            
    return 1;                                
}
disintigrate(str) {
  write("As you use the ring's power it explodes in your hand,\n"
+"disintigrating.\n");
  say(this_player()->query_name()+"'s ring explodes.\n");
  this_player()->add_hit_point(-10);
  destruct(this_object());
  return 1;
}
