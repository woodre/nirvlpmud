/*
 *  List of guild pets.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

pet_list()  {

    write(
    "Pet Grouping 1  [birds]\n"+
    "  1)  Raven             2)  Crow \n"+        
    "  3)  Owl               4)  Flying kitten\n"+
    "  5)  Dove              6)  x \n"+          
    "  7)  x\n\n");

  if(BLVL > 4)  {
    write(
    "Pet Grouping 2  [sprites]\n"+
    "  8)  Pixies            9)  Hawk\n"+
    "  10) Eagle             11) Wind Sprite\n"+
    "  12) Fire Sprite       13) Rain Sprite\n"+
    "  14) Winged Cat\n\n");
        }

  if(BLVL > 7)  {
    write(
    "Pet Grouping 3  [spirits]\n"+
    "  15) Drake             16) Pegasus\n"+
    "  17) Wind Spirit       18) Griffon\n"+
    "  19) Rain Spirit       20) Lightning Spirit\n"+
    "  21) Fire Spirit\n\n");
        }

  if(BLVL > 10)  {
    write(
    "Pet Grouping 4  [elementals]\n"+
    "  22) Phoenix           23) Black Pegasus\n"+
    "  24) Puffball 'o Doom  25) Wind Elemental\n"+
    "  26) Rain Elemental    27) Lightning Elemental\n"+
    "  28) Fire Elemental\n\n");
        }
        
  if(BLVL > 14)  {
    write(
    "Pet Grouping 5  [storms]\n"+
    "  22) Storm Spirit      23) Storm Pegasus\n"+
    "  24) Storm Elemental   25) Storm Phoenix\n"+
    "  26) Storm Crow        27) Storm Sprite\n"+
    "  28) Storm Drake\n\n");
        }

  if(BLVL > 21)  {
    write(
    "Pet Grouping 6  [star]\n"+
    "  22) Star Phoenix      23) Star Pegasus\n"+
    "  24) Star Elemental    25) Star Spirit\n"+
    "  26) Star Sprite       27) Star Crow\n"+
    "  28) Star Drake\n\n");
        }
        
      return 1;
        }
