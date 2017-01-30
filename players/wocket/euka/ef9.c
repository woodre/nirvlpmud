#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;
int rockmoved;

reset(arg){
  rockmoved = 0;
  if(arg){ get_monsters();  return; }
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = "   "+
  "The worn path ends here.  Vines and ferns overgrow around the\n"+
  "large euka trees blocking all the directions.  Light still\n"+
  "manages to  filters down through the trees casting dappled\n"+
  "shadows everywhere.  A cool breeze rattles the green leaves.\n";
  dest_dir = ({
  EPATH+"ef8.c","northeast",
  });
   items = ({
    "ferns","Very large and green ferns that fan out over the path",
    "path","A worn path with soft dirt covering it",
    "light","Bright light that has filtered through the fern leaves",
    "sun light","Bright light that has filtered through the fern leaves",
    "birds","Bright and colorful with long tail feathers.  They sit up\nin the trees",
    "trees","Large Euka trees.  They have large green leaves that create\nshade everywhere.  There branches are smooth and thick",
    "vines","Green vines with sharp thorns",
    "brush","Scrubby bushes with sharp leaves and branches",
    "rock","A very large grey rock.  Perhaps you could 'lift' it\n",
    "tunnel","A dark tunnel leading down.  Perhaps you could 'enter' it.\n",
  });
  smells = ({
    "default","You smell the clean air and fresh sent of Euka trees",
  });
  listens = ({
    "default","You hear songs of birds and the rustle of leaves",
    "birds","You hear them chirping in the trees",
   });
  set_light(1);
  get_monsters();
 }

init(){
  ::init();
  add_action("search","search");
  add_action("lift","lift");
  add_action("enter","enter");
  add_action("nw","northwest");
}

search(str){
  if(str == "bushes"){
    write("As you search through the bushes you manage to find a faint\n"+
          "path leading to the northwest.\n");
    return 1;
  }
  if(str == "ferns"){
    write("As you search though the ferns you find a large rock.\n");
    return 1;
  }
  if(!str){
  notify_fail("What would you like to search?\n");
  return 0;
  }
  notify_fail("You find nothing of intrest.\n");
  return 0;
}

lift(str){
  if(str != "rock"){
    notify_fail("What would you like to lift?\n");
    return 0;
  }
  if(rockmoved){
    write("The rock has already been moved.\n");
    return 1;
  }
  if(random(20) < this_player()->query_attrib("str")){
    write("You manage to lift the rock and push it over uncovering\n"+
          "a tunnel.\n");
    say(TPN+" lifts up a rock and throws it to the side.\n");
    rockmoved = 1;
    return 1;
  }
  else{
    write("You strain to lift the rock but can't.\n");
    say(TPN+" tries to lift the rock up, but can't.\n");
    return 1;
  }
}

enter(str){
  if(str != "tunnel"){
    notify_fail("What would you like to enter?\n");
    return 0;
  }
  if(rockmoved){
    write("You enter the tunnel.\n\n");
    say(TPN+" leaves down a tunnel.\n");
    move_object(this_player(),EPATH+"efburrow.c");
    command("glance",this_player());
    say(TPN+" arrives.\n");
    return 1;
  }
  write("There is a large rock blocking the tunnel.\n");
  return 1;
}

nw(){
  this_player()->move_player("northwest#"+EPATH+"ef13.c");
  return 1;
}

get_monsters(){
int i;  
   if(random(3)==1){
    move_object(clone_object(EPATH+"NPC/snapper.c"),this_object());
   }
   i=0;
   while(random(3)==1 && i < 2){
    move_object(clone_object("/players/wocket/mushrooms/nonge.c"),this_object());
    i++;
   }
   i = 0;
   while(random(3)==1 && i < 2){
     move_object(clone_object("/players/wocket/graveyard/niblet.c"),this_object());
     i++;
   }
}
