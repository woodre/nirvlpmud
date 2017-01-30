#define use_chan "gossip"
inherit "/obj/user/one_chan";
reset(arg) {
  object tp,ob;
  int i,pt,x,so;
  string high;
  tp = find_player("wizardchild");
  if(!tp) destruct(this_object());
  chan_msg("Wizardchild is launched from a catapult and goes flying across the mud!\n",
  use_chan);
  ob = users();
  so = sizeof(ob);
  for(i = 0; i < so; i++) {
   if(ob[i]->query_invis() > 50) continue;
    if(!random(4) && ob[i] != tp) {
      pt = random(50)+random(50);
      if(pt > x) { x = pt; high = ob[i]->query_name(); }
      tell_object(ob[i], "Wizardchild flies into the room, bounces off you, and flies off!\n");
      ob[i]->remote_say("Wizardchild flies into the room, bounces off "+ob[i]->query_name()+", and flies off!\n");
      chan_msg("  He *pings* off "+ob[i]->query_name()+" for "+pt+" points!\n",
      use_chan);
    }
  }
  chan_msg("  The high scorer is "+high+" for "+x+" points!\n",use_chan);
  tell_object(find_player(lower_case(high)), " You are the high scorer with "+x+" points!\n");
  call_out("self_dest",0);
}
self_dest() { destruct(this_object()); }
