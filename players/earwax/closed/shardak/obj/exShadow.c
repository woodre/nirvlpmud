#define b (15+random(20))

#include "../ansi.h"

/* a replacement for DarkNess */

static object x;

void
wax_on_daniel_san(object c)
{

/* Time changed from 90 + random(90) to 60 + random (90)... intent of the spell is to prevent wimpy... no fight is 180 seconds */
/* Changed by Beck 09/11/02 */

    shadow((x=c), 1);
    call_out("wax_off", 60 + random(90));
}

void
removeShadow()
{
    if(x) shadow(x, 0);
    destruct(this_object());
}

void
wax_off()
{
    if(x)
      tell_room(x, RED + "The inferno subsides.\n" + NORM);
    removeShadow();
}

void
long(string arg)
{
    if(!arg) {
      x->long();
      write(RED + "A raging inferno burns around the area.\n" + NORM);
      return;
    }

    else
      x->long(arg);
}

void  /* just to let 'em leave */
exit(object a)
{
    int        dmg;
    string     msg;

if(!x) return;

     if(!a || ((int)a->is_player() && ( ((int)a->query_level()>=20) || (!a->query_pl_k() && !a->query_fight_area()) )))
    {
      x->exit(a);
      return;
    }


/* Damage changed by Beck 09/11/02 ... too much damage for duration and spell cost */
    if((status)a->is_player())
    {
      dmg=b;
      dmg+=b;
      dmg+=b;
      dmg+=b;
    }

    else
      {
        dmg = b;
        dmg += b;
        dmg += b;
        dmg += b;
        dmg += b;
    }

    switch(random(4)) {
      case 0:
        msg = "Flames burn you severely as you escape.\n";
        break;
      case 1:
        msg = "Fire reaches up and burns you as you escape.\n";
        break;
      case 2:
        msg = "The inferno rages around your body...\n";
        break;
      case 3:
        msg = "The flames scorch your battered frame.\n";
        break;
    }

    tell_object(a, "\n" + HIR + msg + NORM + "\n");
    a->hit_player(dmg, "other|fire");
    x->exit(a);

}


WaxedOn(){ return 1; }
int pk_spell() { return 1; }
