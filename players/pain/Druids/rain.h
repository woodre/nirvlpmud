/*
	This is the function definition for the Rain Nature Spell
	for the Monks of the Hidden Path

	note a_mod is the attack spell modifier
*/

rain() {
   object attack;
   string a_name;
   int roll;

   if(a_mod < 10) {
      write(train_fail);
      return 1;
   }

   if(member->query_attack() == 0) {
      write("You must be in battle to use this spell.\n");
      return 1;
   }

   if(tps < 35) {
      write(spirit_fail);
      return 1;
   }

   attack = member->query_attacker();
	if(attack->query_npc() == 0) {
      write("You can not call for a rain storm on a player.\n");
      return 1;
   }

   a_name = attack->query_name();
   write("You call for a Rain Storm from Mother Nature.\n");
   say(tpn+" calls for a Rain Storm from Mother Nature.\n");
   member->add_sp(-50-a_mod/2);
   roll = a_mod+random(70);
   if(roll < 30 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the arm.\n");
      a_name->hit_player(10);
      return 1;
   }
   if(roll < 30 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 30 && m_gl > 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
   }
   if(roll < 70 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the leg.\n");
      a_name->hit_player(13);
      return 1;
   }
   if(roll < 70 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the forehead.\n");
      a_name->hit_player(18);
      return 1;
   }
   if(roll < 70 && m_gl > 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" on the neck.\n");
      a_name->hit_player(22);
      return 1;
   }
   if(roll < 101 && m_gl < 4) {
      write(a_name+"'s weapon slips and nicks "+a_name+" in the forehead.\n");
      a_name->hit_player(18+random(m_mag));
      return 1;
   }
   if(roll < 101 && m_gl < 7) {
      write(a_name+"'s weapon slips and nicks "+a_name+" in the neck.\n");
      a_name->hit_player(22+random(m_mag));
      return 1;
   }
   if(roll < 101 && m_gl > 7) {
      write(a_name+"'s eyes grow large as "+a_name+"'s weapon slips "+
	    "and\n nicks"+a_name+" in the groin!\n");
      a_name->hit_player(25+random(m_mag));
      return 1;
   }
}
