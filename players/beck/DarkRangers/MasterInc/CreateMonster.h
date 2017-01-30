string *RangerMonsters;
mapping RangerMonsterPaths;
int RangerMonstersNumber;

SRangerMonsters(str){
   RangerMonsters = ({ "soccerdillo","octophantom","stagbeetle", });
   RangerMonstersNumber = 3;
}

ARangerMonsters(str){
   RangerMonsters += ({ str });
}

RRangerMonsters(str){
   RangerMonsters -= ({ str });
}

/*
     This allows a random monster to be moved to a room that calls this function.
     Each monster is only allowed once per reboot.
*/
CreateMonster(string name, string room, string pathname){
   int i;
   string monster;
   RangerMonsterPaths = (["soccerdillo":"/players/beck/Rangers/Mons/Soccerdillo.c",
   "octophantom":"/players/beck/Rangers/Mons/Octophantom.c",
   "stagbeetle":"/players/beck/Rangers/Mons/Stagbeetle.c" ]);
   if(RangerMonstersNumber){
      i = sizeof(RangerMonsters);
      i = random(i);
      monster = RangerMonsters[i];
      move_object(RangerMonsterPaths[monster],pathname);
      tell_room(pathname,"The "+capitalize(monster)+" appears in a flash of light.\n");
      RangerMessage("all","Zordon says: The "+capitalize(monster)+" has appeared at "+room);
      RRangerMonsters(monster);
      RangerMonstersNumber -= 1;
  }
}
