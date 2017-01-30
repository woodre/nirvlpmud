#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("dandelion");
   set_short("A Dandelion");
  set_long("A Puffy White Dandelion, gone to seed. You can decapitate\n"+
           "it, sending seeds flying over someone.  <decap> player\n");
   set_weight(1);
   set_value(0);
}
init()
  {add_action("decap","decap");   }
decap(str)
{
write("You decapitate a dandelion, sending fluffy seeds flying towards "+str+". \n");
say(tp+" decapitates a dandelion!  Fluffy white seeds fly everywhere,\n"+
  "landing on "+str+" and parachuting\n"+
"\t\t\t\t  down\n"+
                                                "\t\t\t\t\tto the ground.\n");
 return 1;  }
