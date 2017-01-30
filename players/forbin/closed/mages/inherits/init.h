void init() {
  if(!environment()) return;
  if(!this_player()->is_player()) return;

  if((int)this_player()->query_level() > 19
    && (string)this_player()->query_real_name() != "fred"
    && (string)this_player()->query_real_name() != "forbin"
    && (string)this_player()->query_real_name() != "vertebraker"
    && (string)this_player()->query_real_name() != "boltar") {
    destruct(this_object());
    return;
  }

  Schools         = allocate(8);
  SchoolsBonus    = allocate(8);
  Attribs         = allocate(4);
  AttribsBonus    = allocate(4);
  /* Total exp of 4,500,000 to max schools - equivalent of 30,000,000 game exp */
  SchoolsCosts = ({ 0, 5, 10, 20, 30, 40, 50, 75, 100, 125, 150, 175, 
                    200, 225, 250, 275, 300, 350, 400, 450, 500, 550, 
                    600, 650, 700, 750, 800, 850, 900, 950, 1000, 1075, 
                    1150, 1225, 1300, 1375, 1450, 1525, 1600, 1675, 
                    1750, 1825, 1900, 1975, 2050, 2125, 2200, 2275, 
                    2350, 2425, 2500, 2600, 2700, 2800, 2900, 3000, 
                    3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 
                    3900, 4000, 4125, 4250, 4375, 4500, });
  /* Total exp of 2,000,000 to max attributes - equivalent of 20,000,000 game exp */                    
  AttribsCosts = ({ 0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 175, 
                    200, 225, 250, 275, 300, 350, 400, 450, 500, 600, 
                    700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 
                    1600, 1700, 1800, 1900, 2000, });

  if(this_player()->query_level() < 20)  /* set login to mage tower */
    this_player()->set_home("/players/forbin/mages/rooms/towlog.c");

  if(!restore_gob()) save_gob();  /* restore guild stats */
  advance_checks();  
  
  c = sizeof(spells = files(CMDDIR + "*.c"));  /* add guild commands */
  while(c--) {
    sscanf(spells[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
