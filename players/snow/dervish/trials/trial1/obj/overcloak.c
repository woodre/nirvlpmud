/* 
 * Forbin
 * Created:   2003.09.04
 * Last edit: 2003.09.04 -forbin
 * Change log:
 */

inherit "/obj/armor";

reset(int arg) {
  if(arg) return;
  ::reset();
  set_name("overcloak");
  set_short(GRN+"A dark green overcloak"+NORM);
  set_long("\n");
  set_type("overcloak");
  set_ac(0);
  set_params("other|fire",     1, 3,     "mirror_bounce");
  set_params("other|ice",      1, 3,     "mirror_bounce");
  set_params("other|electric", 1, 3,     "mirror_bounce");
  set_params("other|poison",   1, 3,     "mirror_bounce");
  set_params("other|mental",   1, 3,     "mirror_bounce");
  set_params("magical",        1, 3,     "mirror_bounce");
}

short() {
  string sh, x;
  if(sscanf(sh = (string)::short(), "%s(worn)", x))
    return x+(GRN+"("+NORM+"worn"+GRN+")"+NORM);
  else return sh;
}
   

int
mirror_bounce(object owner)
{
    if(random(6)) return random(2);
    else
    {
      object a;

      if((a = this_player()) && (a != owner))
      {
        if(environment(owner)) tell_room(environment(owner), "\n  * " + short_desc + " FLASHES!\n\n");
        tell_object(a, "You see your own reflection.\n");
        tell_object(a, "The laws of nature reverse, and energy repels!\n");
        a->hit_player(random(10), "magical");
      }
    }
}
