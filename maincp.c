main ()
{       
	int     nRetcode;       /*  Return code from RSC   */
	char 	trade_string[300];
	
	if (Start_Phase3() != 0) {
		printf("Error connecting to Phase3 please check the events.log");
		return(-1);
	}
	/* 949538090100912828AB6 */
  	memset(trade_string, 32, 300);
      
        sprintf (trade_string, "B00CD080102080702B9538    912828AB6   1000              100.00        15.00            A0002                 ");
  /*	sprintf (trade_string, "B    080402080702333333781IBM         1000              100.00                         A0002               11");*/
    
    	nRetcode = Phase3Trade (trade_string, strlen(trade_string));   
    
    	if (nRetcode == 0) {
    		printf("Trade Date = %6.6s, Trade # %5.5s\n", &trade_string[157], & trade_string[163]);
    		printf("Phase3 Info (Advisory) %60.60s\n", &trade_string[168]);
    	}
    	else if (nRetcode == -1) {
    		printf("Phase3 Error (Advisory) %60.60s\n", &trade_string[168]);
    	}
	
    	if (Stop_Phase3() != 0) {
     		printf("Error dis connecting from Phase3 please check the events.log");
     		return(-1);
    	}
    return(0);    
}