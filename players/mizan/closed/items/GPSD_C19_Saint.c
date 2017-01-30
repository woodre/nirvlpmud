inherit "/players/mizan/closed/items/slugthrower.c";

reset(arg)
{
   if(arg) return;

   /* bonk the superclass */
   ::reset(arg);

   /* the short desc of this object */
   my_short_desc = "A GPSD C19 'Saint' assault rifle"; 
   
   /* the long desc of this object */
   my_long_desc = 
      "  This is a sleek, durable weapon of excellent design clearly meant\n"+
      "for giving someone a bad day. The crisp lines make the weapon's\n" +
      "definition clear and simple.\n"+
      "  Not only is the coldwave industrial appearance an effective fashion\n"+
      "statement, but merely holding it makes you want to engage in some \n"+
      "cruel and mindless slaughter.\n"+
      "\n  Etched into the grip of the weapon are:\n"+
      "[GPSD Corporation : Model C19]\n";

   my_short_alias = "rifle";
   
   /* this weapon has no recoil */
   not_recoilless = 1;

   /* the types of ammunition we can use */
   my_ammotype = 
      ({
      "9.64mm",
      "9.64mmHP",
      });
   
   /* Yup, you can swing this thing around like a baseball bat. */
   usable_without_ammo = 1;

   /* It uses a bayonet too */
   uses_bayonet = 1;

   /* the types of bayonets we can use */
   my_bayonet_type = 
      ({
      "generic_bayonet",
      "c19_bayonet",
      });

   /* It also accepts gadgets */
   uses_gadget = 1;

   /* the types of gadgets we can use */
   my_gadget_type =
      ({
      "generic_gadget",
      "laserlok_gadget",
      "targetting_gadget",
      });
   
   /* It also accepts thumpers */
   uses_thumper = 1;
   
   /* the types of thumpers we can use */
   my_thumper_type =
      ({
      "generic_thumper",
      });

   /* the potential amount of damage done in burst mode */
   my_burst_potential = 500;
   
   /* the potential amount of damage done in singlefire mode */
   my_single_potential = 150;
   
   /* the weapon class of this rifle (somewhat irrelevant, mostly for show) */
   my_weaponclass = 16;

}
