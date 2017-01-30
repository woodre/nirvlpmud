
/*
 * TITLES (2/14/94)
 * For setting guild and alignment titles
 */

set_guild_title() {
   string guild_title, align;
   int lvl, al;

   lvl = this_player()->query_level();
   al = this_player()->query_alignment();
   lvl -= 1;
   guild_title = PALGUILD->get_new_title(lvl);
   align = al_title(al);
   this_player()->set_al_title(align);
   this_player()->set_title(guild_title);
   write(filter_color("Your are now:\n",HIG));
   write(filter_color("   "+this_player()->short()+"\n",HIG));
   return 1;
}

/* get alignment title */
al_title(lvl) {
   if(lvl >= 2000)  return "SAINT";
   if(lvl >= 1100)  return "pious";
   if(lvl >=  800)  return "righteous";
   if(lvl >=  500)  return "inviolable";
   if(lvl >=  250)  return "revered";
   if(lvl >     0)  return "virtuous";
   return "RENEGADE";
}

