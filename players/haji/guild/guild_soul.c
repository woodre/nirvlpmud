id(str) { return "haji_soul";
  }
init() {
     move_object(this_object(),this_player());
     add_action("blow","blow");
     add_action("guild_help","infog");
     add_action("guild_bug","gbug");
    if((this_player()->query_level())>=4) {
     add_action("wind","wind");
    }
   if((this_player()->query_level())>=5) {
     add_action("sword","sword");
     add_action("wield","wield");
    }
   if((this_player()->query_level())>=9) {
      add_action("curel","cure_light");
      add_action("curel","cl");
    }
   if((this_player()->query_level())>=10) {
    add_action("wand","wand");
   }
   if((this_player()->query_level())>11) {
     add_action("escape","escape");
       }
   if((this_player()->query_level())>=12) {
      add_action("summon","summon");
    }
    if((this_player()->query_level())>=14) {
      add_action("staff","staff");
    }
   if((this_player()->query_level())>=15) {
      add_action("curec","cure_critic");
      add_action("curec","cc");
     }
   if((this_player()->query_level())>=16) {
       add_action("excalibur","excalibur");
       }
   if((this_player()->query_level())>=18) {
       add_action("makebomb","create");
        }
    if((this_player()->query_level())>=21) {
       add_action("cures","cure_serious");
       add_action("cs","cs");
      }
}
blow(str) {
    object ob;
        if(str==0) {
            write("No such creature alive at this time.\n");
            return 1;
        }
        if(this_player()->query_spell_points() < 10) {
            write("You don't have enough spell points.\n");
            return 1;
        }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) return 0;
    write("You blow on your opponent!\n");
    say(this_player()->query_name()+ "blows on his opponent!\n");
    ob->hit_player(random(15));
    this_player()->restore_spell_points(-10);
    return 1;
    }

}
