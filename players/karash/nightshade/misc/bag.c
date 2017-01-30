/* modified bag to check for "NT" of sender and receiver on
   3/30/97.  -Eurale */
inherit "obj/container";
reset(arg) {
set_name("bag");
set_short("Teleporting bag");
set_long("This is a magical bag. You can send it and whatever is in\n"+
"it to anyone, anywhere on the mud. Just type send <player name>.\n");
set_value(100);
set_weight(1);
set_max_weight(15);
}
init()
{
::init();
add_action("do_send", "send");
}
do_send(str)
{
object ob;
if(this_player()->query_sp() < 50)
{
write("You dont have 50 spell points.\n");
return 1;
}
if(!str) return;
if(!find_player(str))
{
write("They dont exist!\n");
return 1;
}

ob=find_player(str);
if(ob->query_invis()) { write("They dont exist!\n"); return 1; }
if(ob->query_level() > 19) {
  write("You may not send to a wiz.\n"); 
return 1;}
/*  "NT" checks follow - Eurale  */
 if(environment(ob)->query_lock()) { /* verte */
  write(environment(ob)->short()+" is locked.\n");
  write("Stop being an ass.\n");
    return 1;
}
if(environment(ob)->realm() == "NT") {
  write("You cannot send to that area.\n"); return 1; }
if(environment(this_player())->realm() == "NT") {
  write("You are in a 'no send' zone.\n"); return 1; }
this_player()->add_spell_point(-50);
  move_object(this_object(), ob);
  write("You send a bag to "+ob->query_name()+".\n");
  tell_object(ob, "You just got a magical bag from "+this_player()->query_name()+".\n");
  this_player()->add_weight(-1);
return 1;
}

query_save_flag() { return 1; }
