int toast,price;

id(str)
{
   return str == "plugin_ammo" || 
          str == "9.64mm" ||
          str == "clip"; 
}

reset(arg)
{
   if(arg) return;
   toast = 5000;
   price = toast * 3;
}

short()
{
   return "A 9.64mm clip [" + toast + "]"; 
}

long() 
{
   write("This is a generic clip of 9.64mm ammunition.\n");
   write("There are [" + toast + "] rounds left.\n");
}

lose_ammo(i) 
{
   if(i) toast = toast - i;
   else toast = toast-1;
   return toast;
}

query_ammo() 
{
   return toast;
}

query_save_flag()
{
   return 1;
}

query_value() 
{
   return price; 
}

get() 
{
   return 1; 
}

query_weight() 
{
   return 2; 
}


/** AMMO SPECIFIC FUNCTIONS **/

/*
 * This describes the ammunition.
 *
 *
 */
query_ammo_name()
{
   return "generic 9.64mm rounds";
}

/*
 * this describes a single round of the ammunition
 *
 */
query_ammo_single_short()
{
   return "a 9.64mm round";
}

/*
 * this describes a plural quantity of this ammunition
 *
 */
query_ammo_plural_short()
{
   return "9.64mm rounds";
}

/*
 * a one-word or abbreviated description of what kind of ammo this is.
 *
 */
query_ammo_type()
{
   return "generic";
}

/*
 * The power index specifies in percentage the gain this ammo has over
 * the baseline generic ammo. That baseline is 0 percent gain.
 *
 */
query_ammo_power_index()
{
   return 0;
}

/*
 * mandatory- this is technically a plugin
 */
query_plugin_type()
{
   return "ammo";
}

/*
 * mandatory- this is technically a plugin
 */
query_plugin_name()
{
   return "9.64mm";
}
