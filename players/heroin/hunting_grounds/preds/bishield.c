inherit "obj/armor";  

reset(arg)  
{  
::reset(arg) ;  
set_short("Biomechanical shield");  
set_long("This armor is made of an unknown substance.  However, you\n"+  
"are fairly confident that it is semi-organic.  The armor seems to\n"+  
"conform to the body of the owner.  This armor seems to be warn on the.\n"+  
"forearms.. strange why would you need protection here???\n"+
"You adjust the armor and accidently touch a secret button: A Large \n"+
"invisible bio-field encompasses you...This is the Pred's shield!\n");
set_ac(1);  
set_weight(1);  
/* Changed value from 8,000 to 800. Same reason as other changes. -Snow */
set_value(800);  
set_alias("Biomechanical shield");  
set_name("Biomechanical shield");  
set_type("shield");  
}  
  
query_save_flag() { return 0; }  



