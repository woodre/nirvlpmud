
string *legit;

reset(arg) {
  if(arg) return;
 legit = allocate(8);
 legit[0] = "players/llew/Toys/";
 legit[1] = "players/anshar/forest/";
 legit[2] = "players/hurtbrain/castello/gang/";
 legit[3] = "players/snow/newbie/";
 legit[4] = "players/feldegast/island/";
 legit[5] = "players/languilen/fun/";
 legit[6] = "players/catt/AREAS/TEMPLE/";
 legit[7] = "players/boltar/santaland/";
call_out("scheck",1);
}

scheck() {
  if(environment(this_object())) destruct(this_object());
return 1; }


check(){
  string y;
  int x;
  for(x = 0; x < sizeof(legit); x++){
	if(sscanf(file_name(environment(this_player())), 
		legit[x]+"%s", y))
		return 1;
  }
  return 0;
}

/*  
if(!"/players/zeus/newbie/check.c"->check()) return 1;
*/
