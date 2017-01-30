/* look.h */
/* part of ghall.c */


status look_cmd(string str){
  if(!str)
    return 0;
  if(str == "at writing" || str == "writing"){
    if(uncovered){
      write(
"There is some writing engraved into the rock next to the circle\n"+
"which can be 'read'.\n");
      return 1;
    }
    else return 0;
  }
  if(str == "at circle" || str == "circle"){
    if(uncovered){
      write(
"Carved on the face of the rock is a large circle with many bizarre\n"+
"symbols engraved in and around it.  There is some writing to the\n"+
"right of the circle.\n");
      return 1;
    }
    else return 0;
  }
  if(str == "at symbols" || str == "symbols"){
    if(uncovered){
      write(
"There are many strange symbols engraved within and around the circle.\n"+
"Each one is very detailed and none of them look the same.  There is\n"+
"a row of them that run down the center of the symbol, plus six others\n"+
"that are larger than most of the others.  You can feel the power that\n"+
"resides within them.\n");
      return 1;
    }
  }
  if(str == "at rock" || str == "rock"){
    if(!uncovered){
      write(
"The large, dagger shaped rock is protruding out of the ground, pointing\n"+
"unnaturally at the sky.  The side facing north is very flat, and covered\n"+
"by plants.  You could uncover it to see the face of the rock.\n");
      return 1;
    }
    if(uncovered){
      write(
"The large, dagger shaped rock is protruding out of the ground, pointing\n"+
"unnaturally at the sky.  The side facing north is very flat, and not\n"+
"obstructed by anything.  A large circle is carved into the rocks face.\n");
      return 1;
    }
    return 1;
  }
  if(str == "at trees" || str == "trees"){
    write(
"Towering evergreen trees reach high into the sky all around you.\n"+
"Their branches fan out, blocking out all of the light.\n");
    return 1;
  }
  if(str == "at branches" || str == "branches"){
    write(
"The branches of the trees are blocking out all of the light.\n");
    return 1;
  }
  if(str == "at trail" || str == "trail"){
    write(
"A barely noticable trail leads to the north.\n");
    return 1;
  }
  else return 0;
}
