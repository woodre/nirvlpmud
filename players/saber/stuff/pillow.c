#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("pillow");
   set_short("A soft pillow");
  set_long("A wonderfully soft pillow.\n"+
           "You could probably 'bop' somebody with it\n");
   set_weight(1);
   set_value(10);
}
init()
  {add_action("bop","bop");   }
bop(str)
{
write("You *bop* "+str+" over the head with the pillow!\n");
say(tp+" *bops* "+str+" over the head with the pillow!\n");
 return 1;  }
