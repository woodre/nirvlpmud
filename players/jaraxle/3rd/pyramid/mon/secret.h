/* make sure you do if(!player) return; checks in each function here */

secret1(player)
{

tell_object(player,"\nElder Mummy whispers: There is a demon in the pyramid.\n"+
      "A VERY dangerous creature at that...\n"+
      "He feeds off of the ignorance of the good hearted people\n"+
      "of Third Earth.\n");

call_out("secret1_2", 3,player);
}

secret1_2(player){

tell_object(player,"\nThe Elder Mummy looks about the room.\n");

call_out("secret1_3", 3,player);
}

secret1_3(player){

 tell_object(player,"\nIn the pyramid there is a secret cavern.\n"+
      "You can see this cavern by feeling the wall\n"+
      "where the air breezes through.\n"+
      "\tGood luck adventurer.\n"+
      "\t\tYou will need it.\n");
}

secret2(player)
{

tell_object(player,"\nThe Elder Mummy looks around the room.\n"+
      "The Elder Mummy whispers:  There is a great\n"+
      "evil lurking about in the Pyramid...\n");

call_out("secret2_2", 3,player);
}

secret2_2(player){

 tell_object(player,"\nThe Elder Mummy continues:  His evil goes unmatched\n"+
      "on Third Earth.  He loves for those after a heart like\n"+
      "his to give "+HIW+"sacrifice"+NORM+" for power.\n");

call_out("secret2_3", 5,player);
}

secret2_3(player){

 tell_object(player,"\nThe Elder Mummy speaks: If you "+HIW+"ask about"+NORM+" the \n"+
      ""+HIW+"sacrifice"+NORM+" I might be able to help\n"+
      "you along the dark path.\n");

}

