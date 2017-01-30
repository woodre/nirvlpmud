inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("gland");
    set_alias("spot");
    set_short("Glowing Spot");
    set_long("The glowing spot was a part of the Fire Beetle within\n"+
             "the UnderDark. The gland gives off a soft red light,\n"+
             "and feels warm to the touch.\n");
    set_weight(1);
    set_value(150);
    set_light(2);
    /* note: any object with set_light(#) in it will
   increase or decrease the light in the room by # amount
   - Mythos <12-6-96> */
}
