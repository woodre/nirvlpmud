/*  clean up the room i'm in  [cause i'm messy]
*/
status clean_cmd(){
int i, c;
c = 0;
while(c < 2){
object *wr;
 wr = all_inventory(environment(environment()));
  for(i=0; i<sizeof(wr); i++) {
   if(!wr[i]->is_player() || wr[i]->is_npc()){ destruct(wr[i]); }
 }
 c++;
}
 tell_room(environment(environment()), environment()->query_name()+
	 " waves a hand as shadows rise up from the ground.\n");
  return 1; 
}

