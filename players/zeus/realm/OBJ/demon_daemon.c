#define SAVE_PATH "players/zeus/realm/doc/demon_kills/"


int kills;  /*  number of demons killed */
int time;   /*  time since .o was changed */

reset(arg) {
  if(arg) return;

call_out("scheck",1);
}

scheck() {
  if(environment(this_object())) destruct(this_object());
return 1; }

query_kills(object x)
{
  if(!x) return 0;
  if(!restore_object(SAVE_PATH+x->query_real_name()))
  {
    kills = 0;
    save_object(SAVE_PATH+x->query_real_name());
  }
  return kills;
}

add_kills(object x, int amount)
{
  if(!x) return 0;
  if(!amount) return 0;
  if(!restore_object(SAVE_PATH+x->query_real_name()))
    kills = 0;
  kills += 1;
  time = time();
  save_object(SAVE_PATH+x->query_real_name());
}

add_kills2(object x, int amount)
{
  int z;
  if(!x) return 0;
  if(!amount) return 0;
  if(!restore_object(SAVE_PATH+x->query_real_name()))
    kills = 0;
  if(sscanf(amount, "%d", z))
    kills += z;
  save_object(SAVE_PATH+x->query_real_name());
}

sub15(object x)
{
  if(!x) return 0;
  if(!restore_object(SAVE_PATH+x->query_real_name()))
    kills = 0;
  kills -= 15;
  time = time();
  save_object(SAVE_PATH+x->query_real_name());
}

sub45(object x)
{
  if(!x) return 0;
  if(!restore_object(SAVE_PATH+x->query_real_name()))
    kills = 0;
  kills -= 45;
  time = time();
  save_object(SAVE_PATH+x->query_real_name());
}
