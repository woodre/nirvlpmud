extra_look()
{
 if(this_player())
 {
   if(this_player() == USER)
   { 
     if(shaped)
       return "Your arm is shaped into a "+shaped_form+".\n"+
              "Type 'link' to see a listing of your powers";
     
     return "Type 'link' to see a listing of your powers";
   }
   if(shaped)
     return USER->query_name()+"'s arm is shaped into a "+shaped_form+".\n"+
            BOLD+USER->query_name()+"'s "+HIK+"Dark Matter"+NORM+BOLD+" Link"+NORM;

   return BOLD+USER->query_name()+"'s "+HIK+"Dark Matter"+NORM+BOLD+" Link"+NORM;
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
