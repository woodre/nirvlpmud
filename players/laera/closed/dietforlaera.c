#define tp this_player()->query_name()

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("pill");
   set_short("A magical diet pill");
   set_long("A magical diet pill that you can <eat>\n");
   set_weight(1);
   set_value(100);
}

init()
{  add_action("eat_pill", "eat");   }

eat_pill(str)  {
if(str == "pill") {
   /*if(this_player()->query_pregnancy()) {
  write("Shouldnt eat strange drugs when you are pregnant");
return 1; }*/
  write("You eat a magical diet pill.  You loose weight.\n");
  say(tp+" eats a magical diet pill.\n"+
    tp+" looses weight.\n");
  if(this_player()->query_phys_at(3) > 85)
  /*if(!this_player()->query_pregnancy())*/
  this_player()->add_phys_at(3, -400);
  destruct(this_object());
    return 1;   }
}
