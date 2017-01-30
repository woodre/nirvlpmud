inherit "obj/weapon";
reset(arg) {
   if(arg) return;
   set_name("ax");
   set_short("Paul Bunyan's Ax");
   set_long("A huge, heavy and sharp ax for chopping down trees\n"+
            "and sometimes to chop off the heads of people\n"+
            "MUUUHHUAAAHUUAAAAAAA....\n");
   set_weight(2);
   set_value(200);
   set_class(15); /* From 9 (due to powerup of owner) -Snow */
   set_hit_func(this_object());
}
 
   weapon_hit(attacker)
   {
	int n;
	n=random(5);
	if(n>3){
      write("The ax chops some skin off of "+
        attacker->query_name()+"\n");
     say(this_player()->query_name()+ "chops some skin off of "+
 	attacker->query_name()+"\n");
   }
    return n;
}
