/*
	This is the function definition for the chill touch attack spell
	for the Monks of the Hidden Path

	note that a_mod is the attack spell modifier

*/

ctouch(str) {
   object attack;
   string a_name;
   int roll;
   if(a_mod < 5) {
	write(train_fail);
	return 1;
   }
   if(!str) {
      write("Whom do you wish to grasp?\n");
      return 1;
   }
   attack = present(str,environment(member));
   if(!attack) {
      write("That monster is not in the room!\n");
      return 1;
   }
   if(attack->query_npc() == 0) {
      write("You cannot grasp another player!\n");
      return 1;
   }

   if(tps < 40) {
	write(spirit_fail);
	return 1;
   }
   member->add_sp(-40-a_mod/2);
   a_name = attack->query_real_name();
   write("You reach out to grasp "+a_name()+".\n");
   say(m_name+" grasps "+a_name+" with an icy hand.\n");
   roll = a_mod+random(70);
   if(roll < 20 && m_gl < 3) {
      write(a_name+" is chilled by your grasp.\n");
      a_name->hit_player(7);
      return 1;
   }
   if(roll < 20 && m_gl < 5) {
      write("You freeze "+a_name+" with your grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 20 && m_gl < 8) {
      write(a_name+" quivers under your grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 20 && m_gl > 7) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 50 && m_gl < 3) {
      write("You freeze "+a_name+" with your grasp.\n");
      a_name->hit_player(12);
      return 1;
   }
   if(roll < 50 && m_gl < 5) {
      write(a_name+" quivers under your grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 50 && m_gl < 8) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 50 && m_gl > 7) {
      write(a_name+" is thrown back by your icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 85 && m_gl < 3) {
      write(a_name+" quivers at your icy grasp.\n");
      a_name->hit_player(15);
      return 1;
   }
   if(roll < 85 && m_gl < 5) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 85 && m_gl < 8) {
      write(a_name+" is thrown back by your icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 85 && m_gl > 7) {
      write(a_name+"'s soul is frozen by your icy grasp.\n");
      a_name->hit_player(30);
      return 1;
   }
   if(roll < 101 && m_gl < 3) {
      write(a_name+"'s flesh freezes at your icy grasp.\n");
      a_name->hit_player(20);
      return 1;
   }
   if(roll < 101 && m_gl < 5) {
      write(a_name+" is thrown back by your icy grasp.\n");
      a_name->hit_player(25);
      return 1;
   }
   if(roll < 101 && m_gl < 8) {
      write(a_name+"'s soul is frozen by your icy grasp.\n");
      a_name->hit_player(30);
      return 1;
   }
   if(roll < 101 && m_gl > 7) { 
      write("You devestate "+a_name+" with your icy grasp!\n");
      a_name->hit_player(20+random(a_mod));
      return 1;
   }
}

