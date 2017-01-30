int mobs;


id(str){ return str == "contwardaemon"; }

reset(arg){
   if(arg) return;
   mobs = 5000;
   restore_object("players/maledicta/cont/war");   
   mobs += random(30);
}

dest_me(){
	destruct(this_object());
	return 1;
}

query_mobs_left(){ return mobs; }

sub_mob(){ 
mobs -= 1;
save_object("players/maledicta/cont/war");
}

reset_mob(){
mobs = 5000;
save_object("players/maledicta/cont/war");
return 1;
}

