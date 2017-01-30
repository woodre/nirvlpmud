static string *t0,*t1,*t2,*t3,*t4,*t5,*t6,*t7,*t8; /* title arrays */

reset(arg){
  if(arg) return;

  t0 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", });
  t1 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller", "Sand Scourge", });
  t2 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", });
  t3 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf", 
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter", });
  t4 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf",
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter",
         "Masterful Desert Nomad", "Desert Wolf", "Bloodfist Hunter", });
  t5 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf",
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter",
         "Masterful Desert Nomad", "Desert Wolf", "Bloodfist Hunter",
         "Scorpion Hunter", "Skilled Nomadic Hunter", "Skilled Bloodfist Hunter", });
  t6 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf",
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter",
         "Masterful Desert Nomad", "Desert Wolf", "Bloodfist Hunter",
         "Scorpion Hunter", "Skilled Nomadic Hunter", "Skilled Bloodfist Hunter",
         "Desert Warrior", "Bloodfist Warrior", "Nomadic Warrior", });
  t7 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf",
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter",
         "Masterful Desert Nomad", "Desert Wolf", "Bloodfist Hunter",
         "Scorpion Hunter", "Skilled Nomadic Hunter", "Skilled Bloodfist Hunter",
         "Desert Warrior", "Bloodfist Warrior", "Nomadic Warrior","Desert Scorpion",
         "Seasoned Mercenary", "Nomadic Mercenary", "Master Bloodfist Warrior", });
  t8 =({ "Nomad", "Bloodfist", "Vagabond", "Outcast", "Dune Dweller",
         "Sand Scourge", "Scarred Survivalist", "Sand Fox", "Sand Wolf",
         "Experienced Nomad", "Bloodfist Hunter", "Nomadic Hunter",
         "Masterful Desert Nomad", "Desert Wolf", "Bloodfist Hunter",
         "Scorpion Hunter", "Skilled Nomadic Hunter", "Skilled Bloodfist Hunter",
         "Desert Warrior", "Bloodfist Warrior", "Nomadic Warrior","Desert Scorpion",
         "Seasoned Mercenary", "Nomadic Mercenary", "Master Bloodfist Warrior",
         "Desert Predator", "Bloodstained Predator", "Nomadic Predator",
         "Legendary Bloodfist Warrior", });

  call_out("scheck",1); 
}

scheck() {
  if(environment(this_object())) destruct(this_object());
return 1; }

mixed query_titles(int lvl)
{
  string a;
  if(lvl == 0) return t0;
  else if(lvl == 1) return t1;
  else if(lvl == 2) return t2;
  else if(lvl == 3) return t3;
  else if(lvl == 4) return t4;
  else if(lvl == 5) return t5;
  else if(lvl == 6) return t6;
  else if(lvl == 7) return t7;
  else if(lvl == 8) return t8;
  else return 0;
}
