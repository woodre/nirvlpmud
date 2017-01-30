TrainingMessage(str){
   string msg;
   msg = "Would you like to learn "+str+"?\n";
   if(str == "dino"){
      msg = "Congratulations!  You have done well during your initiation period\n"+
      "We would like you to become a true Power Ranger.\n"+
      "You will now have the power to bring justice and protection to Angel Grove\n"+
      "and the rest of Nirvana.  It is your responsibility to uphold the ideals\n"+
      "of the Power Rangers and apply them to everything you do.\n"+
      "Do you want to accept this responsibility and become\n"+
      "A member of the Power Rangers?  (yes/no)\n"+
      "";
   }
   if(str == "generate"){
      msg = "In order to use your abilities you need to have Power.\n"+
      "This Power comes from the Zeo Crystal.\n"+
      "The Zeo Crystal, however, can run out of power if it is not\n"+
      "recharged often.  You have the inner ability to recharge the crystal.\n"+
      "You can generate power by changing your spell points\n"+
      "into a form useful to the crystal.\n"+
      "Would you like to learn how to generate now?\n"+
      "";
   }
   if(str == "rwho"){
      msg = "You have been learning quickly.  I see the urgent need\n"+
      "to get you working with the other rangers.  As you know you\n"+
      "have a Communicator.  This is your link between yourself and\n"+
      "the other Power Rangers.\n"+
      "'rwho' will allow you to see all the other active Rangers.\n"+
      "'rt' will allow you to brodcast a message to all active Rangers.\n"+
      "'rte' allows the use of emotes.\n"+
      "Would you like to be able to use these Communicator options?\n"+
      "";
   }
   if(str == "thunder"){
      msg = "It looks like your enemies are becoming more powerful.\n"+
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
