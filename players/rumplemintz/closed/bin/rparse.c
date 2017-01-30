string vars;
object stores;

static find_item(prev, str){
    object ob;
    string tmp;
    if(str=="here") return environment(this_player());
    if(str=="me") return this_player();
    if(str=="^") return environment(prev);
    if(sscanf(str,"@%s",tmp)==1) return find_living(tmp);
    if(sscanf(str,"*%s",tmp)==1) return find_player(tmp);
    if(str[0]=='/' || str[0]=='~' || str[0]=='.')
	return load_object(this_player()->valid_read(str));
    if(sscanf(str,"$%d",tmp)==1){
	object u;
	u=users();
	write("size: "+sizeof(u)+"\n");
	if(tmp>=sizeof(u) || tmp<0) return 0;
	return u[tmp];
    }
    if(sscanf(str,"$%s",tmp)==1){
	int i;
	while(i<sizeof(vars)){
	    if(tmp==vars[i]) return stores[i];
	    i += 1;
	}
	return 0;
    }
    if(prev==0) prev=environment(this_player());
    if(sscanf(str,"\"%s\"",tmp)==1){
	ob=first_inventory(prev);
	while(ob && ob->short() != tmp){
	    ob=next_inventory(ob);
	}
	return ob;
    }
    if(sscanf(str,"#%d",tmp)==1){
	if(prev=0) return 0;
	ob=first_inventory(prev);
	while(tmp>1){
	    tmp -= 1;
	    if(ob==0) return 0;
	    ob=next_inventory(ob);
	}
	return ob;
    }
    return present(str, prev);
}

assign(var, val){
    int i;
    while(i<sizeof(vars)){
	if(vars[i] == var){
	    stores[i] = val;
	    return;
	}
	if(vars[i] == 0){
	    vars[i] = var;
	    stores[i] = val;
	    return;
	}
	i += 1;
    }
}

static disp(ob){
    write(file_name(ob)+"\n");
}

parse_list(str){
    string tmp, rest;
    object prev;
    prev = environment(this_player());
    while(prev && str){
	if(sscanf(str,"%s:%s",tmp,rest)==2){
	    prev = find_item(prev,tmp);
	    str=rest;
	    continue;
	}
	prev=find_item(prev,str);
	break;
    }
    assign("$", prev);
    if(objectp(prev)) disp(prev);
    return prev;
}
