#include "/players/mokri/define.h"
string *semi_banned;
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("semibanner");
   set_short("asdf");
   set_long("asdf\n");
}

kill_em_all()
{
   int x;
   object who;
   
   if(environment(this_object()))
      {
      for(x = 0; x < sizeof(semi_banned); x++)
      {
         who = find_player(semi_banned[x]);
         if(who && who->query_real_name() == semi_banned[x])
            {
            if(!present("semibanner",who))
               move_object(clone_object("/players/mokri/obj/semiban.c"),who);
            command("save",who);
            destruct(who);
          }
      }
   }
}

init()
{
   ::init();
   semi_banned = ({ "2veeshan","2chip" });
   if(environment(this_object()))
      kill_em_all();
}

query_auto_load() { return "/players/mokri/obj/semiban.c:"; }
drop() { return 1; }
