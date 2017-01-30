inherit "obj/weapon";
int flag;
string come;
short()
{
return "A boomerang ("+come+")";
}

reset(arg){
   if(arg) return;
      ::reset(arg);
      flag=0;
      come="new";
        set_name( "boomerang"  ) ;
        set_long( "This is a boomerang. You can use it typing 'throw boomerang at <name>'\n"+
	"but be careful! It can hit you hard.\n") ;
	set_class(17);
        set_weight(3);
        set_value(2500);
}

init() {
        add_action ("throw", "throw") ;
	add_action("wield", "wield");
	add_action("stopwield", "unwield");

}


throw (who) {
	string str;
	object victim;
	object obj;
	int num,hp;
	if(!who)
		return 0;
	if(sscanf(who,"boomerang at %s",str))   {
	        str = lower_case(str);
        	victim = find_living(str);
        	obj = present(str, environment(this_player()));
        	if(!victim)  {
        		if(!obj)  {
        		        notify_fail("I don't see that here.\n");
        		        return 0 ;
        		}
			if(!living(obj)) {
        	       		return 0;
        		}
		}
		else  {
        		if(!obj)  {
        		        notify_fail("I don't see that here.\n");
        		        return 0 ;
        		}
        		if (victim->query_ghost()) {
        		        notify_fail (victim->query("cap_name")+" is already dead.\n") ;
        		        return 0;
        		}
        		if(victim == this_player()) {
        		        notify_fail("You want to throw to yourself?\n");
        		        return 0;
        		}
			if(!victim->query_npc())  {
				notify_fail("You can't attack other players.\n");
				return 0;
			}
		}
        	obj->attack_object(this_player()) ;
		num=random(3);
		++flag;
		if(!num)  {
			obj->hit_player(30);
			write("Your enemy has smashed by the boomerang.\n");
			say(this_player()->query_name()+" smashes "+capitalize(str)+" with his boomerang.\n");
			}
		else if(num==1)   {
			write("The boomerang misses the target.\n");
			say(this_player()->query_name()+" throws his boomerang but it misses.\n");
			}
		else
			{
                        this_player()->hit_player(30);
			write("The boomerang misses the target but hits you hard!\n");
			say("The boomerang hits "+this_player()->query_name()+".\n");
			}
		if(flag==1)  {
			write("The boomerang starts to crack itself.\n");
			come="ruined";
                       set_class(15);
			}
		else if(flag==3)
			{
			write("The boomerang crashes definitively and turns into dust.\n");
			destruct(this_object());
			}
		else   {
			write("The boomerang is now in a bad shape.\n");
			come="very cracked";
                     set_class(12);
			}
        	return 1 ;
		}
	notify_fail("What do you want to throw?\n");
	return 0;
}


