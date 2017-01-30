#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/string.h"

health_monitor(obj)
{
  string c;
  string *names;
  string *n;
  mapping spells;
  int x, y;

  tell_object(obj, CYN+"<<"+NORM+HIC+"( "+NORM);

  /* HP */
  x = obj->query_hp();
  y = obj->query_mhp();
  if(x * 100 / y <= 10) c = HIR;
  else if(x * 100 / y <= 30) c = HIY;
  else c = "";
  if(x > 999) x = 999;
  tell_object(obj, CYN+"HP "+NORM+c+strpad(x, " ", -3)+NORM+"/"+strpad(y, " ", -3)+"  ");

  /* SP */
  x = obj->query_sp();
  y = obj->query_msp();
  if(x * 100 / y <= 10) c= HIR;
  else if(x * 100 / y <= 30) c= HIY;
  else c = "";
  if(x > 999) x = 999;
  if(y > 999) y = 999;
  tell_object(obj, CYN+"SP "+NORM+c+strpad(x, " ", -3)+NORM+"/"+strpad(y, " ", -3)+" "+HIC+"|"+NORM+" ");

  /* Intox, Full, Soak, Transfer */
  tell_object(obj, CYN+"I: "+NORM+strpad((obj->query_intoxination()*100/obj->query_max_intox()), " ", -3)+"% ");
  tell_object(obj, CYN+"F: "+NORM+strpad((obj->query_stuffed()*100/obj->query_max_stuff()), " ", -3)+"% ");
  tell_object(obj, CYN+"S: "+NORM+strpad((obj->query_soaked()*100/obj->query_max_soak()), " ", -3)+"% ");
  tell_object(obj, CYN+"T: "+NORM+strpad(0, " ", -3)+"% "+HIC+"|"+NORM+" ");

  /* Attacker */
  if(obj->query_attack())
  {
	x = obj->query_attack()->query_hp();
	y = obj->query_attack()->query_mhp();
	tell_object(obj, CYN+"AHP "+NORM+strpad((x*10/y), " ", -2)+"/10 ");
  }
  else
  {
	tell_object(obj, "          ");
  }

  /* End of first line */
  tell_object(obj, HIC+")"+NORM+CYN+">>"+NORM+"\n");

  /* Begin next line */
  tell_object(obj, CYN+"<<"+NORM+HIC+"( "+NORM);

  /*
   * Spells in Effect
   */
  spells = present("mageobj", obj)->query_spell_objects();

  if(!spells || !sizeof(spells))
	tell_object(obj, CYN+"Spells:"+NORM+"                ");
  else
  {
	n = ({});
	names = m_indices(spells);
	for(x=0; x<sizeof(names); x++)
	{
		if(!spells[names[x]]) continue;
		if(names[x] == "blind")		n += ({ "BL" });
		if(names[x] == "ffire")		n += ({ "FF" });
		if(names[x] == "eshield")	n += ({ "ES" });
		if(names[x] == "lifesteal")	n += ({ "LS" });
		if(names[x] == "stoneskin")	n += ({ "SS" });
		if(names[x] == "absorb")	n += ({ "AB" });
		if(names[x] == "augury")	n += ({ "AU" });
		if(names[x] == "gstr")		n += ({ "GS" });
	}
	c = implode(n, "/");
	if(strlen(c) > 0)
		tell_object(obj, CYN+"Spells:"+NORM+" "+strpad(c, " ", 14)+" ");
	else
		tell_object(obj, CYN+"Spells:"+NORM+"                ");
  }
  tell_object(obj, HIC+"|"+NORM+" ");

  /*
   * Next Casting Timers
   */
  x = present("mageobj", obj)->query_next_casting("protection") - time();
  if(x <= 0)
	tell_object(obj, CYN+"P:"+NORM+"   -  ");
  else
	tell_object(obj, CYN+"P:"+NORM+strpad(x, " ", -4)+"  ");

  x = present("mageobj", obj)->query_next_casting("damage") - time();
  if(x <= 0)
	tell_object(obj, CYN+"D:"+NORM+"   -  ");
  else
	tell_object(obj, CYN+"D:"+NORM+strpad(x, " ", -4)+"  ");

  x = present("mageobj", obj)->query_next_casting("heal") - time();
  if(x <= 0)
	tell_object(obj, CYN+"H:"+NORM+"   -  ");
  else
	tell_object(obj, CYN+"H:"+NORM+strpad(x, " ", -4)+"  ");

  x = present("mageobj", obj)->query_next_casting("alteration") - time();
  if(x <= 0)
	tell_object(obj, CYN+"A:"+NORM+"   -  ");
  else
	tell_object(obj, CYN+"A:"+NORM+strpad(x, " ", -4)+"  ");

  if(present("mageobj", obj)->query_casting())
	tell_object(obj, HIC+"|"+NORM+HIR+" *CASTING* "+NORM);
  else
	tell_object(obj, HIC+"|"+NORM+"           ");

  /* End of second line */
  tell_object(obj, HIC+")"+NORM+CYN+">>"+NORM+"\n");

}


/*
<<( HP: 200/200  SP: 300/300 | I:   0% F:   0% S:   0% T:   0% | AHP 10/10 )>>
<<( Spells: SS/ES/FF/CU      | P:  5m  D:   49 H:   -  A:   -  |           )>>
*/


