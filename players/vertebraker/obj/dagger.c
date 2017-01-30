#include "/players/vertebraker/ansi.h"

inherit "/obj/weapon";

status flag;

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    set_name("dagger of haste");
    set_alias("dagger");
    set_type("knife");
    set_short("The Dagger of Haste " + HIC + "(glowing)" + NORM);
    set_long("\
The Dagger of Haste is approximately six inches in length,\n\
and is quite quick when you pull it from a belt.\n\
It is a legendary weapon of repute.\n");
    set_read("The Dagger of Haste");
    set_weight(1);
    set_value(666);
    set_hit_func(this_object());
    set_class(15);
    call_out("funk_me", 100);
    set_light(1);
    set_message_hit(({
 "plunged the Dagger of Haste into", "",
 "stabbed", "",
 "slashed", " brilliantly",
 "sliced", " keenly",
 "sliced", "",
 "grazed", "",
 "grazed", "", }));
 set_save_flag(1);
}

void
chk_heart_atk()
{
    object e;

    if(!random(888) && 
       ((int)(e = environment())->query_attrib("wil") < random(40)))
    {
      tell_object(e, "\
\n\n\tYou collapse to the ground, clutching your chest.\n\n");
      e->hit_player(444);
    }
}

void
funk_me()
{
    object e;
    if((e = environment()) && wielded)
    {
      tell_object(e, "Your heart beats faster.\n");
      e->heart_beat();
      chk_heart_atk();
    }

    call_out("funk_me", 100);
}

status
query_save_flag()
{
    return 1;
}

void
weapon_hit(object a)
{
    int i;
    object e, z;

    if(0 == random(3) && (e = environment()) &&
      (z = environment(e)))
    {
      tell_object(e, "\
Your motions are ablur with the Dagger of Haste!\n");
      for(i = 0; i < random(3); i ++)
        e->heart_beat();
      for(i = 0; i < random(3); i ++)
        e->attack();
      if(!flag)
        for(i = 0; i < random(3); i ++)
        {
          flag = 1;
          weapon_hit(a);
          flag = 0;
        }
      chk_heart_atk();
    }
}
