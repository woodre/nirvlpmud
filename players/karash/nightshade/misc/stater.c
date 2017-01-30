inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("Monster Stater");
set_long
("This is a monster stater. Wanna see how many hp it has?\n"+
 "Just type: stat <monster>.\n");
set_weight(1);
set_alias("stater");
set_value(100);
}
init()

{
::init();
add_action("do_stat", "stat");
}
do_stat(str)
{
object ob;
if(!str) return;
ob=present(str,environment(this_player()));
if(!ob) ob=find_living(str);
if(!ob || !living(ob))
{
write("There is no such creature on the mud.\n");
return 1;
}
if(ob->query_hp()>this_player()->query_hp()) {
  write(ob->query_name()+" has more hit points than you.\n");
}
else
  write(ob->query_name()+" has less hit points than you do.\n");
return 1;
}
