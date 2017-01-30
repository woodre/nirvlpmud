
/*
 * JUDGE (2/11/94)
 * Get the alignment of a living object
 */

judge(str) {
   int align;
   object target;
   string mess;

   if(!verify_use())
     return 1;
   if(!str) 
     notify_fail("Who do you wish to judge?");
   target = present( str, environment( this_player()));
   if(!target || !living(target))
     notify_fail(capitalize(str)+" is not here.");
   if(!target->query_npc() && target->query_level() > 20) 
     notify_fail("Who are you to judge a wizard?");
   align = target->query_alignment();
   if(align <= 0)   mess = filter_color("dull red",RED);  
   if(align < -250) mess = filter_color("light red",RED);
   if(align < -500) mess = filter_color("bright red",HIR); 
   if(align > 0)    mess = filter_color("dull blue",BLU);
   if(align > 250)  mess = filter_color("light blue",BLU);
   if(align > 500)  mess = filter_color("bright blue",HIB);
   write("A "+mess+" aura surrounds "+capitalize(str)+".\n");
   return 1;
}
