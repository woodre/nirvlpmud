#include "definitions.h"

string main_stats;
int linna_tug_items;              /* total number of items tugged from ether-muck */
int linna_push_items;             /* total number of items pushed into ether-muck */
int linna_weapons_wc_total;       /* sum of all the WC of all the weapons pushed */
int linna_weapons_num_total;      /* # of total weapons pushed in */
int linna_armor_ac_total;         /* [ARRAY] sum of all the armor classes of all armors pushed */
int linna_armor_num_total;        /* [ARRAY] # of total armors pushed in */
int linna_items_value_total;      /* total value in coins of items pushed */
int linna_tugitems_value_total;


id(str) { return str == "device"; }

short() { return "Tug Finger Device [1.0]"; }

reset()
{
   move_object(this_object(), "players/mizan/workroom");
   if(!linna_armor_num_total) linna_armor_num_total = allocate(7);
   if(!linna_armor_ac_total) linna_armor_ac_total = allocate(7);
}

tug_finger(str)
{
   object ob, gob;
   
   if(!str) return 0;
   main_stats = 0;
   
   ob = find_player(str);
   
   if(ob)
   {
      /* The player is logged in so we pull from the clay */
      gob = present(GUILD_ID, ob);
      if(!gob)
      {
         write("No such player exists or is not in the guild.\n");
         return 1;
      }

      /* first reset everything */
      linna_tug_items = 0;
      linna_push_items = 0;
      linna_weapons_wc_total = 0;
      linna_weapons_num_total = 0;
      linna_armor_ac_total = allocate(7);
      linna_armor_num_total = allocate(7);
      linna_items_value_total = 0;
      linna_tugitems_value_total = 0;
      
      linna_tug_items = gob->query_linna_tug_items();
      linna_push_items = gob->query_linna_push_items();
      linna_weapons_wc_total = gob->query_linna_weapons_wc_total();
      linna_weapons_num_total = gob->query_linna_weapons_num_total();
      linna_armor_ac_total = gob->query_linna_armor_ac_total();
      linna_armor_num_total = gob->query_linna_armor_num_total();
      linna_items_value_total = gob->query_linna_items_value_total();
      linna_tugitems_value_total = gob->query_linna_tugitems_value_total();
      
      make_report(str);
      
   }
   else
   {
      /* first reset everything */
      linna_tug_items = 0;
      linna_push_items = 0;
      linna_weapons_wc_total = 0;
      linna_weapons_num_total = 0;
      linna_armor_ac_total = allocate(7);
      linna_armor_num_total = allocate(7);
      linna_items_value_total = 0;
      linna_tugitems_value_total = 0;
      main_stats = "";

      /* The player is not logged in so we read the files on the player... */
      restore_object("players/mizan/closed/poly/players/" + str);
      if(!main_stats || main_stats == "")
      {
         write("No such player exists or is not in the guild.\n");
         return 1;
      }
      
      make_report(str);
      
   }

   return 1;
}

make_report(str) 
{
   int items_avg_value, tug_items_avg_value;
   int armor_classes;
   int weapon_str;
   int i;
   
   armor_classes = allocate(7);

   if(linna_push_items > 0)
      items_avg_value = linna_items_value_total / linna_push_items;
   else
      items_avg_value = 0;

   if(linna_tug_items > 0)
      tug_items_avg_value = linna_tugitems_value_total / linna_tug_items;
   else
      tug_items_avg_value = 0;
   
   if(linna_weapons_num_total > 0)
      weapon_str = linna_weapons_wc_total / linna_weapons_num_total;
   else
      linna_weapons_num_total = 0;
   
   
   for(i = 0; i <sizeof(linna_armor_ac_total); i++)
   {
      if(linna_armor_num_total[i] > 0)
         armor_classes[i] = linna_armor_ac_total[i] / linna_armor_num_total[i];
      else
         armor_classes[i] = 0;
   }

   
   write("\n>>Tug-Push Usage Finger --------------------------------------------------<<\n");
   write("\n   " + capitalize(str) + " has deposited a total of " + linna_push_items + " items into tug.\n\n");
   write("   Items pushed were worth an average of [" + items_avg_value + "] gold.\n");
   write("   Items tugged were worth an average of [" + tug_items_avg_value + "] gold.\n\n");
   
   write("   Total items pushed in:       " + linna_push_items + "\n");
   write("   Total items tugged out:      " + linna_tug_items + "\n");
   write("   A generous player would put more things in than take them out.\n\n");
   write("   Total weapons pushed in:     " + linna_weapons_num_total + "\n");
   write("   Average weapon strength:     " + rate_weapon(weapon_str) + "\n\n");
   write("   Total armors pushed in of...\n");
   write("      Type 'armor':             " + linna_armor_num_total[0] + "\n");
   write("      Type 'helmet':            " + linna_armor_num_total[1] +"\n");
   write("      Type 'boots':             " + linna_armor_num_total[2] +"\n");
   write("      Type 'ring':              " + linna_armor_num_total[3] +"\n");
   write("      Type 'amulet':            " + linna_armor_num_total[4] +"\n");
   write("      Type 'shield':            " + linna_armor_num_total[5] +"\n");
   write("      Type 'misc':              " + linna_armor_num_total[6] +"\n\n");
   write("   Average armor strength of...\n");
   write("      Type 'armor':             "  + rate_main_armor(armor_classes[0]) + "\n");
   write("      Type 'helmet':            "  + rate_misc_armor(armor_classes[1]) + "\n");
   write("      Type 'boots':             "  + rate_misc_armor(armor_classes[2]) + "\n");
   write("      Type 'ring':              "  + rate_misc_armor(armor_classes[3]) + "\n");
   write("      Type 'amulet':            "  + rate_misc_armor(armor_classes[4]) + "\n");
   write("      Type 'shield':            "  + rate_misc_armor(armor_classes[5]) + "\n");
   write("      Type 'misc':              "  + rate_misc_armor(armor_classes[6]) + "\n");

   
   /* clear the stats */
/*
   linna_tug_items = 0;
   linna_push_items = 0;
   linna_weapons_wc_total = 0;
   linna_weapons_num_total = 0;

   for(i = 0; i < sizeof(linna_armor_ac_total); i ++)
   {
      linna_armor_ac_total[i] = 0;
   }

   for(i = 0; i < sizeof(linna_armor_num_total); i ++)
   {
      linna_armor_num_total[i] = 0;
   }

   linna_items_value_total = 0;
   linna_tugitems_value_total = 0;
   destruct(this_object());
*/   
   return 1;
}

rate_weapon(arg)
{
   if(!arg) return "Worthless";
   else if(arg > 20) return "GODLIKE!";
   else if(arg > 19) return "Insanely Powerful!";
   else if(arg > 18) return "Very Powerful";
   else if(arg > 17) return "Powerful";
   else if(arg > 16) return "Very Effective";
   else if(arg > 14) return "Effective";
   else if(arg > 12) return "Adequate";
   else if(arg > 10) return "Somewhat Adequate";
   else if(arg > 8) return "Newbie";
   else if(arg > 6) return "Almost Harmless";
   else if(arg > 3) return "Harmless";
   else return "Worthless";
}

rate_main_armor(arg)
{
   if(!arg) return "Basic or No Protection";
   else if(arg > 5) return "GODLIKE!";
   else if(arg > 4) return "Insanely Excellent Protection";
   else if(arg > 3) return "Excellent Protection";
   else if(arg > 2) return "Adequate Protection";
   else if(arg > 1) return "Somewhat Adequate Protection";
   else return "Basic or No Protection";
}

rate_misc_armor(arg)
{
   if(!arg) return "Basic or No Protection";
   else if(arg > 3) return "GODLIKE!";
   else if(arg > 2) return "Excellent Protection";
   else if(arg > 1) return "Adequate Protection";
   else return "Basic or No Protection";
}
