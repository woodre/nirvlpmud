static int pimping;
int
gen_wc_bonus()
{
   int ret_val;
    object e, x;
   ret_val = 0;
    if((e = environment()) && (x = (object)e->query_attack()) && !x->is_player())
    {

        if((int)x->query_alignment() < -333) ret_val += (-(1 + random(3)));
      else
        if((int)x->query_alignment() > 333) ret_val += (1 + random((int)e->query_guild_rank()));
  if(pimping) {
    int gr;
    gr = (int)environment()->query_guild_rank();
    ret_val += (- (8 - gr));
  }
    }

    return ret_val;
}

void player_attack()
{
  object e, room, atk;
  if(!(e=environment()) || !(room = environment(e)) ||
     !(atk=(object)e->query_attack()))
  {
    return;
  }
  
  tell_object(e, "PLAYER ATTACK CALLED\n");
  if((int)e->query_guild_rank() >= 4) {
    object wep;
    if(wep = (object)e->query_weapon()) {
      wep->hit(atk);
    }
    e->toggle_already_fight(0);
    pimping = 1;
    e->attack();
    pimping = 0;
  }
}

