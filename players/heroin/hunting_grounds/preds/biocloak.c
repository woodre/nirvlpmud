inherit "obj/armor";  

reset(arg)  
{  
::reset(arg) ;  
set_short("Predator dreds");  
set_long("This is the dreds of the Predator.  If the predator was human\n"+
"you might consider it his hair...Closer examination reveals that the \n"+
"mane is fortified with bits of scaley-metal...Also It would be perfect \n"+
"length to cover your back...I guess you could wear his dreds as a cape.\n");
set_ac(1);  
set_weight(1);  
/* Changed value from 3000 to 800. - Snow */
set_value(800);  
set_alias("dreds");
set_name("dreds");
set_type("misc");  
}  
  
query_save_flag() { return 0; }  



