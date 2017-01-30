/* Warrior of the Silver Circle guild weapon */
/* filename : /players/bismarck/guild/weap.c */
/* by: Anthony Swiderski (Bismarck) */
/* environment: Borland Turbo C++ v 3.0 */



inherit "obj/weapon";

#define W_SKILL  this_player()->query_guild_rank()
#define NAME this_player()->query_name()

int damage;


reset(arg) {
   ::reset(arg);
   if(arg) return;
set_alias("dagger");
set_alt_name("bis_weap");
	set_name("your worst nightmare");
set_short("a small dagger");
	set_long("A well-crafted object of destruction\n");
	set_class(8);
	set_weight(0);
	set_value(0);

      set_hit_func(this_object());
}
get(){ return 0;}
drop(){ return 1;}
weapon_hit(attacker) {
  string how, what;
  object target;
   int cost;
if(W_SKILL < 101){

  /* MULTI ATTACK */
  target=first_inventory(environment(this_player()));
   while (target) {
     if (living(target)) {
if(target!=this_player()){
     if (this_player()->valid_attack(target)) {
     if(!target->query_attack())
      target->attack_object(this_player());
if(target == attacker)
    damage = random(W_SKILL);
if(target != attacker)
    damage = random(W_SKILL /3);
     if ( damage < 0) damage = 0;
     if (damage == 0){
     tell_object(this_player(), "You missed.\n");
     say(NAME + " missed " + target->query_name() + ".\n");
     }
   else{
     how = " to small fragments";
     what = "massacre";
   if (damage < 30) {
     how = " with a bone crushing sound";
     what = "smashed";
    }
   if (damage < 20) {
     how = " very hard";
     what = "hit";
    }
   if (damage < 10) {
     how = " hard";
     what = "hit";
    }
   if (damage < 5) {
     how = "";
     what = "hit";
    }
   if (damage < 3) {
     how = "";
     what = "grazed";
    }
   if (damage == 1) {
     how = " in the stomach";
     what = "tickled";
    }

    tell_object(this_player(), "You "+what+" "+target->query_name()+
		how + ".\n");
    tell_object(target, NAME + " " + what + " you" + how +
		  ".\n");
    say(NAME + " " + what + " " +target->query_name()+ how +
		".\n");
if(target->is_player()){
if(damage > 70) damage = 70; }
/*
cost = random(damage - 10);
*/
cost = random(damage - 18) + damage;
if(cost > 3*(damage - 18)/2) cost = 3*(damage - 18)/2;
if(cost < 0) cost = 0;
if(cost > this_player()->query_sp()){
/*
damage = random(random(damage));
*/
cost = this_player()->query_sp();
if (damage > 18) damage = random(10) + 8 + 2*cost/3;
/* changed to my recommendations, -Bp. 
   this insures that extra damage, beyond the normal weapon ability
   is drawen from the players spell points as if they were casting 
   spells. making it equivent to conventional guilds.
*/
}
this_player()->add_spell_point(-cost);
target->hit_player(damage/2);
if(target)
target->hit_player(damage/2 + random(target->query_ac()+1));
    
    
	}
      }
}
}
if(target)
      target = next_inventory(target);

}
}
    return random(5);
    }

