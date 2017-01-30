#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("bear");
    set_short("A large teddy bear");
    set_long("A large stuffed teddy bear with brown fur and cute white eyes.\n"+
     "It looks well loved.  You feel that you should hug it.\n");
   set_weight(1);
   set_value(10);
}
init()
{  add_action("hug_bear", "hug");   }
hug_bear(str)
{
if(str == "bear") {
 write("You hug the large teddy bear.\n"+
    "The teddy bear gives you a great sense of comfort.\n");
 say(tp+" hugs a large teddy bear.\n"+
  tp+" looks very happy.\n");
    return 1;   }
}
