hide(int chance) {
object shad,mons,room;
int z;
  if(etp->realm() == "NT") {
    write("You can not hide in shadows here.\n");
  return 1; }
  if(chance < random(100)) {
    write("You fail to hide in shadows.\n");
    say(capitalize(tpn)+" trips.\n");
    mons = all_inventory(etp);
    for(z=0;z<sizeof(mons);z++) {
      if(living(mons[z]) && mons[z] != tp && !mons[z]->id("messenger")) {
        if(mons[z] != find_player(mons[z]->query_real_name())) {
          if((tp->query_alignment() > 0 && mons[z]->query_alignment() < 100) ||
             (tp->query_alignment() < 100 && mons[z]->query_alignment() > 0)) {
               mons[z]->set_wc(mons[z]->query_wc() + 2); 
               mons[z]->attack_object(tp); }
        }
    }
  return 1; }
  room = etp;
  shad = clone_object("/players/mythos/myth/thief/spells/shad.c");
  shad->set_chance(chance);
  move_object(tp,shad);
  move_object(shad,room);
  write("You sink back into the shadows and disappear...\n");
  command("shad_help",tp);
return 1; }
  