void init()
{
  if(!environment()) return;
  if(!this_player()->is_player()) return;

  if((int)this_player()->query_level() > 19
    && (string)this_player()->query_real_name() != "fred"
    && (string)this_player()->query_real_name() != "forbin"
    && (string)this_player()->query_real_name() != "zeus"
    && (string)this_player()->query_real_name() != "vertebraker"
    && (string)this_player()->query_real_name() != "illarion"    
    && (string)this_player()->query_real_name() != "boltar") 
  {
    destruct(this_object());
    return;
  }
  
  GuildLevel = 1;
  AttribsLvl = 1;
  AttribsPts = 10;
  SchoolsLvl = 1;
  SchoolsPts = 10;
  GuildColor = NORM+MAG;
  Schools         = ([ "abju" : 0, "conj" : 0, "ench" : 0, "evoc" : 0,
  	                   "divi" : 0, "illu" : 0, "necr" : 0, "tran" : 0, ]);
  SchoolsBonus    = ([ "abju" : 0, "conj" : 0, "ench" : 0, "evoc" : 0,
  	                   "divi" : 0, "illu" : 0, "necr" : 0, "tran" : 0, ]);
  Attribs         = ([ "power" : 0, "will power" : 0, 
  	                   "intelligence" : 0, "wisdom" : 0, ]);
  AttribsBonus    = ([ "power" : 0, "will power" : 0, 
  	                   "intelligence" : 0, "wisdom" : 0, ]);
  LearnedAbju = LearnedConj = LearnedEnch = LearnedEvoc = ({ });
  LearnedDivi = LearnedIllu = LearnedNecr = LearnedTran = ({ });
  LearnedOne = LearnedTwo = LearnedThree = LearnedFour = ({ });
  LearnedFive = LearnedSix = LearnedSeven = ({ });
  /* Total of 5,100,000 converted exp needed to max glevel */
  /* players start @ level 1 (so 0 & 1 positions in array are zero) */
  GuildLevelCosts = ({ 0, 0, 100000, 300000, 700000, 1500000, 3100000, 5100000, });
  SizeofGLC = sizeof(GuildLevelCosts);
  /* Total exp of 4,500,000 to max schools - equivalent of 30,000,000 game exp */
  /* players start with 10 pts (so 0 position in array are zero) */  
  SchoolsCosts = ({ 0, 0, 5, 10, 20, 30, 40, 50, 75, 100, 125, 150, 175, 
                    200, 225, 250, 275, 300, 350, 400, 450, 500, 550, 
                    600, 650, 700, 750, 800, 850, 900, 950, 1000, 1075, 
                    1150, 1225, 1300, 1375, 1450, 1525, 1600, 1675, 
                    1750, 1825, 1900, 1975, 2050, 2125, 2200, 2275, 
                    2350, 2425, 2500, 2600, 2700, 2800, 2900, 3000, 
                    3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 
                    3900, 4000, 4125, 4250, 4375, 4500, });
  SizeofSC = sizeof(SchoolsCosts);                    
  /* Total exp of 2,000,000 to max attributes - equivalent of 20,000,000 game exp */
  /* players start with 10 pts (so 0 position in array are zero) */
  AttribsCosts = ({ 0, 0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 175, 
                    200, 225, 250, 275, 300, 350, 400, 450, 500, 600, 
                    700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 
                    1600, 1700, 1800, 1900, 2000, });
  SizeofAC = sizeof(AttribsCosts);                    
                    
  if(!this_player()->query_mage_player_shadow())  /* shadow player */
  {
    mageshadow = clone_object(DIR+"obj/mage_shadow.c");
    mageshadow->set_mage_player_shadow(this_player());
  }
                    
/*
  if(this_player()->query_level() < 20)   set login to mage tower 
    this_player()->set_home("/players/forbin/mages/rooms/towlog.c");
*/
  if(!restore_gob()) { save_gob(); }
  advance_checks();  

  c = sizeof(cmds = files(CMDDIR + "*.c"));  /* add guild commands */
  while(c--) 
  {
    sscanf(cmds[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
}
