inherit "obj/armor";
reset(arg){
set_ac(1);
set_value(500);
set_weight(1);
set_name("boots");
set_short("Black Leather Boots");
set_alias("leather boots");
set_long("These leather hip boots once belonged to Storm, sometimes called the goddess\n"+
         "of weather.  They may provide some protection from the weather.\n");
set_type("boots");
 /* added by Ill 5 May 05 - Storm's boots protect against electric damage */
set_params("other|electric",0,10,0);
 /* and cold too, just for the halibut */
set_params("other|ice",0,10,0);
}
