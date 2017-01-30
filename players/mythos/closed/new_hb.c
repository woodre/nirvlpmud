/* global */
static string *light_objects;
/* notice they are in order of availability - more torches than diseases */
/* in reset */
light_objects = ({"bubble","torch","light","posion","disease","processor",
                  "symbol"});
hb() {
  int muff;
  string hsch;
  int is_light;
  int z,aa,b,c,d;
  object rin;
  object tmp,otmp;
  int x;
  if(own) {
    md = (muff ? 1 : 0);
    /* this is actually quicker - present() runs through the inv once per 
       call, so the other way ran through the players inv 16 times */
    tmp = first_inventory(own);
    while(tmp) {
      for(x = 0; x < 7; x++) { /* 7 == sizeof(light_objects) */
        otmp = next_inventory(tmp);
        if(tmp->id(light_objects[x]))
          destruct(tmp);
        tmp = otmp;
      }
    }
    if((x = own->query_intoxination()) > 0)
      own->add_intoxination(-x);
/* what is "still"? remind me about this later :) */
    if(!present("still",own)) {
      move_object(this_object(),own); 
      md = muff;
    }
    if(talent) {  
      tides = call_other("/players/mythos/closed/guild/forest/misc/xb.c",
                         "query_day",0);
    } 
    rin = 0;
    aa = b = c = 0;
    hsch = 0;
    is_light = set_light(0);
    if(tmp = environment(own)) {
      if(hsch = tmp->short()) {
        if(sscanf(hsch,"%s hotel room",hsch) == 1) 
          is_light = 0; 
      } 
      if(!present("mailread",own)) { 
        if(present("dark_cloak",own)) 
          is_light = -1; 
        rin = all_inventory(tmp); /* tmp is still environment(own) */
/**** 
   Ok I do not see what aa b and c do here; their values aren't saved
   from call to call of hb. Maybe you intended them to be static?
*****/
        for(z=0, x=sizeof(rin); z < x; z++) {
          if(rin[z]->id("weather") && !aa) { aa = 1; is_light = 0; }
          if(rin[z]->id("myst") && !b) { b = 1; is_light -= 1; }
          if(rin[z]->id("darkness") && !c) { c = 1; is_light -= 2; }
        }
        if(own->query_interactive() && !own->query_ghost() && own->query_level() < 20) {
          if(is_light > 1) { 
            tell_object(own,
               "You feel great pain as light burns into you!\n");
          }
          if(is_light < -2 && own->query_hp() < own->query_mhp() ) { 
            tell_object(own,
               "You feel a cool touch as the darkness heals you.\n"); 
          }
          if(own->query_hp() - is_light > 0) { 
            own->heal_self(-(is_light)); 
          }
          if(own->query_hp() - is_light > 0) { 
            own->heal_self(-(is_light)); 
          } else { 
            command("drop all",own); 
            own->second_life();
          }
        } 
      } 
    }
    if(own->query_ghost() && !ggt) {
      move_object(clone_object("/players/mythos/closed/guild/death/ddeath.c"),own);
      ggt = 1;
    } 
  }
