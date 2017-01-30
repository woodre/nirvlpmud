new_inventory(){
	object woo,woo2;
	int i;
	i = 1;
	woo = first_inventory(environment());
	
	write(
		BOLD+"   ________________ [ Inventory ] ________________"+NORM+"\n"+
	"   Item: \n");
	
	while(woo){
		woo2 = next_inventory(woo);
		if(woo->short()){
			if(i < 10){ write("["+HIG+"0"+i+NORM+"] "+woo->short()+" "); }
			else{ write("["+HIG+i+NORM+"] "+woo->short()+"  ");  }
			if(woo->armor_class()){  write(HIG+"["+woo->query_type()+"]"+NORM+"\n"); }
			else if(woo->weapon_class()){ write(HIG+"[Weapon]"+NORM+"\n"); }
			else{ write("\n"); }
			i++;
		}
		
		woo = woo2;
	}
        write("Carrying: "+this_player()->query_pct_weight()+"% of max.\n");
	return 1;
}
