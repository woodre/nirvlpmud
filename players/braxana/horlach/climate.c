string who;
int count;
id(str) { return str == "climate"; }

short() { return "Climate Control"; }

reset(arg) {
  if(arg) return;
  who = ({"mythos","braxana"});
  count = 0;
  set_heart_beat(1);
  call_out("moo",2);
}

moo() { if(!environment(this_object())) { destruct(this_object()); return 1; } }

heart_beat() {
object ob,meow,spot;
int h;
 if(count > 100 + random(100)) { 
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
    if(meow = environment(ob[h])) {
      if(ob[h]->query_level() < 20) {
        if(!meow->realm()) {  
           spot=clone_object("/players/braxana/horlach/climate_shadow.c");
           if(random(3)) spot->set_specs("NM");
           else spot->set_specs("NT");
           spot->start_climate_shadow(meow);
           tell_room(meow,"\n\n\tThe area shakes!\n\t\tDirt flies about!\n"+
                  "\t\t\tYou Tremble as you wait for the Earthquake to subside!!\n\n");
        }
      }
  } }
  count = 0; }
  count = count + 1;
}