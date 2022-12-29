#include<stdio.h>
#include<string.h>
#include<math.h>


int main( int argc, char *argv[]){

	// DECLARE MY LOCAL VARIABLES
	char c='*';
	char drawing_command[100];
	int wide=1000;
	int tall=1000;
	char canvas[wide][tall];
	const char EMPTY=' ';


	// LOOP THROUGH EVERY COMMAND AND BREAK AT THE END
	for (; ;){
	
		scanf("%s", drawing_command); 	
		
		
		// GRID COMMAND 	
		if (strcmp(drawing_command,"GRID") == 0){
			
			if (wide != 1000 || tall != 1000){
				char garbage[100];
				fgets(garbage,99, stdin);
				printf("GRID was already set to %d, %d\n", wide, tall);
				continue;	
			}

			scanf("%d\n", &wide);
			scanf("%d\n", &tall);
			canvas[wide][tall];

			for (int i=0; i<wide;i++){
				for (int j=0; j<tall;j++){
					canvas[i][j]=EMPTY;
				}
			}
		       	continue;	
		}


		// CHAR COMMAND
		else if (strcmp(drawing_command,"CHAR") == 0){
			char garbage;
			scanf("%c", &garbage);
			scanf("%c", &c);
			continue;
                }


		// DISPLAY COMMAND
		else if (strcmp(drawing_command,"DISPLAY") == 0){
			
			if (wide == 1000 && tall == 1000){
				char garbage[100];
                                fgets(garbage, 99, stdin);
				puts("Only CHAR command is allowed before the grid size is set.");
				continue;
			}
	
			for (int i=tall-1; i>=0; i--){
				int mod_i=i%10;
                                printf("%d", mod_i);
				for (int j=0; j< wide; j++){
					printf("%c", canvas[j][i]);
				}
				printf("\n");
			}
			printf("  ");
			for (int i=0; i<wide; i++){
				int mod_i=i%10;
				printf("%d", mod_i);
			}
			printf("\n");
			continue;
		}



		// RECTANGLE FUNCTION
		else if (strcmp(drawing_command,"RECTANGLE") == 0){

			if (wide == 1000 && tall == 1000){
                                char garbage[100];
                        	fgets(garbage, 99, stdin);
				puts("Only CHAR command is allowed before the grid size is set.");
                                continue;
                        }
			
			int x1;
                        int y1;
                        int x2;
                        int y2;
                        char garbage;
                        scanf("%d", &x1);
                        scanf("%c", &garbage);
                        scanf("%d", &y1);
                        scanf("%c", &garbage);
                        scanf("%d", &x2);
                        scanf("%c", &garbage);
                        scanf("%d", &y2);

			if ( x1 >1000 ){
				x1=wide;
			}

			if ( x2 >1000 ){
                                x2=wide;
                        }

			if ( y2 >1000 ){
                                y2=tall;
                        }

			if ( y1 >1000 ){
                                y1=tall;
                        }

			for(int i=x1; i<=x2; i++){
				 canvas[i][y1]=c;
			}

			for(int i=x1; i<=x2; i++){
                                 canvas[i][y2]=c;
                        }

			for(int j=y2; j<=y1; j++){
                                 canvas[x1][j]=c;
                        }
			
			for(int j=y2; j<=y1; j++){
                                 canvas[x2][j]=c;
                        }

			continue;
		}



		// LINE FUNCTION
		else if (strcmp(drawing_command,"LINE") == 0){

			if (wide == 1000 && tall == 1000){
                                char garbage[100];
                                fgets(garbage, 99, stdin);
			       	puts("Only CHAR command is allowed before the grid size is set.");
                                continue;
                        }

                        int x1;
                        int y1;
                        int x2;
                        int y2;
                        char garbage;
                        scanf("%d", &x1);
                        scanf("%c", &garbage);
                        scanf("%d", &y1);
                        scanf("%c", &garbage);
                        scanf("%d", &x2);
                        scanf("%c", &garbage);
                        scanf("%d", &y2);
			
			// HANDLE TRUNCATION 
	       		if ( x1 >1000 ){
                                x1=wide;
                        }

                        if ( x2 >1000 ){
                                x2=wide;
                        }

                        if ( y2 >1000 ){
                                y2=tall;
                        }

                        if ( y1 >1000 ){
                                y1=tall;
                        }

			int run= x2 - x1;
			int rise= y2 - y1;

			
			// horizontal lines
			if(rise == 0){
				if (x1 < x2){
					for (int i=x1; i<=x2; i++){
						canvas[i][y1]=c;
					}
				}
				else{
					for (int i=x2; i<= x1; i++){
						canvas[i][y1]=c;
					}
				}
			}

			// veritcal lines
			else if (run == 0){
				if (y1 < y2){
                                	for (int i=y1; i<=y2; i++){
                                        	canvas[x1][i]=c;
                                	}
				}
				else{
					for (int i=y2; i<=y1; i++){
						canvas[x1][i]=c;
					}
				}
                        }

			// one point 
			else if (run ==0 && rise ==0){
				canvas[x1][y1]=c;
			}
			


			else {
				double slope= (double)rise/(double)run;
                         	double b= y2-slope*x2;	

				// case 1: positive slope
				if ( slope > 0){
					double y;
					double y_next;
					int y_round;
					int y_next_round;
					int gap;
					
					// (Both positive)
					if (rise >0 && run >0){
						int direct_next_x= x1+1;
						double direct_next_y= slope*direct_next_x+b;
						int direct_next_y_round= round(direct_next_y);
						gap= direct_next_y_round - y1;
						// HANDLE A SPECIAL CASE OF GAP
						if (gap >=5){
							if (slope <=2)
							gap=0;
						}
						for (int x=x1; x<=x2; x++){
							int this_gap=gap;
							y= slope*x + b;
							y_next=y;
							y_round= round(y);
							while (this_gap>0){
								y_next++;
								y_next_round= round(y_next);
                                                		canvas[x][y_next_round]=c;
								this_gap--;	
							}
							canvas[x][y_round]=c;
						}
					}
			
				
					
					// (Both negative)
					if (rise <0 && run <0){
						int direct_next_x= x2+1;
                                                int direct_next_y= round(slope)*direct_next_x+round(b);
                                                gap= direct_next_y - y2;
						if (gap >=5){
                                                        if (slope <=2)
                                                        gap=0;
                                                }
                                                for (int x=x2; x<=x1; x++){
                                                        int this_gap=gap;
                                                        y= slope*x + b;
                                                        y_next=y;
                                                        y_round= round(y);
                                                        while (this_gap>=2){
                                                                y_next++;
                                                                y_next_round= round(y_next);
                                                                canvas[x][y_next_round]=c;
                                                                this_gap--;
                                                        }
                                              	        canvas[x][y_round]=c;
                                                }
					}
			

				}	
				
				// case2: negative slope
				if ( slope < 0){
					double y;
					double y_next;
					int y_round;
					int y_next_round;
					int direct_next_x=x1+1;
					int direct_next_y= round(slope)*direct_next_x+ round(b);
					int gap= fabs(direct_next_y - y1);
					// HANDLE A SPECIAL CASE OF GAP
					if (gap >=5){
                                      	 	if (slope >=-2)
       		                       		       	gap=2;
      	                                }
					
					for (int x=x1; x<=x2; x++){
                                                int this_gap=gap;
						y= slope*x + b;
                                                y_next=y;
                                                y_round= round(y);
                                                while (this_gap>=2){
                                                        y_next--;
                                                        y_next_round= round(y_next);
                                                        canvas[x][y_next_round]=c;
                                                        this_gap--;
                                                }
					       canvas[x][y_round]=c;
					}
				}
			}	
	
			continue;
		}	



		// CIRCLE FUNCTION
		else if (strcmp(drawing_command,"CIRCLE") == 0){
			
			if (wide == 1000 && tall == 1000){
                                char garbage[100];
                                fgets(garbage, 99, stdin);
				puts("Only CHAR command is allowed before the grid size is set.");
                                continue;
                        }
			
			int center_x,center_y;
			int r;
			char garbage;
			scanf("%d" , &center_x);
			scanf("%c", &garbage);
			scanf("%d" , &center_y);
			scanf("%c", &garbage);
			scanf("%d" , &r);

			// FIRST QUADRANT
			int tempX= center_x;
                        int tempY= center_y + r;
			
			double c1;
			double c2;
			double c3;
			
			int gap;

			for (int i=tempX, j=tempY; i<=center_x+r, j>=center_y; i++,j--){

				c1=sqrt(pow((center_x-tempX),2)+pow((center_y- tempY+1),2));
				c2=sqrt(pow((center_x-tempX-1),2)+pow((center_y- tempY),2));
				c3=sqrt(pow((center_x-tempX-1),2)+pow((center_y- tempY+1),2));

				if (fabs(c1-r)<fabs(c2-r) && fabs(c1-r)<fabs(c3-r)){
					tempY= tempY-1;
					canvas[tempY][tempX]=c;
			
				}

				else if (fabs(c2-r)<fabs(c1-r) && fabs(c2-r)<fabs(c3-r)){
					tempX= tempX+1;
					canvas[tempY][tempX]=c;
	
				}

				else {
					tempX= tempX+1;
                                        tempY= tempY-1;
					canvas[tempY][tempX]=c;

				}
			}



			// SECOND QUADRANT

			tempX= center_x - r;
			tempY= center_y;

			for (int i=tempX, j=tempY; i<=center_x, j<=center_y+r; i++,j++){

                                c1=sqrt(pow((center_x-tempX-1),2)+pow((center_y - tempY),2));
                                c2=sqrt(pow((center_x-tempX),2)+pow((center_y - tempY-1),2));
                                c3=sqrt(pow((center_x-tempX-1),2)+pow((center_y- tempY-1),2));

                                if (fabs(c1-r)<fabs(c2-r) && fabs(c1-r)<fabs(c3-r)){
                                        tempX= tempX+1;
                                        canvas[tempY][tempX]=c;
                                }

                                else if (fabs(c2-r)<fabs(c1-r) && fabs(c2-r)<fabs(c3-r)){
                                        tempY= tempY+1;
                                        canvas[tempY][tempX]=c;
                                }

                                else {
                                        tempX= tempX+1;
                                        tempY= tempY+1;
                                        canvas[tempY][tempX]=c;
                                }
				
				int cur_gap= center_x - tempX;
				gap= cur_gap;
                        }


			// THIRD QUADRANT 
			tempX= center_x;
                        tempY= center_y-r;
				
			for (int i=tempX, j=tempY; i>=center_x-r, j<=center_y; i--,j++){

                                c1=sqrt(pow((center_x-tempX),2)+pow((center_y - tempY-1),2));
                                c2=sqrt(pow((center_x-tempX+1),2)+pow((center_y - tempY),2));
                                c3=sqrt(pow((center_x-tempX+1),2)+pow((center_y- tempY-1),2));

                                if (fabs(c1-r)<fabs(c2-r) && fabs(c1-r)<fabs(c3-r)){
                                        tempY= tempY+1;
                                        canvas[tempY][tempX]=c;
                                }

                                else if (fabs(c2-r)<fabs(c1-r) && fabs(c2-r)<fabs(c3-r)){
                                       tempX= tempX-1;
                                       canvas[tempY][tempX]=c;
				}

                                else {
                                        tempX= tempX-1;
                                        tempY= tempY+1;
                                        canvas[tempY][tempX]=c;
                                }
                        }


			
			// FOURTH QUADRANT 
					
			tempX= center_x+r;
                        tempY= center_y;

                        for (int i=tempX, j=tempY; i>=center_x, j>=center_y-r; i--,j--){

                                c1=sqrt(pow((center_x-tempX+1),2)+pow((center_y - tempY),2));
                                c2=sqrt(pow((center_x-tempX),2)+pow((center_y - tempY+1),2));
                                c3=sqrt(pow((center_x-tempX+1),2)+pow((center_y- tempY+1),2));

                                if (fabs(c1-r)<fabs(c2-r) && fabs(c1-r)<fabs(c3-r)){
                                        tempX= tempX-1;
                                        canvas[tempY][tempX]=c;
                                }

                                else if (fabs(c2-r)<fabs(c1-r) && fabs(c2-r)<fabs(c3-r)){
                                        tempY= tempY-1;
                                        canvas[tempY][tempX]=c;
                                }

                                else {
                                        tempX= tempX-1;
                                        tempY= tempY-1;
                                        canvas[tempY][tempX]=c;
                                }
                        }



			// FILL right gap 
			tempX= center_x;
			tempY= center_y+r;
			for (int i=tempX; i> tempX-gap; i--){
				canvas[tempY][i]=c;
			}

			// FILL bottom gap
			tempX= center_x-r;
                        tempY= center_y;
                        for (int i=tempY; i> tempY-gap; i--){
                                canvas[i][tempX]=c;
                        }

			// FILL left gap
			tempX= center_x;
                        tempY= center_y-r;
                        for (int i=tempX; i< tempX+gap; i++){
                                canvas[tempY][i]=c;
                        }

			// FILL top gap
                        tempX= center_x+r;
                        tempY= center_y;
                        for (int i=tempY; i< tempY+gap; i++){
                                canvas[i][tempX]=c;
                        }
		}


		// END FUNCTION
		else if (strcmp(drawing_command,"END") == 0){

			if (wide == 1000 && tall == 1000){
				return 1;
			}

			for (int i=tall-1; i>=0; i--){
                                int mod_i=i%10;
                                printf("%d", mod_i);
                                for (int j=0; j<wide;j++){
                                       printf("%c", canvas[j][i]);
                                }
                                printf("\n");
                        }

                        printf(" ");

                        for (int i=0; i<wide; i++){
                                int mod_i=i%10;
                                printf("%d", mod_i);
                        }
                        printf("\n");

			return 0;
			break;
		}

		
		// ERROR COMMANDS
		else{	

			char error[100];
			fgets(error, 99, stdin);
			printf("Error did not understand %s %s", drawing_command, error);
			continue;

		}
	}
}



