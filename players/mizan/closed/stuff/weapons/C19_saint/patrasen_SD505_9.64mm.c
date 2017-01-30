int toast,price;

id(str)
{
   return str == "GPSD_standard" || 
          str == "9.64mm" ||
          str == "clip"; 
}

reset(arg)
{
   if(arg) return;
   toast = 35;
   price = toast * 3;
}

short()
{
   return "A 9.64mm clip (Patrasen SD505 APDS armor piercing) [" + toast + "]"; 
}

long() 
{
   write("This is a clip of Patrasen Industries [tm] 9.64mm armor piercing ammunition.\n" +
      "Famous for its red-tipped shell trademark, they feel lethal even in hand.\n"+
      "This is an APDS (armor piercing discarding sabot) munition, capable of punching\n"+
      "holes in most composite armors, including Chobham and certain reactive armors.\n");
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
   return "Patrasen SD505 armor piercing 9.64mm rounds";
}

/*
 * this describes a single round of the ammunition
 *
 */
query_ammo_single_short()
{
   return "an armor piercing 9.64mm round";
}

/*
 * this describes a plural quantity of this ammunition
 *
 */
query_ammo_plural_short()
{
   return "armor piercing 9.64mm rounds";
}

/*
 * a one-word or abbreviated description of what kind of ammo this is.
 *
 */
query_ammo_type()
{
   return "Patrasen SD505";
}

/*
 * The power index specifies in percentage the gain this ammo has over
 * the baseline generic ammo. That baseline is 0 percent gain.
 *
 */
query_ammo_power_index()
{
   return 25;
}