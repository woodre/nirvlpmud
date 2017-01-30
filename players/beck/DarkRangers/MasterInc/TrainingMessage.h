TrainingMessage(str){
   string msg;
   msg = "Would you like to learn "+str+"?\n";
   if(str == "servant"){
      msg = "You have done well during your initiation period\n"+
      "We would like you to become a true Dark Ranger.\n"+
      "You will now have the power to bring down justice and protection to Angel Grove\n"+
      "and the rest of Nirvana.  It is your responsibility to destroy the ideals\n"+
      "of the Power Rangers and remove them from everything you do.\n"+
      "Do you want to accept this responsibility and become\n"+
      "A member of the Dark Rangers?  (yes/no)\n"+
      "";
   }
   if(str == "generate"){
      msg = "In order to use your abilities you need to have Power.\n"+
      "This Power comes from the Dark Crystal.\n"+
      "The Dark Crystal, however, can run out of power if it is not\n"+
      "recharged often.  You have the inner ability to recharge the crystal.\n"+
      "You can generate power by changing your spell points\n"+
      "into a form useful to the crystal.\n"+
      "Would you like to learn how to generate now?\n"+
      "";
   }
   if(str == "rwho"){
      msg = "You have been learning quickly.  I see the urgent need\n"+
      "to get you colaborating with the other dark rangers.  As you know you\n"+
      "have a Communicator.  This is your link between yourself and\n"+
      "the other Dark Rangers.\n"+
      "'rwho' will allow you to see all the other active Rangers.\n"+
      "'rt' will allow you to brodcast a message to all active Rangers.\n"+
      "'rte' allows the use of emotes.\n"+
      "Would you like to be able to use these Communicator options?\n"+
      "";
   }
   if(str == "warrior"){
      msg = "It looks like the Power Rangers are becoming more powerful.\n"+
      "I feel it is time to give you extra power to face the challenges\n"+
      "facing you.  I will upgrade your Dinozord to the latest technology.\n"+
      "The mighty Thunderzord.\n"+
      "Also I have developed a new way of going from one place to another\n"+
      "quickly.  I call this jetting.  Unlike teleport, you will be able to\n"+
      "see where you are as you move along, similar to flying.\n"+
      "To use this type 'jet' and the directions you want to travel in.\n"+
      "Would you like the power upgrades?\n"+
      "";
   }
   return msg;
}
