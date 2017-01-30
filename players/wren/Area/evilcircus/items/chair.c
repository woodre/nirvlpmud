	/* chair */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_id("chair");
set_name("chair");
set_alias("club");
set_short("metal chair");
set_long("This is a sturdy metal chair made out of some sort of \n"+
         "ultra-dense alloy. The chair has been a tool of animal \n"+
         "performance trainers for many years. The legs and crossing \n"+
         "lines provide a distraction to an animal thinking about \n"+
         "striking for it is difficult to determine which edge is \n"+
         "closest. It can also be used to bash them if they do charge. \n");

set_type("club");   /*sword,knife,club,axe,bow,polearm */
set_class(15);
set_weight(2);
set_value(200+random(800));
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(15);
if(W>12)  {
    say(this_player()->query_name()+ "distracts foe with quick feints from the chair.\n");
    write("You distract your foe with several feints from the chair. \n");
    return 4;
          }
if(W<2)  {
    say(this_player()->query_name()+ "cracks foe over the head with the chair.\n");
    write("You haul back and crack opponent over the head with the chair. \n");
    return 8;
          }
return;
}
