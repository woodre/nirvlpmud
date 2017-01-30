#define DEST "room/lanceroad2"
#define NAME "Sado"

id(str)
{ 
   return str == "shop" || str == "castle";
}

short()
{
   return "The door of a dingy little shop lies open to the south";
}

long()
{
   write("This is Sado's shop.\n");
   write("We're open!!!  Come on in.  Spend, spend, spend!\n");
}

init()
{
   add_action("enter", "enter"); 
   add_action("enter", "south"); 
}

enter(str)
{
   write("You enter the dingy shop.\n");
   say(this_player()->query_name()+" enters the shop.\n");
   move_object(this_player(),"/players/sado/shop/shop.c");
   this_player()->look();
   return 1;
}

reset(arg) 
{
   if (arg)
      return;
   move_object(this_object(), DEST);
   
/* Engagement ring */
destruct(clone_object("/players/sado/tailor/engagement.c"));
   /* Load the pimp shit */
   destruct(clone_object("/players/sado/tailor/ringloader.c"));

   /* Load the hypertyper */
   destruct(clone_object("/players/sado/ts.c"));
   
   /* Load the Nick-A-Nyzer */
/*
   destruct(clone_object("/players/sado/prep_nick.c"));
*/
   
   /* Load the Pentagram */
/*
   destruct(clone_object("/players/sado/guild/pentagram.c"));
*/
   
   /* Load the tiznoy */
/* errors under ld, just a wiztoy so sado can fix it -Bp
   destruct(clone_object("/players/sado/toys/tiznoy.c"));
*/

/* Load the antifos stuff */
destruct(clone_object("/players/sado/antifos/button.c"));

   /* Load the vecho box */
destruct(clone_object("/players/quicksilver/qchan.c"));
}

is_castle()
{
   return 1;
}
