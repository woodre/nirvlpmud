/*
 *  A good pair of orcboots.
 *  Read HALFCHAIN.c, and than this file.
 *                                                 -- Saber
 */

inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("orc boots");
   set_short("A pair of orc boots");
   set_alias("boots");
   set_long("A pair of orc boots.  They look good for stomping things.\n");
       /* This sets the boots to the armor type of 'boots' */
   set_type("boots");
   set_ac(1);
   set_weight(2);
   set_value(100);
}
