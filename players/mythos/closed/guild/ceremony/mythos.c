#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("mythos");
  set_short("@ @ @ HE who was foretold is Mythos the Prophet (Diabolic)");
  set_long( "Mythos is a simple man.\n"+  
	        "He is dressed in a black kimono, white obi, and geka for his \n"+
	        "feet.  His long shiny black hair is bound simply into a pony \n"+
	        "tail.  His face is simple and carefree. When his youthful face\n"+
	        "smiles, the sense of innocent joy and tranquillity beam forth.  \n"+
	        "His lithe body moves with grace and fluidity- as if every step is\n"+
	        "made on a cloud.  When he speaks, music pours forth- gentle and \n"+
	        "pleasing to the ear.  Mythos is a mortal embodiment of joy and \n"+
	        "fun.  But beware when he is angry; for dark storm clouds appear \n"+
	        "and his fury has no bounds.  The only changes that appear are \n"+
	        "those of his eyes and voice: black pools of calm turn into blue \n"+
	        "eyes of ice, gentle music turns into flat tones with thunder \n"+
	        "brewing beneith. Follow chivalry and politeness, and the anger \n"+
	        "will not unleash.  Let him be your friend and join him in finding\n"+
	        "fun in life.\n");  
	        
	        set_weight(100000);   
	        set_value(0); }
