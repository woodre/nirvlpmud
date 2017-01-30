/* fire_ring.c 
 * A ring that gives protection against the fire dtype
 * Illarion (6/04)
 *
 *
 */
 
inherit "/obj/armor";
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("ring");
  set_short("A ring of protection from fire");
  set_long("The surface of this silver ring is always cool, even if it\n"+
           "is held over a torch of a campfire.  When worn, that same\n"+
           "feeling of coolness seems to spread all over your body.\n");
  
  /* Fire armor and Reistance */
  set_params("other|fire",0,25,0);
/* regular armor */
  set_ac(1);
  
  set_type("ring");
  set_weight(1);
  set_value(1000);
}

