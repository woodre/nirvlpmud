#define WHO this_player()->query_real_name()
#define WHAT call_other(attacker, "query_name", 0)
inherit "obj/weapon";
   int i, hit;
int shots_used;
   object ob;

reset(arg) {
 ::reset();
  if(arg) return;
   shots_used = 6;
 set_name("A 44 Magnum");
 set_alias("magnum");
  set_short("A 44 Magnum");
set_long("This gun is not accurate, its not easy to hide, but it\n" +
    "blows large holes into its most unfortunate opponent.!!!!\n" +
     "It looks like you can shoot(opponent) with this massive gun!\n" +
   "This is the 44 of Dirty Harry!\n");
  set_class(18);
  set_weight(4);
  set_value(20000);
  set_hit_func(this_object());
}
id(str) { return str == "magnum" || str == "gun" || str == "44"; }

weapon_hit(attacker) {
 i = random(100);
  i++;
   write("Pulling the trigger on the massive 44, you blow away anything in sight!\n" +
  "You hit "+capitalize(WHAT)+" very hard.\n" +
  "BLAM!!!    BLAM!!!\n"+
 "BLAM!!!    BLAM!!!\n" +
 "You smashed "+capitalize(WHAT)+" with a bone crushing sound.\n");
  say(capitalize(WHO) +" pulls the trigger on the mighty 44 and blows the enemy away!\n" +
  "BLAM!!!    BLAM!!!\n" +
  "BLAM!!!    BLAM!!!\n" +
 capitalize(WHO)+" smashed "+capitalize(WHAT)+" with a bone crushing sound.\n");

   if(i<70) {
   return random(7)+9;
  this_player()->add_spell_point(-1);
     }
   if(i<4) {
   write("The massive 44 backfires causing damage to you!\n" +
  "You grazed "+capitalize(WHAT)+".\n");
    this_player()->hit_player(random(10)+5);
 say(capitalize(WHO)+" misfires the 44 Magnum!!!\n"+
  WHO+" grazes "+capitalize(WHAT)+".\n"+
  WHO+"'s 44 backfires into "+this_player()->query_possesive()+" chest!\n"+
  "Causing damage to "+WHO+"\n");
             return 0;
             }
       return 0;
}


init() {
 ::init();
  add_action("reload","reload");
  add_action("shoot","shoot");
}

shoot(str)
{
  if(!str){
  write("Shoot what?\n");
    return 1;
  }
   ob = present(lower_case(str), environment(this_player()));
  if(!ob) {
  write("You try to fire a shot at " +str+ " but you dont see them.\n");
    return 1;
    }
    if(shots_used > 5) {
       write("You have expended all of the 44's bullets.\n");
write("You have to reload the weapon before you can shoot it again.\n");
        return 1;
     }
   present(ob, environment(this_player()))->attacked_by(this_player());
      say(call_other(this_player(),"query_name") + " fires the 44 magnum!!.\n");
  write("You pull the trigger on the 44 unleashing massive fire power!\n" +
  "The bullet strikes " +capitalize(str)+ " in the chest leaving a HUGE hole!\n");
  if (shots_used == 6) { write("The 44 is out of bullets!.\n"); }
      else { write("There are " + (5 - shots_used) + " shots left.\n"); }
     ob->hit_player(15);
      shots_used++;
      return 1;
}
reload() {
   if(present("clip", environment(this_object()))) {
  write("You put in six fresh bullets and reload the 44!\n");
   say(capitalize(WHO)+ " reloads the 44.\n");
      shots_used = 0;
    destruct(present("clip"));
     return 1;
     } else {
  write("You need to buy bullets before you can reload bud!\n");
       return 1;
  }
}
 

