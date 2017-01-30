#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("shard");
 set_short("A shard of crystal");
set_long("A shard of crystal taken from the crystal elemental.\n"+
       "When polished, it has a bright shine.\n");
   set_weight(0);
   set_value(1000);
}

init() {
 add_action("polish_shard","polish");
}

polish_shard(str){
if(!str){
write("What do you want to polish?\n");
return 1; }
write("You polish the shard of crystal.\nYou can see your reflection in it!\n");
say(tp+" polishes the shard of crystal.\n");
  return 1;   }

