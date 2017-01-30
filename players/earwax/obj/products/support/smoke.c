/*
 *      File:                   ~earwax/obj/products/support/smoke.c
 *      Function:               Smoke shadow to obscure locations for grenade.c
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 07/13/2007
 *      Notes:                  Grenade dispensed via ~/obj/dispenser.c
 *                              Grenade is ~/obj/products/grenade.c
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* Global Variables */

object where;

void smoke_inhalation()
{
  object ob;

  if (!where) return;
  ob = first_inventory(where);

  while(ob)
  {
    if ((int)ob->is_player() && (int)ob->query_level() > 8 && 75 > random(100))
    {
      tell_object(ob, GRN+"You choke and cough on the thick smoke!\n"+NORM);
      ob->hit_player(25+random(26), "poison");
    }
    ob = next_inventory(ob);
  }
}

void start_shadow(object ob){
  where = ob;
  shadow(ob, 1);
  call_out("end_shadow", 300);
  if (!random(15)) smoke_inhalation();
}

end_shadow(){
  shadow(where, 0);
  destruct(this_object());
}

void blowie()
{
  tell_room(where,"\n\
Suddenly, the grenade\n"+HIR+BLINK+"\
                     EXPLODES!"+NORM+"\n\
                               The room instantly is filled with "+GRN+"green "+HIK+"smoke!\n\n"+NORM);
  start_shadow(where);
}
                               
string short(){ return GRN+"Smokescreened"+NORM; }
varargs void long(string arg) { 
  if (environment(this_player()) == where)
  {
    write(HIK+"This is what you make out through the thick smoke: \n\n"+NORM);
    where->long(arg);
    return;
  }
  
  write("The room is shrouded in THICK "+GRN+"green"+HIK+" smoke"+NORM
    +", making it impossible to see.\n");
}
  
void start_smoke(object ack)
{
  where = ack;
  call_out("blowie", 1);
}


/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
