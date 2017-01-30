/* WC bonuses go in here...*/

gen_wc_bonus(){
int bonus;
   if(fire_hands){
      tell_object(USER, 
         HIR+"Fire"+NORM+" radiates around your hands as you strike "+ATTN+".\n");
      tell_room(environment(USER), 
         HIR+"Fire"+NORM+" radiates around "+capitalize(NAME)+"'s hands.\n", ({ USER }));
      bonus +=20; }
   return 0;
}
