inherit "obj/armor";  

reset(arg)  
{  
::reset(arg) ;  
set_short("Predator skull");  
set_long("The skull of the predator champion fits nicely over your head\n"+
"Not only does cover you head but it provides great facial protection.\n"+
"Besides this: What better way to Honor your slain enemy, then to wear\n"+
"him as a trophy.  Also, you are now one intimidating looking MOFO\n");
set_ac(1);  
set_weight(1);  
/* Changed value from 5,000 to 800. Weak monsters and small items. -Snow */
set_value(800);  
set_alias("skull");
set_name("Biomechanical helmet");  
set_type("helmet");  
}  
  
query_save_flag() { return 0; }  



