shp <nn> = stores  nn hps                                  nn       6th  Wraith
ssp <nn> = stores  nn sps                                  nn       6th
ghp <nn> = gets back a number of hps                        0       6th
gsp <nn> = gets back a number of sps                        0       6th
stored = shows how many hp/sp you stored                    0       6th
evoke = evokes death upon the monsters in the room         20*mon   6th
lightning <monster> = Summon a black lightining and        50       6th
                      throw it at a monster

possess <monster> = sucks the monster energy into you     100       7th  Spectre
revive <player> = force a dead player to reincarnate      100       7th
                  It works only with Undead and Vampires 
		  (working chances = 60%) 
============================== Spells below aren't active =============
(*) hand = create a spectal hand to fight with u    dam*round       7th
(*) chill <monster> =  lowers temporarily monster's wc     40       7th 
(*) weaken <monster> = lowers temporarily monster's ac     40       7th
                 ( probability : 50% )
(*) fing <monster> = points the finger of death at a      100       7th
                 monster (lowers 10% of hps)

