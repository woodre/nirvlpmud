status main(string str, object PO, object User)
{
	string sstrike, evis, sap, backstab, garrote, pickpocket, ambush, blind;
	
	switch(PO->query_sstrike()){   
		 
		case 1000:
			sstrike = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			sstrike = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			sstrike = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			sstrike = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			sstrike = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			sstrike = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			sstrike = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			sstrike = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			sstrike = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			sstrike = "[X - - - - - - - - -]";
		break;
		
		default:
			sstrike = "[- - - - - - - - - -]";
		break;
		}
		
		switch(PO->query_evis()){
			    
		case 1000:
			evis = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			evis = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			evis = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			evis = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			evis = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			evis = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			evis = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			evis = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			evis = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			evis = "[X - - - - - - - - -]";
		break;
		
		default:
			evis = "[- - - - - - - - - -]";
		break;
		}
		
		switch(PO->query_sap()){
			    
		case 1000:
			sap = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			sap = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			sap = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			sap = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			sap = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			sap = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			sap = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			sap = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			sap = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			sap = "[X - - - - - - - - -]";
		break;
		
		default:
			sap = "[- - - - - - - - - -]";
		break;
		}
		
		switch(PO->query_backstab()){
			    
		case 1000:
			backstab = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			backstab = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			backstab = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			backstab = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			backstab = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			backstab = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			backstab = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			backstab = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			backstab = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			backstab = "[X - - - - - - - - -]";
		break;
		
		default:
			backstab = "[- - - - - - - - - -]";
		break;
		}
		
		switch(PO->query_garrote()){
			    
		case 1000:
			garrote = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			garrote = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			garrote = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			garrote = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			garrote = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			garrote = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			garrote = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			garrote = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			garrote = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			garrote = "[X - - - - - - - - -]";
		break;
		
		default:
			garrote = "[- - - - - - - - - -]";
		break;
		}
		
		
		switch(PO->query_ambush()){
			    
		case 1000:
			ambush = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			ambush = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			ambush = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			ambush = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			ambush = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			ambush = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			ambush = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			ambush = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			ambush = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			ambush = "[X - - - - - - - - -]";
		break;
		
		default:
			ambush = "[- - - - - - - - - -]";
		break;
		}
		
		switch(PO->query_blind()){
			    
		case 1000:
			blind = "[X X X X X X X X X X]";
		break;
		
		case 900..999:
			blind = "[X X X X X X X X X X]";
		break;
		
		case 800..899:
			blind = "[X X X X X X X X - -]";
		break;
		
		case 700..799:
			blind = "[X X X X X X X - - -]";
		break;
		
		case 600..699:
			blind = "[X X X X X X - - - -]";
		break;
		
		case 500..599:
			blind = "[X X X X X - - - - -]";
		break;
		
		case 400..499:
			blind = "[X X X X - - - - - -]";
		break;
		
		case 300..399:
			blind = "[X X X - - - - - - -]";
		break;
		
		case 200..299:
			blind = "[X X - - - - - - - -]";
		break;
		
		case 100..199:
			blind = "[X - - - - - - - - -]";
		break;
		
		default:
			blind = "[- - - - - - - - - -]";
		break;
		}
		tell_object(User, "\n");
		tell_object(User, "Sinister Strike		"+sstrike+"\n");
		tell_object(User, "Eviscerate	         "+evis+"\n");
		tell_object(User, "Sap			     "+sap+"\n");
		tell_object(User, "Backstab		  "+backstab+"\n");
		tell_object(User, "Garrote			    "+garrote+"\n");
		tell_object(User, "Ambush			  "+ambush+"\n");
		tell_object(User, "Blind			     "+blind+"\n");
		return 1;
}
