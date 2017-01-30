/*  The help files for the guilds spells */

info(string str){
  if(str == "focus")
  {
    write(
      "\n  By focusing the shadows you temporarily improve your ability\n"+
      "to fight.\n\n"+
      "\tSyntax:     focus\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "beckon shadows")
  {
    write(
      "\n  Beckon the shadows to gather around you and help you\n"+
      "recouperate as you rest.\n\n"+
      "\tSyntax:     beckon shadows\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "wither corpse")
  {
    write(
      "\n  You may use this spell to drain the power from a corpse.\n\n"+
      "\tSyntax:     wither corpse\n"+
      "\tCost:       low\n"+
      "\tComponent:  corpse\n\n");
  }
  else if(str == "drain")
  {
    write(
      "\n  With this spell you can drain the power that lies within\n"+
      "all things into yourself.\n\n"+
      "\tSyntax:     drain <object>\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "teleport")
  {
    write(
      "\n  With this ability, you can move yourself through the shadows\n"+
      "into the fallen lands from most locations.  This spell is not\n"+
      "intended to be used for casual travel.\n\n"+
      "\tSyntax:     teleport\n"+
      "\tCost:       low\n"+
      "\tComponent:  crows feather\n\n");
  }
  else if(str == "shield")
  {
    write(
      "\n  Conjure forth a barrier of shadows which will help protect\n"+
      "you from harm in combat.\n\n"+
      "\tSyntax:     shield\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "see")
  {
    write(
      "\n  Peer through the shadows at someone else in Nirvana.  If they\n"+
      "are shrouded by darkness you will not be able to see them.\n\n"+
      "\tSyntax:     see <player>\n"+
      "\tCost:       low\n"+
      "\tComponent:  geode\n\n");
  }
  else if(str == "know")
  {
    write(
      "\n  Tap into the knowledge of another player to know their status,\n"+
      "location and if they have one, their opponent.\n\n"+
      "\tSyntax:     know <player>\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "blast")
  {
    write(
      "\n  By gaining control of the powers within you, you can channel\n"+
      "them outward and blast your opponent.\n\n"+
      "\tSyntax:     blast <target>\n"+
      "\tCost:       medium\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "empower")
  {
    write(
      "\n  By enchanting a creature with the power of the shadows, you\n"+
      "temporarily increase its ability to fight.\n\n"+
      "\tSyntax:     empower <npc>\n"+
      "\tCost:       medium\n"+
      "\tComponent:  ruby red gem\n\n");
  }
  else if(str == "weaken")
  {
    write(
      "\n  By weakening your opponent, you make them slower and easier to\n"+
      "damage.  The effects of this spell are only temporary.\n\n"+
      "\tSyntax:     weaken <npc>\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "web")
  {
    write(
      "\n  When you throw a web on an opponent, it will cause them to\n"+
      "become entangled in a web of shadows.\n\n"+
      "\tSyntax:     web <npc>\n"+
      "\tCost:       low\n"+
      "\tComponent:  spider web\n\n");
  }
  else if(str == "dark assistance")
  {
    write(
    "\n  When you are in need, you can summon assistance from the\n"+
    "distant shadows.  For a limited time they will aid you as you\n"+
    "fight.  When combat ends they will depart.\n\n"+
    "\tSyntax:     assistance\n"+
    "\tCost:       high\n"+
    "\tComponent:  dark root\n\n");
  }
  else if(str == "meditate")
  {
    write(
      "\n  After every fight, meditation will allow you to recouperate\n"+
      "your power and endurance.\n\n"+
      "\tSyntax:     meditate\n"+
      "\tCost:       low\n"+
      "\tComponent:  corpse\n\n");
  }
  else if(str == "shadowform")
  {
    write(
      "\n  This spell is used to create a duplicate of yourself, created\n"+
      "from the shadows.  It will allow you enough time to escape from\n"+
      "combat.\n\n"+
      "\tSyntax:     shadowform\n"+
      "\tCost:       low\n"+
      "\tComponent:  ash blossom\n\n");
  }
  else if(str == "descend")
  {
    write(
      "\n  When you use this ability to attack an opponent, not only do\n"+
      "you strike when they are unprepared, but you also invigorate your\n"+
      "senses, as you are more prepared for battle.\n\n"+
      "\tSyntax:     descend <target>\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "shadowcloak")
  {
    write(
      "\n  Wrap yourself in a cloak of shadows, making yourself invisible\n"+
      "to lower level players.  This spell will last until you end it.\n\n"+
      "\tSyntax:     shadowcloak\n"+
      "\tCost:       low\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "repulsion")
  {
    write(
      "\n  In a time of utter desperation when you are being overwhelmed\n"+
      "by your enemies you can bring peace with repulsion.\n\n"+
      "\tSyntax:     repulsion\n"+
      "\tCost:       high\n"+
      "\tComponent:  black leaf\n\n");
  }
  else if(str == "rage")
  {
    write(
      "\n  Control the shadows to unleash violent rage upon your enemy.\n\n"+
      "\tSyntax:     rage <npc>\n"+
      "\tCost:       medium\n"+
      "\tComponent:  black liquid\n\n");
  }
  else if(str == "dark prayer")
  {
    write(
      "\n  The need for power can be very strong, and sometimes is all\n"+
      "that truly matters.  When you are dangerously low on power you\n"+
      "can cast a dark prayer to sacrifice your strength for power.\n\n"+
      "\tSyntax:     dark prayer\n"+
      "\tCost:       high\n"+
      "\tComponent:  bone powder\n\n");
  }
  else if(str == "vanish")
  {
    write(
     "\n  When protecting the body is of the utmost importance, you can\n"+
     "summon the shadows to encase you, protect you, shield you from harm.\n"+
     "The ability to vanish does have serious limitations however.  You\n"+
     "remain hidden until you choose to 'reappear'.\n\n"+
     "\tSyntax:     vanish\n"+
     "\tCost:       high\n"+
     "\tComponent:  pearl\n\n");
  }
  else if(str == "weave")
  {
    write(
      "\n  By enchanting a weapon with the powers of the shadows, it\n"+
      "allows you to use it to aid you in combat.  You may 'deweave'\n"+
      "it to remove the spell from the weapon.\n\n"+
      "\tSyntax:     weave <wep>\n"+
      "\tCost:       high\n"+
      "\tComponent:  shadow gem\n\n");
  }
  else if(str == "vigor")
  {
    write(
      "\n  By beckoning the shadows to aid your fighting ability, they\n"+
      "will drive you to fight harder than you normally would.  You can\n"+
      "only maintain this additional vigor for a limited time.\n\n"+
      "\tSyntax:     vigor <high|medium|low>\n"+
      "\tCost:       medium\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "embrace")
  {
    write(
      "\n  By embracing your opponent you can drive the shadows to the\n"+
      "deepest recesses of their mind.  Your pain will become theirs.\n"+
      "If you are not focused or your opponent is not weakened then your\n"+
      "spell will fail.  Embracing is not instantaneous.\n\n"+
      "\tSyntax:     embrace <npc>\n"+
      "\tCost:       medium\n"+
      "\tComponent:  none\n\n");
  }
  else if(str == "siphon")
  {
    write(
      "\n  Siphon the very energy from your opponent.  This spell must\n"+
      "be channeled and will prevent the casting of other abilities.\n\n"+
      "\tSyntax:     siphon <npc>\n"+
      "\tCost:       none\n"+
      "\tComponent:  siphon stone\n\n");
  }
  return 1;
}


