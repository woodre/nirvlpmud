string *Npcs;
mapping NpcPaths;
int NpcNumber;

void
SNpc(){
   NpcPaths = (["soccerdillo":"/players/beck/Rangers/Mons/Soccerdillo.c",
         "octophantom":"/players/beck/Rangers/Mons/Octophantom.c",
         "goldar":"/players/beck/DarkRangers/Npc/Goldar.c",
         "stagbeetle":"/players/beck/Rangers/Mons/Stagbeetle.c",
         "invenusable flytrap":"/players/beck/monster/inv_flytrap.c" ]);
   Npcs = ({ "soccerdillo","goldar","octophantom","stagbeetle", });
   NpcNumber = 4;
}


ANpcs(str){
   Npcs += ({ str });
}

RNpcs(str){
   Npcs -= ({ str });
}

void
CreateNpc(string npc_name, string room_desc, string room_path){
   move_object(NpcPaths[npc_name],room_path);
   if(member_array(npc_name,Npcs) != -1 ){
      RNpcs(npc_name);
      NpcNumber -= 1;
   }
}
/*
This allows a random monster to be moved to a room that calls this function.
Each monster is only allowed once per reboot.
*/

void
CreateRandomNpc(string room_desc, string room_pathname){
   int i;
   string npc;
   
   if(NpcNumber){
      i = sizeof(Npcs);
      i = random(i);
      npc = Npcs[i];
      move_object(NpcPaths[npc],room_pathname);
/*      
      tell_room(pathname,"The "+capitalize(npc)+" appears in a flash of light.\n");
      RangerMessage("all","Zordon says: The "+capitalize(npc)+" has appeared at "+room);
*/      
      RNpcs(npc);
      NpcNumber -= 1;
   }
}
