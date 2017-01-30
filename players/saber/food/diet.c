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
   if(this_player()->query_pregnancy()) {
   int hh;
   hh = this_player()->query_age() - this_player()->query_pregnancy();
   if (hh > 4000)
  write("You shouldn't eat strange drugs when you are pregnant.\n");
return 1; }
  write("You eat a magical diet pill.  You lose some weight.\n");
  say(tp+" eats a magical diet pill.\n"+
    tp+" loses some weight.\n");
  if(this_player()->query_phys_at(3) > 85)
  if(!this_player()->query_pregnancy())
  this_player()->add_phys_at(3,-random(7) - 3);
  destruct(this_object());
    return 1;   }
}
