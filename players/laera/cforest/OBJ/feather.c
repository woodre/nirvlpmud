#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"

inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("feather");
  set_alias("golden feather");
  set_short(HIY+"A golden feather"+OFF);
set_long(
"A bright yellow feather from a chicobo.  It is so downy and soft, that\n"+
"if you had enough of them, they would make a wonderful pillow.  They\n"+
"are also great for tickling!\n");
  set_value(300);
  set_weight(1);
}

init()
{
     add_action("feather_tickle","tickle");
}

feather_tickle(string str)
{
     object who;

     if(!str)
     {
       notify_fail("Who did you want to tickle?\n");
       return 0;
     }

     who = present(lower_case(str), environment(tp));

     if (!who || !living(who))
     {
       who = find_player(lower_case(str));

       if (!who || !living(who))
       {
         notify_fail("Who did you want to tickle?\n");
         return 0;
       }

       if (who->query_invis() != 0)
       {
       		notify_fail("Who did you want to tickle?\n");
       		return 0;
       }

       if (who->query_level() >= 20)
       {
		   notify_fail("Wizzes don't like to be tickled!\n");
		   return 0;
	   }

       tell_object(who, tpn + " tickles you playfully with a chicobo feather from afar.\n");
       write(tpn + " tickles " + capitalize(str) + " playfully with a chicobo feather from afar.\n");

       return 1;
     }

     if (who->query_invis() != 0)
     {
       notify_fail("Who did you want to tickle?\n");
       return 0;
     }

     if (who->query_level() >= 20)
     {
		 notify_fail("Wizzes don't like to be tickled!\n");
		 return 0;
	 }

     write("You tickle " + capitalize(str) + " playfully with your feather.\n");
     say(tpn + " tickles " + capitalize(str) + " playfully with a chicobo feather.\n");

     return 1;
}

