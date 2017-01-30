/*****************************************************************/
/* Unlimited Sps                                                 */
/* Hps max of wearer at 4/5 original max                         */
/* Hp cost when free sp given, but no chance of death from ring  */
/* Returns a constant negative AC                                */
/* Drains exp, stamina attrib, and all attribs                   */
/*                                                               */
/* Approved by:                                                  */
/*****************************************************************/

#include <ansi.h>
inherit "obj/armor";
int hp, sp, A, B, Z;
string *all;

reset(arg) {

  hp = 0;  
  sp = 0;  
  A = 0;  
  B = 0;  
  Z = 0;
  all =({ "str","sta","wil","mag","pie","ste","luc","int" });

  ::reset(arg);

  set_name("hollow ring of bone");
  set_long(
"This is a small white ring constructed from bone.  On the top of\n"+
"the ring is a glistening black jewel.  Small white bones hold it\n"+
"in place, like the grasping fingers of a dead man.\n");
  set_value(6666);
  set_weight(1);
  set_ac(1);
  set_type("ring");
  set_save_flag(1);
}

do_special(owner)
{
  int top, now, dif, i;
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  top = owner->query_mhp();
  now = owner->query_hp();
  if(now > (top * 4 / 5))                /* low hps max */
  {
    dif = now - (top * 4 / 5);
    owner->add_hit_point(-dif);
    hp += dif;
    if(!random(3))
    {
      tell_object(owner, BOLD+BLK+
        "The hollow ring feeds on your strength.\n"+NORM);
    }
  }
  top = owner->query_msp();
  now = owner->query_spell_point();
  if(now < top)                         /*  free sps */
  {
    dif = top - now;
    owner->add_spell_point(dif);
    sp += dif;
    if(!random(20))
      tell_object(owner, "The hollow ring tightens around your finger.\n");
    owner->add_hit_point(- (dif/10));         /* hps cost */
    hp += (dif/10);
    if(0 == owner->query_hp())
      owner->add_hit_point(1);
    A++;
    B++;
    Z++;
  }
  if(!random(20))                       /*  very low ac */
  {
    tell_object(owner, BOLD+BLK+"The hollow ring glows softly.\n"+NORM);
    return -20;
  }
  if(A > 66)                            /*  lose 6666 xp */
  {
    A = 0;
    if(random((int)owner->query_attrib("luc")) >= 17)
      return 5;
    if((int)owner->query_exp() > 6666)
      owner->add_exp(-6666);
    tell_object(owner, BOLD+BLK+"The hollow ring pulses darkly.\n"+NORM);
  }
  else if(B > 250)                      /*  drain sta */
  {
    B = 0;
    if(random((int)owner->query_attrib("luc")) >= 17)
      return 5;
    tell_object(owner, "You feel a sharp pain run through your body.\n");
    owner->set_attrib("sta", (int)owner->query_attrib("sta") - 1);
    owner->save();
    owner->reset();
  }
  else if(Z > 2000)                     /*  drain all stats */
  {
    Z = 0;
    if(random((int)owner->query_attrib("luc")) == 19)
      return 5;
    tell_object(owner, BOLD+BLK+"A dark glow engulfs your hand.\n"+NORM+
      "Pain engulfs your body and then is gone.\n");
    for(i=0; i < sizeof(all); i++)
    {
      if((int)owner->query_attrib(all[i]) > 0)
        owner->set_attrib(all[i], (int)owner->query_attrib(all[i]) - 1);
    }
    owner->save();
    owner->reset();
  }
  return -6;
}

short(){
  string x;
  x = BOLD+BLK+"the hollow ring of bone"+NORM;
  if(this_player()->query_level() >= 40)
    x += "  < ac 2, ring >";
  if(worn)
    x += " (worn)";
  if(this_player()->query_real_name() == "zeus" ||
    this_player()->query_level() >= 100)
    x += " [hp: "+RED+hp+NORM+" | sp: "+RED+sp+NORM+"]";
  return x;
}
