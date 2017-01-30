object monks;

id(str) { return str == "chat_d"; }

add_user(ob) {
	if (!monks) { 
	   monks = allocate(3);
	   monks += ob;
	   return;
	}
	monks += ob;
	return 1;
}

activate_me() {
	return 1;
}

remove_user(ob) {
	monks -= ob;
}

update_monks() {
	object *old_monks;
	int i;

	old_monks = monks;
	monks = 0;
	i = sizeof(old_monks);
	while (i--) {
	      if (old_monks[i] != 0) {
		 if (!monks)
                    monks = old_monks[i];	
		 else
	            monks += old_monks[i];
	      }
	}
}
              
reset(arg) {
	if (arg) {
           update_monks();
	   return;
	}
	monks = 0;
}

is_user(ob) {
	int i;
	if (!monks)
           return 0;
	i = sizeof(monks);
	i--;
	while (!ob == monks[i]) 
	      i--;
	if (!i) 
           return 0;
	else
           return 1;
}

chat(ob, str) {
	int i;
	string msg;

	i = sizeof(monks);

	msg = "<*"+ob->query_name()+"*>"+str+"\n";

	while (i--) {
	      if (monks[i] != 0) {
	         if (!present("new_mrobe", monks[i])->query_muffle()) 
		    tell_object(monks[i], msg+"\n");
	      }
	}
}

query_users() {
	return monks;
}

	      
