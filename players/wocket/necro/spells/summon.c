#include "../defs.h"

cmd(str){
  if(!str){
    notify_fail("What would you like to summon?\n");
    return 0;
  }
  if(str == "ghastly stench") return gstench();
  if(str == "death fog") return 1;
  if(str == "pestilence") return pestilence();
  notify_fail("That is not something you know how to summon.\n");
  return 0;
}

gstench() {
object ob;
string c, room,msg;
ob = GOB;
  
  if(!GOB->checklev(4,8)) return 1;
  
  /* 05/18/06 Earwax: laf, why was this changed? */
  /* 
  if(!(creator(environment(tp))))
  {
    notify_fail("Something prevents that from being cast here.\n");
    return 0;	
  }  
  */
  
  if(tp->query_sp() < 20) {
    notify_fail("You do not have the spell points available for this spell.\n");
    return 0;
  }
  if((ob->query_blood() < 4) || (ob->query_eye() < 1)){
    notify_fail("You do not have the spell components available for the spell.\n");
    return 0; 
  }
  msg = "You channel energy from the Realm of Death into your spell as you drown\n"+
        "an eye in blood.\n";
  if(BLOODMOON) {
    msg+=ROD+"The Bloodmoon increases the power of your spell.\n";
  }
  if(GRAVESITE) {
    msg+=ROD+"The Graveyard increases the power of your spell.\n";
  }
  write(msg);
  c=file_name(tp);
  room=file_name(environment(tp));
  call_out("summonstench",3,c+"|"+room);
  tp->add_spell_point(-20);
  ob->add_val(1);
  ob->add_blood(-4);
  ob->add_eye(-1);
  ob->save_me();
  return 1; 
}

summonstench(str){
string *things;
object g,who,where;
int t,l;
  things = explode(str,"|");
  who = find_object(things[0]);
  where = find_object(things[1]);
  if(who && where){    
   l = who->query_guild_rank();
    if(present("bloodmoon",where))
      l+1;
    t = who->query_guild_rank()*4;
    if(present("gsite_ob",where) || where->gravesite())
      t+1;
    g = clone_object(OBJ+"/spells/gstench.c");
    g->set_creator(who); 
    g->set_level(l);
    g->set_time(t);
    tell_room(where,GRN+"A thick green stench rises from the ground.\n"+OFF);
    move_object(g,where);
    g->do_stench_damage();
  }
}


pestilence(){
object ob,cost;
string room,msg;
string c;
ob = GOB;
cost = 100;  
  if(!GOB->checklev(7,13)) return 1;  
  
  if(!(creator(environment(tp))))
  {
    notify_fail("Something prevents that from being cast here.\n");
    return 0;	
  }
  
  if(BLOODMOON) {
    msg+=ROD+"The Bloodmoon decreases the cost of your spell.\n";
    cost = cost - 5;
  }
  if(GRAVESITE) {
    msg+=ROD+"The Graveyard decreases the cost of your spell.\n";
    cost = cost -5;
  }
  if(tp->query_sp() < cost) {
    notify_fail("You do not have the spell points available for this spell.\n");
    return 0;
  }
  if( !present("corpse dust",this_player()) ){
    notify_fail("You do not have any corpse dust to use for this spell.\n");
    return 0;
  }
  if(present("corpse dust",this_player())->query_dust() != "daranath"){
    notify_fail("You do not have real corpse dust.\n");
    return 0;
  }
  write("You begin to chant the summoning of death to the Realm of the Dead as you\n"+
        "gently blow the corpse dust from your hands. The air begins to turn cold\n"+
        "as wind swirls around you.\n");
  say(tpn+" chants something and blows dust into the wind.  The air turns cold around you.\n");
  destruct(present("corpse dust",this_player()) );
  ob->add_val(2);
  tp->add_spell_point(-cost);
  call_out("summonpest",3,tp);
  return 1;
}


summonpest(player){
int i,a,lev;
object *ppl;
  if(player){
  ppl = all_inventory(environment(player));
  tell_room(environment(player),BOLD+BLK+"The seeds death fly in on the wind.\n"+OFF); 
  lev = player->query_level();
  for(i=0, a=sizeof(ppl);i<a;i++) {
    if(living(ppl[i])){
     if(ppl[i]->query_npc()){
        if( random(lev) > ppl[i]->query_level() ){
            ppl[i]->death();
        }
        else{
         ppl[i]->attacked_by(player);
        }
     }
     if(ppl[i] == player){
       if(random(lev) > random(lev)){
         tell_object(ppl[i],"You choke upon the death seeds.\n");
         ppl[i]->death(); 
       }
     }
    }
  }
  }
}
