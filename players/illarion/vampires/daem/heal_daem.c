/* Vampire Guild Heal Daemon
  The guild cannot use normal heals.  Instead they have their own tox
  pools and pool of funds.  when healing, they tox, and draw from the
  pool of funds.  coins and tox per heal is based on:
  /bin/soul/healcalc.c

 Max tox amount is based on their skill level in the skill corresponding
 to the the type of tox:
  player intox: ((level + 3) + (ex_lv / 5 + 1)) min 4 max 43
  player stuff/soak: (level * 8 + ex_lv * 2) min 8 max 352
  (Soak/stuff strength are automatically doubled by drink_soft and eat_food
   this is not done for vamp heals so the max is half)
  blood:   blood skill/3   min: 5 max 50
  energy:  telepathy*3/2   min:10 max 175 
  fear:    corruption*3/2  min:10 max 175

  Some abilities have a detox effect.  As per /doc/build/items/heals/heal1
  they cost 30coints/tox for the first two, and 60coins/pt for additional
  detox, to a max of -15
 
 */

/* cost of zero will prevent detox entirely */
detox_cost(int amt) {
  if(amt < 0) return 0;
  if(amt > 15) return 0;
  if(amt < 3) return amt *30;
  amt-=2;
  return 60 + amt*60;
}

/* cost of 0 will prevent healing entirely */
heal_cost(int amt, int tox)
{
  int cost;
  if(amt < 20 || amt > 50) return 0; 
  if(tox > 14 || tox < 5) return 0;
  
  return heal3_cost_calc(amt, tox);
}

heal3_cost_calc(amt, tox)
{
  int cost;

  switch(100*tox / amt)
  {
    case 40..1000: cost = 8;   break;
    case 35..39:   cost = 10;  break;     
    case 31..34:   cost = 11;  break;
    case 28..30:   cost = 12;  break;
    case 26..27:   cost = 13;  break;
    case 24..25:   cost = 14;  break;
    case 22..23:   cost = 15;  break;
    case 20..21:   cost = 16;  break;
    case 18..19:   cost = 17;  break;
    case 16..17:   cost = 18;  break;
    case 14..15:   cost = 20;  break;
    case 12..13:   cost = 22;  break;
    case 8..11:    cost = 30;  break;
    case 0..7:     cost = 40;  break;
  }
  return cost * amt;
}

void tox_table(int doses) {
  int x,y;
  if(!doses) doses = 1;
  write(pad("",3));
  for(y=5;y<16;y++) {
    write(pad(y+"",5));
  }
  write("\n");
  for(x=20*doses; x<=50*doses; x+=10*doses)
  {
    write(pad(x+"",3));
    for(y=5;y<16;y++)
    {
      write(pad(((int)heal3_cost_calc(x,y)/doses)+"",5));
    }
    write("\n");
  }
}



calc_tox_max(gob) {
  int b,t,c;
  b=gob->query_skill_info("level", "Sanguisugency");
  t=gob->query_skill_info("level", "Telepathy");
  c=gob->query_skill_info("level", "Corruption");
  if(b > 0) {
    b = 5 + b/3;
    if(b > 50) b = 50;
  } else b = 0;
  if(t > 0) {
    t=10 + t*3/2;
    if(t > 175) t = 175;
  } else t = 0;
  if(c > 0) {
    c=10 + c*3/2;
    if(c > 175) c = 175;
  } else c = 0;
  gob->set_tox_max(b, t, c);
}

/* Duplicates player.c intox regen code */
get_regen(type, usr) {
  object ob;
  int amt,cnt;
  ob = present(type+"_regen_object",usr);
  while(ob) {
    amt += (int)call_other(ob,"query_"+type+"_regen");
    cnt ++;
    ob = present(type+"_regen_object "+cnt,usr);
  }
  return amt;
}

mud_heal_attempt(usr, gob, str) {
  tell_object(usr, "You may no longer partake of mortal sustenance.\n");
}