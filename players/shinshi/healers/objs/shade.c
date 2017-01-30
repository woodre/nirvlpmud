object targ;
int flag;

id(str) {
return str == "heal_no_xp";
}

shadow_healer_on(object a) {
  if(!a) return 1;
  targ = a;
  flag = 0;
  shadow(targ,1);
  return 1;
}

shadow_healer_off() {
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

add_exp(arg) {
  /* 05/24/06 Earwax: added this */
  if (file_name(previous_object()) == "room/adv_guild" ||
    file_name(previous_object()) == "room/exlv_guild")
    targ->add_exp(arg);
  if(this_player()->query_level() > 20 && query_ip_number(this_player())) {
    tell_object(this_player(),"Please call add_xp(#) to change experience\n");
    return 1;
  }
return 1; }

/* New new exp formula by Illarion - 26 May 2014 */
/* Taken from the Healers guild for the Healers recode */

add_xp(int a)
{ 
    int chng, xl;
    object x, p;
    x = this_player();
    p = previous_object();

    /*if((x && (status)x->is_player() && (int)x->query_level() > 20) ||
       (p && file_name(p) == "players/shinshi/healers/objs/guilddaem")) {
      chng = 100;
    } else {
      xl = (int)targ->query_extra_level();
      chng = 10 + xl/4 + random(xl/4);
    }*/
    
    xl = (int)targ->query_extra_level();
    chng = 10 + xl/4 + random(xl/4);
    
    if(a > 0) a = (a * chng) / 100; 

#ifdef DOUBLEXPDAY
  a *= 2;
#endif
    if(present("double_xp_object", targ ))
      a *= 2;
    targ->add_exp(a); 
}

set_combat_flag(int b) { if(!b) flag = 0; else flag = b; }

query_combat_flag() { return flag; }

query_xpshadow() { return 1; }
