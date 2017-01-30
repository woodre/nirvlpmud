/* took out the heal ability cause there was no charge setup
  - mythos <5-10-96> */

inherit "obj/weapon";
object ob;
int can_heal;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("staff");
                set_class(1);
                set_value(1000);
                set_weight(7);
                set_alias("staff");
                set_short("Staff of Healing");
can_heal=8;
set_long(
"This is a magically enchanted staff of healing.\n";
}
}
init()
{
::init();
/*
if(environment() == this_player()) add_action("do_heal", "heal"); */
if(environment() == this_player()) add_action("do_tonic", "transfer"); ;
}
/*
do_heal(str)
{
if(call_other(this_player(),"drink_alcohol", 20))
  {
    this_player()->heal_self(22);
*/
do_tonic()
{
ob=this_player()->query_sp();
if(ob < 100)
{
write("You dont have enough spell points to transfer.\n");
return 1;
}
write("You transfer some spell points to hit points.\n");
this_player()->add_hit_point(50);
this_player()->add_spell_point(-100);
return 1;
}
