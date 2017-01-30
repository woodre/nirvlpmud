#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

int type;

reset(arg) 
{
   ::reset(arg);
   if (arg) return;
   if(!random(3)) tern();
   else if(!random(3)) kildeer();
   else if(!random(3)) pelican();
   else sandpipr();
}

tern()
{
   type = 0;
   set_name("tern");
   set_short(" Tern");
   set_alias("tern");
   set_long("This shore bird has a white body with black\n"+
            "markings on its head and a grey body and wings.\n"+
            "It's reddish orange bill has a black tip.\n");
   set_level(3);
   set_ac(4);
   set_wc(7);
   set_hp(45);
   set_al(-50);
   set_dead_ob(this_object());
}

sandpipr()
{
   type = 1;
   set_name("sandpiper");
   set_short(" Sandpiper");
   set_alias("sandpiper");
   set_long("The tiny brownish bird with a long bill races to\n"+
            "the foam at water's edge, then just as quickly,\n"+
            "retreats to the safety of the sand.\n");
   set_level(2);
   set_ac(3);
   set_wc(6);
   set_hp(30);
   set_al(35);
   set_dead_ob(this_object());
}

pelican()
{
   type = 2;
   set_name("pelican");
   set_short(" Pelican");
   set_alias("pelican");
   set_long("A huge dark long legged bird, its huge bill\n"+
            "has a large expandable pouch.  Its silvery\n"+
            "brown body is accented by a white neck and\n"+
            "yellow head with bright yellow eyes.\n");
   set_level(4);
   set_ac(4);
   set_wc(8);
   set_hp(60);
   set_al(100);
   set_dead_ob(this_object());
}

kildeer()
{
   type = 3;
   set_name("kildeer");
   set_short(" Kildeer");
   set_alias("kildeer");
   set_long("A small bird with a small dark bill darts about\n"+
            "at the water's edge.  It has black and brown\n"+
            "feathers on it's back and a white chest.\n");
   set_level(2);
   set_ac(3);
   set_wc(6);
   set_hp(30);
   set_al(35);
   set_dead_ob(this_object());
}

monster_died() 
{
  object birdleft;
  birdleft = clone_object("/obj/treasure");
  if(type == 0)
  {
    birdleft->set_id("tail");
    birdleft->set_short("A forked tail");
    birdleft->set_long("Grey forked tail from a tern\n");
    birdleft->set_weight(1);
    birdleft->set_value(120);
    tell_room(environment(),"\
The tern turns with a final attack and dies, losing its tail.\n");
    move_object(birdleft,environment());
  }

  else if(type == 1)
  {
    birdleft->set_id("down");
    birdleft->set_short("Sandpiper down");
    birdleft->set_long("Soft chest feathers from a sandpiper.\n");
    birdleft->set_weight(1);
    birdleft->set_value(90);
    tell_room(environment(),"\
As the tiny bird dies, a small puff of down flies to the sand.\n");
    move_object(birdleft, environment());
  }

  else if(type == 2)
  {
    birdleft->set_id("fish");
    birdleft->set_short("A large fish");
    birdleft->set_long("A large fish flops about on the sand.\n");
    birdleft->set_weight(1);
    birdleft->set_value(150);
    tell_room(environment(),"\
The tame pelican looks at you sadly and, dying,\n\
drops a fish from his bill.\n");
    move_object(birdleft,environment());
  }

  else if(type == 3)
  {
    birdleft->set_id("feather");
    birdleft->set_short("A kildeer feather");
    birdleft->set_long("A tiny brown kildeer feather.\n");
    birdleft->set_weight(1);
    birdleft->set_value(90);
    tell_room(environment(), "\
As the kildeer gasps, a small feather falls beside it.\n");
    move_object(birdleft,environment());  
  }
}
