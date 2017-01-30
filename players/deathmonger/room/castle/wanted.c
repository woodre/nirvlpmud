


string hitlist, name;

reset(arg){
   if(arg) return;
   set_light(0);
}

add_wanted_list(str){
   /* if you don't understand this, go out and shoot someone */
   int i, j;
   name = 0;
   restore_object("players/"+str);
   if(!name){
       return -1;
   }
   if(!hitlist[0]) hitlist[0] = str;
   else hitlist += ({ str });
   save_object("players/deathmonger/hitlist");
   return 1;
}

remove_wanted_list(str){
	string templist;
	int i;
   restore_object("players/deathmonger/hitlist");
   if(!member_array(str, hitlist)) return -1;
   templist = filter_array(hitlist, "removal", this_object(), str);
   hitlist = templist;
   write("Bing?\n");
   save_object("players/deathmonger/hitlist");
   return 1;
}

removal(name, str){
   if(str == 0) write("hmm str == 0\n");
   if(name == str) return 0;
   else return 1;
}

display_wanted_list(){
   int i;
   restore_object("players/deathmonger/hitlist");
   for(i=0;i<sizeof(hitlist);i++){
      write(capitalize(hitlist[i])+"\n");
   }
   return 1;
}

