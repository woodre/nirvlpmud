/*
 *  A suit of magical half chain armor.
 *  Yes, armor is this easy to make.
 *  Read this, and than ORCBOOTS.c
 *                                                 -- Saber
 */

/* This gives you all the code of armor.c */
inherit "obj/armor";

/* Don't touch this just yet...  */
reset(arg){
   ::reset(arg);

       /* This name of the object */
   set_name("half chain");
       /* What the armor looks like in your inventory */
   set_short("A suit of magical half chain");
       /* A nickname for the armor */
   set_alias("chain");
       /* What you see when you 'look' at the armor */
   set_long("A suit of magical fine steel half chain.\n");
       /* The amount of protection the armor gives you. */
   set_ac(4);
       /* How heavy the armor is */
   set_weight(3);
       /* How much the armor is worth */
   set_value(500);
}
