extra_look(){
	if(this_player()){
		if(this_player() == USER) return "Type 'link' to see a listing of your powers";
		else BOLD+USER->query_name()+"'s "+COLOR+"Dark Matter"+NORM+BOLD+" Link"+NORM;
	}
}


short(){
	string all;
	int i,j,count;
   string woo;
	count = 0;
if(!sh_armors) return;
	for(j = 0; j < 8; j++){
		if(sh_armors[j]) count += 1;
	}
  if(count > 0) woo = BOLD+"Shaped Armors:\n"+NORM;
	for(i = 0; i < sizeof(sh_armors); i++){
		if(sh_armors[i]) woo += "     "+sh_armors[i]+" (shaped)\n";
   }
	return woo;
}
