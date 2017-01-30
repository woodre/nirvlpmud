/*
 *    The dead versuib of the snake staff carried by the Priestess of Arate.
 */

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);    
    if (arg) return;

    set_name("snake staff");
    set_alias("staff");
    set_type("staff");         /* set type added by Pavlik */
    set_short("A broken Snake Staff");
    set_long("A long, ironwood staff carved to resemble a snake.\n"+
             "It is covered with runes of alteration and summoning.\n"+
             "The staff has been slain, and is quite dead.\n");
    set_read("To animate the staff, type <snake> <monster name>.\n");
    set_class(8);
    set_weight(2);
    set_value(25);
    call_out("no_corpse",1);
}

no_corpse()  {
object corpse;
  corpse = present("corpse", environment(this_object()));
  destruct(corpse);
  return 1;
          }
          
