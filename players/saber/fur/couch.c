#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("couch");
   set_short("A large, inviting looking couch");
  set_long(
  "An oversized couch, made of some sort of wonderfully soft leather\n"+
  "material.  It looks very inviting.  Perhaps you could sit in it.\n");
   "sit in it.\n"
;
   set_weight(50);
   set_value(100);
}
init()
{  add_action("sit_couch", "sit");   }
 sit_couch(str)
{  if ((!str) || !id(str)) return 0;
 write("You sit in the couch.\n");
 say(tp+" sits in the couch.\n");
    return 1;   }
