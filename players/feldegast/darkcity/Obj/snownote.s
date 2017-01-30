tune_ob.c - if something dies in the release of energies, the charge will not be used. Make it either
            not while() or make sure it can't kill
            in the sleep function, you probably want a stop_hunted() or two to really work
