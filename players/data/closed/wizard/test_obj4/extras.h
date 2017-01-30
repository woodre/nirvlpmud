query_weight(){ if(offhand_wght) return offhand_wght; else return 0; } query_value(){ return 0; } drop(){ return 1; } get(){ return 1; }
no_spell(){ return 0; }

new_quit(){
	if(offhand) command("offhand", USER);
	save_prof();
        set_gld_exp();
	return;
}

query_auto_load(){
	save_object(SAVE_PATH+USERRN);
	return PATH+"gobj.c:";
}

set_gld_exp() {
  int y;
  if(glvl < 40)
    y=compute_comp(glvl);
  if(glvl == 40)
    y=query_totexp();
  if(glvl > 40){
    int i;
    y=query_totexp();
    for(i=41;i<glvl;i++)
    y+=500000;
    }
  if(glvl==41) {
    y+=500000;
  }
    USER->set_guild_exp(y);
}
int query_totexp() { 
  int totexp;
  int sz;
  sz=sizeof(exp_to_level);
  while(sz--)
  totexp += exp_to_level[sz];
  return totexp; 
}   

int compute_comp(int glv)
{
  int x;  
  x=exp_to_level[glv];
  while(glv--)
    x+=exp_to_level[glv];
  return x;
}

