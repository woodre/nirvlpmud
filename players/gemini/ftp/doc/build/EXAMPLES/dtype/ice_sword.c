/* ice_sword.c
 * example of using dtypes in the offensive capabilities
 * of a weapon
 * Illarion (6-04)
 */

inherit "obj/weapon";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("sword");
  set_short("The sword of ice");
  set_long("The blade of this sword seems always to be covered with a\n"+
           "thin sheen of frost, and a chill hangs in the air around it.\n");
  
  set_type("sword");
  /* Physical Damage */
  set_class(12);
  /* Ice Damage */
  set_params("other|ice",5,0);
  set_weight(4);
  set_value(3000);
}
