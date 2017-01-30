
#define STIME 570+random(61)   /* 10 minutes - autosave */
#define NTIME 1770+random(61)  /* 30 minutes - new power check */
object *local_users;
string powers;
int x, ls, *costs;

reset(arg){
  if(arg) return;

  powers = ({ "beckon shadows", "wither corpse", "drain", "teleport",
    "shield", "weaken", "meditate", "web", "blast", "empower",
    "shadowform", "descend", "shadowcloak", "dark assistance",
    "repulsion", "vanish", "rage", "dark prayer", "weave", "see",
    "vigor", "embrace", });

  costs = ({ 50000, 100000, 250000, 450000, 600000, 750000, 950000, 1200000, 
    1500000, 1800000, 2100000, 2400000, 2700000, 3000000, 3300000, 
    3600000, 3900000, 4300000, 5000000, 5500000, 6000000, 7000000 });

call_out("scheck",1); 
call_out("autosave", STIME);
call_out("new_spell", NTIME);
}

scheck() {
  if(environment(this_object())) destruct(this_object());
return 1; }

autosave(){
  local_users = users();
  ls = sizeof(local_users);
  for(x = 0; x < ls; x++)
  {
    if(local_users[x]) /* added by verte */
    if(present("circle_object", local_users[x]) && 
      local_users[x]->query_level() < 21)
    {
      present("circle_object", local_users[x])->save_circle(1);
      /* command("csave", local_users[x]);     auto-save */
    }
  }
  call_out("autosave", STIME);
}

new_spell(){
  int a,b,c,xp;
  object cir;
  local_users = users();
  ls = sizeof(local_users);
  b = sizeof(powers);
  call_out("new_spell", NTIME);
  for(x = 0; x < ls; x++)
  {
    if(local_users[x]) { /* added by Vertebraker [6.2.01] */
    c = 0;
    cir = present("circle_object", local_users[x]);
    if(cir && local_users[x]->query_level() < 21)
    {
      xp = (int)cir->query_guild_exp();
      for(a=0; a < b; a++)
      {
        if(xp > costs[a] && !cir->qs(powers[a]) && !c)
        {
          tell_object(local_users[x], 
            "You feel the circle calling to you.\n");
          c = 1;
        }
      }
    }
  }
}
}

