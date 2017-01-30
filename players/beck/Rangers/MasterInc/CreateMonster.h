string *RangerMonsters;
mapping RangerMonsterPaths;
int RangerMonstersNumber;

SRangerMonsters(str){
   RangerMonsters = ({ "soccerdillo","goldar","octophantom","stagbeetle","saliguana","witchblade","robogoat","snizard","pirantishead", });
   RangerMonstersNumber = 9;
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
         "goldar":"/players/beck/DarkRangers/Npc/Goldar.c",
         "stagbeetle":"/players/beck/Rangers/Mons/Stagbeetle.c",
         "pirantishead":"/players/beck/Rangers/Mons/Pirantishead.c",
         "snizard":"/players/beck/Rangers/Mons/Snizard.c",
         "saliguana":"/players/beck/Rangers/Mons/Saliguana.c",
         "robogoat":"/players/beck/Rangers/Mons/Robogoat.c",
         "witchblade":"/players/beck/Rangers/Mons/Witchblade.c", ]);
   if(RangerMonstersNumber){
      i = sizeof(RangerMonsters);
      i = random(i);
      monster = RangerMonsters[i];
      move_object(RangerMonsterPaths[monster],pathname);
      tell_room(pathname,"The "+capitalize(monster)+" appears in a flash of light.\n");
CHANNEL->ChannelMessage("Power Ranger","["+BOLD+RED+" ENEMY "+OFF+"] Zordon says: The "+capitalize(monster)+" has appeared at "+room+"\n");
      RRangerMonsters(monster);
      RangerMonstersNumber -= 1;
   }
}
