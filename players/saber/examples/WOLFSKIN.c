/*
 *  The pelt of a wolf.
 *  A simple bit of treasure that doesn't really do anything.
 *  Read this, than ROSE.c and than WHISTLE.c
 *                                           -- Saber
 */

/* This gives the item all the code of treasure.c  */
inherit "obj/treasure";

/* Don't fool with the reset just yet...  */
reset(arg)  {
  if(arg) return;

       /* This is the name of the object  */
   set_id("pelt");
       /* This is the description that will be in your inv  */
   set_short("A beautiful wolf pelt");
       /* You will see this if you 'look' at the item  */
   set_long("The pelt of a wolf.  It looks very soft.\n"+
     "You think that it would be worth a decent price.\n");
       /* How much the item weighs  */
   set_weight(3);
       /* How much you can sell the item for */
   set_value(200);
}
