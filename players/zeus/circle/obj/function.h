
/* powers */

dark_prayer(str){  if(MASTER->dark_prayer(str))  return 1;  else return 0; }
dark_assistance(){ if(MASTER->dark_assistance()) return 1;  else return 0; }
descend(str){      if(MASTER->descend(str))      return 1;  else return 0; }
deweave(str){      if(MASTER->deweave(str))      return 1;  else return 0; }
drain_spell(str){  if(MASTER->drain_spell(str))  return 1;  else return 0; }
drift(str){        if(MASTER->drift(str))        return 1;  else return 0; }
embrace(str){      if(MASTER->embrace(str))      return 1;  else return 0; }
empower(str){      if(MASTER->empower(str))      return 1;  else return 0; }
focus(){           if(MASTER->focus())           return 1;  else return 0; }
know(str){         if(MASTER->know(str))         return 1;  else return 0; }
meditate(){        if(MASTER->meditate())        return 1;  else return 0; }
new_invis(str){    if(MASTER->new_invis(str))    return 1;  else return 0; }
repulsion(){       if(MASTER->repulsion())       return 1;  else return 0; }
see(str){          if(MASTER->see(str))          return 1;  else return 0; }
shadowblast(str){  if(MASTER->shadowblast(str))  return 1;  else return 0; }
shadowcloak(){     if(MASTER->shadowcloak())     return 1;  else return 0; }
shadowform(){      if(MASTER->shadowform())      return 1;  else return 0; }
shadowrage(str){   if(MASTER->shadowrage(str))   return 1;  else return 0; }
shadowring(str){   if(MASTER->shadowring(str))   return 1;  else return 0; }
shadowweave(str){  if(MASTER->shadowweave(str))  return 1;  else return 0; }
siphon(str){       if(MASTER->siphon(str))       return 1;  else return 0; }
sshield(){         if(MASTER->shield())          return 1;  else return 0; }
summon(str){       if(MASTER->summon(str))       return 1;  else return 0; }
teleport(str){     if(MASTER->teleport(str))     return 1;  else return 0; }
vanish(){          if(MASTER->vanish())          return 1;  else return 0; }
vigor(str){        if(MASTER->vigor(str))        return 1;  else return 0; }
weaken(str){       if(MASTER->weaken(str))       return 1;  else return 0; }
wither_spell(str){ if(MASTER->wither_spell(str)) return 1;  else return 0; }

/* commands */

beckon(str){       if(MASTER->beckon(str))       return 1;  else return 0; }
c_monitor(str){    if(MASTER->c_monitor(str))    return 1;  else return 0; }
chelp_cmd(){       if(MASTER->chelp_cmd())       return 1;  else return 0; }
emote_cmd(str){    if(MASTER->emote_cmd(str))    return 1;  else return 0; }
remove_all(str){   if(MASTER->remove_all(str))   return 1;  else return 0; }
score_cmd(){       if(MASTER->score_cmd())       return 1;  else return 0; }
set_percent(str){  if(MASTER->set_percent(str))  return 1;  else return 0; }
set_title(str){    if(MASTER->set_title(str))    return 1;  else return 0; }
stop_casting(str){ if(MASTER->stop_casting(str)) return 1;  else return 0; }
who2_new(str){     if(MASTER->who2_new(str))     return 1;  else return 0; }

/* emotes */

battle_cry(){      if(MASTER->battle_cry())      return 1;  else return 0; }
fdraw(str){        if(MASTER->fdraw(str))        return 1;  else return 0; }
scoff_cmd(str){    if(MASTER->scoff_cmd(str))    return 1;  else return 0; }
shadow_wave(){     if(MASTER->shadow_wave())     return 1;  else return 0; }
stand(){           if(MASTER->stand())           return 1;  else return 0; }
wait_cmd(str){     if(MASTER->wait_cmd(str))     return 1;  else return 0; }

c_setmon(str) {      return (status)MASTER->c_setmon(str); }
