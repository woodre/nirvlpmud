string *people;

reset(arg){
	if(arg) return;
	people = ({ });
}

add_people(object ob)
{
	string name;
	
	name = ob->query_real_name();
	
	people += ({ name });
}

check_people(object ob)
{
	string name;
	
	name = ob->query_real_name();
	
	if(member_array(name, people) < 0)
	{
		return 0;
	}
	
	else
	{
		return 1;
	}
}