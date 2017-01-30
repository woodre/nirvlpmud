inherit "room/room";	/*  ttop.c  */
#include "/players/zeus/closed/all.h"
#define QPS 12 /* qps value of quest   7/5 */
int teleport;

reset(arg){
	if(arg) return;

 teleport = 0;  if(random(2)) teleport = 1;

 short_desc="The top of Auseth's Tower";
 set_light(1);
 long_desc=
"You are standing on the top of Auseth's Tower, which is now the highest\n"+
"point in the forest of the Fallen Lands.  You can see for miles in every\n"+
"direction.  Vast fields of trees and grass lay before you.  The only\n"+
"safe way to go from here is back down the staircase.\n";
 items=({
   "trees",
"There are many trees all around, of various types.  Most of them aren't\n"+
"nearly as tall as the tower",
    "sky",
"The sky is a very beautiful blue, and stretches on for miles",
   "grass",
"Some lush looking grass can be seen from here in the distance",
   "fields",
"Fields of trees and grass can be seen off in the distance.  It all\n"+
"looks very beautiful",
   "staircase",
"The stone staircase leads back down into the tower",
   "tower",
"You are standing on the top of the tower.  It is for the most part flat\n"+
"and intact, despite all the growth around the tower",
 });
 dest_dir=({ "/players/zeus/realm/taus/tower7.c", "down", });
}

void init(){
	::init();
    add_action("banish_cmd", "banish");
}

exit(){    if(this_player()) this_player()->clear_fight_area(); }
realm(){   if(teleport) return "NT";  }

oon(object x){
  TR(TO,"\n"+x->QN+" holds the talisman in front of "+x->OBJ+".\n");
}

oot(object x){
  TR(TO,"\n"+x->QN+" whispers a soft phrase...\n");
}

oor(){
  TR(TO,"The wind blows over the tops of the trees...\n");
}

oog(){
  TR(TO,"\nThe talisman begins to glow softly...\n");
}

oom(){
  TR(TO,"\nThe talismans aura expands as it grows stronger...\n");
}

ook(object x){
  TR(TO,"\n"+x->QN+" is enfolded by the glowing yellow aura...\n");
}

ooba(object x){
  TR(TO,"\nThere is a sudden flash of light as the talisman shatters!\n"+
    "The glowing yellow aura engulfs "+x->QN+" and then is gone...\n\n");
  if(x->query_level() < 20)
    "/players/zeus/closed/fl_demon.c"->add_e(x->QRN);
}

oorla(object x){
  TR(TO,"\nTyborleks voice can be heard:\n"+
    "  Congratulations "+x->QN+", you've done a wonderful job.\n"+
    "  The talismans aura will forever protect you from the curse.\n");
}

oomfa(){
  TR(TO,"\nTyborleks voice can be heard:\n"+
    "  Also, to aid you in your path towards becoming a wizard...\n");
}

oomfma(object x){
  TR(TO,"\n"+x->QN+" receives "+QPS+" quest points.\n");
  x->set_quest("fallen_lands");
}

oobada(object x){
  TR(TO,"\nTyborleks voice can be heard:\n"+
    "  You are a strong warrior "+x->QN+", I am impressed.\n"+
    "  May lady luck always be on your side.\n");
}

omygod(){
  TR(TO,"A soft wind blows over the tops of the trees.\n");
}


banish_cmd(str){
  object ta;
  if(str != "curse") return 0;
  ta = present("zeus_quest_talisman", this_player());
  if(!ta) return 0;
  if(0 == ta->query_go()) return 0;
  if((string)this_player()->query_real_name() != ta->query_gz() &&
    (string)this_player()->query_real_name() != ta->query_goo() &&
    (string)this_player()->query_real_name() != ta->query_gt())
  {
    write("The talisman suddenly shatters in your hand.\n");
    destruct(ta);
    write_file("/players/zeus/log/Qsolve", ctime(time())+" -  "+
       capitalize((string)TP->QRN)+" solved but didn't kill demons.\n");
    return 1;
  }
  call_out("oon", 1, this_player());
  call_out("oot", 4, this_player());
  call_out("oor", 7);
  call_out("oog", 11);
  call_out("oom", 15);
  call_out("ook", 19, this_player());
  call_out("ooba", 23, this_player());
  call_out("oorla", 30, this_player());
  call_out("oomfa", 35);
  call_out("oomfma", 38, this_player());
  call_out("oobada", 44, this_player());
  call_out("omygod", 65);
  call_out("omygod", 160);
  write_file("/players/zeus/log/Q", ctime(time())+" -  "+
     capitalize((string)TP->QRN)+" solved the Fallen Lands quest.\n");
  write_file("/players/zeus/log/Qsolve", ctime(time())+" -  "+
     capitalize((string)TP->QRN)+" solved the Fallen Lands quest.\n");
  destruct(ta);
  return 1;
}




