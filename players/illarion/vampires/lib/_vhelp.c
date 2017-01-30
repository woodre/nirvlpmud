#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([]);
}

main(str, targ, usr, gob) {
  string helpfile,libfile;
  string skill;
  int hsize,lsize;

  if(!str) str = "default";
  
  helpfile = DOC + str;
  hsize = file_size(helpfile);
  libfile = LIB + "_" + str + ".c";
  lsize = file_size(libfile);
  
  if(hsize <= 0 && lsize <= 0)
    FAIL("No help available for "+str+".\n");
  

  if(lsize > 0)
  {
    string *req_keys;
    mixed req;
    mixed cmp;
    int x,s;
    req = libfile->query_requirements();
    req_keys = keys(req);
    s=sizeof(req_keys);
    write("Vampire Ability: "+str+"\n-------------------------------------------\n");
    if((skill = libfile->query_skill())) {
      write("Skill Used: "+skill+"\n");
    }    
    if(req["skill"]) {
        write(req["skill"][0]+ " Required: "+req["skill"][1]+"\n");    
    }
    if(req["sp"]) {
      write("Spell Points: " + req["sp"][0] + "\n");
    }
    if(req["debuff"]) {
      write("Required Effect: "+capitalize(req["debuff"][0])+"\n");
    }
    if(req["btox"]) {
      cmp = req["btox"][0];
      if(cmp == 0)
        write("Generates Blood Energy.\n");
      else
        write("Consumes Blood Energy.\n");
    }
    if(req["ttox"]) {
      cmp = req["ttox"][0];
      if(cmp == 0)
        write("Generates Telepathic Energy.\n");
      else
        write("Consumes Telepathic Energy.\n");
    }
    if(req["ctox"]) {
      cmp = req["ctox"][0];
    if(cmp == 0)
      write("Generates Corruption Energy.\n");
    else
      write("Consumes Corruption Energy.\n");
    }
    if(req["tox_tribute"]) {
      cmp = HEALDAEM->heal_cost(req["tox_tribute"][0], gob->query_tox_pref());
      if(cmp == 0) {
        write("Illegal heal or tox rate.\n");
      }
      write("Guild Tribute: "+cmp+"\n");
    }
    if(req["tribute"]) {
      write("Guild Tribute: "+req["tribute"][0]+"\n");
    }
    if(req["gold"]) {
      write("Gold Coins: "+req["gold"][0]+"\n");
    }
    if(req["level"]) {
      write("Player Level: "+req["level"][0]+"\n");
    }
    if(req["xlevel"]) {
      write("Extra Level: "+req["xlevel"][0]+"\n");
    }
    if(req["bloodpts"]) {
      write("Blood Points: "+req["bloodpts"][0]+"\n");
    }
    if(req["glevel"]) {
      write("Guild Level: "+req["glevel"][0]+"\n");
    }
    if(req["min_humanity"]) {
      write("Humanity Above"+req["min_humanity"][0]+"\n");
    }
    if(req["max_humanity"]) {
      write("Humanity Below "+req["max_humanity"][0]+"\n");
    }
    if(hsize > 0) {
      write("-------------------------------------------\n");
      cat(helpfile);
    }
  } else {
    write("Vampire Information: "+capitalize(str)+"\n-------------------------------------------\n");
    cat(helpfile);
  }
    write("-------------------------------------------\n");
  return 1;
}