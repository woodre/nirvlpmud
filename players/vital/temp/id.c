#include <ansi.h>
inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("button");
  set_alias("student id");
  set_short("");
  set_ac(0);
  set_type("button"); /* changed to set_type() --vital 2005.10.21 */
  set_weight(1);
  set_value(0);
}

string
short()
{
  string shrt;
  if(environment() && environment()->is_player())
    shrt = HIW + call_other(this_player(), "query_name") + "'s ID button" +
           NORM;
  else
    shrt = HIY + "A student ID button" + NORM;
  shrt = shrt + ::short();
/*   if(worn) */ /* let the /obj/armor take care of this */
/*     shrt+=" (worn)"; */
/*   if(this_player() && this_player()->query_level() > 20) */
/*     shrt+=" < ac0, button >"; */
  return shrt;
}

void
long(string str)
{
  write(format("The plastic tag you hang on yourself has your name and your\
picture engraved on it.  It shows that you enrolled into Nirvana \
University: be proud of wearing it"));
  ::long();
  return;
}


void init()
{
  ::init();
/*   if(!environment() || !environment()->is_player()) */
/*     destruct(this_object()); */
}
