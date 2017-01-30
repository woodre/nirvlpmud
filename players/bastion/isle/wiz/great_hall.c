inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Great Hall";
  long_desc = 
   "You enter into an enormous hall.  The vaulted ceiling rises some sixty\n"+
   "feet, and extends at least that distance from north to south. A long\n"+
   "table stands on the dias to the north, behind which are placed five\n"+
   "chairs. Larger tables are placed against the walls, currently not in\n"+
   "use, leaving the center of the room free. A fireplace occupies fourteen\n"+
   "feet of the southern wall, also not in use; over it are displayed a\n"+
   "coat of arms with some writing beneath. Adorning the other walls are\n"+
   "many portraits and paintings both fantastic and martial. You may leave\n"+
   "through double doors at the center of the east wall, or two others\n"+
   "north and south of them.\n";
  items = ({"coat of arms",
            "'Where truth dwells, evil cannot prevail'",
            "writing",
            "'Where truth dwells, evil cannot prevail'",
            "portraits",
            "One portrait catches your attention: A handsome man in wizard's robes\ntitled 'The sorcerer Damian on the occasion of his 45th birthday'",
            "portrait",
            "One portrait catches your attention: A handsome man in wizard's robes\ntitled 'The sorcerer Damian on the occasion of his 45th birthday'",
            "paintings",
            "Two paintings draw your eye: One is of a great battle, depicting a force of\nmen, led by someone who looks like one of the portraits on the walls, fighting\na horde of goblins, orcs and other humanoids. Above the second group, on a\nyoung black dragon, rides a man whose face looks vaguely familiar. In his\nright hand is raised a rod or staff. The scene is titled 'The Battle at"+
          "\nBelgaers.' The other painting is of a oak staff, simply wrought, topped\nby a single red stone. The label reads 'The Staff of Wizardry'",
            "painting",
            "Two paintings draw your eye: One is of a great battle, depicting a force of\nmen, led by someone who looks like one of the portraits on the walls, fighting\na horde of goblins, orcs and other humanoids. Above the second group, on a\nyoung black dragon, rides a man whose face looks vaguely familiar. In his\nright hand is raised a rod or staff. The scene is titled 'The Battle at"+
          "\nBelgaers. The other painting is of a oak staff, simply wrought, and topped\nby a single red stone. The label reads 'The Staff of Wizardry'"});
  dest_dir = ({"players/bastion/isle/wiz/kitchen", "northeast",
               "players/bastion/isle/wiz/w_hall2", "east",
               "players/bastion/isle/wiz/parlour", "southeast"});
  }
}
